#include <stdio.h>
#include <stdlib.h>
#include "lib/methodes.c"
#include "lib/socket.c"

int main(void)
{
    initSocket();

    SOCKET sock;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    inet_addr("127.0.0.1");
    SOCKADDR_IN sin;
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(23);

    bind(sock, (SOCKADDR*)&sin, sizeof(sin));

    listen(sock, 5);
    socklen_t taille = sizeof(csin);
    csock = accept(sock , (SOCKADDR*)&csin, &taille);

    closesocket(sock);

    closeSocket();

    return EXIT_SUCCESS;
}
