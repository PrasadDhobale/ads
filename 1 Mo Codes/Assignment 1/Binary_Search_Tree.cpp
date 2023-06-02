#include <iostream>
using namespace std;
class node
{
public:
    node *left;
    int value;
    node *right;
};
node *root = NULL;
int insert_node(node *, node *);
int inorder(node *);
int preorder(node *);
int postorder(node *);
void level_trav(node *root);
void inorder_non_rec(node *root);
void preorder_non_rec(node *root);
void postorder_non_rec(node *root);
node *delete_node(node *root, int k);
node *search(node *root, int key);
int insert_node(node *c_root, node *new_node)
{
    if (c_root->value == new_node->value)
        return 3;
    else
    {
        if (new_node->value < c_root->value)

        {
            if (c_root->left != NULL)
                insert_node(c_root->left, new_node);
            else
            {
                c_root->left = new_node;
                (c_root->left)->left = NULL;
                (c_root->left)->right = NULL;
                return 1;
            }
        }
        else
        {
            if (c_root->right != NULL)
                insert_node(c_root->right, new_node);
            else
            {
                c_root->right = new_node;
                (c_root->right)->left = NULL;
                (c_root->right)->right = NULL;
                return 2;
            }
        }
    }
}
void level_trav(node *ptr)
{
    node *que[20];
    int front = 0, rear = 0;
    que[rear] = ptr;
    while (front <= rear)
    {
        ptr = que[front++];
        if (ptr != NULL)
        {
            cout << "" << ptr->value << "";

            que[++rear] = ptr->left;
            que[++rear] = ptr->right;
        }
    }
}
int inorder(node *c_root)
{
    if (c_root == NULL)
        return 0;
    else
    {
        if (c_root->left != NULL)
            inorder(c_root->left);
        cout << c_root->value << "";
        if (c_root->right != NULL)
            inorder(c_root->right);
    }
}
int preorder(node *c_root)
{
    if (c_root == NULL)
        return 0;
    else
    {
        cout << c_root->value << " ";
        if (c_root->left != NULL)
            preorder(c_root->left);
        if (c_root->right != NULL)
            preorder(c_root->right);
    }
}
int postorder(node *c_root)

{
    if (c_root == NULL)
        return 0;
    else
    {
        if (c_root->left != NULL)
            postorder(c_root->left);
        if (c_root->right != NULL)
            postorder(c_root->right);
        cout << c_root->value << "";
    }
}
class stack
{
    int top;
    node *stack_nodes[20];

public:
    stack()
    {
        top = -1;
    }
    void push(node *);
    node *pop();
    node *peek(stack stk);
    int empty()
    {
        if (top == -1)
            return (1);
        return (0);
    }
};
void stack::push(node *node)
{
    stack_nodes[++top] = node;
}
node *stack::pop()
{
    return (stack_nodes[top--]);
}
void inorder_non_rec(node *c_root)
{
    stack stk;
    node *temp;
    if (c_root != NULL)
    {
        temp = c_root;
        do
        {
            while (temp != NULL)
            {
                stk.push(temp);
                temp = temp->left;
            }
            if (!stk.empty())
            {
                temp = stk.pop();
                cout << temp->value << " ";
                temp = temp->right;
            }
            else
                break;
        } while (1);
    }
    else
        cout << "The tree is empty\n";
}
void preorder_non_rec(node *c_root)

{
    stack stk;
    node *temp = root;
    stk.push(temp);
    while (!stk.empty())
    {
        temp = stk.pop();
        if (temp != NULL)
        {
            cout << temp->value << " ";
            stk.push(temp->right);
            stk.push(temp->left);
        }
    }
}
void postorder_non_rec(node *c_root)
{
    stack stk;
    node *temp = root;
    stk.push(temp);
    while (!stk.empty())
    {
        temp = stk.pop();
        if (temp != NULL)
        {
            stk.push(temp->left);
            stk.push(temp->right);
            cout << temp->value << " ";
        }
    }
}
node *search(node *root, int key)
{
    if (root == NULL || root->value == key)
        return root;
    if (key > root->value)

        return search(root->right, key);
    return search(root->left, key);
}
node *delete_node(node *root, int k)
{
    if (root == NULL)
        return root;
    if (k < root->value)
    {
        root->left = delete_node(root->left, k);
        return root;
    }
    else if (k > root->value)
    {
        root->right = delete_node(root->right, k);
        return root;
    }
    if (root->left == NULL)
    {
        node *temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL)
    {
        node *temp = root->left;
        delete root;
        return temp;
    }
    else
    {

        node *Parent = root;
        node *succ = root->right;
        while (succ->left != NULL)
        {
            Parent = succ;
            succ = succ->left;
        }
        if (Parent != root)
            Parent->left = succ->right;
        else
            Parent->right = succ->right;
        root->value = succ->value;
        delete succ;
        return root;
    }
}
int main()
{
    int choice, v;
    while (1)
    {
        cout << "1.Insert Element\t2.Delete Element" << endl;
        cout << "3.Search Element\t4.Inorder Traversal" << endl;
        cout << "5.Preorder Traversal\t6.Postorder Traversal" << endl;
        cout << "7.Non-rec Inorder\t8.Non-rec Preorder:" << endl;
        cout << "9.Non-rec Postorder\t10.Display the tree" << endl;

        cout << "11.Quit" << endl;
        cout << "Enter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            node *temp;
            temp = new node;
            cout << "\nEnter node:";
            cin >> temp->value;
            if (root == NULL)
            {
                root = new node;
                root->value = temp->value;
                root->left = NULL;
                root->right = NULL;
                cout << "\nThe root node is added\n";
            }
            else
                v = insert_node(root, temp);
            if (v == 1)
                cout << "\nNode added to left\n";
            else if (v == 2)
                cout << "\nNode added to right\n";
            else if (v == 3)
                cout << "\nNode already exists\n";
            break;
        case 2:
            int delete_data;
            cout << endl
                 << "\tEnter the element to be deleted:";
            cin >> delete_data;
            delete_node(root, delete_data);
            cout << endl;
            break;

        case 3:
            int key;
            cout << endl
                 << "\tEnter element to be searched:";
            cin >> key;
            if (root != NULL)
            {
                if (search(root, key) != NULL)
                    cout << endl
                         << "\t" << key << "is found" << endl;
                else
                    cout << endl
                         << "\t" << key << "is not found" << endl;
            }
            else
                cout << endl
                     << "\tTree is Empty";
            break;
        case 4:
            cout << "\nInorder Traversal Sequence:\n";
            v = inorder(root);
            cout << endl;
            break;
        case 5:
            cout << "\nPreorder traversal Sequence:\n";
            v = preorder(root);
            cout << endl;
            break;
        case 6:
            cout << "\nPostorder traversal Sequence:\n";
            v = postorder(root);
            cout << endl;
            break;
        case 7:
            cout << "\nNonrecursive Inorder traversal sequence:\n";
            inorder_non_rec(root);
            cout << endl;
            break;
        case 8:
            cout << "\nNonrecursive Preorder traversal sequence:\n";
            preorder_non_rec(root);
            cout << endl;
            break;

        case 9:
            cout << "\nNonrecursive Postorder traversal sequence:\n";
            postorder_non_rec(root);
            cout << endl;
            break;
        case 10:
            cout << "\nLevelwise display of elements:\n";
            level_trav(root);
            cout << endl;
            break;
        case 11:
            exit(1);
        default:
            cout << "Wrong choice" << endl;
        }
    }
}
