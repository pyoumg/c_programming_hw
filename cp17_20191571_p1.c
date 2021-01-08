#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __Complex{

	int r;
	int i;


}Complex;

Complex Add(Complex a,Complex b);
Complex Sub(Complex a,Complex b);
Complex Mul(Complex a,Complex b);

int main()
{
	Complex a,b,Add1,Sub1,Mul1;
	scanf("%d %d %d %d",&a.r,&a.i,&b.r,&b.i);
	Add1=Add(a,b);
	Sub1=Sub(a,b);
	Mul1=Mul(a,b);
	
	printf("%d %d\n",Add1.r,Add1.i);
	printf("%d %d\n",Sub1.r,Sub1.i);
	printf("%d %d\n",Mul1.r,Mul1.i);


	return 0;
}

Complex Add(Complex a, Complex b)
{
	Complex c;
	c.r=a.r+b.r;
	c.i=a.i+b.i;

	return c;


}

Complex Sub(Complex a,Complex b)
{
	Complex c;
	c.r=a.r-b.r;
	c.i=a.i-b.i;



	return c;
}

Complex Mul(Complex a,Complex b)
{
	Complex c;
	c.r=a.r*b.r-a.i*b.i;
	c.i=a.r*b.i+a.i*b.r;

	return c;
}
