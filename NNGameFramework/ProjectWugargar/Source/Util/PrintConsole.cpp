#include "PrintConsole.h"
#include <stdio.h>
#include <consoleapi.h>


CPrintConsole::CPrintConsole(void)
{
	AllocConsole();
	FILE *pFile;
	freopen_s(&pFile,"COUNT$", "wt", stdout);
}


CPrintConsole::~CPrintConsole(void)
{
	FreeConsole();
}
