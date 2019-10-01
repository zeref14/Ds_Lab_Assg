
/**
 * @file problem1.cpp
 * @author your name (ritesh@domain.com)
 * @brief this program add and multiply polynomial
 * @version 0.1
 * @date 2019-10-02
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

unordered_map<int,int>polynomial_add(unordered_map<int,int>poly,unordered_map<int,int>poly1,int m,int n);
unordered_map<int,int>polynomial_multiply(unordered_map<int,int>poly,unordered_map<int,int>poly1,int m,int n);
void display_product(unordered_map<int,int>product,int m,int n);
void display_add(unordered_map<int,int>add,int m,int n);


int main() 
{ 
    int t;
    cout<<"No. of terms in the expression-";
    cin>>t;
    cout<<"Coefficient\tPower\n";
        int a[t];
        int b[t];
        for(int i=0;i<t;i++)
        {
            cin>>a[i];
            cin>>b[i];
        }

        unordered_map<int,int> umap;
        
        for(int i=0;i<t;i++)
        umap[b[i]]=a[i];


        int t1;
    cout<<"No. of terms in the expression-";
    cin>>t1;
    cout<<"Coefficient\tPower\n";
    
        int a1[t1];
        int b1[t1];
        
        for(int i=0;i<t1;i++)
        {
            cin>>a1[i];
            cin>>b1[i];
        }

        unordered_map<int,int> umap1;
        
        for(int i=0;i<t1;i++)
        umap1[b1[i]]=a1[i];


        int m=b[0];    //Always fill the the cofficient in top-down order
        int n=b1[0];

        unordered_map<int,int>q=polynomial_add(umap,umap1,m,n);
        unordered_map<int,int>p=polynomial_multiply(umap,umap1,m,n);

      int ch;
      while(1)
      {
          cout<<"Enter 1 for addition , 2 for multiplication ,3 for exit"<<endl;
          cin>>ch;
          switch (ch)
          {
          case 1:
              display_add(q,m,n);
              cout<<endl;
              break;
          case 2:
              display_product(p,m,n);
              cout<<endl;
              break;
          case 3:
              exit(0);
              break;
          
          default:
          cout<<"Enter correct arguments\n";
              break;
          }
      }
      
      
      
      return 0; 
} 

/**
 * @brief Construct a new unordered map<int,int>polynomial add object add polynomial
 * 
 */
unordered_map<int,int>polynomial_add(unordered_map<int,int>poly,unordered_map<int,int>poly1,int m,int n)
{
    unordered_map<int,int>add;

    int max=(m<n)?n:m;

    for(int i=0;i<max+1;i++)
    add[i]=poly[i]+poly1[i];

    return add;
}


/**
 * @brief Construct a new unordered map<int,int>polynomial multiply object multiply polynomial
 * 
 */
unordered_map<int,int>polynomial_multiply(unordered_map<int,int>poly,unordered_map<int,int>poly1,int m,int n)
{
    unordered_map<int,int>product;

     for (int i=0; i<m+1; i++) 
   { 
     for (int j=0; j<n+1; j++) 
         product[i+j] += poly[i]*poly1[j]; 
   } 

   return product;

}

/**
 * @brief display product
 * 

 */
void display_product(unordered_map<int,int>product,int m,int n)
{
    cout<<"Coefficient\tPower\n";
    
    for(int i=m+n;i>=0;i--)
    {
        cout<<product[i]<<"\t\t";
        cout<<i<<endl;

    }

}

/**
 * @brief display addition

 */
void display_add(unordered_map<int,int>add,int m,int n)
{
    int max=(m<n)?n:m;
    cout<<"Coefficient\tPower\n";
    
    for(int i=max;i>=0;i--)
    {
        cout<<add[i]<<"\t\t";
        cout<<i<<endl;

    }

}

