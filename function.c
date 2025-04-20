#include<stdio.h>

void main() {
    int i,j,k,n;
    printf("Enter n = ");
    scanf("%d",&n);
    for (i = 1;i<=n;++i){
        for (j = n-1 ;j>=i;--j){
            printf(" ");
        }
        for (k = 0; k<i ; ++k){
            printf("* ");
        }
        printf("\n");
        }
}