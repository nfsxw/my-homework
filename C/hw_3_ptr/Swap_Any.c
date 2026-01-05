#include <stdlib.h>
#include <string.h>

void Swap_Any(void *a, void *b, size_t size)
{
    if(a == NULL || b == NULL || size == 0) return;
    unsigned char *temp = (unsigned char*)malloc(size);
    if(temp == NULL) return;

    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}