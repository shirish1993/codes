#include <stdio.h>

struct node{
	int val;
	struct node* left;
	struct node* right;
};

struct node* root=NULL;

void insert(struct node* temp,int val1);
void inorder(struct node* temp);
void preorder(struct node* temp);
void postorder(struct node* temp);
void mirror(struct node* temp);

int main(){
	insert(root,15);
	insert(root,8);
	insert(root,23);
	insert(root,17);
	insert(root,11);
	insert(root,7);
	insert(root,25);
	printf("\nInorder (in ascending order): ");
	inorder(root);
	printf("\nPostorder: ");
	postorder(root);
	printf("\nPreorder: ");
	preorder(root);
	mirror(root);
	printf("\n======\nAfter mirroring\n======");
	printf("\nInorder (in descending order): ");
	inorder(root);
	printf("\nPostorder: ");
	postorder(root);
	printf("\nPreorder: ");
	preorder(root);
	return 0;
}

void mirror(struct node* temp){
	struct node* temp1;
	if(temp==NULL){
		return;
	}
	temp1=temp->left;
	temp->left=temp->right;
	temp->right=temp1;
	mirror(temp->left);
	mirror(temp->right);
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