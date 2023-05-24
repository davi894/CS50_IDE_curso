#include <stdio.h>

int main(void)
{
    float troco;

    do
    {
        printf("Troco devido: ");
        scanf("%f", &troco);
    } while (troco <= -1);

    int centavos = (int)(troco * 100 + 0.5);
    int moedas = 0;


    while (centavos >= 25)
    {
        centavos -= 25;
        moedas++;
    }

    while (centavos >= 10)
    {
        centavos -= 10;
        moedas++;
    }

    while (centavos >= 5)
    {
        centavos -= 5;
        moedas++;
    }

    while (centavos >= 1)
    {
        centavos -= 1;
        moedas++;
    }

    printf("%d\n", moedas);

    return 0;
}
