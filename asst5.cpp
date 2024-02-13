#include<iostream>
using namespace std;

struct tree
{
   int data;
   struct tree* left;
   struct tree* right;
};

struct tree *newNode(char v)
{
    tree* temp = new tree();
    temp->data = v;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inorder(struct tree *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        cout<< root->data <<" "; 
        inorder(root->right); 
    } 
} 

struct tree* insert(struct tree* node, int key)
{
    if (node == NULL) return newNode(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
   return node;
}

struct tree* search(struct tree* root, int key)
{
    if (root == NULL || root->data == key) 
        return root; 
     
    // Key is greater than root's key 
    if (root->data < key) 
       return search(root->right, key); 
    else
        return search(root->left, key); 
}

struct tree * minValueNode(struct tree* node)
{
    struct tree* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct tree* deleteNode(struct tree* root, int key)
{
    if (root == NULL) 
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
   else
    {
        
        if (root->left == NULL)
        {
            struct tree *temp = root->right;
            free(root);
            return temp;
        }
        
        else if (root->right == NULL)
        {
            struct tree *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            struct tree* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
   return root;
}

void mirror(struct tree* node)  
{ 
    if (node == NULL)  
        return;  
    else
    { 
        struct tree* temp; 
        mirror(node->left); 
        mirror(node->right);

        temp= node->left; 
        node->left = node->right; 
        node->right = temp; 
    } 
}  

struct tree* copy(struct tree *root)
{
    tree *root2;
    if(root==NULL)
        return NULL;
    root2=new tree;
    root2->left=copy(root->left);
    root2->right=copy(root->right);
    root2->data=root->data;

    return root2;
}

int Maxdepth(struct tree *root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        int depth1=Maxdepth(root->left); 
        int depth2=Maxdepth(root->right); 
        if(depth1>depth2)
            return (depth1+1);
        else
            return (depth2+1);

    }
}

int main()
{
    struct tree *root = NULL;
    struct tree *root2=NULL;
    struct tree *root1=NULL;
    struct tree *root3=NULL;
    int ch,n,d,depth;
    while(1)
    {
        cout<<"\n****************MENU*************************";
        cout<<endl<<"\t\t1.INSERT";
        cout<<endl<<"\t\t2.DELETE";
        cout<<endl<<"\t\t3.SEARCH";
        cout<<endl<<"\t\t4.TRAVERSAL";
        cout<<endl<<"\t\t5.DEPTH OF BST";
        cout<<endl<<"\t\t6.COPY OF BST";
        cout<<endl<<"\t\t7.MIRROR IMAGE";
        cout<<endl<<"\t\t8.EXIT";
        cout<<"\n********************************************";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"\nEnter number of values to insert: ";
                cin>>n;
                cout<<"\nEnter the values to create BST: ";
                for(int i=0; i<n; i++)
                {
                    cin>>d;
                    root = insert(root, d);
                }
                break;

            case 2:
                cout<<"\nEnter the element to delete: ";
                cin>>d;
                root3=deleteNode(root, d);
                break;

            case 3:
                cout<<"\nEnter the element to search: ";
                cin>>d;
                root1=search(root, d);
                if(root1!=NULL)
                    cout<<"\nFound in BST!!";
                else
                    cout<<"\nNot Found in BST!!";
                break;

            case 4:
                cout<<"\nTraversal of BST: ";
                inorder(root);
                break;

            case 5:
                depth=Maxdepth(root);
                cout<<"The depth of BST is: "<<depth;
                break;

            case 6:
                root2=copy(root);
                cout<<"The copy of BST is: ";
                inorder(root2);
                break;

            case 7:
                mirror(root);  
                cout <<"\nInorder traversal of the mirror BST is: ";  
                inorder(root); 
                mirror(root);
                break;

            case 8:
                return 0;

            default: 
                cout<<"\nWrong Option";
        }
    } 
    return 0;
}