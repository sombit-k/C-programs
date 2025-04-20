#include<stdio.h>
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    printf(sizeof(*triangle)/sizeof(triangle));
    return sizeof(**triangle)/sizeof(*triangle);
}

void main()
{
    int t[3][3]={{1},{1,2},{1,2,3}};
    
    printf("%d",** ( t ));
}