//Ryan Murphy
//Data Structures
//Project 1

#include <stdio.h>
#include <stdlib.h>

float average;

int main(int argc, char *argv[])
{
	//Displays the welcome message.
	printf ("\nWelcome to the Averaging Program!\n");

	float average;
    int i = 0;
    float total = 0;
	//Calculates the total.
    for( i = 1; i < argc; i++ )
	{
        total += atoi( argv[ i ] );
    }
	//This forumula finds the average.
	argc - 1;
	average = total / (argc);
	//If statement checks for user input/parameters.
	if(argc == 1){
		printf ("\nYou didnt enter any integers!\n");
		printf ("Example: Type test.exe 1 2 3\n");
		printf ("Please try again.\n\n");
		printf ("Press any key to exit\n");
	}
	//Else statement will display the successful average.
	else{
	printf ("Success! You now have an Average!\n");
    printf( "The Average is: %.02f\n\n", average );
	printf("Press any key to exit.\n");
	}

    getchar();	
  return 0;
}
