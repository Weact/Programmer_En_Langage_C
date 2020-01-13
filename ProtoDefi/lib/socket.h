
#if defined (WIN32)

    #include <winsock2.h>

    typedef int socklen_t;

#endif // defined

#include <stdio.h>
#include <stdlib.h>


//METHODES SOCKETS
void initSocket()
{
    //Plateforme = windows
    #if defined (WIN32)

        WSADATA WSAData;
        WSAStartup(MAKEWORD(2,2), &WSAData);

    #endif // defined
}

void closeSocket()
{
    //Plateforme = windows
    #if defined (WIN32)

        WSACleanup();

    #endif // defined
}
