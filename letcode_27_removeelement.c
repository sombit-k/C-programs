// #include<stdio.h>
// int removeElement(int* nums, int numsSize, int val) {
//     int i,j,t,temp;
//     t=numsSize-1;
//     printf("%d",numsSize);
//     for(i=0;i!=t || i <numsSize ;i++)
//     {
//         if(*(nums + i)==val)
//         {
//             for(j=t;j>=i;j--)
//             {
//                 if(*(nums + j)!=val)
//                 {
//                     temp=*(nums + i);
//                     *(nums + i)= *(nums + j);
//                     *(nums + j)= temp;
//                     t=j;
//                     break;
//                 }
//             }
//         }
//     }
//     return *nums;
// }


int removeElement(int* nums, int numsSize, int val) {
    int i,j,t,temp,c=1;
    int k[0]={};
    if(numsSize == 0)
    {
        return numsSize;
    }
    else if(numsSize==1 && *nums!=val)
    {
        return numsSize;
    }
    else if(numsSize==1 && *nums==val)
    {
        return numsSize;
    }
    t=numsSize-1;
    for(i=0;i!=t ;i++)
    {
        if(*(nums + i)==val)
        {
            for(j=t;j>=i;j--)
            {
                if(i==j && *(nums + i)== *(nums + j))
                {
                    return numsSize--;
                }
                if(*(nums + j)!=val)
                {
                    temp=*(nums + i);
                    *(nums + i)= *(nums + j);
                    *(nums + j)= temp;
                    t=j;
                    c++;
                    break;
                }
            }
        }
    }
    
    return (numsSize-c);
}

