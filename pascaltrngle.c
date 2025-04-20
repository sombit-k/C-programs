#include <stdio.h>

int main()
{
    int n;
    printf("Number of Rows for Pascals Triangle : \t");
    scanf("%d",&n);
    printf("\n");
    //form the array first.
    int row=n;
    int L[1]={1};
    int column = 2*n + 2*(n-1);
    int M[row][column];
    M[0][0]=1;
    M[1][0]=1;
    M[1][1]=1;
    int N[column];
    // int column = 2*n + 2*(n-1);
    // int N[row][column];
    // printf("%d\n",M[0][0]);
    if(row>2){
    for (int i=2;i<row;i++){// master loop, moves through rows. 
        M[i][0]=1;
        // printf("%d",M[i][0]);
        for(int j=1;j<i;j++){ // forming an temporary array
            M[i][j]=M[i-1][j-1]+M[i-1][j];
            // printf("%d",M[i][j]);
        }
        M[i][i]=1;
        // printf("%d\n",M[i][i]);
        // printf("\n");
    // N contians an array here
    // for(int x=0;x<=sizeof(N)/N[0];x++){
    //     M[i][x]=N[x];
    // }
}
    
        
        for (int i=0;i<row;i++){
            for(int j=column-i;j>=i;j--){
            printf(" ");
        }
        if(i==0){
            printf("  1\n");
            continue;
        }
        else if(i==1){
            printf("1\t    1\n");
            continue;
        }
            for(int j=0;j<=i;j++){ 
            printf("%d       ",M[i][j]);
        }
        printf("\n");
        
    printf("\n");
    }
}
    
    // for (int i =0;i<=row;i++){
    //     for(int j=1;j<=(i*2)+1;j++){
    //         printf("%d\t",M[i][j]);
    //     }
    // printf("\n");
    // }
    return 0;
}
