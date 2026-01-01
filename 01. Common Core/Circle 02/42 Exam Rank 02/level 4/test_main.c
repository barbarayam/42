#include "test_functions.h"
#include "flood_fill.h"
#include <stdio.h>

int main(void)
{
    char **area;
    
    // --- TEST CASE 1: The Subject Example ---
    printf("\n=== TEST CASE 1 ===\n");
    t_point size = {8, 5};
    t_point begin = {2, 2};
    char *zone[] = {
        "11111111",
        "10001001",
        "10010001",
        "10110001",
        "11100001",
        NULL
    };

    area = make_area(zone);
    printf("Before:\n");
    print_tab(area);
    
    flood_fill(area, size, begin);
    
    printf("After:\n");
    print_tab(area);

    // --- TEST CASE 2: Small Grid (Testing Edge) ---
    printf("\n=== TEST CASE 2 (Tiny) ===\n");
    t_point size2 = {5, 3}; // 5 chars wide, 3 rows high
    t_point begin2 = {0, 0}; // Start at top-left corner
    char *zone2[] = {
        "011",
        "010",
        "000",
        NULL
    };

    char **area2 = make_area(zone2);
    printf("Before:\n");
    print_tab(area2);

    flood_fill(area2, size2, begin2);

    printf("After:\n");
    print_tab(area2);

    return (0);
}