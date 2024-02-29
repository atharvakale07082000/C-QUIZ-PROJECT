#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
int c,i,ans,cho;
char user_name[50];
char user_password[50];
//char set_password[4][50]={"jagdish","ms mam","quizmania"};
char admin_name[40];char admin_password[40];
FILE *fp1;
char ch1;
char ch4;
FILE *fp4;
FILE *fp2;
char username[250];
char userpassword[200];
char ch2;
char admin_set_password[2][40]={"student","teacher"};
	clrscr();
	printf("1) Login ID\n");
	printf("2) Signup\n");
	printf("3) Quit");
	scanf("%d",&c);
	switch(c){
		case 1:
			printf("\n\n\t\tUSER SIGNUP ");

			fp1 = fopen("JAGDISH.txt", "a");

			if (fp1 == NULL)
			{
			printf("\nUnable to open  file.\n");
			printf("Please check whether file exists and you have write privilege.\n");
			exit(0);
			}
			printf("\nEnter the user name : ");
			fflush(stdin);
			gets(username);
			fputs(username, fp1);
			printf("\nenter the password do you want for login to quiz");
			gets(userpassword);
			fputs(userpassword,fp1);
			fclose(fp1);
			break;

		case 2:


		 // clrscr();
		  printf("user login");

		  printf("\nenter the user name \n");
		  gets(user_name);
		 // clrscr();
		  printf("Hello %s",user_name);
		  printf("\nplease enter your password\n");
		  gets(user_password);



		  fp2=fopen("JAGDISH.txt","r");
		  ch2=getc(fp2);
		  for(i=0; i<10; i++)
		  {
		   if(ch2 != user_password[i]);{
		   printf("invalid password");
		   break;
		  }
		  ch2=fgetc(fp2);
		  }
		  clrscr();
		  printf("\n\t\t!!WELCOME %s TO QUIZ MANIA!!",username);


		  //menu for the user



		     printf("\n Take a quiz        : 8");
		     printf("\n See the top scores : 9");
		     printf("\n To quit            : 10");
		     printf("\n Enter Your Choice  : ");
		     scanf("%d", &ans);
		     switch(ans)
		    {
		     case 8:
		     printf("start the quiz\n");
		     //to create userfile every time
		     FILE *fp3=NULL;
		     char username[250];
		     char userfile[250];
		     printf("enter the username :");
		     scanf("%s",username);
		     sprintf(userfile,"%s.txt", username);
		     fp3=fopen(userfile,"w");
		     fclose(fp3);
		     break;
		     case 9:
		     printf("show the top scores");
		     break;
		     case 10:
		     exit(0);
		     break;
		     default:
		      printf("invalid choice");
		    }

	       break;
			case 3:
		 //admin user name and password
		  clrscr();
		  printf("enter the admin name \n");
		  scanf("%s",admin_name);
		  printf("Hello %s ",admin_name);
		  printf("\nplease enter your password\n");
		  scanf("%s",admin_password);
		  for(i=0; i<3; i++)
		  {
		   if(strcmp(admin_password,admin_set_password[i])==0)
		   break;
		  }
		  if(i==3)
		  printf("\nSorry %S you are not a valid admin user", admin_name );
		  else
		  {
		  clrscr();
		  printf("\n\t\tWELCOME %s To QUIZ MAINIA \n\n\n\n",admin_name);

		  // menu for the admin



		     printf("\n To show question file           : 4");
		     printf("\n To show the top scores          : 5");
		     printf("\n To show how many user gave quiz : 6");
		     printf("\n To quit                         : 7");
		     printf("\n Enter Your Choice  : ");
		     scanf("%d", &cho);
		     switch(cho)
		    {
		     case 4:

			printf("showing question file");
			fp4=fopen("q.txt","r");
			if(fp4==NULL)
			  {
			    printf("cant open file");
			  }
			    ch4 =fgetc(fp4);
				while(ch4!=EOF)
				  {
				      ch4=fgetc(fp4);
				      printf("%s", ch4);
				      fclose(fp4);
				      getch();
				    }

			getch();

		     }
		     break;
		     case 5:
		     printf("showing the top scores");
		     break;
		     case 6:
		     printf("showing user list");
		     break;
		     case 7:
		     exit(0);
		     break;
		  }
	   break;
	   case 4:
	   exit(0);
	   break;
	   default:
	   printf("\nInvalid Choice");
	       }
	   getch();
}

