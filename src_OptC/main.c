/*
This is a tmp main file
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>



//The lookup table that takes x bits of the huffman encoded input, and then gets the appropriate code for that input.
static const int lookup[8] =
	{ 0b0100000100000001, 0b0100000100000001, 0b0100000100000001, 0b0100000100000001, 
	  0b0100001000000010, 0b0100001000000010, 0b0100001100000011, 0b0100010000000011
	};

//This is the length that is "shaved" off the front of the input to determin what letter it is.
static const int huffBinLength = 3;

/*
void printbits(char outData[100], FILE *ptr_OutFile) {
   fputs(outData,ptr_OutFile);
}*/

int main(int argc, char *argv[]){

    //unsigned int tmp;
    
    unsigned int shift;
    unsigned int shift2 = 0;
    unsigned int count = 29;
    unsigned int tableEntry=0;
    unsigned int character;
    unsigned int size = 1;
	
    FILE *ptr_File;
    FILE *ptr_OutFile;
    system("pwd");
    ptr_File = fopen("encoded.dat","rb");
    if (!ptr_File)
            {
            	    perror("Error");
                    printf("Unable to open file!");
                    ptr_File = NULL;
                    exit(0);
            }
    ptr_OutFile = fopen("DecodedOutput.txt","w");
    

    char outData[100] = "";
    outData[99] = "\0";
    char * q = outData[0];
    unsigned int outDataCount = 0;
    unsigned char tmpData;
    unsigned int buffer = 0;
    unsigned int buffer2 = 0;
    unsigned char tmp;
    int t = sizeof(outDataCount);
    unsigned int overflow = 0;
    shift = 0;
    int read = 1;
    size = fread(&buffer,sizeof(char),3,ptr_File);
    size = size << 3;
    buffer = buffer << 8;
    //tmpData = buffer;
    while(size){

        //set temp data = to buffer and shift to only get key length bits
        tmpData = buffer >> 29; //check this later
        //Do the lookup
        tableEntry = lookup[tmpData];
        //Get the character in the first 8 bits
        character = tableEntry >>8;
        outData[outDataCount] = (char) character;
        //sprintf(outData+outDataCount,"%c",character);
        outDataCount++;
        //printf("%c\n", character);
        shift = tableEntry & 0b0000000011111111;
        shift2 +=shift;
        //We don't know how much remains in buffer so need to be careful
        //Now read in new data
        if(shift2 >= size+overflow-3){
            buffer2 = buffer << shift;
            overflow += 24 - shift2;
            buffer = 0;
            size = fread(&buffer,sizeof(char),3,ptr_File);
            size = size << 3;
            //tmp = tmp >> (8-shift);
            buffer = buffer2|(buffer << (8-overflow+24-size));
            shift2 = 0;
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
        //fputs(outData,ptr_OutFile);
        printbits(outData, ptr_OutFile);
        outDataCount = 0;
        }





    }
    
    while(buffer)
    {
        tmpData = buffer >> 29; //check this later
        //Do the lookup
        tableEntry = lookup[tmpData];
        //Get the character in the first 8 bits
        character = tableEntry >>8;
        outData[outDataCount] = (char) character;
        //sprintf(outData+outDataCount,"%c",character);
        outDataCount++;
        printf("%c\n", character);
        shift = tableEntry & 0b0000000011111111;
        buffer = buffer << shift;
    }
    outData[outDataCount]='\000';
    fputs(outData,ptr_OutFile);
    
    fclose(ptr_OutFile);
    fclose(ptr_File);
    return 0;
}
