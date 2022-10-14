#include <iostream>

#include "request.cpp"
#include "webserver.cpp"
#include "loadbalancer.h"

using namespace std;

int main()
{
    loadBalancer theBalancer;
    int serverCount = 0;
    int timeToRun = 0;
    int initialRequests = 0;
    int numTimesofRequests = 0;

    cout << "How many servers do you want to process the load on? ";
    cin >> serverCount;
    cout << "How many cycles do you want to run the balancer? ";
    cin >> timeToRun;
    cout << "How many requests do you want to create initially? ";
    cin >> initialRequests;
    cout << "How many times do you want requests to be generated? ";
    cin >> numTimesofRequests;

    webServer theServers[serverCount];

    for (int i = 0; i < initialRequests; i++) /*< add the random requests to the balancer*/
    {
        request gen;
        gen.createIPRequest();
        theBalancer.add(gen);
    }

    for (int j = 0; j < serverCount; j++) /*< add the requests to the array of webservers with names*/
    {
        webServer web((char)(j + 65));
        theServers[j] = web;
        theServers[j].addReq(theBalancer.get(), theBalancer.theTime);
    }

    while (theBalancer.theTime < timeToRun) /*< within the number of cycles that the user has specified*/
    {
        int whichServer = theBalancer.theTime % serverCount;
        if (theServers[whichServer].requestFinished(theBalancer.theTime)) /*< if request is complete, then print out to the system*/
        {
            request req = theServers[whichServer].r;
            cout << "At " << theBalancer.theTime << theServers[whichServer].name << " processed request from " << req.start << " to " << req.finish << endl;
            theServers[whichServer].addReq(theBalancer.get(), theBalancer.theTime);
        }

        if (rand() % numTimesofRequests == 0)
        {
            request gen;
            gen.createIPRequest();
            theBalancer.add(gen);
        }
        theBalancer.theTime++;
    }

    for (int i = 0; i < serverCount; i++)
    {
        if (theServers[i].r.time != 0)
        {
            cout << "Requests left";
        }
    }
}