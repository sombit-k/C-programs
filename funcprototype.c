#include <stdio.h>

void hi(char[],int);

void main(){
    int age = 18;
    char name[]="sombit";
    hi(name, age);

}

void hi(char name[],int age){
    printf("Hello\t%s\t you are %d years old",name,age);
}