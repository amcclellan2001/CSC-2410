/*
Alex McClellan
Dr. Shore
CSC-2410
11 February 2021

This program reads in a file by row and by column. It creates an array from the matrix and prints.
To compile: gcc McClellanLab5.c
To run: ./a.out *FileName*
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#define MAX 1000

void loadMatrixFromFile(char *filename, int matrix[][MAX], int *rows, int *columns);
void dumpToDisplay(int matrix[][MAX], int *rows, int *columns);
int matrixSumRowwise(int matrix[][MAX], int *rows, int *columns);
int matrixSumColwise(int matrix[][MAX], int *rows, int *columns);

int main(int argc, char **argv)
{
	//Variables
	int matrix[MAX][MAX];
	int rows, columns, rowcount, columncount;
	float runtime1, runtime2;
	struct timeval tstart, tend;
	char userinput;

	loadMatrixFromFile(argv[1], matrix, &rows, &columns);
	
	//dumpToDisplay debugging
	if (rows < 4 && columns < 4)
	{
		fprintf(stderr, "The Matrix is too small.\n");
		dumpToDisplay(matrix, &rows, &columns);
		exit(2);
	}

	//Checking rows
	gettimeofday(&tstart, NULL);
	rowcount = matrixSumRowwise(matrix, &rows, &columns);
 	gettimeofday(&tend, NULL);
	runtime1 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/1.e6;

	fprintf(stdout, "Row Count: %d | Run time: %.8lf\n", rowcount, runtime1);

	//Checking columns	
	gettimeofday(&tstart, NULL);
	columncount = matrixSumColwise(matrix, &rows, &columns);
	gettimeofday(&tend, NULL);
	runtime2 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/1.e6;
	
	fprintf(stdout, "Column Count: %d | Run time: %.8lf\n", columncount, runtime2);

	//Printing the Matrix
	fprintf(stdout, "Would you like to print the matrix? Y or N\n");
	fscanf(stdin, "%c", &userinput);

	if (userinput == 'Y')
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				fprintf(stdout, "%8d ", matrix[i][j]);
			}
		}
	}

	return 0;
}

void loadMatrixFromFile(char *filename, int matrix[][MAX], int *rows, int *columns)
{
   //Reading the file
   FILE* data;
 	int r, c;

	data = fopen(filename, "r");
 
	if ((data = NULL))
	{
		fprintf(stderr, "Error: Failed to open %s", filename);
		exit(2);
	}
    
	//int r = malloc(sizeof(int) * MAX);
	//int c = malloc(sizeof(int) * MAX);
	*rows = r;
	*columns = c;

	//Scanning the file
	fscanf(data, "%d %d\n", &r, &c);

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			fscanf(data, "%d", &matrix[i][j]);
		}
	}
	
	fclose(data);
  
}

void dumpToDisplay(int matrix[][MAX], int *rows, int *columns)
{
	//Printing matrix to the screen
	for (int i = 0; i < *rows; i++)
	{
		for (int j = 0; j < *columns; j++)
		{
			fprintf(stdout, "%d ", matrix[i][j]);
		}
	}
}

int matrixSumRowwise(int matrix[][MAX], int *rows, int *columns)
{
	//Checking for row count
	int rowcount;

	for (int i = 0; i < *rows; i++)
	{
		rowcount += matrix[i][0];
	}

	return rowcount;
}

int matrixSumColwise(int matrix[][MAX], int *rows, int *columns)
{
	//Checking for column count
	int columncount;

	for (int i = 0; i < *columns; i++)
	{
		columncount += matrix[0][i];
	}

	return columncount;
}









