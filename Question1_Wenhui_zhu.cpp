#include <iostream>
#include <cstdlib>
using namespace std;


class BinarySearchTree
{
private:
	class node
	{
 	public:
		node* left;
		node* right;
		node* parent;
		int key;
		string data;
	};

public:

	node* root;
	BinarySearchTree()
	{
	root = NULL;
	}
	bool isEmpty() const { return root == NULL; }
	void INORDER_TREE_WALK(node*);
	void TREE_INSERT(int );
	
	void preorder(node* x)
	{
		if (x != NULL)
		{
			cout << " " << x->key << " ";
			if (x->left)
			{
				preorder(x->left);
			}
			if (x->right)
			{
				preorder(x->right);
			}			
		}
	}

	void postorder(node* x)
	{
		if (x != NULL)
		{
			if (x->left)
			{
				 postorder(x->left);
			}
			if (x->right)
			{
				postorder(x->right);
			} 
			cout << " " << x->key << " ";
		}	
	}	

	int findMax(node* x)
	{	
		if(x==NULL)
		{
			cout << " ===================" << endl;
			cout<<" It is empty! "<<endl;
			cout << " ===================" << endl;
			return -999999;
		}
		while(x->right!=NULL)
		{
			x=x->right;
		}
		cout << " ===================" << endl;
		cout<<" The maximum is : "<< x->key;
		return x->key;
	}

	void removeMax(node* x)
	{
		int current=findMax(x);
		if(current == -999999){
			return;
		}
		deleteNode(current);
		cout << " ===================" << endl;
		cout<<" delete compelete. "<<endl;
		cout << " ===================" << endl;
		
	}

	void successor(int value)
	{
		node* x = root;
		while(x!=NULL)
		{	
			if(value<x->key)
			{
				x=x->left;
			}
			else if(value>x->key)
			{
				x = x->right;
			}
			else
			{		
				break;
			}
		}
		
		if(x==NULL)
		{
			cout << " ===================" << endl;
			cout<<" Not find the key"<<endl;
			cout << " ===================" << endl;
		}
		if(x->right!=NULL)
		{
			node* current = x->right;
			while(current->left!=NULL)
			{
				current=current->left;
			}
			cout << " ===================" << endl;
			cout<<" The successor is: "<<current->key<<endl;
			cout << " ===================" << endl;
		}

		else
		{	
			node *par = x->parent;
			node *current = x;
			while(par != NULL && current == par->right)
			{
				current = par;
				par = par->parent;
			}	
			if(par!=NULL)
			{
				cout << " ===================" << endl;
				cout<<" The successor is :"<<par->key<<endl;
				cout << " ===================" << endl;
			}	
			else
			{	
				cout << " ===================" << endl;
				cout<<" There is no successor!"<<endl;
				cout << " ===================" << endl;
			}
		}
	}

	void deleteNode(int value)
	{
		node * x = root;
		while(x!=NULL)
		{
			if(value<x->key)
			{
				x=x->left;
			}
			else if(value>x->key)
			{
				x = x->right;
			}
			else
			{
				break;
			}
		}
		if(x==NULL)
		{	
			cout << " ===================" << endl;
			cout<<" NOT FOUND"<<endl;
			cout << " ===================" << endl;
			return;
		}
		if(x->right!=NULL)
		{
			node*temp = x->right;
			while(temp->left!=NULL)
			{
				temp=temp->left;
			}
			x->key = temp->key;
			if(temp->parent == x)
			{
				x->right = temp->right;
				if(temp->right!=NULL)
				{
					temp->right->parent = temp->parent;
				}
			}
			else
			{
				temp->parent->left = temp->right;
				if(temp->right!=NULL)
				{
					temp->right->parent = temp->parent;
				}	
			}
			free(temp);
		}
		else if(x->left!=NULL)
		{
			node*temp = x->left;
			while(temp->right!=NULL)
			{
				temp=temp->right;
			}
			x->key = temp->key;
			if(temp->parent == x)
			{
				x->left = temp->left;
				if(temp->left!=NULL)
				{
					temp->left->parent = temp->parent;
				}
			}
			else
			{
				temp->parent->right = temp->left;
				if(temp->left!=NULL)
				{
				temp->left->parent = temp->parent;
				}
			}
			free(temp);
		}
		else
		{
			if(x==root)
			{
				root = NULL;
				return;
			}
			if(x->key>x->parent->key)
			{
				x->parent->right=NULL;
			}
			else
			{
				x->parent->left = NULL;
			}
		}
	}
};

void BinarySearchTree::TREE_INSERT(int d)
{
	// This implements the algorithm in page 261 of the textbook	
	node* z = new node();
	z->key = d;
	z->left = NULL;
	z->right = NULL;
	z->parent = NULL;
	
	node* y = NULL;
	node* x = root;
	
	while (x != NULL)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else if (z->key >x->key)
			x = x->right;
	}
	
	z->parent = y;
	if (y == NULL)
		root = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;
}

void BinarySearchTree::INORDER_TREE_WALK(node* x)
{
	if (x != NULL)
	{
		if (x->left) INORDER_TREE_WALK(x->left);
		cout << " " << x->key << " ";
		if (x->right) INORDER_TREE_WALK(x->right);
	}

}

int main()
{
	BinarySearchTree bst;
	int choice, key;
	while (true)
	{
		cout << endl << endl;
		cout << " Binary Search Tree Example " << endl;
		cout << " ----------------------------- " << endl;
		cout << " 1. Insert a Node " << endl;
		cout << " 2. Pre-Order Traversal " << endl;
		cout << " 3. Post-Order Traversal " << endl;
		cout << " 4. In-Order Traversal " << endl;
		cout << " 5. Find Max "<< endl;	
		cout << " 6. Remove Max "<< endl;
		cout << " 7. Successor " << endl;
		cout << " 8. Delete a node "<< endl;
		cout << " 9. Exit " << endl;
		cout << " Enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << " Enter key (int value) to be inserted : ";
			cin >> key;
			bst.TREE_INSERT(key);
			break;
		case 2: cout << endl;
			cout << " ===================" << endl;
			cout << " Pre-Order Traversal " << endl;
			bst.preorder(bst.root);
			break;
		case 3: cout << endl;
			cout << " ===================" << endl;
			cout << " Post-Order Traversal " << endl;
			bst.postorder(bst.root);
			break;
		case 4: cout << endl;
			cout << " -------------------" << endl;
			cout << " In-Order Traversal " << endl;
			bst.INORDER_TREE_WALK(bst.root);
			break;
		case 5:
			bst.findMax(bst.root);
			break;
		case 6:
			bst.removeMax(bst.root);
			break;
		case 7:
			cout<<"Enter the key to find the successor: ";
			cin>>key;
			bst.successor(key);
			break;
		case 8:
			cout<<"Enter the key to be deleted: ";
			cin>>key;
			bst.deleteNode(key);
			break;
		case 9: system("pause");
			return 0;
			break;
		default:
			cout << "Invalid choice!";
		}
	}
}
