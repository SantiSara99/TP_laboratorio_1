#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validation.h"

int getInt(char mensaje[])
{
    int auxiliarInt;
    printf("%s" , mensaje);
    scanf("%d" , &auxiliarInt);
    return auxiliarInt;
}


void getString(char mensaje[], char input[])
{
    printf(mensaje);
    scanf("%s", input);
}


float getFloat(char mensaje[])
{
    float auxiliarFloat;
    printf("%s" , mensaje);
    scanf("%f" , &auxiliarFloat);
    return auxiliarFloat;
}

int isOnlyLetters(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] <  'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        return 0;
        i++;
    }
    return 1;
}

int isPositive(float numero)
{
    if(numero > 0)
    {
        return 1;
    }
    return 0;
}
