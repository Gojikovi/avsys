#ifndef H_STRING
#define H_STRING

#include <stddef.h>

#define GET_VAR_NAME(buffer, var) buffer = #var

size_t strlen(const char* str) {
    size_t count = 0;
    while(str[count] != '\0') {
        count++;
    }

    return count;
}

/* Code: https://gist.github.com/aaronryank/808d667c472af123e6ca08d0aacfcebc */
char *reverse(char *str)
{
    char tmp, *src, *dst;
    size_t len;
    if (str != NULL)
    {
        len = strlen (str);
        if (len > 1) {
            src = str;
            dst = src + len - 1;
            while (src < dst) {
                tmp = *src;
                *src++ = *dst;
                *dst-- = tmp;
            }
        }
    }
    return str;
}

/* itoa from K&R */
void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)        /* record sign */
        n = -n;                /* make n positive */
    i = 0;

    do {                       /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /* get next digit */
    } while ((n /= 10) > 0);   /* delete it */

    if (sign < 0)
        s[i++] = '-';

    reverse(s);
    s[i] = '\0';
    return;
}

#endif