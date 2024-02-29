#include <stdio.h>
#include <time.h>


int main ()
{

	int i;
	unsigned int x_hours=0;
	unsigned int x_minutes=0;
	unsigned int x_seconds=0;
	unsigned int x_milliseconds=0;
	unsigned int totaltime=0,count_down_time_in_secs=0,time_left=0;

	clock_t x_startTime,x_countTime;
	count_down_time_in_secs=5;


    x_startTime=clock();
    time_left=count_down_time_in_secs-x_seconds;

       // 	printf("Time left: ");
	while (time_left>0)
	{
		x_countTime=clock();
		x_milliseconds=x_countTime-x_startTime;
		x_seconds=(x_milliseconds/(CLOCKS_PER_SEC))-(x_minutes*60);
		x_minutes=(x_milliseconds/(CLOCKS_PER_SEC))/60;
		x_hours=x_minutes/60;
		time_left=count_down_time_in_secs-x_seconds;


	     //  for(i=0; i<=5; i--)
	     {
		printf("You have %d seconds left",time_left,count_down_time_in_secs);
		delay(999);
		clrscr();
	     }
       //	printf( "\nYou have %d seconds left",time_left,count_down_time_in_secs);
       }


	printf( "\n\n\nTime's out\n\n\n");
	getch();
return 0;
}