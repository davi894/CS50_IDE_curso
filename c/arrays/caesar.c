#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int k;
    char text[601];

    printf("Texto:");
    fgets(text, sizeof(text), stdin);
    printf("k:");
    scanf("%d", &k);

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                text[i] = ((text[i] - 'A' + k) % 26) + 'A';
            }
            else
            {
                text[i] = ((text[i] - 'a' + k) % 26) + 'a';
            }
        }
    }

    printf("Texto criptografado: %s\n", text);

    return 0;
}
