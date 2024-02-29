#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
void main()
{
int pos;
char number;
char ch;
char ch1;

FILE *fp;
FILE *fp1;
FILE *fp2;
clrscr();
fp=fopen("num.txt","r"); //from this file i am taking number of hard question
fp1=fopen("this.txt","r");// question file
fp2=fopen("cool.txt","w"); // trying to append the question in this file
ch=getc(fp);
ch1=getc(fp1);

while (ch!=EOF)
{
	while (ch!=ch1){
		ch1=getc(fp1);
	}
	while (ch1!='`'){
		fprintf(fp2,"%c",ch1);
		printf("%c", ch1);
		ch1=getc(fp1);

	}
	rewind(fp1);

	getch();
	clrscr();
	ch=getc(fp);
	ch=getc(fp);

}

fclose(fp);
fclose(fp1);
fclose(fp2);
getch();

}

