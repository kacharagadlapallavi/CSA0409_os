#include <stdio.h>

int main()
{
    int blockSize[20], processSize[20];
    int allocation[20];
    int m, n;
    int i, j, best;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter size of each memory block:\n");
    for (i = 0; i < m; i++)
    {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("\nEnter number of processes: ");
    scanf("%d", &n);

    printf("Enter size of each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
        allocation[i] = -1;
    }

    /* Best Fit */
    for (i = 0; i < n; i++)
    {
        best = -1;

        for (j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (best == -1 ||
                    blockSize[j] < blockSize[best])
                {
                    best = j;
                }
            }
        }

        if (best != -1)
        {
            allocation[i] = best;
            blockSize[best] -= processSize[i];
        }
    }

    printf("\nProcess\tProcess Size\tBlock\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t", i + 1, processSize[i]);

        if (allocation[i] != -1)
            printf("B%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}