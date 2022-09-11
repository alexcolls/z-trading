// ZorroControl.dll test /////////////////////////////////

void main()
{
	if(!require(-2.15)) return;
	if(!zInit(2,sizeof(int))) return quit("Can't initialize process!"); 
	int* Info = (int*)zData(1);
	*Info = 1+(int)random(99); // return a random number to the main process
	print(TO_CSV,"Returned: %i",*Info);
}
