#include <stdio.h>

int main(void)
{
    int heigth;

    do
    {
        printf("Digite um número inteiro entre 1 e 8: ");
        scanf("%d", &heigth);
    } while (heigth > 8 || heigth < 1);

    for (int row = 0; row < heigth; row++)
    {
        for (int space = 0; space < heigth - row - 1; space++)
        {
            printf(" ");
        }
        for (int column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf(" ");
        for (int column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("\n");
    }
}
