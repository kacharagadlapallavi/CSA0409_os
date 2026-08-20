#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main()
{
    int fd;
    struct stat fileStat;
    DIR *dir;
    struct dirent *entry;

    /* 1. Open file */
    fd = open("sample.txt", O_CREAT | O_RDWR, 0644);

    if (fd == -1)
    {
        printf("Error opening file.\n");
        return 1;
    }

    printf("File opened successfully.\n");

    /* 2. fcntl() - get file descriptor flags */
    int flags = fcntl(fd, F_GETFL);

    if (flags != -1)
        printf("fcntl(): File status flags obtained.\n");

    /* 3. lseek() - move file pointer */
    lseek(fd, 0, SEEK_END);

    printf("lseek(): File pointer moved to end.\n");

    /* 4. stat() - get file information */
    if (stat("sample.txt", &fileStat) == 0)
    {
        printf("\nFile Information:\n");
        printf("File Size : %ld bytes\n", fileStat.st_size);
        printf("File Inode: %ld\n", fileStat.st_ino);
        printf("File Mode : %o\n", fileStat.st_mode);
    }
    else
    {
        printf("Error getting file information.\n");
    }

    /* 5. opendir() - open directory */
    dir = opendir(".");

    if (dir == NULL)
    {
        printf("Error opening directory.\n");
        close(fd);
        return 1;
    }

    printf("\nDirectory Contents:\n");

    /* 6. readdir() - read directory entries */
    while ((entry = readdir(dir)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    /* Close directory */
    closedir(dir);

    /* Close file */
    close(fd);

    printf("\nFile and directory operations completed.\n");

    return 0;
}