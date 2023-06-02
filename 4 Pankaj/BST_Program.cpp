#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
   
    Node* search(Node* root, int key) {
        if(root == NULL || root->data == key)        
            return root;

        if(root->data < key)
            return search(root->right,key);

        return search(root->left,key);
    }
    
    Node* insert(Node* root, int data) {
        if(root == NULL){
            return new Node(data);
        }
     else{
            Node* cur;
            if(data <= root->data) {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else {
                cur = insert(root->right, data);
                root->right = cur;
            }
        return root;
     }
   }
   
   Node* deletenode(Node* root, int k)
    {
        if (root == NULL)
            return root;
   
        if(root->data > k){
            root->left = deletenode(root->left, k);
            return root;
        }
        else if(root->data < k){
            root->right = deletenode(root->right, k);
            return root;
        }
  
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
          Node* Parent = root;
          Node *succ = root->right;
          while (succ->left != NULL) {
              Parent = succ;
              succ = succ->left;
            }

            if (Parent != root)
                Parent->left = succ->right;
            else
                Parent->right = succ->right;

            root->data = succ->data;

            delete succ;          
            return root;
        }
    }
   
    void inorder(Node* root){
        if(root == NULL)
            return;
       
        inorder(root->left);
        
        cout << root->data << " ";
        
        inorder(root->right);
    }
    
    
    void preorder(Node* root){
        if(root == NULL)
            return;
       
        cout << root->data << " ";

        preorder(root->left);

        preorder(root->right);
    }
    void postorder(Node* root){
        if(root == NULL)
            return;
       

        postorder(root->left);

        postorder(root->right);
        
        cout << root->data << " ";
    }
    
    
    void inOrder(Node *root) 
    { 
        stack<Node *> s; 
        Node *curr = root; 
  
        while (curr != NULL || s.empty() == false) 
        { 
            
            while (curr !=  NULL) 
            { 
               
                s.push(curr); 
                curr = curr->left; 
            } 
  
            curr = s.top(); 
            s.pop(); 
  
            cout << curr->data << " "; 
  
        
            curr = curr->right; 
        }
    }
    
    
    void preOrder(Node* root)
    {
        if (root == NULL)
            return;
 
        stack<Node *> s;
        s.push(root);
 
        while (s.empty() == false) {
         
            Node* node = s.top();
            cout<<node->data<<" ";
            s.pop();
 
            if (node->right)
                s.push(node->right);
            if (node->left)
                s.push(node->left);
        }
    }
    
    void postOrder(Node *root)  
    {  
        if (root == NULL) return;  
  
        
        stack<Node *> s1;
        
        stack<Node *> s2;
  
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
			  int nodeCount = q.size();
            while (nodeCount > 0) 
            {  
                
                Node *node = q.front();  
                cout<<node->data<<" ";  
                q.pop(); 
				 
                if (node->left != NULL)  
                    q.push(node->left);  
                if (node->right != NULL)  
                    q.push(node->right);
					  
                nodeCount--;  
            }  
        }
		}  
    }
};

int main()
{
    Node Tree(0);
   
    Node* root = NULL;
    int choice;
    char ch='Y';
   
    while(ch=='Y'||ch=='y')
    {
        cout<<endl<<"\t You Can Perform Following Operations on Binary Search Tree :-"<<endl;
        cout<<endl<<"\t\t 1. Create"<<endl<<"\t\t 2. Insert"<<endl<<"\t\t 3. Delete"<<endl<<"\t\t 4. Search"<<endl<<"\t\t 5. Display"<<endl<<"\t\t 6. Breadth First Search / LOP"<<endl<<"\t\t 7. Quit"<<endl;
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
                cout<<endl<<"\t ................BST Constructed............"<<endl;
                break;
            case 2: 
                t=0;
                cout<<endl<<"\t Enter data to insert in BST :- ";
                cin>>t;
                root = Tree.insert(root,t);
                cout<<endl<<"\t\t ................Elements Inserted............";
                break;
            case 3: 
                int delete_data;
                cout<<endl<<"\t Enter the node tobe Deleted :-";
                cin>>delete_data;
                //Node* d(0);
                Tree.deletenode(root,delete_data);
                cout<<endl<<"\t\t Inorder Traversal is of Tree is as :- ";
                Tree.inorder(root);
                break;
            case 4: 
             
                if(root!=NULL){
                    cout<<endl<<"\t\t Enter the data to Search in BST :";
                    int data;
                    cin>>data;
                    
                    if(Tree.search(root,data)!=NULL)
                        cout<<endl<<"\t\t ......."<<data<<" is found in BST..............";
                    else
                        cout<<endl<<"\t\t ......."<<data<<" is not found in BST..............";
                }
                else
                    cout<<endl<<"\t ...............BST is Empty................";
                break;
            case 5:
                if(root!=NULL)
                {
                    cout<<endl<<"\t Tree Traversals are as follws :- ";
                    
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
                    cout<<endl<<endl<<"\t\t Non-recursive Postorder Traversal of Tree is :- ";
                    Tree.postOrder(root);
                }
                else
                    cout<<endl<<"\t ...............BST is Empty................";
                break;
            case 6: 
                if(root!=NULL)
                {
                    cout<<endl<<"\t Breadth First Search Traversal (LOP) :- ";
                    Tree.printLevelOrder(root);  
                }
                else
                    cout<<endl<<"\t ...............BST is Empty................";
                break;
            case 7: exit(0);
            default : 
                cout<<endl<<"\t\t ...............Invalid Choice.....Re-enter your choice";
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
