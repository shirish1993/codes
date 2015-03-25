#include <stdio.h>

struct list{
	int val;
	struct list* next;
	struct list* left;
	struct list* right;
};

struct list* root_list=NULL;
struct list* pos1=NULL;
struct list* pos2=NULL;

void display_list(struct list* temp);
void populate_list(struct list* temp,int val1);
int find_min(struct list* temp,int min);
void remove_min(struct list* temp,int min);
void huffman(struct list* temp);
void display_tree(struct list* temp,int arr[],int top);

int main(){
	int min1;
	int arr[10];
	populate_list(root_list,5);
	populate_list(root_list,2);
	populate_list(root_list,2);
	populate_list(root_list,1);
	populate_list(root_list,1);
	printf("\nList is:\n");
	
	display_list(root_list);
	/*min1=find_min(root_list->next,root_list->val);
	min1=find_min(root_list->next,root_list->val);
	min1=find_min(root_list->next,root_list->val);
	printf("\nList is:\n");
	display_list(root_list);*/
	huffman(root_list);
	printf("\ncomplete tree\n");
	display_tree(root_list,arr,0);
	return 0;
}

void display_tree(struct list* temp,int arr[],int top){
	int i;
	if(temp->left!=NULL){
		//printf("0");
		arr[top]=1;
		display_tree(temp->left,arr,top+1);
	}
	if(temp->right!=NULL){
		//printf("1");
		arr[top]=0;
		display_tree(temp->right,arr,top+1);
	}
	if(temp->left==NULL && temp->right==NULL){
		printf("%d: ",temp->val);
		for(i=0;i<top;i++){
			printf("%d",arr[i]);
		}
		printf("\n");	
	}
}

void huffman(struct list* temp){
	if(root_list->next==NULL)
		return;
	else{
		int min1,min2;
		struct list* new1=(struct list*)malloc(sizeof(struct list));
		min1=find_min(root_list->next,root_list->val);
		pos2=pos1;
		
		min2=find_min(root_list->next,root_list->val);
	
		
		new1->val=min1+min2;
		new1->next=root_list;
		root_list=new1;
		new1->left=pos1;
		new1->right=pos2;
		printf("\nList is:\n");
		display_list(root_list);
		huffman(root_list);
	}
}

void remove_min(struct list* temp,int min){
	if(root_list->val==min){
		pos1=root_list;
		root_list=root_list->next;
		//printf(": %d :",min);
		return;
	}
	else if(temp->next==NULL)
		return;
	else{
		if(temp->next->val==min){
			pos1=temp->next;
			temp->next=temp->next->next;
			//printf(": %d :",min);
			return;
		}
		else{
			remove_min(temp->next,min);
		}
	}

}

int find_min(struct list* temp,int min){
	if(temp!=NULL){
		if(temp->val<min){
			min=temp->val;
		}
		find_min(temp->next,min);
	}
	else{
		remove_min(root_list,min);
		return min;
	}
}

void populate_list(struct list* temp,int val1){
	if(root_list==NULL){
		struct list* new1=(struct list*)malloc(sizeof(struct list));
		new1->val=val1;
		new1->next=NULL;
		new1->left=NULL;
		new1->right=NULL;
		root_list=new1;
	}
	else if(temp->next!=NULL)
		populate_list(temp->next,val1);
	else{
		struct list* new1=(struct list*)malloc(sizeof(struct list));
		new1->val=val1;
		new1->next=NULL;
		new1->left=NULL;
		new1->right=NULL;
		temp->next=new1;
	}
}

void display_list(struct list* temp){
	if(temp!=NULL){
		printf("%d ",temp->val);
		display_list(temp->next);
	}
	else{
		return;
	}
}