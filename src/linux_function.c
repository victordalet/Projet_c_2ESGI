#include <assert.h>
#include <stdlib.h>
#include <string.h>

void reverse(char str[], int length) {
    int start;
    int end = length - 1;
    for (start = 0; start < end; ++start, --end) {
        const char ch = str[start];
        str[start] = str[end];
        str[end] = ch;
    }
}

char *itoa(int num, char *str, int base) {
    int i = 0;
    char isNegNum = 0;
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
    } else {
        if ((num < 0) && (base == 10)) {
            isNegNum = 1;
            num = -num;
        }
        do {
            const int rem = (num % base);
            str[i++] = (rem > 9) ? ((rem - 10) + 'a') : (rem + '0');
            num = num / base;
        } while (num != 0);
        if (isNegNum) {
            str[i++] = '-';
        }
        str[i] = '\0';
        reverse(str, i);
    }
    return str;
}

char **str_split(char *a_str, const char a_delim) {
    char **result = 0;
    size_t count = 0;
    char *tmp = a_str;
    char *last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    while (*tmp) {
        if (a_delim == *tmp) {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char *) * count);

    if (result) {
        size_t idx = 0;
        char *token = strtok(a_str, delim);

        while (token) {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}
