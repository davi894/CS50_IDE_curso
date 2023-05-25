#include <stdio.h>

int length(const char *text);

int main()
{

    char text[1000];
    int L, S = 0;

    printf("\n Digite aqui o seu texto:");

    fgets(text, 1000, stdin);

    for (size_t i = 0; i <= length(text); i++)
    {
        if (text[i] != '\0')
        {
            L++;
        }
        else if (text[i] == '\0' || text[i] == "!" || text[i] == "?" || text[i] == ".")
        {
            S++;
        }
    }

    float indiceColemanLiau = (int)(0.0588 * L - 0.296 * S - 15.8);

    if (indiceColemanLiau >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (indiceColemanLiau < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %f\n", indiceColemanLiau);
    }

    return 0;
}

int length(const char *text)
{
    int comprimento = 0;

    while (text[comprimento])
    {
        comprimento++;
    }

    return comprimento;
}
