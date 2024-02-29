#include<stdio.h>
#include<string.h>
#include<conio.h>
struct so
{
	char name[10];
	int marks;
};


void main()
{
	FILE *f=fopen("UID.txt","r");
	int i=0,temp_m,j;
	char temp_n[10];
	struct so s[5];
	clrscr();
	while(!feof(f))
	{
		fscanf(f,"%s %d", &s[i].name, &s[i].marks);
		i++;
	}
	for (i=0;i<4;i++){
		printf("%s : %d\n", s[i].name, s[i].marks);

	}
	i=0;
	for (i=0;i<3;i++){
		for (j=i+1;j<4;j++) {

			if (s[i].marks<s[j].marks){
				s[5].marks=s[i].marks;
				strcpy(s[5].name,s[i].name);
				s[i].marks=s[j].marks;
				strcpy(s[i].name,s[j].name);
				s[j].marks=s[5].marks;
				strcpy(s[j].name,s[5].name);

			}
		}

	}
	for (i=0;i<4;i++){

		printf("%d) %s : %d\n", i+1, s[i].name, s[i].marks);
	}

	//Sort
      	
 
{
   int gd = DETECT, gm, midx, midy;
 
   initgraph(&gd, &gm, "C:\\TC\\BGI");
 
   setcolor(MAGENTA);
   rectangle(0,40,639,450);
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
   setcolor(WHITE);
   outtextxy(275,10,"Pie Chart");
 
   midx = getmaxx()/2;
   midy = getmaxy()/2;
 
    
   
   }
	getch();

}