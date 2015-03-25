#include <stdio.h>

struct node{
	int val;
	struct node* next;
};

struct node* root=NULL;

struct node* left=NULL;

void add_node(struct node* temp);
void delete_node(struct node* temp);
void display(struct node*temp);
void reverse(struct node* temp);

int main(){
	add_node(root);
	add_node(root);
	add_node(root);
	add_node(root);
	display(root);
	/*delete_node(root);
	delete_node(root);
	delete_node(root);*/
	reverse(root);
	printf("\nReverse ll is :\n");
	display(root);
	
	
	return 0;
}

void add_node(struct node* temp){
	int val1,pos1;
	struct node* new1=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter value to insert and position:");
	int flag=0;
	scanf("%d %d",&val1,&pos1);
	new1->val=val1;
	if((root==NULL && pos1==1) || pos1==1){
		new1->next=root;
		root=new1;
		flag=1;
	}
	else{
		int check=2;
		while(temp!=NULL){
				if(check++==pos1){
					flag=1;
					break;
				}
				temp=temp->next;
		}
		if(flag==1){
			new1->next=temp->next;
			temp->next=new1;
		}
	}	
	if(flag==0){
		printf("Enter valid position\n");
	}
}

void delete_node(struct node* temp){
	int val1;
	int flag=0;
	printf("\nEnter element to delete");
	scanf("%d",&val1);
	if(temp->val==val1){
		flag=1;
		root=temp->next;
	}
	else{
		while(temp->next!=NULL){
			if(temp->next->val==val1){
				flag=1;
				break;
			}
			temp=temp->next;
		}
		if(flag==1)
			temp->next=temp->next->next;
	}
	if(flag==0){
		printf("Invalid node\n");
	}
}

void display(struct node*temp){
	if(temp==NULL)
		return;
	else{
		printf("%d ",temp->val);
		display(temp->next);
	}
}

void reverse(struct node* temp){
	
	if(temp->next!=NULL){
		root=temp->next;
		temp->next=left;
		left=temp;
		reverse(root);
	}
	else{
		temp->next=left;
		return;
	}

}














