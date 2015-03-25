#include <stdio.h>

void bubble_sort(int *arr,int length);
void display(int *arr,int length);

int main(){
	int arr[]={10,9,8,7,6,5,4,3,2,1};
	int length=sizeof(arr)/sizeof(arr[0]);
	
	bubble_sort(arr,length);
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

void bubble_sort(int *arr,int length){
	int i,j;
	for(i=0;i<length-1;i++){
		for(j=0;j<length-i-1;j++){
			if(*(arr+j)>*(arr+j+1)){
				
				int temp=*(arr+j);
				printf("hello");
				*(arr+j)=*(arr+j+1);
				*(arr+j+1)=temp;
			}
		}
		display(arr,length);
	}
}