//
// Created by stormnight on 7/21/19.
//

#ifndef SAFETYCOMMON_COMMONSSLFUNCTIONS_H
#define SAFETYCOMMON_COMMONSSLFUNCTIONS_H

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
}
#endif //SAFETYCOMMON_COMMONSSLFUNCTIONS_H
