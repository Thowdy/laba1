#include <stdio.h>
//Вывести на экран в виде таблицы значения функции F
int main()
{
	float a, b, c, x0, xk, dx;
	printf("Var 11 ex 1\n");
	printf("a="); scanf("%f", &a);
	printf("b="); scanf("%f", &b);
	printf("c="); scanf("%f", &c);
	printf("x0="); scanf("%f", &x0);
	printf("xk="); scanf("%f", &xk);
	printf("dx="); scanf("%f", &dx);

	printf("------------------\n");
	printf("|   x   |    y   |\n");
	printf("|-------|--------|\n");
	for (float x = x0; x <= xk; x += dx)
	{
		
		float f;
		if (x < 1 && c != 0) f = a*x*x + b / c; else
			if (x > 15 && c == 0) f = (x - a) / x; else
				f = x*x / c / c;
		
		if (((int)a & (int)b) ^ (int)c == 0) f = (int)f;
		printf("|%6.2f | %7.2f|\n",x,f);
	}
	printf("------------------\n");
	getchar();
	getchar();
}