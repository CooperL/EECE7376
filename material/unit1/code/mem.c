#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "common.h"
int value;
int main(int argc, char **argv)
{
    // Check syntax
    if (argc != 2)
    {
         fprintf(stderr, "usage: mem <value>\n");
exit(1); }
    // Make p point to global variable and assign initial value
    int *p = &value;
    *p = atoi(argv[1]);
    printf("(pid:%d) address of p: %p, value of p: %d\n",
              (int) getpid(), p, *p);
    // Increment content of p forever
    while (1)
    {
         spin(1);
         *p = *p + 1;
         printf("(pid:%d) value of p: %d\n", getpid(), *p);
}
    // Unreachable
return 0; }
