#include <stdio.h>

int maximam(int a, int b, int c){
    return (a>b)?((a>c)?a:c):((b>c)?b:c);
}

void main(){
    int a,b,c;
    printf("Enter 3 numbers\t\n");
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    printf("%d",maximam(a,b,c));
}