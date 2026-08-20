#include <stdio.h>

int main()
{
    FILE *fp;
    char data[100];

    /* Create and write to file */
    fp = fopen("sample.txt", "w");

    if (fp == NULL)
    {
        printf("Error creating file.\n");
        return 1;
    }

    printf("Enter data to write into file: ");
    fgets(data, sizeof(data), stdin);

    fprintf(fp, "%s", data);

    fclose(fp);

    printf("File created and data written successfully.\n");

    /* Read file */
    fp = fopen("sample.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    printf("\nData in file:\n");

    while (fgets(data, sizeof(data), fp) != NULL)
    {
        printf("%s", data);
    }

    fclose(fp);

    /* Append data */
    fp = fopen("sample.txt", "a");

    if (fp == NULL)
    {
        printf("Error opening file for append.\n");
        return 1;
    }

    printf("\nEnter data to append: ");
    fgets(data, sizeof(data), stdin);

    fprintf(fp, "%s", data);

    fclose(fp);

    printf("Data appended successfully.\n");

    /* Display updated file */
    fp = fopen("sample.txt", "r");

    printf("\nUpdated file contents:\n");

    while (fgets(data, sizeof(data), fp) != NULL)
    {
        printf("%s", data);
    }

    fclose(fp);

    return 0;
}