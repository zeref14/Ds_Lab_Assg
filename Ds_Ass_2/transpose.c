/**
 * @file transpose.c
 * @author Ritesh Singh (you@domain.com)
 * @brief This program encodes the data given in a file
 * @version 0.1
 * @date 2019-08-07
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include <string.h>


void encoder(char *,char *,int ,int ,int ,int );

/**
 * @brief This variable counts the number of lines in the input file
 * 
 */
int count=0;

/**
 * @brief This function reads the file input.txt and also write the decrypted data in output.txt
 * 
 * @param argc This counts the total number of arguments passed
 * @param argv This contains list of the arguments
 * @return int This functions return 0
 */
int main(int argc,char const *argv[])
{
    
    if(argc<5 || argc>5)
    {
        printf("Please give correct number of arguments\n");
    }
    else
    {
    int n=atoi(argv[1]);
    int a=atoi(argv[2]);
    int b=atoi(argv[3]);


    
    char c;
    FILE *fp,*fp1;
    FILE *fw;
    fw=fopen("outputfile.txt","w");
    fp=fopen(argv[4],"r");
    fp1=fopen(argv[4],"r");
    while ((c = fgetc(fp1)) != EOF)
    {
        if(c=='\n')
        count++;
    }
    for(int i=0;i<count;i++)
    {
       char s[1024];
       fgets(s,sizeof(s),fp);
    
    int l=strlen(s);
    s[l-1]='\0';
    l=strlen(s);
    
    int q;
    if(l%n==0)
    {
        q=l/n;
    }
    else
    {
        q=l/n;
        q=q+1;
    }
    int m=q*n;
    for(int i=l;i<m;i++)
    {
        s[i]='$';
    }

    char so[1024];
    encoder(s,so,a,b,q,n);
    fprintf(fw,"%s",so);
    fprintf(fw,"\n");

    }
    

    printf("The given file is encrypted in outputfile.txt\n");
fclose(fp);
fclose(fp1);
fclose(fw);
    }
    return 0;
}

/**
 * @brief This function encodes the data wrt provided keys
 * 
 * @param s This char array stores the string from input file
 * @param s2 This char array stores the data to be written on outputfile
 * @param a This is a part of the key
 * @param b This is a part of key
 * @param q This is the quotient when length of string is divided by n
 * @param n This is the key
 */
void encoder(char *s,char *s2,int a,int b,int q,int n)
{
    int j;
    
    
    int temp=0;
    
    for(int k=0;k<q;k++)
    {
    for(int i=0;i<n;i++)
    {
        j=(a*i+b)%n;
        s2[i+temp]=s[j+temp];
        
    }
    temp=temp+n;
    }
   }

   