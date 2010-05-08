#include "ProxyLib.h"
#include <PeLib.h>
#include <sstream>
#include <functional>
#include <algorithm>
#include <iterator>
#include <iostream>

// Little helper function for debug output.
std::ostream& operator<<(std::ostream& os, const Import& imp)
{
	os << imp.name;
	return os;
}

// Used to convert int->string
template<typename T>
std::string convert(T v)
{
	std::ostringstream os;
	os << v;
	return os.str();
}

/**
* @param dllname Name of the DLL which will be emulated.
* @param templname Name of the ASM template file.
**/
ProxyLib::ProxyLib(const std::string& dllname, const std::string& templname) : m_dllname(dllname), m_templname(templname)
{
}

/**
* Add another file which uses the emulated DLL.
* @param impname Name of the file which uses the emulated DLL.
**/
void ProxyLib::addImporter(const std::string& impname)
{
	m_impfiles.push_back(impname);
}

/**
* Returns a list of all functions that are imported by all files which use the emulated DLL.
* @return List of imported functions.
**/
std::list<Import> ProxyLib::getIncludedFunctionNames() const
{
	std::vector<std::string>::const_iterator Iter = m_impfiles.begin();

	std::list<Import> incImports;
	
	while (Iter != m_impfiles.end()) // Loop through all filenames.
	{
		PeLib::PeFile32 f(*Iter);
		if (!f.readMzHeader() && !f.readPeHeader() && !f.readImportDirectory())
		{
		
			int fileindex;
			
			if ((fileindex = f.impDir().getFileIndex(m_dllname, PeLib::OLDDIR)) == -1)
			{
				// Dll is not imported by that file.
				++Iter;
				continue;
			}
			
			unsigned int nrimports = f.impDir().getNumberOfFunctions(fileindex, PeLib::OLDDIR);
			
			for (unsigned int i=0;i<nrimports;i++) // Loop through all functions.
			{
				Import imp;
				imp.name = f.impDir().getFunctionName(fileindex, i, PeLib::OLDDIR);
				incImports.push_back(imp);
			}
		}
		++Iter;
	}
	
	incImports.insert(incImports.end(), m_impfunctions.begin(), m_impfunctions.end());
	
	return incImports;
}

/**
* Get a list of all functions the DLL exports.
* @return List of exported functions.
**/
std::list<Import> ProxyLib::getExportedFunctionNames() const
{
	std::list<Import> fnames;
	
	PeLib::PeFile32 f(m_dllname);
	
	if (!f.readMzHeader() && !f.readPeHeader() && !f.readExportDirectory())
	{
	
		Import imp;
		unsigned int base = f.expDir().getBase();
		
		// Loop through all exported functions.
		for (unsigned int i=0;i<f.expDir().getNumberOfFunctions();i++)
		{
			unsigned int ordinal = f.expDir().getFunctionOrdinal(i);
	
			if (i < f.expDir().getNumberOfNames())
			{
				imp.name = f.expDir().getFunctionName(i);
				imp.byName = true;
			}
			else 
			{
				imp.name = convert(ordinal);
				imp.byName = false;
			}
			
			imp.ordinal = base + ordinal;
			
			fnames.push_back(imp);
		}
	}

	return fnames;
}

/**
* Function which generates the ASM code of all exported functions.
* @param fnames List of functions which will be generated.
* @return Asm code of the exported functions.
**/
std::string ProxyLib::generateFunctions(const std::list<Import>& fnames) const
{
	std::ostringstream functions;
	std::string name;
	
	std::list<Import>::const_iterator Iter = fnames.begin();
	
	while (Iter != fnames.end())
	{
		if (Iter->byName)
		{
			functions << Iter->name << " proc" << std::endl;
		}
		else
		{
			functions << "Function_" << Iter->name << " proc" << std::endl;
		}
		functions << "\tjmp dword ptr [" << Iter->name << "Handle]" << std::endl;
		functions << "\tret" << std::endl;
		if (Iter->byName)
		{
			functions << Iter->name << " endp" << std::endl;
		}
		else
		{
			functions << "Function_" << Iter->name << " endp" << std::endl;
		}
		functions << std::endl;
		
		++Iter;
	}
	return functions.str();
}

/**
* @param templ ASM Template.
* @param oldvalue String to replace.
* @param newvalue New value for string.
**/
void ProxyLib::replace(std::string& templ, const std::string& oldvalue, const std::string& newvalue) const
{
	unsigned int found = templ.find(oldvalue);
	if (found != std::string::npos)
	{
		templ.replace(found, oldvalue.size(), newvalue);
	}
}

/**
* Generates a comma-separated list of the ordinals of the exported functions and formats
* the list so that it can be used in MASM.
* @param fnames List of exported functions.
* @return List of function ordinals.
**/
std::string ProxyLib::generateOrdinalString(const std::list<Import>& fnames) const
{
	std::ostringstream ordinals;

	std::list<Import>::const_iterator Iter = fnames.begin();
//	unsigned int counter = 0;
	
	ordinals << "Ordinals\t\t\t\tdd 0" << std::endl;

	while (Iter != fnames.end())
	{
		ordinals << Iter->name << "Handle\t\tdd OFFSET " << Iter->name << "String" << std::endl;
		++Iter;
	}

	ordinals << "OrdinalsEnd\t\t\t\tdd 0" << std::endl;
	
	return ordinals.str();
}

/**
* Creates a list of function names.
* @param Exported functions.
* @return List of exported function names which is ready to be used in MASM.
**/
std::string ProxyLib::generateNameString(const std::list<Import>& fnames) const
{
	std::ostringstream names;

	std::list<Import>::const_iterator Iter = fnames.begin();

	while (Iter != fnames.end())
	{
		names << Iter->name << "String" << "\t\t\t\tdb '" << Iter->name << "',0";
		Iter++;
		if (Iter == fnames.end()) names << ",0";
		names << std::endl;
	}
	
	return names.str();
}

void ProxyLib::addImportedFunction(const std::string& funcname)
{
	Import imp;
	imp.name = funcname;
	imp.byName = true;
	imp.ordinal = 0;
	m_impfunctions.push_back(imp);
}

/**
* Writes the DLL template.
* @param filename Name of the created ASM file.
* @param templfile Name of the ASM template file.
* @param fnames Names of exported functions.
* @param dllname Name of the old DLL file.
**/
void ProxyLib::writeCode(const std::string& filename, const std::string& templfile, const std::list<Import>& fnames, const std::string& dllname) const
{
	std::string functions = generateFunctions(fnames);

	std::ifstream tfile(templfile.c_str());
	std::string templ ((std::istreambuf_iterator<char>(tfile)), std::istreambuf_iterator<char>());

	replace(templ, "%FUNCTIONS%", functions);
	replace(templ, "%OLDDLL%", dllname);
	replace(templ, "%NAMESTRING%", generateNameString(fnames));
	replace(templ, "%ORDINALSTRING%", generateOrdinalString(fnames));
	
	std::ofstream asmfile((filename + ".asm").c_str());
	std::copy(templ.begin(), templ.end(), std::ostream_iterator<char>(asmfile));
}

/**
* Writes the DEF file for the new DLL file.
* @param filename Name of the DLL library.
* @param fnames List of exported functions.
**/
void ProxyLib::writeDef(const std::string& filename, const std::list<Import>& fnames) const
{
	std::list<Import>::const_iterator Iter = fnames.begin();
	std::ofstream deffile((filename + ".def").c_str());
	
	deffile << "LIBRARY " << filename << std::endl;
	deffile << "EXPORTS" << std::endl;
	
	while (Iter != fnames.end())
	{
		if (Iter->byName)
		{
			deffile << Iter->name << std::endl;
		}
		else
		{
			deffile << "Function_" << Iter->name << " @" << Iter->ordinal << std::endl;
		}
		
		++Iter;
	}
}

/**
* Create the ASM and DEF files for the DLL.
* @param outputfile Name of the DLL library.
**/
void ProxyLib::make(const std::string& outputfile)
{
	std::list<Import> ifnames = getIncludedFunctionNames();
	ifnames.sort();
//	std::copy(ifnames.begin(), ifnames.end(), std::ostream_iterator<Import>(std::cout, " "));
	std::list<Import> efnames = getExportedFunctionNames();
	efnames.sort();
//	std::copy(efnames.begin(), efnames.end(), std::ostream_iterator<Import>(std::cout, " "));
	std::list<Import> fnames;
	std::set_intersection(efnames.begin(), efnames.end(), ifnames.begin(), ifnames.end(), std::back_inserter<std::list<Import> >(fnames));
//	std::set_intersection(efnames.begin(), efnames.end(), ifnames.begin(), ifnames.end(), std::ostream_iterator<Import>(std::cout, " "));
	writeCode(outputfile, m_templname, fnames, m_dllname);
	writeDef(outputfile, fnames);
}
