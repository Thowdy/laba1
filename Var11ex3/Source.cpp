//Коэффициенты системы линейных уравнений заданы в виде прямоугольной матрицы 
//С помощью допустимых преобразований привести систему к треугольному виду

#include <stdio.h>

const int N = 3; 
float A[N][N + 1] 
=
{
	1,  1,  1, 3,
	2,  3,  4, 9,
	4, -1, -1, 2
};

int main()
{
	printf("Var 11 ex 3\n");

	//*
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N + 1; j++)
		{
			printf("A[%d][%d]=", i, j); scanf("%f", &A[i][j]);
		}
		getchar();
	//*/
	printf("Before\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N + 1; j++)	printf("%6.1f", A[i][j]); 
		printf("\n");
	}

	for (int k = 0; k < N; k++)
	{
		for (int row = k + 1; row < N; row++)
		{
			if (A[k, k] == 0)
			{
				printf("Can't do\n");
				getchar();
				return 1;
			}
			float D = A[row][k] / A[k][k];
			for (int col = 0; col < N + 1; col++)
				A[row][col] = A[row][col] - A[k][col] * D;
		}
	}

	printf("After\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N + 1; j++)	printf("%6.1f", A[i][j]);
		printf("\n");
	}

	getchar();
}