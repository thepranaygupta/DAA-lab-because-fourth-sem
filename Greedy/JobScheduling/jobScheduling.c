#include <stdio.h>
#include <stdlib.h>
// #define n 6

typedef struct s
{
    int id;
    int profit;
    int deadline;
} Job;

void sortProfit(Job *a, int n)
{
    int i, j;
    Job temp;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        for (j = i - 1; (j >= 0) && ((a[j].profit) < (temp.profit)); j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
    return;
}

void display(Job *a, int m)
{
    int i;
    printf("\nID:      \t");
    for (i = 0; i < m; i++)
    {
        printf("%d\t", a[i].id);
    }
    printf("\nProfit:  \t");
    for (i = 0; i < m; i++)
    {
        printf("%d\t", a[i].profit);
    }
    printf("\nDeadline:\t");
    for (i = 0; i < m; i++)
    {
        printf("%d\t", a[i].deadline);
    }
    return;
}

int main()
{
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    if (n < 1)
    {
        printf("\nInvalid Input\n");
        return 0;
    }
    Job *pool = (Job *)malloc(n * sizeof(Job));
    // Job pool[n];
    int i, j, r, size = 0;
    int profit = 0;
    Job solution[n + 1];
    for (i = 0; i < n; i++)
    {
        pool[i].id = (i + 1);
        printf("Enter the profit for Job %d: ", i + 1);
        scanf("%d", &pool[i].profit);
        printf("Enter the deadline for Job %d: ", i + 1);
        scanf("%d", &pool[i].deadline);
    }
    sortProfit(pool, n);
    display(pool, n);
    solution[0].id = 0;
    solution[0].profit = 0;
    solution[0].deadline = 0;
    solution[1] = pool[0];
    size = 1;
    for (i = 1; i < n; i++)
    {
        r = size;
        while (((solution[r].deadline) > (pool[i].deadline)) && (solution[r].deadline != r))
        {
            r--;
        }
        if (((solution[r].deadline) <= (pool[i].deadline)) && ((pool[i].deadline) > r))
        {
            for (j = size; j >= r + 1; j--)
            {
                solution[j + 1] = solution[j];
            }
            solution[j + 1] = pool[i];
            size++;
        }
    }
    display(solution, size + 1);
    return 0;
}
