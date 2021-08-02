#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *nums;
	int x;
	int i;
       
	nums = fopen("nums.txt", "w+");
	x = atoi(argv[1]);
	fprintf(nums, "Initial number: %d\n", x); 

	int counter = 0;
	int digits[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	int firstDigit;
	int max = x; 
	int numSum = 0;

	while (x != 1) {
		x = (x % 2) ? 3*x+1 : x/2;
		counter++;
		numSum += x;

		if (x > max) max = x;

		firstDigit = x;
		while (firstDigit >= 10) firstDigit /= 10;

		switch(firstDigit) {
			case 1:
				digits[0]++;
				break;
			case 2:
				digits[1]++;
				break;
			case 3:
				digits[2]++;
				break;
			case 4:
				digits[3]++;
				break;
			case 5:
				digits[4]++;
				break;
			case 6:
				digits[5]++;
				break;
			case 7:
				digits[6]++;
				break;
			case 8:
				digits[7]++;
				break;
			case 9:
				digits[8]++;
				break;
			default:
				break;
		}

		fprintf(nums, "%d\n", x); 

	}

	printf("Number: %d\n", x);
	printf("Amount of steps: %d\n", counter);
	printf("Highest point: %d\n", max);
	printf("Average value: %.1f\n", (float)numSum/counter+1);

	int digitSum = 0;
	for (i = 0; i < 9; i++) digitSum += digits[i];

	printf("\nLeading digit (percentage):");
	for (i = 0; i < 9; i++) {
		float percentage = ((float)digits[i] / (float)digitSum) * 100;
		printf("\n%d (%4.1f%%)| ", i+1, percentage);

		for (percentage; percentage >= 0.5; percentage -= 1.0f) {
			printf("=");
		}
	}
	printf("\n");

	fclose(nums);

	return 0;
}
