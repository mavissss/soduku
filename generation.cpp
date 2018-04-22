#include <stdio.h>
#include<string.h>
#include <fstream>
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int tmp[9],a[9][9];
char model[9][9] = 
{
{ 'i','g','h','c','a','b','f','d','e' },
{ 'c','a','b','f','d','e','i','g','h' },
{ 'f','d','e','i','g','h','c','a','b' },
{ 'g','h','i','a','b','c','d','e','f' },
{ 'a','b','c','d','e','f','g','h','i' },
{ 'd','e','f','g','h','i','a','b','c' },
{ 'h','i','g','b','c','a','e','f','d' },
{ 'b','c','a','e','f','d','h','i','g' },
{ 'e','f','d','h','i','g','b','c','a' }
}; 
ofstream out("soduku.txt"); 
int Find(int a1[9][9], int sttro, int *row, int *col)
{
	int i, j;

	for (i = sttro; i < 9; i++) 
		for (j = 0; j < 9; j++) 
			if (a1[i][j] == 0) 
			{
				*row = i;
				*col = j;
				return 1;
			}
	return 0;
}

void print(int a3[9][9])
{
	int i, j;

	for (i = 0; i < 9; i++) 
	{
		for (j = 0; j < 9; j++) 
		{
			if(j==0)
			printf("%d", a3[i][j]);
			else
			printf(" %d", a3[i][j]);
			if (j == 8) 
				printf("\n");
		}
	}
}

int yunsuan(int a2[9][9], int row, int col)
{
	int i, j, n;
	int xiayilie, xiayihang;
	n = 0;
	while(1) 
	{
		next_num:
			++n;
		if (n >= 10) break;
		for (j = 0; j < 9; j++) 
			if (a2[row][j] == n) 
				goto next_num;
		for (i = 0; i < 9; i++) 
			if (a2[i][col] == n) 
				goto next_num;
		int x = (row / 3) * 3;
		int y = (col / 3) * 3;
		for (i = x; i < x + 3; i++) 
			for (j = y; j < y + 3; j++)	
				if (a2[i][j] == n) 
					goto next_num;
		a2[row][col] = n;
		if (!Find(a2, row, &xiayilie, &xiayihang)) 
			return 1;
		if (!yunsuan(a2, xiayilie, xiayihang)) 
		{
			a2[row][col] = 0;
			continue;
		} 
		else	
			return 1;
	}
	return 0;
}

void jiejue(int a2[9][9])
{
	int row, col;

	Find(a2, 0, &row, &col);
	yunsuan(a2, row, col);
}

void generate1to9() 
{
	for (int k = 0; k < 9; k++) 
    	tmp[k] = 0;
	for (int i = 0; i<9; i++) 
	{
    	tmp[i] = 1 + rand() % 9;               
    		for (int j = 0; j<i; j++)                
        		if (tmp[i] == tmp[j]) 
				{ 
					i--; 
					break; 
				}  
	}
}

void init()
{
	generate1to9();
	for (int i = 0; i<9; i++) 
    	if (tmp[i] == 9) 
		{
        	tmp[i] = tmp[8];
        	tmp[8] = 9;
    	}
}
void generator()
{
	for (int i = 0; i<9; i++)
    	for (int j = 0; j<9; j++)
    	{
       		if (model[i][j] == 'a') 
			   a[i][j] = tmp[0];
        	else if (model[i][j] == 'b') 
				a[i][j] = tmp[1];
        	else if (model[i][j] == 'c') 
				a[i][j] = tmp[2];
        	else if (model[i][j] == 'd') 
				a[i][j] = tmp[3];
        	else if (model[i][j] == 'e') 
				a[i][j] = tmp[4];
        	else if (model[i][j] == 'f') 
				a[i][j] = tmp[5];
        	else if (model[i][j] == 'g') 
				a[i][j] = tmp[6];
        	else if (model[i][j] == 'h') 
				a[i][j] = tmp[7];
        	else if (model[i][j] == 'i') 
				a[i][j] = tmp[8];
	
    	}
}
int checkargvs(char *a1, char *a2)
{
	if (a1 == NULL || a2 == NULL)
	{
		printf("not enouth argvs\n");
		return 0;
	}
	if (!strcmp(a1, "-c"))
	{
		if (strlen(a2) > 7)
		{
			printf("too large!\n");
			return 0;
		}
		for (int i = 0; i < strlen(a2); i++)
		{
			if (a2[i] >= '0'&&a2[i] <= '9')
				continue;
			printf("illegal!\n");
			return 0;
		}
		if (atoi(a2) > 1000000)
		{
			printf("too large!\n");
			return 0;
		}
		return 1;
	}
	else if (!strcmp(a1, "-s"))
	{
		char path[100] = { 0 };
		FILE *ques = fopen(a2, "r+");
		if (ques == NULL)
		{
			printf("wrong.\n");
			return 0;
		}
		fclose(ques);
		return 2;
	}
	else
		return 0;
} 
