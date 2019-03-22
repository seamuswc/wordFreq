#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


#include "linked_list.c"
#include "get_words.c"
#include "sort.c"


//Works with .txt files
//Should switch sort alg. to merge sort.


int main(int argc, char const *argv[]) {

    list * l = create_list();
  

    char filename[100];

    getFilename(filename, sizeof(filename));
    int count = get_words(filename, l);

    sort(l);
    print_singles(l);
    printf("%d Total word count\n", count );
    free_nodes(l);


    return 0;
}


