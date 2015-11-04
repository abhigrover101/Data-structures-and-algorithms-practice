#include<stdio.h>
#include<string.h>

int palindrome(char str[1010],int i,int j)
{
	if(i>=j && str[i]==str[j])
		return 1;
	if(str[i]==str[j])
		return palindrome(str,i+1,j-1);
	return 0;
}

int main()
{
	char str[1010];
	int c=0,i,j;
	scanf("%s",str);
	j=strlen(str)-1;
	for(;j>=0;j--)
		for(i=0;i<=j;i++)
			c=c+palindrome(str,i,j);
	printf("%d\n",c);
	return 0;
}
