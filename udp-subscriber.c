
/* Sample UDP subscriber */

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char**argv)
{
   int sockfd,n;
   struct sockaddr_in servaddr,cliaddr;
   socklen_t len;
   char mesg[1000];

   sockfd=socket(AF_INET,SOCK_DGRAM,0);

   servaddr.sin_family = AF_INET;
   servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
   servaddr.sin_port=htons(32100);
   bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));

   while (1)
   {
      len = sizeof(cliaddr);
      n = recvfrom(sockfd,mesg,1000,MSG_DONTWAIT,(struct sockaddr *)&cliaddr,&len);
      if (n>0) {
          mesg[n] = 0;
          printf("Received the following: ");
          printf("%s",mesg);
      }
   }
}
