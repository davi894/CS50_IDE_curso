#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Tamanho do bloco em bytes
#define BLOCK_SIZE 512

// Assinatura de início de um arquivo JPEG
#define JPEG_START 0xffd8ffe0

// Função para verificar se um bloco começa com a assinatura de um arquivo JPEG
int is_jpeg_start(uint8_t *block)
{
    return (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0);
}

int main(int argc, char *argv[])
{
    // Verificação do número correto de argumentos
    if (argc != 1)
    {
        printf("Uso: %s\n", argv[0]);
        return 1;
    }

    char image_filename[256];

    printf("Digite o nome do arquivo de imagem forense: ");
    scanf("%255s", image_filename);

    // Abertura do arquivo da imagem forense
    FILE *forensic_image = fopen(image_filename, "r");
    if (forensic_image == NULL)
    {
        printf("Não foi possível abrir a imagem forense.\n");
        return 1;
    }

    // Variáveis para controle dos arquivos JPEG
    int jpeg_count = 0;
    FILE *current_jpeg = NULL;

    // Buffer para armazenar os blocos lidos da imagem forense
    uint8_t block[BLOCK_SIZE];

    // Leitura dos blocos da imagem forense
    while (fread(block, sizeof(uint8_t), BLOCK_SIZE, forensic_image) == BLOCK_SIZE)
    {
        // Verificação se o bloco é o início de um arquivo JPEG
        if (is_jpeg_start(block))
        {
            // Fechamento do arquivo JPEG atual, se existir
            if (current_jpeg != NULL)
                fclose(current_jpeg);

            // Criação e abertura de um novo arquivo JPEG
            char filename[8];
            sprintf(filename, "%03i.jpg", jpeg_count);
            current_jpeg = fopen(filename, "w");
            if (current_jpeg == NULL)
            {
                printf("Não foi possível criar o arquivo JPEG.\n");
                return 1;
            }

            // Incremento do contador de arquivos JPEG
            jpeg_count++;
        }

        // Escrita do bloco no arquivo JPEG atual, se estiver aberto
        if (current_jpeg != NULL)
            fwrite(block, sizeof(uint8_t), BLOCK_SIZE, current_jpeg);
    }

    // Fechamento do último arquivo JPEG
    if (current_jpeg != NULL)
        fclose(current_jpeg);

    // Fechamento do arquivo da imagem forense
    fclose(forensic_image);

    return 0;
}
