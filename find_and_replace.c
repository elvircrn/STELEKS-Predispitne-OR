#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void expand(char *str, int where, int amount)
{
    int i, str_len = strlen(str);
    for (i = str_len; i >= where; i--)
        str[i + amount] = str[i];
}

void shrink(char *str, int where, int amount)
{
    int i, str_len = strlen(str);

    //                \/
    for (i = where; i <= str_len; i++)
        str[i - amount] = str[i];
}

void find_and_replace(char *str, char *find, char *replace)
{
    int rep_len = strlen(replace), find_len = strlen(find), str_len = strlen(str);
    int i, j;
    for (i = 0; i + find_len <= str_len; i++)
    {
        int match = 1;
        for (j = 0; j < find_len; j++)
        {
            if (find[j] != str[i + j])
            {
                match = 0;
                break;
            }
        }

        if (match)
        {
            if (find_len < rep_len)
                expand(str, i, rep_len - find_len);
            else
                shrink(str, i + find_len, find_len - rep_len);
            for (j = 0; j < rep_len; j++)
                str[i + j] = replace[j];
            i += j;
            str_len += rep_len - find_len;
        }
    }
}

int main()
{
    char str[30] = "...world..world..";
    find_and_replace(str, "world", "worldworld");
    printf("%s\n", str);
    return 0;
}
