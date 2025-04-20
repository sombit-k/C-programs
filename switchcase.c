#include <stdio.h>
void main(){
    char grade;
    printf("Enter a character : \t");
    scanf("%c",&grade);
    switch(grade){
        case 'A':
            printf("Excellent");
            break;
        case 'B':
            printf("Good");
            break;
        case 'C':
            printf("Okay");
            break;
        case 'F':
            printf("Failure");
            break;
        default:
            printf("Enter valid Grade");
            break;
    }
}