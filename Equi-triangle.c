#include <stdio.h>


int main(){
    // char c1;
    // printf("character: \n");
    // scanf("%c",&c1);
    int r;
    printf("How many rows?: \n");
    scanf("%d",&r);
    
    int n =2+(n-1)*r;
    for(int i =r;i>0;--i){
        for(int j =1;j<=i;j++){
            printf(" ");
        }
        for(int j=1;j<=(r-i)*2 + 1;j++){
            printf("%d",r-i+1);
        }
    printf("\n");
    }
}