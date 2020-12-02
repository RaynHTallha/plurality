#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//define max candidates
#define MAX 9

//make candidates structure
typedef struct
{
    char name[50];
    int votes;
}
candidate;
candidate candidates[MAX];

int candidateCount;

//functions prototypes
void printWinner(void);
//functions prototypes
bool vote(char name[]);


// main function
int main(int argc, char *argv[])
{
    //check for arguments counts
    if (argc < 3)
    {
        //if there is no argument
        printf("Usage ./plurality [candidates ... ] \n");
        return 1;
    }
    candidateCount = argc - 1;
    if (candidateCount > MAX)
    {
        //if arguments count is too high
        printf("max of 9 candidates is allowed\n");
        return 2;
    }

    for (int i = 0; i < candidateCount; i++)
    {
        //assigning candidates names
        strcpy(candidates[i].name, argv[i + 1]);
        candidates[i].votes = 0;
    }
    //asking for voters counts
    int votersCount = get_int("Number of voters: ");

    for (int i = 0; i < votersCount; i++)
    {
        //getting votes
        char name[50];
        printf("vote: ");
        scanf("%s", name);

        if (!vote(name))
        {
            //if vote invalid
            printf("Invalid vote\n");
        }
    }
    printWinner();
}

bool vote(char name[])
{
    for (int i = 0; i < candidateCount; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            //assigning votes
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

void printWinner(void)
{
    int mostVotes = 0;
    for (int i = 0; i < candidateCount; i++)
    {
        if (candidates[i].votes > mostVotes)
        {
            //comparing votes
            mostVotes = candidates[i].votes;
        }
    }
    for (int i = 0; i < candidateCount; i++)
    {
        if (candidates[i].votes == mostVotes)
        {
            //printing winner
            printf("%s\n", candidates[i].name);
        }
    }
}
