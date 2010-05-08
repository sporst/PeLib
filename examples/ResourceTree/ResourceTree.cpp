/**
* ResourceTree.cpp - Example program for the PeLib library.
* ResourceTree shows how to use low-level ResourceDirectory functions.
*
* Copyright (c) 2004 Sebastian Porst (webmaster@the-interweb.com)
* All rights reserved.
*
* This software is licensed under the zlib/libpng License.
* For more details see http:www.opensource.org/licenses/zlib-license.php
* or the license information file (license.htm) in the root directory 
* of PeLib.
**/

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "../../source/PeLib.h"

template<typename T>
std::string convert(T x)
{
	std::stringstream ss;
	ss << std::hex << std::uppercase << std::setw(8) << std::setfill('0') << x;
	return ss.str();
}

template<int bits>
void dumpResourceTree(const std::string& name, PeLib::ResourceElement* elem, std::string pad, const PeLib::PeHeaderT<bits>& peh)
{
	bool isLeaf = elem->isLeaf();
	
	std::cout << std::endl;
	std::cout << pad << "ResourceElement:      " << name << std::endl;
	std::cout << pad << "Type:                 " << (isLeaf ? "Leaf" : "Node") << std::endl;
	std::cout << pad << "RVA:                  " << std::setw(8) << std::setfill('0') << std::uppercase << std::hex << elem->getElementRva() << std::endl;
	std::cout << pad << "Offset:               " << std::setw(8) << std::setfill('0') << std::uppercase << std::hex << peh.rvaToOffset(elem->getElementRva()) << std::endl;
	
	if (isLeaf)
	{
		PeLib::ResourceLeaf* leaf = static_cast<PeLib::ResourceLeaf*>(elem);
		
		std::cout << pad << "OffsetToData:         " << std::setw(8) << std::setfill('0') << std::uppercase << std::hex << leaf->getOffsetToData() << std::endl;
		std::cout << pad << "Size:                 " << std::setw(8) << std::setfill('0') << std::uppercase << std::hex << leaf->getSize() << std::endl;
		std::cout << pad << "CodePage:             " << std::setw(8) << std::setfill('0') << std::uppercase << std::hex << leaf->getCodePage() << std::endl;
		std::cout << pad << "Reserved:             " << std::setw(8) << std::setfill('0') << std::uppercase << std::hex << leaf->getReserved() << std::endl;
	}
	else
	{
		PeLib::ResourceNode* node = static_cast<PeLib::ResourceNode*>(elem);
		
		unsigned int uiNamedEntries = node->getNumberOfNamedEntries();
		unsigned int uiIdEntries = node->getNumberOfIdEntries();
		
		std::cout << pad << "Characteristics:      " << std::setw(8) << std::setfill('0') << std::uppercase << std::hex << node->getCharacteristics() << std::endl;
		std::cout << pad << "TimeDateStamp:        " << std::setw(8) << std::setfill('0') << std::uppercase << std::hex << node->getTimeDateStamp() << std::endl;
		std::cout << pad << "MajorVersion:         " << std::setw(4) << std::setfill('0') << std::uppercase << std::hex << node->getMajorVersion() << std::endl;
		std::cout << pad << "MinorVersion:         " << std::setw(4) << std::setfill('0') << std::uppercase << std::hex << node->getMinorVersion() << std::endl;
		std::cout << pad << "NumberOfNamedEntries: " << std::setw(4) << std::setfill('0') << std::uppercase << std::hex << uiNamedEntries << std::endl;
		std::cout << pad << "NumberOfIdEntries:    " << std::setw(4) << std::setfill('0') << std::uppercase << std::hex << uiIdEntries << std::endl;
		
		for (unsigned int i=0;i<uiNamedEntries;i++)
		{
			PeLib::dword childOffset = node->getOffsetToChildName(i);
			PeLib::dword dataOffset = node->getOffsetToChildData(i);
			std::string childname = node->getChildName(i);
			
			dumpResourceTree(childname + " (Offset: " + convert(childOffset) + ")", node->getChild(i), pad + "\t", peh);
		}
		
		for (unsigned int i=0;i<uiIdEntries;i++)
		{
			PeLib::dword childOffset = node->getOffsetToChildName(i);
			PeLib::dword dataOffset = node->getOffsetToChildData(i);
			
			dumpResourceTree(convert(childOffset), node->getChild(i), pad + "\t", peh);
		}
	}
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cout << "Usage: ResourceTree filename" << std::endl;
		return 1;
	}

	std::string filename(argv[1]);
	
	PeLib::PeFile* f = PeLib::openPeFile(filename);
	
	if (!f)
	{
		std::cout << "Invalid PE file" << std::endl;
		return 2;
	}
	
	try
	{
		f->readMzHeader();
		f->readPeHeader();
		f->readResourceDirectory();
	}
	catch(...)
	{
		std::cout << "An error occured while reading the file. Maybe the file is not a valid PE file." << std::endl;
		delete f;
		return 3;
	}
	
	try
	{
		if (PeLib::getFileType(filename) == PeLib::PEFILE32)
		{
			dumpResourceTree("Root", f->resDir().getRoot(), "", static_cast<PeLib::PeFileT<32>*>(f)->peHeader());
		}
		else if (PeLib::getFileType(filename) == PeLib::PEFILE32)
		{
			dumpResourceTree("Root", f->resDir().getRoot(), "", static_cast<PeLib::PeFileT<64>*>(f)->peHeader());
		}
		else
		{
			std::cout << "Invalid PE file" << std::endl;
			delete f;
			return 2;
		}

	}
	catch(...)
	{
		std::cout << "An error occured while reading the resource directory. Maybe the directory is invalid." << std::endl;
		delete f;
		return 4;
	}
	
	delete f;
}
