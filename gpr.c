#include<stdio.h>
#include<string.h>
void main()
{
    char fn[10],mn[10],ln[10],n[40];
    int i,j,k;
    printf("Enter first,middle,last name");
    gets(fn);
    gets(mn);
    gets(ln);
    for(i=0;fn[i]!='\0';i++)
    {
        n[i]=fn[i];
    }
    n[i]=" ";
    for(j=0;mn[j]!='\0';j++)
    {
        n[i+j+1]=mn[j];
    }
    n[i+j+1]=" ";
    for(k=0;ln[k]!='\0';k++)
    {
        n[i+j+k+1]=ln[k];
    }
    n[i+j+k+1]=" ";
}