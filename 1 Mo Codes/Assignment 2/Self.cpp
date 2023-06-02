#include<iostream>
using namespace std;
#define maxval 9999

class node{
	public:
		int k;
		node *left,*right;
		bool rith,leth;
};

class TBT{
	public:
		node *root;
		TBT(){ 
			root= new node();
			root->right= root->left= root;
			root->leth = true;
			root->k = maxval;
		}	
		
		void insert(int key){
			node *p=root;
			for(;;){
				if(p->k<key){
					if(p->rith)
					break;
					p=p->right;
				}
				else if(p->k>key){
					if(p->leth)
					break;
					p=p->left;
				}
				else{
					return;
				}
			}
			node *temp=new node();
			temp->k=key;
			temp->rith=temp->leth=true;
			if(p->k<key){
				temp->right=p->right;
				temp->left=p;
				p->right=temp;
				p->rith=false;
			}
			else{
				temp->right=p;
				temp->left=p->left;
				p->left=temp;
				p->leth=false;
			}
		}
		
		void create_TBT(){
			int n,ch=1;
			do{
				cout<<"\nEnter value:";
				cin>>n;
				insert(n);
				cout<<"\nWant to continue(1/0): ";
				cin>>ch;
			}while(ch!=0);
		}
		
		void inorder_rec(node *temp){
			if(temp!=NULL){
				if(temp->leth==false)
				inorder_rec(temp->left);
				cout<<"\t"<<temp->k;
				if(temp->rith==false)
				inorder_rec(temp->right);
			}
		}
		
		void postorder_rec(node *temp){
			if (temp!=NULL){
				if(temp->leth==false)
				postorder_rec(temp->left);
				if(temp->rith==false)
				postorder_rec(temp->right);
				cout<<"\t"<<temp->k;
			} 
		}
		
		void preorder_rec(node *temp){
			if (temp!=NULL){
				cout<<"\t"<<temp->k;
				if(temp->leth==false)
				preorder_rec(temp->left);
				if(temp->rith==false)
				preorder_rec(temp->right);
			} 
		}
		
		node* inorder_successor(node *t1){
			if(t1->rith== 1)
			t1 = t1->right;
			else{
				t1 = t1->right;
				while(t1->leth == 0)
				t1 = t1->left;
			}
			return t1;
		}

		void inorder_traversal() {
			node *t1 = root->left;
			while(t1->leth == 0)
			t1 = t1->left;
			while(t1!=root){
				cout<<"\t"<<t1->k;
				t1 = inorder_successor(t1);
			} 
		}
};



int main(){
	TBT t;
	int ch;
	do{
		cout<<"\nChoose the choices from the following opitions: ";
		cout<<"\n1. Create TBT\n2. Inorder Recursive Traversal\n3. Postorder Recursive Traversal\n4. Preorder Recursive Traversal\n5. Inorder Non recursive Traversal\n6. Exit.\nEnter choice: ";
		cin>>ch;
		switch(ch){
			case 1:{
				t.create_TBT();
				break;
			}
			case 2:{
				cout<<"\nInorder Recursive Traversal"<<endl;
				t.inorder_rec(t.root->left);
				break;
			}
			case 3:{
				cout<<"\nPostorder Recursive Traversal"<<endl;
				t.postorder_rec(t.root->left);
				break;
			}
			case 4:{
				cout<<"\nPreorder Recursive Traversal"<<endl;
				t.preorder_rec(t.root->left);
				break;
			}
			case 5:{
				cout<<"\nInorder Non Recursive Traversal"<<endl;
				t.inorder_traversal();
				break;
			}
		}
	}while(ch!=6);
	return 0;
}
