#include <stdio.h>
#include "string.h"
#include "blockio.h"

//appends a character to a character array
void append(char* s, char c)
{
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}
