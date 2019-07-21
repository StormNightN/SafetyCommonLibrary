#include "CommonSSLFunctions.h"

#include <openssl/bio.h>
#include <openssl/err.h>
#include <mutex>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <memory.h>


namespace OpenSSLCommon
{
    /**
     * METHOD NAME: OpenSSLCommon::OpenSSLInitializing
     */
    void OpenSSLInitializing()
    {
        static bool wasInitialized = false;
        static std::mutex openSSLInitializationGuard;
        std::lock_guard<std::mutex> guard{ openSSLInitializationGuard };

        if(!wasInitialized)
        {
            SSL_load_error_strings();
            ERR_load_BIO_strings();
            OpenSSL_add_all_algorithms();

            SSL_library_init();
        }
    }

    /**
     * METHOD NAME: OpenSSLCommon::CreateOpenSSLContext
     */
    SSL_CTX* CreateOpenSSLContext(bool isServer)
    {
        SSL_CTX* result = isServer ? SSL_CTX_new(SSLv23_server_method()) :
                                     SSL_CTX_new(SSLv23_client_method());
        if (result == nullptr)      // error was occurred
        {
            ERR_print_errors_fp(stderr);
        }

        return result;
    }

    /**
     * METHOD NAME: OpenSSLCommon::CreateClientSocket
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
     * METHOD NAME: OpenSSLCommon::CreateServerSocket
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
}