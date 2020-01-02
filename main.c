#include <stdio.h>
#include <stdint.h>

#include "braille/braille.h"

char str[100];

int main()
{
    printf("Enter Text:\n");
    scanf("%s",str);
    ParseString(str);
    return 0;
}

