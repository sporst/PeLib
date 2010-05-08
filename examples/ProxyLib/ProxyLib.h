#ifndef PROXYLIB_H
#define PROXYLIB_H

#include <string>
#include <list>
#include <vector>

struct Import
{
	std::string name;
	unsigned int ordinal;
	bool byName;
	
	bool operator<(const Import& imp) const
	{
		return imp.name > name;
	}
};

class ProxyLib
{
	private:
	  std::string m_dllname;
	  std::string m_templname;
	  std::vector<std::string> m_impfiles;
	  std::list<Import> m_impfunctions;
	  
	  std::string generateFunctions(const std::list<Import>& fnames) const;
	  void replace(std::string& templ, const std::string& oldvalue, const std::string& newvalue) const;
	  std::string generateOrdinalString(const std::list<Import>& fnames) const;
	  std::string generateNameString(const std::list<Import>& fnames) const;

	public:
	  ProxyLib(const std::string& dllname, const std::string& templname);
	  void addImporter(const std::string& impname);
	  void make(const std::string& outputfile);
	  void addImportedFunction(const std::string& funcname);
	  std::list<Import> getIncludedFunctionNames() const;
	  std::list<Import> getExportedFunctionNames() const;
	  void writeCode(const std::string& filename, const std::string& templfile, const std::list<Import>& fnames, const std::string& dllname) const;
	  void writeDef(const std::string& filename, const std::list<Import>& fnames) const;
};

#endif
