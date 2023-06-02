/* AVL tree operations:
    1. Creation
    2. Display level wise
    3. In,Pre,post order traversal using both recursive and non-reccursive method
*/
#include<iostream>
using namespace std;
class AVL
{
    public:
        int value;
        AVL *left;
        AVL *right;
} *root;

class AVL_Tree
{
    public:
        int height(AVL *);
        int diff(AVL *);
        AVL *right_rotation(AVL *);
        AVL *left_rotation(AVL *);
        AVL *left_right_rotation(AVL *);
        AVL *right_left_rotation(AVL *);
        AVL* balance(AVL *);
        AVL* insert(AVL *,int);
        void display(AVL *);
        
        void inorder_nonrec(AVL *);
        void preorder_nonrec(AVL *);
        void postorder_nonrec(AVL *);
        AVL_Tree()
		{
            root=NULL;
        }
};
// Height of AVL Tree
int AVL_Tree :: height(AVL *temp)
{
    int h = 0;
    if (temp != NULL){
        int left_height = height(temp->left);
        int right_height = height(temp->right);
        int max_height = max(left_height,right_height);
        h = max_height+1;
    }
    return h;
}
//Height Difference
int AVL_Tree :: diff(AVL *temp)
{
    int left_height = height(temp->left);
    int right_height = height(temp->right);
    int b_factor= left_height - right_height;
    return b_factor;
}
//Left-Left Rotation
AVL *AVL_Tree :: left_rotation(AVL *parent)
{
    AVL *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
//Right-Right Rotation
AVL *AVL_Tree::right_rotation(AVL *parent)
{
    AVL *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}
//Left-Right Rotation
AVL *AVL_Tree :: left_right_rotation(AVL *parent)
{
    AVL *temp;
    temp = parent->left;
    parent->left = left_rotation (temp);
    return right_rotation (parent);
}
//Right-Left Rotation
AVL *AVL_Tree :: right_left_rotation(AVL *parent)
{
    AVL *temp;
    temp = parent->right;
    parent->right = right_rotation (temp);
    return left_rotation (parent);
}
//Balancing AVL Tree
AVL *AVL_Tree :: balance(AVL *temp)
{
    int bal_factor = diff(temp);
    if (bal_factor > 1)
	{
        if (diff (temp->left) > 0)
            temp = right_rotation (temp);
        else
            temp = left_right_rotation (temp);
    }
    else if (bal_factor < -1){
        if (diff (temp->right) > 0)
            temp = right_left_rotation(temp);
        else
            temp = left_rotation(temp);
    }
    return temp;
}
//Insertion of node Element into the tree
AVL *AVL_Tree :: insert(AVL *root,int data)
{
    if (root == NULL)
	{
        root = new AVL;
        root->value = data;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if(data < root->value)
	{
        root->left = insert(root->left,data);
        root = balance (root);
    }
    else if(data > root->value)
	{
        root->right = insert(root->right,data);
        root = balance (root);
    }
    else
        cout<<"Node element already exists"<<endl;
    return root;
}
//Display AVL Tree
void AVL_Tree :: display(AVL *ptr)
{
    AVL *que[20];
    int front=0,rear=0;
    que[rear]=ptr;
    while(front<=rear){
        ptr=que[front++];
        if(ptr!=NULL){
            cout<<ptr->value<<" ";
            que[++rear]=ptr->left;
            que[++rear]=ptr->right;
        }
    }
}

class stack
{
	int top;
	AVL *stack_nodes[20];
	public:
		stack()
		{
			top=-1;
		}
		void push(AVL*);
		AVL *pop();
		int empty()
		{
			if(top==-1)
				return 1;
			return 0;
		}
};

void stack::push(AVL* node)
{
	stack_nodes[++top]=node;
}

AVL *stack::pop()
{
	return(stack_nodes[top--]);
}

void AVL_Tree::inorder_nonrec(AVL *c_root)
{
	stack stk;
	AVL *temp;
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
			if (!stk.empty())
			{
				temp=stk.pop();
				
				cout<<temp->value<<" ";
				temp=temp->right;
			}
			else
				break;
			
		}
		while(1);
	}
	else
		cout<<"Tree is empty\n";
	
}

void AVL_Tree::preorder_nonrec(AVL *c_root)
{
	stack stk;
	AVL *temp;
	if(c_root!=NULL)
	{
		stk.push(c_root);
		while(!stk.empty())
		{
			temp=stk.pop();
			cout<<temp->value<<" ";
			if(temp->right!=NULL)
			{
				stk.push(temp->right);
			}
			if(temp->left!=NULL)
			{
				stk.push(temp->left);
			}
		}
	}
	else
	{
		cout<<"Tree is empty"<<endl;
	}
}

void AVL_Tree::postorder_nonrec(AVL *c_root)
{
stack stk1, stk2;
    AVL *temp;
    
    if (c_root != NULL) {
        stk1.push(c_root);

        while (!stk1.empty()) {
            temp = stk1.pop();
            stk2.push(temp);

            if (temp->left != NULL) {
                stk1.push(temp->left);
            }

            if (temp->right != NULL) {
                stk1.push(temp->right);
            }
        }

        while (!stk2.empty()) {
            temp = stk2.pop();
            cout << temp->value << " ";
        }
    } else {
        cout << "Tree is empty" << endl;
    }
}

int main()
{
    int ch, item;
    AVL_Tree avl;
    cout<<"----------- AVL Tree Implementation -------------"<<endl;
    do
	{
        cout<<"\n\nMenu"<<endl;
        cout<<"1.Insert elements into the tree"<<endl;
        cout<<"2.Display levelwise AVL Tree"<<endl;
        cout<<"3.Inorder non-recursive"<<endl;
        cout<<"4.Preorder non-recursive"<<endl;
        cout<<"5.Postorder non-recursive"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"\nEnter your Choice: "<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"\nEnter the node value to be inserted : ";
                cin>>item;
                root = avl.insert(root, item);
                break;
            case 2:
                if (root==NULL){
                    cout<<"Tree is Empty"<<endl;
                    continue;
                }
                cout<<"\nBalanced AVL Tree : ";
                avl.display(root);
                break;
            case 3:
            	cout<<"\nInorder traversal using non-recursive: ";
            	avl.inorder_nonrec(root);
            	break;
            case 4:
            	cout<<"\nPreorder traversal using non-recursive:";
            	avl.preorder_nonrec(root);
            	break;
            case 5:
            	cout<<"\nPostorder traversal using non-recursive:";
            	avl.postorder_nonrec(root);
            	break;
            case 6:
                cout<<"You have quited the program..."<<endl;
                break;
            default:
                cout<<"Invalid Input try again..."<<endl;
        }
    }
    while(ch!=6);
    return 0;
}
