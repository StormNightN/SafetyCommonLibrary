//
// Created by stormnight on 7/27/19.
//

#ifndef SAFETYCOMMON_NETWORKING_H
#define SAFETYCOMMON_NETWORKING_H

#include <cstdint>

/**
 * Contains common networking function
 */
namespace Networking
{
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

    /**
     * Close socket descriptor
     *
     * @param sd            socket descriptor
     *
     * @return              result of closing operation
     * @retval              0  operation success
     * @retval              -1 unsuccessful operation
     *
     */
    int CloseSocket(int32_t& sd);
}

#endif //SAFETYCOMMON_NETWORKING_H