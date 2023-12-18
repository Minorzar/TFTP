#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 516
#define DATA_PACKET_SIZE 512

#define GETTFTP "gettftp"

// Structure for TFTP packets
struct TFTP_Packet {
    short opcode;
    union {
        short block_num;
        char data[DATA_PACKET_SIZE];
    } content;
};

void receiveDataPacket(int, FILE*) ;