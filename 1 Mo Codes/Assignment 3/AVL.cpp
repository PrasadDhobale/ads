#include<iostream>
using namespace std;
class avlt
{
	public:
	int value;
	avlt *left;
	avlt *right;
} *root;

class avlt_Tree
{
	public:
	int height(avlt *);
	int diff(avlt *);
	avlt *right_rotation(avlt *);
	avlt *left_rotation(avlt *);
	avlt *left_right_rotation(avlt *);
	avlt *right_left_rotation(avlt *);
	avlt* balance(avlt *);
	avlt* insert(avlt *, int );
	void display(avlt *);
	void inorder(avlt *);
	void preorder(avlt *);
	void postorder(avlt *);
	void inorder_non_rec(avlt *);
	void preorder_non_rec(avlt *);
	void postorder_non_rec(avlt *);
	avlt_Tree()
	{
	root = NULL;
	}
};
// Height of avlt Tree
int avlt_Tree::height(avlt *temp)
{
	int h = 0;
	if (temp != NULL)
	{
		 int left_height = height (temp->left);
		 int right_height = height (temp->right);
		 int max_height = max (left_height,right_height);
		 h = max_height + 1;
	}
	return h;
}
//Height Difference
int avlt_Tree::diff(avlt *temp)
{
	int left_height = height (temp->left);
	int right_height = height (temp->right);
	int b_factor= left_height - right_height;
	return b_factor;
}
//Left Rotation
avlt *avlt_Tree::left_rotation(avlt *parent)
{
	avlt *temp;
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	return temp;
}

//Right Rotation
avlt *avlt_Tree::right_rotation(avlt *parent)
{
	avlt *temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}

//Left - Right Rotation
avlt *avlt_Tree::left_right_rotation(avlt *parent)
{
	avlt *temp;
	temp = parent->left;
	parent->left = right_rotation (temp);
	return left_rotation (parent);
}
//Right- Left Rotation
avlt *avlt_Tree::right_left_rotation(avlt *parent)
{
	avlt *temp;
	temp = parent->right;
	parent->right = left_rotation (temp);
	return right_rotation (parent);
}
//Balancing avlt Tree
avlt *avlt_Tree::balance(avlt *temp)
{
	int bal_factor = diff(temp);
	if (bal_factor > 1)
	{
	if (diff (temp->left) > 0)
	temp = right_rotation (temp);
	else
	temp = left_right_rotation (temp);
	}
	else if (bal_factor < -1)
	{
	if (diff (temp->right) > 0)
	temp = right_left_rotation(temp);
	else
	temp = left_rotation(temp);
	}
	return temp;
}
//Insertion of node Element into the tree
avlt *avlt_Tree::insert(avlt *root,int data)
{
	if (root == NULL)
	{
	root = new avlt;
	root->value = data;
	root->left = NULL;
	root->right = NULL;
	return root;
	}
	else
	if (data< root->value)
	{
	root->left = insert(root->left,data);
	root = balance (root);
	}
	else if (data>root->value)
	{
	root->right = insert(root->right,data);
	root = balance (root);
	}
	else
	cout<<" node element already exists\n";
	return root;
}
//Display avlt Tree
void avlt_Tree::display(avlt *ptr)
{
	avlt *que[20];
	int front=0,rear=0;
	que[rear]=ptr;
	while(front<=rear)
	{
		ptr=que[front++];
		if(ptr!=NULL)
		{
			cout<<" "<<ptr->value<<" ";
			que[++rear]=ptr->left;
			que[++rear]=ptr->right;
		}
	}
}

class stack
{
	int top;
	avlt *stack_nodes[20];
	public:
	stack()
	{
		top=-1;
	}
	void push(avlt *);
	avlt* pop();
	avlt* peek( stack stk);
	int empty()
	{
		if(top==-1)
		return(1);
		return(0);
	}
};

void stack::push(avlt *node)
{
	stack_nodes[++top]=node;
}

avlt *stack::pop()
{
	return(stack_nodes[top--]);
}

void avlt_Tree::inorder(avlt *tree)
{
	if (tree == NULL)
	return;
	inorder (tree->left);
	cout<<tree->value<<" ";
	inorder (tree->right);
}
void avlt_Tree::inorder_non_rec(avlt *c_root)
{
	stack stk;
	avlt *temp;
	if(c_root!=NULL)
	{
		temp=c_root;
		do
		{
			while(temp!=NULL)
			{
				stk.push(temp);
				temp=temp->left;
			}
			if(!stk.empty())
			{
				temp=stk.pop();
				cout<<temp->value<<" ";
				temp=temp->right;
			}
			else
			break;
		}while(1);
	}
	else
	cout<<" The tree is empty ";
}

//Preorder Traversal of avlt Tree
void avlt_Tree::preorder(avlt *tree)
{
	if (tree == NULL)
	return;
	cout<<tree->value<<" ";
	preorder (tree->left);
	preorder (tree->right);
}
void avlt_Tree::preorder_non_rec(avlt *c_root)
{
	stack stk;
	avlt *temp=root;
	stk.push(temp);
	while(!stk.empty())
	{
		temp=stk.pop();
		if(temp!=NULL)
		{
			cout<<temp->value<<" ";
			stk.push(temp->right);
			stk.push(temp->left);
		}
	}
}
//Postorder Traversal of avlt Tree
void avlt_Tree::postorder(avlt *tree)
{
	if (tree == NULL)
	return;
	postorder ( tree ->left );
	postorder ( tree ->right );
	cout<<tree->value<<" ";
}
void avlt_Tree::postorder_non_rec(avlt *ptr)
{
	int flag[50];
	int top_prev;
	avlt * stkarr[50];
	int top =1;
	stkarr[++top]=NULL;
	do
	{
		while (ptr!=NULL)
		{
			stkarr[++top]=ptr;
			flag[top]=1;
			if (ptr->right !=NULL)
			{
				stkarr[++top]=ptr->right;
				flag[top]=-1;
			}
			ptr=ptr->left;
		}
		top_prev=top;
		ptr=stkarr[top--];
		while (flag[top_prev]==1)
		{
			cout<<ptr->value<<" ";
			top_prev=top;
			ptr=stkarr[top--];
		}
	}while (ptr!=NULL);
}

int main()
{
	int ch, item;
	avlt_Tree avlt;
	do
	{
		cout<<"\n ----Select the Options Given Below----";
		cout<<"\n 1.Insert elements into the tree";
		cout<<"\n 2.Display levelwise avlt Tree";
		cout<<"\n 3.Recursive Inorder traversal.";
		cout<<"\n 4.Recursive Preorder traversal.";
		cout<<"\n 5.Recursive Postorder traversal.";
		cout<<"\n 6.Non Recursive Inorder traversal.";
		cout<<"\n 7.Non Recursive Preorder traversal.";
		cout<<"\n 8.Non Recursive Postorder traversal.";
		cout<<"\n 9.Exit"<<endl;
		cout<<"\n\nEnter your Choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			cout<<"Enter the node value to be inserted: ";
			cin>>item;
			root = avlt.insert(root, item);
			break;
			case 2:
			if (root==NULL)
				{
				cout<<"Tree is Empty"<<endl;
				continue;
			}
			cout<<"Balanced avlt Tree:"<<endl;
			avlt.display(root);
			break;
			case 3:
			cout<<"Recursive Inorder Traversal : "<<endl;
			avlt.inorder(root);
			cout<<endl;
			break;
			case 4:
			cout<<"Recursive Preorder Traversal : "<<endl;
			avlt.preorder(root);
			cout<<endl;
			break;
			
			case 5:
			cout<<"Recursive Postorder Traversal : "<<endl;
			avlt.postorder(root);
			cout<<endl;
			break;
			
			case 6:
			cout<<"Non-Recursive Inorder Traversal : "<<endl;
			avlt.inorder_non_rec(root);
			cout<<endl;
			break;
			
			case 7:
			cout<<"Non-Recursive Preorder Traversal : "<<endl;
			avlt.preorder_non_rec(root);
			cout<<endl;
			break;
			
			case 8:
			cout<<"Non-Recursive Postorder Traversal : "<<endl;
			avlt.postorder_non_rec(root);
			cout<<endl;
			break;
			
			case 9:
			cout<<"\nYou have quited the program...";
			break;
			default:
			cout<<"Invalid Input try again.."<<endl;
			break;
		}
	}while(ch!=9);
	return 0;
}
