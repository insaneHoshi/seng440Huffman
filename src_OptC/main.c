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

//struct for data parsing.
struct structFP {
	FILE *ptr_File;
	char tmpData;
	int bitsRead;
};

struct structFP newFP(){
	
	struct structFP myFileParser;
	
	myFileParser.tmpData = " ";
	myFileParser.bitsRead = 0;
	myFileParser.ptr_File = fopen("encoded.dat","rb");
	
	if (!myFileParser.ptr_File)
		{
			printf("Unable to open file!");
			myFileParser.ptr_File = NULL;
		}
	
	return myFileParser;
}

void closeFP(struct structFP myFileParser) {
	fclose(myFileParser.ptr_File);

}

unsigned int getEncodedData(int numBits, struct structFP *myFileParser){
	unsigned int copy = 0;
	if(myFileParser->bitsRead == 0)
	{//initial read
	
	fread(&myFileParser->tmpData,sizeof(char),1,myFileParser->ptr_File);
	
	copy = (int) myFileParser->tmpData;
	copy = copy >>numBits;
	
	myFileParser->bitsRead+=numBits;

	}
	
	return copy;

}

void printbits(char v) {
   for (; v; v >>= 1) 
      putchar('0' + (v & 1));
   
   printf("\n");
}

int main(int argc, char *argv[]){

	unsigned int input = 0b01011011101011011100000000000000;
	//unsigned int tmp;
	unsigned int shift;
	unsigned int count = 29;
	unsigned int tableEntry=0;
	unsigned int character;
	
	FILE *ptr_File;
	
	ptr_File = fopen("encoded.dat","rb");
	
	if (!ptr_File)
		{
			printf("Unable to open file!");
			ptr_File = NULL;
		}
	
	unsigned char tmpData;
	unsigned char buffer;
	unsigned char tmp;
	shift = 0;
	int read = 1;
	fread(&buffer,sizeof(char),1,ptr_File);
	//tmpData = buffer;
	while(read){
		//printbits(tmpData);
		//set temp data = to buffer and shift to only get key length bits
		tmpData = buffer >> 5; //check this later
		//Do the lookup
		tableEntry = lookup[tmpData];
		//Get the character in the first 8 bits
		character = tableEntry >>8;
		printf("%c\n", character);
		//printbits(tmpData);
		//Get the shift value in the last 8 bits
		shift = tableEntry&0b0000000011111111;
                //buffer = buffer << shift;
		
		/*//Do it again because we know we can
		//set temp data = to buffer and shift to only get key length bits
		tmpData = buffer >> 5;
		//Do the lookup
		tableEntry = lookup[tmpData];
		//Get the character in the first 8 bits
		character = tableEntry >>8;
		printf("%c\n", character);
		//printbits(tmpData);
		//Get the shift value in the last 8 bits
		shift += tableEntry&0b0000000011111111;
		
		*/
		//We don't know how much remains in buffer so need to be careful
		tmpData = buffer << shift;
		//Now read in new data
		read = fread(&buffer,sizeof(char),1,ptr_File);
                //tmp = tmp >> (8-shift);
		buffer = tmpData|(buffer >> (8-shift));
                shift = 0;
		
	/*tmp = tmpData;
	
	tmp=tmp>>count;
	//printf("%u\n",tmp);
	
	tableEntry = lookup[tmp];
	character = tableEntry >>8;
	shift = tableEntry&0b0000000011111111;
	
	
	//printf("count: %d ", count);
	printbits(tmpData);
	printf("%c\n", character);
	//printf("%u\n", input);
	tmpData = tmpData << shift;
	//printf("%u\n", input);
	*/
	
	}
	
	fclose(ptr_File);
	return 0;
}



int getLookupTable(){

	

	return 0;
}
