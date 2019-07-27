//
// Created by stormnight on 7/27/19.
//
#include <mutex>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <memory.h>
#include <unistd.h>

namespace Networking
{
    /**
     * METHOD NAME: Networking::CreateClientSocket
     */
    int CreateClientSocket(const char* pIpAddress, uint16_t port, int32_t& sd)
    {
        sockaddr_in addr{};

        sd = socket(PF_INET, SOCK_STREAM, 0);
        if (sd == -1)
        {
            return -1;
        }

        bzero(&addr, sizeof(addr));

        addr.sin_family = AF_INET;
        addr.sin_port = ntohs(port);
        if (inet_aton(pIpAddress, &addr.sin_addr) == 0)
        {
            return -1;
        }

        if (connect(sd, (sockaddr*)(&addr), sizeof(addr)) != 0)
        {
            return -1;
        }

        return 0;
    }

    /**
     * METHOD NAME: Networking::CreateServerSocket
     */
    int CreateServerSocket(uint16_t port, int32_t& sd, int n)
    {
        sockaddr_in addr{};

        sd = socket(PF_INET, SOCK_STREAM, 0);
        if (sd == -1)
        {
            return -1;
        }

        bzero(&addr, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port =htons(port);
        addr.sin_addr.s_addr = INADDR_ANY;

        if (bind(sd, (sockaddr*)(&addr), sizeof(addr)) != 0)
        {
            return -1;
        }

        if (listen(sd, n) != 0)
        {
            return -1;
        }

        return 0;
    }

    /**
     * METHOD NAME: Networking::CloseSocket
     */
    int CloseSocket(int32_t& sd)
    {
        return close(sd);
    }
}