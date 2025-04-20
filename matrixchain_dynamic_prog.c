#include<stdio.h>
void optParan(int i, int j, int k[100][100]) {
    if (i == j) {
        printf("M%d", i + 1);
        return;
    }
    printf("(");
    optParan(i, k[i][j] - 1, k);
    optParan(k[i][j], j, k);
    printf(")");
}

void main()
{
    int a[100][2],t,min,n,i,j,l,d[100], c[100][100],k[100][100],ki;
    printf("Enter the number of matrices: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the dimensions of Matrix %d\n",(i+1));
        printf("Row & Column ");
        scanf("%d %d",&a[i][0],&a[i][1]);
        // printf("Column: ");
        //         scanf("%d",&a[i][1]);
        d[i]=a[i][1];
    }
    d[-1]=a[0][0];
    for(l=0;l<n-1;l++)
    {	i=0;
        for(j=l+1;j<n;j++)
        {			
            min=10000;
            for(ki=i;ki<j;ki++)
            {	
                
                t=(c[i][ki]+c[ki+1][j]+d[i-1]*d[ki]*d[j]);
                if(min>t)
                {
                    c[i][j]=t;
                    k[i][j]=ki+1;	
                }
            }
        i++;
        }
    }
    printf("The table of minimum matrix multiplication is: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }

    printf("Optimal Parenthesis Arrangement: ");
    optParan(0, n - 1, k); // Call the recursive function
    printf("\n");
}

