#include <stdio.h>
#include <string.h>

int main(){

    char name[25];

    printf("\n whats ur name?: \n\n");
    fgets(name, 25, stdin);
    name[strlen(name)-1]='\0';

    while(strlen(name)==0){
        printf("You didnt enter the name\n\n");
        printf("\n whats ur name?: \n\n");
        fgets(name, 25, stdin);
        name[strlen(name)-1]='\0';
    }

    printf("Hello %s", name);

    return 0;
}