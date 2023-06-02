#include<iostream>
#define Max_value 9999
using namespace std;

class Node
{
	public:
		int info;
		Node *left,*right;
		bool lthread,rthread;
};

class TBT
{
	public:
		Node*insert(Node*root, int ikey)
		{
			Node*p=root;
			Node*par=NULL;
			while(p!=NULL)
			{
				if(ikey == p->info)
				{
					cout<<endl<<"\t\t !!Duplicate Key!!";
					return root;
				}
				par=p;
				if(ikey<p->info)
				{
					if(p->lthread==false)
						p=p->left;
					else
						break;
				}
				else
				{
					if(p->rthread==false)
						p=p->right;
					else
						break;		
				}
			}	
			Node*tmp=new Node;
			tmp->info=ikey;
			tmp->lthread=true;
			tmp->rthread=true;
	
			if(par==NULL)
			{
				root=tmp;
				tmp->left=NULL;
				tmp->right=NULL;
			}
			else if(ikey<(par->info))
			{
				tmp->left=par->left;
				tmp->right=par;
				par->lthread=false;
				par->left=tmp;
			}
			return root;
		}
		
		void inorder(Node*root);
		void preorder(Node* root);
		void postorder(Node* root);
		// Returns inorder successor using rthread (Used in inorder)
		Node* inorderSuccessor(Node* ptr)
	    {
	        // If rthread is set, we can quickly find
	        if (ptr->rthread == true)
	            return ptr->right;
	 
	        // Else return leftmost child of right subtree
	        ptr = ptr->right;
	        while (ptr->lthread == false)
	            ptr = ptr->left;
	        return ptr;
	    }
	    // Non-recursive Printing the threaded tree in Inorder
	    void inOrder(Node* root);
	    
	    // Non-recursive Preorder Traversal of TBT
	    void preOrder(Node *root);
	    
	    //Non-recursive Postorder Traversal of TBT
	    void postOrder(Node* root);
	    void del();
	    void search();
	    void printlevelorder();
};

void TBT :: inorder(Node*root)
{
	if(root==NULL)
		return;
			
	if(root->lthread==false)
		inorder(root->left);
		cout<<root->info<<" ";
			
	if(root->rthread == false)
		inorder(root->right);	
}

void TBT :: preorder(Node* root)
{
	if(root==NULL)
		return;
			
	cout<<root->info<<" ";
			
	if(root->lthread== false)
		preorder(root->left);
			
	if(root->rthread==false)
		preorder(root->right);
}

void TBT :: postorder(Node* root)
{
	if(root == NULL)
		return;
				
	if(root->lthread == false)
		postorder(root->left);
			
	if(root->rthread == false)
		postorder(root->right);
	cout<<root->info<<" ";
}

void TBT :: inOrder(Node* root)
{
    if (root == NULL)
	    cout<<endl<<"\t Tree is empty";
	 
	// Reach leftmost Node
    Node* ptr = root;
	while (ptr->lthread == false)
		ptr = ptr->left;
	 
	    // One by one print successors
	    //cout<<endl<<"\t Tree is as :-";
	    while (ptr != NULL) 
		{
	        cout<<" "<<ptr->info;
	        ptr = inorderSuccessor(ptr);
	    }
}

void TBT :: preOrder(Node *root)
{
    Node *ptr;
	if(root==NULL)
	{
	    cout<<"Tree is empty";
	    return;
	}
	ptr=root;
	while(ptr!=NULL)
	{
		cout<<ptr->info<<" ";
        if(ptr->lthread==false)
	        ptr=ptr->left;
	    else if(ptr->rthread==false)
	        ptr=ptr->right;
	    else
	    {
	        while(ptr!=NULL && ptr->rthread==true)
	            ptr=ptr->right;    // go to successor / parent
	        if(ptr!=NULL)
	            ptr=ptr->right;    // go to right child of successor / parent
	    }
    }
}

//void TBT :: postOrder(Node* root)
//{
//	// Non-Recursive Postorder Traversal
//	stack<Node *> S1;
//    stack<Node *> S2;
//    S1.push(root);
//    while(S1.empty()==false)
//    {
//        S2.push(S1.top());
//        Node* temp=S1.top();
//        S1.pop();
//        if(temp->lthread==false) S1.push(temp->left);
//        if(temp->rthread==false) S1.push(temp->right);
//    }
//    while(!S2.empty())
//    {
//        Node* temp=S2.top();
//        S2.pop();
//        cout<<temp->data<<" ";
//    }
//    cout<<endl;
//}

void TBT :: postOrder(Node *root)
 {
 	// Base Case
 	if (root == NULL) return;
 	// Create two empty stack for post order traversal
 	stack<Node *> s1;
 	stack<Node *> s2;

	// Enqueue Root and initialize height
 	s1.push(root);

 	while (s1.empty() == false)
 	{
 		Node *node = s1.top();
 		s1.pop();

 		s2.push(node);

 		if (node->left != NULL)
 		s1.push(node->left);

 		if (node->right != NULL)
 		s1.push(node->right);
 	}
 	while(!s2.empty())
 	{
 		Node *n= s2.top();
 		cout<<n->data<<" ";
		 s2.pop();
	}
}

int main()
{
	TBT Tree;
	
	Node*root=NULL;
	int choice;
	char ch='Y';
	while(ch=='Y'||ch=='y')
	{
		cout<<endl<<"\tYou Can Perform Following Operations on Threaded Binary Tree :-"<<endl;
		cout<<endl<<"\t\t 1. Create"<<endl<<"\t\t 2. Recursive in-order traversal"<<endl<<"\t\t 3. Recursive preorder traversal"<<endl<<"\t\t 4. Recursive post-order traversal"<<endl<<"\t\t 5. Non-recursive in-order traversal"<<endl<<"\t\t 6. Non recursive preorder traversal"<<endl<<"\t\t 7. Non recursive post-order traversal"<<endl<<"\t\t 8. Exit";
		cout<<endl<<"\n\tEnter your Choice:- ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				//Number of nodes to be inserted
				int t;
				cout<<endl<<"\t Enter number of nodes you want to insert :- ";
				cin>>t;
				while(t--)
				{
					int data;
					cout<<endl<<"\t\t Enter "<<t<<" Element :- ";
					cin>>data;
					root=Tree.insert(root,data);
				}
				cout<<endl<<"\t.............TBT Constructed..............."<<endl;
				break;
			case 2:
				cout<<endl<<endl<<"\t\t Inorder Traversal of Tree is :- ";
                Tree.inorder(root);
				break;
			case 3:
				cout<<endl<<endl<<"\t\t Preorder Traversal of Tree is :- ";
                Tree.preorder(root);
                break;
            case 4:
            	cout<<endl<<endl<<"\t\t Postorder Traversal of Tree is :- ";
                Tree.postorder(root);
                break;
            case 5:
            	cout<<endl<<endl<<"\t\t Non-recursive Inorder Traversal of Tree is :- ";
                Tree.inOrder(root);
            	break;
            case 6:
            	cout<<endl<<endl<<"\t\t Non-recursive Preorder Traversal of Tree is :- ";
                Tree.preOrder(root);
                break;
//            case 7:
//            	cout<<endl<<endl<<"\t\t Non-recursive Postorder Traversal of Tree is :- ";
//            	Tree.postOrder(root);
            	break;
            case 8:
				exit(0); 
            default: 
				cout<<endl<<"\t\t ...............Invalid Choice.....Re-enter your choice Again";
                break;
		}
		cout<<endl<<endl<<"\t Do you want to continue (Y/N)..........";
        cin>>ch;
        if(ch=='Y' || ch=='y')
            continue;
        else
            exit(0);
	}
	return 0;
}






