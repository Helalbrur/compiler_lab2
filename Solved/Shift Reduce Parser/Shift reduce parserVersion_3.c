#include<stdio.h>
#include<string.h>
int i=0,j=0,k=0,z=0,length=0;
char stk[15],input[16],act[10],ac[20];
void check();
int main(){
      printf("Given grammar is\nS->S+S\nS->S*S\nS->id\n");
      printf("Enter input string:");
      scanf("%s",&input);
      length=strlen(input);
      strcpy(act,"Shift->");
      puts("stack \t input \t\t action");
      printf("$ \t %s$ \t\t ...",input);
      for(k=0,i=0; j<length; k++,i++,j++)
       {
         if(input[j]=='i' && input[j+1]=='d'){
              stk[i]=input[j];
              stk[i+1]=input[j+1];
              stk[i+2]='\0';
              input[j]=' ';
              input[j+1]=' ';
              printf("\n$%s\t%s$\t%sid",stk,input,act);
              check();
           }
         else{
              stk[i]=input[j];
              stk[i+1]='\0';
              input[j]=' ';
              printf("\n$%s\t%s$\t%ssymbols",stk,input,act);
              check();
           }
       }

   }
void check(){
     strcpy(ac,"Reduce to S");
     for(z=0; z<length; z++)
       if(stk[z]=='i' && stk[z+1]=='d'){
           stk[z]='S';
           stk[z+1]='\0';
           printf("\n$%s\t%s$\t%s",stk,input,ac);
           j++;
         }
     for(z=0; z<length; z++)
       if(stk[z]=='S' && stk[z+1]=='+' && stk[z+2]=='S'){
           stk[z]='S';
           stk[z+1]='\0';
           stk[z+2]='\0';
           printf("\n$%s\t%s$\t%s",stk,input,ac);
           i=i-2;
         }
     for(z=0; z<length; z++)
       if(stk[z]=='S' && stk[z+1]=='*' && stk[z+2]=='S'){
           stk[z]='S';
           stk[z+1]='\0';
           stk[z+1]='\0';
           printf("\n$%s\t%s$\t%s",stk,input,ac);
           i=i-2;
         }
}

/*
S �> S + S
S �> S * S
S �> id
*/
