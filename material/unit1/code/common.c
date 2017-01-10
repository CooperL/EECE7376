#include <stdlib.h>
#include <sys/time.h>
#include <sys/stat.h>
#include "common.h"

double getTime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double) t.tv_sec + (double) t.tv_usec / 1e6;
}
void spin(int how_long)
{
    double t = getTime();
    while ((getTime() - t) < (double) how_long);
}
