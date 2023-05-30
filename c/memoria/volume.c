#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define HEADER_SIZE 44

int main()
{
    char input[100];
    char output[100];
    float factor;

    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", input);

    printf("Digite o nome do arquivo de saída: ");
    scanf("%s", output);

    printf("Digite o fator de volume: ");
    scanf("%f", &factor);

    // Abre o arquivo de entrada para leitura
    FILE *inputFile = fopen(input, "rb");
    if (inputFile == NULL)
    {
        printf("Não foi possível abrir o arquivo de entrada.\n");
        return 1;
    }

    // Abre o arquivo de saída para escrita
    FILE *outputFile = fopen(output, "wb");
    if (outputFile == NULL)
    {
        printf("Não foi possível criar o arquivo de saída.\n");
        fclose(inputFile);
        return 1;
    }

    // Lê e grava o cabeçalho do arquivo WAV
    uint8_t header[HEADER_SIZE];
    fread(header, sizeof(uint8_t), HEADER_SIZE, inputFile);
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, outputFile);

    // Lê as amostras de áudio e grava as amostras modificadas no arquivo de saída
    int16_t buffer;
    while (fread(&buffer, sizeof(int16_t), 1, inputFile) == 1)
    {
        buffer = buffer * factor;
        fwrite(&buffer, sizeof(int16_t), 1, outputFile);
    }

    // Fecha os arquivos de entrada e saída
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
