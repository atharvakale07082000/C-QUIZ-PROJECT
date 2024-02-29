#include<stdio.h>
#include<conio.h>
#include<time.h>
struct ans
{
	char right[3], choice[3];
	int assign;
};
void main()
{

	FILE * r, * ;
	int q=0;
	int d;
	char get, user;
	struct ans a[11];
	r=fopen("easy.txt", "r");
	clrscr();

	printf("\n\n\n\n\n\n\n\n\n\n\t%d) ", q+1);
	while((get=getc(r))!=EOF){
		if(get=='#'){
		break;
		}
		if (get=='{'){
			if((q+1)>9){
			printf("\n            ");
			}
			else{
			printf("\n           ");
			}
			continue;
		}
		if (get=='}'){
			printf("\n");
			continue;
		}
		if (get=='?'){
			printf("%c\n", get);
			continue;
		}
		if (get=='$')
		{
			printf("\n");
			get=getc(r);
			if ((q+1)<10)
			{
				printf("\n\t   Correct answer: %c\n", get);
			}
			else{
				printf("\n\t    Correct answer: %c\n", get);
				printf("\n\t    Your answer   :  ", user);
			}

			getch();
			clrscr();
			a[q].right[q]=get;
			continue;
		}
		if (get=='`'){
			if ((q+1)<10)
			{
				printf("\n\t   ");
			}
			else{
				printf("\n\t    ");
			}

			get=getc(r);
		}
		if (get=='*'){
			q++;
			get=getc(r);
			printf("\n\n\n\n\n\n\n\n\n\n\t%d) ", q+1);
			continue;
		}
		printf("%c", get);

		}
	d=clock();
	printf("%d",d);




}