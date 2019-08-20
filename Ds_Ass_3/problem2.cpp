/**
 * @file problem2.cpp
 * @author Ritesh Singh (you@domain.com)
 * @brief This program count the no. of XOR triplets
 * @version 0.1
 * @date 2019-08-20
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include<iostream>
#include <bits/stdc++.h>
 

using namespace std;
/**
 * @brief This is the linked list datastructure
 * 
 */
struct pre_xor
{
    int key;
    int pre;

    pre_xor * next;                            
};
/**
 * @brief The head of linked list
 * 
 */
pre_xor *pre,*first;

int arr_index[100];
int icount=0;


void calculate_pre_xor(int *,int );
void print_xor();
int xor_return(int );
void index_printer(int ,unordered_map<int ,int> & );
/**
 * @brief This function counts the number of XOR
 * 
 * @return int Default return 0
 */
int main()
{

    int n;
    int ans=0;
    cout<<"Enter the value of n:\n";
    cin>>n;
    int a[n];
    cout<<"Enter n spaced integers:"<<endl;

    for (int i=0;i<n;i++)
    cin>>a[i];

int k=0;
    int b[n];
    
    b[0]=a[0];
    for(int i=1;i<n;i++)
    b[i]=b[i - 1] ^ a[i];

    

    unordered_map<int,int> mp;
    unordered_map<int, int> mp1;
    unordered_map< int, int> index;
    
    



     pre=(pre_xor *)malloc(sizeof(pre_xor));
    pre->key=0;
    pre->pre=a[0];
    first=pre;

    for(int i=1;i<n;i++)
    {
        calculate_pre_xor(b,i);
    }


    for(int i=0;i<n;i++)
    {
        int p=0^xor_return(i);
       


        if(mp[p]>0)
		{
		   
		   ans=ans+mp[p]*(i-1)-mp1[p];
           index[p]=i;
        }
		if (p == 0)
        { 
			ans=ans+i;
            arr_index[icount]=i;
            icount++;
        }
			
		mp[p]++; 
		mp1[p]+=i;
    }

    cout<<"The total number of triplets are:"<<endl;
    cout<<ans<<endl;
    
   cout<<"The list of triplets are:"<<endl; 
   index_printer(n,index);

  

    return 0;
}

/**
 * @brief Calculate XOR and stores in linked list
 * 
 * @param a An array
 * @param l The length of array
 */
void calculate_pre_xor(int *a,int l)
{ 
   pre_xor *n=(pre_xor *)malloc(sizeof(pre_xor));
   
   
   n->key=l;
   n->pre=a[l];

   pre_xor *temp;
   temp=first;

   for(int i=0;i<l;i++)
   {
       if(i==l-1)
       {
           temp->next=n;
       }
       else
       {
           temp=temp->next;
       }
    }
}
/**
 * @brief This function prints value stored in linked list
 * 
 */
void print_xor()
{
    pre_xor *temp;
    temp=first;
    while(temp)
    {
        cout<<temp->pre<<endl;
        temp=temp->next;
    }
}

/**
 * @brief This function returns XOR from linked list
 * 
 * @param l The index
 * @return int return XOR value
 */
int xor_return(int l)
{
    pre_xor *temp;
    temp=first;
    int p=temp->pre;
    for(int i=0;i<l;i++)
    {
        temp=temp->next;
        p=temp->pre;
    }

    return p;
}

/**
 * @brief This function prints the triplets
 * 
 * @param n Total number of elements
 * @param index A unordered map
 */
void index_printer(int n,unordered_map<int,int> &index)
{

    for(int i=0;i<icount;i++)
    {
        int k=arr_index[i];
        for(int i=2;i<k+2;i++)
        {
            cout<<"("<<"1"<<","<<i<<","<<k+1<<")"<<endl;
        }
    }


    pre_xor *temp;
    temp=first;

    for(int q=0;q<n;q++)
    {
        int p=temp->pre;

        if(index[p]>0)
        {
            int k=temp->key;
            for(int i=k+3;i<index[p]+2;i++)
            {
                cout<<"("<<k+2<<","<<i<<","<<index[p]+1<<")"<<endl;
            }
        }

        temp=temp->next;
        }

}