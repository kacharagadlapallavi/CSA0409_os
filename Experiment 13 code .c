#include <stdio.h>

int main() {
    int block[5] = {100, 500, 200, 300, 600};
    int process[4] = {212, 417, 112, 426};

    for(int i=0;i<4;i++) {
        for(int j=0;j<5;j++) {
            if(block[j] >= process[i]) {
                printf("Process %d allocated in block %d\n", i+1, j+1);
                block[j] -= process[i];
                break;
            }
        }
    }
    return 0;
}