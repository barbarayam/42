// Assignment name  : swap_bits
// Expected files   : swap_bits.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that takes a byte, swaps its halves (like the example) and
// returns the result.

// Your function must be declared as follows:

// unsigned char	swap_bits(unsigned char octet);

// Example:

//   1 byte
// _____________
//  0100 | 0001
//      \ /
//      / \
//  0001 | 0100

unsigned char	swap_bits(unsigned char octet)
{
	unsigned char lower_to_upper;
	unsigned char upper_to_lower;

	lower_to_upper = (octet & 0x0F) << 4;
	upper_to_lower = (octet & 0xF0) >> 4;
	return (lower_to_upper | upper_to_lower);
 }

#include <stdio.h>

 int main (void)
 {
	printf("%d\n", swap_bits('A'));
 }