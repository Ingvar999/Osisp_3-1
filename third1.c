#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#define Pi 3.1416

int main(int argc, char *argv[])
{
	//sleep(1);
	int n = atoi(argv[1]), i = atoi(argv[2]), j = atoi(argv[3]), N = atoi(argv[4]), pid;//это идентификатор процесса (число)
	
	int k = j*2 + 1;
	int sign = (j & 1) * (-2) + 1;
	float x = (float)(2*Pi*i)/N;
	while (x>Pi)
		x -= 2*Pi;
	if (x > Pi/2)
		x = Pi - x;
	if (x < -Pi/2)
		x = -Pi - x;
	long fact = 1;
	float pow = 1;
	for (int l = 1; l <= k; ++l)
	{
		fact *= l;
		pow *= x;
	}
	
	float result = sign * pow / fact;

	printf("%d / %d / %d / %.4f\n", pid = getpid(), i, j, result); //идентификатор процесса, номер ряда Тейлора, номер члена ряда 
	FILE *f = fopen("temp~", "r+");
	fseek(f, (i*n + j)*sizeof(float), SEEK_SET);
	fwrite(&result, sizeof(float), 1, f);
	fclose(f);
	return 0;
}
