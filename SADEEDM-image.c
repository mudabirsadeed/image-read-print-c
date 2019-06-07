/* Image reading and printing program */
#include <stdlib.h>
#include <stdio.h>
#define MAXWIDTH 80
#define MAXHEIGHT 100

void imgprint (int, int);

void imgread (int,int);

void arrayprint(int, int, int);

int array[MAXWIDTH][MAXHEIGHT];
/* uses imgread on the input file, also calls function arrayprint, the input file is a run time encoded image and does not output anything.*/
void main()
{
int width=0;
int height=0;
int grey_levels=0;


 scanf("%i", &width);
 scanf("%i", &height);
 scanf("%i", &grey_levels);
 
 imgread(height, width);
 arrayprint(height, width, grey_levels);

}

/*prints one pixel to stdout. Passed the grey level of the pixel to be printed and the total grey levels in the image. */
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

/*reads the run length encoded input file into the array. The parameters passed are the height and width of the image. Does not return a value*/
void imgread (int height, int width)
{ 
  int t=0;
  int g=0; 
  int i=0;
  int f=0;
  int currentx = 0;
  int currenty = -1;
 for (i=1;i<height*width;i=i+f)
 {
  
  scanf("%i", &t);
  scanf("%i", &f);

  for(g=1;g<=f;g++)
  {
   if (currentx%width==0)
    {
     currenty += 1;
     currentx = 0;
    }
   array[currentx][currenty] = t;
   currentx++;   
  }
 }  
}
/*uses function imgprint on each pixel in the array. Passed the height and width of the image. Outputs the content of the array up to the width and height of the image*/
void arrayprint (int height,int width, int grey_levels)
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
