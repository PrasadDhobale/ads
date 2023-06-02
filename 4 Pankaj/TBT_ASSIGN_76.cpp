#include <bits/stdc++.h>
#include<iostream>
#include <iomanip>
using namespace std;
 
class Node {
    public:
    Node *left, *right;
    int Data;

    bool LT;
    bool RT;
    
    Node()
    {
    	left=NULL;
    	right=NULL;
	}


    Node* insert(Node* root, int ikey)
    {
        Node* ptr = root;
        Node* par = NULL; 
        
        while (ptr != NULL) {
            
            if (ikey == ptr->Data)
            {
                cout<<endl<<"\t\t Duplicate Key!";
                return root;
            }
 
            par = ptr;
 
            if (ikey < ptr->Data) {
                if (ptr->LT == false)
                    ptr = ptr->left;
                else
                    break;
            }
            else { 
            
                if (ptr->RT == false)
                    ptr = ptr->right;
                else
                    break;
            }
        }
 
        Node* newNode = new Node;
        newNode->Data = ikey;
        newNode->LT = true;
        newNode->RT = true;
        
        if (par == NULL) {
            root = newNode;
    
        }
        else if (ikey < (par->Data)) {
            
            newNode->left = par->left;   
            newNode->right = par;        
            par->LT = false;       
            par->left = newNode;   
        
        }
        else {
        	
            newNode->left = par;           
            newNode->right = par->right;  
            par->RT = false;         
            par->right = newNode;     
            
        }
        return root;
    }
    
    
    void inorder(Node* root){
        if(root == NULL)
            return;
       
        
        if(root->LT == false)
            inorder(root->left);
        
        cout << root->Data<< " ";
       
        if(root->RT == false)
            inorder(root->right);
    }
    
    
    void preorder(Node* root){
        if(root == NULL)
            return;
       
        cout << root->Data<< " ";
        
       
        if(root->LT == false)
            preorder(root->left);
        
        if(root->RT == false)
            preorder(root->right);
    }
    
    
    void postorder(Node* root){
        if(root == NULL)
            return;
       
        if(root->LT == false)
            postorder(root->left);
        
        if(root->RT == false)
            postorder(root->right);
        
        cout << root->Data<< " ";
    }
   
    Node* inorderSuccessor(Node* ptr)
    {

        if (ptr->RT == true)
            return ptr->right;
 
        ptr = ptr->right;
        while (ptr->LT == false)
            ptr = ptr->left;
        return ptr;
    }

    void inOrder(Node* root)
    {
        if (root == NULL)
            cout<<endl<<"\t Tree is empty";
 
        Node* ptr = root;
        while (ptr->LT == false)
            ptr = ptr->left; 
 
        
        while (ptr != NULL) {
            cout<<" "<<ptr->Data;
            
        ptr = inorderSuccessor(ptr);
        }
    }
    
 void INorder(Node* root) {
 	
   Node *temp = root;
   while (temp != NULL) {
      while (temp->LT == true) {
         temp = temp->left;
      }
      cout << temp->Data << " ";
      if (temp->RT == true) {
         temp = temp->right;
      } 
	  else {
         temp = temp->right;
         
         while (temp != NULL && temp->LT == false) {
            temp = temp->right;
         }
      }
   }
   cout << endl;
}
    
    void preOrder(Node *root)
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
            cout<<ptr->Data<<" ";
            if(ptr->LT==false)
                ptr=ptr->left;
            else if(ptr->RT==false)
                ptr=ptr->right;
            else
            {
                while(ptr!=NULL && ptr->RT==true)
                    ptr=ptr->right;    
                if(ptr!=NULL)
                    ptr=ptr->right;   
            }
        }
    }

    Node* inSucc(Node* ptr)
    {
        if (ptr->RT == true)
            return ptr->right;
 
        ptr = ptr->right;
        while (ptr->LT == false)
            ptr = ptr->left;
 
        return ptr;
    }

    Node* inPred(Node* ptr)
    {
        if (ptr->LT == true)
            return ptr->left;
 
        ptr = ptr->left;
        while (ptr->RT == false)
            ptr = ptr->right;
        
        return ptr;
    }

    Node* caseA(Node* root, Node* par,Node* ptr)
    {
        if (par == NULL)
            root = NULL;
 
        else if (ptr == par->left) {
            par->LT = true;
            par->left = ptr->left;
        }
        else {
            par->RT = true;
            par->right = ptr->right;
        }
 
        delete ptr;
        
        return root;
    }
 
    Node* caseB(Node* root, Node* par,Node* ptr)
    {
        Node* child;
 
        if (ptr->LT == false)
            child = ptr->left;
 
        else
            child = ptr->right;
 
        if (par == NULL)
            root = child;
 
        else if (ptr == par->left)
            par->left = child;
        else
            par->right = child;
 
        Node* s = inSucc(ptr);
        Node* p = inPred(ptr);
 
        if (ptr->LT == false)
            p->right = s;
 
        else {
            if (ptr->RT == false)
                s->left = p;
        }
 
        delete ptr;
        
        return root;
    }
 
    Node* caseC(Node* root,Node* par,Node* ptr)
    {
        Node* parsucc = ptr;
        Node* succ = ptr->right;
 
        while (succ->LT==false) {
            parsucc = succ;
            succ = succ->left;
        }
 
        ptr->Data = succ->Data;
 
        if (succ->LT == true && succ->RT == true)
            root = caseA(root, parsucc, succ);
        else
            root = caseB(root, parsucc, succ);
 
        return root;
    }
 
    Node* delThreadedBST(Node* root, int dkey)
    {
        Node *par = NULL, *ptr = root;
 
        int found = 0;
 
        while (ptr != NULL) {
            if (dkey == ptr->Data) {
                found = 1;
                break;
            }
            par = ptr;
            if (dkey < ptr->Data) {
                if (ptr->LT == false)
                    ptr = ptr->left;
                else
                    break;
            }
            else {
                if (ptr->RT == false)
                    ptr = ptr->right;
                else
                    break;
            }
        }
 
        if (found == 0)
            cout<<"key not present in tree\n";
        
        else if (ptr->LT == false && ptr->RT == false)
           root = caseC(root, par, ptr);
 
        else if (ptr->LT == false)
            root = caseB(root, par, ptr);
 
        else if (ptr->RT == false)
            root = caseB(root, par, ptr);
 
        else
            root = caseA(root, par, ptr);
 
        return root;
    }
    
    Node* search(Node* root, int key) {
        if(root == NULL || root->Data == key)        
            return root;

        if(root->Data < key && root->RT==false)
            return search(root->right,key);

        else if (root->Data > key && root->LT==false)
            return search(root->left,key);
    }
    
    Node* Search(Node* root, int key) 
	{
     Node* current = root;

     while (current != NULL) {
     	
        if (current->Data == key) {
            return current;
        }
        else if (current->Data < key && current->RT == false) {
            current = current->right;
        }
        else if (current->Data > key && current->LT == false) {
            current = current->left;
        }
        else {
            break;
        }
    }
    return NULL;
}

    void printLevelOrder(Node *root)  
    {  
        if (root == NULL) return;  
  
        queue<Node *> q;  
  
        q.push(root);  
  
        while (q.empty() == false)  
        {  
            cout<<" ===> ";
            
		     	while (q.empty() == false)
				 {
				   
                Node *node = q.front();  
                cout<<node->Data<<" ";  
                q.pop();  
                
                if (node->LT == false)  
                    q.push(node->left);  
                if (node->RT == false)  
                    q.push(node->right); 
					
			
            }
		
        }  
    }
    
    
void display_menu() {
	
    cout << setfill('*') << setw(60) << "" << endl;
    cout << setfill(' ');
    cout << setw(28) << "You Can Perform Following Operations on Threaded Binary Tree :-" << endl;
    cout << setw(60) << "" << endl;
    cout << "1. Create" << endl;
    cout << "2. Insert" << endl;
    cout << "3. Delete " << endl;
    cout << "4. Search " << endl;
    cout << "5. Display" << endl;
    cout << "6. Breadth First Search" << endl;
    cout << "7. Exit" << endl;
    cout << setw(60) << "" << endl;
}
};

int main()
{
    Node Tree;
   
    Node* root = NULL;
    int choice;
    char ch='Y';
    
    while(ch=='Y'||ch=='y')
    {
        Tree.display_menu();
	    cout<<endl<<"\t Enter your Choice :- ";
        cin>>choice;
        
        switch(choice)
        {
            case 1: 
                int t;
                cout<<endl<<"\t Enter number of nodes you want to insert :- ";
                cin>>t;
                while(t--){
                    int data;
                    cout<<endl<<"\t\t Enter "<<t<<" Element......:- ";
                    cin>>data;
                    root = Tree.insert(root,data);
                }
                cout<<endl<<"\t ................TBT Constructed............"<<endl;
                break;
                
            case 2: 
                t=0;
                cout<<endl<<"\t Enter data to insert in TBT :- ";
                cin>>t;
                root = Tree.insert(root,t);
                cout<<endl<<"\t\t ................Node added in TBT............";
                break;
                
            case 3: 
                int delete_data;
                cout<<endl<<"\t Enter the node tobe Deleted :-";
                cin>>delete_data;
                
                root = Tree.delThreadedBST(root, delete_data);
                
                cout<<endl<<"\t\t Non-Recursive Inorder Traversal of TBT is as :- ";
                Tree.inOrder(root);
                
                break;
                
            case 4:
                
                if(root!=NULL){
                    cout<<endl<<"\t\t Enter the data to Search in TBT :";
                    int data;
                    cin>>data;
                    
                    if(Tree.Search(root,data)!=NULL)
                        cout<<endl<<"\t\t ......."<<data<<" is found in TBT..............";
                    else
                        cout<<endl<<"\t\t ......."<<data<<" is not found in TBT..............";
                }
                else
                    cout<<endl<<"\t ...............TBT is Empty................";
                break;
                
            case 5:
                if(root!=NULL)
                {
                    cout<<endl<<"\t TBT Traversals are as foll0ws :- ";
                    
                    cout<<endl<<endl<<"\t\t Inorder Traversal of Tree is :- ";
                    Tree.inorder(root);
                   
                    cout<<endl<<endl<<"\t\t Non-recursive Inorder Traversal of Tree is :- ";
                    Tree.inOrder(root);
                    
                    cout<<endl<<endl<<"\t\t Preorder Traversal of Tree is :- ";
                    Tree.preorder(root);
                    
                    cout<<endl<<endl<<"\t\t Non-recursive Preorder Traversal of Tree is :- ";
                    Tree.preOrder(root);
                    
                    cout<<endl<<endl<<"\t\t Postorder Traversal of Tree is :- ";
                    Tree.postorder(root);
                    
                }
                else
                    cout<<endl<<"\t ...............TBT is Empty................";
                break;
            case 6: 
                if(root!=NULL)
                {
                    cout<<endl<<"\t Breadth First Search Traversal (LOP) :- ";
                    Tree.printLevelOrder(root);  
                }
                else
                    cout<<endl<<"\t ...............TBT is Empty................";
                break;
            case 7: exit(0);
            default : 
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
