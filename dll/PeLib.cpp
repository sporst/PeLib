/*
* PeLib.cpp - DLL wrapper for the PeLib library.
*
* Copyright (c) 2004 Sebastian Porst (webmaster@the-interweb.com)
* All rights reserved.
*
* This software is licensed under the zlib/libpng License.
* For more details see http://www.opensource.org/licenses/zlib-license.php
* or the license information file (license.htm) in the root directory 
* of PeLib.
*/

#define NOMINMAX

#include <windows.h>
#include <algorithm>
#include "../source/PeLib.h"

using namespace PeLib;

unsigned int uiErrorCode;

extern "C"
{
	int WINAPI DllMain( HINSTANCE, unsigned int, void*)
	{
		return 1;
 	}

	int WINAPI DllEntryPoint( HINSTANCE hInst, unsigned int reason, void * lpReserved )
	{
		return DllMain( hInst, reason, lpReserved );
	}

int BoundImportDirectory_addBoundImport(BoundImportDirectory* module, const std::string& strModuleName, dword dwTds, word dwOmn, word wWfr)
{
	return module->addBoundImport(strModuleName, dwTds, dwOmn, wWfr);
}

int BoundImportDirectory_getModuleIndex(BoundImportDirectory* module, const std::string& strModuleName)
{
	return module->getModuleIndex(strModuleName);
}

int BoundImportDirectory_getNumberOfModules(BoundImportDirectory* module)
{
	return module->getNumberOfModules();
}

int BoundImportDirectory_read(BoundImportDirectory* module, const std::string& strFileName, dword dwOffset, dword dwSize)
{
	return module->read(strFileName, dwOffset, dwSize);
}

void BoundImportDirectory_rebuild(BoundImportDirectory* module, std::vector<PeLib::byte>& vBuffer, bool fMakeValid = true)
{
	module->rebuild(vBuffer, fMakeValid);
}

void BoundImportDirectory_clear(BoundImportDirectory* module)
{
	module->clear();
}

void BoundImportDirectory_removeBoundImport(BoundImportDirectory* module, const std::string& strModuleName)
{
	module->removeBoundImport(strModuleName);
}

int BoundImportDirectory_size(BoundImportDirectory* module)
{
	return module->size();
}

int BoundImportDirectory_write(BoundImportDirectory* module, const std::string& strFilename, dword dwOffset, bool fMakeValid = true)
{
	return module->write(strFilename, dwOffset, fMakeValid);
}

dword BoundImportDirectory_getTimeDateStamp(BoundImportDirectory* module, dword dwBidnr)
{
	return module->getTimeDateStamp(dwBidnr);
}

word BoundImportDirectory_getOffsetModuleName(BoundImportDirectory* module, dword dwBidnr)
{
	return module->getOffsetModuleName(dwBidnr);
}

word BoundImportDirectory_getNumberOfModuleForwarderRefs(BoundImportDirectory* module, dword dwBidnr)
{
	return module->getNumberOfModuleForwarderRefs(dwBidnr);
}

std::string BoundImportDirectory_getModuleName(BoundImportDirectory* module, dword dwBidnr)
{
	return module->getModuleName(dwBidnr);
}

void BoundImportDirectory_setTimeDateStamp(BoundImportDirectory* module, dword dwBidnr, dword dwTds)
{
	module->setTimeDateStamp(dwBidnr, dwTds);
}

void BoundImportDirectory_setOffsetModuleName(BoundImportDirectory* module, dword dwBidnr, word wOmn)
{
	module->setOffsetModuleName(dwBidnr, wOmn);
}

void BoundImportDirectory_setNumberOfModuleForwarderRefs(BoundImportDirectory* module, dword dwBidnr, word wMfr)
{
	module->setNumberOfModuleForwarderRefs(dwBidnr, wMfr);
}

void BoundImportDirectory_setModuleName(BoundImportDirectory* module, dword dwBidnr, const std::string& strModuleName)
{
	module->setModuleName(dwBidnr, strModuleName);
}

dword BoundImportDirectory_getTimeDateStamp_module(BoundImportDirectory* module, dword dwBidnr, dword forwardedModule)
{
	return module->getTimeDateStamp(dwBidnr, forwardedModule);
}

word BoundImportDirectory_getOffsetModuleName_module(BoundImportDirectory* module, dword dwBidnr, dword forwardedModule)
{
	return module->getOffsetModuleName(dwBidnr, forwardedModule);
}

word BoundImportDirectory_getNumberOfModuleForwarderRefs_module(BoundImportDirectory* module, dword dwBidnr, dword forwardedModule)
{
	return module->getNumberOfModuleForwarderRefs(dwBidnr, forwardedModule);
}

std::string BoundImportDirectory_getModuleName_module(BoundImportDirectory* module, dword dwBidnr, dword forwardedModule)
{
	return module->getModuleName(dwBidnr, forwardedModule);
}

void BoundImportDirectory_setTimeDateStamp_module(BoundImportDirectory* module, dword dwBidnr, dword forwardedModule, dword dwTds)
{
	module->setTimeDateStamp(dwBidnr, forwardedModule, dwTds);
}

void BoundImportDirectory_setOffsetModuleName_module(BoundImportDirectory* module, dword dwBidnr, dword forwardedModule, word wOmn)
{
	module->setOffsetModuleName(dwBidnr, forwardedModule, wOmn);
}

void BoundImportDirectory_setNumberOfModuleForwarderRefs_module(BoundImportDirectory* module, dword dwBidnr, dword forwardedModule, word wMfr)
{
	module->setNumberOfModuleForwarderRefs(dwBidnr, forwardedModule, wMfr);
}

void BoundImportDirectory_setModuleName_module(BoundImportDirectory* module, dword dwBidnr, dword forwardedModule, const std::string& strModuleName)
{
	module->setModuleName(dwBidnr, forwardedModule, strModuleName);
}

word BoundImportDirectory_calcNumberOfModuleForwarderRefs(BoundImportDirectory* module, dword dwBidnr)
{
	return module->calcNumberOfModuleForwarderRefs(dwBidnr);
}

void BoundImportDirectory_addForwardedModule(BoundImportDirectory* module, dword dwBidnr, const std::string& name, dword timeStamp = 0, word offsetModuleName = 0, word forwardedModules = 0)
{
	module->addForwardedModule(dwBidnr, name, timeStamp, offsetModuleName, forwardedModules);
}

void BoundImportDirectory_removeForwardedModule(BoundImportDirectory* module, dword dwBidnr, word forwardedModule)
{
	module->removeForwardedModule(dwBidnr, forwardedModule);
}

int ComHeaderDirectory_read(ComHeaderDirectory* module, const std::string& strFilename, unsigned int uiOffset, unsigned int uiSize)
{
	return module->read(strFilename, uiOffset, uiSize);
}

void ComHeaderDirectory_rebuild(ComHeaderDirectory* module, std::vector<PeLib::byte>& vBuffer)
{
	module->rebuild(vBuffer);
}

int ComHeaderDirectory_size(ComHeaderDirectory* module)
{
	return module->size();
}

int ComHeaderDirectory_write(ComHeaderDirectory* module, const std::string& strFilename, unsigned int dwOffset)
{
	return module->write(strFilename, dwOffset);
}

dword ComHeaderDirectory_getSizeOfHeader(ComHeaderDirectory* module)
{
	return module->getSizeOfHeader();
}

word ComHeaderDirectory_getMajorRuntimeVersion(ComHeaderDirectory* module)
{
	return module->getMajorRuntimeVersion();
}

word ComHeaderDirectory_getMinorRuntimeVersion(ComHeaderDirectory* module)
{
	return module->getMinorRuntimeVersion();
}

dword ComHeaderDirectory_getMetaDataVa(ComHeaderDirectory* module)
{
	return module->getMetaDataVa();
}

dword ComHeaderDirectory_getMetaDataSize(ComHeaderDirectory* module)
{
	return module->getMetaDataSize();
}

dword ComHeaderDirectory_getFlags(ComHeaderDirectory* module)
{
	return module->getFlags();
}

dword ComHeaderDirectory_getEntryPointToken(ComHeaderDirectory* module)
{
	return module->getEntryPointToken();
}

dword ComHeaderDirectory_getResourcesVa(ComHeaderDirectory* module)
{
	return module->getResourcesVa();
}

dword ComHeaderDirectory_getResourcesSize(ComHeaderDirectory* module)
{
	return module->getResourcesSize();
}

dword ComHeaderDirectory_getStrongNameSignatureVa(ComHeaderDirectory* module)
{
	return module->getStrongNameSignatureVa();
}

dword ComHeaderDirectory_getStrongNameSignagureSize(ComHeaderDirectory* module)
{
	return module->getStrongNameSignagureSize();
}

dword ComHeaderDirectory_getCodeManagerTableVa(ComHeaderDirectory* module)
{
	return module->getCodeManagerTableVa();
}

dword ComHeaderDirectory_getCodeManagerTableSize(ComHeaderDirectory* module)
{
	return module->getCodeManagerTableSize();
}

dword ComHeaderDirectory_getVTableFixupsVa(ComHeaderDirectory* module)
{
	return module->getVTableFixupsVa();
}

dword ComHeaderDirectory_getVTableFixupsSize(ComHeaderDirectory* module)
{
	return module->getVTableFixupsSize();
}

dword ComHeaderDirectory_getExportAddressTableJumpsVa(ComHeaderDirectory* module)
{
	return module->getExportAddressTableJumpsVa();
}

dword ComHeaderDirectory_getExportAddressTableJumpsSize(ComHeaderDirectory* module)
{
	return module->getExportAddressTableJumpsSize();
}

dword ComHeaderDirectory_getManagedNativeHeaderVa(ComHeaderDirectory* module)
{
	return module->getManagedNativeHeaderVa();
}

dword ComHeaderDirectory_getManagedNativeHeaderSize(ComHeaderDirectory* module)
{
	return module->getManagedNativeHeaderSize();
}

void ComHeaderDirectory_setSizeOfHeader(ComHeaderDirectory* module, dword dwValue)
{
	module->setSizeOfHeader(dwValue);
}

void ComHeaderDirectory_setMajorRuntimeVersion(ComHeaderDirectory* module, word wValue)
{
	module->setMajorRuntimeVersion(wValue);
}

void ComHeaderDirectory_setMinorRuntimeVersion(ComHeaderDirectory* module, word wValue)
{
	module->setMinorRuntimeVersion(wValue);
}

void ComHeaderDirectory_setMetaDataVa(ComHeaderDirectory* module, dword dwValue)
{
	module->setMetaDataVa(dwValue);
}

void ComHeaderDirectory_setMetaDataSize(ComHeaderDirectory* module, dword dwValue)
{
	module->setMetaDataSize(dwValue);
}

void ComHeaderDirectory_setFlags(ComHeaderDirectory* module, dword dwValue)
{
	module->setFlags(dwValue);
}

void ComHeaderDirectory_setEntryPointToken(ComHeaderDirectory* module, dword dwValue)
{
	module->setEntryPointToken(dwValue);
}

void ComHeaderDirectory_setResourcesVa(ComHeaderDirectory* module, dword dwValue)
{
	module->setResourcesVa(dwValue);
}

void ComHeaderDirectory_setResourcesSize(ComHeaderDirectory* module, dword dwValue)
{
	module->setResourcesSize(dwValue);
}

void ComHeaderDirectory_setStrongNameSignatureVa(ComHeaderDirectory* module, dword dwValue)
{
	module->setStrongNameSignatureVa(dwValue);
}

void ComHeaderDirectory_setStrongNameSignagureSize(ComHeaderDirectory* module, dword dwValue)
{
	module->setStrongNameSignagureSize(dwValue);
}

void ComHeaderDirectory_setCodeManagerTableVa(ComHeaderDirectory* module, dword dwValue)
{
	module->setCodeManagerTableVa(dwValue);
}

void ComHeaderDirectory_setCodeManagerTableSize(ComHeaderDirectory* module, dword dwValue)
{
	module->setCodeManagerTableSize(dwValue);
}

void ComHeaderDirectory_setVTableFixupsVa(ComHeaderDirectory* module, dword dwValue)
{
	module->setVTableFixupsVa(dwValue);
}

void ComHeaderDirectory_setVTableFixupsSize(ComHeaderDirectory* module, dword dwValue)
{
	module->setVTableFixupsSize(dwValue);
}

void ComHeaderDirectory_setExportAddressTableJumpsVa(ComHeaderDirectory* module, dword dwValue)
{
	module->setExportAddressTableJumpsVa(dwValue);
}

void ComHeaderDirectory_setExportAddressTableJumpsSize(ComHeaderDirectory* module, dword dwValue)
{
	module->setExportAddressTableJumpsSize(dwValue);
}

void ComHeaderDirectory_setManagedNativeHeaderVa(ComHeaderDirectory* module, dword dwValue)
{
	module->setManagedNativeHeaderVa(dwValue);
}

void ComHeaderDirectory_setManagedNativeHeaderSize(ComHeaderDirectory* module, dword dwValue)
{
	module->setManagedNativeHeaderSize(dwValue);
}

int DebugDirectory_read(DebugDirectory* module, const std::string& strFilename, unsigned int uiOffset, unsigned int uiSize)
{
	return module->read(strFilename, uiOffset, uiSize);
}

void DebugDirectory_rebuild(DebugDirectory* module, std::vector<PeLib::byte>& obBuffer)
{
	module->rebuild(obBuffer);
}

int DebugDirectory_write(DebugDirectory* module, const std::string& strFilename, unsigned int uiOffset)
{
	return module->write(strFilename, uiOffset);
}

int DebugDirectory_getNumberOfEntries(DebugDirectory* module)
{
	return module->getNumberOfEntries();
}

void DebugDirectory_addEntry(DebugDirectory* module)
{
	module->addEntry();
}

void DebugDirectory_removeEntry(DebugDirectory* module, unsigned int uiIndex)
{
	module->removeEntry(uiIndex);
}

dword DebugDirectory_getCharacteristics(DebugDirectory* module, unsigned int uiIndex)
{
	return module->getCharacteristics(uiIndex);
}

dword DebugDirectory_getTimeDateStamp(DebugDirectory* module, unsigned int uiIndex)
{
	return module->getTimeDateStamp(uiIndex);
}

word DebugDirectory_getMajorVersion(DebugDirectory* module, unsigned int uiIndex)
{
	return module->getMajorVersion(uiIndex);
}

word DebugDirectory_getMinorVersion(DebugDirectory* module, unsigned int uiIndex)
{
	return module->getMinorVersion(uiIndex);
}

dword DebugDirectory_getType(DebugDirectory* module, unsigned int uiIndex)
{
	return module->getType(uiIndex);
}

dword DebugDirectory_getSizeOfData(DebugDirectory* module, unsigned int uiIndex)
{
	return module->getSizeOfData(uiIndex);
}

dword DebugDirectory_getAddressOfRawData(DebugDirectory* module, unsigned int uiIndex)
{
	return module->getAddressOfRawData(uiIndex);
}

dword DebugDirectory_getPointerToRawData(DebugDirectory* module, unsigned int uiIndex)
{
	return module->getPointerToRawData(uiIndex);
}

void DebugDirectory_setCharacteristics(DebugDirectory* module, unsigned int uiIndex, dword dwValue)
{
	module->setCharacteristics(uiIndex, dwValue);
}

void DebugDirectory_setTimeDateStamp(DebugDirectory* module, unsigned int uiIndex, dword dwValue)
{
	module->setTimeDateStamp(uiIndex, dwValue);
}

void DebugDirectory_setMajorVersion(DebugDirectory* module, unsigned int uiIndex, word wValue)
{
	module->setMajorVersion(uiIndex, wValue);
}

void DebugDirectory_setMinorVersion(DebugDirectory* module, unsigned int uiIndex, word wValue)
{
	module->setMinorVersion(uiIndex, wValue);
}

void DebugDirectory_setType(DebugDirectory* module, unsigned int uiIndex, dword dwValue)
{
	module->setType(uiIndex, dwValue);
}

void DebugDirectory_setSizeOfData(DebugDirectory* module, unsigned int uiIndex, dword dwValue)
{
	module->setSizeOfData(uiIndex, dwValue);
}

void DebugDirectory_setAddressOfRawData(DebugDirectory* module, unsigned int uiIndex, dword dwValue)
{
	module->setAddressOfRawData(uiIndex, dwValue);
}

void DebugDirectory_setPointerToRawData(DebugDirectory* module, unsigned int uiIndex, dword dwValue)
{
	module->setPointerToRawData(uiIndex, dwValue);
}

void ExportDirectory_addFunction(ExportDirectory* module, const std::string& strFuncname, dword dwFuncAddr)
{
	module->addFunction(strFuncname, dwFuncAddr);
}

int ExportDirectory_getFunctionIndex(ExportDirectory* module, const std::string& strFunctionName)
{
	return module->getFunctionIndex(strFunctionName);
}

int ExportDirectory_read(ExportDirectory* module, const std::string& strFilename, unsigned int uiOffset, unsigned int uiSize, const PeHeader& pehHeader)
{
	return module->read(strFilename, uiOffset, uiSize, pehHeader);
}

void ExportDirectory_rebuild(ExportDirectory* module, std::vector<PeLib::byte>& vBuffer, dword dwRva)
{
	module->rebuild(vBuffer, dwRva);
}

int ExportDirectory_size(ExportDirectory* module)
{
	return module->size();
}

int ExportDirectory_write(ExportDirectory* module, const std::string& strFilename, unsigned int uiOffset, unsigned int uiRva)
{
	return module->write(strFilename, uiOffset, uiRva);
}

void ExportDirectory_setNameString(ExportDirectory* module, const std::string& strFilename)
{
	module->setNameString(strFilename);
}

std::string ExportDirectory_getNameString(ExportDirectory* module)
{
	return module->getNameString();
}

std::string ExportDirectory_getFunctionName(ExportDirectory* module, dword dwIndex)
{
	return module->getFunctionName(dwIndex);
}

word ExportDirectory_getFunctionOrdinal(ExportDirectory* module, dword dwIndex)
{
	return module->getFunctionOrdinal(dwIndex);
}

dword ExportDirectory_getAddressOfName(ExportDirectory* module, dword dwIndex)
{
	return module->getAddressOfName(dwIndex);
}

dword ExportDirectory_getAddressOfFunction(ExportDirectory* module, dword dwIndex)
{
	return module->getAddressOfFunction(dwIndex);
}

void ExportDirectory_setFunctionName(ExportDirectory* module, dword dwIndex, const std::string& strName)
{
	module->setFunctionName(dwIndex, strName);
}

void ExportDirectory_setFunctionOrdinal(ExportDirectory* module, dword dwIndex, word wValue)
{
	module->setFunctionOrdinal(dwIndex, wValue);
}

void ExportDirectory_setAddressOfName(ExportDirectory* module, dword dwIndex, dword dwValue)
{
	module->setAddressOfName(dwIndex, dwValue);
}

void ExportDirectory_setAddressOfFunction(ExportDirectory* module, dword dwIndex, dword dwValue)
{
	module->setAddressOfFunction(dwIndex, dwValue);
}

dword ExportDirectory_getBase(ExportDirectory* module)
{
	return module->getBase();
}

dword ExportDirectory_getCharacteristics(ExportDirectory* module)
{
	return module->getCharacteristics();
}

dword ExportDirectory_getTimeDateStamp(ExportDirectory* module)
{
	return module->getTimeDateStamp();
}

word ExportDirectory_getMajorVersion(ExportDirectory* module)
{
	return module->getMajorVersion();
}

word ExportDirectory_getMinorVersion(ExportDirectory* module)
{
	return module->getMinorVersion();
}

dword ExportDirectory_getName(ExportDirectory* module)
{
	return module->getName();
}

dword ExportDirectory_getNumberOfFunctions(ExportDirectory* module)
{
	return module->getNumberOfFunctions();
}

dword ExportDirectory_getNumberOfNames(ExportDirectory* module)
{
	return module->getNumberOfNames();
}

dword ExportDirectory_getAddressOfFunctions(ExportDirectory* module)
{
	return module->getAddressOfFunctions();
}

dword ExportDirectory_getAddressOfNames(ExportDirectory* module)
{
	return module->getAddressOfNames();
}

dword ExportDirectory_getNumberOfNameOrdinals(ExportDirectory* module)
{
	return module->getNumberOfNameOrdinals();
}

dword ExportDirectory_getNumberOfAddressOfFunctionNames(ExportDirectory* module)
{
	return module->getNumberOfAddressOfFunctionNames();
}

dword ExportDirectory_getNumberOfAddressOfFunctions(ExportDirectory* module)
{
	return module->getNumberOfAddressOfFunctions();
}

dword ExportDirectory_getAddressOfNameOrdinals(ExportDirectory* module)
{
	return module->getAddressOfNameOrdinals();
}

void ExportDirectory_setBase(ExportDirectory* module, dword dwValue)
{
	module->setBase(dwValue);
}

void ExportDirectory_setCharacteristics(ExportDirectory* module, dword dwValue)
{
	module->setCharacteristics(dwValue);
}

void ExportDirectory_setTimeDateStamp(ExportDirectory* module, dword dwValue)
{
	module->setTimeDateStamp(dwValue);
}

void ExportDirectory_setMajorVersion(ExportDirectory* module, word wValue)
{
	module->setMajorVersion(wValue);
}

void ExportDirectory_setMinorVersion(ExportDirectory* module, word wValue)
{
	module->setMinorVersion(wValue);
}

void ExportDirectory_setName(ExportDirectory* module, dword dwValue)
{
	module->setName(dwValue);
}

void ExportDirectory_setNumberOfFunctions(ExportDirectory* module, dword dwValue)
{
	module->setNumberOfFunctions(dwValue);
}

void ExportDirectory_setNumberOfNames(ExportDirectory* module, dword dwValue)
{
	module->setNumberOfNames(dwValue);
}

void ExportDirectory_setAddressOfFunctions(ExportDirectory* module, dword dwValue)
{
	module->setAddressOfFunctions(dwValue);
}

void ExportDirectory_setAddressOfNames(ExportDirectory* module, dword dwValue)
{
	module->setAddressOfNames(dwValue);
}

int IatDirectory_read(IatDirectory* module, const std::string& strFilename, unsigned int dwOffset, unsigned int dwSize)
{
	return module->read(strFilename, dwOffset, dwSize);
}

int IatDirectory_numberOfAddresses(IatDirectory* module)
{
	return module->numberOfAddresses();
}

void IatDirectory_addAddress(IatDirectory* module, dword dwValue)
{
	module->addAddress(dwValue);
}

void IatDirectory_removeAddress(IatDirectory* module, dword dwAddrnr)
{
	module->removeAddress(dwAddrnr);
}

void IatDirectory_removeAll(IatDirectory* module)
{
	module->removeAll();
}

void IatDirectory_rebuild(IatDirectory* module, std::vector<PeLib::byte>& vBuffer)
{
	module->rebuild(vBuffer);
}

int IatDirectory_size(IatDirectory* module)
{
	return module->size();
}

int IatDirectory_write(IatDirectory* module, const std::string& strFilename, unsigned int uiOffset)
{
	return module->write(strFilename, uiOffset);
}

dword IatDirectory_getAddress(IatDirectory* module, dword dwAddrnr)
{
	return module->getAddress(dwAddrnr);
}

void IatDirectory_setAddress(IatDirectory* module, dword dwAddrnr, dword dwValue)
{
	module->setAddress(dwAddrnr, dwValue);
}

int ImportDirectory_addFunction32_byHint(ImportDirectory<32>* module, const std::string& strFilename, word wHint)
{
	return module->addFunction(strFilename, wHint);
}

int ImportDirectory_addFunction64_byHint(ImportDirectory<64>* module, const std::string& strFilename, word wHint)
{
	return module->addFunction(strFilename, wHint);
}

int ImportDirectory_addFunction32_byName(ImportDirectory<32>* module, const std::string& strFilename, const std::string& strFuncname)
{
	return module->addFunction(strFilename, strFuncname);
}

int ImportDirectory_addFunction64_byName(ImportDirectory<64>* module, const std::string& strFilename, const std::string& strFuncname)
{
	return module->addFunction(strFilename, strFuncname);
}

int ImportDirectory_getFileIndex32(ImportDirectory<32>* module, const std::string& strFilename, currdir cdDir)
{
	return module->getFileIndex(strFilename, cdDir);
}

int ImportDirectory_getFileIndex64(ImportDirectory<64>* module, const std::string& strFilename, currdir cdDir)
{
	return module->getFileIndex(strFilename, cdDir);
}

int ImportDirectory_getFunctionIndex32(ImportDirectory<32>* module, const std::string& strFilename, const std::string& strFuncname, currdir cdDir)
{
	return module->getFunctionIndex(strFilename, strFuncname, cdDir);
}

int ImportDirectory_getFunctionIndex64(ImportDirectory<64>* module, const std::string& strFilename, const std::string& strFuncname, currdir cdDir)
{
	return module->getFunctionIndex(strFilename, strFuncname, cdDir);
}

std::string ImportDirectory_getFileName32(ImportDirectory<32>* module, dword dwFilenr, currdir cdDir)
{
	return module->getFileName(dwFilenr, cdDir);
}

std::string ImportDirectory_getFileName64(ImportDirectory<64>* module, dword dwFilenr, currdir cdDir)
{
	return module->getFileName(dwFilenr, cdDir);
}

void ImportDirectory_setFileName32(ImportDirectory<32>* module, dword filenr, currdir dir, const std::string& name)
{
	module->setFileName(filenr, dir, name);
}

void ImportDirectory_setFileName64(ImportDirectory<64>* module, dword filenr, currdir dir, const std::string& name)
{
	module->setFileName(filenr, dir, name);
}

word ImportDirectory_getFunctionHint32(ImportDirectory<32>* module, dword dwFilenr, dword dwFuncnr, currdir cdDir)
{
	return module->getFunctionHint(dwFilenr, dwFuncnr, cdDir);
}

word ImportDirectory_getFunctionHint64(ImportDirectory<64>* module, dword dwFilenr, dword dwFuncnr, currdir cdDir)
{
	return module->getFunctionHint(dwFilenr, dwFuncnr, cdDir);
}

void ImportDirectory_setFunctionHint32(ImportDirectory<32>* module, dword dwFilenr, dword dwFuncnr, currdir cdDir, word value)
{
	module->setFunctionHint(dwFilenr, dwFuncnr, cdDir, value);
}

void ImportDirectory_setFunctionHint64(ImportDirectory<64>* module, dword dwFilenr, dword dwFuncnr, currdir cdDir, word value)
{
	module->setFunctionHint(dwFilenr, dwFuncnr, cdDir, value);
}

std::string ImportDirectory_getFunctionName32(ImportDirectory<32>* module, dword dwFilenr, dword dwFuncnr, currdir cdDir)
{
	return module->getFunctionName(dwFilenr, dwFuncnr, cdDir);
}

std::string ImportDirectory_getFunctionName64(ImportDirectory<64>* module, dword dwFilenr, dword dwFuncnr, currdir cdDir)
{
	return module->getFunctionName(dwFilenr, dwFuncnr, cdDir);
}

void ImportDirectory_setFunctionName32(ImportDirectory<32>* module, dword dwFilenr, dword dwFuncnr, currdir cdDir, const std::string& functionName)
{
	module->setFunctionName(dwFilenr, dwFuncnr, cdDir, functionName);
}

void ImportDirectory_setFunctionName64(ImportDirectory<64>* module, dword dwFilenr, dword dwFuncnr, currdir cdDir, const std::string& functionName)
{
	module->setFunctionName(dwFilenr, dwFuncnr, cdDir, functionName);
}

dword ImportDirectory_getNumberOfFiles32(ImportDirectory<32>* module, currdir cdDir)
{
	return module->getNumberOfFiles(cdDir);
}

dword ImportDirectory_getNumberOfFiles64(ImportDirectory<64>* module, currdir cdDir)
{
	return module->getNumberOfFiles(cdDir);
}

dword ImportDirectory_getNumberOfFunctions32(ImportDirectory<32>* module, dword dwFilenr, currdir cdDir)
{
	return module->getNumberOfFunctions(dwFilenr, cdDir);
}

dword ImportDirectory_getNumberOfFunctions64(ImportDirectory<64>* module, dword dwFilenr, currdir cdDir)
{
	return module->getNumberOfFunctions(dwFilenr, cdDir);
}

int ImportDirectory_read32(ImportDirectory<32>* module, const std::string& strFilename, unsigned int uiOffset, unsigned int uiSize, const PeHeaderT<32>& pehHeader)
{
	return module->read(strFilename, uiOffset, uiSize, pehHeader);
}

int ImportDirectory_read64(ImportDirectory<64>* module, const std::string& strFilename, unsigned int uiOffset, unsigned int uiSize, const PeHeaderT<64>& pehHeader)
{
	return module->read(strFilename, uiOffset, uiSize, pehHeader);
}

void ImportDirectory_rebuild32(ImportDirectory<32>* module, std::vector<PeLib::byte>& vBuffer, dword dwRva, bool fixEntries = true)
{
	module->rebuild(vBuffer, dwRva, fixEntries);
}

void ImportDirectory_rebuild64(ImportDirectory<64>* module, std::vector<PeLib::byte>& vBuffer, dword dwRva, bool fixEntries = true)
{
	module->rebuild(vBuffer, dwRva, fixEntries);
}

int ImportDirectory_removeFile32(ImportDirectory<32>* module, const std::string& strFilename)
{
	return module->removeFile(strFilename);
}

int ImportDirectory_removeFile64(ImportDirectory<64>* module, const std::string& strFilename)
{
	return module->removeFile(strFilename);
}

int ImportDirectory_removeFunction32_byName(ImportDirectory<32>* module, const std::string& strFilename, const std::string& strFuncname)
{
	return module->removeFunction(strFilename, strFuncname);
}

int ImportDirectory_removeFunction64_byName(ImportDirectory<64>* module, const std::string& strFilename, const std::string& strFuncname)
{
	return module->removeFunction(strFilename, strFuncname);
}

int ImportDirectory_removeFunction32_byHint(ImportDirectory<32>* module, const std::string& strFilename, word wHint)
{
	return module->removeFunction(strFilename, wHint);
}

int ImportDirectory_removeFunction64_byHint(ImportDirectory<64>* module, const std::string& strFilename, word wHint)
{
	return module->removeFunction(strFilename, wHint);
}

int ImportDirectory_size32(ImportDirectory<32>* module)
{
	return module->size();
}

int ImportDirectory_size64(ImportDirectory<64>* module)
{
	return module->size();
}

int ImportDirectory_write32(ImportDirectory<32>* module, const std::string& strFilename, unsigned int uiOffset, unsigned int uiRva)
{
	return module->write(strFilename, uiOffset, uiRva);
}

int ImportDirectory_write64(ImportDirectory<64>* module, const std::string& strFilename, unsigned int uiOffset, unsigned int uiRva)
{
	return module->write(strFilename, uiOffset, uiRva);
}

dword ImportDirectory_getFirstThunk32_byNumber(ImportDirectory<32>* module, dword dwFilenr, dword dwFuncnr, currdir cdDir)
{
	return module->getFirstThunk(dwFilenr, dwFuncnr, cdDir);
}

dword ImportDirectory_getFirstThunk64_byNumber(ImportDirectory<64>* module, dword dwFilenr, dword dwFuncnr, currdir cdDir)
{
	return module->getFirstThunk(dwFilenr, dwFuncnr, cdDir);
}

void ImportDirectory_setFirstThunk32_byNumber(ImportDirectory<32>* module, dword dwFilenr, dword dwFuncnr, currdir cdDir, dword value)
{
	module->setFirstThunk(dwFilenr, dwFuncnr, cdDir, value);
}

void ImportDirectory_setFirstThunk64_byNumber(ImportDirectory<64>* module, dword dwFilenr, dword dwFuncnr, currdir cdDir, dword value)
{
	module->setFirstThunk(dwFilenr, dwFuncnr, cdDir, value);
}

dword ImportDirectory_getOriginalFirstThunk32_byNumber(ImportDirectory<32>* module, dword dwFilenr, dword dwFuncnr, currdir cdDir)
{
	return module->getOriginalFirstThunk(dwFilenr, dwFuncnr, cdDir);
}

dword ImportDirectory_getOriginalFirstThunk64_byNumber(ImportDirectory<64>* module, dword dwFilenr, dword dwFuncnr, currdir cdDir)
{
	return module->getOriginalFirstThunk(dwFilenr, dwFuncnr, cdDir);
}

void ImportDirectory_setOriginalFirstThunk32(ImportDirectory<32>* module, dword dwFilenr, dword dwFuncnr, currdir cdDir, dword value)
{
	module->setOriginalFirstThunk(dwFilenr, dwFuncnr, cdDir, value);
}

void ImportDirectory_setOriginalFirstThunk64(ImportDirectory<64>* module, dword dwFilenr, dword dwFuncnr, currdir cdDir, dword value)
{
	module->setOriginalFirstThunk(dwFilenr, dwFuncnr, cdDir, value);
}

dword ImportDirectory_getFirstThunk32_byName(ImportDirectory<32>* module, const std::string& strFilename, currdir cdDir)
{
	return module->getFirstThunk(strFilename, cdDir);
}

dword ImportDirectory_getFirstThunk64_byName(ImportDirectory<64>* module, const std::string& strFilename, currdir cdDir)
{
	return module->getFirstThunk(strFilename, cdDir);
}

dword ImportDirectory_getOriginalFirstThunk32_byName(ImportDirectory<32>* module, const std::string& strFilename, currdir cdDir)
{
	return module->getOriginalFirstThunk(strFilename, cdDir);
}

dword ImportDirectory_getOriginalFirstThunk64_byName(ImportDirectory<64>* module, const std::string& strFilename, currdir cdDir)
{
	return module->getOriginalFirstThunk(strFilename, cdDir);
}

dword ImportDirectory_getForwarderChain32_byName(ImportDirectory<32>* module, const std::string& strFilename, currdir cdDir)
{
	return module->getForwarderChain(strFilename, cdDir);
}

dword ImportDirectory_getForwarderChain64_byName(ImportDirectory<64>* module, const std::string& strFilename, currdir cdDir)
{
	return module->getForwarderChain(strFilename, cdDir);
}

dword ImportDirectory_getRvaOfName32_byName(ImportDirectory<32>* module, const std::string& strFilename, currdir cdDir)
{
	return module->getRvaOfName(strFilename, cdDir);
}

dword ImportDirectory_getRvaOfName64_byName(ImportDirectory<64>* module, const std::string& strFilename, currdir cdDir)
{
	return module->getRvaOfName(strFilename, cdDir);
}

dword ImportDirectory_getTimeDateStamp32_byName(ImportDirectory<32>* module, const std::string& strFilename, currdir cdDir)
{
	return module->getTimeDateStamp(strFilename, cdDir);
}

dword ImportDirectory_getTimeDateStamp64_byName(ImportDirectory<64>* module, const std::string& strFilename, currdir cdDir)
{
	return module->getTimeDateStamp(strFilename, cdDir);
}

dword ImportDirectory_getFirstThunk32(ImportDirectory<32>* module, dword dwFilenr, currdir cdDir)
{
	return module->getFirstThunk(dwFilenr, cdDir);
}

dword ImportDirectory_getFirstThunk64(ImportDirectory<64>* module, dword dwFilenr, currdir cdDir)
{
	return module->getFirstThunk(dwFilenr, cdDir);
}

void ImportDirectory_setFirstThunk32_byNumber_function(ImportDirectory<32>* module, dword dwFilenr, currdir cdDir, dword value)
{
	module->setFirstThunk(dwFilenr, cdDir, value);
}

void ImportDirectory_setFirstThunk64_byNumber_function(ImportDirectory<64>* module, dword dwFilenr, currdir cdDir, dword value)
{
	module->setFirstThunk(dwFilenr, cdDir, value);
}

dword ImportDirectory_getOriginalFirstThunk32(ImportDirectory<32>* module, dword dwFilenr, currdir cdDir)
{
	return module->getOriginalFirstThunk(dwFilenr, cdDir);
}

dword ImportDirectory_getOriginalFirstThunk64(ImportDirectory<64>* module, dword dwFilenr, currdir cdDir)
{
	return module->getOriginalFirstThunk(dwFilenr, cdDir);
}

void ImportDirectory_setOriginalFirstThunk32_byNumber_function(ImportDirectory<32>* module, dword dwFilenr, currdir cdDir, dword value)
{
	module->setOriginalFirstThunk(dwFilenr, cdDir, value);
}

void ImportDirectory_setOriginalFirstThunk64_byNumber_function(ImportDirectory<64>* module, dword dwFilenr, currdir cdDir, dword value)
{
	module->setOriginalFirstThunk(dwFilenr, cdDir, value);
}

dword ImportDirectory_getForwarderChain32_byNumber(ImportDirectory<32>* module, dword dwFilenr, currdir cdDir)
{
	return module->getForwarderChain(dwFilenr, cdDir);
}

dword ImportDirectory_getForwarderChain64_byNumber(ImportDirectory<64>* module, dword dwFilenr, currdir cdDir)
{
	return module->getForwarderChain(dwFilenr, cdDir);
}

void ImportDirectory_setForwarderChain32_byNumber_function(ImportDirectory<32>* module, dword dwFilenr, currdir cdDir, dword value)
{
	module->setForwarderChain(dwFilenr, cdDir, value);
}

void ImportDirectory_setForwarderChain64_byNumber_function(ImportDirectory<64>* module, dword dwFilenr, currdir cdDir, dword value)
{
	module->setForwarderChain(dwFilenr, cdDir, value);
}

dword ImportDirectory_getRvaOfName32_byNumber(ImportDirectory<32>* module, dword dwFilenr, currdir cdDir)
{
	return module->getRvaOfName(dwFilenr, cdDir);
}

dword ImportDirectory_getRvaOfName64_byNumber(ImportDirectory<64>* module, dword dwFilenr, currdir cdDir)
{
	return module->getRvaOfName(dwFilenr, cdDir);
}

void ImportDirectory_setRvaOfName32(ImportDirectory<32>* module, dword dwFilenr, currdir cdDir, dword value)
{
	module->setRvaOfName(dwFilenr, cdDir, value);
}

void ImportDirectory_setRvaOfName64(ImportDirectory<64>* module, dword dwFilenr, currdir cdDir, dword value)
{
	module->setRvaOfName(dwFilenr, cdDir, value);
}

dword ImportDirectory_getTimeDateStamp32(ImportDirectory<32>* module, dword dwFilenr, currdir cdDir)
{
	return module->getTimeDateStamp(dwFilenr, cdDir);
}

dword ImportDirectory_getTimeDateStamp64(ImportDirectory<64>* module, dword dwFilenr, currdir cdDir)
{
	return module->getTimeDateStamp(dwFilenr, cdDir);
}

void ImportDirectory_setTimeDateStamp32_byNumber(ImportDirectory<32>* module, dword dwFilenr, currdir cdDir, dword value)
{
	module->setTimeDateStamp(dwFilenr, cdDir, value);
}

void ImportDirectory_setTimeDateStamp64_byNumber(ImportDirectory<64>* module, dword dwFilenr, currdir cdDir, dword value)
{
	module->setTimeDateStamp(dwFilenr, cdDir, value);
}

bool MzHeader_isValid(MzHeader* module)
{
	return module->isValid();
}

bool MzHeader_isValid_field(MzHeader* module, PeLib::MzHeader::Field field)
{
	return module->isValid(field);
}

void MzHeader_makeValid(MzHeader* module)
{
	module->makeValid();
}

void MzHeader_makeValid_field(MzHeader* module, PeLib::MzHeader::Field field)
{
	module->makeValid(field);
}

int MzHeader_read(MzHeader* module, const std::string& strFilename)
{
	return module->read(strFilename);
}

int MzHeader_read_fromMemory(MzHeader* module, unsigned char* pcBuffer, unsigned int uiSize, unsigned int originalOffs = 0)
{
	return module->read(pcBuffer, uiSize, originalOffs);
}

void MzHeader_rebuild(MzHeader* module, std::vector<PeLib::byte>& vBuffer)
{
	module->rebuild(vBuffer);
}

int MzHeader_size(MzHeader* module)
{
	return module->size();
}

int MzHeader_write(MzHeader* module, const std::string& strFilename, dword dwOffset)
{
	return module->write(strFilename, dwOffset);
}

word MzHeader_getMagicNumber(MzHeader* module)
{
	return module->getMagicNumber();
}

word MzHeader_getBytesOnLastPage(MzHeader* module)
{
	return module->getBytesOnLastPage();
}

word MzHeader_getPagesInFile(MzHeader* module)
{
	return module->getPagesInFile();
}

word MzHeader_getRelocations(MzHeader* module)
{
	return module->getRelocations();
}

word MzHeader_getSizeOfHeader(MzHeader* module)
{
	return module->getSizeOfHeader();
}

word MzHeader_getMinExtraParagraphs(MzHeader* module)
{
	return module->getMinExtraParagraphs();
}

word MzHeader_getMaxExtraParagraphs(MzHeader* module)
{
	return module->getMaxExtraParagraphs();
}

word MzHeader_getSsValue(MzHeader* module)
{
	return module->getSsValue();
}

word MzHeader_getSpValue(MzHeader* module)
{
	return module->getSpValue();
}

word MzHeader_getChecksum(MzHeader* module)
{
	return module->getChecksum();
}

word MzHeader_getIpValue(MzHeader* module)
{
	return module->getIpValue();
}

word MzHeader_getCsValue(MzHeader* module)
{
	return module->getCsValue();
}

word MzHeader_getAddrOfRelocationTable(MzHeader* module)
{
	return module->getAddrOfRelocationTable();
}

word MzHeader_getOverlayNumber(MzHeader* module)
{
	return module->getOverlayNumber();
}

word MzHeader_getOemIdentifier(MzHeader* module)
{
	return module->getOemIdentifier();
}

word MzHeader_getOemInformation(MzHeader* module)
{
	return module->getOemInformation();
}

dword MzHeader_getAddressOfPeHeader(MzHeader* module)
{
	return module->getAddressOfPeHeader();
}

word MzHeader_getReservedWords1(MzHeader* module, unsigned int uiNr)
{
	return module->getReservedWords1(uiNr);
}

word MzHeader_getReservedWords2(MzHeader* module, unsigned int uiNr)
{
	return module->getReservedWords2(uiNr);
}

void MzHeader_setMagicNumber(MzHeader* module, word wValue)
{
	module->setMagicNumber(wValue);
}

void MzHeader_setBytesOnLastPage(MzHeader* module, word wValue)
{
	module->setBytesOnLastPage(wValue);
}

void MzHeader_setPagesInFile(MzHeader* module, word wValue)
{
	module->setPagesInFile(wValue);
}

void MzHeader_setRelocations(MzHeader* module, word wValue)
{
	module->setRelocations(wValue);
}

void MzHeader_setSizeOfHeader(MzHeader* module, word wValue)
{
	module->setSizeOfHeader(wValue);
}

void MzHeader_setMinExtraParagraphs(MzHeader* module, word wValue)
{
	module->setMinExtraParagraphs(wValue);
}

void MzHeader_setMaxExtraParagraphs(MzHeader* module, word wValue)
{
	module->setMaxExtraParagraphs(wValue);
}

void MzHeader_setSsValue(MzHeader* module, word wValue)
{
	module->setSsValue(wValue);
}

void MzHeader_setSpValue(MzHeader* module, word wValue)
{
	module->setSpValue(wValue);
}

void MzHeader_setChecksum(MzHeader* module, word wValue)
{
	module->setChecksum(wValue);
}

void MzHeader_setIpValue(MzHeader* module, word wValue)
{
	module->setIpValue(wValue);
}

void MzHeader_setCsValue(MzHeader* module, word wValue)
{
	module->setCsValue(wValue);
}

void MzHeader_setAddrOfRelocationTable(MzHeader* module, word wValue)
{
	module->setAddrOfRelocationTable(wValue);
}

void MzHeader_setOverlayNumber(MzHeader* module, word wValue)
{
	module->setOverlayNumber(wValue);
}

void MzHeader_setOemIdentifier(MzHeader* module, word wValue)
{
	module->setOemIdentifier(wValue);
}

void MzHeader_setOemInformation(MzHeader* module, word wValue)
{
	module->setOemInformation(wValue);
}

void MzHeader_setAddressOfPeHeader(MzHeader* module, dword dwValue)
{
	module->setAddressOfPeHeader(dwValue);
}

void MzHeader_setReservedWords1(MzHeader* module, unsigned int uiNr, word wValue)
{
	module->setReservedWords1(uiNr, wValue);
}

void MzHeader_setReservedWords2(MzHeader* module, unsigned int uiNr, word wValue)
{
	module->setReservedWords2(uiNr, wValue);
}

std::string PeFile_getFileName(PeFile* module)
{
	return module->getFileName();
}

void PeFile_setFileName(PeFile* module, std::string strFilename)
{
	module->setFileName(strFilename);
}

int PeFile_readMzHeader(PeFile* module)
{
	return module->readMzHeader();
}

int PeFile_readExportDirectory(PeFile* module)
{
	return module->readExportDirectory();
}

int PeFile_readPeHeader(PeFile* module)
{
	return module->readPeHeader();
}

int PeFile_readImportDirectory(PeFile* module)
{
	return module->readImportDirectory();
}

int PeFile_readBoundImportDirectory(PeFile* module)
{
	return module->readBoundImportDirectory();
}

int PeFile_readResourceDirectory(PeFile* module)
{
	return module->readResourceDirectory();
}

int PeFile_readRelocationsDirectory(PeFile* module)
{
	return module->readRelocationsDirectory();
}

int PeFile_readComHeaderDirectory(PeFile* module)
{
	return module->readComHeaderDirectory();
}

int PeFile_readIatDirectory(PeFile* module)
{
	return module->readIatDirectory();
}

int PeFile_readDebugDirectory(PeFile* module)
{
	return module->readDebugDirectory();
}

int PeFile_readTlsDirectory(PeFile* module)
{
	return module->readTlsDirectory();
}

MzHeader& PeFile_mzHeader(PeFile* module)
{
	return module->mzHeader();
}

ExportDirectory& PeFile_expDir(PeFile* module)
{
	return module->expDir();
}

BoundImportDirectory& PeFile_boundImpDir(PeFile* module)
{
	return module->boundImpDir();
}

ResourceDirectory& PeFile_resDir(PeFile* module)
{
	return module->resDir();
}

RelocationsDirectory& PeFile_relocDir(PeFile* module)
{
	return module->relocDir();
}

ComHeaderDirectory& PeFile_comDir(PeFile* module)
{
	return module->comDir();
}

IatDirectory& PeFile_iatDir(PeFile* module)
{
	return module->iatDir();
}

DebugDirectory& PeFile_debugDir(PeFile* module)
{
	return module->debugDir();
}

int PeHeaderT_addSection32(PeHeaderT<32>* module, const std::string& strName, dword dwSize)
{
	return module->addSection(strName, dwSize);
}

int PeHeaderT_addSection64(PeHeaderT<64>* module, const std::string& strName, dword dwSize)
{
	return module->addSection(strName, dwSize);
}

int PeHeaderT_calcSizeOfImage32(PeHeaderT<32>* module)
{
	return module->calcSizeOfImage();
}

int PeHeaderT_calcSizeOfImage64(PeHeaderT<64>* module)
{
	return module->calcSizeOfImage();
}

int PeHeaderT_calcSpaceAfterHeader32(PeHeaderT<32>* module)
{
	return module->calcSpaceAfterHeader();
}

int PeHeaderT_calcSpaceAfterHeader64(PeHeaderT<64>* module)
{
	return module->calcSpaceAfterHeader();
}

int PeHeaderT_calcStartOfCode32(PeHeaderT<32>* module)
{
	return module->calcStartOfCode();
}

int PeHeaderT_calcStartOfCode64(PeHeaderT<64>* module)
{
	return module->calcStartOfCode();
}

int PeHeaderT_calcOffset32(PeHeaderT<32>* module)
{
	return module->calcOffset();
}

int PeHeaderT_calcOffset64(PeHeaderT<64>* module)
{
	return module->calcOffset();
}

int PeHeaderT_calcRva32(PeHeaderT<32>* module)
{
	return module->calcRva();
}

int PeHeaderT_calcRva64(PeHeaderT<64>* module)
{
	return module->calcRva();
}

word PeHeaderT_calcNumberOfSections32(PeHeaderT<32>* module)
{
	return module->calcNumberOfSections();
}

word PeHeaderT_calcNumberOfSections64(PeHeaderT<64>* module)
{
	return module->calcNumberOfSections();
}

void PeHeaderT_enlargeLastSection32(PeHeaderT<32>* module, unsigned int uiSize)
{
	module->enlargeLastSection(uiSize);
}

void PeHeaderT_enlargeLastSection64(PeHeaderT<64>* module, unsigned int uiSize)
{
	module->enlargeLastSection(uiSize);
}

word PeHeaderT_getSectionWithOffset32(PeHeaderT<32>* module, dword dwOffset)
{
	return module->getSectionWithOffset(dwOffset);
}

word PeHeaderT_getSectionWithOffset64(PeHeaderT<64>* module, qword dwOffset)
{
	return module->getSectionWithOffset(dwOffset);
}

word PeHeaderT_getSectionWithRva32(PeHeaderT<32>* module, dword rva)
{
	return module->getSectionWithRva(rva);
}

word PeHeaderT_getSectionWithRva64(PeHeaderT<64>* module, qword rva)
{
	return module->getSectionWithRva(rva);
}

bool PeHeaderT_isValid32(PeHeaderT<32>* module, unsigned int foo)
{
	return module->isValid(foo);
}

bool PeHeaderT_isValid64(PeHeaderT<64>* module, unsigned int foo)
{
	return module->isValid(foo);
}

void PeHeaderT_makeValid32(PeHeaderT<32>* module, dword dwOffset)
{
	module->makeValid(dwOffset);
}

void PeHeaderT_makeValid64(PeHeaderT<64>* module, dword dwOffset)
{
	module->makeValid(dwOffset);
}

int PeHeaderT_offsetToRva32(PeHeaderT<32>* module, dword dwOffset)
{
	return module->offsetToRva(dwOffset);
}

int PeHeaderT_offsetToRva64(PeHeaderT<64>* module, qword dwOffset)
{
	return module->offsetToRva(dwOffset);
}

int PeHeaderT_offsetToVa32(PeHeaderT<32>* module, dword dwOffset)
{
	return module->offsetToVa(dwOffset);
}

int PeHeaderT_offsetToVa64(PeHeaderT<64>* module, qword dwOffset)
{
	return module->offsetToVa(dwOffset);
}

int PeHeaderT_read32(PeHeaderT<32>* module, std::string strFilename, unsigned int uiOffset)
{
	return module->read(strFilename, uiOffset);
}

int PeHeaderT_read64(PeHeaderT<64>* module, std::string strFilename, unsigned int uiOffset)
{
	return module->read(strFilename, uiOffset);
}

void PeHeaderT_rebuild32(PeHeaderT<32>* module, std::vector<PeLib::byte>& vBuffer)
{
	module->rebuild(vBuffer);
}

void PeHeaderT_rebuild64(PeHeaderT<64>* module, std::vector<PeLib::byte>& vBuffer)
{
	module->rebuild(vBuffer);
}

dword PeHeaderT_rvaToOffset32(PeHeaderT<32>* module, dword dwRva)
{
	return module->rvaToOffset(dwRva);
}

qword PeHeaderT_rvaToOffset64(PeHeaderT<64>* module, qword dwRva)
{
	return module->rvaToOffset(dwRva);
}

dword PeHeaderT_rvaToVa32(PeHeaderT<32>* module, dword dwRva)
{
	return module->rvaToVa(dwRva);
}

qword PeHeaderT_rvaToVa64(PeHeaderT<64>* module, qword dwRva)
{
	return module->rvaToVa(dwRva);
}

dword PeHeaderT_vaToRva32(PeHeaderT<32>* module, dword dwRva)
{
	return module->vaToRva(dwRva);
}

qword PeHeaderT_vaToRva64(PeHeaderT<64>* module, qword dwRva)
{
	return module->vaToRva(dwRva);
}

dword PeHeaderT_vaToOffset32(PeHeaderT<32>* module, dword dwRva)
{
	return module->vaToOffset(dwRva);
}

qword PeHeaderT_vaToOffset64(PeHeaderT<64>* module, qword dwRva)
{
	return module->vaToOffset(dwRva);
}

int PeHeaderT_write32(PeHeaderT<32>* module, std::string strFilename, unsigned int uiOffset)
{
	return module->write(strFilename, uiOffset);
}

int PeHeaderT_write64(PeHeaderT<64>* module, std::string strFilename, unsigned int uiOffset)
{
	return module->write(strFilename, uiOffset);
}

int PeHeaderT_writeSections32(PeHeaderT<32>* module, const std::string& strFilename)
{
	return module->writeSections(strFilename);
}

int PeHeaderT_writeSections64(PeHeaderT<64>* module, const std::string& strFilename)
{
	return module->writeSections(strFilename);
}

int PeHeaderT_writeSectionData32(PeHeaderT<32>* module, const std::string& strFilename, word wSecnr, const std::vector<PeLib::byte>& vBuffer)
{
	return module->writeSectionData(strFilename, wSecnr, vBuffer);
}

int PeHeaderT_writeSectionData64(PeHeaderT<64>* module, const std::string& strFilename, word wSecnr, const std::vector<PeLib::byte>& vBuffer)
{
	return module->writeSectionData(strFilename, wSecnr, vBuffer);
}

dword PeHeaderT_getNtSignature32(PeHeaderT<32>* module)
{
	return module->getNtSignature();
}

dword PeHeaderT_getNtSignature64(PeHeaderT<64>* module)
{
	return module->getNtSignature();
}

word PeHeaderT_getMachine32(PeHeaderT<32>* module)
{
	return module->getMachine();
}

word PeHeaderT_getMachine64(PeHeaderT<64>* module)
{
	return module->getMachine();
}

word PeHeaderT_getNumberOfSections32(PeHeaderT<32>* module)
{
	return module->getNumberOfSections();
}

word PeHeaderT_getNumberOfSections64(PeHeaderT<64>* module)
{
	return module->getNumberOfSections();
}

dword PeHeaderT_getTimeDateStamp32(PeHeaderT<32>* module)
{
	return module->getTimeDateStamp();
}

dword PeHeaderT_getTimeDateStamp64(PeHeaderT<64>* module)
{
	return module->getTimeDateStamp();
}

dword PeHeaderT_getPointerToSymbolTable32(PeHeaderT<32>* module)
{
	return module->getPointerToSymbolTable();
}

dword PeHeaderT_getPointerToSymbolTable64(PeHeaderT<64>* module)
{
	return module->getPointerToSymbolTable();
}

dword PeHeaderT_getNumberOfSymbols32(PeHeaderT<32>* module)
{
	return module->getNumberOfSymbols();
}

dword PeHeaderT_getNumberOfSymbols64(PeHeaderT<64>* module)
{
	return module->getNumberOfSymbols();
}

word PeHeaderT_getSizeOfOptionalHeader32(PeHeaderT<32>* module)
{
	return module->getSizeOfOptionalHeader();
}

word PeHeaderT_getSizeOfOptionalHeader64(PeHeaderT<64>* module)
{
	return module->getSizeOfOptionalHeader();
}

word PeHeaderT_getCharacteristics32(PeHeaderT<32>* module)
{
	return module->getCharacteristics();
}

word PeHeaderT_getCharacteristics64(PeHeaderT<64>* module)
{
	return module->getCharacteristics();
}

word PeHeaderT_getMagic32(PeHeaderT<32>* module)
{
	return module->getMagic();
}

word PeHeaderT_getMagic64(PeHeaderT<64>* module)
{
	return module->getMagic();
}

PeLib::byte PeHeaderT_getMajorLinkerVersion32(PeHeaderT<32>* module)
{
	return module->getMajorLinkerVersion();
}

PeLib::byte PeHeaderT_getMajorLinkerVersion64(PeHeaderT<64>* module)
{
	return module->getMajorLinkerVersion();
}

PeLib::byte PeHeaderT_getMinorLinkerVersion32(PeHeaderT<32>* module)
{
	return module->getMinorLinkerVersion();
}

PeLib::byte PeHeaderT_getMinorLinkerVersion64(PeHeaderT<64>* module)
{
	return module->getMinorLinkerVersion();
}

dword PeHeaderT_getSizeOfCode32(PeHeaderT<32>* module)
{
	return module->getSizeOfCode();
}

dword PeHeaderT_getSizeOfCode64(PeHeaderT<64>* module)
{
	return module->getSizeOfCode();
}

dword PeHeaderT_getSizeOfInitializedData32(PeHeaderT<32>* module)
{
	return module->getSizeOfInitializedData();
}

dword PeHeaderT_getSizeOfInitializedData64(PeHeaderT<64>* module)
{
	return module->getSizeOfInitializedData();
}

dword PeHeaderT_getSizeOfUninitializedData32(PeHeaderT<32>* module)
{
	return module->getSizeOfUninitializedData();
}

dword PeHeaderT_getSizeOfUninitializedData64(PeHeaderT<64>* module)
{
	return module->getSizeOfUninitializedData();
}

dword PeHeaderT_getAddressOfEntryPoint32(PeHeaderT<32>* module)
{
	return module->getAddressOfEntryPoint();
}

dword PeHeaderT_getAddressOfEntryPoint64(PeHeaderT<64>* module)
{
	return module->getAddressOfEntryPoint();
}

dword PeHeaderT_getBaseOfCode32(PeHeaderT<32>* module)
{
	return module->getBaseOfCode();
}

dword PeHeaderT_getBaseOfCode64(PeHeaderT<64>* module)
{
	return module->getBaseOfCode();
}

dword PeHeaderT_getImageBase32(PeHeaderT<32>* module)
{
	return module->getImageBase();
}

qword PeHeaderT_getImageBase64(PeHeaderT<64>* module)
{
	return module->getImageBase();
}

dword PeHeaderT_getSectionAlignment32(PeHeaderT<32>* module)
{
	return module->getSectionAlignment();
}

dword PeHeaderT_getSectionAlignment64(PeHeaderT<64>* module)
{
	return module->getSectionAlignment();
}

dword PeHeaderT_getFileAlignment32(PeHeaderT<32>* module)
{
	return module->getFileAlignment();
}

dword PeHeaderT_getFileAlignment64(PeHeaderT<64>* module)
{
	return module->getFileAlignment();
}

word PeHeaderT_getMajorOperatingSystemVersion32(PeHeaderT<32>* module)
{
	return module->getMajorOperatingSystemVersion();
}

word PeHeaderT_getMajorOperatingSystemVersion64(PeHeaderT<64>* module)
{
	return module->getMajorOperatingSystemVersion();
}

word PeHeaderT_getMinorOperatingSystemVersion32(PeHeaderT<32>* module)
{
	return module->getMinorOperatingSystemVersion();
}

word PeHeaderT_getMinorOperatingSystemVersion64(PeHeaderT<64>* module)
{
	return module->getMinorOperatingSystemVersion();
}

word PeHeaderT_getMajorImageVersion32(PeHeaderT<32>* module)
{
	return module->getMajorImageVersion();
}

word PeHeaderT_getMajorImageVersion64(PeHeaderT<64>* module)
{
	return module->getMajorImageVersion();
}

word PeHeaderT_getMinorImageVersion32(PeHeaderT<32>* module)
{
	return module->getMinorImageVersion();
}

word PeHeaderT_getMinorImageVersion64(PeHeaderT<64>* module)
{
	return module->getMinorImageVersion();
}

word PeHeaderT_getMajorSubsystemVersion32(PeHeaderT<32>* module)
{
	return module->getMajorSubsystemVersion();
}

word PeHeaderT_getMajorSubsystemVersion64(PeHeaderT<64>* module)
{
	return module->getMajorSubsystemVersion();
}

word PeHeaderT_getMinorSubsystemVersion32(PeHeaderT<32>* module)
{
	return module->getMinorSubsystemVersion();
}

word PeHeaderT_getMinorSubsystemVersion64(PeHeaderT<64>* module)
{
	return module->getMinorSubsystemVersion();
}

dword PeHeaderT_getWin32VersionValue32(PeHeaderT<32>* module)
{
	return module->getWin32VersionValue();
}

dword PeHeaderT_getWin32VersionValue64(PeHeaderT<64>* module)
{
	return module->getWin32VersionValue();
}

dword PeHeaderT_getSizeOfImage32(PeHeaderT<32>* module)
{
	return module->getSizeOfImage();
}

dword PeHeaderT_getSizeOfImage64(PeHeaderT<64>* module)
{
	return module->getSizeOfImage();
}

dword PeHeaderT_getSizeOfHeaders32(PeHeaderT<32>* module)
{
	return module->getSizeOfHeaders();
}

dword PeHeaderT_getSizeOfHeaders64(PeHeaderT<64>* module)
{
	return module->getSizeOfHeaders();
}

dword PeHeaderT_getCheckSum32(PeHeaderT<32>* module)
{
	return module->getCheckSum();
}

dword PeHeaderT_getCheckSum64(PeHeaderT<64>* module)
{
	return module->getCheckSum();
}

word PeHeaderT_getSubsystem32(PeHeaderT<32>* module)
{
	return module->getSubsystem();
}

word PeHeaderT_getSubsystem64(PeHeaderT<64>* module)
{
	return module->getSubsystem();
}

word PeHeaderT_getDllCharacteristics32(PeHeaderT<32>* module)
{
	return module->getDllCharacteristics();
}

word PeHeaderT_getDllCharacteristics64(PeHeaderT<64>* module)
{
	return module->getDllCharacteristics();
}

dword PeHeaderT_getSizeOfStackReserve32(PeHeaderT<32>* module)
{
	return module->getSizeOfStackReserve();
}

qword PeHeaderT_getSizeOfStackReserve64(PeHeaderT<64>* module)
{
	return module->getSizeOfStackReserve();
}

dword PeHeaderT_getSizeOfStackCommit32(PeHeaderT<32>* module)
{
	return module->getSizeOfStackCommit();
}

qword PeHeaderT_getSizeOfStackCommit64(PeHeaderT<64>* module)
{
	return module->getSizeOfStackCommit();
}

dword PeHeaderT_getSizeOfHeapReserve32(PeHeaderT<32>* module)
{
	return module->getSizeOfHeapReserve();
}

qword PeHeaderT_getSizeOfHeapReserve64(PeHeaderT<64>* module)
{
	return module->getSizeOfHeapReserve();
}

dword PeHeaderT_getSizeOfHeapCommit32(PeHeaderT<32>* module)
{
	return module->getSizeOfHeapCommit();
}

qword PeHeaderT_getSizeOfHeapCommit64(PeHeaderT<64>* module)
{
	return module->getSizeOfHeapCommit();
}

dword PeHeaderT_getLoaderFlags32(PeHeaderT<32>* module)
{
	return module->getLoaderFlags();
}

dword PeHeaderT_getLoaderFlags64(PeHeaderT<64>* module)
{
	return module->getLoaderFlags();
}

dword PeHeaderT_getNumberOfRvaAndSizes32(PeHeaderT<32>* module)
{
	return module->getNumberOfRvaAndSizes();
}

dword PeHeaderT_getNumberOfRvaAndSizes64(PeHeaderT<64>* module)
{
	return module->getNumberOfRvaAndSizes();
}

dword PeHeaderT_calcNumberOfRvaAndSizes32(PeHeaderT<32>* module)
{
	return module->calcNumberOfRvaAndSizes();
}

dword PeHeaderT_calcNumberOfRvaAndSizes64(PeHeaderT<64>* module)
{
	return module->calcNumberOfRvaAndSizes();
}

void PeHeaderT_addDataDirectory32(PeHeaderT<32>* module)
{
	module->addDataDirectory();
}

void PeHeaderT_addDataDirectory64(PeHeaderT<64>* module)
{
	module->addDataDirectory();
}

void PeHeaderT_removeDataDirectory32(PeHeaderT<32>* module, dword index)
{
	module->removeDataDirectory(index);
}

void PeHeaderT_removeDataDirectory64(PeHeaderT<64>* module, dword index)
{
	module->removeDataDirectory(index);
}

dword PeHeaderT_getIddExportRva32(PeHeaderT<32>* module)
{
	return module->getIddExportRva();
}

dword PeHeaderT_getIddExportRva64(PeHeaderT<64>* module)
{
	return module->getIddExportRva();
}

dword PeHeaderT_getIddExportSize32(PeHeaderT<32>* module)
{
	return module->getIddExportSize();
}

dword PeHeaderT_getIddExportSize64(PeHeaderT<64>* module)
{
	return module->getIddExportSize();
}

dword PeHeaderT_getIddImportRva32(PeHeaderT<32>* module)
{
	return module->getIddImportRva();
}

dword PeHeaderT_getIddImportRva64(PeHeaderT<64>* module)
{
	return module->getIddImportRva();
}

dword PeHeaderT_getIddImportSize32(PeHeaderT<32>* module)
{
	return module->getIddImportSize();
}

dword PeHeaderT_getIddImportSize64(PeHeaderT<64>* module)
{
	return module->getIddImportSize();
}

dword PeHeaderT_getIddResourceRva32(PeHeaderT<32>* module)
{
	return module->getIddResourceRva();
}

dword PeHeaderT_getIddResourceRva64(PeHeaderT<64>* module)
{
	return module->getIddResourceRva();
}

dword PeHeaderT_getIddResourceSize32(PeHeaderT<32>* module)
{
	return module->getIddResourceSize();
}

dword PeHeaderT_getIddResourceSize64(PeHeaderT<64>* module)
{
	return module->getIddResourceSize();
}

dword PeHeaderT_getIddExceptionRva32(PeHeaderT<32>* module)
{
	return module->getIddExceptionRva();
}

dword PeHeaderT_getIddExceptionRva64(PeHeaderT<64>* module)
{
	return module->getIddExceptionRva();
}

dword PeHeaderT_getIddExceptionSize32(PeHeaderT<32>* module)
{
	return module->getIddExceptionSize();
}

dword PeHeaderT_getIddExceptionSize64(PeHeaderT<64>* module)
{
	return module->getIddExceptionSize();
}

dword PeHeaderT_getIddSecurityRva32(PeHeaderT<32>* module)
{
	return module->getIddSecurityRva();
}

dword PeHeaderT_getIddSecurityRva64(PeHeaderT<64>* module)
{
	return module->getIddSecurityRva();
}

dword PeHeaderT_getIddSecuritySize32(PeHeaderT<32>* module)
{
	return module->getIddSecuritySize();
}

dword PeHeaderT_getIddSecuritySize64(PeHeaderT<64>* module)
{
	return module->getIddSecuritySize();
}

dword PeHeaderT_getIddBaseRelocRva32(PeHeaderT<32>* module)
{
	return module->getIddBaseRelocRva();
}

dword PeHeaderT_getIddBaseRelocRva64(PeHeaderT<64>* module)
{
	return module->getIddBaseRelocRva();
}

dword PeHeaderT_getIddBaseRelocSize32(PeHeaderT<32>* module)
{
	return module->getIddBaseRelocSize();
}

dword PeHeaderT_getIddBaseRelocSize64(PeHeaderT<64>* module)
{
	return module->getIddBaseRelocSize();
}

dword PeHeaderT_getIddDebugRva32(PeHeaderT<32>* module)
{
	return module->getIddDebugRva();
}

dword PeHeaderT_getIddDebugRva64(PeHeaderT<64>* module)
{
	return module->getIddDebugRva();
}

dword PeHeaderT_getIddDebugSize32(PeHeaderT<32>* module)
{
	return module->getIddDebugSize();
}

dword PeHeaderT_getIddDebugSize64(PeHeaderT<64>* module)
{
	return module->getIddDebugSize();
}

dword PeHeaderT_getIddArchitectureRva32(PeHeaderT<32>* module)
{
	return module->getIddArchitectureRva();
}

dword PeHeaderT_getIddArchitectureRva64(PeHeaderT<64>* module)
{
	return module->getIddArchitectureRva();
}

dword PeHeaderT_getIddArchitectureSize32(PeHeaderT<32>* module)
{
	return module->getIddArchitectureSize();
}

dword PeHeaderT_getIddArchitectureSize64(PeHeaderT<64>* module)
{
	return module->getIddArchitectureSize();
}

dword PeHeaderT_getIddGlobalPtrRva32(PeHeaderT<32>* module)
{
	return module->getIddGlobalPtrRva();
}

dword PeHeaderT_getIddGlobalPtrRva64(PeHeaderT<64>* module)
{
	return module->getIddGlobalPtrRva();
}

dword PeHeaderT_getIddGlobalPtrSize32(PeHeaderT<32>* module)
{
	return module->getIddGlobalPtrSize();
}

dword PeHeaderT_getIddGlobalPtrSize64(PeHeaderT<64>* module)
{
	return module->getIddGlobalPtrSize();
}

dword PeHeaderT_getIddTlsRva32(PeHeaderT<32>* module)
{
	return module->getIddTlsRva();
}

dword PeHeaderT_getIddTlsRva64(PeHeaderT<64>* module)
{
	return module->getIddTlsRva();
}

dword PeHeaderT_getIddTlsSize32(PeHeaderT<32>* module)
{
	return module->getIddTlsSize();
}

dword PeHeaderT_getIddTlsSize64(PeHeaderT<64>* module)
{
	return module->getIddTlsSize();
}

dword PeHeaderT_getIddLoadConfigRva32(PeHeaderT<32>* module)
{
	return module->getIddLoadConfigRva();
}

dword PeHeaderT_getIddLoadConfigRva64(PeHeaderT<64>* module)
{
	return module->getIddLoadConfigRva();
}

dword PeHeaderT_getIddLoadConfigSize32(PeHeaderT<32>* module)
{
	return module->getIddLoadConfigSize();
}

dword PeHeaderT_getIddLoadConfigSize64(PeHeaderT<64>* module)
{
	return module->getIddLoadConfigSize();
}

dword PeHeaderT_getIddBoundImportRva32(PeHeaderT<32>* module)
{
	return module->getIddBoundImportRva();
}

dword PeHeaderT_getIddBoundImportRva64(PeHeaderT<64>* module)
{
	return module->getIddBoundImportRva();
}

dword PeHeaderT_getIddBoundImportSize32(PeHeaderT<32>* module)
{
	return module->getIddBoundImportSize();
}

dword PeHeaderT_getIddBoundImportSize64(PeHeaderT<64>* module)
{
	return module->getIddBoundImportSize();
}

dword PeHeaderT_getIddIatRva32(PeHeaderT<32>* module)
{
	return module->getIddIatRva();
}

dword PeHeaderT_getIddIatRva64(PeHeaderT<64>* module)
{
	return module->getIddIatRva();
}

dword PeHeaderT_getIddIatSize32(PeHeaderT<32>* module)
{
	return module->getIddIatSize();
}

dword PeHeaderT_getIddIatSize64(PeHeaderT<64>* module)
{
	return module->getIddIatSize();
}

dword PeHeaderT_getIddDelayImportRva32(PeHeaderT<32>* module)
{
	return module->getIddDelayImportRva();
}

dword PeHeaderT_getIddDelayImportRva64(PeHeaderT<64>* module)
{
	return module->getIddDelayImportRva();
}

dword PeHeaderT_getIddDelayImportSize32(PeHeaderT<32>* module)
{
	return module->getIddDelayImportSize();
}

dword PeHeaderT_getIddDelayImportSize64(PeHeaderT<64>* module)
{
	return module->getIddDelayImportSize();
}

dword PeHeaderT_getIddComHeaderRva32(PeHeaderT<32>* module)
{
	return module->getIddComHeaderRva();
}

dword PeHeaderT_getIddComHeaderRva64(PeHeaderT<64>* module)
{
	return module->getIddComHeaderRva();
}

dword PeHeaderT_getIddComHeaderSize32(PeHeaderT<32>* module)
{
	return module->getIddComHeaderSize();
}

dword PeHeaderT_getIddComHeaderSize64(PeHeaderT<64>* module)
{
	return module->getIddComHeaderSize();
}

dword PeHeaderT_getImageDataDirectoryRva32(PeHeaderT<32>* module, dword dwDirectory)
{
	return module->getImageDataDirectoryRva(dwDirectory);
}

dword PeHeaderT_getImageDataDirectoryRva64(PeHeaderT<64>* module, dword dwDirectory)
{
	return module->getImageDataDirectoryRva(dwDirectory);
}

dword PeHeaderT_getImageDataDirectorySize32(PeHeaderT<32>* module, dword dwDirectory)
{
	return module->getImageDataDirectorySize(dwDirectory);
}

dword PeHeaderT_getImageDataDirectorySize64(PeHeaderT<64>* module, dword dwDirectory)
{
	return module->getImageDataDirectorySize(dwDirectory);
}

std::string PeHeaderT_getSectionName32(PeHeaderT<32>* module, word uiSectionnr)
{
	return module->getSectionName(uiSectionnr);
}

std::string PeHeaderT_getSectionName64(PeHeaderT<64>* module, word uiSectionnr)
{
	return module->getSectionName(uiSectionnr);
}

dword PeHeaderT_getVirtualSize32(PeHeaderT<32>* module, word uiSectionnr)
{
	return module->getVirtualSize(uiSectionnr);
}

dword PeHeaderT_getVirtualSize64(PeHeaderT<64>* module, word uiSectionnr)
{
	return module->getVirtualSize(uiSectionnr);
}

dword PeHeaderT_getVirtualAddress32(PeHeaderT<32>* module, word uiSectionnr)
{
	return module->getVirtualAddress(uiSectionnr);
}

dword PeHeaderT_getVirtualAddress64(PeHeaderT<64>* module, word uiSectionnr)
{
	return module->getVirtualAddress(uiSectionnr);
}

dword PeHeaderT_getSizeOfRawData32(PeHeaderT<32>* module, word uiSectionnr)
{
	return module->getSizeOfRawData(uiSectionnr);
}

dword PeHeaderT_getSizeOfRawData64(PeHeaderT<64>* module, word uiSectionnr)
{
	return module->getSizeOfRawData(uiSectionnr);
}

dword PeHeaderT_getPointerToRawData32(PeHeaderT<32>* module, word uiSectionnr)
{
	return module->getPointerToRawData(uiSectionnr);
}

dword PeHeaderT_getPointerToRawData64(PeHeaderT<64>* module, word uiSectionnr)
{
	return module->getPointerToRawData(uiSectionnr);
}

dword PeHeaderT_getPointerToRelocations32(PeHeaderT<32>* module, word uiSectionnr)
{
	return module->getPointerToRelocations(uiSectionnr);
}

dword PeHeaderT_getPointerToRelocations64(PeHeaderT<64>* module, word uiSectionnr)
{
	return module->getPointerToRelocations(uiSectionnr);
}

dword PeHeaderT_getPointerToLinenumbers32(PeHeaderT<32>* module, word uiSectionnr)
{
	return module->getPointerToLinenumbers(uiSectionnr);
}

dword PeHeaderT_getPointerToLinenumbers64(PeHeaderT<64>* module, word uiSectionnr)
{
	return module->getPointerToLinenumbers(uiSectionnr);
}

dword PeHeaderT_getNumberOfRelocations32(PeHeaderT<32>* module, word uiSectionnr)
{
	return module->getNumberOfRelocations(uiSectionnr);
}

dword PeHeaderT_getNumberOfRelocations64(PeHeaderT<64>* module, word uiSectionnr)
{
	return module->getNumberOfRelocations(uiSectionnr);
}

dword PeHeaderT_getNumberOfLinenumbers32(PeHeaderT<32>* module, word uiSectionnr)
{
	return module->getNumberOfLinenumbers(uiSectionnr);
}

dword PeHeaderT_getNumberOfLinenumbers64(PeHeaderT<64>* module, word uiSectionnr)
{
	return module->getNumberOfLinenumbers(uiSectionnr);
}

dword PeHeaderT_getCharacteristics32_section(PeHeaderT<32>* module, word uiSectionnr)
{
	return module->getCharacteristics(uiSectionnr);
}

dword PeHeaderT_getCharacteristics64_section(PeHeaderT<64>* module, word uiSectionnr)
{
	return module->getCharacteristics(uiSectionnr);
}

void PeHeaderT_setNtSignature32(PeHeaderT<32>* module, dword value)
{
	module->setNtSignature(value);
}

void PeHeaderT_setNtSignature64(PeHeaderT<64>* module, dword value)
{
	module->setNtSignature(value);
}

void PeHeaderT_setMachine32(PeHeaderT<32>* module, word value)
{
	module->setMachine(value);
}

void PeHeaderT_setMachine64(PeHeaderT<64>* module, word value)
{
	module->setMachine(value);
}

void PeHeaderT_setNumberOfSections32(PeHeaderT<32>* module, word value)
{
	module->setNumberOfSections(value);
}

void PeHeaderT_setNumberOfSections64(PeHeaderT<64>* module, word value)
{
	module->setNumberOfSections(value);
}

void PeHeaderT_setTimeDateStamp32(PeHeaderT<32>* module, dword value)
{
	module->setTimeDateStamp(value);
}

void PeHeaderT_setTimeDateStamp64(PeHeaderT<64>* module, dword value)
{
	module->setTimeDateStamp(value);
}

void PeHeaderT_setPointerToSymbolTable32(PeHeaderT<32>* module, dword value)
{
	module->setPointerToSymbolTable(value);
}

void PeHeaderT_setPointerToSymbolTable64(PeHeaderT<64>* module, dword value)
{
	module->setPointerToSymbolTable(value);
}

void PeHeaderT_setNumberOfSymbols32(PeHeaderT<32>* module, dword value)
{
	module->setNumberOfSymbols(value);
}

void PeHeaderT_setNumberOfSymbols64(PeHeaderT<64>* module, dword value)
{
	module->setNumberOfSymbols(value);
}

void PeHeaderT_setSizeOfOptionalHeader32(PeHeaderT<32>* module, word value)
{
	module->setSizeOfOptionalHeader(value);
}

void PeHeaderT_setSizeOfOptionalHeader64(PeHeaderT<64>* module, word value)
{
	module->setSizeOfOptionalHeader(value);
}

void PeHeaderT_setCharacteristics32_section(PeHeaderT<32>* module, word value)
{
	module->setCharacteristics(value);
}

void PeHeaderT_setCharacteristics64_section(PeHeaderT<64>* module, word value)
{
	module->setCharacteristics(value);
}

void PeHeaderT_setMagic32(PeHeaderT<32>* module, word value)
{
	module->setMagic(value);
}

void PeHeaderT_setMagic64(PeHeaderT<64>* module, word value)
{
	module->setMagic(value);
}

void PeHeaderT_setMajorLinkerVersion32(PeHeaderT<32>* module, PeLib::byte value)
{
	module->setMajorLinkerVersion(value);
}

void PeHeaderT_setMajorLinkerVersion64(PeHeaderT<64>* module, PeLib::byte value)
{
	module->setMajorLinkerVersion(value);
}

void PeHeaderT_setMinorLinkerVersion32(PeHeaderT<32>* module, PeLib::byte value)
{
	module->setMinorLinkerVersion(value);
}

void PeHeaderT_setMinorLinkerVersion64(PeHeaderT<64>* module, PeLib::byte value)
{
	module->setMinorLinkerVersion(value);
}

void PeHeaderT_setSizeOfCode32(PeHeaderT<32>* module, dword value)
{
	module->setSizeOfCode(value);
}

void PeHeaderT_setSizeOfCode64(PeHeaderT<64>* module, dword value)
{
	module->setSizeOfCode(value);
}

void PeHeaderT_setSizeOfInitializedData32(PeHeaderT<32>* module, dword value)
{
	module->setSizeOfInitializedData(value);
}

void PeHeaderT_setSizeOfInitializedData64(PeHeaderT<64>* module, dword value)
{
	module->setSizeOfInitializedData(value);
}

void PeHeaderT_setSizeOfUninitializedData32(PeHeaderT<32>* module, dword value)
{
	module->setSizeOfUninitializedData(value);
}

void PeHeaderT_setSizeOfUninitializedData64(PeHeaderT<64>* module, dword value)
{
	module->setSizeOfUninitializedData(value);
}

void PeHeaderT_setAddressOfEntryPoint32(PeHeaderT<32>* module, dword value)
{
	module->setAddressOfEntryPoint(value);
}

void PeHeaderT_setAddressOfEntryPoint64(PeHeaderT<64>* module, dword value)
{
	module->setAddressOfEntryPoint(value);
}

void PeHeaderT_setBaseOfCode32(PeHeaderT<32>* module, dword value)
{
	module->setBaseOfCode(value);
}

void PeHeaderT_setBaseOfCode64(PeHeaderT<64>* module, dword value)
{
	module->setBaseOfCode(value);
}

void PeHeaderT_setImageBase32(PeHeaderT<32>* module, dword value)
{
	module->setImageBase(value);
}

void PeHeaderT_setImageBase64(PeHeaderT<64>* module, qword value)
{
	module->setImageBase(value);
}

void PeHeaderT_setSectionAlignment32(PeHeaderT<32>* module, dword value)
{
	module->setSectionAlignment(value);
}

void PeHeaderT_setSectionAlignment64(PeHeaderT<64>* module, dword value)
{
	module->setSectionAlignment(value);
}

void PeHeaderT_setFileAlignment32(PeHeaderT<32>* module, dword value)
{
	module->setFileAlignment(value);
}

void PeHeaderT_setFileAlignment64(PeHeaderT<64>* module, dword value)
{
	module->setFileAlignment(value);
}

void PeHeaderT_setMajorOperatingSystemVersion32(PeHeaderT<32>* module, word value)
{
	module->setMajorOperatingSystemVersion(value);
}

void PeHeaderT_setMajorOperatingSystemVersion64(PeHeaderT<64>* module, word value)
{
	module->setMajorOperatingSystemVersion(value);
}

void PeHeaderT_setMinorOperatingSystemVersion32(PeHeaderT<32>* module, word value)
{
	module->setMinorOperatingSystemVersion(value);
}

void PeHeaderT_setMinorOperatingSystemVersion64(PeHeaderT<64>* module, word value)
{
	module->setMinorOperatingSystemVersion(value);
}

void PeHeaderT_setMajorImageVersion32(PeHeaderT<32>* module, word value)
{
	module->setMajorImageVersion(value);
}

void PeHeaderT_setMajorImageVersion64(PeHeaderT<64>* module, word value)
{
	module->setMajorImageVersion(value);
}

void PeHeaderT_setMinorImageVersion32(PeHeaderT<32>* module, word value)
{
	module->setMinorImageVersion(value);
}

void PeHeaderT_setMinorImageVersion64(PeHeaderT<64>* module, word value)
{
	module->setMinorImageVersion(value);
}

void PeHeaderT_setMajorSubsystemVersion32(PeHeaderT<32>* module, word value)
{
	module->setMajorSubsystemVersion(value);
}

void PeHeaderT_setMajorSubsystemVersion64(PeHeaderT<64>* module, word value)
{
	module->setMajorSubsystemVersion(value);
}

void PeHeaderT_setMinorSubsystemVersion32(PeHeaderT<32>* module, word value)
{
	module->setMinorSubsystemVersion(value);
}

void PeHeaderT_setMinorSubsystemVersion64(PeHeaderT<64>* module, word value)
{
	module->setMinorSubsystemVersion(value);
}

void PeHeaderT_setWin32VersionValue32(PeHeaderT<32>* module, dword value)
{
	module->setWin32VersionValue(value);
}

void PeHeaderT_setWin32VersionValue64(PeHeaderT<64>* module, dword value)
{
	module->setWin32VersionValue(value);
}

void PeHeaderT_setSizeOfImage32(PeHeaderT<32>* module, dword value)
{
	module->setSizeOfImage(value);
}

void PeHeaderT_setSizeOfImage64(PeHeaderT<64>* module, dword value)
{
	module->setSizeOfImage(value);
}

void PeHeaderT_setSizeOfHeaders32(PeHeaderT<32>* module, dword value)
{
	module->setSizeOfHeaders(value);
}

void PeHeaderT_setSizeOfHeaders64(PeHeaderT<64>* module, dword value)
{
	module->setSizeOfHeaders(value);
}

void PeHeaderT_setCheckSum32(PeHeaderT<32>* module, dword value)
{
	module->setCheckSum(value);
}

void PeHeaderT_setCheckSum64(PeHeaderT<64>* module, dword value)
{
	module->setCheckSum(value);
}

void PeHeaderT_setSubsystem32(PeHeaderT<32>* module, word value)
{
	module->setSubsystem(value);
}

void PeHeaderT_setSubsystem64(PeHeaderT<64>* module, word value)
{
	module->setSubsystem(value);
}

void PeHeaderT_setDllCharacteristics32(PeHeaderT<32>* module, word value)
{
	module->setDllCharacteristics(value);
}

void PeHeaderT_setDllCharacteristics64(PeHeaderT<64>* module, word value)
{
	module->setDllCharacteristics(value);
}

void PeHeaderT_setSizeOfStackReserve32(PeHeaderT<32>* module, dword value)
{
	module->setSizeOfStackReserve(value);
}

void PeHeaderT_setSizeOfStackReserve64(PeHeaderT<64>* module, qword value)
{
	module->setSizeOfStackReserve(value);
}

void PeHeaderT_setSizeOfStackCommit32(PeHeaderT<32>* module, dword value)
{
	module->setSizeOfStackCommit(value);
}

void PeHeaderT_setSizeOfStackCommit64(PeHeaderT<64>* module, qword value)
{
	module->setSizeOfStackCommit(value);
}

void PeHeaderT_setSizeOfHeapReserve32(PeHeaderT<32>* module, dword value)
{
	module->setSizeOfHeapReserve(value);
}

void PeHeaderT_setSizeOfHeapReserve64(PeHeaderT<64>* module, qword value)
{
	module->setSizeOfHeapReserve(value);
}

void PeHeaderT_setSizeOfHeapCommit32(PeHeaderT<32>* module, dword value)
{
	module->setSizeOfHeapCommit(value);
}

void PeHeaderT_setSizeOfHeapCommit64(PeHeaderT<64>* module, qword value)
{
	module->setSizeOfHeapCommit(value);
}

void PeHeaderT_setLoaderFlags32(PeHeaderT<32>* module, dword value)
{
	module->setLoaderFlags(value);
}

void PeHeaderT_setLoaderFlags64(PeHeaderT<64>* module, dword value)
{
	module->setLoaderFlags(value);
}

void PeHeaderT_setNumberOfRvaAndSizes32(PeHeaderT<32>* module, dword value)
{
	module->setNumberOfRvaAndSizes(value);
}

void PeHeaderT_setNumberOfRvaAndSizes64(PeHeaderT<64>* module, dword value)
{
	module->setNumberOfRvaAndSizes(value);
}

void PeHeaderT_setIddDebugRva32(PeHeaderT<32>* module, dword dwValue)
{
	module->setIddDebugRva(dwValue);
}

void PeHeaderT_setIddDebugRva64(PeHeaderT<64>* module, dword dwValue)
{
	module->setIddDebugRva(dwValue);
}

void PeHeaderT_setIddDebugSize32(PeHeaderT<32>* module, dword dwValue)
{
	module->setIddDebugSize(dwValue);
}

void PeHeaderT_setIddDebugSize64(PeHeaderT<64>* module, dword dwValue)
{
	module->setIddDebugSize(dwValue);
}

void PeHeaderT_setIddDelayImportRva32(PeHeaderT<32>* module, dword dwValue)
{
	module->setIddDelayImportRva(dwValue);
}

void PeHeaderT_setIddDelayImportRva64(PeHeaderT<64>* module, dword dwValue)
{
	module->setIddDelayImportRva(dwValue);
}

void PeHeaderT_setIddDelayImportSize32(PeHeaderT<32>* module, dword dwValue)
{
	module->setIddDelayImportSize(dwValue);
}

void PeHeaderT_setIddDelayImportSize64(PeHeaderT<64>* module, dword dwValue)
{
	module->setIddDelayImportSize(dwValue);
}

void PeHeaderT_setIddExceptionRva32(PeHeaderT<32>* module, dword dwValue)
{
	module->setIddExceptionRva(dwValue);
}

void PeHeaderT_setIddExceptionRva64(PeHeaderT<64>* module, dword dwValue)
{
	module->setIddExceptionRva(dwValue);
}

void PeHeaderT_setIddExceptionSize32(PeHeaderT<32>* module, dword dwValue)
{
	module->setIddExceptionSize(dwValue);
}

void PeHeaderT_setIddExceptionSize64(PeHeaderT<64>* module, dword dwValue)
{
	module->setIddExceptionSize(dwValue);
}

void PeHeaderT_setIddGlobalPtrRva32(PeHeaderT<32>* module, dword dwValue)
{
	module->setIddGlobalPtrRva(dwValue);
}

void PeHeaderT_setIddGlobalPtrRva64(PeHeaderT<64>* module, dword dwValue)
{
	module->setIddGlobalPtrRva(dwValue);
}

void PeHeaderT_setIddGlobalPtrSize32(PeHeaderT<32>* module, dword dwValue)
{
	module->setIddGlobalPtrSize(dwValue);
}

void PeHeaderT_setIddGlobalPtrSize64(PeHeaderT<64>* module, dword dwValue)
{
	module->setIddGlobalPtrSize(dwValue);
}

void PeHeaderT_setIddIatRva32(PeHeaderT<32>* module, dword dwValue)
{
	module->setIddIatRva(dwValue);
}

void PeHeaderT_setIddIatRva64(PeHeaderT<64>* module, dword dwValue)
{
	module->setIddIatRva(dwValue);
}

void PeHeaderT_setIddIatSize32(PeHeaderT<32>* module, dword dwValue)
{
	module->setIddIatSize(dwValue);
}

void PeHeaderT_setIddIatSize64(PeHeaderT<64>* module, dword dwValue)
{
	module->setIddIatSize(dwValue);
}

void PeHeaderT_setIddLoadConfigRva32(PeHeaderT<32>* module, dword dwValue)
{
	module->setIddLoadConfigRva(dwValue);
}

void PeHeaderT_setIddLoadConfigRva64(PeHeaderT<64>* module, dword dwValue)
{
	module->setIddLoadConfigRva(dwValue);
}

void PeHeaderT_setIddLoadConfigSize32(PeHeaderT<32>* module, dword dwValue)
{
	module->setIddLoadConfigSize(dwValue);
}

void PeHeaderT_setIddLoadConfigSize64(PeHeaderT<64>* module, dword dwValue)
{
	module->setIddLoadConfigSize(dwValue);
}

void PeHeaderT_setIddResourceRva32(PeHeaderT<32>* module, dword dwValue)
{
	module->setIddResourceRva(dwValue);
}

void PeHeaderT_setIddResourceRva64(PeHeaderT<64>* module, dword dwValue)
{
	module->setIddResourceRva(dwValue);
}

void PeHeaderT_setIddResourceSize32(PeHeaderT<32>* module, dword dwValue)
{
	module->setIddResourceSize(dwValue);
}

void PeHeaderT_setIddResourceSize64(PeHeaderT<64>* module, dword dwValue)
{
	module->setIddResourceSize(dwValue);
}

void PeHeaderT_setIddSecurityRva32(PeHeaderT<32>* module, dword dwValue)
{
	module->setIddSecurityRva(dwValue);
}

void PeHeaderT_setIddSecurityRva64(PeHeaderT<64>* module, dword dwValue)
{
	module->setIddSecurityRva(dwValue);
}

void PeHeaderT_setIddSecuritySize32(PeHeaderT<32>* module, dword dwValue)
{
	module->setIddSecuritySize(dwValue);
}

void PeHeaderT_setIddSecuritySize64(PeHeaderT<64>* module, dword dwValue)
{
	module->setIddSecuritySize(dwValue);
}

void PeHeaderT_setIddTlsRva32(PeHeaderT<32>* module, dword dwValue)
{
	module->setIddTlsRva(dwValue);
}

void PeHeaderT_setIddTlsRva64(PeHeaderT<64>* module, dword dwValue)
{
	module->setIddTlsRva(dwValue);
}

void PeHeaderT_setIddTlsSize32(PeHeaderT<32>* module, dword dwValue)
{
	module->setIddTlsSize(dwValue);
}

void PeHeaderT_setIddTlsSize64(PeHeaderT<64>* module, dword dwValue)
{
	module->setIddTlsSize(dwValue);
}

void PeHeaderT_setIddImportRva32(PeHeaderT<32>* module, dword dwValue)
{
	module->setIddImportRva(dwValue);
}

void PeHeaderT_setIddImportRva64(PeHeaderT<64>* module, dword dwValue)
{
	module->setIddImportRva(dwValue);
}

void PeHeaderT_setIddImportSize32(PeHeaderT<32>* module, dword dwValue)
{
	module->setIddImportSize(dwValue);
}

void PeHeaderT_setIddImportSize64(PeHeaderT<64>* module, dword dwValue)
{
	module->setIddImportSize(dwValue);
}

void PeHeaderT_setIddExportRva32(PeHeaderT<32>* module, dword dwValue)
{
	module->setIddExportRva(dwValue);
}

void PeHeaderT_setIddExportRva64(PeHeaderT<64>* module, dword dwValue)
{
	module->setIddExportRva(dwValue);
}

void PeHeaderT_setIddExportSize32(PeHeaderT<32>* module, dword dwValue)
{
	module->setIddExportSize(dwValue);
}

void PeHeaderT_setIddExportSize64(PeHeaderT<64>* module, dword dwValue)
{
	module->setIddExportSize(dwValue);
}

void PeHeaderT_setSectionName32(PeHeaderT<32>* module, word uiSectionnr, std::string strName)
{
	module->setSectionName(uiSectionnr, strName);
}

void PeHeaderT_setSectionName64(PeHeaderT<64>* module, word uiSectionnr, std::string strName)
{
	module->setSectionName(uiSectionnr, strName);
}

void PeHeaderT_setVirtualSize32(PeHeaderT<32>* module, word uiSectionnr, dword dwValue)
{
	module->setVirtualSize(uiSectionnr, dwValue);
}

void PeHeaderT_setVirtualSize64(PeHeaderT<64>* module, word uiSectionnr, dword dwValue)
{
	module->setVirtualSize(uiSectionnr, dwValue);
}

void PeHeaderT_setVirtualAddress32(PeHeaderT<32>* module, word uiSectionnr, dword dwValue)
{
	module->setVirtualAddress(uiSectionnr, dwValue);
}

void PeHeaderT_setVirtualAddress64(PeHeaderT<64>* module, word uiSectionnr, dword dwValue)
{
	module->setVirtualAddress(uiSectionnr, dwValue);
}

void PeHeaderT_setSizeOfRawData32(PeHeaderT<32>* module, word uiSectionnr, dword dwValue)
{
	module->setSizeOfRawData(uiSectionnr, dwValue);
}

void PeHeaderT_setSizeOfRawData64(PeHeaderT<64>* module, word uiSectionnr, dword dwValue)
{
	module->setSizeOfRawData(uiSectionnr, dwValue);
}

void PeHeaderT_setPointerToRawData32(PeHeaderT<32>* module, word uiSectionnr, dword dwValue)
{
	module->setPointerToRawData(uiSectionnr, dwValue);
}

void PeHeaderT_setPointerToRawData64(PeHeaderT<64>* module, word uiSectionnr, dword dwValue)
{
	module->setPointerToRawData(uiSectionnr, dwValue);
}

void PeHeaderT_setPointerToRelocations32(PeHeaderT<32>* module, word uiSectionnr, dword dwValue)
{
	module->setPointerToRelocations(uiSectionnr, dwValue);
}

void PeHeaderT_setPointerToRelocations64(PeHeaderT<64>* module, word uiSectionnr, dword dwValue)
{
	module->setPointerToRelocations(uiSectionnr, dwValue);
}

void PeHeaderT_setPointerToLinenumbers32(PeHeaderT<32>* module, word uiSectionnr, dword dwValue)
{
	module->setPointerToLinenumbers(uiSectionnr, dwValue);
}

void PeHeaderT_setPointerToLinenumbers64(PeHeaderT<64>* module, word uiSectionnr, dword dwValue)
{
	module->setPointerToLinenumbers(uiSectionnr, dwValue);
}

void PeHeaderT_setNumberOfRelocations32(PeHeaderT<32>* module, word uiSectionnr, dword dwValue)
{
	module->setNumberOfRelocations(uiSectionnr, dwValue);
}

void PeHeaderT_setNumberOfRelocations64(PeHeaderT<64>* module, word uiSectionnr, dword dwValue)
{
	module->setNumberOfRelocations(uiSectionnr, dwValue);
}

void PeHeaderT_setNumberOfLinenumbers32(PeHeaderT<32>* module, word uiSectionnr, dword dwValue)
{
	module->setNumberOfLinenumbers(uiSectionnr, dwValue);
}

void PeHeaderT_setNumberOfLinenumbers64(PeHeaderT<64>* module, word uiSectionnr, dword dwValue)
{
	module->setNumberOfLinenumbers(uiSectionnr, dwValue);
}

void PeHeaderT_setCharacteristics32(PeHeaderT<32>* module, word uiSectionnr, dword dwValue)
{
	module->setCharacteristics(uiSectionnr, dwValue);
}

void PeHeaderT_setCharacteristics64(PeHeaderT<64>* module, word uiSectionnr, dword dwValue)
{
	module->setCharacteristics(uiSectionnr, dwValue);
}

dword PeHeader32_getBaseOfData(PeHeader32* module)
{
	return module->getBaseOfData();
}

void PeHeader32_setBaseOfData(PeHeader32* module, dword value)
{
	module->setBaseOfData(value);
}

int RelocationsDirectory_getNumberOfRelocations(RelocationsDirectory* module)
{
	return module->getNumberOfRelocations();
}

int RelocationsDirectory_getNumberOfRelocationData(RelocationsDirectory* module, unsigned int ulRelocation)
{
	return module->getNumberOfRelocationData(ulRelocation);
}

int RelocationsDirectory_read(RelocationsDirectory* module, const std::string& strFilename, unsigned int uiOffset, unsigned int uiSize)
{
	return module->read(strFilename, uiOffset, uiSize);
}

void RelocationsDirectory_rebuild(RelocationsDirectory* module, std::vector<PeLib::byte>& vBuffer)
{
	module->rebuild(vBuffer);
}

int RelocationsDirectory_size(RelocationsDirectory* module)
{
	return module->size();
}

int RelocationsDirectory_write(RelocationsDirectory* module, const std::string& strFilename, unsigned int dwOffset)
{
	return module->write(strFilename, dwOffset);
}

dword RelocationsDirectory_getVirtualAddress(RelocationsDirectory* module, unsigned int ulRelocation)
{
	return module->getVirtualAddress(ulRelocation);
}

dword RelocationsDirectory_getSizeOfBlock(RelocationsDirectory* module, unsigned int ulRelocation)
{
	return module->getSizeOfBlock(ulRelocation);
}

word RelocationsDirectory_getRelocationData(RelocationsDirectory* module, unsigned int ulRelocation, unsigned int ulDataNumber)
{
	return module->getRelocationData(ulRelocation, ulDataNumber);
}

void RelocationsDirectory_setRelocationData(RelocationsDirectory* module, unsigned int ulRelocation, unsigned int ulDataNumber, word wData)
{
	module->setRelocationData(ulRelocation, ulDataNumber, wData);
}

void RelocationsDirectory_setVirtualAddress(RelocationsDirectory* module, unsigned int ulRelocation, dword dwValue)
{
	module->setVirtualAddress(ulRelocation, dwValue);
}

void RelocationsDirectory_setSizeOfBlock(RelocationsDirectory* module, unsigned int ulRelocation, dword dwValue)
{
	module->setSizeOfBlock(ulRelocation, dwValue);
}

void RelocationsDirectory_addRelocationData(RelocationsDirectory* module, unsigned int ulRelocation, word wValue)
{
	module->addRelocationData(ulRelocation, wValue);
}

void RelocationsDirectory_removeRelocationData(RelocationsDirectory* module, unsigned int ulRelocation, word wValue)
{
	module->removeRelocationData(ulRelocation, wValue);
}

bool ResourceChild_equalId(ResourceChild* module, dword wId)
{
	return module->equalId(wId);
}

bool ResourceChild_equalName(ResourceChild* module, std::string strName)
{
	return module->equalName(strName);
}

bool ResourceChild_isNamedResource(ResourceChild* module)
{
	return module->isNamedResource();
}

int ResourceElement_getElementRva(ResourceElement* module)
{
	return module->getElementRva();
}

bool ResourceElement_isLeaf(ResourceElement* module)
{
	return module->isLeaf();
}

void ResourceElement_makeValid(ResourceElement* module)
{
	module->makeValid();
}

bool ResourceLeaf_isLeaf(ResourceLeaf* module)
{
	return module->isLeaf();
}

void ResourceLeaf_makeValid(ResourceLeaf* module)
{
	module->makeValid();
}

std::vector<PeLib::byte> ResourceLeaf_getData(ResourceLeaf* module)
{
	return module->getData();
}

void ResourceLeaf_setData(ResourceLeaf* module, const std::vector<PeLib::byte>& vData)
{
	module->setData(vData);
}

dword ResourceLeaf_getOffsetToData(ResourceLeaf* module)
{
	return module->getOffsetToData();
}

dword ResourceLeaf_getSize(ResourceLeaf* module)
{
	return module->getSize();
}

dword ResourceLeaf_getCodePage(ResourceLeaf* module)
{
	return module->getCodePage();
}

dword ResourceLeaf_getReserved(ResourceLeaf* module)
{
	return module->getReserved();
}

void ResourceLeaf_setOffsetToData(ResourceLeaf* module, dword dwValue)
{
	module->setOffsetToData(dwValue);
}

void ResourceLeaf_setSize(ResourceLeaf* module, dword dwValue)
{
	module->setSize(dwValue);
}

void ResourceLeaf_setCodePage(ResourceLeaf* module, dword dwValue)
{
	module->setCodePage(dwValue);
}

void ResourceLeaf_setReserved(ResourceLeaf* module, dword dwValue)
{
	module->setReserved(dwValue);
}

bool ResourceNode_isLeaf(ResourceNode* module)
{
	return module->isLeaf();
}

void ResourceNode_makeValid(ResourceNode* module)
{
	module->makeValid();
}

int ResourceNode_getNumberOfChildren(ResourceNode* module)
{
	return module->getNumberOfChildren();
}

void ResourceNode_addChild(ResourceNode* module)
{
	module->addChild();
}

ResourceElement* ResourceNode_getChild(ResourceNode* module, unsigned int uiIndex)
{
	return module->getChild(uiIndex);
}

void ResourceNode_removeChild(ResourceNode* module, unsigned int uiIndex)
{
	module->removeChild(uiIndex);
}

std::string ResourceNode_getChildName(ResourceNode* module, unsigned int uiIndex)
{
	return module->getChildName(uiIndex);
}

dword ResourceNode_getOffsetToChildName(ResourceNode* module, unsigned int uiIndex)
{
	return module->getOffsetToChildName(uiIndex);
}

dword ResourceNode_getOffsetToChildData(ResourceNode* module, unsigned int uiIndex)
{
	return module->getOffsetToChildData(uiIndex);
}

void ResourceNode_setChildName(ResourceNode* module, unsigned int uiIndex, const std::string& strNewName)
{
	module->setChildName(uiIndex, strNewName);
}

void ResourceNode_setOffsetToChildName(ResourceNode* module, unsigned int uiIndex, dword dwNewOffset)
{
	module->setOffsetToChildName(uiIndex, dwNewOffset);
}

void ResourceNode_setOffsetToChildData(ResourceNode* module, unsigned int uiIndex, dword dwNewOffset)
{
	module->setOffsetToChildData(uiIndex, dwNewOffset);
}

dword ResourceNode_getCharacteristics(ResourceNode* module)
{
	return module->getCharacteristics();
}

dword ResourceNode_getTimeDateStamp(ResourceNode* module)
{
	return module->getTimeDateStamp();
}

word ResourceNode_getMajorVersion(ResourceNode* module)
{
	return module->getMajorVersion();
}

word ResourceNode_getMinorVersion(ResourceNode* module)
{
	return module->getMinorVersion();
}

word ResourceNode_getNumberOfNamedEntries(ResourceNode* module)
{
	return module->getNumberOfNamedEntries();
}

word ResourceNode_getNumberOfIdEntries(ResourceNode* module)
{
	return module->getNumberOfIdEntries();
}

void ResourceNode_setCharacteristics(ResourceNode* module, dword value)
{
	module->setCharacteristics(value);
}

void ResourceNode_setTimeDateStamp(ResourceNode* module, dword value)
{
	module->setTimeDateStamp(value);
}

void ResourceNode_setMajorVersion(ResourceNode* module, word value)
{
	module->setMajorVersion(value);
}

void ResourceNode_setMinorVersion(ResourceNode* module, word value)
{
	module->setMinorVersion(value);
}

void ResourceNode_setNumberOfNamedEntries(ResourceNode* module, word value)
{
	module->setNumberOfNamedEntries(value);
}

void ResourceNode_setNumberOfIdEntries(ResourceNode* module, word value)
{
	module->setNumberOfIdEntries(value);
}

int TlsDirectory_read32(TlsDirectory<32>* module, const std::string& strFilename, unsigned int uiOffset, unsigned int uiSize)
{
	return module->read(strFilename, uiOffset, uiSize);
}

int TlsDirectory_read64(TlsDirectory<64>* module, const std::string& strFilename, unsigned int uiOffset, unsigned int uiSize)
{
	return module->read(strFilename, uiOffset, uiSize);
}

void TlsDirectory_rebuild32(TlsDirectory<32>* module, std::vector<PeLib::byte>& vBuffer)
{
	module->rebuild(vBuffer);
}

void TlsDirectory_rebuild64(TlsDirectory<64>* module, std::vector<PeLib::byte>& vBuffer)
{
	module->rebuild(vBuffer);
}

int TlsDirectory_size32(TlsDirectory<32>* module)
{
	return module->size();
}

int TlsDirectory_size64(TlsDirectory<64>* module)
{
	return module->size();
}

int TlsDirectory_write32(TlsDirectory<32>* module, const std::string& strFilename, unsigned int dwOffset)
{
	return module->write(strFilename, dwOffset);
}

int TlsDirectory_write64(TlsDirectory<64>* module, const std::string& strFilename, unsigned int dwOffset)
{
	return module->write(strFilename, dwOffset);
}

dword TlsDirectory_getStartAddressOfRawData32(TlsDirectory<32>* module)
{
	return module->getStartAddressOfRawData();
}

dword TlsDirectory_getStartAddressOfRawData64(TlsDirectory<64>* module)
{
	return module->getStartAddressOfRawData();
}

dword TlsDirectory_getEndAddressOfRawData32(TlsDirectory<32>* module)
{
	return module->getEndAddressOfRawData();
}

dword TlsDirectory_getEndAddressOfRawData64(TlsDirectory<64>* module)
{
	return module->getEndAddressOfRawData();
}

dword TlsDirectory_getAddressOfIndex32(TlsDirectory<32>* module)
{
	return module->getAddressOfIndex();
}

dword TlsDirectory_getAddressOfIndex64(TlsDirectory<64>* module)
{
	return module->getAddressOfIndex();
}

dword TlsDirectory_getAddressOfCallBacks32(TlsDirectory<32>* module)
{
	return module->getAddressOfCallBacks();
}

dword TlsDirectory_getAddressOfCallBacks64(TlsDirectory<64>* module)
{
	return module->getAddressOfCallBacks();
}

dword TlsDirectory_getSizeOfZeroFill32(TlsDirectory<32>* module)
{
	return module->getSizeOfZeroFill();
}

dword TlsDirectory_getSizeOfZeroFill64(TlsDirectory<64>* module)
{
	return module->getSizeOfZeroFill();
}

dword TlsDirectory_getCharacteristics32(TlsDirectory<32>* module)
{
	return module->getCharacteristics();
}

dword TlsDirectory_getCharacteristics64(TlsDirectory<64>* module)
{
	return module->getCharacteristics();
}

void TlsDirectory_setStartAddressOfRawData32(TlsDirectory<32>* module, dword dwValue)
{
	module->setStartAddressOfRawData(dwValue);
}

void TlsDirectory_setStartAddressOfRawData64(TlsDirectory<64>* module, dword dwValue)
{
	module->setStartAddressOfRawData(dwValue);
}

void TlsDirectory_setEndAddressOfRawData32(TlsDirectory<32>* module, dword dwValue)
{
	module->setEndAddressOfRawData(dwValue);
}

void TlsDirectory_setEndAddressOfRawData64(TlsDirectory<64>* module, dword dwValue)
{
	module->setEndAddressOfRawData(dwValue);
}

void TlsDirectory_setAddressOfIndex32(TlsDirectory<32>* module, dword dwValue)
{
	module->setAddressOfIndex(dwValue);
}

void TlsDirectory_setAddressOfIndex64(TlsDirectory<64>* module, dword dwValue)
{
	module->setAddressOfIndex(dwValue);
}

void TlsDirectory_setAddressOfCallBacks32(TlsDirectory<32>* module, dword dwValue)
{
	module->setAddressOfCallBacks(dwValue);
}

void TlsDirectory_setAddressOfCallBacks64(TlsDirectory<64>* module, dword dwValue)
{
	module->setAddressOfCallBacks(dwValue);
}

void TlsDirectory_setSizeOfZeroFill32(TlsDirectory<32>* module, dword dwValue)
{
	module->setSizeOfZeroFill(dwValue);
}

void TlsDirectory_setSizeOfZeroFill64(TlsDirectory<64>* module, dword dwValue)
{
	module->setSizeOfZeroFill(dwValue);
}

void TlsDirectory_setCharacteristics32(TlsDirectory<32>* module, dword dwValue)
{
	module->setCharacteristics(dwValue);
}

void TlsDirectory_setCharacteristics64(TlsDirectory<64>* module, dword dwValue)
{
	module->setCharacteristics(dwValue);
}

}

