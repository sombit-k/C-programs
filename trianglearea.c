#include<stdio.h>
#include<math.h>
void main()
{
    float a,p,s1,s2,s3,s;
    
    printf("3 sides");
    scanf("%f%f%f",&s1,&s2,&s3);
    p=s1+s2+s3;
    s=p/2.0;
    a=pow((s*(s-s1)*(s-s2)*(s-s3)),0.5);
    printf("%f %f",p,a);
}