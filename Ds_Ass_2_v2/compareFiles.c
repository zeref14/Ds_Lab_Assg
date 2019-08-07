/**
 * @file compareFiles.c
 * @author Ritesh Singh (you@domain.com)
 * @brief This program compares the input and decrypted file
 * @version 0.1
 * @date 2019-08-07
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count=0;

/**
 * @brief This function compares the two files
 * 
 * @return int This return 0
 */
int main()
{
    
    FILE *fi,*fo,*fp1;
    char c;
    fi=fopen("inputfile.txt","r");
    fo=fopen("decryptedOutputfile.txt","r");
    fp1=fopen("decryptedOutputfile.txt","r");
    
      while ((c = fgetc(fp1)) != EOF)
    {
        if(c=='\n')
        count++;
    }
    for(int i=0;i<count;i++)
{    
    char si[1024];
    char so[1024];
    fgets(si,sizeof(si),fi);
    fgets(so,sizeof(so),fo);
    int l=strcmp(si,so);
    if(l==0)
    {
        printf("The input and output string are EQUAL\n");
    }
    else
    {
        printf("The input and output string are different\n");
    }

}
    fclose(fi);
    fclose(fo);
    fclose(fp1);

}