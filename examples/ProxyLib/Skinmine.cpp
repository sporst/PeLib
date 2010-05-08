#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <list>
#include <algorithm>
#include <iterator>
#include "ProxyLib.h"

// Note that you need ProxyLib and PeLib to compile this program.
// You can find both on http://www.pelib.com

int main()
{
	ProxyLib user33("user32.dll", "template.asm");
	user33.addImporter("winmine.exe");
	user33.addImportedFunction("AppendMenuA");
	user33.addImportedFunction("CallNextHookEx");
	user33.addImportedFunction("CreatePopupMenu");
	user33.addImportedFunction("GetMenuItemInfoA");
	user33.addImportedFunction("GetWindowThreadProcessId");
	user33.addImportedFunction("LoadMenuW");
	user33.addImportedFunction("SetWindowsHookExA");
	user33.make("user33");
	
	ProxyLib gdi33("gdi32.dll", "template.asm");
	gdi33.addImporter("winmine.exe");
	gdi33.addImportedFunction("LoadSkin");
	gdi33.make("gdi33");
}
