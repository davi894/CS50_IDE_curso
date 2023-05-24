#include <stdio.h>

int length(const char *text);
int isLuhnValid(const char* cardNumber);
int charToInt(char c);

int main()
{
    char cardNumber[17];
    printf("Digite o número do cartão: ");
    scanf("%16s", cardNumber);

    if (isLuhnValid(cardNumber))
    {
        printf("O número do cartão é válido!\n");
    }
    else
    {
        printf("O número do cartão é inválido!\n");
    }

    return 0;
}

int isLuhnValid(const char* cardNumber)
{
    int len = length(cardNumber);
    int sum = 0;
    int isSecondDigit = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        int digit = charToInt(cardNumber[i]);

        if (isSecondDigit)
        {
            digit *= 2;

            if (digit > 9)
            {
                digit = digit % 10 + 1;
            }
        }

        sum += digit;
        isSecondDigit = !isSecondDigit;
    }

    return (sum % 10 == 0);
}

int charToInt(char c)
{
    return c - '0';
}

int length(const char *text)
{
    int comprimento = 0;

    while (text[comprimento] != '\0')
    {
        comprimento++;
    }

    return comprimento;
}
