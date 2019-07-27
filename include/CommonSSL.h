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
namespace OpenSSL
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

}

#endif //SAFETYCOMMON_COMMONSSLFUNCTIONS_H