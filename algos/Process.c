// Process communication test /////////////////////////////////

typedef struct INFO { 
	var Position; 
} INFO;
INFO *Own, *Other;

void main()
{
	if(!require(-2.14)) return;
	if(!zInit(2,sizeof(INFO))) { printf("Can't initialize process!"); return; } 
	printf("Process id %i", Core); 
	printf("\nMove the Other slider!"); 
	
	if(Core <= 1) zOpen(2,"-w 320");
	Own = zData(Core);
	Other = zData(3-Core); // Core is 1 or 2
	
	slider(1,1,1,100,"This",0);
	slider(2,1,1,100,"Other",0);
	while(wait(1)) {
		slider(1,Own->Position);
		Other->Position = slider(2);
	}
	zClose(2);
}
