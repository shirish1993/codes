#include <stdio.h>

int partition(int *arr,int l,int h);
void sort(int *arr,int l,int h);

int main(){
	int arr[]={14,4,3,2,8,10,12};
	int size=sizeof(arr)/sizeof(arr[0]);
	int i;
	sort(arr,0,size-1);
	printf("\n");
	for(i=0;i<size;i++)
		printf("%d \n",arr[i]);
}

void sort(int *arr,int l,int h){
	int j;
	if(h<l)
		return;
	j=partition(arr,l,h);
	sort(arr,l,j-1);
	sort(arr,j+1,h);
}

int partition(int *arr,int l,int h){
	int i=l;
	int j=h+1;
	int temp;
	
	while(1){
		while(*(arr+ ++i)<*(arr+ l)){
			if(i>=h)
				break;
		}
		
		while(*(arr+ --j)>*(arr+ l)){
			if(j<=l)
				break;
		}		
		if(i>=j)
			break;
		temp=*(arr+i);
		*(arr+i)=*(arr+j);
		*(arr+j)=temp;
	}
	temp=*(arr+l);
	*(arr+l)=*(arr+ j);
	*(arr+j)=temp;
	
		
	return j;
	
}