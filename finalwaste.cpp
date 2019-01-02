#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<time.h>
#include <ctime>
#include <iomanip>
#include<iostream>
int random_number(int min_num, int max_num);
int num;

std::string month[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",

                        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

std::string day[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };


int main(void)
{
	time_t timer;

    tm * time;

    const int BASE_YEAR = 1900;

 

    std::time(&timer);

    time = localtime(&timer);

    std::cout<< day[time->tm_wday] << " "
              << month[time->tm_mon] << " " << time->tm_mday

              << " " << (time->tm_year + BASE_YEAR)<<"\n";
              

    std::cout << "\n \n" << std::setw(2) << std::setfill('0')

              << time->tm_hour << " : " << std::setw(2) << std::setfill('0')

              << time->tm_min << " : " << std::setw(2) << std::setfill('0')
              << time->tm_sec<<"\n\n";   

   
   
   
   
	int end,loop,line;
	
	char str1[100], c;
	
	
	// Generate Random number
	num=random_number(1,18);


	if(!end)
	printf("__________________________________________________________________________");
	printf("\n");
	printf("LEARN A WORD A DAY");
	printf("\n-------------------------------------------------------------------------");
	printf("\n");
	printf("\n");
	

	char file[]="file";

	char snum[5];
	// convert num to string [buf]
	itoa(num, snum, 10);
	strcat(file,snum);	
	strcat(file,".txt")	;
	

	FILE  *fptr = fopen(file,"r");
    if (fptr == NULL)
    {
        printf("\nCannot open file \n");
        exit(0);
    }
 
    // Read contents from file
    c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }
    printf("\n-------------------------------------------------------------------------");
    fclose(fptr);
	
	
	return 0;
}


int random_number(int min_num, int max_num)
{
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    } else {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }

    srand(time(NULL));
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}









