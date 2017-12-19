#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h> 
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH_FIO 20
#define MAX_LENGTH_FILM 30
#define MAX_LENGTH_COUNTRY 10
#define MAX_LENGTH_FILMS 1000

int Num_films = 0;


typedef struct
{
	char Name[MAX_LENGTH_FIO];
	char Surname[MAX_LENGTH_FIO];
} Author;


typedef struct
{
	char Name[MAX_LENGTH_FILM];
	char Country[MAX_LENGTH_COUNTRY];
	Author Author;
	int Year = 0;
	int BoxOffice = 0;
	int Budget = 0;

} Film;

Film Films[MAX_LENGTH_FILMS];

FILE* f_Films = fopen("output.txt", "w");



void Choice()
{
	printf("��������� ��������: \n");
	printf(" 1-�������� ����� \n");
	printf(" 2-����� ������\n");
	printf(" 3-���������� �� �����\n");
	printf(" 4-���������� ���� ������\n");
	printf(" 5-���������\n");
	
}

int CheckNumber()
{
	int number = 0;
	do
	{
		int result = scanf_s("%d", &number);
		if (result == 0) {
			printf("�� ����� �� �����, ��� ������ �� �����, ����)");
			_getch();
			exit(1);
		}
		if (number < 1 || number > 5)
			printf("�������� �������\n");
	}
		while (number < 1 || number > 5);
		return number;
}
void addfilm()
{
	printf("������� �������� ������\n");
	getchar();
	gets_s(Films[Num_films].Name, MAX_LENGTH_FILM + 1);
	printf("������� ��� ���������\n");
	scanf("%s", Films[Num_films].Author.Name);
	printf("������� ������� ���������\n");
	scanf("%s", Films[Num_films].Author.Surname);
	printf("������� ���� �������� ������\n");
	scanf("%d", &Films[Num_films].Year);
	printf("������� ������ ������\n");
	scanf("%d" , &Films[Num_films].Budget);
	printf("������� �������� �����\n");
	scanf("%d", &Films[Num_films].BoxOffice);
	Num_films++;

}
void writefilm(int i)
{
	fprintf(f_Films, "%-30s|%-20s|%-20s|", Films[i].Name, Films[i].Author.Name, Films[i].Author.Surname);
	fprintf(f_Films, "%10d|%10d|%10d\n", Films[i].Year, Films[i].Budget, Films[i].BoxOffice);
}
void searchfilm()

{
	int x;
	char c[MAX_LENGTH_FILM];
	printf("�� ������ ���������� �� ������ ����� �����?\n");
	printf("1-���\n 2-�������\n 3-�������� ������\n 4-��� ��������\n");
	scanf("%d", &x);
	scanf("%s", c);
	for (int i = 0; i < Num_films; i++)
	{
		switch (x)
		{
		case 1:
		{
			if (!strcmp(Films[i].Author.Name, c))
			{
				writefilm(i);
			}
		} break;
		case 2:
		{
			if (!strcmp(Films[i].Author.Surname, c))
			{
				writefilm(i);
			}
		} break;
		case 3:
		{
			if (!strcmp(Films[i].Name, c))
			{
				writefilm(i);
			}
			break;
		}
		case 4: 
		{
			char str[12];
			sprintf(str, "%d", Films[i].Year);
			if (!strcmp(str, c))
			{
				writefilm(i);
			}
		}
		}

	}
}
void swap(Film *FilmA, Film *FilmB)
{
	Film TempFilm = *FilmA;
	*FilmA = *FilmB;
	*FilmB = TempFilm;
}
void sortfilm()
{
	for (int i = 1; i < Num_films; ++i)
	{
		for (int r = 0; r < Num_films - i; r++)
		{
			if (strcmp(Films[r].Name, Films[r + 1].Name) > 0)
			{
				swap(&Films[r], &Films[r + 1]);
			}
		}

	}

}


void writefilms()
{
	fprintf(f_Films, "%-30s|%-20s|%-20s|", "Film Name", "Author Name", "Author Suname");
	fprintf(f_Films, "%10s|%10s|%10s\n", "Year", "Budget", "Box Office");
	for (int i = 0; i < Num_films; i++)
	{
		writefilm(i);
	}
}
int main()
{
	int num;
	system("chcp 1251");
	system("cls");
	do
	{
		Choice();
		num = CheckNumber();
		switch (num)
		{
		case 1: {
			addfilm();
			printf("����� ��������\n\n");
		}
			break;
		case 2: {
			searchfilm();
			printf("����� ��������\n\n");
		}
			break;
		case 3: {
			sortfilm();
			printf("���������� ���������\n\n");
		}
			break;
		case 4: {
			writefilms();
			printf("������ ������� ������� � ����\n\n");
		}
			break;
		case 5: printf("�� �������");
			break;
		}
	}
	while (num != 5);
	_getch();
	return 0;


	
}