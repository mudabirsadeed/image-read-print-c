/* Image reading, doubling, smoothing and printing program */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define MAXWIDTH 80
#define MAXHEIGHT 100

void imgprint (int, int);

void imgread (int,int);
void smooth(int, int);
void arrayprint(int, int, int);
int aaarray[2*MAXWIDTH][2*MAXHEIGHT];
int array[MAXWIDTH][MAXHEIGHT];
void doublesize(int, int, int, int);
/*reads parameters from the input file, calculates some others and uses function imgread on the input file, calls functions doublesize and arrayprint, the input file is a run time encoded image and does not output anything.*/
void main()
{
int width=0;
int height=0;
int grey_levels=0;
int nwidth, nheight,ngrey_levels;

 scanf("%i", &width);
 scanf("%i", &height);
 scanf("%i", &grey_levels);

 nwidth=(width*2)-1;
 nheight=(height*2)-1;
 ngrey_levels = 4;

 imgread(height, width);
 doublesize(nheight, nwidth, height, width);
 smooth(nheight, nwidth);
 smooth(nheight, nwidth);
 smooth(nheight, nwidth);
 arrayprint(nheight, nwidth, ngrey_levels);

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

/*reads the run length encoded input file into array. The parameters passed are the height and width of the image. Does not return a value*/
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
/*uses function imgprint on each pixel in aaarray. Passed the height, width and grey levels of the image. Outputs the content of the array up to the width and height of the image in stdout*/
void arrayprint (int height,int width, int grey_levels)
{
 int x=0;
 int y=0;
 
 for (x=0 ; x < height; x++)
 {
  for (y=0 ; y < width; y++)
  {
    imgprint(aaarray[y][x],grey_levels);
  }
 printf("\n");
 }
}
/*copies the image in array to aaarray while doubling the size of the picture, filling in the gaps with pixels that are gradients of the original pixels. Inputs are height, width, new height and new width. No output*/
void doublesize(nheight, nwidth, height, width)
{
 int x, y;
 
 
/*copies the image in array to aaarray at double the position on both axis (0,0 stays 0,0; 1,1 becomes 2,2 etc.)*/

 for (y=0 ; y < height; y++)
 {
  for (x=0 ; x < width; x++)
  {
   aaarray[2*x][2*y]=array[x][y];
  }
 }
/*converts the old pixels into the new grey level format*/
 for (y=0 ; y < nheight; y++)
 {
  for (x=0 ; x < nwidth; x++)
  {
     if(aaarray[x][y]==1)
      aaarray[x][y]=3;
  }
 }

/*fills in new pixels to the right of each old pixel, minus the edges*/
 for (y=0; y < nheight; y+=2)
  {
   for (x=1; x < nwidth; x+=2)
    {
     aaarray[x][y]=(((aaarray[x+1][y])+(aaarray[x-1][y]))/2); 
    }
  }
 /*fills in new pixels under each old pixel, minus the edges*/
 for (y=1; y < nheight; y+=2)
  {
   for (x=0; x < nwidth; x+=2)
    {
     aaarray[x][y]=(((aaarray[x][y+1])+(aaarray[x][y-1]))/2); 
    }
  }
/*fills in new pixels diagonally down right of each old pixel, minus the edges*/
 for (y=1; y < nheight; y+=2)
  {
   for (x=1; x < nwidth; x+=2)
    {
     {
     aaarray[x][y]=(((aaarray[x][y+1])+(aaarray[x][y-1])+(aaarray[x-1][y])+(aaarray[x+1][y])+2)/4); 
    
     }
    }
  }
}

/*Prints a pixel into array2 that is the average of all its surrounding pixels from aaarray, doing this for each pixel from aaarray. array2 is then printed back into aaarray. Inputs are the doubled height and width of the original image and outputs nothing*/
void smooth(height, width)
 {
  int i, j;
  int array2[2*MAXWIDTH][2*MAXHEIGHT];

for (j=0 ; j < height; j++)
 {
  for (i=0 ; i < width; i++)
  {
   array2[i][j]=4;
  }
 }

  for (j=1; j < height-1; j++)
  {
   for (i=1; i < width-1; i++)
    {
     {
  array2[i][j]=((aaarray[i-1][j-1]+2*aaarray[i-1][j]+aaarray[i-1][j+1]+2*aaarray[i][j-1]+4*aaarray[i][j]+2*aaarray[i][j+1] + aaarray[i+1][j-1] + 2*aaarray[i+1][j]+aaarray[i+1][j+1]+7)/16);
     }
    }
  }

for (j=0 ; j < height; j++)
 {
  for (i=1 ; i < width; i++)
  {
   aaarray[i][j]=array2[i][j];
  }
 }
}
