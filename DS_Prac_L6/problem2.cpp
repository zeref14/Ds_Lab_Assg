#include <iostream>
#include <cstdlib>
using namespace std;

int x=0;
struct node
{
    int n;
    int degree;
    node* parent;
    node* child;
    node* sibling;
};

class BinomialHeap
{
    private:
        node *H;
        node *Hr;
        int count;
    public:
        node* Initializeheap();
        int Binomial_link(node*, node*);
        node* Create_node(int);
        node* Union(node*, node*);
        node* Insert(node*, node*);
        node* Merge(node*, node*);
        node* Extract_Min(node*);
        int Revert_list(node*);
        int Display(node*,node *);
        node* Search(node*, int);
        int Decrease_key(node*, int, int);
        int Delete(node*, int);
        BinomialHeap()
        {
            H = Initializeheap();
            Hr = Initializeheap();
            int count = 1;
        }
};
 

node* BinomialHeap::Initializeheap()
{
    node* np;
    np = NULL;
    return np;
}

int BinomialHeap::Binomial_link(node* y, node* z)
{
    y->parent = z;
    y->sibling = z->child;
    z->child = y;
    z->degree = z->degree + 1;
}

node* BinomialHeap::Create_node(int k)
{
    node* p = new node;
    p->n = k;
    return p;
}

node* BinomialHeap::Insert(node* H, node* x)
{
    node* H1 = Initializeheap();
    x->parent = NULL;
    x->child = NULL;
    x->sibling = NULL;
    x->degree = 0;
    H1 = x;
    H = Union(H, H1);
    return H;
}
 

node* BinomialHeap::Union(node* H1, node* H2)
{
    node *H = Initializeheap();
    H = Merge(H1, H2);
    if (H == NULL)
        return H;
    node* prev_x;
    node* next_x;
    node* x;
    prev_x = NULL;
    x = H;
    next_x = x->sibling;
    while (next_x != NULL)
    {
        if ((x->degree != next_x->degree) || ((next_x->sibling != NULL)
            && (next_x->sibling)->degree == x->degree))
        {
            prev_x = x;
            x = next_x;
        }
        else
	    {
            if (x->n <= next_x->n)
            {
                x->sibling = next_x->sibling;
                Binomial_link(next_x, x);
            }
            else
            {
                if (prev_x == NULL)
                    H = next_x;
                else
                    prev_x->sibling = next_x;
                Binomial_link(x, next_x);
                x = next_x;
            }
	    }
        next_x = x->sibling;
    }
    return H;
}

node* BinomialHeap::Merge(node* H1, node* H2)
{
    node* H = Initializeheap();
    node* y;
    node* z;
    node* a;
    node* b;
    y = H1;
    z = H2;
    if (y != NULL)
    {
        if (z != NULL)
        {
            if (y->degree <= z->degree)
                H = y;
            else if (y->degree > z->degree)
                H = z;
        }
        else
            H = y;
    }
    else
        H = z;
    while (y != NULL && z != NULL)
    {
        if (y->degree < z->degree)
        {
            y = y->sibling;
        }
        else if (y->degree == z->degree)
        {
            a = y->sibling;
            y->sibling = z;
            y = a;
        }
        else
        {
            b = z->sibling;
            z->sibling = y;
            z = b;
        }
    }
    return H;
}

int BinomialHeap::Display(node* H,node * H2)
{
    node* p;
    node *c;
    p = H2;
    c=H;
    
    if(c==NULL)
    {
        return 0;
    }
    else
    {
        if(c->sibling==p->sibling && p->sibling!=NULL)
        {
            cout<<c->degree<<":";
        }
        if(p->sibling==NULL && x==0)
        {
            cout<<p->degree<<":";
            x=1;
        }
        cout<<c->n<<" ";
        
        Display(c->child,p);
        

        if(c->sibling==p->sibling && p->sibling!=NULL)
        {
            cout<<endl;
            p=p->sibling;
        }
        Display(c->sibling,p);
        
        
    }
     
}

int main()
{
    int n, m, l, i;
    BinomialHeap bh;
    node* p;
    node *H;
    H = bh.Initializeheap();
    char ch;
    while (1)
    {
       
        cout<<"1)Insert Element in the heap"<<endl;
        cout<<"2)Display Heap"<<endl;
        cout<<"3)Exit"<<endl;
        cout<<"Enter Your Choice: ";
        cin>>l;
        switch(l)
        {
        case 1:
            cout<<"Enter the element to be inserted: ";
            cin>>m;
            p = bh.Create_node(m);
            H = bh.Insert(H, p);
            break;
       
        case 2:
            cout<<"The Heap is: "<<endl;
            bh.Display(H,H);
            cout<<endl;
            break;
        case 3:
            exit(1);
        default:
            cout<<"Wrong Choice";
	  }
    }
    return 0;
}