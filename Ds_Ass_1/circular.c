/**
 * @file circular.c
 * @author Ritesh Singh (you@domain.com)
 * @brief This program have functions of circular linked list
 * @version 0.1
 * @date 2019-07-31
 *  @copyright Copyright (c) 2019
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

 /**
  * @brief This node defines the node and its instance variable
  */
struct node
{
    int val ;
    char name[20] ;
    char dob[10];
    char address[50];
    char phone_no[15];
    struct node *next;
    struct node *prev;    
};
typedef struct node n;

n* create_node(int,char *,char *,char *,char *);
void add_node(int *);
void delete_node(int*);
void modify(int);
void print();
void unused_roll_no(int *,int);
int use_roll_no(int *arr);
void add_from_file(int *,char [],char [],char [],char[]);
int search(int );
void sort_name();
void searchdata();

 
n *new, *ptr, *prev;
n *first = NULL, *last = NULL;
/**
 * @brief Length of the circular list
 * 
 */
int number = 0;
/**
 * @brief This is front of the queue

 * 
 */
int front=0;
/**
  * @brief This is end of the queue
 * 
 */
int end=0;
/**
 * @brief This is roll counter
 * 
 */
int opq=0;
 /**
  * @brief This method contains reading from the file and other functions
  *
  */
void main()
{
    int ch;
    int *arr;
    arr=(int*)malloc(50*sizeof(int));
    char name[100][100];
	char dob[100][13];
	char address[1000][500];
	char phone_no[100][13];

	char filename[31] = "StudentData.csv";
	char buff[1024];
	FILE *fp = fopen(filename, "r");
	fgets(buff, sizeof(buff), fp);

	for(int i=0;i<13;i++)
    {
		fgets(buff, sizeof(buff), fp);
		char* getValue = strtok(buff, ",");
		getValue = strtok(NULL, ",");
		strcpy(name[i], getValue);
		getValue = strtok(NULL, ",");
		strcpy(dob[i], getValue);
		getValue = strtok(NULL, "\"");
		strcpy(address[i], getValue);
		getValue = strtok(NULL, "\",");
		strcpy(phone_no[i], getValue);
   }

    
    
     
    while (1)
    {
          printf("Enter 1 to read from file:\nEnter 2 for other options:\n");
          int x;
          scanf("%d",&x);
          
          if(x==1)
          {
          int j;
            printf("Enter the line from which you want to make entry\n");
            scanf("%d",&j);
            j=j-1;
            add_from_file(arr,name[j],address[j],dob[j],phone_no[j]);
          }
              
        else if(x==2)
        {
        printf("Enter your choice:\n");
        printf("1.To add data manually\t2.To delete an entry\t3.To print data\t4.To modify data\t5.To sort by name\t6.Search a Roll_no\t7.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1 :
            add_node(arr);
            break;
            case 2 :
            delete_node(arr);
            break;
            case 3 :
            print();
            break;
            case 4:
            modify(0);
            break;
            case 5:
            sort_name();
            break;
            case 6:
            searchdata();
            break;
            case 7 :
            exit(0);
            default:
            printf("Enter between 1 to 7\n");    

            }
        }
        else
        {
            printf("Enter either 1 or 2\n");
        }
        
    }
}
/**
 * @brief This method create a new node in the circular list
 * 
 * @param Roll_No of the students
 * @param Address of the students
 * @param Name of the students
 * @param Phone_No of the students
 * @param DOB of the students
 */
n* create_node(int info,char *adress,char *name,char * phone_no,char *dob)
{
    number++;
    new = (n *)malloc(sizeof(n));
    new->val = info;
    strcpy(new->address,adress);
    strcpy(new->name,name);
    strcpy(new->phone_no,phone_no);
    strcpy(new->dob,dob);
    
    new->next = NULL;
    new->prev = NULL;
    return new;
}
/**
 * @brief This method reads from the file and pass info to create node
 * @param It is the queue which contains deleted Roll_No
 * @param Name from file
 * @param Address from file
 * @param Dob from file
 * @param Phone_No from file
 */
void add_from_file(int *arr,char name[],char address[],char dob[],char phone_no[])
{
    if(front==end)
    {
         int rollno=101+opq;
         
         
        new=create_node(rollno,address,name,phone_no,dob);
        
        if (first == last && first == NULL)
    {
 
        first = last = new;
        first->next = last->next = NULL;
        first->prev = last->prev = NULL;
        
    }
    else
    {
        last->next = new;
        new->prev = last;
        last = new;
        last->next = first;
        first->prev = last;
    }
    opq++;

    }

    else
{
    int rollno=use_roll_no(arr);
    int pos;
    int i;
    n *prevnode;
    struct node *new=create_node(rollno,address,name,phone_no,dob);
    int f=0;
    for(int k=0;k<number;k++)
   {
       f=search(rollno);
       if(f!=-1)
       {
           pos=f;
           
           break;
       }
       else
       {
           rollno++;
       }
       
   }

if (first == last && first == NULL)
    {
        if (pos == 1)
        {
            first = last = new;
            first->next = last->next = NULL;    
            first->prev = last->prev = NULL;
        }

    }
    else
    {
        if (number < pos)
            printf("Roll number not present\n");
 
        else
        {
            if(pos==1)
            {
                new->next=first;
                first->prev=new;
                last->next=new;
                new->prev=last;
                first=new;

            }
            else
            {
                for (ptr = first, i = 1;i <= number;i++)
              {
                prevnode = ptr;
                ptr = ptr->next;
                if (i == pos-1)
                  {
                    prevnode->next = new;
                    new->prev = prevnode;
                    new->next = ptr;
                    ptr->prev = new;
                    break;
                  }
              }
            }
        }
    }
    

    
}
}
/**
 * @brief This method takes input from the console and pass info to create node
 * @param It is the queue which contains deleted Roll_No
 */
void add_node(int *arr)
{
 
    char name[20] ;
    char dob[10];
    char address[50];
    char phone_no[15];
    
    printf("Enter the name you would like to add:(Use '_' to add string)\n");
    scanf("%s", name);
    printf("Enter the address you would like to add:(Use '_' to add string)\n");
    scanf("%s", address);
    printf("Enter the phone_no you would like to add:(No spaces in between)\n");
    scanf("%s", phone_no);
    printf("Enternter the dob:(No spaces in between)\n");
    scanf("%s", dob);
       
       if(front==end)
{
   
    int rollno=101+opq;
    
    new = create_node(rollno,address,name,phone_no,dob);
    
    if (first == last && first == NULL)
    {
 
        first = last = new;
        first->next = last->next = NULL;
        first->prev = last->prev = NULL;
        
    }
    else
    {
        last->next = new;
        new->prev = last;
        last = new;
        last->next = first;
        first->prev = last;
    }
    opq++;
}

   else 
{
   int rollno=use_roll_no(arr);
    int pos;
    int i;
    n *prevnode;
    new=create_node(rollno,address,name,phone_no,dob);
    int f=0;
    for(int k=0;k<number;k++)
   {
       f=search(rollno);
       if(f!=-1)
       {
           pos=f;
           
           break;
       }
       else
       {
           rollno++;
       }
       
   }
   
    if (first == last && first == NULL)
    {
        if (pos == 1)
        {
            first = last = new;
            first->next = last->next = NULL;    
            first->prev = last->prev = NULL;
        }
        else
            printf(" empty linked list you cant insert at that particular position\n");
    }
    else
    {
        if (number < pos)
            printf("node cant be inserted as position is exceeding the linkedlist length\n");
 
        else
        {
            if(pos==1)
            {
                new->next=first;
                first->prev=new;
                last->next=new;
                new->prev=last;
                first=new;

            }
            else
            {
                for (ptr = first, i = 1;i <= number;i++)
              {
                prevnode = ptr;
                ptr = ptr->next;
                if (i == pos-1)
                  {
                    prevnode->next = new;
                    new->prev = prevnode;
                    new->next = ptr;
                    ptr->prev = new;
                    break;
                  }
              }

            }
        }
    }
    

    
}
} 
/**
 * @brief This method modify the pre defined data of a given Roll_No
 * @param Roll_No to be modified
 */
void modify(int rollno)
{    
    if(rollno==0)
    {
    int roll_no;
             printf("Enter the roll_no. you want to modify:\n");
            scanf("%d", &roll_no);
            rollno=roll_no;
    }
    int   i, f = 0;
    char name[20] ;
    char dob[10];
    char address[50];
    char phone_no[15];
    
    printf("Enter the  new name:\n");
    scanf("%s", name);
    printf("Enter the  new address:\n");
    scanf("%s", address);
    printf("Enter the  new phone_no:\n");
    scanf("%s", phone_no);
    printf("Enter the  new DOB:\n");
    scanf("%s", dob);
    
    if (first == last && first == NULL)
        printf("List is empty\n");
    else
    {    
        for (ptr = first, i = 0;i < number;ptr = ptr->next,i++)
        {    
            if (ptr->val == rollno)
            {    
                
                strcpy(ptr->address,address);
                strcpy(ptr->name,name);
                strcpy(ptr->phone_no,phone_no);
                strcpy(ptr->dob,dob);
                f = 1;
            }    
        }
        if (f == 0)
            printf("Roll_no is not present\n");
    }
}

/**
 * @brief This method returns a position of a given Roll_No
 * @param Roll_No to be searched
 * @return Gives position of Roll_No in circular list
 */
int search(int rollno)
{
    int count = 0, i, f = 0,pos;
 
    if (first == last && first == NULL)
    {
        printf("List is empty\n");
        return -1;
    }
    else
    {
        for (ptr = first,i = 0;i < number;i++,ptr = ptr->next)
        {
            count++;
            if (ptr->val == rollno)
            {
                 f = 1;
                pos=count;
               f = 1;
               break;
            }    
        }
        
    }
    if(f==1)
            {
                return pos;
            }
            else
            {
                return -1;
            }
            
}
/**
 * @brief This node deletes a node
 * @param The array where deleted Roll_No to be stored
 */
void delete_node(int *arr)
{
    int count = 0, rollno, i, f = 0,pos;
 
    printf("Enter the rollno to be deleted:\n");
    scanf("%d", &rollno);
 
    if (first == last && first == NULL)
        printf("List is empty\n");
    else
    {
        for (ptr = first,i = 0;i < number;i++,ptr = ptr->next)
        {
            count++;
            if (ptr->val == rollno)
            {
                pos=count;
                unused_roll_no(arr,rollno);
                f = 1;
            }    
        }
        if (f == 0)
            printf("The roll_no is not found in linkedlist\n");
    }
    
    n  *prevnode;
 
    if (first == last && first == NULL)
        printf("Linked list is empty,you cannott delete\n");
 
    else
    {
        if (number < pos)
            printf("Node cannot be deleted due to exceeding size\n");
 
        else
        {
            for (ptr = first,i = 1;i <= number;i++)
            {
                prevnode = ptr;
                ptr = ptr->next;
                if (pos == 1)
                {    
                    number--;
                    last->next = prevnode->next;
                    ptr->prev = prevnode->prev;
                    first = ptr;
                    free(prevnode);
                    break;        
                }
                else if (i == pos-1 )
                {    
                    number--;
                    prevnode->next = ptr->next;
                    ptr->next->prev = prevnode;
                    free(ptr);
                    break;
                }
            }
        }
    }
}

/**
 * @brief This method prints the data
 */
void print()
{
    int i;
    if (first == last && first == NULL)
        printf("List is empty\n");
    else
    {    
        printf("There are %d number of nodes\n", number);
        for (ptr = first, i = 0;i < number;i++,ptr = ptr->next)
            {
            printf("Roll_NO:%d\n", ptr->val);
            
            printf("\tName:%s\n",ptr->name);
            // printf("\n Address:%s",ptr->address);
            printf("\tPhone_no:%s\n",ptr->phone_no);
            printf("\tDOB:%s\n",ptr->dob);
            }
    }
}


/**
 * @brief This method stores the deleted Roll_No
 * @param The array in which Roll_No will be stored
 * @param Deleted Roll_No
 */

void unused_roll_no(int *arr,int roll_no)
{
    
    arr[end]=roll_no;
    end++;
}

/**
 * @brief This method pop Roll_No
 * @param The array from which Roll_No is poped
 * @return Roll_no
 */
int use_roll_no(int *arr)
{
    int b=arr[0];
    for(int i=0;i<50;i++)
    {
        arr[i]=arr[i+1];
    }
    end--;
    return b;
}

/**
 * @brief This method sorts the array wrt Names
 */
void sort_name()
{
    n *temp,*index;
    char a[] = "Empty";
    new=create_node(0,a,a,a,a);
    number--;
    for(int i=0;i<number-1;i++)
    {
        index=first;
        temp=first->next;
        for(int j=0;j<number-1-i;j++)
        {
            int test=strcmp(index->name,temp->name);
            if(test>0)
            {
                new->val=temp->val;
                strcpy(new->address,temp->address);
                strcpy(new->dob,temp->dob);
                strcpy(new->name,temp->name);
                strcpy(new->phone_no,temp->phone_no);


                temp->val=index->val;
                strcpy(temp->address,index->address);
                strcpy(temp->dob,index->dob);
                strcpy(temp->name,index->name);
                strcpy(temp->phone_no,index->phone_no);

                index->val=new->val;
                strcpy(index->address,new->address);
                strcpy(index->dob,new->dob);
                strcpy(index->name,new->name);
                strcpy(index->phone_no,new->phone_no);

                index=temp;
                temp=temp->next;
            }
            else
            {
                index=temp;
                temp=temp->next;
            }
            

        }
    }
}
/**
 * @brief This method search for a particular roll_no and prints it
 * 
 */
void searchdata()
{
    int rollno;
    printf("Enter the rollno to be searched\n");
    scanf("%d",&rollno);
    
    int count = 0, i, f = 0,pos;
 
    if (first == last && first == NULL)
    {
        printf("List is empty\n");
        
    }
    else
    {
        for (ptr = first,i = 0;i < number;i++,ptr = ptr->next)
        {
            count++;
            if (ptr->val == rollno)
            {
                 f = 1;
                pos=count;
               printf("Roll_NO:%d\n", ptr->val);
            
            printf("\tName:%s\n",ptr->name);
            // printf("\n Address:%s",ptr->address);
            printf("\tPhone_no:%s\n",ptr->phone_no);
            printf("\tDOB:%s\n",ptr->dob);
               break;
            }    
        }
        if (f == 0)
            printf("The roll_no is not found in linkedlist\n");
    }
} 
