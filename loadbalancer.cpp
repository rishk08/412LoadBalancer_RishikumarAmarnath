#ifndef LOADBALANCER_H
#include "loadbalancer.h"
#endif

void loadBalancer::add(request r) /*!\fn add a new request to the load balancer*/
{
    rQueue.push(r);
    theTime++;
}

request loadBalancer::get() /*!\fn get the request that's at the front of the queue to place in server*/
{
    theTime++;
    if (!rQueue.empty())
    {
        request r = rQueue.front();
        rQueue.pop();
        return r;
    }
}