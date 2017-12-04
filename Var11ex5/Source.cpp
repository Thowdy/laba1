#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Marsh
{
	char Start[64];
	char Finish[64];
	int Number;
};

const int N = 8;
Marsh M[N];

void Sort()
{
	for (int k = 0; k < N; k++)
	{
		int min = k;
		for (int i = k + 1; i < N; i++)
			if (M[i].Number < M[min].Number) min = i;
		Marsh Temp = M[k];
		M[k] = M[min];
		M[min] = Temp;
	}
}


void Input()
{
	char Buffer[64];
	for (int k = 0; k < N; k++)
	{
		printf("������ %d\n",k);
		printf("����� = "); gets_s(Buffer); M[k].Number = atoi(Buffer);
		printf("������ = "); gets_s(M[k].Start);
		printf("����� = "); gets_s(M[k].Finish);
	}
}

void Print(char * StartorFinish)
{
	int count = 0;
	for (int k = 0; k < N; k++)
		if (StartorFinish=="" || strcmp(StartorFinish,M[k].Start)==0 || strcmp(StartorFinish, M[k].Finish) == 0)
		{
			printf("������� ����� %d �� %s � %s\n",M[k].Number,M[k].Start,M[k].Finish);
			count++;
		}
	if (count == 0) printf("��� ����� ���������\n");
}

int main()
{
	system("chcp 1251>nul");
	Input();
	Sort();
	Print("");
	while (true)
	{
		printf("������� ����� �������� ");
		char Buffer[64];
		gets_s(Buffer);
		if (strlen(Buffer) == 0) break;
		Print(Buffer);
	}
}
