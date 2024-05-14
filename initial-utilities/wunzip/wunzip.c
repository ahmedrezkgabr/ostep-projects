#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Asuure that used well
    if (argc < 2)
    {
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }

    FILE *pf = NULL;
    int count = 0;
    char character = 0;
    // Loop for each file passed
    for (int i = 1; i < argc; i++)
    {
        // Open the next file with read operation
        pf = fopen(argv[i], "r");

        if (pf == NULL)
        {
            printf("wzip: cannot open file\n");
            exit(1);
        }
        else // Opened well
        {
            // Loop till the end of the file and
            // Read the next 4-bytes (size of int) as int from the opened file
            while (fread(&count, sizeof(int), 1, pf) != 0)
            {
                // Read the char corresponding to that count
                fread(&character, sizeof(char), 1, pf);

                // Print the char for count-times
                for (int j = 0; j < count; ++j)
                {
                    printf("%c", character);
                }
            }
        }
        fclose(pf);
    }

    exit(0);
}