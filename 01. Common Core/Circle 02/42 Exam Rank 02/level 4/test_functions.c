#include "test_functions.h"

/*
** make_area
** duplicates the read-only 'zone' strings into malloc'd memory
** so we can modify them with 'F'.
*/
char    **make_area(char **zone)
{
    char    **area;
    int     i;
    int     j;
    int     rows;
    int     cols;

    // 1. Count rows
    rows = 0;
    while (zone[rows])
        rows++;

    // 2. Allocate array of pointers (+1 for NULL terminator)
    area = (char **)malloc(sizeof(char *) * (rows + 1));

    i = 0;
    while (i < rows)
    {
        // 3. Count columns for current row
        cols = 0;
        while (zone[i][cols])
            cols++;

        // 4. Allocate memory for the string (+1 for \0)
        area[i] = (char *)malloc(sizeof(char) * (cols + 1));

        // 5. Copy characters
        j = 0;
        while (j < cols)
        {
            area[i][j] = zone[i][j];
            j++;
        }
        area[i][j] = '\0'; // Null-terminate string
        i++;
    }
    area[i] = NULL; // Null-terminate array
    return (area);
}

void    print_tab(char **area)
{
    int i;

    i = 0;
    while (area[i])
    {
        printf("%s\n", area[i]);
        i++;
    }
}