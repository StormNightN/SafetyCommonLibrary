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
     * @return          SSL context
     * @retval          nullptr unsuccessful initialization
     * @retval          not nullptr successful initialization
     *
     */
    SSL_CTX* CreateOpenSSLContext(bool isServer);

    /**
     * Free OpenSSL context
     *
     * @param pContext  free OpenSSL context
     *
     */
    void FreeOpenSSLContext(SSL_CTX* pContext);

    /**
     * Create client socket
     *
     * @param pIpAddress    string, which represents IP address
     * @param port          target port
     * @param sd            socket descriptor
     *
     * @return              operation result
     * @retval              0  operation success
     * @retval              -1 unsuccessful operation
     *
     */
    int CreateClientSocket(const char* pIpAddress, uint16_t port, int32_t& sd);

    /**
     * Create server socket
     *
     * @param port          port, on which server will be listen
     * @param sd            socket descriptor
     * @param n             count parallel accepted connection
     *
     * @return              operation result
     * @retval              0  operation success
     * @retval              -1 unsuccessful operation
     *
     */
    int CreateServerSocket(uint16_t port, int32_t& sd, int n);
}
#endif //SAFETYCOMMON_COMMONSSLFUNCTIONS_H
