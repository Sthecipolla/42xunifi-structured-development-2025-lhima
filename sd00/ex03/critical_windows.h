#ifndef CRITICAL_WINDOWS_H
# define CRITICAL_WINDOWS_H

#define TRUE 1
#define FALSE 0

#include <stdio.h>

int count_critical_windows(const int *readings, int size);

#endif