#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Asuure that used well
    if (argc < 2)
    {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    FILE *pf = NULL;
    FILE *phelper = fopen("helper.txt", "w+");
    char *line = NULL;
    size_t strlenght = 0;

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
            // Loop for each line in the file
            while (getline(&line, &strlenght, pf) != EOF)
            {
                // Put all the lines for all the files in one file
                fprintf(phelper, "%s", line);
            }
            fclose(pf);
        }
    }

    rewind(phelper);
    char prev_char = EOF;
    char current_char;
    __uint64_t count = 0;

    // Loop on each char in the helper file
    while ((current_char = (char)fgetc(phelper)) != EOF)
    {
        if (current_char == prev_char) // Same char
        {
            count++;
        }
        else // New char
        {
            if (prev_char != EOF)
            {
                // Write the count of the char
                fwrite(&count, sizeof(int), 1, stdout);
                
                // Write the char itself
                putchar(prev_char);
            }
            prev_char = current_char;
            count = 1;
        }
    }

    // Write the last character sequence
    if (prev_char != EOF)
    {
        fwrite(&count, sizeof(int), 1, stdout);
        putchar(prev_char);
    }

    // Free resources
    fclose(phelper);
    remove("helper.txt");
    phelper = NULL;
    exit(0);
}
