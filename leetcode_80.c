#include<stdio.h>
int  sendback(int* a, int index, int n)
{
    int t;
    for(int i=index;i<n-1;i++)
    {
        t=*(a+i+1);
        *(a+i+1)=*(a+i);
        *(a+i)=t;
        printf("%d %d\n",*(a+i),i);
    }
    printf("\n\n");
    return 1;
}


int removeDuplicates(int* nums, int numsSize) 
{
    int *a=nums;
    int n=numsSize,i,c,k=0;
    c=0;
    for(i=0;i<n-1;i++)
    {
        if(*(a+i)==*(a+i+1))
        {
            if(c>=1 && c<n)
            {
            i--;
            k += sendback(a,i,n);
            c++;
            }
            else
            {
            c++;
            }
        }
        else c=0;
        
    }
        for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return n-k;
}

void main()
{
    int a[3]={1,1,1};
    int k= removeDuplicates(a,3);
    printf("\n Your answer is %d",k);
}