#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tf, N, tt = 0, i = 1;  
//tf:total frames to send,N:window size,tt:total frames sent,i:track 1st frame in currnrt window

void transmission() {
    while (i <= tf)  //it ensures transmission until all frames are sent and acknowledged
    {
        int z = 0;   //keeps track of acknowlwdged frames
        
        // Sending frames
        for (int k = i; k < i + N && k <= tf; k++) //start sending from the first frame in the current window
            {
            printf("Sending Frame %d...\n", k); // k as it is send 
            tt++;
        }
        
        // Receiving Acknowledgment
        for (int k = i; k < i + N && k <= tf; k++) {
            int f = rand() % 2;     // f=0(ACK recieved)  f=1(ACK lost)
            if (f==0) 
            {
                printf("Acknowledgment for Frame %d...\n", k);
                z++;  // ack frames are increased
            } 
            else
            {
                printf("Timeout!! Frame Number: %d Not Received\n", k);
                printf("Retransmitting Window...\n");
                break;
            }
        }
        printf("\n");  // Adds a blank line after processing a window
        i = i + z;   //sliding window moves forward by numbr of ACKed frames
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

//new code
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_FRAMES 10
#define WINDOW_SIZE 4

int total_sent = 0;
int base = 1; // Starting frame number (1-indexed for display)

void transmission() {
    while (base <= TOTAL_FRAMES) {
        int ack_count = 0;

        // Sending frames in the current window
        for (int i = base; i < base + WINDOW_SIZE && i <= TOTAL_FRAMES; i++) {
            printf("Sending frame %d...\n", i);
            total_sent++;
        }

        // Receiving acknowledgments for frames
        for (int i = base; i < base + WINDOW_SIZE && i <= TOTAL_FRAMES; i++) {
            int lost = rand() % 2;  // 0: ack received, 1: ack lost
            if (lost == 0) {
                printf("Acknowledgment for frame %d received.\n", i);
                ack_count++;
            } else {
                printf("Timeout! Frame %d acknowledgment lost.\n", i);
                printf("Retransmitting window...\n");
                break;
            }
        }

        printf("\n");
        base += ack_count; // Slide the window by number of frames acknowledged
    }
}

int main() {
    srand(time(NULL));

    transmission();

    printf("Total number of frames sent (including retransmissions): %d\n", total_sent);

    return 0;
}

