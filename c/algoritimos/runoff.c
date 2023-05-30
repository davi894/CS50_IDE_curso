#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 9

typedef struct
{
    char name[100];
    int votes;
} candidate;

candidate candidates[MAX];

int candidate_count;

bool vote(char *name);
void print_winner(void);

int main(void)
{
    printf("Enter the number of candidates: ");
    scanf("%d", &candidate_count);

    if (candidate_count < 2 || candidate_count > MAX)
    {
        printf("Invalid number of candidates. Minimum is 2 and maximum is %d.\n", MAX);
        return 1;
    }

    printf("Enter the names of the candidates:\n");
    for (int i = 0; i < candidate_count; i++)
    {
        printf("Candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    int voter_count;
    printf("Enter the number of voters: ");
    scanf("%d", &voter_count);

    for (int i = 0; i < voter_count; i++)
    {
        char name[100];
        printf("Vote: ");
        scanf("%s", name);

        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    print_winner();

    return 0;
}

bool vote(char *name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return 1;
        }
    }
    return 0;
}

void print_winner(void)
{
    int max_votes = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
