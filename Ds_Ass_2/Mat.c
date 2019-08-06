/**
 * @file compareFiles.c
 * @author Ritesh Singh (you@domain.com)
 * @brief This program help to build quad tree
 * @version 0.1
 * @date 2019-08-07
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>




/**
 * @brief This srtucture contains quadtree variables
 * 
 */
struct node
{
    int **arr;
    struct node *topleft;
    struct node *topright;
    struct node *bottomleft;
    struct node *bottomright;
};
typedef struct node quad;

/**
 * @brief This structure contains dataype required to represent level and data
 * 
 */
struct node1
{
    int *height;
    int *data;
};
typedef struct node1 pos;
/**
 * @brief This variable helps to build Maximal Tree
 * 
 */
int count=0;//Use to build Maximal Tree

void create_tree(quad *,int );
int max_tree(int ,int **);
void read_file(int **,int);
void increase_array(int **,int **,int,int);
int check_same(int **,int );
int power(int);
/**
 * @brief This stores the original size of array
 * 
 */
int size=0;
/**
 * @brief This variable helps to find level of tree
 * 
 */
int co=0;//Use to find level
pos *level;

/**
 * @brief This function prints the maximal array and the other information
 * 
 * @return int This returns 0
 */
int main()
{
    int n;
    printf("Input the size of array in input file\n");
    scanf("%d",&n);
    printf("\n");
    int **a = (int **)malloc(n * sizeof(int *)); 
    for (int i=0; i<n; i++) 
         a[i] = (int *)malloc(n * sizeof(int));

        

        level=(pos *)malloc(sizeof(pos));
        level->height=(int *)malloc(100 *sizeof(int));
        level->data=(int *)malloc(100 *sizeof(int));
        

    int m=2;
   while(1)
   { 
    if(n<m)
    {
        break;
    }
    else
    {
        m=m*2;
    }
    
   }
    size=m;
  
         quad *b1=(quad *)malloc(sizeof(quad));
         b1->arr=(int **)malloc(m * sizeof(int *));
         for (int i=0; i<m; i++) 
         b1->arr[i]= (int *)malloc(m * sizeof(int));

         read_file(a,n);
         increase_array(a,b1->arr,n,m);

         b1->topleft=NULL;
         b1->topright=NULL;
         b1->bottomleft=NULL;
         b1->bottomright=NULL;

         int f=check_same(b1->arr,m);
         if(f==-1)
         {
             create_tree(b1,m);
         }

      
       int i1=max_tree(m,b1->arr);

        for(int i=0;i<m;i++)
   {
       for(int j=0;j<m;j++)
       {
           printf("%02d ",b1->arr[i][j]);
       }
       printf("\n");
       }

       printf("\n");
       for(int i=0;i<co;i++)
       printf("(%d,%d,%d)\n",i+1,level->data[i],level->height[i]);

  
return 0;
}

/**
 * @brief This function reads the input file
 * 
 * @param a This is the array which stores
 * @param n This is the size of array
 */
void read_file(int **a,int n)
{
    FILE *fp;
    fp=fopen("inputsample.txt","r");
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
        fscanf(fp,"%d",&a[i][j]);
        }
    }

 
}
/**
 * @brief This functions increases the size of array
 * 
 * @param a This array stores data in old size
 * @param b This array stores data in new size
 * @param n This is old size
 * @param m This is new size
 */
void increase_array(int **a,int **b,int n,int m)
{
   for(int i=0;i<m;i++)
   {
       for(int j=0;j<m;j++)
       {
           b[i][j]=0;
       }
   }
   for(int i=m-1;i>m-n-1;i--)
   {
       for(int j=m-1;j>m-n-1;j--)
       {
           b[i][j]=a[i-m+n][j-m+n];

       }
   }
   
   
}


/**
 * @brief Create a tree object This creatse the tree
 * 
 * @param a This is the structure required to make quadtree
 * @param m This is the new size of array
 */
void create_tree(quad *a,int m)
{
    
    int k=m/2;
    quad *n1=(quad *)malloc(sizeof(quad));
    n1->arr=(int **)malloc(k * sizeof(int *));
         for (int i=0; i<k; i++) 
         n1->arr[i]= (int *)malloc(k * sizeof(int));
    quad *n2=(quad *)malloc(sizeof(quad));
    n2->arr=(int **)malloc(k * sizeof(int *));
         for (int i=0; i<k; i++) 
         n2->arr[i]= (int *)malloc(k * sizeof(int));
    quad *n3=(quad *)malloc(sizeof(quad));
    n3->arr=(int **)malloc(k * sizeof(int *));
         for (int i=0; i<k; i++) 
         n3->arr[i]= (int *)malloc(k * sizeof(int));
    quad *n4=(quad *)malloc(sizeof(quad));
    n4->arr=(int **)malloc(k * sizeof(int *));
         for (int i=0; i<k; i++) 
         n4->arr[i]= (int *)malloc(k * sizeof(int));

    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
    {
        n1->arr[i][j]=a->arr[i][j];
        n2->arr[i][j]=a->arr[i][j+k];
        n3->arr[i][j]=a->arr[i+k][j];
        n4->arr[i][j]=a->arr[i+k][j+k];
    }

    }


    a->topleft=n1;
    a->topright=n2;
    a->bottomleft=n3;
    a->bottomright=n4;

    int f=check_same(n1->arr,k);
    if(f==-1)
    {
        create_tree(n1,k);
    }
    f=0;

      f=check_same(n2->arr,k);
    if(f==-1)
    {
        create_tree(n2,k);
    }
    f=0;

      f=check_same(n3->arr,k);
    if(f==-1)
    {
        create_tree(n3,k);
    }
    f=0;

    f=check_same(n4->arr,k);
    if(f==-1)
    {
        create_tree(n4,k);
    }
    f=0;
}

/**
 * @brief This function check if the elements are same in a array
 * 
 * @param a This is the array which stores data
 * @param m This is the size
 * @return int This reutrn either 0 or -1
 */
int check_same(int **a,int m)
{
    int test=a[0][0];
    int f=0;

    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
        if(test!=a[i][j])
        {
            f=-1;
            break;

        }
        }
        if(f==-1)
        {
            break;
        }
    }

    if(f==0)
    {
        int c=power(size);
        int c1=power(m);
        int l1=c-c1;
        level->height[co]=l1;
        level->data[co]=a[0][0];
        co++;
    }
     return f;
    
}
/**
 * @brief This helps to build maximal array
 * 
 * @param n This is the size
 * @param a This is the array which stores data
 * @return int This either returns 1,0,1024
 */
int max_tree(int n,int **a)
{
    int i1,i2,i3,i4;
    int item;

    int k=n;
     
    if(k!=2)
    {
        k=k/2;
        int **a1 = (int **)malloc(k * sizeof(int *)); 
    for (int i=0; i<k; i++) 
         a1[i] = (int *)malloc(k * sizeof(int));
         int **a2 = (int **)malloc(k * sizeof(int *)); 
    for (int i=0; i<k; i++) 
         a2[i] = (int *)malloc(k * sizeof(int));
         int **a3 = (int **)malloc(k * sizeof(int *)); 
    for (int i=0; i<k; i++) 
         a3[i] = (int *)malloc(k * sizeof(int));
         int **a4 = (int **)malloc(k * sizeof(int *)); 
    for (int i=0; i<k; i++) 
         a4[i] = (int *)malloc(k * sizeof(int));

        for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
    {
        a1[i][j]=a[i][j];
    }

    }

     for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
       {
            a2[i][j]=a[i][j+k];
       }

    }

     for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            a3[i][j]=a[i+k][j];
        }

    }

     for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            a4[i][j]=a[i+k][j+k];
        }

    }

    i1=max_tree(k,a1);
    i2=max_tree(k,a2);
    i3=max_tree(k,a3);
    i4=max_tree(k,a4);

    if(i2==i1 && i3==i1 && i4==i1 && i1!=1024)
    {
        item=i1;

        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                a2[i][j]=a1[i][j];
                a3[i][j]=a1[i][j];
                a4[i][j]=a1[i][j];
                
                
            }
            
        }
        count=count-3;

        
        

        
    }
    else
    {
        item=1024;
    }
    

    
    
    

        
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
    {
        a[i][j]=a1[i][j];
        a[i][j+k]=a2[i][j];
        a[i+k][j]=a3[i][j];
        a[i+k][j+k]=a4[i][j];
    }

    }

    return item;



    }

    else
    {
        if(a[0][1]==a[0][0] && a[1][0]==a[0][0] && a[1][1]==a[0][0])
        {
        
            item=a[0][0];
            a[0][0]=++count;
            a[1][0]=count;
            a[0][1]=count;
            a[1][1]=count;

            return item;
        }

        else
        {
            a[0][0]=++count;
            a[1][0]=++count;
            a[0][1]=++count;
            a[1][1]=++count;

            return 1024;
        }
        
    }
    
}

/**
 * @brief This help us to calulate power index of 2
 * 
 * @param m This is the size
 * @return int This returns power inices
 */
int power(int m)
{
    int c=0;
    while(m!=1)
    {
        m=m/2;
        c++;
    }
    return c;
}