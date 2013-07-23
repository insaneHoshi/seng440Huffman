/*
This is a tmp main file
*/
#include <stdio.h>

//The lookup table that takes x bits of the huffman encoded input, and then gets the appropriate code for that input.
static const int lookup[8] =
	{ 0b0100000100000001, 0b0100000100000001, 0b0100000100000001, 0b0100000100000001, 
	  0b0100001000000010, 0b0100001000000010, 0b0100001100000011, 0b0100010000000011
	};

//This is the length that is "shaved" off the front of the input to determin what letter it is.
static const int huffBinLength = 3;

void printbits(unsigned int v) {
   for (; v; v >>= 1) 
      putchar('0' + (v & 1));
   
   printf("\n");
}

int main(int argc, char *argv[]){

	unsigned int input = 0b01011011101011011100000000000000;
	unsigned int tmp;
	unsigned int shift;
	unsigned int count = 29;
	unsigned int tableEntry=0;
	unsigned int character;

	
	while(input != 0)
	{
		tmp = input;
		
		tmp=tmp>>count;
		//printf("%u\n",tmp);
		
		tableEntry = lookup[tmp];
		character = tableEntry >>8;
		shift = tableEntry&0b0000000011111111;
		
		
		//printf("count: %d ", count);
		printbits(input);
		printf("%c\n", character);
		//printf("%u\n", input);
		input = input << shift;
		//printf("%u\n", input);
		
	}
	
	
	return 0;
}



int getLookupTable(){

	

	return 0;
}
