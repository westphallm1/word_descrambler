#include<stdio.h>
#include<assert.h>
#include"strhash.h"


int main(int argc, char *argv[]){
    assert(strhash("bagel") == strhash("legba"));
}
