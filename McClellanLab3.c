/*
Alex McClellan
Dr. Shore
CSC-2410
4 February 2021

This program converts real numbers into hexadecimal values.
To compile, use: gcc McClellanLab4.c
To run, use: ./a.out
*/

#include<stdlib.h>
#include<stdio.h>

int main()
{
	//Variables
	float value = 0xAABBCCDD;

	//User input
	printf("This program converts real numbers into hexadecimal values.\n");
	printf("Please enter the value you would like to convert:\n");
	scanf("%f", &value);
	
	//Pointer to the address of value
	char *p = (char *) &value;

	//Loop to print hexadecimal value
	printf("Hexadecimal value: ");
	p--;

	for (int i = 0; i < sizeof(value); i++)
	{
		printf("%02hhX", *p);
		p += sizeof(value) - 1;
	}
	printf("\n");

	return 0;
}
