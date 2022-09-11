///////////////////////////////////
// Pi calculator
///////////////////////////////////

int main()
{
	printf("\n");
	long num=0;
	long a=10000, b=0, c=14000, d, e=0, f[16000], gg, n=0;
	for(; b<c; b++) f[b] = a/5; 
	for(; c>0; c-=14)
	{
		d = 0;
		gg = c*2;
		for(b=c; b>0; d*=b)
		{
			d += f[b]*a;
			gg--;
			f[b] = d%gg;
			d /= gg;
			gg--;
			b--;
			if (b == 0) break;
		}
		printf("%.4d",e+d/a);
		e = d%a;
		num+=4;
		if ((n++)%10 == 0) printf("\n");
	}
	printf("\n%d digits of pi calculated!",num);
}

 
