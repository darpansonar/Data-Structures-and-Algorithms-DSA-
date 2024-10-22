#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
	int height;
};

struct node *root=NULL;

//Height of a node
int height(node *root)
{
	if(root==NULL)
		return 0;
		
	return root->height;
}

//Balance factor
int balanceFactor(node *root)
{
	if(root==NULL)
		return 0;
	
	return (height(root->left) - height(root->right));
}

// Right rotation 
struct node *rightRotate(node *z) 
{
    node *y = z->left;
    node *T3 = y->right;

    // Perform rotation
    y->right = z;
    z->left = T3;

    // Update heights
    z->height = max(height(z->left), height(z->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return z;
}

// Left rotation
struct node *leftRotate(node *z) 
{
    node *y = z->right;
    node *T2 = y->left;

    // Perform rotation
    y->left = z;
    z->right = T2;

    // Update heights
    z->height = max(height(z->left), height(z->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

//Left - Right Rotation
struct node *leftRightRotate(node *z)
{
	z->left=leftRotate(z->left);
	return rightRotate(z);
}

//Right - Left Rotation
struct node *rightLeftRotate(node *z)
{
	z->right=rightRotate(z->right);
	return leftRotate(z);
}

// Insert a key into the AVL tree and balance it
struct node *insert(node* root, int value) 
{
    // Perform normal BST insertion
    if (root == NULL)
    {
    	node *ptr=new node;
		ptr->data=value;
		
		ptr->left=ptr->right=NULL;
		return ptr;
	}

    else if(value<root->data)
	{
		root->left=insert(root->left,value);
		cout<<value<<" inserted on left  ";
	}
	
	else if(value>root->data)
	{
		root->right=insert(root->right,value);
		cout<<value<<" inserted on right  ";
	}
	
	else
		return root;

    root->height = 1 + max(height(root->left), height(root->right)); // Update the height

    int balance = balanceFactor(root);

    // If the node becomes unbalanced, there are 4 cases

    // Case 1 - Left Left
    if (balance > 1 && value < root->left->data)
        return rightRotate(root);

    // Case 2 - Right Right
    if (balance < -1 && value > root->right->data)
        return leftRotate(root);

    // Case 3 - Left Right
    if (balance > 1 && value > root->left->data) 
        return leftRightRotate(root);

    // Case 4 - Right Left
    if (balance < -1 && value < root->right->data) 
        return rightLeftRotate(root);

    // Return the unchanged node pointer
    return root;
}

// Utility function to find the node with the minimum key value
int minValue(node *root)
{
	if(root==NULL)
		return -1;
		
	else if(root->left==NULL)
		return root->data;
	
	return minValue(root->left);
}

// Function to delete a node from the AVL tree and balance it
struct node *deleteNode(node* root, int value) 
{
    // Perform standard BST delete
    if(root==NULL)
		return NULL;
	
	if(value<root->data) 
		root->left=deleteNode(root->left,value);
	
	else if(value>root->data)
		root->right=deleteNode(root->right,value);
		
	else
	{
		//Node with no child
		if((root->left==NULL)&&(root->right==NULL))
		{
			delete root;
			return NULL;
		}
		
		//Node with 1 child
		else if(root->left==NULL)
		{
			node *temp=root->right;
			delete root;
			return temp;
		}
		
		else if(root->right==NULL)
		{
			node *temp=root->left;
			delete root;
			return temp;
		}
		
		//Node with 2 children
		else
		{
			int succVal=minValue(root->right);
			root->data=succVal; //copy sucessor's value to root
			root->right=deleteNode(root->right,succVal); //Delete successor
		}
	}

    if (root == NULL) // If the tree had only one node then return
        return root;

    root->height = 1 + max(height(root->left), height(root->right)); // Update the height

    int balance = balanceFactor(root);

    // If the node becomes unbalanced, then balance it

    // Case 1 - Left Left
    if (balance > 1 && balanceFactor(root->left) >= 0)
        return rightRotate(root);

    // Case 2 - Left Right
    if (balance > 1 && balanceFactor(root->left) < 0) 
        return leftRightRotate(root);

    // Case 3 - Right Right
    if (balance < -1 && balanceFactor(root->right) <= 0)
        return leftRotate(root);

    // Case 4 - Right Left
    if (balance < -1 && balanceFactor(root->right) > 0) 
        return rightLeftRotate(root);

    return root;
}

//AVL Tree : Traversal
void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

void preorder(struct node *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
}

//AVL : Search
struct node *search(node *root,int value)
{
	if(root==NULL)
		return NULL;
		
	if(value==root->data)
		return root;
		
	if(value<root->data)
		return search(root->left,value);
		
	return search(root->right,value);
}

int main()
{
	int c=0,n,value;
	node *target;
	node *result;
	
	cout<<endl<<"Enter root node value : ";
	cin>>value;
	cout<<"Root = "<<value;
	// Insert root element
	root = insert(root, value);
	
	cout<<"\n\nMenu : ";
	cout<<"\n1.Insert\n2.Delete\n3.Inorder Traversal\n4.Preorder traversal";
	cout<<"\n5.Postorder Traversal\n6.Search\n7.Exit";
	
	while(c!=7)
	{
		cout<<"\n\nEnter : ";
		cin>>c;
		
		switch(c)
		{
			case 1:
				cout<<"Enter node value that is to be inserted : ";
				cin>>n;
				root=insert(root,n);
				break;
			
			case 2:
				cout<<"Enter node value that is to be deleted : ";
				cin>>n;
				
				target=search(root, n);
                if(target) 
				{
                    root=deleteNode(root, n);
                    cout<<"n"<<" deleted successfully";
                } 
                
				else 
				{
                    cout<<"Node value "<<n<<" not found";
                }
				break;
				
			case 3:
				cout<<"Inorder Traversal : ";
				inorder(root);
				break;
				
			case 4:
				cout<<"Preorder Traversal : ";
				preorder(root);
				break;
				
			case 5:
				cout<<"Postorder Traversal : ";
				postorder(root);
				break;
				
			case 6:
				cout<<"Enter node value that is to be searched : ";
				cin>>n;
				result=search(root,n);
				
                if(result) 
				{
                    cout<<"Node value "<<n<<" found "<<result->data;
                } 
				else 
				{
                    cout<<"Node value "<<n<<" not found";
                }
				break;
			
			case 7:
				exit(0);
				
			default:
				cout << "Invalid choice!\n";
				break;
		}
	}
	
	return 0;
}

