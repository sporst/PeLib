#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "../../source/PeLib.h"

template<typename T>
std::string toString(T x, char f = '0')
{
	std::stringstream ss;
	ss << std::setw(sizeof(T)*2) << std::setfill(f) << std::hex << std::uppercase << x;
	return ss.str();
}

template<>
std::string toString<PeLib::byte>(PeLib::byte x, char f)
{
	std::stringstream ss;
	ss << std::setw(2) << std::setfill(f) << std::hex << std::uppercase << (int)x;
	return ss.str();
}

std::string formatOutput(const std::string& text, const std::string& val, const std::string& pad = "", unsigned int maxsize = 70)
{
	std::stringstream ss;
	
	ss << pad << text << std::setw(maxsize - text.length() - val.length() - pad.length()) << std::setfill(' ') << "";
	ss << val;
	return ss.str();
}

std::string centerOutput(const std::string& text, unsigned int maxsize = 70)
{
	std::stringstream ss;
	
	unsigned int left = (maxsize - text.length()) / 2;
	ss << std::setw(left) << std::setfill(' ') << "";
	ss << text;
	
	return ss.str();
}

void dump(const std::string& d)
{
	std::cout << d << std::endl;
}

void dumpMzHeader(PeLib::PeFile* pef)
{
	const PeLib::MzHeader& mzh = pef->mzHeader();
	
	dump(centerOutput("MZ Header"));
	dump(formatOutput("e_magic", toString(mzh.getMagicNumber())));
	dump(formatOutput("e_cblp", toString(mzh.getBytesOnLastPage())));
	dump(formatOutput("e_cp", toString(mzh.getPagesInFile())));
	dump(formatOutput("e_crlc", toString(mzh.getRelocations())));
	dump(formatOutput("e_cparhdr", toString(mzh.getSizeOfHeader())));
	dump(formatOutput("e_minalloc", toString(mzh.getMinExtraParagraphs())));
	dump(formatOutput("e_maxalloc", toString(mzh.getMaxExtraParagraphs())));
	dump(formatOutput("e_ss", toString(mzh.getSsValue())));
	dump(formatOutput("e_sp", toString(mzh.getSpValue())));
	dump(formatOutput("e_csum", toString(mzh.getChecksum())));
	dump(formatOutput("e_ip", toString(mzh.getIpValue())));
	dump(formatOutput("e_cs", toString(mzh.getCsValue())));
	dump(formatOutput("e_lfarlc", toString(mzh.getAddrOfRelocationTable())));
	dump(formatOutput("e_ovnovalue", toString(mzh.getOverlayNumber())));
	dump(formatOutput("e_oemid", toString(mzh.getOemIdentifier())));
	dump(formatOutput("e_oeminfo", toString(mzh.getOemInformation())));
	dump(formatOutput("e_lfanew", toString(mzh.getAddressOfPeHeader())));
	
	for (unsigned int i=0;i<=3;i++)
	{
		dump(formatOutput("e_res", toString(mzh.getReservedWords1(i))));
	}
	for (unsigned int i=0;i<=9;i++)
	{
		dump(formatOutput("e_res2", toString(mzh.getReservedWords2(i))));
	}
	
	dump("");
	dump(centerOutput("----------------------------------------------"));
	dump("");
}

template<int bits>
void dumpPeHeader(PeLib::PeFile& pef)
{
	const PeLib::PeHeaderT<bits>& peh = static_cast<PeLib::PeFileT<bits>&>(pef).peHeader();
	
	dump(centerOutput("PE Header"));
	dump(formatOutput("NT Signature", toString(peh.getNtSignature())));
	dump(formatOutput("Machine", toString(peh.getMachine())));
	dump(formatOutput("NumberOfSections", toString(peh.getNumberOfSections())));
	dump(formatOutput("TimeDateStamp", toString(peh.getTimeDateStamp())));
	dump(formatOutput("PointerToSymbolTable", toString(peh.getPointerToSymbolTable())));
	dump(formatOutput("NumberOfSymbols", toString(peh.getNumberOfSymbols())));
	dump(formatOutput("SizeOfOptionalHeader", toString(peh.getSizeOfOptionalHeader())));
	dump(formatOutput("Characteristics", toString(peh.getCharacteristics())));
	dump(formatOutput("Magic", toString(peh.getMagic())));
	dump(formatOutput("MajorLinkerVersion", toString(peh.getMajorLinkerVersion())));
	dump(formatOutput("MinorLinkerVersion", toString(peh.getMinorLinkerVersion())));
	dump(formatOutput("SizeOfCode", toString(peh.getSizeOfCode())));
	dump(formatOutput("SizeOfInitializedData", toString(peh.getSizeOfInitializedData())));
	dump(formatOutput("SizeOfUninitializedData", toString(peh.getSizeOfUninitializedData())));
	dump(formatOutput("AddressOfEntryPoint", toString(peh.getAddressOfEntryPoint())));
	dump(formatOutput("BaseOfCode", toString(peh.getBaseOfCode())));
	dump(formatOutput("ImageBase", toString(peh.getImageBase())));
	dump(formatOutput("SectionAlignment", toString(peh.getSectionAlignment())));
	dump(formatOutput("FileAlignment", toString(peh.getFileAlignment())));
	dump(formatOutput("MajorOperatingSystemVersion", toString(peh.getMajorOperatingSystemVersion())));
	dump(formatOutput("MinorOperatingSystemVersion", toString(peh.getMinorOperatingSystemVersion())));
	dump(formatOutput("MajorImageVersion", toString(peh.getMajorImageVersion())));
	dump(formatOutput("MinorImageVersion", toString(peh.getMinorImageVersion())));
	dump(formatOutput("MajorSubsystemVersion", toString(peh.getMajorSubsystemVersion())));
	dump(formatOutput("MinorSubsystemVersion", toString(peh.getMinorSubsystemVersion())));
	dump(formatOutput("Win32VersionValue", toString(peh.getWin32VersionValue())));
	dump(formatOutput("SizeOfImage", toString(peh.getSizeOfImage())));
	dump(formatOutput("SizeOfHeaders", toString(peh.getSizeOfHeaders())));
	dump(formatOutput("CheckSum", toString(peh.getCheckSum())));
	dump(formatOutput("Subsystem", toString(peh.getSubsystem())));
	dump(formatOutput("DllCharacteristics", toString(peh.getDllCharacteristics())));
	dump(formatOutput("SizeOfStackReserve", toString(peh.getSizeOfStackReserve())));
	dump(formatOutput("SizeOfStackCommit", toString(peh.getSizeOfStackCommit())));
	dump(formatOutput("SizeOfHeapReserve", toString(peh.getSizeOfHeapReserve())));
	dump(formatOutput("SizeOfHeapCommit", toString(peh.getSizeOfHeapCommit())));
	dump(formatOutput("LoaderFlags", toString(peh.getLoaderFlags())));
	dump(formatOutput("NumberOfRvaAndSizes", toString(peh.getNumberOfRvaAndSizes())));
	
	dump("");
	
	std::string tabnames[] = {"Export Directory",
							  "Import Directory",
							  "Resource Directory",
							  "Exception Directory",
							  "Security Directory",
							  "BaseReloc Directory",
							  "Debug Directory",
							  "Architecture Directory",
							  "GlobalPtr Directory",
							  "Tls Directory",
							  "LoadConfig Directory",
							  "BoundImport Directory",
							  "IAT Directory",
							  "DelayImport Directory",
							  "ComDescriptor Directory",
							  "Reserved Directory"
							 };
	
	for (unsigned int i=0;i<peh.getNumberOfRvaAndSizes();i++)
	{
		dump(formatOutput(tabnames[i] + " (RVA)", toString(peh.getImageDataDirectoryRva(i))));
		dump(formatOutput(tabnames[i] + " (Size)", toString(peh.getImageDataDirectorySize(i))));
	}
	
	dump("");
	
	for (int i=0;i<peh.getNumberOfSections();i++)
	{
		dump(formatOutput("Name", peh.getSectionName(i)));
		dump(formatOutput("VirtualSize", toString(peh.getVirtualSize(i))));
		dump(formatOutput("VirtualAddress", toString(peh.getVirtualAddress(i))));
		dump(formatOutput("SizeOfRawData", toString(peh.getSizeOfRawData(i))));
		dump(formatOutput("PointerToRawData", toString(peh.getPointerToRawData(i))));
		dump(formatOutput("PointerToRelocations", toString(peh.getPointerToRelocations(i))));
		dump(formatOutput("PointerToLinenumbers", toString(peh.getPointerToLinenumbers(i))));
		dump(formatOutput("NumberOfRelocations", toString(peh.getNumberOfRelocations(i))));
		dump(formatOutput("NumberOfLineNumbers", toString(peh.getNumberOfLinenumbers(i))));
		dump(formatOutput("Characteristics", toString(peh.getCharacteristics(i))));
		dump("");
	}
	
	dump(centerOutput("----------------------------------------------"));
	dump("");
}

void dumpExportDirectory(PeLib::PeFile* pef)
{
	dump(centerOutput("Export Directory"));
	
	if (pef->readExportDirectory())
	{
		dump(centerOutput("Not available"));
		dump("");
		dump(centerOutput("----------------------------------------------"));
		dump("");
		return;
	}
	
	const PeLib::ExportDirectory& exp = pef->expDir();
	
	dump(formatOutput("Base", toString(exp.getBase())));
	dump(formatOutput("Characteristics", toString(exp.getCharacteristics())));
	dump(formatOutput("TimeDateStamp", toString(exp.getTimeDateStamp())));
	dump(formatOutput("MajorVersion", toString(exp.getMajorVersion())));
	dump(formatOutput("MinorVersion", toString(exp.getMinorVersion())));
	dump(formatOutput("Name", toString(exp.getName())));
	dump(formatOutput("NumberOfFunctions", toString(exp.getNumberOfFunctions())));
	dump(formatOutput("NumberOfNames", toString(exp.getNumberOfNames())));
	dump(formatOutput("AddressOfFunctions", toString(exp.getAddressOfFunctions())));
	dump(formatOutput("AddressOfNames", toString(exp.getAddressOfNames())));
//	dump(formatOutput("NumberOfNameOrdinals", toString(exp.getNumberOfNameOrdinals())));
//	dump(formatOutput("NumberOfAddressOfFunctionNames", toString(exp.getNumberOfAddressOfFunctionNames())));
//	dump(formatOutput("NumberOfAddressOfFunctions", toString(exp.getNumberOfAddressOfFunctions())));
	dump(formatOutput("AddressOfNameOrdinals", toString(exp.getAddressOfNameOrdinals())));
	
	dump("");
	
	for (unsigned int i=0;i<exp.getNumberOfFunctions();i++)
	{
		dump(formatOutput("Name", exp.getFunctionName(i), "\t"));
		dump(formatOutput("Ordinal (w/o Base)", toString(exp.getFunctionOrdinal(i)), "\t"));
		dump(formatOutput("Address", toString(exp.getAddressOfFunction(i)), "\t"));
		dump("");
	}
	
//	dump(formatOutput("e_magic", toString(mzh.getMagicNumber())));
	dump(centerOutput("----------------------------------------------"));
	dump("");
}

template<int bits>
void dumpImportDirectory(PeLib::PeFile& pef)
{
	dump(centerOutput("Import Directory"));
	
	if (pef.readImportDirectory())
	{
		dump(centerOutput("Not available"));
		dump("");
		dump(centerOutput("----------------------------------------------"));
		dump("");
		return;
	}

	const PeLib::ImportDirectory<bits>& imp = static_cast<PeLib::PeFileT<bits>&>(pef).impDir();
	
	for (unsigned int i=0;i<imp.getNumberOfFiles(PeLib::OLDDIR);i++)
	{
		dump(formatOutput("DLL Name", imp.getFileName(i, PeLib::OLDDIR)));
		dump(formatOutput("OriginalFirstThunk", toString(imp.getOriginalFirstThunk(i, PeLib::OLDDIR)), "    "));
		dump(formatOutput("TimeDateStamp", toString(imp.getTimeDateStamp(i, PeLib::OLDDIR)), "    "));
		dump(formatOutput("ForwarderChain", toString(imp.getForwarderChain(i, PeLib::OLDDIR)), "    "));
		dump(formatOutput("Name", toString(imp.getRvaOfName(i, PeLib::OLDDIR)), "    "));
		dump(formatOutput("FirstThunk", toString(imp.getFirstThunk(i, PeLib::OLDDIR)), "    "));
		dump("");
		
		for (unsigned int j=0;j<imp.getNumberOfFunctions(i, PeLib::OLDDIR);j++)
		{
			dump(formatOutput("Function Name", imp.getFunctionName(i, j, PeLib::OLDDIR), "    "));
			dump(formatOutput("Hint", toString(imp.getFunctionHint(i, j, PeLib::OLDDIR)), "        "));
			dump(formatOutput("First Thunk", toString(imp.getFirstThunk(i, j, PeLib::OLDDIR)), "        "));
			dump(formatOutput("Original First Thunk", toString(imp.getOriginalFirstThunk(i, j, PeLib::OLDDIR)), "        "));
			dump("");
		}
		
		dump("");
	}
	
	dump(centerOutput("----------------------------------------------"));
	dump("");
}

void dumpResourceTree(const std::string& name, PeLib::ResourceElement* elem, std::string pad)
{
	bool isLeaf = elem->isLeaf();
	
	dump(formatOutput("ResourceElement", name, pad));
	dump(formatOutput("Type",(isLeaf ? "Leaf" : "Node"), pad));
	dump(formatOutput("RVA", toString(elem->getElementRva()), pad));
//	std::cout << pad << "Offset:               " << std::setw(8) << std::setfill('0') << std::uppercase << std::hex << peh.rvaToOffset(elem->getElementRva()) << std::endl;
	
	if (isLeaf)
	{
		PeLib::ResourceLeaf* leaf = static_cast<PeLib::ResourceLeaf*>(elem);
		
		dump(formatOutput("OffsetToData", toString(leaf->getOffsetToData()), pad));
		dump(formatOutput("Size", toString(leaf->getSize()), pad));
		dump(formatOutput("CodePage", toString(leaf->getCodePage()), pad));
		dump(formatOutput("Reserved", toString(leaf->getReserved()), pad));
	}
	else
	{
		PeLib::ResourceNode* node = static_cast<PeLib::ResourceNode*>(elem);
		
		unsigned int uiNamedEntries = node->getNumberOfNamedEntries();
		unsigned int uiIdEntries = node->getNumberOfIdEntries();
		
		dump(formatOutput("Characteristics", toString(node->getCharacteristics()), pad));
		dump(formatOutput("TimeDateStamp", toString(node->getTimeDateStamp()), pad));
		dump(formatOutput("MajorVersion", toString(node->getMajorVersion()), pad));
		dump(formatOutput("MinorVersion", toString(node->getMinorVersion()), pad));
		dump(formatOutput("NumberOfNamedEntries", toString(node->getNumberOfNamedEntries()), pad));
		dump(formatOutput("NumberOfIdEntries", toString(node->getNumberOfIdEntries()), pad));
		
		dump("");
		
		for (unsigned int i=0;i<uiNamedEntries;i++)
		{
			PeLib::dword childOffset = node->getOffsetToChildName(i);
//			PeLib::dword dataOffset = node->getOffsetToChildData(i);
			std::string childname = node->getChildName(i);
			
			dumpResourceTree(childname + " (Offset: " + toString(childOffset) + ")", node->getChild(i), pad + "  ");
		}
		
		for (unsigned int i=0;i<uiIdEntries;i++)
		{
			PeLib::dword childOffset = node->getOffsetToChildName(i);
//			PeLib::dword dataOffset = node->getOffsetToChildData(i);
			
			dumpResourceTree(toString(childOffset), node->getChild(i), pad + "  ");
		}
		
		dump("");
	}
}

void dumpResourceDirectory(PeLib::PeFile* pef)
{
	dump(centerOutput("Resource Directory"));
	
	if (pef->readResourceDirectory())
	{
		dump(centerOutput("Not available"));
		dump("");
		dump(centerOutput("----------------------------------------------"));
		dump("");
		return;
	}

	PeLib::ResourceDirectory& res = pef->resDir();
	
	dumpResourceTree("Root", res.getRoot(), "");
	dump(centerOutput("----------------------------------------------"));
	dump("");
}

void dumpRelocationsDirectory(PeLib::PeFile* pef)
{
	dump(centerOutput("Relocations Directory"));
	
	if (pef->readRelocationsDirectory())
	{
		dump(centerOutput("Not available"));
		dump("");
		dump(centerOutput("----------------------------------------------"));
		dump("");
		return;
	}
	
	PeLib::RelocationsDirectory& reloc = pef->relocDir();
	
	for(unsigned int i=0;i<reloc.calcNumberOfRelocations();i++)
	{
		dump(formatOutput("VirtualAddress", toString(reloc.getVirtualAddress(i))));
		dump(formatOutput("SizeOfBlock", toString(reloc.getSizeOfBlock(i))));
		
		for (unsigned j=0;j<reloc.calcNumberOfRelocationData(i);j++)
		{
			dump(formatOutput("RelocationData", toString(reloc.getRelocationData(i,j)), "  "));
		}
		
		dump("");
	}
	
	dump(centerOutput("----------------------------------------------"));
	dump("");
}

template<int bits>
void dumpTlsDirectory(PeLib::PeFile& pef)
{
	dump(centerOutput("TLS Directory"));
	
	if (pef.readTlsDirectory())
	{
		dump(centerOutput("Not available"));
		dump("");
		dump(centerOutput("----------------------------------------------"));
		dump("");
		return;
	}
	
	const PeLib::TlsDirectory<bits>& tls = static_cast<PeLib::PeFileT<bits>&>(pef).tlsDir();
	
	dump(formatOutput("StartAddressOfRawData", toString(tls.getStartAddressOfRawData())));
	dump(formatOutput("EndAddressOfRawData", toString(tls.getEndAddressOfRawData())));
	dump(formatOutput("AddressOfIndex", toString(tls.getAddressOfIndex())));
	dump(formatOutput("AddressOfCallBacks", toString(tls.getAddressOfCallBacks())));
	dump(formatOutput("SizeOfZeroFill", toString(tls.getSizeOfZeroFill())));
	dump(formatOutput("Characteristics", toString(tls.getCharacteristics())));
	
	dump(centerOutput("----------------------------------------------"));
	dump("");
}

void dumpBoundImportDirectory(PeLib::PeFile* pef)
{
	dump(centerOutput("BoundImport Directory"));
	
	if (pef->readBoundImportDirectory())
	{
		dump(centerOutput("Not available"));
		dump("");
		dump(centerOutput("----------------------------------------------"));
		dump("");
		return;
	}
	
	PeLib::BoundImportDirectory& bimp = pef->boundImpDir();
	
	for (int i=0;i<bimp.calcNumberOfModules();i++)
	{
		dump(formatOutput("ModuleName", bimp.getModuleName(i)));
		dump(formatOutput("TimeDateStamp", toString(bimp.getTimeDateStamp(i))));
		dump(formatOutput("OffsetOfModuleName", toString(bimp.getOffsetModuleName(i))));
		dump(formatOutput("NumberOfModuleForwarderRefs", toString(bimp.getNumberOfModuleForwarderRefs(i))));
		dump("");
	}
	
	dump(centerOutput("----------------------------------------------"));
	dump("");
}

void dumpIatDirectory(PeLib::PeFile* pef)
{
	dump(centerOutput("ImportAddressTable Directory"));
	
	if (pef->readIatDirectory())
	{
		dump(centerOutput("Not available"));
		dump("");
		dump(centerOutput("----------------------------------------------"));
		dump("");
		return;
	}
	
	PeLib::IatDirectory& iat = pef->iatDir();
	
	for (unsigned int i=0;i<iat.calcNumberOfAddresses();i++)
	{
		dump(formatOutput("Address", toString(iat.getAddress(i))));
	}
	
	dump(centerOutput("----------------------------------------------"));
	dump("");
}

void dumpComHeaderDirectory(PeLib::PeFile* pef)
{
	dump(centerOutput("ComHeaderDirectory"));
	
	if (pef->readComHeaderDirectory())
	{
		dump(centerOutput("Not available"));
		dump("");
		dump(centerOutput("----------------------------------------------"));
		dump("");
		return;
	}
	
	PeLib::ComHeaderDirectory& com = pef->comDir();
	
	dump(formatOutput("SizeOfHeader", toString(com.getSizeOfHeader())));
	dump(formatOutput("MajorRuntimeVersion", toString(com.getMajorRuntimeVersion())));
	dump(formatOutput("MinorRuntimeVersion", toString(com.getMinorRuntimeVersion())));
	dump(formatOutput("MetaDataVa", toString(com.getMetaDataVa())));
	dump(formatOutput("MetaDataSize", toString(com.getMetaDataSize())));
	dump(formatOutput("Flags", toString(com.getFlags())));
	dump(formatOutput("EntryPointToken", toString(com.getEntryPointToken())));
	dump(formatOutput("ResourcesVa", toString(com.getResourcesVa())));
	dump(formatOutput("ResourcesSize", toString(com.getResourcesSize())));
	dump(formatOutput("StrongNameSignatureVa", toString(com.getStrongNameSignatureVa())));
	dump(formatOutput("StrongNameSignagureSize", toString(com.getStrongNameSignagureSize())));
	dump(formatOutput("CodeManagerTableVa", toString(com.getCodeManagerTableVa())));
	dump(formatOutput("CodeManagerTableSize", toString(com.getCodeManagerTableSize())));
	dump(formatOutput("VTableFixupsVa", toString(com.getVTableFixupsVa())));
	dump(formatOutput("VTableFixupsSize", toString(com.getVTableFixupsSize())));
	dump(formatOutput("ExportAddressTableJumpsVa", toString(com.getExportAddressTableJumpsVa())));
	dump(formatOutput("ExportAddressTableJumpsSize", toString(com.getExportAddressTableJumpsSize())));
	dump(formatOutput("ManagedNativeHeaderVa", toString(com.getManagedNativeHeaderVa())));
	dump(formatOutput("ManagedNativeHeaderSize", toString(com.getManagedNativeHeaderSize())));
	
	dump(centerOutput("----------------------------------------------"));
	dump("");
}

class DumpPeHeaderVisitor : public PeLib::PeFileVisitor
{
public:
    virtual void callback(PeLib::PeFile32 &file) {dumpPeHeader<32>(file);}
    virtual void callback(PeLib::PeFile64 &file) {dumpPeHeader<64>(file);}
};

class DumpImpDirVisitor : public PeLib::PeFileVisitor
{
public:
    virtual void callback(PeLib::PeFile32 &file) {dumpImportDirectory<32>(file);}
    virtual void callback(PeLib::PeFile64 &file) {dumpImportDirectory<64>(file);}
};

class DumpTlsDirVisitor : public PeLib::PeFileVisitor
{
public:
    virtual void callback(PeLib::PeFile32 &file) {dumpTlsDirectory<32>(file);}
    virtual void callback(PeLib::PeFile64 &file) {dumpTlsDirectory<64>(file);}
};

int main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		std::cout << "Usage: filedump filename" << std::endl;
		return 1;
	}
	
	std::string filename = argv[1];
	
	PeLib::PeFile* pef = PeLib::openPeFile(filename);
	
	if (!pef)
	{
		std::cout << "Invalid PE File" << std::endl;
		return 2;
	}

	pef->readMzHeader();
	pef->readPeHeader();
	
	dumpMzHeader(pef);
	
	DumpPeHeaderVisitor v1;
	pef->visit(v1);
	
	dumpExportDirectory(pef);
	
	DumpImpDirVisitor v2;
	pef->visit(v2);
	
	dumpResourceDirectory(pef);
	
	dumpRelocationsDirectory(pef);
	
	DumpTlsDirVisitor v3;
	pef->visit(v3);
	
	dumpBoundImportDirectory(pef);
	dumpIatDirectory(pef);
	dumpComHeaderDirectory(pef);
	
	delete pef;
	
	return 0;
}
