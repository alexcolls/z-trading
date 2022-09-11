
string Format = "+%m/%d/%Y %H:%M:%S,f3,f1,f2,f4,f6,f";

string t6 = ".t6";
string cv = ".csv";
string path = "D:\\IntrinioAdjustedForTB\\";	

function ChangeFormat(string in,string symb){
	dataNew(1,0,0);
	string InName = in;	
	strcat(symb,".t6");
	printf(InName);
	printf(symb);
	int Records = dataParse(1,Format,InName);
	if(Records) dataSave(1,symb);		
	dataNew(1,0,0);	
}





void main()
{			
	assetList("AssetsPrueba");
	
	string Name;
	while(Name = loop(Assets))
	{		
		string inName = "";
		
		strcpy(inName,path);
		strcat(inName,Name);
		strcat(inName,cv);
		
		ChangeFormat(inName,Name);			
	}	
}