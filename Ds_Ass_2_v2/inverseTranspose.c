/**
 * @file inverseTranspose.c
 * @author Ritesh Singh (you@domain.com)
 * @brief This function decrypts the data
 * @version 0.1
 * @date 2019-08-07
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



// void decoder(char *,char *,int ,int ,int ,int );
void decode(char *,char *,int ,int ,int ,int );

/**
 * @brief This variable count the number of line
 * 
 */
int count=0;
/**
 * @brief This function reads and write the data
 * 
 * @param argc This counts the number of arguments passed
 * @param argv This stores the arguments
 * @return int The function returns 0
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

    FILE *fp,*fp1;
    FILE *fw;
    fw=fopen("decryptedOutputfile.txt","w");
    fp=fopen(argv[4],"r");
    fp1=fopen(argv[4],"r");
    
    char c;
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
    s[l-1]='\0';//Removing "\n" from the last
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
    
    char so[1024];
    decode(s,so,a,b,q,n);
    
    for(int i=0;i<l;i++)
    {
        if(so[i]=='$')
        {
            so[i]='\0';
            
        }
    }
    
    fprintf(fw,"%s",so);
    fprintf(fw,"\n");
    }

    fclose(fp);
    fclose(fp1);
    fclose(fw);
    }

    printf("The given file is decrypted in decryptedOutputfile.txt\n");
    
    return 0;
}

/**
 * @brief This function decrypt the file
 * 
 * @param s This char array stores the string from input file
 * @param s2 This char array stores the data to be written on file
 * @param a This is a part of the key
 * @param b This is a part of key
 * @param q This is the quotient when length of string is divided by n
 * @param n This is the key
 */
void decode(char *s,char *s2,int a,int b,int q,int n)
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

   // void decoder(char *s,char *s2,int a,int b,int q,int n)
// {
//     int j;
//     int temp=0;
//     for(int k=0;k<q;k++)
//     {
//         for(int i=0;i<n;i++)
//         {
//             j=(a*i+b)%n;
//             s2[j+temp]=s[i+temp];
//         }
//         temp=temp+n;
//     }


// }
