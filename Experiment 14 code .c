#include <stdio.h>
#include <string.h>

int main() {
    char files[10][20];
    int n;

    printf("Enter number of files: ");
    scanf("%d", &n);

    for(int i=0;i<n;i++) {
        printf("Enter file name: ");
        scanf("%s", files[i]);
    }

    printf("Files:\n");
    for(int i=0;i<n;i++)
        printf("%s\n", files[i]);

    return 0;
}