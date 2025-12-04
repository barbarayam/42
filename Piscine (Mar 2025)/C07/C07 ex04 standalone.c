C07 ex04
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
char *ft_convert_base(char *nbr, char *base_from, char *base_to);

// Test helper function
void test_conversion(char *nbr, char *base_from, char *base_to, char *expected) {
    char *result = ft_convert_base(nbr, base_from, base_to);
    
    printf("Converting \"%s\" from base \"%s\" to base \"%s\":\n", nbr, base_from, base_to);
    
    if (result == NULL && expected == NULL) {
        printf("✅ Test passed: Both result and expected are NULL\n");
    } else if (result == NULL) {
        printf("❌ Test failed: Result is NULL, expected \"%s\"\n", expected);
    } else if (expected == NULL) {
        printf("❌ Test failed: Result is \"%s\", expected NULL\n", result);
    } else if (strcmp(result, expected) == 0) {
        printf("✅ Test passed: \"%s\"\n", result);
    } else {
        printf("❌ Test failed: Got \"%s\", expected \"%s\"\n", result, expected);
    }
    
    if (result)
        free(result);
    
    printf("\n");
}

int main(void) {
    printf("=== TESTING FT_CONVERT_BASE ===\n\n");
    
    // Test 1: Decimal to binary
    test_conversion("42", "0123456789", "01", "101010");
    
    // Test 2: Binary to decimal
    test_conversion("101010", "01", "0123456789", "42");
    
    // Test 3: Decimal to hexadecimal
    test_conversion("255", "0123456789", "0123456789ABCDEF", "FF");
    
    // Test 4: Hexadecimal to decimal
    test_conversion("FF", "0123456789ABCDEF", "0123456789", "255");
    
    // Test 5: Negative number
    test_conversion("-42", "0123456789", "01", "-101010");
    
    // Test 6: Zero
    test_conversion("0", "0123456789", "01", "0");
    
    // Test 7: Invalid base_from (duplicate character)
    test_conversion("42", "01234556789", "01", NULL);
    
    // Test 8: Invalid base_to (contains + sign)
    test_conversion("42", "0123456789", "01+", NULL);
    
    // Test 9: Base with special characters
    test_conversion("hello", "helowrd", "0123456789", "42968");
    
    // Test 10: Octal to binary
    test_conversion("52", "01234567", "01", "101010");
    
    return 0;
}
