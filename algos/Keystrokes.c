// Opens Notepad, writes something, saves it, and closes Notepad.
function main()
{
// start Notepad before 
	exec("Notepad.exe",0,0);
	printf("Waiting for notepad...");
   while(!window("Editor")) wait(100);  // wait until Notepad is open
	keys("Zorro is cool!"); 			// write something
	wait(500);
   keys("[Ctrl-]s");               	// open Save dialog (Ctrl-S) 
   while(!window(NULL)) wait(100);	// wait until the dialog window is open
   keys("cool.txt[Enter]"); 			// save as "cool.txt"
   while(!window("Editor")) wait(100);  // wait until dialog window closed
	wait(500);
   keys("[Alt-][F4]"); // exit Notepad (Alt-F4)
	printf("\nOk!");
}

