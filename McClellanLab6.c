/*
Alex McClellan
Dr. Shore
CSC-2410
18 February 2021

This program takes hexadecimal values and combines them via a formula.
To compile, type: gcc -g -Wall McClellanLab6.c
To run, type: ./a.out
*/

#include<stdio.h>

int main()
{
	//Variables
	unsigned char A, B, C;
	unsigned char F;

	//User input
	fprintf(stdout, "Enter a value for A: ");
	fscanf(stdin, "%hhX", &A);

	fprintf(stdout, "Enter a value for B: ");
	fscanf(stdin, "%hhX", &B);
	
	fprintf(stdout, "Enter a value for C: ");
	fscanf(stdin, "%hhX", &C);

	//Formula
	F = (A & ~B) | (B & C);

	//Output
	fprintf(stdout, "A=0x%hhX\n", A);
	fprintf(stdout, "B=0x%hhX\n", B);
	fprintf(stdout, "C=0x%hhX\n", C);
	fprintf(stdout, "F=0x%hhX\n", F);

	return 0;
}
		
	
	


