/**
 * @file deque.c
 * @author Ritesh Singh (you@domain.com)
 * @brief This program contains deque and its properties
 * @version 0.1
 * @date 2019-07-31
 * @copyright Copyright (c) 2019
 * 
 */
#include<stdio.h>
#include<stdlib.h>




void display(int *arr);
void add_element_back(int *arr);
void add_element_front(int *arr);
void delete_back(int *arr);
void delete_front(int *arr);
void array_full(int *arr);
void array_half(int *arr);
void shift_right(int *arr,int data);
void print_size();

/**
 * @brief This is the front of deque
 * 
 */
int front=0;
/**
 * @brief This is the end of the deque
 * 
 */
int end=0;
/**
 * @brief This is the size of the deque
 * 
 */
int n;
/**
 * @brief This method contains other methods
 * 
 */
void main()
{
    int *arr;
 
 printf("Enter the size of the array\n");
 scanf("%d",&n);
 arr=(int*)malloc(n*sizeof(int));
 printf("Enter the first element\n");
 scanf("%d",&arr[0]);
 end++;
    int ch;
   
    
    while(1)
  {
       printf("Enter the choices:\n");
       printf("1.Enter element from back\t");
       printf("2.Enter element from front\t");
       printf("3.Delete element from back\t");
       printf("4.Delete element from front\t");
       printf("  5.Print element from front\t");
       printf("6.Print the size of deque\t");
       printf("7.Exit\n\n");
    scanf("%d",&ch);
    printf("\n\n");
    switch(ch)
    {
        case 1:
        
        add_element_back(arr);
        break;
        case 2:
        add_element_front(arr);
        
        break;
        case 3:
        delete_back(arr);
        break;
        case 4:
        delete_front(arr);
        break;
        case 5:
        display(arr);
        break;
        case 6:
       print_size();
       break;
       case 7:
       exit(0);
        default:
        ;
    }
  }
}

/**
 * @brief This method print the deque
 * 
 * @param arr This is the deque
 */
void display(int *arr)
{
    
    for(int i=0;i<end;i++)
    {
        printf("%d\n",arr[i]);
    }
    printf("\n");
}
/**
 * @brief This method add elements at back of deque
 * 
 * @param arr This is deque
 */
void add_element_back(int *arr)
{
    int data;
    
    printf("Enter the data\n");
    scanf("%d",&data);
    if(end%n!=front)
    {
    arr[end]=data;
    end++;
    }
     else if(end%n==front)
    {
        
        array_full(arr);
        arr[end]=data;
        end++;
        
    }


}

/**
 * @brief This method add from front
 * 
 * @param arr This is the deque
 */
void add_element_front(int *arr)
{
    int data;
    printf("Enter the data\n");
    scanf("%d",&data);
    if(end%n==front)
    {
        array_full(arr);
        shift_right(arr,data);
        
    }
    else
    {
        shift_right(arr,data);
        
    }
    

}
/**
 * @brief This method deletes from front
 * 
 * @param arr This is the deque
 */
void delete_front(int *arr)
{
    if(front==end)
    {
        printf("The array is empty\n");
    }
    else
    {
        for(int i=0;i<n-1;i++)
        {
            arr[i]=arr[i+1];
        }
        end--;
        if(end==n/2 &&end==0)
        {
            array_half(arr);
        }
    }
    
}
/**
 * @brief This method delete from back
 * 
 * @param arr This is the deque
 */
void delete_back(int *arr)
{
    if(front==end)
    {
        printf("Deque is empty\n");
    }
    else
{
        
    
    
    --end;
    if(end==n/2)
    {
        array_half(arr);
        arr[end]=0;
    }
    else
    {
        arr[end]=0;
    }
    
}    
}
/**
 * @brief This method increase the size of deque
 * 
 * @param arr This is the deque
 */
void array_full(int *arr)
{
    int *ptr;
    
    n=2*n;
    ptr=(int*)realloc(arr,sizeof(int)*(n));
    arr=ptr;

}
/**
 * @brief This method shifts the data towards right
 * 
 * @param arr This is the deque
 * @param data The data to be entered at front
 */

void shift_right(int*arr,int data)
{
    for(int i=1;i<n;i++)
        {
            
            arr[n-i]=arr[n-i-1];
        }
        arr[0]=data;
        end++;
}
/**
 * @brief This method reduces the size of deque
 * 
 * @param arr This is deque
 */
void array_half(int *arr)
{
  int *ptr;
    n=n/2;
    ptr=(int*)realloc(arr,sizeof(int)*(n));
    arr=ptr;   
}
/**
 * @brief This method prints size of deque
 * 
 */
void print_size()
{
    printf("The size of deque is%d\n",n);
}




