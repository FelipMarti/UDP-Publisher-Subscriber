
/* Sample UDP publisher */

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char**argv)
{
   int sockfd;
   struct sockaddr_in servaddr;
   char sendline[1000];

   sockfd=socket(AF_INET,SOCK_DGRAM,0);

   servaddr.sin_family = AF_INET;
   servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
   servaddr.sin_port=htons(32100);

   printf("Publishing...\n");
   
   int i=0;
   while (i < 100000) {
      sprintf(sendline, "Interation number %d \n", i);
      sendto(sockfd,sendline,strlen(sendline),0,
             (struct sockaddr *)&servaddr,sizeof(servaddr));
      i++;
   }

   printf("DONE!\n");

}
