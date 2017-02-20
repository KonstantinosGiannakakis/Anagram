#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(void)
{
	//here is the declaration of the variables
	char  **str, *str2;
	int cols, rows, i, j, k, sum = 0, counter = 0, l = 0;
	int *index;
	char c, ch;

	printf("Give the dimensions of the array (columns x rows) \n");
	scanf_s("%d%d", &cols, &rows);
	
	//here we clear the input from the '\n' character
	while ((c = getchar()) != '\n' && c != EOF) {}
	
	//here we allocate the memory of the MxN dimensions array
	str = (char **)malloc(rows * sizeof(char*));
	if (str == NULL)
	{
		printf("Error! memory not allocated.\n");
		exit(0);
	}

	for (i = 0; i < rows; i++)
	{
		str[i] = (char*)malloc(cols * sizeof(char));
		if (str[i] == NULL)
		{
			printf("Error! memory not allocated.\n");
			exit(0);
		}

	}

	printf("Give the characters\n");
	
	//here the program gets the input from the keyboard and pass it in the str[][] array
	//also when it finds a ' ' (space character), crops it and pass the next letter
	i = 0;
	j = 0;
	while ((ch = getchar()) != '\n' && ch != EOF)
	{
		if (j == cols)
		{
			j = 0;
			i++;
		}

		if (ch != ' ')
		{
			str[i][j] = ch;
			j++;
		}


	}

	printf("The matrix is :\n");
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			printf("%c ", str[i][j]);
		}
		printf("\n");
	}

	//here we allocate memory for the second string --> str2
	str2 = (char *)malloc(cols);
	if (str2 == NULL)
	{
		printf("Error! memory not allocated.\n");
		exit(0);
	}

	//here we allocate the space for the index
	index = (int *)malloc(rows * sizeof(int));
	if (index == NULL)
	{
		printf("Error! memory not allocated.\n");
		exit(0);
	}

	//here is the check for anagrams rows


	for (i = 0; i < rows; i++)
	{
		k = 0;
		for (j = cols - 1; j >= 0; j--)
		{
			str2[k] = str[i][j];
			k++;
		}

		for (j = 0, k = 0; j < cols; j++, k++)
		{
			if (str[i][j] == str2[k])
				sum++;
		}

		if (sum == cols)
		{
			index[l] = i;
			counter++;
			l++;
		}
		sum = 0;
	}

	if (counter == 0)
	{
		printf("There are no rows with anagrams\n");
	}
	else
	{
		printf("%d%% ", counter * 100 / rows);
		printf("(%d/%d) of the matrix rows are anagrams. Those are:\n", counter, rows);
		for (i = 0; i < counter; i++)
		{
			printf("[%d] ", index[i]);
			for (j = 0; j < cols; j++)
			{
				printf("%c ", str[i][j]);
			}
			printf("\n");
		}
	}




	//here we free the memory we allocated before

	for (i = 0; i < rows; i++)
		free(str[i]);
	free(str);
	free(str2);

	return 0;
}
