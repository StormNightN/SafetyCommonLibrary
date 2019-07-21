//
// Created by stormnight on 7/21/19.
//

#ifndef SAFETYCOMMON_COMMONSSLFUNCTIONS_H
#define SAFETYCOMMON_COMMONSSLFUNCTIONS_H

#include <openssl/ossl_typ.h>
#include <openssl/ssl.h>

/**
 * Contain common functions for openssl.
 */
namespace OpenSSLCommon
{
    /**
     * Function, which does OpenSSL initialization.
     * On thread safety manner.
     */
    void OpenSSLInitializing();
    
    /**
     * Create SSL context
     *
     * @param isServer  true, if server context should be created, false otherwise
     *
     * @return          SSL_CTX is not equal null, if initialization was
     *                  success, SSL context otherwise
     */
    SSL_CTX* CreateOpenSSLContext(bool isServer);

    /**
     * Free OpenSSL context
     *
     * @param pContext  free OpenSSL context
     */
    inline void FreeOpenSSLContext(SSL_CTX* pContext)
    {
        SSL_CTX_free(pContext);
    }

    /**
     * Create client socket
     *
     * @param pIpAddress    string, which represents IP address
     * @param port          target port
     * @param sd            socket descriptor
     *
     * @return              0 is operation was success, -1 otherwise
     */
    int CreateClientSocket(const char* pIpAddress, uint16_t port, int32_t& sd);
}
#endif //SAFETYCOMMON_COMMONSSLFUNCTIONS_H
