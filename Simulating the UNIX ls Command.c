#include <stdio.h>
#include <dirent.h>

int main()
{
    DIR *dir;
    struct dirent *entry;

    /* Open current directory */
    dir = opendir(".");

    if (dir == NULL)
    {
        printf("Unable to open directory.\n");
        return 1;
    }

    printf("Contents of current directory:\n\n");

    /* Read directory entries */
    while ((entry = readdir(dir)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    /* Close directory */
    closedir(dir);

    return 0;
}