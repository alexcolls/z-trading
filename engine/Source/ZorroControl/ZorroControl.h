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
