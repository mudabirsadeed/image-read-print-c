/* Image reading program */

#include <stdio.h>

void imgprint (int);
int width=0;
int height=0;
int grey_levels=0;
int total_length=0;
int t=0;
int i=0;
int g=0;
int f=0;
int a=0;

main()
{
 
 scanf("%i", &width);
 scanf("%i", &height);
 total_length=width*height;
 scanf("%i", &grey_levels);

 
 for (i=1;i<=total_length;i=i+f)
 {
  
  scanf("%i", &t);
  scanf("%i", &f);

  for(g=1;g<=f;g++)
  {
   a++;
   imgprint(t);
   if (a%width==0)
   {
     printf("\n");
   }
  }
 }
}


void imgprint (int temp)
{
 switch(temp)
 {
  case 0: 
  printf("#");
  break;
  case 1: 
  printf(".");
  break;
  case 2: 
  printf(" ");
  break;
 }
}

