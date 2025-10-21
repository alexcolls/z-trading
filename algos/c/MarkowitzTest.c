//////////////////////////////////////////////////////
// Markowitz algorithm test //////////////////////////
//////////////////////////////////////////////////////

function main()
{
	var Means[3] = { .062,.146,.128 };
	var Covariances[3][3] = {.0146,.0187,.0145,.0187,.0854,.0104,.0145,.0104,.0289 };
	var Weights[3];
	
	var BestVariance = markowitz(Covariances,Means,3,0);

	markowitzReturn(Weights,1);
	printf("\nMax: %.2f %.2f %.2f",Weights[0],Weights[1],Weights[2]);
	markowitzReturn(Weights,BestVariance);
	printf("\nBest:  %.2f %.2f %.2f",Weights[0],Weights[1],Weights[2]);
	markowitzReturn(Weights,0);
	printf("\nMin:  %.2f %.2f %.2f",Weights[0],Weights[1],Weights[2]);
}