#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *str = NULL;
    size_t STR_LENGTH = 100;
    if (argc == 1)
    {
        // too few arguments to the utility
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }
    if (argc == 2)
    {
        // read from the standard input
        while (getline(&str, &STR_LENGTH, stdin) != EOF)
        {
            if (strstr(str, argv[1]) != NULL)
            {
                // there is a match between the word and the line
                printf("%s", str);
            }
        }
    }
    else
    {
        // Read from files
        for (int i = 2; i < argc; i++)
        {
            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL)
            {
                printf("wgrep: cannot open file\n");
                
                exit(1);
            }
            while (getline(&str, &STR_LENGTH, fp) != EOF)
            {
                if (strstr(str, argv[1]) != NULL)
                    printf("%s", str);
            }

            fclose(fp);
        }
    }
    return 0;
}