#include <stdio.h>

struct node{
	int val;
	struct node* left;
	struct node* right;
};

struct queue{
	struct node* addr;
	struct queue* next;
	int level;
};

struct node* root=NULL;
struct node* pos=NULL;
struct queue* head=NULL;
struct queue* end=NULL;

void spiral();
void insert(struct node* temp,int val1);
void inorder(struct node* temp);
void preorder(struct node* temp);
void postorder(struct node* temp);
void enqueue(struct node* temp,int level);
int dequeue();

int main(){
	insert(root,15);
	insert(root,8);
	insert(root,23);
	insert(root,17);
	insert(root,11);
	insert(root,7);
	insert(root,25);
	printf("\nInorder: ");
	inorder(root);
	printf("\nPostorder: ");
	postorder(root);
	printf("\nPreorder: ");
	preorder(root);
	printf("\nSpiral: ");
	enqueue(root,1);
	spiral();
	return 0;
}

void spiral(){
	int level;
	struct queue* temp=head;
	
	if(head==NULL)
		return;
		
	level=dequeue();
	
	if(temp->addr->left!=NULL){
		enqueue(temp->addr->left,level+1);
	}
	if(temp->addr->right!=NULL){
		enqueue(temp->addr->right,level+1);
	}
		
	spiral();
}


void enqueue(struct node* temp,int level1){
	struct queue* temp1=(struct queue*)malloc(sizeof(struct queue));
	temp1->level=level1;
	temp1->next=NULL;
	temp1->addr=temp;
	if(head==NULL){
		head=temp1;
		end=temp1;
	}
	else{
		end->next=temp1;
		end=temp1;
	}
}

int dequeue(){
	struct queue* temp1,*temp2;
	int val1=head->level;
	//printf("\nlevel %d ",val1);
	if(val1%2==0){
		printf("%d ",head->addr->val);
		head=head->next;
	}
	else{
		temp1=head;
		while(temp1->next!=NULL && temp1->next->level==val1){
			temp2=temp1;
			temp1=temp1->next;
		}
		printf("%d ",temp1->addr->val);
		if(temp1==head){
			head=head->next;
		}
		else{
			temp2->next=temp1->next;
		}
	}
	return val1;
}

void insert(struct node* temp,int val1){

	if(root==NULL){
		struct node* new1=(struct node*)malloc(sizeof(struct node));
		root=new1;
		new1->val=val1;
		new1->left=NULL;
		new1->right=NULL;
	}
	else if(val1>temp->val){
		if(temp->right==NULL){
			struct node* new1=(struct node*)malloc(sizeof(struct node));
			temp->right=new1;
			new1->val=val1;
			new1->left=NULL;
			new1->right=NULL;
		}
		else{
			insert(temp->right,val1);
		}
	}
	else if(val1<temp->val){
		if(temp->left==NULL){
			struct node* new1=(struct node*)malloc(sizeof(struct node));
			temp->left=new1;
			new1->val=val1;
			new1->left=NULL;
			new1->right=NULL;
		}
		else{
			insert(temp->left,val1);
		}
	}
	else{
		printf("\nDuplicate entry\n");
	}

}

void inorder(struct node* temp){
	if(temp==NULL)
		return;
	else{		
		inorder(temp->left);
		printf("%d ",temp->val);
		inorder(temp->right);
	}
}
void preorder(struct node* temp){
	if(temp==NULL)
		return;
	else{
		printf("%d ",temp->val);
		preorder(temp->left);
		preorder(temp->right);
	}
}
void postorder(struct node* temp){
	if(temp==NULL)
		return;
	else{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d ",temp->val);
	}
}