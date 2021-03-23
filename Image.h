/*
Filename: Image.h
Name: Jordan Driscoll
Date Created: 3/22/2021
Description: This is the actual image object, it stores all of the methods for images
*/


typedef struct Pixel{
	unsigned char red; 
	unsigned char blue; 
	unsigned char green; 
	
}Pixel;


typedef struct Frame{
 /*The camera from which it was created*/
 int cameraNum; 
 /*The frame number overall*/
 int frameNum; /*Initail - 0. Set in GPU Manager*/
 /*An array of the pixels, each image is 1280x800*/
 Pixel* pixel[1280][800]; 
}Frame; 


/*The function to create a pixel, setting its values ranodmly*/
void* create_Pixel(void* empty); 

/*Opens dev/urandom */
unsigned char chooseRandNum(); 

/*The function that creates a frame, creates a pixel*/
Frame* create_Frame(int cameraNum); 

void free_Frame(Frame* frame);

//Prints a frame
void print_Frame(Frame* frame); 

//Prints a pixel
void print_Pixel(Pixel* p); 


