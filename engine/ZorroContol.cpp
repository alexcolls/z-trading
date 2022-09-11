// ZorroTest.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//
       
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
// TODO: reference additional headers your program requires here
#include "ZorroControl.h"
// Zorro Control DLL ///////////////////////////////
//int zInit(int Num,int Size);
//void* zData(int Id);
//HANDLE zOpen(int Id, const char* Cmd);
//void zClose(int Id);
//int zStatus(int Id);
typedef int(*_zInit)(int,int);
typedef HANDLE(*_zOpen)(int,const char*);
typedef void(*_zClose)(int);
typedef int(*_zStatus)(int);
typedef void*(*_zData)(int);

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
    }
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
