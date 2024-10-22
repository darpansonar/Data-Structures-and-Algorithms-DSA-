#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root=NULL;

//BST : Insert
struct node *insert(struct node *root,int value)
{
	if(root==NULL)
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
	return root;
}

//BST : Search
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

//BST : Tree traversal
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

//BST : Min & Max
int maxValue(node *root)
{
	if(root==NULL)
		return -1;
		
	else if(root->right==NULL)
		return root->data;
	
	return maxValue(root->right);
}

int minValue(node *root)
{
	if(root==NULL)
		return -1;
		
	else if(root->left==NULL)
		return root->data;
	
	return minValue(root->left);
}

//Successor and predecessor of root node
struct node *findPredecessor(node *root, node *target) // Function to find the inorder predecessor
{
    node *predecessor = NULL;
    while (root) 
	{
        if (target->data > root->data) 
		{
            predecessor = root;  // Potential predecessor
            root = root->right;
        } 
		else 
		{
            root = root->left;
        }
    }
    return predecessor;
}

struct node *findSuccessor(node *root, node *target) // Function to find the inorder successor
{
    node *successor = NULL;
    while (root) 
	{
        if (target->data < root->data) 
		{
            successor = root;  
            root = root->left;
        } 
		else 
		{
            root = root->right;
        }
    }
    return successor;
}

//BST : Delete
struct node *deleteNode(node *root,int value)
{
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
	return root;
}

int main()
{
	int c=0,n,value;
	node *result;
	node *target;
	
	cout<<endl<<"Enter root node value : ";
	cin>>value;
	cout<<"Root = "<<value;
	// Insert root element
	root = insert(root, value);
	
	cout<<"\n\nMenu : ";
	cout<<"\n1.Insert\n2.Inorder Traversal\n3.Preorder traversal\n4.Postorder Traversal";
	cout<<"\n5.Search\n6.Min value\n7.Max value\n8.Inorder Sucessor";
	cout<<"\n9.Inorder Predecessor\n10.Delete\n11.Exit";
	
	while(c!=11)
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
				cout<<"Inorder Traversal : ";
				inorder(root);
				break;
				
			case 3:
				cout<<"Preorder Traversal : ";
				preorder(root);
				break;
				
			case 4:
				cout<<"Postorder Traversal : ";
				postorder(root);
				break;
				
			case 5:
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
				
			case 6:
				cout<<"Minimum value of node in BST : "<<minValue(root);
				break;
				
			case 7:
				cout<<"Maximum value of node in BST : "<<maxValue(root);
				break;
				
			case 8:
				
				cout<<"Enter node value to find it's successor : ";
				cin>>n;
    			
    			target=search(root,n);
                if(target) 
				{
                    node *successor=findSuccessor(root,target);
                    if(successor) 
					{
                        cout<<"Inorder Successor of "<<target->data<<" is: "<<successor->data;
                    } 
					else
					{
                        cout<<"Inorder Successor does not exist";
                    }
                } 
				else 
				{
                    cout<<"Node value "<<n<<" not found";
                }
				break;
				
			case 9:
				cout<<"Enter node value to find it's predecessor : ";
				cin>>n;
			
    			target=search(root,n);
                if(target) 
				{
                    node *predecessor=findPredecessor(root,target);
                    if (predecessor) 
					{
                        cout<<"Inorder Predecessor of "<<target->data<<" is: "<<predecessor->data;
                    } 
					else 
					{
                        cout<<"Inorder Predecessor does not exist";
                    }
                } 
				else 
				{
                    cout<<"Node not found.";
                }
				break;
				
			case 10:
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
				
			case 11:
				exit(0);
				
			default:
				cout << "Invalid choice!\n";
				break;
		}
	}
	
	return 0;
}
