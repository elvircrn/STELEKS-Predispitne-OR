#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    FILE *out = fopen("in.txt", "w");
    fprintf(out, "1234");
    fclose(out);

    FILE *in = fopen("in.txt", "r");

    char str[10];

    printf("%s\n", str);

    fclose(in);
    return 0;
}


