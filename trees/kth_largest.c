#include <stdio.h>

struct node{
	int val;
	struct node* left;
	struct node* right;
};

struct node* root=NULL;
struct node* pos=NULL;

void insert(struct node* temp,int val1);
void delete(struct node* temp,int val1);
void both_child(struct node* temp,int val1);
void inorder(struct node* temp);
void preorder(struct node* temp);
void postorder(struct node* temp);
int max(struct node* temp);
int min(struct node* temp);
void search(struct node* temp,int val1);
void search_parent(struct node* temp,int val1);

int main(){
	insert(root,9);
	insert(root,8);
	insert(root,23);
	insert(root,17);
	insert(root,11);
	insert(root,10);
	insert(root,15);
	insert(root,12);
	printf("\nInorder: ");
	inorder(root);
	printf("\nPostorder: ");
	postorder(root);
	printf("\nPreorder: ");
	preorder(root);
	/*printf("\nMin is %d and max is %d",min(root),max(root));
	search(root,111);
	if(pos!=NULL)
		printf("\nvalue 11 is %d",pos->val);
	else
		printf("\nno not found");
		*/
	delete(root,10);
	printf("\n\nAfter deletion of node 11\n");
	printf("\nInorder: ");
	inorder(root);
	printf("\nPostorder: ");
	postorder(root);
	printf("\nPreorder: ");
	preorder(root);
	return 0;
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

void both_child(struct node* temp,int val1){
	int min1,max1;
	min1=max1=-1;
	if(temp->right!=NULL){
		min1=min(temp->right);
	}
	else{
		max1=max(temp->left);
	}
	
	if(min1!=-1){
		delete(temp,min1);
		temp->val=min1;
	}
	else{
		delete(temp,max1);
		temp->val=max1;
	}
	return ;
}

void delete(struct node* temp,int val1){
	
	if(root->val==val1){
		both_child(root,val1);
	}
	else if(temp->left!=NULL && temp->left->val==val1){
		if(temp->left->left==NULL && temp->left->right==NULL){//no child
			temp->left=NULL;
			return ;
		}
		else if(temp->left->left==NULL && temp->left->right!=NULL)//only right child
			temp->left=temp->left->right;
		else if(temp->left->left!=NULL && temp->left->right==NULL)//only left child
			temp->left=temp->left->left;
		else{//both child
			
			both_child(temp->left,val1);
		}
	}
	else if(temp->right!=NULL && temp->right->val==val1){
		if(temp->right->left==NULL && temp->right->right==NULL)//no child
			temp->right=NULL;
		else if(temp->right->left==NULL && temp->right->right!=NULL)//only right child
			temp->right=temp->right->right;
		else if(temp->right->left!=NULL && temp->right->right==NULL)//only left child
			temp->right=temp->right->left;
		else{//both child
			
			both_child(temp->right,val1);
		}
	}
	else{
		
		if(val1>temp->val){
			if(temp->right==NULL){
				printf("Element not found121\n");
				return ;
			}
			else{
				delete(temp->right,val1);
			}
		}
		else{
			if(temp->left==NULL){
				
				return ;
			}
			else{
				delete(temp->left,val1);
			}
		}
	}


}

int min(struct node* temp){

	if(temp->left==NULL)
		return temp->val;
	else{
		min(temp->left);
	}

}

int max(struct node* temp){

	if(temp->right==NULL)
		return temp->val;
	else{
		max(temp->right);
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

void search_parent(struct node* temp,int val1){
	
	if(val1<temp->val){
		if(temp->left->left!=NULL || temp->left->right!=NULL)
			search_parent(temp->left,val1);
		else{
			pos=NULL;
			return;
		}
	}
	else if(val1>temp->val){
		if(temp->right->left!=NULL || temp->right->right!=NULL)
			search_parent(temp->right,val1);
		else{
			pos=NULL;
			return;
		}
	}
	else {
		if(temp->left!=NULL)
			if(temp->left->val==val1){
				pos=temp;
				return;
		}
		if(temp->right!=NULL){
			if(temp->right->val==val1){
				pos=temp;
				return;
			}
		}
	}
}

void search(struct node* temp,int val1){
	
	if(temp==NULL){
		//printf("\nelement not present\n");
		pos=NULL;
		return ;
	}
	else if(val1>temp->val){
		search(temp->right,val1);
	}
	else if(val1<temp->val){
		search(temp->left,val1);
	}
	else{
		//printf("\nElement found\n");
		pos=temp;
		return ;
		//printf("\n%d",pos->val);
	}

}