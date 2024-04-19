#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 128

int main(int argc, char *argv[])
{
    FILE *fp;
    char buffer[BUFFER_SIZE];

    if (argc == 0)
    {
        // too few arguments to the utility
        // fprintf(stderr, "Usage: %s file1 [file2 ...]\n", argv[0]);
        exit(0);
    }
    for (int i = 1; i < argc; i++)
    {
        fp = fopen(argv[i], "r"); // open the ith file in read mode
        if (fp == NULL)
        {
            // if null means cannot open the file
            // fprintf(stdout, "wcat: %s: No such file or directory\n", argv[i]);
            
            printf("wcat: cannot open file\n");
            // skip this iteration
            exit(1);
        }

        while (fgets(buffer, BUFFER_SIZE, fp) != NULL)
        {
            // get data from the file and print it to the stdout
            fprintf(stdout, "%s", buffer);
        }

        // reclose the file
        fclose(fp);
    }

    exit(0);
}