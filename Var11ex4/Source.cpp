#include <stdio.h>
#include <math.h>
//определить радиус и центр окружности, проходЯщей 
//по крайней мере через три различные точки заданного 
//множества точек на плоскости 
//и содержащей внутри наибольшее количество точек этого множества

const int N = 10; 
float x[N] = {0,0,  100,100,10,10, 50,50, 25, 10}; 
float y[N] = {0,100,100,  0,10,50, 50,10, 10, 25};

int main()
{
	/*
	for (int i = 0; i < N; i++)
	{
		printf("x[%d]=", i); scanf("%f", &x[i]);
		printf("y[%d]=", i); scanf("%f", &y[i]);
	}
	getchar();
	//*/

	int b1, b2, b3;
	int n = 0;

	for (int p1 = 0; p1 < N; p1++)
		for (int p2 = p1 + 1; p2 < N; p2++)
			for (int p3 = p2 + 1; p3 < N; p3++)
			{
				
				float x1 = x[p1];
				float x2 = x[p2];
				float x3 = x[p3];
				float y1 = y[p1];
				float y2 = y[p2];
				float y3 = y[p3];
				float d = x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2);
				if (d == 0) continue; 
				float d1 = x2*x2 + y2*y2 - x3*x3 - y3*y3;
				float d2 = x3*x3 + y3*y3 - x1*x1 - y1*y1;
				float d3 = x1*x1 + y1*y1 - x2*x2 - y2*y2;
				float xc = -0.5*(y1*d1 + y2*d2 + y3*d3) / d;
				float yc = 0.5*(x1*d1 + x2*d2 + x3*d3) / d;
				float r02 = (x1 - xc)*(x1 - xc) + (y1 - yc)*(y1 - yc);
				int counter = 0;
				for (int i = 0; i < N; i++)
				{
					float r2 = (x[i] - xc)*(x[i] - xc) + (y[i] - yc)*(y[i] - yc);
					
					if (r2 < r02) counter++;
				}

				if (counter > n)
				{
					b1 = p1; b2 = p2; b3 = p3; n = counter;

				}
			}

	printf("Best:\n%d(%.2f;%.2f)\n%d(%.2f;%.2f)\n%d(%.2f;%.2f)\n", b1,x[b1],y[b1],b2, x[b2], y[b2],b3, x[b3], y[b3]);


	float x1 = x[b1];
	float x2 = x[b2];
	float x3 = x[b3];
	float y1 = y[b1];
	float y2 = y[b2];
	float y3 = y[b3];
	float d = x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2);
	float d1 = x2*x2 + y2*y2 - x3*x3 - y3*y3;
	float d2 = x3*x3 + y3*y3 - x1*x1 - y1*y1;
	float d3 = x1*x1 + y1*y1 - x2*x2 - y2*y2;
	float xc = -0.5*(y1*d1 + y2*d2 + y3*d3) / d;
	float yc = 0.5*(x1*d1 + x2*d2 + x3*d3) / d;
	float r = sqrt((x1 - xc)*(x1 - xc) + (y1 - yc)*(y1 - yc));

	printf("R = %.2f\nx=%.2f\ny=%.2f\nN=%d\n",r,xc,yc,n);

	getchar();

}