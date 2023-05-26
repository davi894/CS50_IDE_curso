#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(const char *word);

int main(void)
{
    // Get input words from both players
    char word1[100];
    printf("Player 1: ");
    fgets(word1, sizeof(word1), stdin);
    word1[strcspn(word1, "\n")] = '\0';

    char word2[100];
    printf("Player 2: ");
    fgets(word2, sizeof(word2), stdin);
    word2[strcspn(word2, "\n")] = '\0';

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the scores
    printf("Player 1 score: %d\n", score1);
    printf("Player 2 score: %d\n", score2);

    // Compare scores and print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }

    return 0;
}

int compute_score(const char *word)
{
    int score = 0;

    for (size_t i = 0; i < strlen(word); i++)
    {
        char c = toupper(word[i]);

        if (isalpha(c))
        {
            int index = c - 'A';
            score += POINTS[index];
        }
    }

    return score;
}
