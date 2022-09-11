// ZorroTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ZorroControl.h"

int _tmain(int argc, _TCHAR* argv[])
{
// open ZorroControl.dll and get its function pointers
	HINSTANCE H = LoadLibrary("ZorroControl.dll");
	if(!H) {
		printf("Can't mount ZorroControl.dll!"); return EXIT_FAILURE;
	}
	_zInit zInit = (_zInit)GetProcAddress(H,"zInit");
	_zOpen zOpen = (_zOpen)GetProcAddress(H,"zOpen");
	_zClose zClose = (_zClose)GetProcAddress(H,"zClose");
	_zStatus zStatus = (_zStatus)GetProcAddress(H,"zStatus");
	_zData zData = (_zData)GetProcAddress(H,"zData");

// initialize process communication
	if(!zInit(2,sizeof(int))) {
		printf("Can't initialize communication!"); return EXIT_FAILURE;
	}6

// get and clear the data area
	int* Info = (int*)zData(1);
	*Info = 0; 

// start minimized Zorro process
	if(!zOpen(2,"Control -run -h")) {	
		printf("Can't initialize Zorro process!"); return EXIT_FAILURE;
	}

// wait for Zorro's response (a random number from 1..100)
	while(*Info == 0) Sleep(100); 

// display it and quit
	printf("Zorro returned %i\n",*Info);
	zClose(2);
	Sleep(1000);
	return EXIT_SUCCESS;
}

