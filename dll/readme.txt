PeLib DLL - Version 0.06 (alpha release)
=========================================

Copyright 2004 by Sebastian Porst
WWW: http://www.pelib.com
E-Mail: webmaster@the-interweb.com

=========================================

1. What is PeLib DLL?
2. Where can I find a documentation of PeLib DLL?
3. How do I build the DLL myself?

1. What is PeLib DLL?
   PeLib DLL is the PeLib library in DLL form. To learn
   more about PeLib visit http://www.pelib.com. Essentially
   it's an open-source C++ library for the modification of
   PE files. PeLib DLL provides the same functionality in
   DLL form to allow programs written in other languages
   than C++ to access PeLib's functionality.

   The PeLib.dll file you find in the PeLib distribution
   package is packed with UPX. If you compile the DLL yourself
   the filesize will be larger.

2. Where can I find a documentation of PeLib DLL?
   There is none yet. To find out which functions are
   exported by PeLib.dll check the PeLib.def file in
   the same directory you found this readme.txt file.
   The functions are identical to the PeLib functions
   with the same name, the only difference is that the
   PeLib DLL functions have a prefix ("XXX_") that indicates
   to which part of the PeLib library they belong to.
   As the functions are identical you can consult the PeLib
   documentation on http://www.pelib.com if you want to
   find out how to use the PeLib.dll functions.

   There are however some differences:
   - Whenever PeLib wants a string, PeLib.dll wants a
     pointer to a buffer and the size of the buffer.
   - Whenever PeLib wants a vector, PeLib.dll wants a
     pointer to a buffer and the size of the buffer.

   To find out the exact number and types of the parameters
   the individual functions expect you can check out
   the PeLib.cpp file you find in the directory you found
   this readme.txt file.

3. Assuming you have a working copy of g++ and you already
   built the PeLib.a file (see readme.txt in the source dir)
   go to the dll directory and enter
   
   make -f makefile.g++