#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void partOne()
{

}

void partTwo()
{

}

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        printf("Invalid arguments");
        return 1;
    }

    int intOperation = atoi(argv[1]);
    
	FILE *file;
	char* line = NULL;
	size_t len = 0;
	ssize_t read;

	file = fopen(".txt", "r");
	if(file == NULL)
	{
		printf("File didn't open");
		return 1;
	}

    /* Parse input into data structure */
	char* res;
	while((read = getline(&line, &len, file)) != -1)
	{
		res = strtok(line, " ");
		while(res != NULL)
        {


		    res = strtok(NULL, " ");
        }

	}

    /* Run function specified in argument */
    switch (intOperation)
    {
        case 1:
            partOne();
            break;

        case 2:
            partTwo();
            break;

        default:
            printf("Invalid argument, must be either 1 or 2.");
            break;
    }

    return 0;
}