//server code

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd;
    struct sockaddr_in server, client;
    char buffer[1024];
    socklen_t len = sizeof(client);

   
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

   
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

  
    bind(sockfd, (struct sockaddr *)&server, sizeof(server));

    printf("Waiting for data...\n");

   
    recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&client, &len);
    printf("Message from client: %s\n", buffer);

   
    sendto(sockfd, "Hello from server", 18, 0, (struct sockaddr *)&client, len);

    close(sockfd);
    return 0;
}

//UDP Client code
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd;
    struct sockaddr_in server;
    char buffer[1024] = "Hello from client";
    char response[1024];
    socklen_t len = sizeof(server);

  
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");  // Server IP address

   
    sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&server, len);
    printf("Message sent to server\n");

   
    recvfrom(sockfd, response, sizeof(response), 0, (struct sockaddr *)&server, &len);
  
    printf("Message from server: %s\n", response);

    close(sockfd);
    return 0;
}
