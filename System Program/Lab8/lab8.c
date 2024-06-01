#include <stdio.h>
#include <sys/wait.h>
#include "apue.h"
#include "tellwait.h"

void accumulation(int d_sum);

int main()
{
	FILE *sum;
	int total_sum = 0;
	pid_t pid[5];
	int year = 5, week = 52, day = 7;

	sum = fopen("sum.txt", "w");
	fprintf(sum, "%d\n", 0);
	fclose(sum);

	/**********************************************************/

	TELL_WAIT();

	for (int i = 0; i < 5; i++)
	{
		if ((pid[i] = fork()) < 0)
		{
			perror("fork error");
			exit(EXIT_FAILURE);
		}
		else if (pid[i] == 0)
		{ // Child process
			for (int j = 1; j <= week; j++)
			{
				FILE *file;
				char filename[10];
				sprintf(filename, "%d-%02d.txt", i + 1, j);
				file = fopen(filename, "r");
				if (file == NULL)
				{
					perror("Error opening file");
					exit(EXIT_FAILURE);
				}
				for (int k = 0; k < day; k++)
				{
					int d_sum = 0;
					for (int l = 0; l < 96; l++)
					{
						int value;
						if (fscanf(file, "%d", &value) != 1)
						{
							perror("Error reading file");
							exit(EXIT_FAILURE);
						}
						d_sum += value;
					}
                    WAIT_PARENT(); // Wait for parent process
                    accumulation(d_sum); // Accumulate daily sum to sum.txt
                    TELL_PARENT(getppid()); // Notify parent process  
				}
				fclose(file);
				
			}
			exit(EXIT_SUCCESS);
		}
	}

	for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < week * day; j++)
        {
            TELL_CHILD(pid[i]); // Allow one child to write to sum.txt
        	WAIT_CHILD(); // Wait for child to finish
		}
    }

	/**********************************************************/

	sum = fopen("sum.txt", "r");
	fscanf(sum, "%d", &total_sum);
	printf("Day_Average = %d\n", total_sum / (year * week * day));
	fclose(sum);

	return 0;
}

void accumulation(int d_sum) // Accumulating the daily sum to "sum.txt".
{
	FILE *sum;
	int tmp = 0;

	sum = fopen("sum.txt", "r+");
	fscanf(sum, "%d", &tmp);

	tmp += d_sum;

	rewind(sum);
	fprintf(sum, "%d", tmp);
	fclose(sum);
	
	return;
}


// https://chatgpt.com/share/db0c7805-aac2-4e30-a2c8-45c124881a34
