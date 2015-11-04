#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
	int N,count=0,i=0,counter=0,j=0;
	scanf("%d",&N);
	char str[100][21],line[1000];
	double rel[100][100];
	for(i=0;i<100;i++)
		for(j=0;j<100;j++)
			rel[i][j]=0;
	while(N--)
	{
		int a,b,temp1=0,temp2=0,p=0,q=0,flag1=0,flag2=0,newflag=0;
		char word1[100][20],word2[100][20];
  		// Wrong input
	/*	scanf("%[^\n]", line);
		for(i=0;line[i];i++)
		{
			if(line[i]==' ')
			{
				a=atoi(line,line+i);
				break;
			}
		}
		for(;line[i];i++)
		{
			if(line[i]==' ')
			{
				strcpy(word1[counter],line+i);
				break;
			}
		}
		i+=2; //for '='
		for(;line[i];i++)
		{
			if(line[i]==' ')
			{
				b=atoi(line,line+i);
				break;
			}
		}
		for(;line[i];i++)
		{
			if(line[i]==' ')
			{
				strcpy(word2[counter],line+i);
				break;
			}
		}
		*/
		//Input after correction
		scanf("%d %s = %d %s",&a,word1[counter],&b,word2[counter]);
		for(i=0;i<=count;i++)
		{
			if(strcmp(word1[counter],str[i])==0)
			{
				temp1=i;
				flag1=1;
			}
			if(strcmp(word2[counter],str[i])==0)
			{
				flag2=1;
				temp2=i;
			}
		}
		if(flag1==0)
		{
			strcpy(str[count+1],word1[counter]);
			temp1=count+1;
			count++;
		}

		if(flag2==0)
		{
			strcpy(str[count+1],word2[counter]);
			temp2=count+1;
			count++;
		}
		if(flag1==0 || flag2==0)
		{
			rel[temp1][temp2]=(1.0*a)/(1.0*b);
			rel[temp2][temp1]=(1.0*b)/(1.0*a);
		}

		if(flag1==0 || flag2==0)
		{
			newflag=1;
			printf("True\n");
		}
		for(i=0;i<=count;i++)
		{
			if((rel[temp1][i]!=0 && rel[temp2][i]!=0) && ((1.0*a)/(1.0*b)!=rel[temp1][i]/rel[temp2][i]))
			{
				printf("False\n");
				newflag=2;
				break;
			}
		}
		
		if(newflag==0 && (rel[temp1][temp2]==(1.0*a)/(1.0*b) || rel[temp2][temp1]==(1.0*b)/(1.0*a) || rel[temp1][temp2]==0))
			printf("True\n");
		else if(newflag==0)
			printf("False\n");

		if(rel[temp1][temp2]==0 && rel[temp2][temp1]==0 && newflag!=2)
		{
			rel[temp1][temp2]=(1.0*a)/(1.0*b);
			rel[temp2][temp1]=(1.0*b)/(1.0*a);
		}
		counter++;
			
	}
}
