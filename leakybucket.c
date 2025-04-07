#include<stdio.h>
void main()
{
    int n,in,out,bsize,bucket=0,possible;
    printf("Enter the no of inputs:\n");
    scanf("%d",&n);
    printf("Enter bucket size:");
    scanf("%d",&bsize);
    printf("enter outgoing rate:");
    scanf("%d",&out);
    while(n!=0)
    {
        printf("enter no of incoming packets:");
        scanf("%d",&in);
        if(in <= (bsize - bucket))
        {
            bucket+=in;
            printf("Bucket status:%d out of %d\n",bucket,bsize);
        }
        else
        {
            printf("dropped:%d\n",in-(bsize-bucket));
            printf("bucket status:%d out of %d\n",bucket,bsize);
            bucket=bsize;     //bucket full
            
        }
        
        if (bucket < out)
            bucket = 0;
        else
           bucket=bucket-out;

        
        printf("bucket status:%d out of %d\n",bucket,bsize);
        n--;
    }
}
