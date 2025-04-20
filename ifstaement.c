#include <stdio.h>

void main(){
    int a;
    printf("enter a age\n\n");
    scanf("%d",&a);
    if(a>=18){
        printf("\n\nadult");
    }
    else if(a<18 ){
        printf("\n\nminor");
    }
    else {
        printf("u r unborn");
    }
}