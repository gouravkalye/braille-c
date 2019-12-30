#include<stdio.h>
#include<string.h>
#include <stdint.h>
#include "braille.h"

uint8_t charPerLine[MAX_LINE][MAX_CHAR];

uint8_t curLineNo = 0;
uint8_t curCharNo = 0;

void PrintString(void)
{
    uint8_t lineNo = 0;
    uint8_t charNo = 0;
    
    for(lineNo;lineNo <= MAX_LINE - 1;lineNo++)
    {
        for(charNo;charNo <= MAX_CHAR - 1;charNo++)
        {
            if(charPerLine[lineNo][charNo] == 1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
            //printf("%x ",charPerLine[lineNo][charNo]);
            if(charNo%2 != 0)
            {
               printf(" "); 
               // add space between two letter
            }
        }
        charNo = 0;
        printf("\n");
        // move to next line of letter
    }
}

void ParseString(char* string)
{
    uint8_t i = 0;
    uint8_t iteration = 0;
    uint8_t blockSize = MAX_CHAR/2;
    uint16_t len = 0;
    len = strlen(string);
    iteration = len/blockSize;
    uint16_t currPos = 0;
    uint16_t lastPos = 0;
    char buff[MAX_CHAR];
    printf("len: %d, iteration: %d\n\n",len,iteration);
    for(i=0;i<=iteration;i++)
    {
        strncpy(buff,&string[currPos],blockSize);
        currPos=currPos+blockSize;
        EncodeString(buff);
        PrintString();
        curLineNo = 0;
        curCharNo = 0;
        ClearCharArray();
        printf("\n\n");
    }
}

void ClearCharArray(void)
{
    memset(charPerLine, 0, sizeof(charPerLine[0][0]) * MAX_LINE * MAX_CHAR);
}

void FillCharArray(uint8_t a1,uint8_t a2,uint8_t b1,uint8_t b2,uint8_t c1,uint8_t c2)
{
    charPerLine[curLineNo][curCharNo] = a1;
    curLineNo++;
    charPerLine[curLineNo][curCharNo] = b1;
    curLineNo++;
    charPerLine[curLineNo][curCharNo] = c1;
    
    curLineNo = 0;
    curCharNo++;
    
    charPerLine[curLineNo][curCharNo] = a2;
    curLineNo++;
    charPerLine[curLineNo][curCharNo] = b2;
    curLineNo++;
    charPerLine[curLineNo][curCharNo] = c2;
    
    curLineNo = 0;
    curCharNo++;
    
}

void EncodeString(char* string)
{
    uint16_t len = 0;
    uint16_t i = 0;
    len = strlen(string);
    for(i=0;i<=len;i++)
    {
        EncodeChar(string[i]);
    }
}

void EncodeChar(char curChar)
{
    switch(curChar)
    {
        case 'A':
        case 'a':
            FillCharArray(CHAR_A);
        break;
        
        case 'B':
        case 'b':
            FillCharArray(CHAR_B);
        break;
        
        case 'C':
        case 'c':
            FillCharArray(CHAR_C);
        break;
        
        case 'D':
        case 'd':
            FillCharArray(CHAR_D);
        break;
        
        case 'E':
        case 'e':
            FillCharArray(CHAR_E);
        break;
        
        case 'F':
        case 'f':
            FillCharArray(CHAR_F);
        break;
        
        case 'G':
        case 'g':
            FillCharArray(CHAR_G);
        break;
        
        case 'H':
        case 'h':
            FillCharArray(CHAR_H);
        break;
        
        case 'I':
        case 'i':
            FillCharArray(CHAR_I);
        break;
        
        case 'J':
        case 'j':
            FillCharArray(CHAR_J);
        break;
        
        case 'K':
        case 'k':
            FillCharArray(CHAR_K);
        break;
        
        case 'L':
        case 'l':
            FillCharArray(CHAR_L);
        break;
        
        case 'M':
        case 'm':
            FillCharArray(CHAR_M);
        break;
        
        case 'N':
        case 'n':
            FillCharArray(CHAR_N);
        break;
        
        case 'O':
        case 'o':
            FillCharArray(CHAR_O);
        break;
        
        case 'P':
        case 'p':
            FillCharArray(CHAR_P);
        break;
        
        case 'Q':
        case 'q':
            FillCharArray(CHAR_Q);
        break;
        
        case 'R':
        case 'r':
            FillCharArray(CHAR_R);
        break;
        
        case 'S':
        case 's':
            FillCharArray(CHAR_S);
        break;
        
        case 'T':
        case 't':
            FillCharArray(CHAR_T);
        break;
        
        case 'U':
        case 'u':
            FillCharArray(CHAR_U);
        break;
        
        case 'V':
        case 'v':
            FillCharArray(CHAR_V);
        break;
                
        case 'W':
        case 'w':
            FillCharArray(CHAR_W);
        break;
                
        case 'X':
        case 'x':
            FillCharArray(CHAR_X);
        break;
                
        case 'Y':
        case 'y':
            FillCharArray(CHAR_Y);
        break;
                
        case 'Z':
        case 'z':
            FillCharArray(CHAR_Z);
        break;
        
        case ' ':
            FillCharArray(CHAR_SP);
        break;
        
    }
}



