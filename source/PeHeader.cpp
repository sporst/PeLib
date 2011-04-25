/*
* PeHeader.cpp - Part of the PeLib library.
*
* Copyright (c) 2004 - 2005 Sebastian Porst (webmaster@the-interweb.com)
* All rights reserved.
*
* This software is licensed under the zlib/libpng License.
* For more details see http://www.opensource.org/licenses/zlib-license.php
* or the license information file (license.htm) in the root directory 
* of PeLib.
*/

#include "PeLibInc.h"
#include "PeHeader.h"

namespace PeLib
{
	template<>
	void PeHeaderT<32>::makeValidSpecific()
	{
		setMachine(PELIB_IMAGE_FILE_MACHINE_I386);
		dword dwCharacteristics = PELIB_IMAGE_FILE_EXECUTABLE_IMAGE | PELIB_IMAGE_FILE_32BIT_MACHINE;
		setCharacteristics(dwCharacteristics);
		setMagic(PELIB_IMAGE_NT_OPTIONAL_HDR32_MAGIC);
	}

	template<>
	void PeHeaderT<64>::makeValidSpecific()
	{
		setMachine(PELIB_IMAGE_FILE_MACHINE_AMD64);
		dword dwCharacteristics = PELIB_IMAGE_FILE_EXECUTABLE_IMAGE | PELIB_IMAGE_FILE_LARGE_ADDRESS_AWARE;
		setCharacteristics(dwCharacteristics);
		setMagic(PELIB_IMAGE_NT_OPTIONAL_HDR64_MAGIC);
	}

	template<>
	void PeHeaderT<32>::readBaseOfData(InputBuffer& ibBuffer, PELIB_IMAGE_NT_HEADERS<32>& header) const
	{
		ibBuffer >> header.OptionalHeader.BaseOfData;
	}
	
	template<>
	void PeHeaderT<64>::readBaseOfData(InputBuffer&, PELIB_IMAGE_NT_HEADERS<64>&) const
	{
	}
	
	template<>
	void PeHeaderT<32>::rebuildBaseOfData(OutputBuffer& obBuffer) const
	{
		obBuffer << m_inthHeader.OptionalHeader.BaseOfData;
	}
	
	template<>
	void PeHeaderT<64>::rebuildBaseOfData(OutputBuffer&) const
	{
	}
	
    template<>
    bool PeHeaderT<32>::isValid() const
    {
		return true;
    }
    
    template<>
    bool PeHeaderT<64>::isValid() const
    {
		return true;
    }
    
    template<>
    bool PeHeaderT<32>::isValid(unsigned int pehf) const
    {
    /*
        if (pehf == NtSignature)
        {
            return m_inthHeader.Signature == IMAGE_NT_SIGNATURE;
        }
        else if (pehf == NumberOfSections)
        {
            return getNumberOfSections() == calcNumberOfSections();
        }      */
        return false;
    }

    template<>
    bool PeHeaderT<64>::isValid(unsigned int pehf) const
    {
        return false;
    }

	/**
	* @return The BaseOfData value from the PE header.
	**/
	dword PeHeader32::getBaseOfData() const
	{
		return m_inthHeader.OptionalHeader.BaseOfData;
	}

	/**
	* Changes the file's BaseOfData.
	* @param dwValue New value.
	**/
	void PeHeader32::setBaseOfData(dword dwValue)
	{
		m_inthHeader.OptionalHeader.BaseOfData = dwValue;
	}

}
