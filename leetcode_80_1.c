#include<stdio.h>
int  sendback(int* a, int index, int n)
{
    int t;
    for(int i=index;i<n-1;i++)
    {
        t=*(a+i+1);
        *(a+i+1)=*(a+i);
        *(a+i)=t;
    }
    return 1;
}
int removeDuplicates(int* nums, int numsSize) 
{
    int *a=nums;
    int n=numsSize,i=0,c=0,k=0;
    while(i<n-1)
    {
        
        if( *(a+i)==*(a+i+1))
        {
            c++;
            if(c>1 && c<n-1)
            {
                k += sendback(a,i,n);
                continue;
            }
            
            
        }
        else c=0;
        i++;
    }
    return n-k;
}

void main()
{
    int a[3]={1,1,1};
    int k= removeDuplicates(a,3);
    printf("\n Your answer is %d",k);
}