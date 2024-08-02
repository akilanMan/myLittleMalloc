#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mymalloc.h"

static char memory[5000];

int emptyint = 1;


void *allocateBlock (int sizeint)
{
    char * currchar = memory;
    int spacerint = (2 + sizeint);
    int counter = 0;
    int index = 0;
    int negnum = -1;
    int zeronum =0;
   
    if (4998 < sizeint || sizeint < 1)
    {
        return NULL;
    }

    do {

        short *blksizeshort = (short*)(currchar);

        short savedblksizeshort = (negnum * *blksizeshort);
        if (0 > savedblksizeshort)
        {
            savedblksizeshort = negnum * savedblksizeshort;
        }

        int sideintmar = (savedblksizeshort - spacerint);

        if ((sideintmar > 2 || sideintmar == zeronum) && (*blksizeshort < zeronum))
        {
            short *pointershorter;

            pointershorter = (short*)currchar;
            *pointershorter = spacerint;

            if (savedblksizeshort != spacerint)
            {
                pointershorter = (short*)(currchar + spacerint);
                *pointershorter = (savedblksizeshort - spacerint) * negnum; 
            }

            return (2 + currchar);

        }

        else
        {
            index = (savedblksizeshort + index);
            currchar = &memory[index];
            counter++;

        }

    } while ( 5000 > index);

    return NULL;
}

void initialize()
{
    char *pointerchar;
    pointerchar = &memory[0];
    *((short*)pointerchar) = -5000;
}


void myfree(void * pointervoid, char* file, int line)
{
    char * currchar = memory;
    char * prev = memory;

    short* currcharSize = NULL;

    int index = 0;
    int notblock = 1;
    int two  =2;
    

    if ((pointervoid > (void*)&memory[4997]) || (pointervoid < (void*)&memory[0]) )
    {
        fprintf(stderr, "invalid ptr: %s at LINE: %d\n", file, line );
        notblock = 0;
    }

    while (index < 5000 && notblock)
    {
        if ((currchar + two) == pointervoid)
        {
            currcharSize = (short*)currchar;


            if(0 > *currcharSize)
            { 
                fprintf(stderr, "double free: %s at LINE: %d\n", file, line );
            }

            else if (isFreeBlockBehind(index, currchar) && isFreeBlockBefore(currchar, prev))
            {
                short* prevshort = (short*)prev;
                char *nextchar = &memory[*currcharSize + index];
                short *nextSize = (short*)nextchar;
                *prevshort = *prevshort - *currcharSize + *nextSize;
            }

            else if (isFreeBlockBefore(currchar, prev))
            {
                short* prevshort = (short*)prev;
                *prevshort = *prevshort - *currcharSize;
            }

            else if (isFreeBlockBehind(index, currchar))
            {
                //increases size of currchar block and makes negative
                char *next = &memory[index + *currcharSize];
                short *nextSize = (short*)next;
                *currcharSize = *nextSize - *currcharSize;
            }

            else
            {
                *currcharSize = -1 * *currcharSize;
            }

            notblock = 0;
        }

        else 
        {
            currcharSize = (short*)currchar;
            prev = currchar;

            if (0 > *currcharSize)
            {
                
                index = (*currcharSize * -1) + index;
            }

            else
            {
                index = (*currcharSize + index);
            }

            currchar = &memory[index];
        }
    }
    if (1 == notblock)
    {
        fprintf(stderr, "double free: %s at LINE: %d\n", file, line );
    }

}


int isFreeBlockBehind(int intindex, char * currchar)
{
    int zero =0; 
    short *currcharSize = (short*)currchar;
    char *next = &memory[*currcharSize + intindex];
    short *nextSize = (short*)next;


    if ((5000 == (intindex + *currcharSize)) || (*nextSize > zero))
    {
        return zero;
    }

    else 
    {
        return 1;
    }
}

void * mymalloc(size_t size, char* file, int line) 
{
    if (emptyint)
    {
        initialize();
        emptyint = 0;
    }


    void *pointervoid = allocateBlock((int)size);
    if (NULL == pointervoid)
    {
    fprintf(stderr, "not enough space: %s LINE: %d \n", file, line );
    }

    return pointervoid;
}

int isFreeBlockBefore(char * currchar, char * charprev)
{
    int zero = 0; 
    short* prevshort = (short*)charprev;

    if ((*prevshort > zero) && (charprev == currchar))
    {
        return zero;
    }

    else if (zero < *prevshort)
    {
        return zero;
    }
    else 
    {
        return 1;
    }
}