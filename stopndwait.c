#include<stdio.h>
#include<stdlib.h> //rand,srand
#include<time.h>
#include<unistd.h> //for sleep()

#define TIMEOUT 3  // no of seconds before trans if ACK lost
#define TOTAL_PACKETS 5  //no of packets to send

int simulate_ack()
{
    return rand()%10<7; //fn decides if reciever successfully ack the packet
}

int main()
{
    srand(time(0)); //ensures each time rand() produce different values
    int packet=1;  //start sending packets from 1
    int ack_recieved; //stores if ack recieved
    
    while(packet<= TOTAL_PACKETS)
    {
        printf("Sender:Sending packet %d....\n",packet);
        sleep(1);  //pauses prgm for 1 sec
        ack_recieved =simulate_ack();
        if(ack_recieved)  //if ack_recieved=1
        {
            printf("Reciever:ACK for packet %d recieved.\n\n",packet);
            packet++;
        }
        else   //if ack_recieved=0
        {
            printf("Reciever:ACK for packet %d lost!Retransmitting....\n\n",packet);
            sleep(TIMEOUT); //sender waits for TIMEOUT sec(3) before retransmittin
            
        }
       
        
    }
     printf("All packets sent succesfully\n");
    return 0;
}
