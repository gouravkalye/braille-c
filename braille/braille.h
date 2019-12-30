#ifndef _BRAILLE_H_
#define _BRAILLE_H_

#define MAX_LINE 3
#define MAX_CHAR 16

#define CHAR_A  1,0,0,0,0,0
#define CHAR_B  1,0,1,0,0,0
#define CHAR_C  1,1,0,0,0,0
#define CHAR_D  1,1,0,1,0,0
#define CHAR_E  1,0,0,1,0,0
#define CHAR_F  1,1,1,0,0,0
#define CHAR_G  1,1,1,1,0,0
#define CHAR_H  1,0,1,1,0,0
#define CHAR_I  0,1,1,0,0,0
#define CHAR_J  0,1,1,1,0,0
#define CHAR_K  1,0,0,0,1,0
#define CHAR_L  1,0,1,0,1,0
#define CHAR_M  1,1,0,0,1,0
#define CHAR_N  1,1,0,1,1,0
#define CHAR_O  1,0,0,1,1,0
#define CHAR_P  1,1,1,0,1,0
#define CHAR_Q  1,1,1,1,1,0
#define CHAR_R  1,0,1,1,1,0
#define CHAR_S  0,1,1,0,1,0
#define CHAR_T  0,1,1,1,1,0
#define CHAR_U  1,0,0,0,1,1
#define CHAR_V  1,0,1,1,1,0
#define CHAR_W  1,0,1,0,1,0
#define CHAR_X  0,1,1,1,0,1
#define CHAR_Y  1,1,0,0,1,1
#define CHAR_Z  1,0,0,1,1,1
#define CHAR_SP  0,0,0,0,0,0

void PrintString(void);
void EncodeChar(char curChar);
void ClearCharArray(void);
void FillCharArray(uint8_t a1,uint8_t a2,uint8_t b1,uint8_t b2,uint8_t c1,uint8_t c2);
void EncodeString(char* string);
void ParseString(char* string);

#endif
