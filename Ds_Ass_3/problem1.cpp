/**
 * @file problem1.cpp
 * @author Ritesh Singh (you@domain.com)
 * @brief This program works on different types of BST Trees
 * @version 0.1
 * @date 2019-08-20
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

/**
 * @brief This is BST Tree datastructure
 * 
 */
struct bst_node
{
    int data;
    int height;
    struct bst_node *left;
    struct bst_node *right;

};

/**
 * @brief This is AVL Tree datastructure
 * 
 */
struct avl_node
{
    int data;
    struct avl_node *left;
    struct avl_node *right;
    int height;
};



enum Color {RED, BLACK}; 
/**
 * @brief This is RED BLACK Tree datastructures
 * 
 */
struct Node 
{ 
	int data; 
	bool color; 
	Node *left, *right, *parent; 

	
	Node(int data) 
	{ 
	this->data = data; 
	left = right = parent = NULL; 
	this->color = RED; 
	} 
}; 

/**
 * @brief This class contains different methods for RED BLACK Tree
 * 
 */
class RBTree 
{ 
private: 
	Node *root; 
protected: 
	void rotateLeft(Node *&, Node *&); 
	void rotateRight(Node *&, Node *&); 
	void fixViolation(Node *&, Node *&); 
public: 
	
	RBTree() { root = NULL; } 
	void insert(const int &n); 
	void inorder(); 
	void levelOrder();
    void print_rbtree();
    void printPath_rbtree(); 
}; 

/**
 * @brief This method print RED BLACK Tree in inorder
 * 
 * @param root The parameter is root of RED BLACK Tree
 */
void inorderHelper(Node *root) 
{ 
	if (root == NULL) 
		return; 

	inorderHelper(root->left); 
	cout << root->data << "\t"; 
	inorderHelper(root->right); 
} 




int max(int ,int );
void printArray(int arr[], int len) ;


void insert_data();
bst_node * bst_newnode(bst_node *,int );
bst_node * bst_node_insert(bst_node *,int);
int height_bst(bst_node *node);
void inorder(bst_node *);
void display();
void print_bst(bst_node *);
void printPaths_bst(bst_node* node);
void printPathsRecur_bst(bst_node* node, int path[], int pathLen);

void insert_avl();
int height(avl_node *);
avl_node * newNode(int );
avl_node *rightRotate(avl_node *);
avl_node *leftRotate(avl_node *);  
int getBalance(avl_node *);
avl_node* avl_node_insert(avl_node* , int );
void inorder_avl(struct avl_node *);
void isert_avl_inorder(struct bst_node *);
void insert_inorder(struct bst_node *);
void print_avl(avl_node *);
void printPathsRecur_avl(avl_node* node, int path[], int pathLen);  
void printPaths_avl(avl_node* node);



void print_rb(Node *node);
void printPathsRecur_rb(Node* node, int path[], int pathLen);  
void printPaths_rb(Node* node);
void RBTree::inorder()	 { inorderHelper(root);} 
void RBTree::print_rbtree()	 { print_rb(root);} 
void RBTree::printPath_rbtree()	 { printPaths_rb(root);}


/**
 * @brief This is an object of class RBTree
 * 
 */
RBTree tree;
int bst_length=0;
/**
 * @brief This is the root node of BST Tree
 * 
 */
bst_node *root;
/**
 * @brief This array stores inorder inputs for AVL Tree
 * 
 */
int arr_inorder[100];
/**
 * @brief Counter for arr_inorder array
 * 
 */
int ci=0;
/**
 * @brief This counts the space for level wise indentation in BST Tree
 * 
 */
int cspace=0;
/**
 * @brief This counts the space for level wise indentation in AVL Tree
 * 
 */
int cspace1=0;
/**
 * @brief This counts the space for level wise indentation in RED BLACK Tree
 * 
 */
int cspace2=0;
/**
 * @brief This is the root of AVL Tree
 * 
 */
avl_node *root_avl;


/**
 * @brief This method contains access to other methods
 * 
 * @return int Default return 0
 */
int main()
{
    while(1)
    {
        cout<<"1.To insert a node in the BST and in the red-black tree\n2. To create AVL tree from the inorder traversal of the BST\n3. To print the inorder traversal of the BST/AVL/red-black tree\n4. To display all the paths in the BST/AVL tree/red-black tree\n5. To print the BST/AVL tree/red-black Tree in the terminal using level-wise indentation\n6. Exit\n";
        cout<<endl;
        int ch;
        cin>>ch;
        cout<<endl;
        
        switch (ch)
        {
        case 1:
        insert_data();
        break;
        case 2:
        
        insert_inorder(root);
        insert_avl();
        break;
        case 3:
        cout<<"The inorder traversal of BST tree is:"<<endl;
        inorder(root);
        cout<<endl;
        cout<<"The inorder traversal of AVL tree is:"<<endl;
        inorder_avl(root_avl);
        cout<<endl;
        cout<<"The inorder traversal of Red Black tree is:"<<endl;
        tree.inorder();
        cout<<"\n\n"; 
        break;
        case 4:
        cout<<"The complete path of BST Tree:"<<endl;
        printPaths_bst(root);
        cout<<"The complete path of AVL Tree"<<endl;
        printPaths_avl(root_avl);
        cout<<"The complete path of RED BLACK Tree:"<<endl;
        tree.printPath_rbtree();
        break;
        case 5:
        cout<<"The level-wise indentation of BST Tree:"<<endl;
        print_bst(root);
        cout<<"The level-wise indentation of AVL Tree:"<<endl;
        print_avl(root_avl);
        cout<<"The level-wise indentation of RED BLACK Tree:"<<endl;
        tree.print_rbtree();
        cspace=0;
        cspace1=0;
        cspace2=0;
        cout<<endl;
        break;
        case 6:
        exit(0);
        break;
       default:
            break;
        }



    }
    return 0;
}
/**
 * @brief This method returns max of two integers
 * 
 * @param a This is the first integer
 * @param b This is the second integer
 * @return int This is the max value
 */
int max(int a, int b)  
{  
    return (a > b)? a : b;  
} 

/**
 * @brief This function prarr path of Tree which are stored in array
 * 
 * @param arr This array stores value of nodes of tree at particular path
 * @param len This is the length of the path
 */
void printArray(int arr[], int len)  
{  
    int i;  
    
    for (i = 0; i < len; i++)  
    {
        for(int j=i;j<len;j++)  
        {
        cout << arr[j] ;
        if(j!=len-1)
        {
            cout<<"->";
        }

        }  

        cout<<endl;
    }  
    cout<<endl;  
}

/**
 * @brief This method insert data in BST Tree and RED BLACK Tree from input
 * 
 */
void insert_data()
{
    int data;
    cin>>data;
    root=bst_node_insert(root,data);
    tree.insert(data);
}


/**
 * @brief This node create array whic contain inorder of BST Tree
 * 
 * @param node The root of BST Tree
 */
void insert_inorder(struct bst_node *node)
    {
        if(node)
        {
            insert_inorder(node->left);    
            arr_inorder[ci]=node->data;
            ci++;
            insert_inorder(node->right);     
        }
    }


/**
 * @brief This method return level of node of BST Tree
 * 
 * @param node The node of which we want the height
 * @return int It returns the height
 */
    int height_bst(bst_node *node)  
    {  
    if (node == NULL)  
        return 0;  
    return node->height;  
    } 


/**
 * @brief This method add data to new node in BST Tree
 * 
 * @param node The new node to be insertd
 * @param data The value to be inserted in new node
 * @return bst_node* The new node is returned
 */
bst_node * bst_newnode(struct bst_node *node,int data)
{
    node=(bst_node *)malloc(sizeof(bst_node));
    bst_node *n1,*n2;
    node->data=data;
    node->height=1;
    bst_length++;
    return node;
}

bst_node * bst_node_insert(struct bst_node *node,int data)
{
    
   
    if(node==NULL)
    {
         return bst_newnode(node,data);
    }

    else
    {
        if(data<=node->data)
        {
        node->left=bst_node_insert(node->left,data);
        node->height = 1 + max(height_bst(node->left),  
                        height_bst(node->right));
        }
        else
        {
        node->right=bst_node_insert(node->right,data);
        node->height = 1 + max(height_bst(node->left),  
                        height_bst(node->right));
        }
        return node;
    }
    
    
}
/**
 * @brief This method prints inorder of BST Tree
 * 
 * @param node The root of BST Tree
 */
void inorder(struct bst_node *node)
    {
        if(node)
        {
            inorder(node->left);    
            
            cout<<node->data<<"\t";
              
            inorder(node->right);     
        }

        
    }


/**
 * @brief This method sends root node and array to store path for BST Tree
 * 
 * @param node It is root node
 */
  void printPaths_bst(bst_node* node)  
{  
    int path[1000];  
    printPathsRecur_bst(node, path, 0);  
}

/**
 * @brief This method recursively sends path to be printed for BST Tree
 * 
 * @param node The required node
 * @param path The array in which path is stored
 * @param pathLen The length of the path
 */
void printPathsRecur_bst(bst_node* node, int path[], int pathLen)  
{  
    if (node == NULL)  
        return;  
        
      
 
    path[pathLen] = node->data;  
    pathLen++;  
      
   
    if (node->left == NULL && node->right == NULL)  
    {  
        printArray(path, pathLen);  
    }  
    else
    {  
     
        printPathsRecur_bst(node->left, path, pathLen);  
        printPathsRecur_bst(node->right, path, pathLen);  
    }  
} 



    
/**
 * @brief This function print the BST Tree with indentation
 * 
 * @param node The root of BST Tree
 */
    void print_bst(bst_node *node)
    {
        if(cspace!=0)
        {
            for(int i=0;i<cspace;i++)
            cout<<"\t";
        }

        cout<<node->data<<"["<<node->height-1<<"]"<<endl;
        if(node->left)
        {
            cspace++;
            print_bst(node->left);
        }

        if(node->right)
        {
            cspace++;
            print_bst(node->right);
        }
        else
        {
            cspace--;
        }
    }


  
  /**
   * @brief This function add data to AVL Tree through inorder traversal
   * 
   */
  
  
  void insert_avl()
{
   for(int i=0;i<ci;i++)
   root_avl=avl_node_insert(root_avl,arr_inorder[i]);

}
   /**
    * @brief This function returns height of a particular node of AVL Tree
    * 
    * @param node Required Node
    * @return int Height of Node
    */
    int height(avl_node *node)  
{  
    if (node == NULL)  
        return 0;  
    return node->height;  
} 


/**
 * @brief This method print inorder for AVL Tree
 * 
 * @param node The root node of AVL Tree
 */
void inorder_avl(struct avl_node *node)
    {
        if(node)
        {
            inorder_avl(node->left);    
            
            cout<<node->data<<"\t";
              
            inorder_avl(node->right);     
        }

       
    }

/**
 * @brief This method add data to new node of AVL Tree
 * 
 * @param data Data to be stored in Tree
 * @return avl_node* Returns the new node
 */
avl_node * newNode(int data)  
{  
    avl_node * node=(avl_node *)malloc(sizeof(avl_node)); 
    node->data = data;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1;  
    return(node);  
}
/**
 * @brief This function perform RR rotation
 * 
 * @param y The node to be rotated
 * @return avl_node* Returns a node
 */
avl_node *rightRotate(avl_node *y)  
{  
    avl_node *x = y->left;  
    avl_node *T2 = x->right;  
  
    
    x->right = y;  
    y->left = T2;  
  
     
    y->height = max(height(y->left), 
                    height(y->right)) + 1;  
    x->height = max(height(x->left), 
                    height(x->right)) + 1;  
  
      
    return x;  
}

/**
 * @brief This function perform LL Rotation
 * 
 * @param x The node passed
 * @return avl_node* Returns a node
 */
avl_node *leftRotate(avl_node *x)  
{  
    avl_node *y = x->right;  
    avl_node *T2 = y->left;  
   
    y->left = x;  
    x->right = T2;  
  
    
    x->height = max(height(x->left),     
                    height(x->right)) + 1;  
    y->height = max(height(y->left),  
                    height(y->right)) + 1;  
  
    return y;  
}

/**
 * @brief Get the Balance object 
 * 
 * @param node The node to be balanced
 * @return int Return new balance factor
 */
int getBalance(avl_node *node)  
{  
    if (node == NULL)  
        return 0;  
    return height(node->left) - height(node->right);  
}
/**
 * @brief This function insert data in new node
 * 
 * @param node the node to be inserted
 * @param data data to be inserted
 * @return avl_node* Return a node
 */
avl_node* avl_node_insert(avl_node* node, int data)  
{  
   
    if (node == NULL)  
        return(newNode(data));  
  
    if (data < node->data)  
        node->left = avl_node_insert(node->left, data);  
    else if (data > node->data)  
        node->right = avl_node_insert(node->right, data);  
    else  
        return node;  
  
    
    node->height = 1 + max(height(node->left),  
                        height(node->right));  
  
    
    int balance = getBalance(node);  
  
    
    if (balance > 1 && data < node->left->data)  
        return rightRotate(node);  
  
   
    if (balance < -1 && data > node->right->data)  
        return leftRotate(node);  
  
    if (balance > 1 && data > node->left->data)  
    {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
   
    if (balance < -1 && data < node->right->data)  
    {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
  
    return node;  
}



/**
 * @brief This function print indentation of AVL Tree
 * 
 * @param node The root of AVL Tree
 */

      void print_avl(avl_node *node)
    {
        if(cspace1!=0)
        {
            for(int i=0;i<cspace1;i++)
            cout<<"\t";
        }
        int lev;

        if(node->left==NULL && node->right !=NULL)
        {
            lev= node->right->height;
            
        }
        else if(node->left!=NULL && node->right ==NULL)
        {
            lev=node->left->height;
        }
        else if(node->left==NULL && node->right ==NULL)
        {
            lev=0;
        }
        else
        {
            lev=node->left->height - node->right->height;
        }
        cout<<node->data<<"["<<lev<<"]"<<endl;
        if(node->left)
        {
            cspace1++;
            print_avl(node->left);
        }

        if(node->right)
        {
            cspace1++;
            print_avl(node->right);
        }
        
        cspace1--;
    
    }


/**
 * @brief This method sends root node and array to store path for AVL Tree
 * 
 * @param node It is root node
 */
    void printPaths_avl(avl_node* node)  
{  
    int path[1000];  
    printPathsRecur_avl(node, path, 0);  
}


/**
 * @brief This method recursively sends path to be printed for AVL Tree
 * 
 * @param node The required node
 * @param path The array in which path is stored
 * @param pathLen The length of the path
 */
void printPathsRecur_avl(avl_node* node, int path[], int pathLen)  
{  
    if (node == NULL)  
        return;  
        
    path[pathLen] = node->data;  
    pathLen++;  
      
  
    if (node->left == NULL && node->right == NULL)  
    {  
        printArray(path, pathLen);  
    }  
    else
    {  
        
        printPathsRecur_avl(node->left, path, pathLen);  
        printPathsRecur_avl(node->right, path, pathLen);  
    }  
}  


/**
 * @brief This function is use to BST Insert
 * 
 * @param root The root node
 * @param pt A node
 * @return Node* Returns a node
 */
Node* BSTInsert(Node* root, Node *pt) 
{ 
	
	if (root == NULL) 
	return pt; 

	
	if (pt->data < root->data) 
	{ 
		root->left = BSTInsert(root->left, pt); 
		root->left->parent = root; 
	} 
	else if (pt->data > root->data) 
	{ 
		root->right = BSTInsert(root->right, pt); 
		root->right->parent = root; 
	} 

	
	return root; 
} 

/**
 * @brief This function rotates left
 * 
 * @param root the root node
 * @param pt node to be rotated
 */

void RBTree::rotateLeft(Node *&root, Node *&pt) 
{ 
	Node *pt_right = pt->right; 

	pt->right = pt_right->left; 

	if (pt->right != NULL) 
		pt->right->parent = pt; 

	pt_right->parent = pt->parent; 

	if (pt->parent == NULL) 
		root = pt_right; 

	else if (pt == pt->parent->left) 
		pt->parent->left = pt_right; 

	else
		pt->parent->right = pt_right; 

	pt_right->left = pt; 
	pt->parent = pt_right; 
} 

/**
 * @brief This function rotates Right
 * 
 * @param root The root Node
 * @param pt the node to be rotated
 */
void RBTree::rotateRight(Node *&root, Node *&pt) 
{ 
	Node *pt_left = pt->left; 

	pt->left = pt_left->right; 

	if (pt->left != NULL) 
		pt->left->parent = pt; 

	pt_left->parent = pt->parent; 

	if (pt->parent == NULL) 
		root = pt_left; 

	else if (pt == pt->parent->left) 
		pt->parent->left = pt_left; 

	else
		pt->parent->right = pt_left; 

	pt_left->right = pt; 
	pt->parent = pt_left; 
} 


/**
 * @brief This function maintain the rule of RED BLACK Tree
 * 
 * @param root The root node
 * @param pt The node to fix violation
 */

void RBTree::fixViolation(Node *&root, Node *&pt) 
{ 
	Node *parent_pt = NULL; 
	Node *grand_parent_pt = NULL; 

	while ((pt != root) && (pt->color != BLACK) && 
		(pt->parent->color == RED)) 
	{ 

		parent_pt = pt->parent; 
		grand_parent_pt = pt->parent->parent; 

		
		if (parent_pt == grand_parent_pt->left) 
		{ 

			Node *uncle_pt = grand_parent_pt->right; 

			
			if (uncle_pt != NULL && uncle_pt->color == RED) 
			{ 
				grand_parent_pt->color = RED; 
				parent_pt->color = BLACK; 
				uncle_pt->color = BLACK; 
				pt = grand_parent_pt; 
			} 

			else
			{ 
				
				if (pt == parent_pt->right) 
				{ 
					rotateLeft(root, parent_pt); 
					pt = parent_pt; 
					parent_pt = pt->parent; 
				} 

				rotateRight(root, grand_parent_pt); 
				swap(parent_pt->color, grand_parent_pt->color); 
				pt = parent_pt; 
			} 
		} 

		else
		{ 
			Node *uncle_pt = grand_parent_pt->left; 

		
			if ((uncle_pt != NULL) && (uncle_pt->color == RED)) 
			{ 
				grand_parent_pt->color = RED; 
				parent_pt->color = BLACK; 
				uncle_pt->color = BLACK; 
				pt = grand_parent_pt; 
			} 
			else
			{ 
				
				if (pt == parent_pt->left) 
				{ 
					rotateRight(root, parent_pt); 
					pt = parent_pt; 
					parent_pt = pt->parent; 
				} 
                rotateLeft(root, grand_parent_pt); 
				swap(parent_pt->color, grand_parent_pt->color); 
				pt = parent_pt; 
			} 
		} 
	} 

	root->color = BLACK; 
} 


/**
 * @brief The function adds in RED BLACK Tree
 * 
 * @param data The data to be stored in Tree
 */
void RBTree::insert(const int &data) 
{ 
	Node *pt = new Node(data); 

	
	root = BSTInsert(root, pt); 

	
	fixViolation(root, pt); 
} 


/**
 * @brief This function print indentation of RED BLACK Tree
 * 
 * @param node The root node
 */
void print_rb(Node *node)
    {
        if(cspace2!=0)
        {
            for(int i=0;i<cspace2;i++)
            cout<<"\t";
        }

        if(node->color==RED)
        {
            cout<<node->data<<"[RED]"<<endl;
        }
        else if(node->color==BLACK)
        {
            cout<<node->data<<"[BLACK]"<<endl;
        }
        if(node->left)
        {
            cspace2++;
            print_rb(node->left);
        }

        if(node->right)
        {
            cspace2++;
            print_rb(node->right);
        }
        else
        {
            cspace2--;
        }
    }

/**
 * @brief This method sends root node and array to store path for RED BLACK Tree
 * 
 * @param node It is root node
 */
void printPaths_rb(Node* node)  
{  
    int path[1000];  
    printPathsRecur_rb(node, path, 0);  
}

/**
 * @brief This method recursively sends path to be printed for RED BLACK Tree
 * 
 * @param node The required node
 * @param path The array in which path is stored
 * @param pathLen The length of the path
 */
void printPathsRecur_rb(Node* node, int path[], int pathLen)  
{  
    if (node == NULL)  
        return;  
        
   
    path[pathLen] = node->data;  
    pathLen++;  
      
    
    if (node->left == NULL && node->right == NULL)  
    {  
        printArray(path, pathLen);  
    }  
    else
    {  
        printPathsRecur_rb(node->left, path, pathLen);  
        printPathsRecur_rb(node->right, path, pathLen);  
    }  
}  