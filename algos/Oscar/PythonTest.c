
function main()
{
	if(!pyStart("",1)) {
		printf("Error - Python won't start!");
		return;
	}
	
	var Vec[5] = { 0,1,2,3,4 };
	pySet("PyVec",Vec,5);
	pyX("for i in range(5): PyVec[i] *= 10\n");
	pyVec("PyVec",Vec,5);
	
	int i;
	printf("\nReturned: ");
	for(i=0; i<5; i++) printf("%.0f ",Vec[i]);

// test a function
	pyX("def PySum(V):\n Sum = 0\n for X in V: Sum += X\n return Sum\n\n");
	pyX("Result = PySum(PyVec)");
	pyX("print(PyVec)");
	printf("\nSum: %.0f",pyVar("Result"));
}
