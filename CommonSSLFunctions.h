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
     * @return  SSL_CTX is not equal null, if initialization was
     *          success, SSL context otherwise
     */
    inline SSL_CTX* CreateOpenSSLContext(bool isServer)
    {
        return isServer ? SSL_CTX_new(SSLv23_server_method()) :
            SSL_CTX_new(SSLv23_client_method());
    }

    /**
     * Free OpenSSL context
     *
     * @param pContext  free OpenSSL context
     */
    inline void FreeOpenSSLContext(SSL_CTX* pContext)
    {
        SSL_CTX_free(pContext);
    }
}
#endif //SAFETYCOMMON_COMMONSSLFUNCTIONS_H
