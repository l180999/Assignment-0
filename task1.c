#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[]){

 if(argc==1)
   printf("One argument passed. TRY AGAIN! \n");

else if(argc==2){
 FILE *fp;
 fp=fopen(argv[1], "r");
 char ch;
 int count=0;
 if(fp){
	while (!feof(fp)){
	        ch = fgetc(fp);
	        if(ch>='0' && ch<='9')
                   count++;
	      }
   fclose(fp);

printf("The total number of digits in the file are: ");
printf("%d",count);
printf("\n");

 }
  else
     printf("Error Opening file \n");	   	   
}
else 
    printf("Error more argument passed \n");
}
