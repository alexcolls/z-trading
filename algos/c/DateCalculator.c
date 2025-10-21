// Date calculator ///////////////////////////////////

void main()
{
	slider(1,2019,2000,2020,"Year","");
	slider(2,1,1,12,"Month","");
	slider(3,1,1,31,"Day",""); 
	printf("W = Win, U = Unix, [Stop] to end");
	while(wait(100)) {
		var WinDate = dmy(slider(1)*10000+slider(2)*100+slider(3));
		print(TO_INFO,"W %.0f  U %i",WinDate,utm(WinDate));
	}
	printf("\n");
}