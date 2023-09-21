#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned long long int factor;
    unsigned long long int value;
    unsigned long long int result;

    file = fopen(argv[1], "r");

    if (file == NULL)
	{
        perror("Error opening file");
        return 1;
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        value = strtoull(line, NULL, 10);
        factor = 2;

        while (factor * factor <= value)
		{
            if (value % factor == 0)
			{
                result = value / factor;
                printf("%llu=%llu*%llu\n", value, result, factor);
                break;
            }
            factor++;
        }

        if (factor * factor > value)
            printf("%llu is a prime number\n", value);
    }

    fclose(file);

    if (line != NULL)
        free(line);

    return 0;
}
