#include <stdio.h>

int main(void) {
    int n;

    do {
        printf("Digite um número inteiro entre 1 e 8: ");
        scanf("%d", &n);
    } while (n > 8 || n < 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j < n - 1) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }

    return 0;
}
