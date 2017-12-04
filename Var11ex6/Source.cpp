#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NOTEBOOK {
	char model[21]; 
	struct size {	
		float x;
		float y;
		float z;
	} size;
	float w;
	int price; 
} NOTEBOOK;

NOTEBOOK NB[100];
int N = 0;

float Extract(char * Buffer, int Start, int Len)
{
	char buffer[10];
	memcpy(buffer, &Buffer[Start-1], Len);
	buffer[Len] = 0;
	return atof(buffer);
}

void ReadFromText()
{
	FILE * F = fopen("note.txt", "r");
	char Buffer[255];
	while (true)
	{
		fgets(Buffer, 255, F);
		if (feof(F)) break;
		float hdd = Extract(Buffer, 72, 5);
		if (hdd >= 1) continue; 
		memcpy(NB[N].model, Buffer, 20);
		NB[N].size.x = Extract(Buffer,30,4);
		NB[N].size.y = Extract(Buffer,35,4);
		NB[N].size.z = Extract(Buffer,40,4);
		NB[N].w = Extract(Buffer,26,3);
		NB[N].price = (int)Extract(Buffer,21,4);
		N++;
	}
	fclose(F);
}

void Append(NOTEBOOK notebook, char * FileName)

{

	FILE * F = fopen(FileName, "rb+");
	short size = 0;
	if (!F) 
	{
		F = fopen(FileName, "wb");
		fwrite(&size, sizeof(size), 1, F);
		fclose(F);
		F = fopen(FileName, "rb+");
	}
	
	fread(&size, sizeof(size), 1, F); 
	size++;
	fseek(F, 0, SEEK_SET);
	fwrite(&size, sizeof(size), 1, F);

	
	fseek(F, 0, SEEK_END); 
	fwrite(&notebook, sizeof(notebook), 1, F);
	fclose(F);
}

void Sort()
	{
		for (int k = 0; k < N; k++)
		{
			int min = k;
			for (int i = k + 1; i < N; i++)
				if (strcmp(NB[i].model,NB[min].model)<0) min = i;
			NOTEBOOK Temp = NB[k];
			NB[k] = NB[min];
			NB[min] = Temp;
		}
	}

int main()
{
	ReadFromText();
	Sort();
	for (int n = 0; n < N; n++)	Append(NB[n],"Result.dat");
}