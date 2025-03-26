#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tf, N, tt = 0, i = 1;  // Global variables

void transmission() {
    while (i <= tf) {
        int z = 0;
        
        // Sending frames
        for (int k = i; k < i + N && k <= tf; k++) {
            printf("Sending Frame %d...\n", k);
            tt++;
        }
        
        // Receiving Acknowledgment
        for (int k = i; k < i + N && k <= tf; k++) {
            int f = rand() % 2;
            if (!f) {
                printf("Acknowledgment for Frame %d...\n", k);
                z++;
            } else {
                printf("Timeout!! Frame Number: %d Not Received\n", k);
                printf("Retransmitting Window...\n");
                break;
            }
        }
        printf("\n");
        i = i + z;
    }
}

int main() {
    srand(time(NULL));
    
    printf("Enter the Total number of frames: ");
    scanf("%d", &tf);
    
    printf("Enter the Window Size: ");
    scanf("%d", &N);
    
    transmission();
    
    printf("Total number of frames which were sent and resent: %d\n", tt);
    
    return 0;
}


Ith ayalo
