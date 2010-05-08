Description of the examples:

Directory	Language	Description
FileDump3	C++		Dumps a lot of information about the structure of a PE file
				to stdout. Comparable to Matt Pietrek's PeDump.
isnatch		C++		Extracts icons from files. Example for the ResourceDirectory class.
offs		MASM		Converts between RVA and file offset. Example for the PeLib DLL.
oon2		C++		oon stands for "Out of nowhere" and shows how to create a valid
				PE file from the scratch nothing but PeLib functions. All fields of the
				PE header are manually set.
ProxyLib	C++		Reads DLL files and creates MASM sources for DLL files that have the same
				exports as the read DLL file.
