#ifndef REQUEST_CPP
#include "request.cpp"
#endif

class webServer
{
public:
    request r;    //!< requests that will be added to the server
    int starting; //!< the start time for processing
    char name;    //!< names of the servers

    webServer()
    {
        starting = 0;
        name = ' ';
    }

    webServer(char c)
    {
        starting = 0;
        name = c;
    }

    /**
     *  add request to the server and update starting time
     */
    void addReq(request req, int now)
    {
        r = req;
        starting = now;
    }

    /**
     * check to see if the request is completed based on the time specified
     */
    bool requestFinished(int now)
    {
        if (now >= (starting + r.time))
        {
            return true;
        }
        return false;
    }
};