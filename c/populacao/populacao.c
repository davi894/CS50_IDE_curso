#include <stdio.h>

int main(int argc, char const *argv[])
{

    int valueInitial;

    do
    {
        printf("Digite um valor inicial: ");
        scanf("%d", &valueInitial);

    } while (valueInitial < 9);

    int valueBirths = (int)valueInitial / 3;
    int valueDeaths = (int)valueInitial / 4;

    int calculatedFinaly = valueInitial + valueBirths - valueDeaths;

    printf("O crescimento da população de lhamas foi de %d\n", calculatedFinaly - valueInitial);

    return 0;
}
