#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include <sys/shm.h>

int main(){
 
 char name[30];
 char rollno[20];
 char email[30]; 
 int opt;

 printf("Select a option from below \n\n");
  
 printf("Press 1 to Add a Student \n");
 printf("Press 2 to Read Student Record \n");
 printf("Press 3 to Delete Student Record \n");
 scanf("%d",&opt);

 while(opt<1 || opt>3){
  printf("Wrong option selected. Select again: \n");
   scanf("%d",&opt);
}

 if(opt==1){
       FILE *file = fopen("file.txt","w");
       if(file){
       printf("Enter your details \n");
       int i=0;
       while(i<3){
       printf("Enter the name \n");
         scanf("%s",name);

       printf("Enter the roll number \n");
         scanf("%s",rollno);

       printf("Enter the email \n");
         scanf("%s",email);
            
            fputs("Name: ",file);
            fputs(name,file);
            fputs("  ",file);
            fputs("Roll No: ",file); 
            fputs(rollno,file);
            fputs("  ",file);
            fputs("Email: ",file); 
            fputs(email,file);
            fputs("\n",file);
    
       if(i<2)
       printf("Enter the details of your classmate \n");
       i++;
    }
    fclose(file); 
  }
  else  
     printf("Cannot open file \n");
}
 if(opt==2){
 int read;
 printf("Press 0 to read your record \n");
 printf("Press 1 or 2 to read your classmates record \n");
   scanf("%d",&read);   

 if(read==0){
    char c[100]="";
    FILE *file = fopen("file.txt","r");
       if(file){
       fgets(c,100,file);
       puts(c);
       }
  fclose(file);
}  
 if(read>=1){
  char c[100]="";
  char junk[50]="";
  int i=0;      
    FILE *file = fopen("file.txt","r");
       if(file){
    while(i!=read){
    fgets(junk,50,file);
    i++;
     }
       fgets(c,100,file);
       puts(c);
    }
  fclose(file);
   } 

 }

if(opt==3){
 int del;
 printf("Press 0 to delete your record \n");
 printf("Press 1 or 2 to delete your classmates record \n");
   scanf("%d",&del);

     char c[100]="";
     int i=0;
     char junk[50]="";
    FILE *temp = fopen("temp.txt","w");
       if(temp){
    FILE *file = fopen("file.txt","r");
       if(file){
      while(!feof(file)){
       if(del!=i){
       fgets(c,100,file);  
       fputs(c,temp);
         }
        else
         fgets(junk,50,file);
        i++;
        memset(c,0,100);
        }
        
      }
    fclose(file);
  }
   fclose(temp);

  rename("temp.txt","file.txt");
}

return 0;
}
