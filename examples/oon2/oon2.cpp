/**
* oon2.cpp - Example program for the PeLib library.
* OON2 (The 2nd version of "Out of nowhere") creates a valid PE file
* from scratch. The creation of the header structures are automized
* as much as possible. The file produced by oon2 ("dummy.exe")
* shows a messagebox when you run it.
*
* Copyright (c) 2004 Sebastian Porst (webmaster@the-interweb.com)
* All rights reserved.
*
* This software is licensed under the zlib/libpng License.
* For more details see http://www.opensource.org/licenses/zlib-license.php
* or the license information file (license.htm) in the root directory 
* of PeLib.
**/

#include "../../source/PeLib.h"
#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::string strFilename = "dummy.exe";
	
	PeLib::PeFile32 f(strFilename);

	unsigned int uiSizeMzHeader = f.mzHeader().size();

	// At first we need a valid MZ header.
	std::cout << "Building MZ header..." << std::endl;
	f.mzHeader().setAddressOfPeHeader(uiSizeMzHeader);
	f.mzHeader().makeValid();
	f.mzHeader().write(strFilename, 0);

	// Then we need a valid PE header.
	std::cout << "Building PE header..." << std::endl;
	f.peHeader().setAddressOfEntryPoint(0x1000);
	f.peHeader().makeValid(uiSizeMzHeader);

	// We need a section for the code.
	std::cout << "Building Sections..." << std::endl;

	f.peHeader().addSection("PELIB", 0x200);
	f.peHeader().addSection("FOO", 0x200);
	f.peHeader().addSection("A", 0x200);
	f.peHeader().addSection("B", 0x200);
	f.peHeader().addSection("C", 0x200);
	unsigned uiImpDir = f.peHeader().getVirtualAddress(0) + 0x100;

	// After the section was added the PE header needs to be updated.
	// At least 5 directories need to exist in a valid PE file even though only the second
	// one will be used.
	f.peHeader().addDataDirectory();
	f.peHeader().addDataDirectory();
	f.peHeader().addDataDirectory();
	f.peHeader().addDataDirectory();
	f.peHeader().addDataDirectory();
	f.peHeader().addDataDirectory();
	f.peHeader().addDataDirectory();
	f.peHeader().addDataDirectory();
	f.peHeader().addDataDirectory();
	f.peHeader().setIddImportRva(uiImpDir);
	f.peHeader().setIddImportSize(f.impDir().size());
	f.peHeader().setImageBase(0x01000000);
	f.peHeader().setMajorSubsystemVersion(4);
	f.peHeader().setSubsystem(2);
	f.peHeader().makeValid(uiSizeMzHeader);

	f.peHeader().write(strFilename, uiSizeMzHeader);

	// Write the new section to the output file.
	f.peHeader().writeSections(f.getFileName());
	// Dummy.exe needs to import User32.dll's MessageBoxA to use it.
	std::cout << "Building Import Directory..." << std::endl;
	f.impDir().addFunction("User32.dll", "MessageBoxA");
	f.impDir().write(strFilename, f.peHeader().rvaToOffset(uiImpDir), uiImpDir);

	// Program code created with an assembler.
	char data[] = { 0x6A, 0x00,	// push	0
			0x68, 0x00, 0x00, 0x00, 0x00,	// push "PeLib"
			0x68, 0x00, 0x00, 0x00, 0x00,	// push "Built with PeLib"
			0x6A, 0x00,	// push 0
			0xFF, 0x15, 0x00, 0x00, 0x00, 0x00,	// call MessageBoxA
			0xC3,	// ret
			'B','u','i','l','t',' ',	// Data string
			'w','i','t','h',' ',
			'P','e','L','i','b',0x00};

	unsigned int uiOffset = f.peHeader().getPointerToRawData(0);

	// Update the program code with the necessary addresses for data and calls
	*(PeLib::dword*)(&data[3]) = f.peHeader().offsetToVa(uiOffset + 32);
	*(PeLib::dword*)(&data[8]) = f.peHeader().offsetToVa(uiOffset + 21);
	*(PeLib::dword*)(&data[16]) = f.peHeader().rvaToVa(uiImpDir + 0x28);

	// Write program code to file.
	std::cout << "Writing data..." << std::endl;
	std::vector<PeLib::byte> vData(data, data + sizeof(data)/sizeof(data[0]));
	f.peHeader().writeSectionData(f.getFileName(), 0, vData);
}
