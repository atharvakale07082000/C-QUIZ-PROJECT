#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
    // opening both file in read only mode

    FILE *fp1 = fopen("ANSWER.txt", "r");
    FILE *fp2 = fopen("USER.txt", "r");
    FILE *fp3 = fopen("helen.txt", "w");
    char ch1 =fgetc(fp1);
    char ch2 =fgetc(fp2);

    if (fp1 == NULL || fp2 == NULL)
    {
      clrscr();
       printf("Error : Files not open");
       exit(0);
    }


    // error keeps track of number of errors
    // line keeps track of error line
    int error = 0,  line = 1, score=0;
    clrscr();
    // iterate loop till end of file
    while (ch1 !=EOF && ch2 !=EOF)
    {

	if (ch1 =='\n'&& ch2=='\n')
	{
	    line++;
//	    fputc(line,fp3);
	}

	// if fetched data is not equal then
	// error is incremented
	if (ch1 != ch2)
	{
  //	    error++;
    //	    printf("\nhard question Number : %d ", line);
	    fprintf( fp3,"%d\n",line);

	}

	// fetching character until end of file
	ch1 = fgetc(fp1);
	ch2 = fgetc(fp2);
    }

  //  printf("\nTotal Errors : %d", error);
 //   score=5-error;
   // printf("\nYour score   : %d",score);


 // closing both file
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    getch();
    return 0;

}