#ifndef DELAYIMPORTDIRECTORY_H
#define DELAYIMPORTDIRECTORY_H

#include "PeLibAux.h"

namespace PeLib
{
	/// Class that handles the delay import directories.
	/**
	* This class handles the delay import directories.
	**/
	template<int bits>
	class DelayImportDirectory
	{
	private:
		typedef typename std::vector<PELIB_IMAGE_DELAY_IMPORT_DIRECTORY<bits> >::iterator DelayImpDirFileIterator;
		typedef typename std::vector<PELIB_IMAGE_DELAY_IMPORT_DIRECTORY<bits> >::const_iterator ConstDelayImpDirFileIterator;
		typedef typename std::vector<PELIB_THUNK_DATA<bits> >::iterator ThunkDataFileIterator;
		typedef typename std::vector<PELIB_THUNK_DATA<bits> >::const_iterator ConstThunkDataFileIterator;
		typedef typename FieldSizes<bits>::VAR4_8 VAR4_8;

		/// Stores information about imported DLLs.
		std::vector<PELIB_IMAGE_DELAY_IMPORT_DIRECTORY<bits> > m_vIdid;

		int readIat(PELIB_IMAGE_DELAY_IMPORT_DIRECTORY<bits>& idid, std::vector<VAR4_8>& vAddr, unsigned int uiFieldOffset, 
			std::ifstream& ifFile, unsigned int uiSize, const PeHeaderT<bits>& pehHeader);
		void rebuildIat(OutputBuffer& obBuffer, std::vector<VAR4_8>& vAddresses);

	public:
		/// Read a file's delay import directory.
		int read(const std::string& strFilename, unsigned int uiOffset, unsigned int uiSize, const PeHeaderT<bits>& pehHeader);
		/// Rebuild the delay import directory.
		void rebuild(std::vector<byte>& vBuffer, dword dwRva, bool fixEntries = true) const;
		/// Writes the delay import directory to a file.
		int write(const std::string& strFilename, unsigned int uiOffset, unsigned int uiRva, bool fixEntries = true);

		/// Returns the size of the delay import directory.
		unsigned int size() const;

		/// Returns the ID of a file through it's name.
		unsigned int getFileIndex(const std::string& strFilename);

		/// Returns the ordinal of an imported function.
		VAR4_8 getFunctionOrdinal(dword dwFilenr, dword dwItem) const;
		/// Sets the ordinal of an imported function.
		void setFunctionOrdinal(dword dwFilenr, dword dwItem, VAR4_8 value);

		/// Returns the hint of an imported function.
		word getFunctionHint(dword dwFilenr, dword dwItem) const;
		/// Sets the hint of an imported function.
		void setFunctionHint(dword dwFilenr, dword dwItem, word value);

		/// Returns the address of the name of the imported function.
		std::string getFunctionName(dword dwFilenr, dword dwItem) const;
		/// Sets the address of the name of the imported function.
		void setFunctionName(dword dwFilenr, dword dwItem, const std::string& value);

		/// Returns the IAT item of the delay import directory.
		dword getIatItem(dword dwFilenr, dword dwItem) const;
		/// Returns the bound IAT item of the delay import directory.
		dword getBoundIatItem(dword dwFilenr, dword dwItem) const;
		/// Returns the unload IAT item of the delay import directory.
		dword getUnloadIatItem(dword dwFilenr, dword dwItem) const;

		/// Sets the IAT item of the delay import directory.
		void setIatItem(dword dwFilenr, dword dwItem, dword Value);
		/// Sets the bound IAT item of the delay import directory.
		void setBoundIatItem(dword dwFilenr, dword dwItem, dword Value);
		/// Sets the unload IAT item of the delay import directory.
		void setUnloadIatItem(dword dwFilenr, dword dwItem, dword Value);

		/// Adds a file to the delay import directory.
		void addFile(const std::string& strFilename);

		/// Adds a function to the delay import directory.
		void addFunction(dword dwFilenr, const std::string& fname);
		/// Adds a function to the delay import directory.
		void addFunction(dword dwFilenr, word hint);

		/// Adds the IAT item of the delay import directory.
		void addIatItem(dword dwFilenr, VAR4_8 value);
		/// Adds the bound IAT item of the delay import directory.
		void addBoundIatItem(dword dwFilenr, VAR4_8 value);
		/// Adds the unload IAT item of the delay import directory.
		void addUnloadIatItem(dword dwFilenr, VAR4_8 value);

		/// Removes a function from the delay import directory
		int removeFunction(dword dwFilenr, const std::string& fname);
		/// Removes a function from the delay import directory
		int removeFunction(dword dwFilenr, word hint);

		/// Removes a IAT item from the delay import directory.
		void removeIatItem(dword dwFilenr, dword index);
		/// Removes a bound IAT item from the delay import directory.
		void removeBoundIatItem(dword dwFilenr, dword index);
		/// Removes a unload IAT item from the delay import directory.
		void removeUnloadIatItem(dword dwFilenr, dword index);

		/// Returns the number of files which are imported.
		dword getNumberOfFiles() const;

		/// Returns the number of IAT items
		dword getNumberOfIat(dword dwFilenr) const;
		/// Returns the number of INT items
		dword getNumberOfInt(dword dwFilenr) const;
		/// Returns the number of bound IAT items
		dword getNumberOfBoundIat(dword dwFilenr) const;
		/// Returns the number of unload IAT items
		dword getNumberOfUnloadIat(dword dwFilenr) const;

		/// Returns the name of an file.
		std::string getFileName(dword dwFilenr) const;
		/// Sets the name of an file.
		void setFileName(dword dwFilenr, const std::string &value);

		/// Returns the grAttrs value of a file.
		dword getAttributes(dword dwFilenr) const;
		/// Sets the grAttrs value of a file.
		void setAttributes(dword dwFilenr, dword value);

		/// Returns the szName value of a file.
		dword getAddressOfName(dword dwFilenr) const;
		/// Sets the szName value of a file.
		void setAddressOfName(dword dwFilenr, dword value);

		/// Returns the phmod value of a file.
		dword getModuleHandle(dword dwFilenr) const;
		/// Sets the phmod value of a file.
		void setModuleHandle(dword dwFilenr, dword value);
	
		/// Returns the pIAT value of a file.
		dword getIat(dword dwFilenr) const;
		/// Sets the pIAT value of a file.
		void setIat(dword dwFilenr, dword value);

		/// Returns the pINT value of a file.
		dword getInt(dword dwFilenr) const;
		/// Sets the pINT value of a file.
		void setInt(dword dwFilenr, dword value);

		/// Returns the pBoundIAT value of a file.
		dword getBoundIat(dword dwFilenr) const;
		/// Sets the pBoundIAT value of a file.
		void setBoundIat(dword dwFilenr, dword value);

		/// Returns the pUnloadIAT value of a file.
		dword getUnloadIat(dword dwFilenr) const;
		/// Sets the pUnloadIAT value of a file.
		void setUnloadIat(dword dwFilenr, dword value);
	
		/// Returns the dwTimeStamp value of a file.
		dword getTimeDateStamp(dword dwFilenr) const;
		/// Sets the dwTimeStamp value of a file.
		void setTimeDateStamp(dword dwFilenr, dword value); 
	};


	template<int bits>
	int DelayImportDirectory<bits>::readIat(PELIB_IMAGE_DELAY_IMPORT_DIRECTORY<bits>& idid, std::vector<VAR4_8>& vAddr, unsigned int uiFieldOffset, std::ifstream& ifFile, unsigned int uiFileSize, const PeHeaderT<bits>& pehHeader)
	{
		dword uiVaoft = *(dword*)((char*)(&idid.deldesc) + uiFieldOffset);

		if (uiVaoft)
		{
			if (idid.deldesc.grAttrs)
			{
				uiVaoft = static_cast<dword>(pehHeader.rvaToOffset(uiVaoft));
			}
			else
			{
				uiVaoft = static_cast<dword>(pehHeader.vaToOffset(uiVaoft));
			}

			ifFile.seekg(static_cast<unsigned int>(uiVaoft), std::ios_base::beg);

			VAR4_8 addr;
			do
			{
				if (uiFileSize < uiVaoft + sizeof(addr))
				{
					return ERROR_INVALID_FILE;
				}
				uiVaoft += sizeof(addr);
			
				ifFile.read(reinterpret_cast<char*>(&addr), sizeof(addr));
				if (addr) vAddr.push_back(addr);
			} while (addr);
		}

		return NO_ERROR;
	}

	template<int bits>
	void DelayImportDirectory<bits>::rebuildIat(OutputBuffer& obBuffer, std::vector<VAR4_8>& vAddresses)
	{
		for (unsigned int i=0;i<vAddresses.size();i++)
		{
			obBuffer << vAddresses[i];
		}
		obBuffer << (VAR4_8)0;
	}

	/**
	* Read an import directory from a file.
	* @param strFilename Name of the file which will be read.
	* @param uiOffset Offset of the delay import directory
	* @param uiSize Size of the delay import directory
	* @param pehHeader A valid PE header.
	**/
	template<int bits>
	int DelayImportDirectory<bits>::read(const std::string& strFilename, unsigned int uiOffset, unsigned int uiSize, const PeHeaderT<bits>& pehHeader)
	{
		std::ifstream ifFile(strFilename.c_str(), std::ios_base::binary);

		if (!ifFile)
		{
			return ERROR_OPENING_FILE;
		}
		
		unsigned int uiFileSize = fileSize(ifFile);
		
		if (uiFileSize < uiOffset + uiSize)
		{
			return ERROR_INVALID_FILE;
		}

		ifFile.seekg(uiOffset, std::ios_base::beg);

		std::vector<unsigned char> vDelayimportdirectory(uiSize);
		ifFile.read(reinterpret_cast<char*>(&vDelayimportdirectory[0]), uiSize);

		PELIB_IMAGE_DELAY_IMPORT_DIRECTORY <bits> ididCurr;
		unsigned int uiDesccounter = 0;

		InputBuffer inpBuffer(vDelayimportdirectory);

		std::vector<PELIB_IMAGE_DELAY_IMPORT_DIRECTORY<bits> > vIdidCurr;

		do // Read and store all descriptors
		{
			inpBuffer >> ididCurr.deldesc.grAttrs;
			inpBuffer >> ididCurr.deldesc.szName;
			inpBuffer >> ididCurr.deldesc.phmod;
			inpBuffer >> ididCurr.deldesc.pIAT;
			inpBuffer >> ididCurr.deldesc.pINT;
			inpBuffer >> ididCurr.deldesc.pBoundIAT;
			inpBuffer >> ididCurr.deldesc.pUnloadIAT;
			inpBuffer >> ididCurr.deldesc.dwTimeStamp;

			if (ididCurr.deldesc.szName != 0 || ididCurr.deldesc.pIAT != 0 || ididCurr.deldesc.pINT != 0)
			{
				vIdidCurr.push_back(ididCurr);
			}

			uiDesccounter++;

			if (uiSize < (uiDesccounter + 1) * PELIB_IMAGE_IMPORT_DESCRIPTOR::size()) break;
		} while (ididCurr.deldesc.szName != 0 || ididCurr.deldesc.pIAT != 0 || ididCurr.deldesc.pINT != 0);

		char namebuffer[2] = {0};
			
		// Name
		for (unsigned int i=0;i<vIdidCurr.size();i++)
		{
			if (vIdidCurr[i].deldesc.grAttrs)
			{
				ifFile.seekg(static_cast<unsigned int>(pehHeader.rvaToOffset(vIdidCurr[i].deldesc.szName)), std::ios_base::beg);
			}
			else
			{
				ifFile.seekg(static_cast<unsigned int>(pehHeader.vaToOffset(vIdidCurr[i].deldesc.szName)), std::ios_base::beg);
			}

			std::string dllname = "";
			
			do
			{
				ifFile.read(namebuffer, 1);
				if (!ifFile || !namebuffer[0]) break; // reached end of file or 0-byte
				dllname += namebuffer;
			} while (true);
			
			vIdidCurr[i].name = dllname;
		}

		for (unsigned int i=0;i<vIdidCurr.size();i++)
		{
			int iErrCode;
			iErrCode = readIat(vIdidCurr[i], vIdidCurr[i].impat, offsetof(PELIB_IMAGE_DELAY_IMPORT_DESCRIPTOR, pIAT), ifFile, uiFileSize, pehHeader);
			if (iErrCode)
				return iErrCode;
			iErrCode = readIat(vIdidCurr[i], vIdidCurr[i].boundiat, offsetof(PELIB_IMAGE_DELAY_IMPORT_DESCRIPTOR, pBoundIAT), ifFile, uiFileSize, pehHeader);
			if (iErrCode)
				return iErrCode;
			iErrCode = readIat(vIdidCurr[i], vIdidCurr[i].unloadiat, offsetof(PELIB_IMAGE_DELAY_IMPORT_DESCRIPTOR, pUnloadIAT), ifFile, uiFileSize, pehHeader);
			if (iErrCode)
				return iErrCode;
		}

		for (unsigned int i=0;i<vIdidCurr.size();i++)
		{
			dword uiVaoft;

			if (vIdidCurr[i].deldesc.grAttrs)
			{
				uiVaoft = static_cast<dword>(pehHeader.rvaToOffset(vIdidCurr[i].deldesc.pINT));
			}
			else
			{
				uiVaoft = static_cast<dword>(pehHeader.vaToOffset(vIdidCurr[i].deldesc.pINT));
			}

			ifFile.seekg(static_cast<unsigned int>(uiVaoft), std::ios_base::beg);

			PELIB_THUNK_DATA<bits> tdCurr;
			do
			{
				if (uiFileSize < uiVaoft + sizeof(tdCurr.itd.Ordinal))
				{
					return ERROR_INVALID_FILE;
				}
				uiVaoft += sizeof(tdCurr.itd.Ordinal);
				
				ifFile.read(reinterpret_cast<char*>(&tdCurr.itd.Ordinal), sizeof(tdCurr.itd.Ordinal));
				if (tdCurr.itd.Ordinal) vIdidCurr[i].impnt.push_back(tdCurr);
			} while (tdCurr.itd.Ordinal);
		}

		// Names
		for (unsigned int i=0;i<vIdidCurr.size();i++)
		{
			unsigned int j = 0;
			for (unsigned int j=0;j<vIdidCurr[i].impnt.size();j++)
			{
				if (vIdidCurr[i].impnt[j].itd.Ordinal & PELIB_IMAGE_ORDINAL_FLAGS<bits>::IMAGE_ORDINAL_FLAG)
				{
					vIdidCurr[i].impnt[j].hint  = 0;
					continue;
				}

				if (vIdidCurr[i].deldesc.grAttrs)
				{
					ifFile.seekg(static_cast<unsigned int>(pehHeader.rvaToOffset(vIdidCurr[i].impnt[j].itd.Ordinal)), std::ios_base::beg);
				}
				else
				{
					ifFile.seekg(static_cast<unsigned int>(pehHeader.vaToOffset(vIdidCurr[i].impnt[j].itd.Ordinal)), std::ios_base::beg);				
				}

				ifFile.read(reinterpret_cast<char*>(&vIdidCurr[i].impnt[j].hint), sizeof(vIdidCurr[i].impnt[j].hint));
					
				if (!ifFile)
					return ERROR_INVALID_FILE;

				std::string funcname = "";
				do
				{
					ifFile.read(namebuffer, 1);
					if (!ifFile || !namebuffer[0]) break; // reached end of file or 0-byte
					funcname += namebuffer;
				} while (true);
			
				vIdidCurr[i].impnt[j].fname = funcname;
			}
		}
		std::swap(vIdidCurr, m_vIdid);
		return NO_ERROR;
	}

	/**
	* Rebuilds the import directory.
	* @param vBuffer Buffer the rebuilt import directory will be written to.
	* @param dwRva The RVA of the DelayImportDirectory in the file.
	* @param fixEntries Fix entries in file.
	**/
	template<int bits>
	void DelayImportDirectory<bits>::rebuild(std::vector<byte>& vBuffer, dword dwRva, bool fixEntries) const
	{
		OutputBuffer obBuffer(vBuffer);
		unsigned int uiCuroft = dwRva + (static_cast<unsigned int>(m_vIdid.size()) + 1) * PELIB_IMAGE_DELAY_IMPORT_DESCRIPTOR::size();

		for (unsigned int i=0;i<m_vIdid.size();i++)
		{
			obBuffer << (fixEntries ? (dword)1 : m_vIdid[i].deldesc.grAttrs);
			obBuffer << (fixEntries ? uiCuroft : m_vIdid[i].deldesc.szName);
			uiCuroft += alignOffset(static_cast<unsigned int>(m_vIdid[i].name.size()) + 1, 4);
			obBuffer << m_vIdid[i].deldesc.phmod;
			obBuffer << (fixEntries ? uiCuroft : m_vIdid[i].deldesc.pIAT);
			uiCuroft += (static_cast<unsigned int>(m_vIdid[i].impat.size()) + 1) * sizeof(VAR4_8);
			obBuffer << (fixEntries ? uiCuroft : m_vIdid[i].deldesc.pINT);
			uiCuroft += (static_cast<unsigned int>(m_vIdid[i].impnt.size()) + 1) * sizeof(VAR4_8);
			obBuffer << (fixEntries ? uiCuroft : m_vIdid[i].deldesc.pBoundIAT);
			uiCuroft += (static_cast<unsigned int>(m_vIdid[i].boundiat.size()) + 1) * sizeof(VAR4_8);
			obBuffer << (fixEntries ? uiCuroft : m_vIdid[i].deldesc.pUnloadIAT);
			uiCuroft += (static_cast<unsigned int>(m_vIdid[i].unloadiat.size()) + 1) * sizeof(VAR4_8);
			obBuffer << m_vIdid[i].deldesc.dwTimeStamp;
		}

		obBuffer << (dword)0 << (dword)0 << (dword)0 << (dword)0 << (dword)0 << (dword)0 << (dword)0 << (dword)0;

		for (unsigned int i=0;i<m_vIdid.size();i++)
		{
			obBuffer.add(m_vIdid[i].name.c_str(), static_cast<unsigned int>(m_vIdid[i].name.size()) + 1);
			for (unsigned int j=0;j<alignOffset(m_vIdid[i].name.size() + 1, 4) - m_vIdid[i].name.size() - 1;j++)
			{
				obBuffer << (byte)0;
			}

			for (unsigned int j=0;j<m_vIdid[i].impat.size();j++)
			{
				obBuffer << m_vIdid[i].impat[j];
			}
			obBuffer << (VAR4_8)0;

			for (unsigned int j=0;j<m_vIdid[i].impnt.size();j++)
			{
				if (m_vIdid[i].impnt[j].itd.Ordinal & PELIB_IMAGE_ORDINAL_FLAGS<bits>::IMAGE_ORDINAL_FLAG
					|| fixEntries == false)
				{
					obBuffer << m_vIdid[i].impnt[j].itd.Ordinal;
				}
				else
				{
					obBuffer << uiCuroft;
					uiCuroft += alignOffset(static_cast<unsigned int>(m_vIdid[i].impnt[j].fname.size()) + 3, 2);
				}
			}
			obBuffer << (VAR4_8)0;
			
			for (unsigned int j=0;j<m_vIdid[i].boundiat.size();j++)
			{
				obBuffer << m_vIdid[i].boundiat[j];
			}
			obBuffer << (VAR4_8)0;

			for (unsigned int j=0;j<m_vIdid[i].unloadiat.size();j++)
			{
				obBuffer << m_vIdid[i].unloadiat[j];
			}
			obBuffer << (VAR4_8)0;
		}

		for (unsigned int i=0;i<m_vIdid.size();i++)
		{
			for (unsigned int j=0;j<m_vIdid[i].impnt.size();j++)
			{
				if (!(m_vIdid[i].impnt[j].itd.Ordinal & PELIB_IMAGE_ORDINAL_FLAGS<bits>::IMAGE_ORDINAL_FLAG))
				{
					obBuffer << m_vIdid[i].impnt[j].hint;
					obBuffer.add(m_vIdid[i].impnt[j].fname.c_str(), static_cast<unsigned int>(m_vIdid[i].impnt[j].fname.size()) + 1);

					if (alignOffset(static_cast<unsigned int>(m_vIdid[i].impnt[j].fname.size()) + 1, 2) - m_vIdid[i].impnt[j].fname.size() - 1)
					{
						obBuffer << (byte)0;
					}
				}
			}
		}
	}

	/**
	* Writes the current import directory to a file.
	* @param strFilename Name of the file.
	* @param uiOffset File Offset of the new delay import directory.
	* @param uiRva RVA which belongs to that file offset.
	**/
	template<int bits>
	int DelayImportDirectory<bits>::write(const std::string& strFilename, unsigned int uiOffset, unsigned int uiRva, bool fixEntries)
	{
		std::fstream ofFile(strFilename.c_str(), std::ios_base::in);
		
		if (!ofFile)
		{
			ofFile.clear();
			ofFile.open(strFilename.c_str(), std::ios_base::out | std::ios_base::binary);
		}
		else
		{
			ofFile.close();
			ofFile.open(strFilename.c_str(), std::ios_base::in | std::ios_base::out | std::ios_base::binary);
		}
		
		if (!ofFile)
		{
			return ERROR_OPENING_FILE;
		}

		ofFile.seekp(uiOffset, std::ios_base::beg);

		std::vector<byte> vBuffer;

		rebuild(vBuffer, uiRva, fixEntries);

		ofFile.write(reinterpret_cast<const char*>(&vBuffer[0]), vBuffer.size());
		ofFile.close();

		/*std::copy(m_vNewiid.begin(), m_vNewiid.end(), std::back_inserter(m_vOldiid));
		m_vNewiid.clear();*/
		
		return NO_ERROR;
	}

	/**
	* @return Size of the delay import directory.
	**/
	template<int bits>
	unsigned int DelayImportDirectory<bits>::size() const
	{
		return std::accumulate(m_vIdid.begin(), m_vIdid.end(), 0, accumulate<PELIB_IMAGE_DELAY_IMPORT_DIRECTORY<bits> >);
	}

	/**
	* Searches through the delay import directory and returns the number of the 
	* delay import directory entry which belongs to the given filename.
	* @param strFilename Name of the imported file.
	* @return The ID of an imported file.
	**/
	template<int bits>
	unsigned int DelayImportDirectory<bits>::getFileIndex(const std::string& strFilename)
	{
		for (unsigned int i=0;i<m_vIdid.size();i++)
		{
			if (!m_vIdid[i].name.compare(strFilename))
			{
				return i;
			}
		}
		return -1;
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @param dwItem ID of the imported function.
	* @return Ordinal of an imported function.
	**/
	template<int bits>
	typename DelayImportDirectory<bits>::VAR4_8 DelayImportDirectory<bits>::getFunctionOrdinal(dword dwFilenr, dword dwItem) const
	{
		return m_vIdid[dwFilenr].impnt[dwItem].itd.Ordinal;
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @param dwItem ID of the imported function.
	* @param value Ordinal of an imported function.
	**/
	template<int bits>
	void DelayImportDirectory<bits>::setFunctionOrdinal(dword dwFilenr, dword dwItem, VAR4_8 value)
	{
		m_vIdid[dwFilenr].impnt[dwItem].itd.Ordinal = value;
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @param dwItem ID of the imported function.
	* @return Hint of an imported function.
	**/
	template<int bits>
	word DelayImportDirectory<bits>::getFunctionHint(dword dwFilenr, dword dwItem) const
	{
		return m_vIdid[dwFilenr].impnt[dwItem].hint;
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @param dwItem ID of the imported function.
	* @param value Hint of an imported function.
	**/
	template<int bits>
	void DelayImportDirectory<bits>::setFunctionHint(dword dwFilenr, dword dwItem, word value)
	{
		m_vIdid[dwFilenr].impnt[dwItem].hint = value;
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @param dwItem ID of the imported function.
	* @return Name of an imported function.
	**/
	template<int bits>
	std::string DelayImportDirectory<bits>::getFunctionName(dword dwFilenr, dword dwItem) const
	{
		return m_vIdid[dwFilenr].impnt[dwItem].fname;
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @param dwItem ID of the imported function.
	* @param value Name of an imported function.
	**/
	template<int bits>
	void DelayImportDirectory<bits>::setFunctionName(dword dwFilenr, dword dwItem, const std::string& value)
	{
		m_vIdid[dwFilenr].impnt[dwItem].fname = value;
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @param dwItem ID of the IAT item.
	* @return Value of the IAT item.
	**/
	template<int bits>
	dword DelayImportDirectory<bits>::getIatItem(dword dwFilenr, dword dwItem) const
	{
		return m_vIdid[dwFilenr].impat[dwItem];
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @param dwItem ID of the bound IAT item.
	* @return Value of the bound IAT item.
	**/
	template<int bits>
	dword DelayImportDirectory<bits>::getBoundIatItem(dword dwFilenr, dword dwItem) const
	{
		return m_vIdid[dwFilenr].boundiat[dwItem];
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @param dwItem ID of the unload IAT item.
	* @return Value of the unload IAT item.
	**/
	template<int bits>
	dword DelayImportDirectory<bits>::getUnloadIatItem(dword dwFilenr, dword dwItem) const
	{
		return m_vIdid[dwFilenr].unloadiat[dwItem];
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @param dwItem ID of the IAT item.
	* @param value Value of the IAT item.
	**/
	template<int bits>
	void DelayImportDirectory<bits>::setIatItem(dword dwFilenr, dword dwItem, dword value)
	{
		m_vIdid[dwFilenr].impat[dwItem] = value;
	}
        	
	/**
	* @param dwFilenr ID of the imported file.
	* @param dwItem ID of the bound IAT item.
	* @param value Value of the bound IAT item.
	**/
	template<int bits>
	void DelayImportDirectory<bits>::setBoundIatItem(dword dwFilenr, dword dwItem, dword value)
	{
		return m_vIdid[dwFilenr].boundiat[dwItem] = value;
	}

	
	/**
	* @param dwFilenr ID of the imported file.
	* @param dwItem ID of the unload IAT item.
	* @param value Value of the unload IAT item.
	**/
	template<int bits>
	void DelayImportDirectory<bits>::setUnloadIatItem(dword dwFilenr, dword dwItem, dword value)
	{
		m_vIdid[dwFilenr].unloadiat[dwItem] = value;
	}

	/**
	* @param strFilename Name of the new imported file.
	**/
	template<int bits>
	void DelayImportDirectory<bits>::addFile(const std::string& strFilename)
	{
		PELIB_IMAGE_DELAY_IMPORT_DIRECTORY<bits> idid;
		idid.name = strFilename;
		m_vIdid.push_back(idid);
	}

	/**
	* Add another import (by Ordinal) to the current file.
	* @param dwFilenr ID of the imported file.
	* @param fname Name of the function in the DLL.
	**/
	template<int bits>
	void DelayImportDirectory<bits>::addFunction(dword dwFilenr, const std::string& fname)
	{
		PELIB_THUNK_DATA<bits> td;
		td.hint = 0;
		td.fname = fname;
		m_vIdid[dwFilenr].impnt.push_back(td);
	}

	/**
	* Add another import (by Ordinal) to the current file.
	* @param dwFilenr ID of the imported file.
	* @param ordinal The ordinal of the function in the DLL.
	**/
	template<int bits>
	void DelayImportDirectory<bits>::addFunction(dword dwFilenr, word ordinal)
	{
		PELIB_THUNK_DATA<bits> td;
		td.hint = ordinal;
		m_vIdid[dwFilenr].impnt.push_back(td);
	}
	
	/**
	* @param dwFilenr ID of the imported file.
	* @param value Value of the IAT item.
	**/
	template<int bits>
	void DelayImportDirectory<bits>::addIatItem(dword dwFilenr, VAR4_8 value)
	{
		m_vIdid[dwFilenr].impat.push_back(value);
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @param value Value of the bound IAT item.
	**/
	template<int bits>
	void DelayImportDirectory<bits>::addBoundIatItem(dword dwFilenr, VAR4_8 value)
	{
		m_vIdid[dwFilenr].boundiat.push_back(value);
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @param value Value of the unload IAT item.
	**/
	template<int bits>
	void DelayImportDirectory<bits>::addUnloadIatItem(dword dwFilenr, VAR4_8 value)
	{
		m_vIdid[dwFilenr].unloadiat.push_back(value);
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @param fname Name of the function which will be removed.
	**/
	template<int bits>
	int DelayImportDirectory<bits>::removeFunction(dword dwFilenr, const std::string& fname)
	{
		for (ThunkDataFileIterator i=m_vIdid[dwFilenr].impnt.begin();i!=m_vIdid[dwFilenr].impnt.end();i++)
		{
			if (!i->itd.fname.compare(fname))
			{
				m_vIdid[dwFilenr].impnt.erase(i);
				return 1;
			}
		}	
		return 0;
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @param hint The hint of the function which will be removed.
	**/
	template<int bits>
	int DelayImportDirectory<bits>::removeFunction(dword dwFilenr, word hint)
	{
		for (ThunkDataFileIterator i=m_vIdid[dwFilenr].impnt.begin();i!=m_vIdid[dwFilenr].impnt.end();i++)
		{
			if (i->hint == hint)
			{
				m_vIdid[dwFilenr].impnt.erase(i);
				return 1;
			}
		}
		return 0;
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @param value Value of the IAT item.
	**/
	template<int bits>
	void DelayImportDirectory<bits>::removeIatItem(dword dwFilenr, dword index)
	{
		m_vIdid[dwFilenr].impat.erase(m_vIdid[dwFilenr].impat.begin() + index);
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @param value Value of the bound IAT item.
	**/
	template<int bits>
	void DelayImportDirectory<bits>::removeBoundIatItem(dword dwFilenr, dword index)
	{
		m_vIdid[dwFilenr].boundiat.erase(m_vIdid[dwFilenr].boundiat.begin() + index);
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @param value Value of the unload IAT item.
	**/
	template<int bits>
	void DelayImportDirectory<bits>::removeUnloadIatItem(dword dwFilenr, dword index)
	{
		m_vIdid[dwFilenr].unloadiat.erase(m_vIdid[dwFilenr].unloadiat.begin() + index);
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @return Number of imported files.
	**/
	template<int bits>
	dword DelayImportDirectory<bits>::getNumberOfFiles() const
	{
		return m_vIdid.size();		
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @return Number of IAT items.
	**/
	template<int bits>
	dword DelayImportDirectory<bits>::getNumberOfIat(dword dwFilenr) const
	{
		return m_vIdid[dwFilenr].impat.size();		
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @return Number of INT items.
	**/
	template<int bits>
	dword DelayImportDirectory<bits>::getNumberOfInt(dword dwFilenr) const
	{
		return m_vIdid[dwFilenr].impnt.size();		
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @return Number of bound IAT items.
	**/
	template<int bits>
	dword DelayImportDirectory<bits>::getNumberOfBoundIat(dword dwFilenr) const
	{
		return m_vIdid[dwFilenr].boundiat.size();		
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @return Number of unload IAT items.
	**/
	template<int bits>
	dword DelayImportDirectory<bits>::getNumberOfUnloadIat(dword dwFilenr) const
	{
		return m_vIdid[dwFilenr].unloadiat.size();		
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @return Name of an imported file.
	**/
	template<int bits>
	std::string DelayImportDirectory<bits>::getFileName(dword dwFilenr) const
	{
		return m_vIdid[dwFilenr].name;
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @param value Name of an imported file.
	**/
	template<int bits>
	void DelayImportDirectory<bits>::setFileName(dword dwFilenr, const std::string &value)
	{
		m_vIdid[dwFilenr].name = value;
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @return grAttrs value of an imported file.
	**/
	template<int bits>
	dword DelayImportDirectory<bits>::getAttributes(dword dwFilenr) const
	{
		return m_vIdid[dwFilenr].deldesc.grAttrs;
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @param value grAttrs value of an imported file.
	**/
	template<int bits>
	void DelayImportDirectory<bits>::setAttributes(dword dwFilenr, dword value)
	{
		m_vIdid[dwFilenr].deldesc.grAttrs = value;
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @return szName value of an imported file.
	**/
	template<int bits>
	dword DelayImportDirectory<bits>::getAddressOfName(dword dwFilenr) const
	{
		return m_vIdid[dwFilenr].deldesc.szName;
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @param value szName value of an imported file.
	**/
	template<int bits>
	void DelayImportDirectory<bits>::setAddressOfName(dword dwFilenr, dword value)
	{
		m_vIdid[dwFilenr].deldesc.szName = value;
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @return phmod value of an imported file.
	**/
	template<int bits>
	dword DelayImportDirectory<bits>::getModuleHandle(dword dwFilenr) const
	{
		return m_vIdid[dwFilenr].deldesc.phmod;
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @param value phmod value of an imported file.
	**/
	template<int bits>
	void DelayImportDirectory<bits>::setModuleHandle(dword dwFilenr, dword value)
	{
		m_vIdid[dwFilenr].deldesc.phmod = value;
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @return pIAT value of an imported file.
	**/
	template<int bits>
	dword DelayImportDirectory<bits>::getIat(dword dwFilenr) const
	{
		return m_vIdid[dwFilenr].deldesc.pIAT;
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @param value pIAT value of an imported file.
	**/
	template<int bits>
	void DelayImportDirectory<bits>::setIat(dword dwFilenr, dword value)
	{
		m_vIdid[dwFilenr].deldesc.pIAT = value;
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @return pINT value of an imported file.
	**/
	template<int bits>
	dword DelayImportDirectory<bits>::getInt(dword dwFilenr) const
	{
		return m_vIdid[dwFilenr].deldesc.pINT;
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @param value pINT value of an imported file.
	**/
	template<int bits>
	void DelayImportDirectory<bits>::setInt(dword dwFilenr, dword value)
	{
		m_vIdid[dwFilenr].deldesc.pINT = value;
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @return pBoundIAT value of an imported file.
	**/
	template<int bits>
	dword DelayImportDirectory<bits>::getBoundIat(dword dwFilenr) const
	{
		return m_vIdid[dwFilenr].deldesc.pBoundIAT;
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @param value pBoundIAT value of an imported file.
	**/
	template<int bits>
	void DelayImportDirectory<bits>::setBoundIat(dword dwFilenr, dword value)
	{
		m_vIdid[dwFilenr].deldesc.pBoundIAT = value;
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @return pUnloadIAT value of an imported file.
	**/
	template<int bits>
	dword DelayImportDirectory<bits>::getUnloadIat(dword dwFilenr) const
	{
		return m_vIdid[dwFilenr].deldesc.pUnloadIAT;
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @param value pUnloadIAT value of an imported file.
	**/
	template<int bits>
	void DelayImportDirectory<bits>::setUnloadIat(dword dwFilenr, dword value)
	{
		m_vIdid[dwFilenr].deldesc.pUnloadIAT = value;
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @return dwTimeStamp value of an imported file.
	**/
	template<int bits>
	dword DelayImportDirectory<bits>::getTimeDateStamp(dword dwFilenr) const
	{
		return m_vIdid[dwFilenr].deldesc.dwTimeStamp;
	}

	/**
	* @param dwFilenr ID of the imported file.
	* @param value dwTimeStamp value of an imported file.
	**/
	template<int bits>
	void DelayImportDirectory<bits>::setTimeDateStamp(dword dwFilenr, dword value)
	{
		m_vIdid[dwFilenr].deldesc.dwTimeStamp = value;
	}

	typedef DelayImportDirectory<32> DelayImportDirectory32;
	typedef DelayImportDirectory<64> DelayImportDirectory64;
}

#endif