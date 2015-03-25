#include <stdio.h>

void merge(int *arr,int l,int h);
void merge_sort(int *arr,int l,int h);

int main(){
	int arr[]={9,1,15,12,14,6,18,17,19};
	int i;
	merge_sort(arr,0,8);
	printf("\n");
	for(i=0;i<9;i++)
		printf("%d ",arr[i]);
	return 0;
}

void merge_sort(int *arr,int l,int h){
	int mid=(h+l)/2;
	if(h==l)
		return;
	else{
		merge_sort(arr,l,mid);
		merge_sort(arr,mid+1,h);
		merge(arr,l,h);
	}
}

void merge(int *arr,int l,int h){
	int l1=l;
	int size=h-l+1;
	int temp[size];
	int mid=(h+l)/2;
	int j=mid+1;
	int i=0;
	while(l<=mid && j<=h){
		if(*(arr+l)<*(arr+j)){
			temp[i++]=*(arr+l++);
		}
		else{
			temp[i++]=*(arr+j++);
		}
	}
	
	while(l<=mid){
		
		temp[i++]=*(arr+l++);
	}
	while(j<=h){
		temp[i++]=*(arr+j++);
	}
	for(i=0;i<size;i++){
		*(arr+l1+i)=temp[i];
	}

}