/**
* isnatch.cpp - Example program for the PeLib library.
* ISnatch extracts icons from PE files.
*
* Copyright (c) 2004 Sebastian Porst (webmaster@the-interweb.com)
* All rights reserved.
*
* This software is licensed under the zlib/libpng License.
* For more details see http://www.opensource.org/licenses/zlib-license.php
* or the license information file (license.htm) in the root directory 
* of PeLib.
**/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <exception>
#include <algorithm>

#include "../../source/PeLib.h"
#include <windows.h>
/**
* Takes a filename including it's path, returns the filename without it's path.
* @param filename Filename with path.
* @return Filename without path.
**/
std::string extractFilename(const std::string& filename)
{
	std::string::size_type pos = filename.find_last_of("/");
	return pos == std::string::npos ? filename : filename.substr(pos + 1, filename.size() - pos - 1);
}

/**
* Icon names have the structure "icons/filename_id.ico" where id is the id of the icon
* in the PE file, or at least some other number.
* @param filename Name of the PE file without any path.
* @param id Identifier of the icon.
* @return A string of the form "icons/filename_id.ico".
**/
std::string makeIconName(const std::string& filename, PeLib::word id)
{
	std::stringstream s;
	s << "icons/" << extractFilename(filename) << "_" << id << ".ico";
	return s.str();
}

/**
* Extracts all icons from a PE file.
* @param filename Name of the PE file.
**/
void extractIcons(const std::string& filename)
{
	std::cout << "Opening file: " << filename << std::endl;
	
	PeLib::PeFile* pef = PeLib::openPeFile(filename);
	
	if (!pef)
	{
		std::cout << "Not a valid PE file" << std::endl;
		return;
	}
	
	try
	{
		pef->readMzHeader();
		pef->readPeHeader();
		pef->readResourceDirectory();
	}
	catch(std::exception& e)
	{
		delete pef;
		std::cout << "Not a valid PE file." << std::endl << std::endl;
		return;
	}
	
	unsigned int icons = pef->resDir().getNumberOfResources(PeLib::PELIB_RT_ICON);
	unsigned int icongroups = pef->resDir().getNumberOfResources(PeLib::PELIB_RT_GROUP_ICON);
	
	if (icongroups == -1 || icons == -1)
	{
		std::cout << "No icons found." << std::endl << std::endl;
		delete pef;
		return;
	}
	
	std::cout << icons << " icons found in " << icongroups << " icon groups." << std::endl;

	std::vector<PeLib::byte> data;
	
	using PeLib::word;
	
	// Icons in ICO fils have a different header than icons in PE files.
	// The first six bytes never change for simple ICO files.
	char iconheader[22] = {0, 0, 1, 0, 1, 0};
	
	unsigned int icongroupindex = pef->resDir().resourceTypeIdToIndex(PeLib::PELIB_RT_GROUP_ICON);
	
	for (unsigned int i=0;i<icongroups;i++)
	{
		std::cout << "Reading icon group " << i + 1 << "." << std::endl;
		
//		std::cout << "OH :" << pef->resDir().getResourceIdByIndex(icongroupindex, i) << std::endl;
		
		pef->resDir().getResourceData(PeLib::PELIB_RT_GROUP_ICON, pef->resDir().getResourceIdByIndex(icongroupindex, i), data);
		
		word entries = *(word*)(&data[4]); // Number of icons in icon group.
		for (int j=0;j<entries;j++)
		{
			std::cout << "Reading icon " << j + 1<< "." << std::endl;
			
			// Parts of the icon header can be copied from the PE icon to the ICO icon.
			std::copy(data.begin() + 6 + j * 14, data.begin() + 6 + j * 14 + 12, iconheader + 6);
			*(word*)(&iconheader[18]) = 0x16;
			
			// Read the icon data.
			std::vector<PeLib::byte> icondata;
			word iconid = *(word*)(&data[6 + 12 + j * 14]);
			pef->resDir().getResourceData(PeLib::PELIB_RT_ICON, iconid, icondata);
			
			std::string iconname = makeIconName(filename, iconid);
			std::ofstream file(iconname.c_str(), std::ios::binary);
			if (file)
			{
				std::cout << "Writing icon " << j + 1 << " to file " << iconname << "." << std::endl;
	
				// Write the icon header followed by the icon data.
				file.write(iconheader, 22);
				file.write(reinterpret_cast<char*>(&icondata[0]), icondata.size());
			}
			else
			{
				std::cout << "Couldn't open file: " << iconname << ". Make sure the icons subdirectory exists." << std::endl;
			}
		}
	}
	delete pef;
	std::cout << std::endl;
}

/**
* Reads the icons of all files with file extension fileext in directory dirname.
* @param dirname A directory name.
* @param fileext A file extension of the form "*.exe" or "*.dll"
**/
void directoryExtraction(const std::string& dirname, const std::string& fileext)
{
	WIN32_FIND_DATA filedata;

	std::string filename = dirname + "/" + fileext;
	HANDLE h;
	
	if ((h = FindFirstFile(filename.c_str(), &filedata)) == INVALID_HANDLE_VALUE)
	{
		std::cout << "No files with extension " << fileext << " found." << std::endl;
		return;
	}
	
	do
	{
		extractIcons(dirname + "/" + filedata.cFileName);
	} while (FindNextFileA(h, &filedata));
	
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "usage: isnatch <[-f filename]|[-d directory]>" << std::endl;
		return 1;
	}
	
	// Replace all \ with / to allow easier path processing.
	std::replace(argv[2], argv[2] + strlen(argv[2]), '\\', '/');

	if (!strcmp(argv[1], "-f"))
	{
		extractIcons(argv[2]);
	}
	else if (!strcmp(argv[1], "-d"))
	{
		directoryExtraction(argv[2], "*.exe");
		directoryExtraction(argv[2], "*.dll");
	}
	else
	{
		std::cout << "Invalid first parameter" << std::endl;
		std::cout << "usage: isnatch <[-f filename]|[-d directory]>" << std::endl;
	}
}
