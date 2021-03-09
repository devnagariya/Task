#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jansson.h>


int main()
{
 FILE *sourceFile;
 char ch;
 char key[100];
 char value[100];
 char *s;
 

 sourceFile = fopen("abc.txt", "r");
 
 	
 
 ch = fgetc(sourceFile);
 
 static int counter = 0;
 	
	while (ch != EOF)
 	{
 	
 			if(ch == '\n')
 			counter++;
 			if(counter == 8)
 			break;
 			ch = fgetc(sourceFile);
	 }
		ch = fgetc(sourceFile);
 			 json_t *root=json_object();
        
	while (ch != EOF)
	 {
 	
 		// 1st KEY
		int key_deci = 0;
 		while(ch != EOF)
		{
			if(ch == ' ')
			break;
			key[key_deci] = ch;
			key_deci++;
			ch = fgetc(sourceFile);
		}
               
		// Removing Space
		while(ch != EOF)
		{
			if(ch != ' ')
			break;
 
			ch = fgetc(sourceFile);
		}
		
		// 1st Value
		int des = 0;
 
 		while(ch != EOF)
 		{
 			if(ch == ' ')
 			break;
 			value[des] = ch;
 			des++;
 			ch = fgetc(sourceFile);
 		}
 		json_object_set_new( root , &key , json_string(value));
		 // Removing Space
 		while(ch != EOF)
 		{
 			if(ch != ' ')
 			break;
 
 			ch = fgetc(sourceFile);
 		}
 		
 		for(int i=0; i< sizeof(key);i++)
 			key[i] = '\0';
 		for(int i=0; i< sizeof(value);i++)
 			value[i] = '\0';
                      
 		// 2. KEY
 		key_deci = 0;
 		while(ch != EOF)
 		{
 			if(ch == ' ')
 			break;
 			key[key_deci] = ch;
 			key_deci++;
 			ch = fgetc(sourceFile);
 		}
   		// Removing Space
 		while(ch != EOF)
 		{
 			if(ch != ' ')
 			break;
 
 			ch = fgetc(sourceFile);
 		}
 
 		// Value
 		des = 0;
 		while(ch != EOF)
 		{
 			if(ch == '\n')
 			{
 				ch = fgetc(sourceFile);
 				break;
 			}
 
 			value[des] = ch;		
 			des++;	
 			ch = fgetc(sourceFile);
 		}
 	
   	      			json_object_set_new( root , &key , json_string(value));
	
		for(int i=0; i< sizeof(key);i++)
 			key[i] = '\0';
 			
 		for(int i=0; i< sizeof(value);i++)
 			value[i] = '\0';
                       
 		while(ch != EOF)
 		{
 			if(ch != ' ')
 			break;
 
 			ch = fgetc(sourceFile);
 		}
 
	 }
	 
	 s = json_dumps(root,0);	
	 puts(s);
	 json_object_del(root, key[3]);
 	 json_decref(root);   

 	fclose(sourceFile);
	return 0;
}
