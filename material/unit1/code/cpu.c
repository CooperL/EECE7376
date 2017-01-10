#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int main(int argc, char *argv[])
{
    // Check valid arguments
    if (argc != 2)
    {
         fprintf(stderr, "usage: cpu <string>\n");
         exit(1); 
    }

    // Print first argument forever
    while (1)
    {
         printf("%s\n", argv[1]);
         spin(1); 
    }

    // Unreachable
    return 0; 
}
