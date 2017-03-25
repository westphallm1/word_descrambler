#include<string.h>
#include<stdlib.h>
#include"strhash.h"

/*
 *function to compare two characters, used by quicksort
 */
int cmpchar(const void *p1, const void *p2)
{
    return *(char *) p1 - *(char *) p2;
}

/*
 *function to hash a string
 *designed such that all strings containing the same characters
 *will have the same hash
 */
size_t strhash(char * str)
{
    //Step 1 - sort the characters of the string
    size_t len = strlen(str);

    //sort a copy so as to maintain the original
    char * cpy = malloc(len*sizeof(char)+1);

    strcpy(cpy,str);
    qsort(cpy,len,sizeof(char),cmpchar);
    
    //step 2 - hash it
    //use the hash: sum(31^[n] * str[n])
    int i, mul=1;
    size_t hash=0;
    for(i=0; i < len; hash+=(mul*=31)*cpy[i++]);
    free(cpy);

    return hash;
}
