/*
This is a tmp main file
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <inttypes.h>



//The lookup table that takes x bits of the huffman encoded input, and then gets the appropriate code for that input.
static const int lookup[1024] =
	{ 0b0111011100000110, 0b0111011100000110, 0b0111011100000110, 0b0111011100000110, 0b0111011100000110, 0b0111011100000110, 0b0111011100000110, 0b0111011100000110, 0b0111011100000110, 0b0111011100000110, 0b0111011100000110, 0b0111011100000110, 0b0111011100000110, 0b0111011100000110, 0b0111011100000110, 0b0111011100000110, 
0b0110110100000110, 0b0110110100000110, 0b0110110100000110, 0b0110110100000110, 0b0110110100000110, 0b0110110100000110, 0b0110110100000110, 0b0110110100000110, 0b0110110100000110, 0b0110110100000110, 0b0110110100000110, 0b0110110100000110, 0b0110110100000110, 0b0110110100000110, 0b0110110100000110, 0b0110110100000110, 
0b0110011000000110, 0b0110011000000110, 0b0110011000000110, 0b0110011000000110, 0b0110011000000110, 0b0110011000000110, 0b0110011000000110, 0b0110011000000110, 0b0110011000000110, 0b0110011000000110, 0b0110011000000110, 0b0110011000000110, 0b0110011000000110, 0b0110011000000110, 0b0110011000000110, 0b0110011000000110, 
0b0111100100000110, 0b0111100100000110, 0b0111100100000110, 0b0111100100000110, 0b0111100100000110, 0b0111100100000110, 0b0111100100000110, 0b0111100100000110, 0b0111100100000110, 0b0111100100000110, 0b0111100100000110, 0b0111100100000110, 0b0111100100000110, 0b0111100100000110, 0b0111100100000110, 0b0111100100000110, 
0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 0b0111010000000100, 
0b0110010000000101, 0b0110010000000101, 0b0110010000000101, 0b0110010000000101, 0b0110010000000101, 0b0110010000000101, 0b0110010000000101, 0b0110010000000101, 0b0110010000000101, 0b0110010000000101, 0b0110010000000101, 0b0110010000000101, 0b0110010000000101, 0b0110010000000101, 0b0110010000000101, 0b0110010000000101, 0b0110010000000101, 0b0110010000000101, 0b0110010000000101, 0b0110010000000101, 0b0110010000000101, 0b0110010000000101, 0b0110010000000101, 0b0110010000000101, 0b0110010000000101, 0b0110010000000101, 0b0110010000000101, 0b0110010000000101, 0b0110010000000101, 0b0110010000000101, 0b0110010000000101, 0b0110010000000101, 
0b0110110000000101, 0b0110110000000101, 0b0110110000000101, 0b0110110000000101, 0b0110110000000101, 0b0110110000000101, 0b0110110000000101, 0b0110110000000101, 0b0110110000000101, 0b0110110000000101, 0b0110110000000101, 0b0110110000000101, 0b0110110000000101, 0b0110110000000101, 0b0110110000000101, 0b0110110000000101, 0b0110110000000101, 0b0110110000000101, 0b0110110000000101, 0b0110110000000101, 0b0110110000000101, 0b0110110000000101, 0b0110110000000101, 0b0110110000000101, 0b0110110000000101, 0b0110110000000101, 0b0110110000000101, 0b0110110000000101, 0b0110110000000101, 0b0110110000000101, 0b0110110000000101, 0b0110110000000101, 
0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 0b0110000100000100, 
0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 0b0110111100000100, 
0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 0b0110100100000100, 
0b0111000000000110, 0b0111000000000110, 0b0111000000000110, 0b0111000000000110, 0b0111000000000110, 0b0111000000000110, 0b0111000000000110, 0b0111000000000110, 0b0111000000000110, 0b0111000000000110, 0b0111000000000110, 0b0111000000000110, 0b0111000000000110, 0b0111000000000110, 0b0111000000000110, 0b0111000000000110, 
0b0110011100000110, 0b0110011100000110, 0b0110011100000110, 0b0110011100000110, 0b0110011100000110, 0b0110011100000110, 0b0110011100000110, 0b0110011100000110, 0b0110011100000110, 0b0110011100000110, 0b0110011100000110, 0b0110011100000110, 0b0110011100000110, 0b0110011100000110, 0b0110011100000110, 0b0110011100000110, 
0b0111011000000111, 0b0111011000000111, 0b0111011000000111, 0b0111011000000111, 0b0111011000000111, 0b0111011000000111, 0b0111011000000111, 0b0111011000000111, 
0b0111000100001010, 
0b0110101100001010, 
0b0110101000001001, 0b0110101000001001, 
0b0111101000001001, 0b0111101000001001, 
0b0111100000001001, 0b0111100000001001, 
0b0110001000000110, 0b0110001000000110, 0b0110001000000110, 0b0110001000000110, 0b0110001000000110, 0b0110001000000110, 0b0110001000000110, 0b0110001000000110, 0b0110001000000110, 0b0110001000000110, 0b0110001000000110, 0b0110001000000110, 0b0110001000000110, 0b0110001000000110, 0b0110001000000110, 0b0110001000000110, 
0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 0b0110111000000100, 
0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 0b0010000000000011, 
0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 0b0110010100000011, 
0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 0b0111001100000100, 
0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 0b0111001000000100, 
0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 0b0110100000000100, 
0b0111010100000101, 0b0111010100000101, 0b0111010100000101, 0b0111010100000101, 0b0111010100000101, 0b0111010100000101, 0b0111010100000101, 0b0111010100000101, 0b0111010100000101, 0b0111010100000101, 0b0111010100000101, 0b0111010100000101, 0b0111010100000101, 0b0111010100000101, 0b0111010100000101, 0b0111010100000101, 0b0111010100000101, 0b0111010100000101, 0b0111010100000101, 0b0111010100000101, 0b0111010100000101, 0b0111010100000101, 0b0111010100000101, 0b0111010100000101, 0b0111010100000101, 0b0111010100000101, 0b0111010100000101, 0b0111010100000101, 0b0111010100000101, 0b0111010100000101, 0b0111010100000101, 0b0111010100000101, 
0b0110001100000101, 0b0110001100000101, 0b0110001100000101, 0b0110001100000101, 0b0110001100000101, 0b0110001100000101, 0b0110001100000101, 0b0110001100000101, 0b0110001100000101, 0b0110001100000101, 0b0110001100000101, 0b0110001100000101, 0b0110001100000101, 0b0110001100000101, 0b0110001100000101, 0b0110001100000101, 0b0110001100000101, 0b0110001100000101, 0b0110001100000101, 0b0110001100000101, 0b0110001100000101, 0b0110001100000101, 0b0110001100000101, 0b0110001100000101, 0b0110001100000101, 0b0110001100000101, 0b0110001100000101, 0b0110001100000101, 0b0110001100000101, 0b0110001100000101, 0b0110001100000101, 0b0110001100000101, 
};

int main(int argc, char *argv[]){

    //unsigned int tmp;
    
    unsigned int shift = 0;
    unsigned int total_shift = 0;
    unsigned int tableEntry=0;
    unsigned int character;
    unsigned int size = 0;
    char outData[100] = "";
    unsigned int outDataCount = 0;
    unsigned int tmpData;
    outData[99] = '\000';
    uint64_t buffer = 0;
    uint64_t buffer2 = 0;
    char * point = (char*)&buffer;
    unsigned int overflow = 0;
    
    FILE *ptr_File;
    FILE *ptr_OutFile;
    ptr_File = fopen("alphabet.dat","rb");
    if (!ptr_File)
            {
                        perror("Error");
                    printf("Unable to open file!");
                    ptr_File = NULL;
                    exit(0);
            }
    ptr_OutFile = fopen("DecodedOutput.txt","w");
    

    

    size += fread(point+5,sizeof(char),1,ptr_File);
    size += fread(point+4,sizeof(char),1,ptr_File);
    size += fread(point+3,sizeof(char),1,ptr_File);
    size += fread(point+2,sizeof(char),1,ptr_File);
    size += fread(point+1,sizeof(char),1,ptr_File);
    size += fread(point,sizeof(char),1,ptr_File);
    size = size << 3;
    buffer = buffer << 16;
    //tmpData = buffer;
    while(size){

        //set temp data = to buffer and shift to only get key length bits
        tmpData = buffer >> 54; //check this later
        //Do the lookup
        tableEntry = lookup[tmpData];
        //Get the character in the first 8 bits
        character = tableEntry >>8;
        outData[outDataCount] = (char) character;
        //sprintf(outData+outDataCount,"%c",character);
        outDataCount++;
        //printf("%c\n", character);
        shift = tableEntry & 0b0000000011111111;
        total_shift +=shift;
        //We don't know how much remains in buffer so need to be careful
        //Now read in new data
        if(total_shift >= size+overflow-10){
            buffer2 = buffer << shift;
            overflow += 48 - total_shift;
            buffer = 0;
            size = 0;
            size += fread(point+5,sizeof(char),1,ptr_File);
            size += fread(point+4,sizeof(char),1,ptr_File);
            size += fread(point+3,sizeof(char),1,ptr_File);
            size += fread(point+2,sizeof(char),1,ptr_File);
            size += fread(point+1,sizeof(char),1,ptr_File);
            size += fread(point,sizeof(char),1,ptr_File);
            size = size << 3;
            //tmp = tmp >> (8-shift);
            buffer = buffer2|(buffer << (16-overflow));
            total_shift = 0;
            buffer2 = 0;
        }
        else
        {
            buffer = buffer << shift;
        }

        if(outDataCount == 99 || !size){
        //Output Out Data to a file
                if(!size){
                outData[outDataCount]='\000';
                }
        fputs(outData,ptr_OutFile);
        //printbits(outData, ptr_OutFile);
        outDataCount = 0;
        }





    }
    
    while(buffer)
    {
        tmpData = buffer >> 54; //check this later
        //Do the lookup
        tableEntry = lookup[tmpData];
        //Get the character in the first 8 bits
        character = tableEntry >>8;
        outData[outDataCount] = (char) character;
        //sprintf(outData+outDataCount,"%c",character);
        outDataCount++;
        //printf("%c\n", character);
        shift = tableEntry & 0b0000000011111111;
        buffer = buffer << shift;
    }
    outData[outDataCount]='\000';
    fputs(outData,ptr_OutFile);
    
    fclose(ptr_OutFile);
    fclose(ptr_File);
    return 0;
}



