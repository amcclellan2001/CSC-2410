/*
Alex McClellan
Dr. Shore
CSC 2410
14 January 2021
Argc/Argv Program
*/


//Note: I keep getting 0 as my largest number, but I cannot figure out why that is

#include<stdlib.h>
#include<stdio.h>

int main(int argc, char* argv[])
{
	//Variables
	int i, x;
	float array[argc], largestnumber;
	
	//Conversion
	for (i = 1; i < argc; i++);
	{
		array[i] = atof(argv[i]);
	}

	printf("This program figures out the largest real numbers from input.\n");
	
	//Computation
	for (x = 1; x < argc; x++);
	{
		if (array[i] > array[i+1]);
		{
			largestnumber = array[i];
		}
	}
	
	//Output
	printf("The largest number is: %.2f\n", largestnumber);

	return 0;
}
