#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isSafe(int* report)
{
    /* 0: Increasing, 1: Decreasing */
    int decreasing = report[0] < report[1];

    int difference;
    for(int i = 0; i < 7; i++)
    {
        if(report[i] == 0 || report[i+1] == 0)
            return 1;

        /* check if increasing or not */
        if(!((report[i] < report[i+1]) == decreasing) || report[i] == report[i+1])
            return 0;

        difference = report[i] - report[i+1];
        if(difference < 0)
		{
			difference *= -1;
		}

        if(difference > 3)
            return 0;
    }

    return 1;
}

void remove_element(int *array, int index, int array_length)
{
   int i;
   for(i = index; i < array_length - 1; i++) array[i] = array[i + 1];

    array[array_length - 1] = 0;
}

int problemDampener(int* report)
{
    /* This is gonna be really shit and inefficient but I'm too tired to care */
    int tmp[8];
    for(int j = 0; j < 8; j++)
    {
        memcpy(tmp, report, 8 * sizeof(report[0]));
        remove_element(tmp, j, 8);
        if(isSafe(tmp))
            return 1;
    }

    return 0;
}

int main()
{
	FILE *file;
	char* line = NULL;
	size_t len = 0;
	ssize_t read;

	file = fopen("reports.txt", "r");
	if(file == NULL)
	{
		printf("File didn't open");
		return 1;
	}

    int reports[1000][8] = {0};

	char* res;
    int tmp;
    int i = 0;
    int j = 0;
	while((read = getline(&line, &len, file)) != -1)
	{
        j = 0;
		res = strtok(line, " ");
		while(res != NULL)
        {
		    if((tmp = atoi(res)))
            {
                reports[i][j] = tmp;
                j++;
			}	
			
		    res = strtok(NULL, " ");
        }

        i++;
	}

    int noSafeReports = 0;
    for(int i = 0; i < 1000; i++)
    {
        if(isSafe(reports[i]))
            noSafeReports++;
    }

    printf("Number of safe reports: %d\n", noSafeReports);

    int noNewSafeReports = 0;
    for(int i = 0; i < 1000; i++)
    {
        if(isSafe(reports[i]))
        {
            noNewSafeReports++;
        }
        else
        {
            /* Inital report not safe */
            noNewSafeReports += problemDampener(reports[i]);
        }
    }

    int test[8] = {1, 2, 3, 4, 5, 6, 0, 0};
    remove_element(test, 0, 8);
    for(int i = 0; i < 8; i++)
    {
        printf("%d ", test[i]);
    }

    printf("Number of new safe reports: %d\n", noNewSafeReports);
}
