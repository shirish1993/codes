#include <stdio.h>

struct node{
	int val;
	struct node* next;
};

struct node* root=NULL;
struct node **arr;

void radix(int *arr1,int size,int m,int n);
void insert_no(int arr1,int index);
void form_arr(int *arr);
void refresh();

int main(){
	int i=0;
	int arr1[]={9,8,4,1,5,2,10};
	int size=sizeof(arr1)/sizeof(arr1[0]);
	printf("\nUnsorted array:");
	for(i=0;i<size;i++){
		printf("%d ",*(arr1+i));
	}
	arr=malloc(sizeof(struct node*)*10);
	for(i=0;i<10;i++){
		arr[i]=malloc(sizeof(struct node*));
		arr[i]->val=i;
		arr[i]->next=NULL;
	}
	radix(arr1,size,10,1);
	printf("\nSorted array:");
	for(i=0;i<size;i++){
		printf("%d ",*(arr1+i));
	}
	
	return 0;
}

void refresh(){
	int i;
	for(i=0;i<10;i++){
		arr[i]->next=NULL;
	}
}

void insert_no(int arr1,int index){
	struct node *temp=arr[index];
	struct node *temp1=malloc(sizeof(struct node));
	
	while(temp->next!=NULL){
		temp=temp->next;
		//printf("%d ",temp->val);
	}
	
	temp->next=temp1;
	temp1->val=arr1;
	temp1->next=NULL;
	return;
	
}

void form_arr(int *arr1){
	int i=0;
	int count=0;
	struct node* temp;
	for(i=0;i<10;i++){
		temp=arr[i]->next;
		while(temp!=NULL){
			*(arr1+ count++)=temp->val;
			temp=temp->next;
		}
	}
	//printf("\nno elem %d\n",count);
}

void radix(int *arr1,int size,int m,int n){
	int i=0;
	int temp;
	int flag=0;
	refresh();
	for(i=0;i<size;i++){
		temp=*(arr1+i)%m;
		temp/=n;
		if(temp!=0)
			flag=1;
		//printf("%d %d \n",*(arr1+i),temp);
		insert_no(*(arr1+i),temp);
	}
	form_arr(arr1);
	if(flag==1)
		radix(arr1,size,m*10,n*10);
	else
		return;
}