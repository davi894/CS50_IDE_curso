#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define ALPHABET_SIZE 26

char *substitution_cipher(const char *key, const char *text)
{
    char *ciphered_text = malloc(strlen(text) + 1);

    for (size_t i = 0; i < strlen(text); i++)
    {
        char c = text[i];

        if (isalpha(c))
        {
            char substitution = key[toupper(c) - 'A'];
            ciphered_text[i] = islower(c) ? tolower(substitution) : substitution;
        }
        else
        {
            ciphered_text[i] = c;
        }
    }

    ciphered_text[strlen(text)] = '\0';
    return ciphered_text;
}

char *substitution_decipher(const char *key, const char *text)
{
    char *deciphered_text = malloc(strlen(text) + 1);

    for (size_t i = 0; i < strlen(text); i++)
    {
        char c = text[i];

        if (isalpha(c))
        {
            int index = 0;
            char substitution = tolower(c);

            for (int j = 0; j < ALPHABET_SIZE; j++)
            {
                if (tolower(key[j]) == substitution)
                {
                    index = j;
                    break;
                }
            }

            deciphered_text[i] = isupper(c) ? toupper('A' + index) : 'a' + index;
        }
        else
        {
            deciphered_text[i] = c;
        }
    }

    deciphered_text[strlen(text)] = '\0';
    return deciphered_text;
}

int main()
{
    char key[ALPHABET_SIZE + 1];
    printf("Digite a chave de substituição: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';

    if (strlen(key) != ALPHABET_SIZE)
    {
        printf("A chave deve conter exatamente 26 caracteres.\n");
        return 1;
    }

    for (size_t i = 0; i < ALPHABET_SIZE; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("A chave deve conter apenas letras do alfabeto.\n");
            return 1;
        }
    }

    char text[100];
    printf("Texto simples: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    char *ciphered_text = substitution_cipher(key, text);
    printf("Texto cifrado: %s\n", ciphered_text);

    char deciphered_text[100];
    printf("Digite o texto cifrado: ");
    fgets(deciphered_text, sizeof(deciphered_text), stdin);
    deciphered_text[strcspn(deciphered_text, "\n")] = '\0';

    char *decrypted_text = substitution_decipher(key, deciphered_text);
    printf("Texto decifrado: %s\n", decrypted_text);

    free(ciphered_text);
    free(decrypted_text);
    return 0;
}
