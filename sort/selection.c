#include <stdio.h>

void selection_sort(int *arr,int length);
void display(int *arr,int length);

int main(){
	int arr[]={10,9,8,7,6,5,4,3,2,1};
	int length=sizeof(arr)/sizeof(arr[0]);
	
	selection_sort(arr,length);
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

void selection_sort(int *arr,int length){
	int i,j,pos,temp;
	
	for(i=0;i<length-1;i++){
		pos=i;
		for(j=i+1;j<length;j++){
			if(*(arr+j)<*(arr+pos)){
				pos=j;
			}
		}
		temp=*(arr+pos);
		*(arr+pos)=*(arr+i);
		*(arr+i)=temp;
		display(arr,length);
	}
}