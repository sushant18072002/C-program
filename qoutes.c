#include <stdio.h>
#include <string.h>
void qoutes_tag(char word[],char filename[]){
     FILE *fpr;
	int ii=0,tt=0,i,tag_flag=1,entry_flag=0,zz=0;
	char tag[3000],temp[3000],temp2[3000];
     char ch,k;
     fpr = fopen(filename, "r");
     if (fpr== NULL)
     {
          puts("Issue in opening the Output file");
     }
    while((ch=getc(fpr)) != EOF){	zz++;
    	  if(ch=='{'){
    	  	tag_flag=0;
    	  	entry_flag=1;
		  }
		  else if(ch=='}'){
		  	tag[0]='\0';
		  	ii=0;
		  	tag_flag=1;
    	  	entry_flag=0;
		  }
		  else if(ch=='#'){
		  	if(!strcmp(word,tag)){
		  	  printf("~~~~~~~~~~%s~~~~~~~~~~ \n",temp);
		  		break;
			}
		  	strcpy(temp2,word);
		  	temp2[3]=temp[3]='\0';
		  	if(!strcmp(temp2,temp)){
		  	  qoutes_tag(tag,"quotes.txt");
		  		break;
			  }
		  	temp[0]='\0';
		  	tt=0;
		  }
		  else if(tag_flag==1){
    	    tag[ii++]=ch;
    	    tag[ii]='\0';
    	  }
    	  else if(entry_flag==1&&ch!='\n'){
    	  	temp[tt++]=ch;
    	   	temp[tt]='\0';
		  }
      }
     fclose(fpr);
}
int main()
{
     char str[1000],word[100];
     int i,l,c=0;
     printf("Enter the String ");
     gets(str);
     l=strlen(str);
     str[strlen(str)]=' ';
     for(i=0;i<=l;i++){
          if(str[i]==' '){
          		if(strlen(word)>2)
          		qoutes_tag(word,"tag.txt");
               word[0]='\0';
               c=0;
          }
          else 
          word[c++]=str[i];
          word[c]='\0';
     }
     return 0;
}
