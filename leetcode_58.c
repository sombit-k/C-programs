#include<stdio.h>
#include<string.h>
// int lengthOfLastWord(char* s) {
//     int n,c=0;
//     for( n = 0;*(s+n)!=0;n++);
//     printf("\nSize of the sentence is : %d ",n);
//     for(int i = n-1;i!=0;i++)
//     {
        
//         if(c && (*(s+i)==' '|| i==0))
//         return c;
//         else if(*(s+i)!=' ' || *(s+i)!= '\0')
//         c++;
//         if(c)
//         c++;
//     }
// }
int lengthOfLastWord(char* s);
void main()
{
    char* s;
    printf("Enter a string: ");
    gets(s);
    int n = lengthOfLastWord(s);
    printf("\nLenght of last word is: %d",n);
}



// int lengthOfLastWord(char* s) {
//     int n,c=0,flag=0;
//     for( n = 0;*(s+n)!=0;n++);
//     printf("\nSize of the sentence is : %d",n);
//     for(int i = n-1;i!=0;i--)
//     {
//         printf("\nc is: %d",c);
//         printf("\nchecking the letter-------------------->%c,------index is :%d ",*(s+i),i);
//         if(c)
//         c++;
//         else if((*(s+i)==' ' || *(s+i)=='\0')&& (*(s+i-1)!=' '))
//         c++;
//         else 
//         return c;
//     }
// }
int li(char* s, int n)
{
    if (*(s+n)!=' ')
    return n;
    else{
        while(n>0)
        {
            if((*(s+n)==' ')&& (*(s+n-1)!=' '))
            // if((*(s+n-1)!=' '))
            return n-1;
            n--;
        }
    }
}

int fi(char* s,int n)
{
    while(1)
    {
        if(n==0)
        return 0;
        else if((*(s+n)!=' ')&& (*(s+n-1)==' '))
        return n;
        else n--;
    }
}
int lengthOfLastWord(char* s) {
    int n;
    for( n = 0;*(s+n)!=0;n++);
    printf("\nSize of the sentence is : %d",n);   
    int lastindex=li(s,n-1);
    printf("\nThe last idnex is: %d",lastindex);
    int firstindex=fi(s,lastindex);
    printf("\nThe first idnex is: %d",firstindex);
    return lastindex-firstindex+1;
}