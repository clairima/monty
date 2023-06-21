#include <stdio.h>
#include "monty.h"
#define _GNU_SOURCE

ssize_t getline(char **lineptr, size_t *n, FILE *stream) {
    size_t bufsize = 0;
    int c;
    size_t i = 0;

    if (lineptr == NULL || n == NULL || stream == NULL) {
        return -1;
    }

    if (*lineptr == NULL || *n == 0) {
        *n = 128;
        *lineptr = malloc(*n);
        if (*lineptr == NULL) {
            return -1;
        }
    }

    while ((c = fgetc(stream)) != EOF) {
        if (i >= bufsize - 1) {
            bufsize += 128;
            char *temp = realloc(*lineptr, bufsize);
            if (temp == NULL) {
                return -1;
            }
            *lineptr = temp;
            *n = bufsize;
        }
        (*lineptr)[i++] = c;
        if (c == '\n') {
            break;
        }
    }

    if (i == 0) {
        return -1;
    }

    (*lineptr)[i] = '\0';
    return i;
}


buss_t buss = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	buss.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		buss.content = content;
		counter++;
		if (read_line > 0)
		{
			execute(content, &stack, counter, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
