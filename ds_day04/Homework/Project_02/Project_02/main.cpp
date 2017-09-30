//Ryan Murphy
//Data Structures
//Assignemtn 2

#include<iostream>
#include<iomanip>
#include <time.h>

using namespace std;

//Creates the struct for the Die.
struct RandRoll{
	int Die1;
	int Die2;
};

int main()
{
	RandRoll Rolls[100];//will contain the random rolls
	srand((unsigned) time( 0 ) ); //random-number generator

	int i;
	int Total;
	int DieTotal[14] = {0};

	for (i=0;i<100;i++)//Rolls each die 100 times
	{
		Rolls[i].Die1=(rand() %6+1);
		Rolls[i].Die2=(rand() %6+1);
	}
	for (i=0;i<100;i++)//Adds each die roll to get total
	{
		Total = (Rolls[i].Die1 + Rolls[i].Die2);
		
		switch (Total)//Keeps track of each die roll count.
		{
		case 0: DieTotal[0]++; break;
		case 1: DieTotal[1]++; break;
		case 2: DieTotal[2]++; break;
		case 3: DieTotal[3]++; break;
		case 4: DieTotal[4]++; break;
		case 5: DieTotal[5]++; break;
		case 6: DieTotal[6]++; break;
		case 7: DieTotal[7]++; break;
		case 8: DieTotal[8]++; break;
		case 9: DieTotal[9]++; break;
		case 10: DieTotal[10]++; break;
		case 11: DieTotal[11]++; break;
		case 12: DieTotal[12]++; break;
		}
	}

	cout<<"Dice Results: Total of each roll."<<endl<<endl;

	for(i=1;i<14;i++)//Dispalys the die roll info.
	{
		cout<<"Amount of "<<setw(2)<<i<<" rolls:  "<<setw(2)<<DieTotal[i]<<endl;
	}

	getchar();
	return 0;
}
