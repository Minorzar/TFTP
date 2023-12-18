#include "gettftp.h"



void receiveDataPacket(int clientSocket, FILE* file) {
    struct TFTP_Packet data_packet;
    int bytesRead;

    if ((bytesRead = recv(clientSocket, &data_packet, sizeof(data_packet), 0)) == -1) {
        perror("Error receiving DATA");
        exit(EXIT_FAILURE);
    }

    // Check opcode for DATA
    if (ntohs(data_packet.opcode) != 3) {
        printf("Unexpected packet received.\n");
        exit(EXIT_FAILURE);
    }

    // Write data to file
    fwrite(data_packet.content.data, 1, bytesRead - 4, file);

    // Send ACK packet to server
    struct TFTP_Packet ack_packet;
    ack_packet.opcode = htons(4);  // Opcode for ACK
    ack_packet.content.block_num = data_packet.content.block_num;

    if (send(clientSocket, &ack_packet, sizeof(ack_packet), 0) == -1) {
        perror("Error sending ACK");
        exit(EXIT_FAILURE);
    }
}
