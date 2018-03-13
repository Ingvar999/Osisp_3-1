#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc != 4)
		printf("Неверное число параметров");
	else
	{
		int K = atoi(argv[1]), N = atoi(argv[2]), n = atoi(argv[3]);
		int count = n * K, stat;
		char bufi[10], bufj[10];
		for (int i = 0; i<K; ++i)
			for (int j = 0; j<n; ++j)
				if (fork() == 0)
				{
					snprintf (bufi, sizeof(bufi), "%d",i);
					snprintf (bufj, sizeof(bufj), "%d",j);
					execl("31.out", "31.out", argv[3], bufi, bufj, argv[2], 0);
				}
		while (count-- > 0)
			wait(&stat);
		
		FILE *in = fopen("temp~", "r");
		FILE *out = fopen("result.txt", "w");
		float temp, result;
		for (int i = 0; i<K; ++i)
		{
			result = 0;
			for (int j = 0; j<n; ++j)
			{
				fseek(in, (i*n + j)*sizeof(float), SEEK_SET);
				fread(&temp, sizeof(float), 1, in);
				result += temp;
			}
			fprintf(out, "%.4f\n", result);
		}
		fclose(in);
		fclose(out);
		printf("done\n");
	}
	return 0;
}
