//This is the C file for testing Multithreading in C

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>



void* color(void* v); 

void* color(void* v){
	int* num = (int*)v;  
	printf("Here: %d\n", *num); 
	
	return NULL; 
}

int main(){
	pthread_t thread;

	int i = 0; 
	
	for(i = 0; i < 5; i++){
		
		pthread_create(&thread, NULL, color, &i);
		pthread_join(thread,NULL);
	}
	int in; 

	//pthread_exit(&thread); 

	return 0; 
}
