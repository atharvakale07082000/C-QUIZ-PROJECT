#include<stdio.h>
#include<conio.h>
#include<string.h>
struct ans
{
	char right[3], choice[3];
	int assign;
};

struct stud
{
	char id[10], password[20];

};
int main()
{
	
	FILE *r, *wr, *admin, *user;
	char get,g;
	struct ans a[10];
	int p,q=0,coun=0;
	struct stud s[20];
	FILE *reg, *test, *fp1;
	int i,choice,str,flag,pass_try=0, difficult;
	char id_ip[10],password_ip[20],ad_id[10],ad_pass[20],quiz=0,q_paper[10];
	char userpassword[20], username[20];
	strcpy(ad_id,"admin");
	strcpy(ad_pass, "adminofquiz");

	new_login:
	clrscr();





	///CHOICES
	printf("1) User login\n");
	printf("2) Admin login\n");
	printf("3) New user\n");
	printf("4) Exit\n\n");
	printf("  Choice: ");
	scanf("%d", &choice);
	///CHOICES






	///NEW USER
	if (choice==3){
	fp1 = fopen("check.txt", "a");

	if (fp1 == NULL)
		{
		printf("\nUnable to open  file.\n");
		printf("Please check whether file exists and you have write privilege.\n");
		getch();
		exit(0);
		}
	printf("\nEnter New User ID: ");
	fflush(stdin);
	gets(username);
	fputs(username, fp1);
	fprintf(reg, " ");
	printf("\nEnter a password: ");
	fflush(stdin);

	gets(userpassword);
	fputs(" ", fp1);
	fputs(userpassword,fp1);
	fprintf(fp1,"\n");
	fclose(fp1);
	goto new_login;
	}
	///NEW USER









	///ADMIN
	if(choice==2){
	clrscr();


	printf("Enter admin password: ");
	fflush(stdin);
	gets(password_ip);
	str=strcmp(ad_pass, password_ip);
	if (str!=0){
		clrscr();
		printf("Wrong Password\n");
		getch();
		goto new_login;
	}
	clrscr();
	printf("ADMIN\n\n");
	printf("1) Set a Test\n");
	printf("2) View Ranking\n");
	printf("3) Users Data\n");
	printf("   \nChoice: ");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			clrscr();
			printf("Difficulty level\n\n");
			printf("1) Easy\n");
			printf("2) Medium\n");
			printf("3) Difficult\n");
			printf("\nChoice: ");
			scanf("%d", &difficult);
			switch(difficult){
				case 1:
					strcpy(q_paper,"easy.txt");
					break;
					
				case 2:
					strcpy(q_paper,"medium.txt");
					break;
					
				case 3:
					strcpy(q_paper,"difficult.txt");
					break;

			}
			clrscr();
			printf("%s",q_paper);
			getch();
			goto new_login;
		}

	getch();
	}
	///ADMIN








	///EXIT
	if (choice==4){
	clrscr();
	printf("Enter Admin Password: ");
	scanf("%s", &password_ip);
	str=strcmp(password_ip,ad_pass);
	if (str==0){
		return 0;
	}
	else{
		clrscr();
		printf("Wrong Password\nExit not allowed");
		getch();
		goto new_login;
		}
	}
	///EXIT









	///USER LOGIN
	if (choice==1){
		clrscr();
		printf("Login ID: ");
		scanf("%s", &id_ip);
		reg=fopen("check.txt", "a+");

		for (i=0;i<10;i++){
			fscanf(reg,"%s %s",&s[i].id,&s[i].password);
			fprintf(test,"%s\n", s[i].id);
		}

		for (i=0;i<10;i++){

			str=strcmp(id_ip, s[i].id);
			if (str==0){
				pass_try=0;
				wrg_p:
				clrscr();
				printf("Password: ");
				scanf("%s", &password_ip);
				flag=1;
				str=strcmp(password_ip, s[i].password);
				if (str==0){
					clrscr();
					printf("Login Successful");
				}
				else{
					printf("Wrong Password");
					pass_try++;
				if (pass_try==3){
					goto new_login;
				}
				goto wrg_p;
				}
			}
		}
		if (flag!=1){
		clrscr();
		printf("User not found");
		getch();
		goto new_login;
		}

		r=fopen(q_paper, "r");
		wr=fopen("answer.txt", "w");

		//This while loop prints questions one by one
		//Takes input from user
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
	
				if ((q+1)>9){
				printf("\n\t    Choice: ");
				}
				else{
				printf("\n\t   Choice: ");
				}
				scanf("%s", &a[q].choice[q]);
	
				fprintf(wr,"%c\n", a[q].choice[q]);
			q++;	
					get=getc(r);
				clrscr();
				printf("\n\n\n\n\n\n\n\n\n\n\t%d) ", q+1);
				continue;
			}
			printf("%c", get);
	
		}
	
	
	
		//This for loop checks if answer is right
		for (q=0;q<11;q++)
		{
				if (a[q].right[q]==a[q].choice[q]){
				}
		}
		printf("\n\nScore: %d", coun) ;
	
		fclose(r);
		fclose(wr);
	
		getch();
			

	}
	fclose(reg);
	getch();


}
