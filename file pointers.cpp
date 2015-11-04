#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main()
{
    char line[100];
    cout << "Enter Address\n";
    char path[100];
    scanf("%[^\n]",path);
    //printf("%s\n",path);
    FILE *fp=fopen(path,"r");
    while(fscanf(fp,"%[^\n]",line)!=EOF)
    {
        printf("%s\n",line);
    }
    return 0;
}
