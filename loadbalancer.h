#define LOADBALANCER_H

#ifndef REQUEST_CPP
#include "request.cpp"
#endif

#include <queue>

class loadBalancer
{
public:
    int theTime;           //!< time in the load balancer
    queue<request> rQueue; //!< request queue that will be placing the requests in the servers

    loadBalancer()
    {
        theTime = 0;
    }
    /**
     * add a new request to the load balancer
     */
    void add(request r);

    /**
     * get the request that's at the front of the queue to place in server
     */
    request get();
};
