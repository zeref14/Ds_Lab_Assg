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

/**
 * @brief This function compares the two files
 * 
 * @return int This return 0
 */
int main()
{
    char si[1024];
    char so[1024];
    FILE *fi,*fo;
    fi=fopen("inputfile.txt","r");
    fo=fopen("decryptedOutputfile.txt","r");
    fgets(si,sizeof(si),fi);
    fgets(so,sizeof(so),fo);
    int l=strcmp(si,so);
    if(l==0)
    {
        printf("The input and output files are EQUAL\n");
    }
    else
    {
        printf("The input and output files are different\n");
    }
    

}