#include <stdio.h>
#include<string.h>
#include <fstream>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include "generation.cpp"
int main(int argc, char ** argv)
{
	int jieguo;
	jieguo = checkargvs(argv[1], argv[2]);
	if(jieguo==0);
	if(jieguo==1)//�������� 
	{
		int n;
		n=atoi(argv[2]);
		while(n--)
		{
    		init();
    		
    		generator();
			for(int i = 0; i < 9; i ++)
    		{
        		for(int j = 0; j < 9; j ++)
        		{
        			if(j==0)
        			out<<a[i][j];
        			else
        	    	out<<' '<<a[i][j];//��ÿ��Ԫ��д���ļ����Զ��ŷָ���
        		}
        		out << endl;//ÿ�������������ӻ��С�
    		}
    		out << endl;
		}
	out.close();
	}
	else//���� 
	{
		int a1[9][9]={0};
		FILE * pFile;
		int mm;
		pFile = fopen (argv[2] , "r");
		char s[20];
		while(1)
		{
			if(feof(pFile))   
					break;
			mm=10;
			while(mm--)
			{
				if(fgets (s , 20 , pFile))
				{
					for(int j1=0;j1<9;j1++)
						a1[9-mm][j1]=s[2*j1]-'0';
			
				}	
			}
			jiejue(a1);
			for(int i = 0; i < 9; i ++)
    		{
        		for(int j = 0; j < 9; j ++)
        		{
        			if(j==0)
        			out<<a1[i][j];
        			else
        	    	out<<' '<<a1[i][j];
        		}
        		out << endl;
    		}
    		out << endl;	
		}
	}
	
}
