#include <stdio.h>

int left(int i);
int right(int i);
int parent(int i);
void heapify(int *arr,int i,int size);
void build_heap(int *arr,int size);
void sort(int *arr,int size);

int main(){
	int arr[]={8,15,4,2,3,10,1};
	int i;
	int size=sizeof(arr)/sizeof(arr[0]);
	sort(arr,size-1);
	for(i=0;i<size;i++)
		printf("%d ",arr[i]);
	return 0;
}

int left(int i){
	return 2*i;
}
int right(int i){
	return 2*i+1;
}
int parent(int i){
	return i/2;
}
void heapify(int *arr,int i,int size){
	int l=left(i+1)-1;
	int r=right(i+1)-1;
	int max=i;
	int temp;
	if(l<=size && *(arr+l)>*(arr+i))
		max=l;
		
	if(r<=size && *(arr+r)>*(arr+max))
		max=r;
	
	if(max!=i){
		temp=*(arr+i);
		*(arr+i)=*(arr+max);
		*(arr+max)=temp;
		heapify(arr,max,size);
	}
	
}
void build_heap(int *arr,int size){
	int i;
	for(i=(size+1)/2;i>=0;i--){
		heapify(arr,i,size);
	}
}
void sort(int *arr,int size){
	int i;
	int temp;
	build_heap(arr,size);
	for(i=size;i>0;i--){
		temp=*(arr+i);
		*(arr+i)=*arr;
		*arr=temp;
		size-=1;
		heapify(arr,0,size);
	}
}