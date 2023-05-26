#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ALLELES 3
#define NUM_PARENTS 2

typedef struct person
{
    struct person *parents[NUM_PARENTS];
    char alleles[NUM_ALLELES];
} person;

char random_allele()
{
    char alleles[NUM_ALLELES] = {'A', 'B', 'O'};
    return alleles[rand() % NUM_ALLELES];
}

person *create_family(int generations)
{
    if (generations <= 0)
    {
        return NULL;
    }

    person *new_person = malloc(sizeof(person));

    if (generations > 1)
    {
        new_person->parents[0] = create_family(generations - 1);
        new_person->parents[1] = create_family(generations - 1);

        new_person->alleles[0] = random_allele();
        new_person->alleles[1] = random_allele();
    }
    else
    {
        new_person->parents[0] = NULL;
        new_person->parents[1] = NULL;

        new_person->alleles[0] = random_allele();
        new_person->alleles[1] = random_allele();
    }

    return new_person;
}

void free_family(person *p)
{
    if (p == NULL)
    {
        return;
    }

    free_family(p->parents[0]);
    free_family(p->parents[1]);

    free(p);
}

void print_family(person *p, int generation)
{
    if (p == NULL)
    {
        return;
    }

    printf("Generation %d: Alleles: %c %c\n", generation, p->alleles[0], p->alleles[1]);

    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

int main(void)
{
    srand(time(NULL));

    int generations = 3;
    person *family = create_family(generations);

    print_family(family, 0);

    free_family(family);

    return 0;
}
