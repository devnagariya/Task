#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main (){

	FILE *fptr1,*fptr2;
	char filename[100],c ;
	
	//open one file for reading
	fptr1 = fopen("/etc/protocols","r");
	if (fptr1 == NULL){
		printf("Can't open protocols file \n");
		return 0;
	} 

	
	//open one more file
	fptr2= fopen("/home/dev/a.txt","w");
	if (fptr2 == NULL){
		printf("Can't open \n ");
		return 0;
	} 
	
	//Read contents 
	c = fgetc(fptr1);
	while (c !=EOF){
	
		fputc(c,fptr2);
		c = fgetc(fptr1);
	}
	
	printf("\nFile completed copied to another file \n");
	
	fclose(fptr1);
	fclose(fptr2);
	return 0;


}
