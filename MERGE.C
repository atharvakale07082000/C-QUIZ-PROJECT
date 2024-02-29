#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct login
{
	char id[20];
	char password[20];

};

struct ans
{
	char right[3], choice[3];
	int assign;
};

struct so
{
	char name[10];
	int marks;
};

void main()
{
	int choice, i=0, flag=0, string_comp , q_paper_code, score;
	char id_ip[20], pass_ip[20], admin_password[20], q_paper[10], ch;
	struct login login[6];
	
	FILE *log;
	FILE *ranking;

	main_menu:
	log=fopen("login.txt", "a+");
	
	heading();
	strcpy(admin_password,"adminadmin");


	
	clrscr();
	i=0;
	flag=0;
	choice=main_menu();

	while(i<7)
	{
		fscanf(log, "%s %s", &login[i].id, &login[i].password);
		i++;

	}
	clrscr();
	admin:
	switch(choice) //1) Login  2)Signup  3) Exit  4) Admin
	{
		case 1: //login
			login:
			clrscr();
			gotoxy(36,13);
			printf("ID: ");
			scanf("%s", &id_ip);

			string_comp=strcmp(id_ip, "admin");
			if (string_comp==0)
			{
				choice=4; //switch 4 for admin
				goto admin;

			}

			gotoxy(30, 14);
			printf("Password: ");
			scanf("%s", &pass_ip);
			i=0;
			while(i<7)
			{
				string_comp=strcmp(id_ip, login[i].id);
				if (string_comp==0)
				{
					string_comp=strcmp(pass_ip, login[i]. password);
					if (string_comp==0)
					{
						clrscr();
						gotoxy(34,15);
						printf("User verified");
						flag=1; //User Exist
						getch();
						break;
					}
					else{
						gotoxy(33,15);
						printf("Wrong Password");
						getch();
						flag=2;

					}
				}

				i++;
			}
			if (flag==0)
			{
				gotoxy(31,15);
				printf("User doesn't exist");
				getch();
				goto main_menu;

			}

			// USER LOGIN SUCCESSFUL
			//USER MENU
			clrscr();
			gotoxy(30,11);
			printf("1. Give test");
			gotoxy(30,12);
			printf("2. Previous tests");
			gotoxy(30,13);
			printf("3. Ranking");
			gotoxy(30,15);
			printf("Choice: ");
			scanf("%d", &choice);
			switch(choice)
			{
				case 1:
				{
					ranking=fopen("marks.txt", "a");
					fprintf(ranking,"%s ", id_ip);
					fclose(ranking);
					paper(q_paper_code);
					getch();
					goto main_menu;
				}

				case 2:
				{
					last_papers();
				}
				
				case 3:
				{
					sort();
					
				}
			}
			getch();
			break;

		case 2: //signup
		{
			signup:
			clrscr();
			gotoxy(33,13);
			printf("User ID: ");
			scanf("%s", &id_ip);

			for(i=0; i<7; i++)
			{
				string_comp=strcmp(id_ip, login[i].id);
				if (string_comp==0)
				{
					clrscr();
					gotoxy(28, 13);
					printf("This User ID already exists");
					gotoxy(31,14);
					printf("Enter another User ID");
					getch();
					clrscr();
					goto signup;
				}
			}
			gotoxy(32, 14);
			printf("Password: ");
			scanf("%s", &pass_ip);
			getch();
			fprintf(log,"\n%s %s", id_ip, pass_ip);
			clrscr();
			goto main_menu;

		}
		case 3:
		{
			clrscr();
			gotoxy(31,13);
			printf("Enter admin password");
			gotoxy(36,14);
			scanf("%s", &pass_ip);
			string_comp=strcmp(pass_ip, admin_password);
			if (string_comp!=0)
			{
					clrscr();
					gotoxy(33,13);
					printf("Wrong Password");
					getch();

			}
			return 0;
		}	
		case 4:
		{
			gotoxy(24,14);
			printf("Admin password: ");
			scanf("%s", &pass_ip);
			string_comp=strcmp(pass_ip, admin_password);
			if (string_comp!=0)
			{
				clrscr();
				gotoxy(33,14);
				printf("Wrong Password");
				getch();
				goto login;

			}

			choice=admin_menu(); //1)Set test  2)Ranking  3)Difficult questions
			
			switch(choice)
			{
				case 1:
				{	
					clrscr();
					gotoxy(32,14);
					printf("1. Easy");
					gotoxy(32,15);
					printf("2. Difficult");
					gotoxy(32,17);
					printf("Choice: ");
					scanf("%d", &choice);
					switch(choice)
					{
						case 1:
						{
							q_paper_code=1;
							break;

						}
						case 2:
						{
							q_paper_code=2;
							break;
						}
						
					}
					break;
										
					
				}
				
				case 2:
				{
					sort();			
				}
				
				case 3:
				{
						difficult();				
					
				}
				
			}
			
			goto main_menu;
			
		}	


	}



	getch();
	fclose(log);
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int difficult()
{
    // opening both file in read only mode

    FILE *fp1 = fopen("correct.txt", "r");
    FILE *fp2 = fopen("answer.txt", "r");
    FILE *fp3 = fopen("helen.txt", "w");
    char ch1 =fgetc(fp1);
    char ch2 =fgetc(fp2);
    int line = 1;


    if (fp1 == NULL || fp2 == NULL)
    {
		clrscr();
       printf("Error : Files not open");
       exit(0);
    }


    // error keeps track of number of errors
    // line keeps track of error line
    clrscr();
    // iterate loop till end of file
    while (ch1 !=EOF && ch2 !=EOF)
    {

	if (ch1 =='\n'&& ch2=='\n')
	{
	    line++;
	}

	// if fetched data is not equal then
	// error is incremented
	if (ch1 != ch2)
	{
	//    error++;
	 //   printf("\nhard question Number : %d ", line);
	 printf("%d\n", line);
	 getch();
	    fprintf( fp3,"%d\n",line);
	}

	// fetching character until end of file
	ch1 = fgetc(fp1);
	ch2 = fgetc(fp2);
    }

//    printf("\nTotal Errors : %d", error);
//    score=5-error;
//    printf("\nYour score   : %d",score);


 // closing both file
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    getch();
    return 0;


	
}

int paper(level)
{
	int marks=0, q=0;
	FILE *r, *ranking, *answer, *corr;
	char q_paper[20], ch;
	struct ans a[10];
	clrscr();
	answer=fopen("ANSWER.TXT", "w");
	corr=fopen("correct.txt", "w");
	if (level==1)
	{
		strcpy(q_paper, "easy.txt");
	}
	if (level==2)
	{
		strcpy(q_paper, "difficult.txt");
	}
	r=fopen(q_paper, "r");
	printf("\n\n\n\n\n\n\n\n\n\n\t%d) ", q+1);
	while((ch=getc(r))!=EOF)
	{
		delay(2);
		if(ch=='#')
		{
			break;
		}

		if (ch=='{')
		{
			if((q+1)>9)
			{
				printf("\n            ");
			}
			else
			{
				printf("\n           ");
			}
			continue;
		}

		if (ch=='}')
		{
			printf("\n");
			continue;
		}

		if (ch=='?')
		{
			printf("%c\n", ch);
			continue;
		}

		if (ch=='$')
		{
			printf("\n");
			ch=getc(r);
			fprintf(corr,"%c\n", ch);
			a[q].right[q]=ch;
			continue;
		}

		if (ch=='`'){
			if ((q+1)<10)
			{
				printf("\n\t   ");
			}
			else
			{
				printf("\n\t    ");
			}
			ch=getc(r);
		}
		if (ch=='*')
		{

			if ((q+1)>9)
			{
				printf("\n\t    Choice: ");
			}
			else
			{
				printf("\n\t   Choice: ");
			}
			scanf("%s", &a[q].choice[q]);
			fprintf(answer,"%c\n", a[q].choice[q]);
			q++;
			ch=getc(r);
			clrscr();
			printf("\n\n\n\n\n\n\n\n\n\n\t%d) ", q+1);
			continue;
		}
		printf("%c", ch);


	}
	clrscr();

	q=0;
	marks=0;
	while (q<11)
	{
		if (a[q].choice[q]==a[q].right[q])
		{
				marks++;
		}
		q++;
	}
	gotoxy(34,14);
	printf("MARKS: %d", marks);
	getch();
	ranking=fopen("MARKS.TXT", "a");
	fprintf(ranking, "%d\n", marks);
	fclose(ranking);
	fclose(answer);
	fclose(corr);
}

int admin_menu()
{
	int choice;
	clrscr();
	gotoxy(31,12);
	printf("1. Set a test");
	gotoxy(31,13);
	printf("2. See ranking");
	gotoxy(31,14);
	printf("3. Difficult questions");
	gotoxy(34,15);
	printf("in the test");
	gotoxy(31,17);
	printf("Choice: ");
	scanf("%d", &choice);
	return choice;
}

int heading()
{
	clrscr();

	gotoxy(38, 13);
	cprintf("QUIZ");
	getch();
	
	clrscr();


}

int main_menu()
{
	int choice;
	gotoxy(35,13);
	printf("1. Login");
	gotoxy(35,14);
	printf("2. Sign Up");
	gotoxy(35,15);
	printf("3. Exit");
	gotoxy(35,17);
	printf("Choice: ");
	scanf("%d", &choice);

	return choice;

}

int sort()
{
	FILE *f=fopen("marks.txt","r");
	int i=0,temp_m,j;
	char temp_n[10];
	struct so s[6];
	clrscr();
	while(!feof(f))
	{
		fscanf(f,"%s %d\n", &s[i].name, &s[i].marks);
		i++;
	}
	
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
		gotoxy(30,12+i);
		printf("%d) %s", i+1, s[i].name);
		gotoxy(43,12+i);
		printf(": %d\n", s[i].marks);
	}

	//Sort

	getch();

}

int last_papers()
{
	int ans,q=0;
	FILE *r;
	char get;
	FILE *fp3;
	char ch;
	char name[250];
	char userfile[250];
	char a;
	fp3=fopen("ANSWER.TXT", "r");
	r=fopen("easy.txt", "r");
	a=getc(fp3);
	clrscr();
	
	if(r==NULL){
		printf("cant open the file");
		getch();
	}

	printf("\n\n\n\n\n\n\n\n\n\n\t%d) ", q+1);
	while((ch=getc(r))!=EOF)
	{

		delay(1);
		if(ch=='#')
		{
			break;
		}

		if (ch=='{')
		{
			if((q+1)>9)
			{
				printf("\n            ");
			}
			else
			{
				printf("\n           ");
			}
			continue;
		}

		if (ch=='}')
		{
			printf("\n");
			continue;
		}

		if (ch=='?')
		{
			printf("%c\n", ch);
			continue;
		}

		if (ch=='$')
		{
			printf("\n");
			ch=getc(r);

			if((q+1)>9)
			{
				printf("\n            ");
			}
			else
			{
				printf("\n           ");
			}
			printf("Correct answer: %c", ch);


			continue;
		}

		if (ch=='`'){
			if ((q+1)<10)
			{
				printf("\n\t   ");
			}
			else
			{
				printf("\n\t    ");
			}
			ch=getc(r);
		}
		if (ch=='*')
		{

			if ((q+1)>9)
			{
				printf("\n\t    Your Choice   : ");
			}
			else
			{
				printf("\n\t   Your Choice   : ");
			}
			printf("%c", a);
			a=getc(fp3);
			a=getc(fp3);
			getch();
			q++;
			ch=getc(r);
			clrscr();
			if((q+1)==11)
			{
				break;
			}
			printf("\n\n\n\n\n\n\n\n\n\n\t%d) ", q+1);
			continue;
		}
		printf("%c", ch);


	}
	fclose(fp3);
	fclose(r);


}