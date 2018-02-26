#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<linux/ip.h>
#include<linux/icmp.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include"pcap.h"
#include "utility.c"

int main(void)
{
  /* Allocate a buffer large enough to hold IP and ICMP header */
  	char* packet = (char*)malloc(
  			  sizeof(struct iphdr) + sizeof(struct icmphdr));

  /* Declare pointers to appropriately offset IP and ICMP headers */
  	struct iphdr* ip = (struct iphdr*)packet;

  	struct icmphdr* icmp = (struct icmphdr*)(packet + sizeof(struct iphdr));

  /* Populate the headers with data */
  	icmp->type = ICMP_ECHO;	
  	icmp->un.echo.id = rand();
  	icmp->code = 0;
  	icmp->checksum = 0;
  	icmp->un.echo.sequence = rand();
  	

  	ip->saddr = inet_addr("192.168.0.33");
  	ip->daddr = inet_addr("255.255.255.255");
  	ip->version = 4;
  	ip->ihl = 5;
  	ip->tos = 0;
  	ip->tot_len = htons(sizeof(struct iphdr) + sizeof(struct icmphdr));
  	ip->id = rand ();
  	ip->frag_off = 0;
  	ip->ttl = 255;
  	ip->protocol = IPPROTO_ICMP;

  	icmp->checksum = in_checksum((unsigned short*)icmp, sizeof(icmp));

  /* Write the buffer to file using write_pcap() */

  	write_pcap("packet", packet, sizeof(struct iphdr) + sizeof(struct icmphdr));
  	

  /* Free dynamic memory */
  	free(packet);
  
  return EXIT_SUCCESS;
}
