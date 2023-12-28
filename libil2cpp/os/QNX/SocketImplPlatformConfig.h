#pragma once

#include <netinet/in.h>
#include <sys/socket.h>     // posix sockets

struct ip_mreqn
{
    struct  in_addr imr_multiaddr;
    struct  in_addr imr_address;
};
