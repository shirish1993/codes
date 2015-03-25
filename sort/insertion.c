#include <stdio.h>

void insertion_sort(int *arr,int length);
void display(int *arr,int length);

int main(){
	int arr[]={3,7,4,9,5,2,6,1};
	int length=sizeof(arr)/sizeof(arr[0]);
	
	insertion_sort(arr,length);
	display(arr,length);
	
	return 0;
}

void display(int *arr,int length){
	int i;
	printf("\narray is: ");
	for(i=0;i<length;i++)
		printf("%d ",*(arr+i));
	printf("\n");
}

void insertion_sort(int *arr,int length){
	int i,j,pos,temp;
	
	for(i=1;i<length;i++){
		for(j=0;j<i;j++){
			if(*(arr+j)>*(arr+i)){
				temp=*(arr+i);
				*(arr+i)=*(arr+j);
				*(arr+j)=temp;
			}
		}
		display(arr,length);
	}
}