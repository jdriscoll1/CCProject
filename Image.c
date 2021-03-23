#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#include "Image.h"

#define WIDTH 2
#define HEIGHT 2

int main(){

 	Frame* f = create_Frame(0); 
 	free_Frame(f); 

}

void* create_Pixel(void* empty){
	//First allocate the pixel
	Pixel* pixel = malloc(sizeof(Pixel)); 
	


    //ssize_t has the ability to return negative values to indicate an error
    //This is the result of the random number 
	int red = chooseRandNum(); 
    int blue = chooseRandNum(); 
    int green = chooseRandNum(); 
	int i; 

	//Then, set the values
	pixel->red = red; 
	pixel->blue = blue; 
	pixel->green = green; 
	
	
	return pixel; 


}
unsigned char chooseRandNum(){
	
	//Open the urand directory
	FILE* randDir; 
	if((randDir = fopen("/dev/urandom", "r")) == NULL){
		printf("/dev/urandom did not open"); 
		exit(0); 
	
	} 
	int value = fgetc(randDir);
	fclose(randDir); 
	return value;
	
}

Frame* create_Frame(int cameraNum){
	//Allocate Space for the Frame
	Frame* frame = malloc(sizeof(Frame));
	frame->cameraNum = cameraNum;
	//This will be determined later
	frame->frameNum = 0; 

	
	//The row
	int r; 
	//The column
	int c; 
	
	pthread_t thread; 
	
	//Create a thread that creates all the pixels at once 
	for(r = 0; r < HEIGHT; r++){
		for(c = 0; c < WIDTH; c++){ 
		
			pthread_create(&thread, NULL, create_Pixel, NULL); 
			pthread_join(thread, (void**)&frame->pixel[r][c] ); 
			
		}
	}
	return frame; 
}

void free_Frame(Frame* frame){
	int r = 0; 
	int c = 0; 
	for(r = 0; r < HEIGHT; r++){
		for(c = 0; c < WIDTH; c++){
			free(frame->pixel[r][c]);  
			
		}
	}
	
	free(frame); 
}
void print_Frame(Frame* frame){
	int r = 0; 
	int c = 0; 
	for(r = 0; r < HEIGHT; r++){
		for(c = 0; c < WIDTH; c++){
			print_Pixel(frame->pixel[r][c]);  
			
		}
	}
}
void print_Pixel(Pixel* p){
	printf("Red: %u\nBlue: %u\nGreen: %u\n", p->red, p->blue, p->green); 
}
