#include <stdio.h>
#include <ctype.h>

void main(){

    char unit;
    float temp;
    
    printf("Enter the unit\n");
    scanf("%c",&unit);
    // unit = toupper(unit);

    switch (unit){
        case 'C' :
            printf("Enter the temp. in celcius \n");
            scanf("%f",&temp);
            temp=(temp * 9 / 5) + 32;
            printf("The new temp. is\t %.1f \n \t",temp);
            break;
        case 'F' :
            printf("Enter the temp. in Farhenheit \n");
            scanf("%f",&temp);
            temp=((temp -32) *5 )/9;
            printf("The new temp. is\t %.1f \n \t",temp);
            break;
        default:
            printf("Wrongchoice \t\t");
            

    }

}

