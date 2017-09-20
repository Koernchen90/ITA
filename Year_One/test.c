/*
author: Raupe

Aufgabe: C25A 1
a) Das Programmstück soll zu einer Funktion printbin_u8(x) zusammengefasst werden.
Die Funktion nimmt eine Zahl x und gibt sie wie oben aus. Wie lautet der Prototyp?
b) Erstellen Sie bitte die Funktionsdenition (schreiben Sie also die Funktion)!
c) Testen Sie die Funktion mit einem kleinen Programm printbin_u8.c!

a) void printbin_u8 (int zahl)


*/

//imports
#include <stdio.h>

//Prototyps

void printbin_u8 (unsigned char x);

//main
int main (void)
{
    printbin_u8 (2);
}

/* b) */
void printbin_u8 (unsigned char x)
{
    //laufvar
    int i;
    //operation
    for (i = 0; i < 8; i++)
    {
        if (x > 127 )
            printf ("1");
        else
            printf ("0");
        x = x * 2;
     //   printf ("x=%i\n",x );// betrachten der Funktionsweise
    }
    printf ("\n");
    return;
}
