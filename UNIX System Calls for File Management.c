#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char buffer[100];
    char data[] = "Hello, this is UNIX file management.";

    /* Create/Open file */
    fd = open("sample.txt", O_CREAT | O_RDWR, 0644);

    if (fd == -1)
    {
        printf("Error opening file.\n");
        return 1;
    }

    printf("File opened successfully.\n");

    /* Write to file */
    write(fd, data, sizeof(data) - 1);

    printf("Data written successfully.\n");

    /* Move file pointer to beginning */
    lseek(fd, 0, SEEK_SET);

    /* Read from file */
    int n = read(fd, buffer, sizeof(buffer) - 1);

    if (n > 0)
    {
        buffer[n] = '\0';
        printf("Data read from file: %s\n", buffer);
    }

    /* Close file */
    close(fd);

    printf("File closed successfully.\n");

    return 0;
}