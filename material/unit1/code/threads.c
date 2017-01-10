#include <stdio.h>
#include <stdlib.h>
#include "common.h"

// Global counter
volatile int counter = 0;

// Number of iterations
int loops;

// Thread function
void *worker(void *arg)
{
    int i;
    for (i = 0; i < loops; i++)
        counter++;
}

// Main program
int main(int argc, char **argv)
{
    // Check syntax
    if (argc != 2)
    {
         fprintf(stderr, "usage: threads <loops>\n");
exit(1); }
    // Read number of iterations from argument
    loops = atoi(argv[1]);
    // Show initial value for counter
    printf("Initial value: %d\n", counter);
    // Spawn two threads
    pthread_t p1, p2;
    pthread_create(&p1, NULL, worker, NULL);
    pthread_create(&p2, NULL, worker, NULL);
    // Wait for threads to finish
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    // Show final value for counter
    printf("Final value: %d\n", counter);
￼￼￼￼return 0; }
