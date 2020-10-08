#include<stdio.h>
#include<string.h>
#include<stdbool.h>
void main(int argc, char *argv[])
{
 if(argc==1)
   printf("One argument passed. TRY AGAIN! \n");
	
  else if(argc==2){      
       FILE *fp;						
	FILE *fp2;						
	bool flag=0;
	char buff[100]={0};
	fp=fopen(argv[1],"r");
	fp2=fopen("Inverted.txt","a+");
	while(fscanf(fp,"%s",buff)!=EOF)			 
	{
		for(int i=0;buff[i]!='\0';i++)
		{
			if(buff[i]=='a' || buff[i]=='A' || buff[i]=='e' || buff[i]=='E' || buff[i]=='i' || buff[i]=='I' || buff[i]=='o' || buff[i]=='O' || buff[i]=='u' || buff[i]=='U')
			{
				int len=strlen(buff)-1;
				char temp;
				for(int j=0;j<=(len/2);j++)	
				{
					temp=buff[j];
					buff[j]=buff[len-j];
					buff[len-j]=temp;
				}
				break;
			}
		}
			int len=strlen(buff);
			buff[len]=' ';
			buff[len+1]='\0';
			fputs(buff,fp2);
			}
	fclose(fp);
	fclose(fp2);
}
else 
    printf("Error more argument passed \n");
}