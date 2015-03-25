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
void form_loop(struct node* temp);
void detect_remove_loops(struct node* temp);
int count=0;
int main(){
	add_node(root);
	add_node(root);
	add_node(root);
	add_node(root);
	add_node(root);
	add_node(root);
	add_node(root);
	display(root);
	/*delete_node(root);
	delete_node(root);
	delete_node(root);*/
	display(root);
	printf("\n");
	form_loop(root);
	printf("\n");
	display(root);
	detect_remove_loops(root);
	printf("\n");
	display(root);
	return 0;
}

void add_node(struct node* temp){
	int val1,pos1;
	int flag=0;
	struct node* new1=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter value to insert and position:");
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
	if(count++>50){
		count=0;
		return;
	}
	if(temp==NULL)
		return;
	else{
		printf("%d ",temp->val);
		display(temp->next);
	}
}

void form_loop(struct node* temp){
	
	struct node* start=temp->next->next;
	
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=start;

}

void detect_remove_loops(struct node* temp){
	int num=0;
	int pos=0;
	struct node* fast=temp;
	struct node* slow=temp;
	
	do{
		fast=fast->next->next;
		slow=slow->next;
	}while(fast!=slow);

	do{
		slow=slow->next;
		num++;
	}while(fast!=slow);
	
	fast=temp;
	slow=temp;
	
	while(pos++!=num){
		fast=fast->next;
	}
	
	while(fast->next!=slow->next){
		fast=fast->next;
		slow=slow->next;
	}
	
	fast->next=NULL;
	
}













