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


Ith ayalo
