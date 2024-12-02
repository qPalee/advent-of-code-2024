#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr, j, j + 1);
        }
    }
}

int findDifference(int* list1, int* list2)
{
	int sum = 0;
	int difference;
	for(int i = 0; i < 1000; i++)
	{
		difference = list1[i] - list2[i];
		if(difference < 0)
		{
			difference *= -1;
			
		}

		sum += difference;
	}

	return sum;
}

int findSimilarityScore(int* list1, int* list2)
{
	int similarityScore = 0;
	for(int i = 0; i < 1000; i++)
	{
		int counter = 0;
		for(int j = 0; j < 1000; j++)
		{
			if(list1[i] == list2[j])
			{
				counter++; 
			}
		}

		similarityScore += list1[i] * counter;
	}

	return similarityScore;
}

int main()
{
	FILE *file;
	char* line = NULL;
	size_t len = 0;
	ssize_t read;

	int list1[1000] = {0};
	int list2[1000] = {0};

	file = fopen("lists.txt", "r");
	if(file == NULL)
	{
		printf("File didn't open");
		return 1;
	}

	char* res;
	int tmp;
	int counter = 0;
	while((read = getline(&line, &len, file)) != -1)
	{
		res = strtok(line, " ");
		while(res != NULL) 
		{
			if((tmp = atoi(res))){
				if(list1[counter] == 0)
				{
					list1[counter] = tmp;
				}
				else
				{
					list2[counter] = tmp;
				}
			}
			
			res = strtok(NULL, " ");
		}

		counter++;
	}

	bubbleSort(list1, 1000);
	bubbleSort(list2, 1000);

	int sum = findDifference(list1, list2);

	printf("Total Difference: %d\n", sum);

	int similarityScore = findSimilarityScore(list1, list2);

	printf("Similarity Score: %d\n", similarityScore);

	fclose(file);
	if(line)
	{
		free(line);
	}
	return 0;
}