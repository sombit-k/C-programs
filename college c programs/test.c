#include <stdio.h>
#include <limits.h>

void merge(int *A,int p,int q,int r){
	int n1,n2,i,j,k,L[100],R[100];
	n1 = q - p + 1;
	n2 = r - q;
	for (i = 0 ; i < n1 ; ++i){
		L[i] = A[p+i];
	}
	for (j = 0 ; j < n2 ; ++j){
		R[j] = A[q + 1 + j];
	}
	L[n1] = R[n2] = INT_MAX;
	i = j = 0;
	for(k = p ; k <= r ; ++k){
		if (L[i] <= R[j]){
			A[k] = L[i];
			i++;
		}
		else{
			A[k] = R[j];
			j++;
		}
	}
}

void mergeSort(int *A,int p ,int r){
	int q ;	
	if (p<r){
		q = (p+r)/2;
		mergeSort(A,p,q);
		mergeSort(A,q+1,r);
		merge(A,p,q,r);	
	}
}

void arrayPrinter(int *A,int n){
	int i ;
	for(i = 0 ; i<n ; ++i){
		printf("%d ",A[i]);
	}
	printf("\n");
}
void main(){
	int A[100],size,i,j;
	printf("Enter size : ");
	scanf("%d",&size);
	for(i = 0 ; i < size ; ++i){
		printf("Enter :");
		scanf("%d",&A[i]);
	}
	arrayPrinter(A,size);
	mergeSort(A,0,size-1);
	arrayPrinter(A,size);
}

