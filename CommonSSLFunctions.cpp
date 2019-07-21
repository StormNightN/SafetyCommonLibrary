#include "CommonSSLFunctions.h"

#include <openssl/bio.h>
#include <openssl/err.h>
#include <mutex>


namespace OpenSSLCommon
{
    /**
     * METHOD NAME OpenSSLCommon::OpenSSLInitializing
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
}