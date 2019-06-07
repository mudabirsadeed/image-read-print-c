/* Image reading program */
#include <stdlib.h>
#include <stdio.h>
#define MAXWIDTH 80
#define MAXHEIGHT 100
void imgprint (int, int);



void imgread (int,int,int);

void arrayprint(int, int, int, int);
int array[MAXWIDTH][MAXHEIGHT];
 
int main()
{
int width=0;
int height=0;
int grey_levels=0;
int total_length=0;
int t=0;
int i=0;
int g=0;
int f=0;
 scanf("%i", &width);
 scanf("%i", &height);
 total_length=width*height;
 scanf("%i", &grey_levels);
 

 

 for (i=1;i<total_length;i=i+f)
 {
  
  scanf("%i", &t);
  scanf("%i", &f);

  for(g=1;g<=f;g++)
  {
   static int currentx = 0;
   static int currenty = -1;
   if (currentx%width==0)
    {
     currenty += 1;
     currentx = 0;
    }
   imgread(t,currentx,currenty);
   currentx++;   
  }
 }
 arrayprint(0, height, width, grey_levels);
return 0;
}


void imgprint (int temp, int grey_levels)
{
 switch(grey_levels){
  case 3:
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
  break;
 case 2:
   switch(temp)
   {
    case 0: 
    printf("#");
    break;
    case 1: 
    printf(" ");
    break;
   }
  break;
 case 4:
   switch(temp)
   {
    case 0: 
    printf("#");
    break;
    case 1: 
    printf(":");
    break;
    case 2: 
    printf(".");
    break;
    case 3: 
    printf(" ");
    break;
   }
  break;
 }}


void imgread (int temp2,int currentx,int currenty)
{ 
 array[currentx][currenty] = temp2;  
}

void arrayprint (int temp3,int height,int width, int grey_levels)
{
 int x=0;
 int y=0;
 
 for (x=0 ; x < height; x++)
 {
  for (y=0 ; y < width; y++)
  {
    imgprint(array[y][x],grey_levels);
  }
 printf("\n");
 }
}
