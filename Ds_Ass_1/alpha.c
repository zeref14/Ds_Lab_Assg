/**
 * @file alpha.c
 * @author Ritesh Singh (you@domain.com)
 * @brief This program remove or preserves a particular shade
 * @version 0.1
 * @date 2019-07-31
 * @copyright Copyright (c) 2019
 * 
 */
#include<stdio.h>
#include<stdlib.h>

void remove_greenshades();
void remove_redshades();
void remove_blueshades();
void preserve_greenshade();
void preserve_redshade();
void preserve_blueshade();
void pixel_value();

/** 
 
 * brief This is main method which has access to all other functions

 */
short main()
{
   short ch;
   
   
while(1)
{
  printf("Enter a choice:\n");
   
  

   printf("1.Remove_Greenshades\t2.Remove_Redshades\t3.Remove_Blueshades\t4.Preserve_Greenshades\t5.Preserve_Redshades\t  6.Preserve_Blueshades\t7.Pixel_Value\t 8.Exit\n");
    scanf("%hd",&ch);
   switch (ch)
   {
   case 1:
       remove_greenshades();
       break;
       case 2:
       remove_redshades();
       break;
       case 3:
       remove_blueshades();
       break;
       case 4:
       preserve_greenshade();
       break;
       case 5:
       preserve_redshade();
       break;
       case 6:
       preserve_blueshade();
       break;
       case 7:
       pixel_value();
       break;
       case 8:
       exit(0);
   
   default:
       break;
   }
}
    return 0;
}

/**
 * @brief This methods remove Green Shades
 */
void remove_greenshades()
{
    FILE *fg,*fb,*fr,*fgw,*frw,*fbw;
    short count=0;
    fb=fopen("Blue.dat","r");
    fg=fopen("Green.dat","r");
    fr=fopen("Red.dat","r");
    short red[953][1268];
    short blue[953][1268];
    short green[953][1268];
    
    for(short i=0;i<953;i++)
    {
        for(short j=0;j<1268;j++)
        {
     fscanf(fg,"%hd,",&green[i][j]);
     fscanf(fr,"%hd,",&red[i][j]);
     fscanf(fb,"%hd,",&blue[i][j]);
    
    
      // if(count==-1)
      // {
      //     break;
      // }
    
        }
    }

    
    for(short i=0;i<953;i++)
    {
        for(short j=0;j<1268;j++)
        {
            if(green[i][j]>red[i][j] && green[i][j]>blue[i][j])
            {
                green[i][j]=0;
            }
        }
    }
    
    fgw=fopen("green.dat","w");
    frw=fopen("red.dat","w");
    fbw=fopen("blue.dat","w");
    
    for(short i=0;i<953;i++)
    {
        for(short j=0;j<1268;j++)
        {
            if(j==1267)
    {
    fprintf(frw,"%hd",red[i][j]);
    fprintf(fbw,"%hd",blue[i][j]);
    fprintf(fgw,"%hd",green[i][j]);
    
    }
    else
    {
        fprintf(frw,"%hd,",red[i][j]);
        fprintf(fbw,"%hd,",blue[i][j]);
        fprintf(fgw,"%hd,",green[i][j]);
       
    }
    
        }
        fprintf(fgw,"\n");
        fprintf(frw,"\n");
        fprintf(fbw,"\n");
    }

    

    fclose(fr);
    fclose(fg);
    fclose(fb);
    fclose(fbw);
    fclose(frw);
    fclose(fgw);
    
}
/**
 * @brief This methods remove Red Shades
 */
void remove_redshades()
{
    FILE *fg,*fb,*fr,*fgw,*frw,*fbw;
    short count=0;
    fb=fopen("Blue.dat","r");
    fg=fopen("Green.dat","r");
    fr=fopen("Red.dat","r");
    short red[953][1268];
    short blue[953][1268];
    short green[953][1268];
    
    for(short i=0;i<953;i++)
    {
        for(short j=0;j<1268;j++)
        {
     fscanf(fg,"%hd,",&green[i][j]);
     fscanf(fr,"%hd,",&red[i][j]);
     fscanf(fb,"%hd,",&blue[i][j]);
    
    
      if(count==-1)
      {
          break;
      }
    
        }
    }

    
    for(short i=0;i<953;i++)
    {
        for(short j=0;j<1268;j++)
        {
            if(red[i][j]>green[i][j] && red[i][j]>blue[i][j])
            {
                red[i][j]=0;
            }
        }
    }
    fgw=fopen("green.dat","w");
    frw=fopen("red.dat","w");
    fbw=fopen("blue.dat","w");
    
    for(short i=0;i<953;i++)
    {
        for(short j=0;j<1268;j++)
        {
            if(j==1267)
    {
    fprintf(frw,"%hd",red[i][j]);
    fprintf(fbw,"%hd",blue[i][j]);
    fprintf(fgw,"%hd",green[i][j]);
    
    }
    else
    {
        fprintf(frw,"%hd,",red[i][j]);
        fprintf(fbw,"%hd,",blue[i][j]);
        fprintf(fgw,"%hd,",green[i][j]);
       
    }
    
        }
        fprintf(fgw,"\n");
        fprintf(frw,"\n");
        fprintf(fbw,"\n");
    }

    

    fclose(fr);
    fclose(fg);
    fclose(fb);
    fclose(fbw);
    fclose(frw);
    fclose(fgw);
    
}
/**
 * @brief This methods remove Blue Shades
 */

void remove_blueshades()
{
    FILE *fg,*fb,*fr,*fgw,*frw,*fbw;
    short count=0;
    fb=fopen("Blue.dat","r");
    fg=fopen("Green.dat","r");
    fr=fopen("Red.dat","r");
    short red[953][1268];
    short blue[953][1268];
    short green[953][1268];
    
    for(short i=0;i<953;i++)
    {
        for(short j=0;j<1268;j++)
        {
     fscanf(fg,"%hd,",&green[i][j]);
     fscanf(fr,"%hd,",&red[i][j]);
     fscanf(fb,"%hd,",&blue[i][j]);
    
    
      if(count==-1)
      {
          break;
      }
    
        }
    }

    
    for(short i=0;i<953;i++)
    {
        for(short j=0;j<1268;j++)
        {
            if(blue[i][j]>red[i][j] && blue[i][j]>red[i][j])
            {
                blue[i][j]=0;
            }
        }
    }
    
    fgw=fopen("green.dat","w");
    frw=fopen("red.dat","w");
    fbw=fopen("blue.dat","w");
    
    for(short i=0;i<953;i++)
    {
        for(short j=0;j<1268;j++)
        {
            if(j==1267)
    {
    fprintf(frw,"%hd",red[i][j]);
    fprintf(fbw,"%hd",blue[i][j]);
    fprintf(fgw,"%hd",green[i][j]);
    
    }
    else
    {
        fprintf(frw,"%hd,",red[i][j]);
        fprintf(fbw,"%hd,",blue[i][j]);
        fprintf(fgw,"%hd,",green[i][j]);
       
    }
    
        }
        fprintf(fgw,"\n");
        fprintf(frw,"\n");
        fprintf(fbw,"\n");
    }

    

    fclose(fr);
    fclose(fg);
    fclose(fb);
    fclose(fbw);
    fclose(frw);
    fclose(fgw);
    
}
/**
 * @brief This methods preserves Green Shades
 */
void preserve_greenshade()
{
    FILE *fg,*fb,*fr,*fgw,*frw,*fbw;
    short count=0;
   fb=fopen("Blue.dat","r");
    fg=fopen("Green.dat","r");
    fr=fopen("Red.dat","r");
    short red[953][1268];
    short blue[953][1268];
    short green[953][1268];
    
    for(short i=0;i<953;i++)
    {
        for(short j=0;j<1268;j++)
        {
     fscanf(fg,"%hd,",&green[i][j]);
     fscanf(fr,"%hd,",&red[i][j]);
     fscanf(fb,"%hd,",&blue[i][j]);
    
    
      if(count==-1)
      {
          break;
      }
    
        }
    }

    
    for(short i=0;i<953;i++)
    {
        for(short j=0;j<1268;j++)
        {
            if(red[i][j]>green[i][j] && red[i][j]>blue[i][j])
            {
                red[i][j]=0;
            }
            if(blue[i][j]>red[i][j] && blue[i][j]>red[i][j])
            {
                blue[i][j]=0;
            }
        }
    }
    fgw=fopen("green.dat","w");
    frw=fopen("red.dat","w");
    fbw=fopen("blue.dat","w");
    
    for(short i=0;i<953;i++)
    {
        for(short j=0;j<1268;j++)
        {
            if(j==1267)
    {
    fprintf(frw,"%hd",red[i][j]);
    fprintf(fbw,"%hd",blue[i][j]);
    fprintf(fgw,"%hd",green[i][j]);
    
    }
    else
    {
        fprintf(frw,"%hd,",red[i][j]);
        fprintf(fbw,"%hd,",blue[i][j]);
        fprintf(fgw,"%hd,",green[i][j]);
       
    }
    
        }
        fprintf(fgw,"\n");
        fprintf(frw,"\n");
        fprintf(fbw,"\n");
    }

    

    fclose(fr);
    fclose(fg);
    fclose(fb);
    fclose(fbw);
    fclose(frw);
    fclose(fgw);
    
}
/**
 * @brief This methods preserve Red Shades
 */
void preserve_redshade()
{
    FILE *fg,*fb,*fr,*fgw,*frw,*fbw;
    short count=0;
    fb=fopen("Blue.dat","r");
    fg=fopen("Green.dat","r");
    fr=fopen("Red.dat","r");
    short red[953][1268];
    short blue[953][1268];
    short green[953][1268];
    
    for(short i=0;i<953;i++)
    {
        for(short j=0;j<1268;j++)
        {
     fscanf(fg,"%hd,",&green[i][j]);
     fscanf(fr,"%hd,",&red[i][j]);
     fscanf(fb,"%hd,",&blue[i][j]);
    
    
      if(count==-1)
      {
          break;
      }
    
        }
    }

    
    for(short i=0;i<953;i++)
    {
        for(short j=0;j<1268;j++)
        {
            if(green[i][j]>red[i][j] && green[i][j]>blue[i][j])
            {
                green[i][j]=0;
            }
             if(blue[i][j]>red[i][j] && blue[i][j]>red[i][j])
            {
                blue[i][j]=0;
            }
        }
    }
    fgw=fopen("green.dat","w");
    frw=fopen("red.dat","w");
    fbw=fopen("blue.dat","w");
    
    for(short i=0;i<953;i++)
    {
        for(short j=0;j<1268;j++)
        {
            if(j==1267)
    {
    fprintf(frw,"%hd",red[i][j]);
    fprintf(fbw,"%hd",blue[i][j]);
    fprintf(fgw,"%hd",green[i][j]);
    
    }
    else
    {
        fprintf(frw,"%hd,",red[i][j]);
        fprintf(fbw,"%hd,",blue[i][j]);
        fprintf(fgw,"%hd,",green[i][j]);
       
    }
    
        }
        fprintf(fgw,"\n");
        fprintf(frw,"\n");
        fprintf(fbw,"\n");
    }

    

    fclose(fr);
    fclose(fg);
    fclose(fb);
    fclose(fbw);
    fclose(frw);
    fclose(fgw);
    
}
/**
 * @brief This methods preserves Blue Shades
 */
void preserve_blueshade()
{
    FILE *fg,*fb,*fr,*fgw,*frw,*fbw;
    short count=0;
  fb=fopen("Blue.dat","r");
    fg=fopen("Green.dat","r");
    fr=fopen("Red.dat","r");
    short red[953][1268];
    short blue[953][1268];
    short green[953][1268];
    
    for(short i=0;i<953;i++)
    {
        for(short j=0;j<1268;j++)
        {
     fscanf(fg,"%hd,",&green[i][j]);
     fscanf(fr,"%hd,",&red[i][j]);
     fscanf(fb,"%hd,",&blue[i][j]);
    
    
      if(count==-1)
      {
          break;
      }
    
        }
    }

    
    for(short i=0;i<953;i++)
    {
        for(short j=0;j<1268;j++)
        {
           if(green[i][j]>red[i][j] && green[i][j]>blue[i][j])
            {
                green[i][j]=0;
            }
            if(red[i][j]>green[i][j] && red[i][j]>blue[i][j])
            {
                red[i][j]=0;
            }
        }
    }
    
    fgw=fopen("green.dat","w");
    frw=fopen("red.dat","w");
    fbw=fopen("blue.dat","w");
    
    for(short i=0;i<953;i++)
    {
        for(short j=0;j<1268;j++)
        {
            if(j==1267)
    {
    fprintf(frw,"%hd",red[i][j]);
    fprintf(fbw,"%hd",blue[i][j]);
    fprintf(fgw,"%hd",green[i][j]);
    
    }
    else
    {
        fprintf(frw,"%hd,",red[i][j]);
        fprintf(fbw,"%hd,",blue[i][j]);
        fprintf(fgw,"%hd,",green[i][j]);
       
    }
    
        }
        fprintf(fgw,"\n");
        fprintf(frw,"\n");
        fprintf(fbw,"\n");
    }

    

    fclose(fr);
    fclose(fg);
    fclose(fb);
    fclose(fbw);
    fclose(frw);
    fclose(fgw);
    
}
/**
 * @brief This methods gives the pixel value of input and output file at particular coordinate
 */
void pixel_value()
{

 short x,y;
    printf("Enter the coordinates x:\n");
    scanf("%hd",&x);
    printf("Enter the coordinates y:\n");
    scanf("%hd",&y);
  
  FILE *fing,*finr,*finb,*foutg,*foutr,*foutb;
 finb=fopen("Blue.dat","r");
    fing=fopen("Green.dat","r");
    finr=fopen("Red.dat","r");
 foutg=fopen("green.dat","r");
    foutr=fopen("red.dat","r");
    foutb=fopen("blue.dat","r");
  short ag[953][1268];
  short ar[953][1268];
  short ab[953][1268];


   for(short i=0;i<953;i++)
    {
        for(short j=0;j<1268;j++)
        {
     fscanf(fing,"%hd,",&ag[i][j]);
     fscanf(finr,"%hd,",&ar[i][j]);
     fscanf(finb,"%hd,",&ab[i][j]);
    
        }
    }
    
    printf("The RGB value of input file is:\n");
    printf("R:%hd\t",ar[x-1][y-1]);
    printf("G:%hd\t",ag[x-1][y-1]);
    printf("B:%hd\n",ab[x-1][y-1]);

    for(short i=0;i<953;i++)
    {
        for(short j=0;j<1268;j++)
        {
     fscanf(foutg,"%hd,",&ag[i][j]);
     fscanf(foutr,"%hd,",&ar[i][j]);
     fscanf(foutb,"%hd,",&ab[i][j]);
    
        }
    }

     printf("The RGB value of output file is:\n");
    printf("R:%hd\t",ar[x-1][y-1]);
    printf("G:%hd\t",ag[x-1][y-1]);
    printf("B:%hd\n",ab[x-1][y-1]);

    
    
  




    fclose(fing);
    fclose(finr);
    fclose(finb);
    fclose(foutg);
    fclose(foutr);
    fclose(foutb);
    

 }