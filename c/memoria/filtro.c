#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    // Variável para armazenar o filtro escolhido pelo usuário
    char filter;

    // Leitura do filtro escolhido pelo usuário
    printf("Escolha um filtro (b para blur, g para grayscale, r para reflect): ");
    scanf(" %c", &filter);

    // Abertura do arquivo de imagem
    FILE *image_file = fopen("input.bmp", "rb");
    if (image_file == NULL)
    {
        printf("Não foi possível abrir o arquivo de imagem.\n");
        return 1;
    }

    // Leitura dos dados da imagem
    BITMAPFILEHEADER bf;
    BITMAPINFOHEADER bi;
    RGBTRIPLE image[MAX_HEIGHT][MAX_WIDTH];

    fread(&bf, sizeof(BITMAPFILEHEADER), 1, image_file);
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, image_file);

    // Verificação se é um arquivo BMP válido
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        printf("Arquivo de imagem inválido.\n");
        fclose(image_file);
        return 1;
    }

    // Cálculo da largura e altura da imagem
    int width = bi.biWidth;
    int height = abs(bi.biHeight);

    // Verificação se a imagem está dentro das dimensões máximas suportadas
    if (width > MAX_WIDTH || height > MAX_HEIGHT)
    {
        printf("A imagem excede as dimensões máximas suportadas.\n");
        fclose(image_file);
        return 1;
    }

    // Leitura dos pixels da imagem
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            fread(&image[i][j], sizeof(RGBTRIPLE), 1, image_file);
        }
        // Preenchimento dos bytes de padding se existirem
        fseek(image_file, padding(width), SEEK_CUR);
    }

    // Fechamento do arquivo de imagem
    fclose(image_file);

    // Aplicação do filtro escolhido
    switch (filter)
    {
    case 'b':
        blur(height, width, image);
        break;
    case 'g':
        grayscale(height, width, image);
        break;
    case 'r':
        reflect(height, width, image);
        break;
    default:
        printf("Filtro inválido.\n");
        return 1;
    }

    // Criação do novo arquivo de imagem
    FILE *output_file = fopen("output.bmp", "wb");
    if (output_file == NULL)
    {
        printf("Não foi possível criar o arquivo de saída.\n");
        return 1;
    }

    // Escrita dos dados da imagem no arquivo de saída
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, output_file);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, output_file);

    // Escrita dos pixels da imagem no arquivo de saída
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            fwrite(&image[i][j], sizeof(RGBTRIPLE), 1, output_file);
        }
        // Preenchimento dos bytes de padding se existirem
        for (int k = 0; k < padding(width); k++)
        {
            fputc(0x00, output_file);
        }
    }

    // Fechamento do arquivo de saída
    fclose(output_file);

    printf("Filtro aplicado com sucesso. Imagem de saída salva em output.bmp.\n");

    return 0;
}
