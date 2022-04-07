
#include <stdio.h>
#define n 6

typedef struct s
{
    int id;
    int profit;
    int deadline;
} Job;

void sortProfit(Job *a)
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

void disp(Job *a, int m)
{
    int i;
    printf("\n ID:\t");
    for (i = 0; i < m; i++)
    {
        printf("%d\t", a[i].id);
    }
    printf("\n Profit:\t");
    for (i = 0; i < m; i++)
    {
        printf("%d\t", a[i].profit);
    }
    printf("\n Deadline:\t");
    for (i = 0; i < m; i++)
    {
        printf("%d\t", a[i].deadline);
    }
}

int main()
{
    Job pool[n];
    int i, j, r, sz = 0;
    int profit = 0;
    Job solution[n + 1];
    for (i = 0; i < n; i++)
    {
        pool[i].id = (i + 1);
        printf("Enter Proffit value for %dth job: ", i + 1);
        scanf("%d", &pool[i].profit);
        printf("Enter deadline for %dth job: ", i + 1);
        scanf("%d", &pool[i].deadline);
    }
    // disp(pool,n);
    sortProfit(pool);
    disp(pool, n);
    solution[0].id = 0;
    solution[0].profit = 0;
    solution[0].deadline = 0;
    solution[1] = pool[0];
    sz = 1;
    for (i = 1; i < n; i++)
    {
        r = sz;
        while (((solution[r].deadline) > (pool[i].deadline)) && (solution[r].deadline != r))
        {
            r--;
        }
        if (((solution[r].deadline) <= (pool[i].deadline)) && ((pool[i].deadline) > r))
        {
            for (j = sz; j >= r + 1; j--)
            {
                solution[j + 1] = solution[j];
            }
            solution[j + 1] = pool[i];
            sz++;
        }
    }
    disp(solution, sz + 1);
    getch();
    return 0;
}
