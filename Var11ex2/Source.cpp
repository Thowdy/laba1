#include <stdio.h>
#include <math.h>
//� ������� ��������� �� N ������������ ���������,
//����� ����� ������������ �� ������ ��������
//����� ������� ���������, ������������� ����� ������� �������������� ��������
//����� ������, ������ �� ���� ��� ��������, �������� ������� ��������� � ��������� [a,b]
//�������������� � ����� ������� �������� ��������� ������

const int N = 10;
float A[N] = { 5, 7, 3.14, -5, -7, -3.13, 10,20,30,-40 };

int main()
{
	printf("Var 11 ex 2\n");

	
	for (int i = 0; i < N; i++)
	{
		printf("A[%d]="); scanf("%f", &A[i]);
	};
	
	for (int i = 0; i < N; i++)
		printf("%5.2f ", A[i]);
	printf("\n");

	
	int min = 0;
	for (int i = 1; i < N; i++)
		if (fabs(A[i]) < fabs(A[min])) min = i;
	printf("min index = %d\n");


	min = N;
	for (int i = N - 1; i >= 0; i--)
		if (A[i] < 0) min = i;
	float sum = 0;
	for (int i = min + 1; i < N; i++)
		sum += fabs(A[i]);
	if (min == N) printf("no negative\n"); else printf("sum = %5.2f\n",sum);

	
	float a, b;
	printf("a="); scanf("%f", &a);
	printf("b="); scanf("%f", &b);

	int k = 0;
	for (int i = 0; i < N; i++)
		if (A[i]<a || A[i]>b) A[k++] = A[i];
	for (int i = k; i < N; i++) A[i] = 0;

	printf("Pack\n");
	for (int i = 1; i < N; i++)
		printf("%5.2f ", A[i]);
	printf("\n");

	getchar();
	getchar();
}