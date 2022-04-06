#include <stdio.h>
#include <stdlib.h>

void quicksort_descending(float *a, float *p, float *w, int first, int last)
{
    float temp1, temp2, temp3;
    int low = first;
    int high = last;
    float pivot = a[(low + high) / 2];
    while (low <= high)
    {
        while (a[low] > pivot)
            low++;

        while (a[high] < pivot)
            high--;
        if (low <= high)
        {
            temp1 = a[low];
            temp2 = p[low];
            temp3 = w[low];

            a[low] = a[high];
            p[low] = p[high];
            w[low] = w[high];

            a[high] = temp1;
            p[high] = temp2;
            w[high] = temp3;

            low++;
            high--;
        }
    }
    if (low < last)
    {
        quicksort_descending(a, p, w, low, last);
    }
    if (high > first)
    {
        quicksort_descending(a, p, w, first, high);
    }
}

int main()
{
    int n, i;
    float cap, cur_cap, cur_profit;
    float *profit, *wt, *ppw;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of Knapsack: ");
    scanf("%f", &cap);

    profit = (float *)malloc(n * sizeof(float));
    wt = (float *)malloc(n * sizeof(float));
    ppw = (float *)malloc(n * sizeof(float));
    for (i = 0; i < n; i++)
    {
        printf("Enter the profit associated with item %d: ", i + 1);
        scanf("%f", &profit[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter the weight associated with item %d: ", i + 1);
        scanf("%f", &wt[i]);
    }

    printf("\nProfit per weight (PPW): ");
    for (i = 0; i < n; i++)
    {
        ppw[i] = profit[i] / wt[i];
        printf("%f ", ppw[i]);
    }

    quicksort_descending(ppw, profit, wt, 0, n - 1);
    printf("\n\nAfter Sorting Profit per weight (PPW): ");
    for (i = 0; i < n; i++)
        printf("%f ", ppw[i]);

    printf("\nAfter Sorting Profit: ");
    for (i = 0; i < n; i++)
        printf("%f ", profit[i]);

    printf("\nAfter Sorting Weight: ");
    for (i = 0; i < n; i++)
        printf("%f ", wt[i]);
    printf("\n");

    cur_cap = cap;
    cur_profit = 0;
    i = 0;
    while (cur_cap > 0)
    {
        if (wt[i] <= cur_cap)
        {
            cur_profit += profit[i];
            cur_cap -= wt[i];
        }
        else
        {
            cur_profit += (ppw[i] * cur_cap);
            cur_cap = 0;
        }
        i++;
        printf("\nAt iteration: %d, Current Profit: %f ", i, cur_profit);
    }
    printf("\nTotal Profit: %f", cur_profit);
    return 0;
}
