#include <string>
#include <sstream>
using namespace std;
#define REQUEST_CPP

class request
{
public:
    string start;  //!< source IP
    string finish; //!< destination IP
    int time;      //!< time to process the request

    /**
     * this method generates the IP addresses for the request processing
     */
    void createIPRequest()
    {
        stringstream startIP, finishIP;
        for (int i = 0; i < 3; i++)
        {
            startIP << (rand() % 256) << ".";
            finishIP << (rand() % 256) << ".";
        }
        startIP << (rand() % 256);
        finishIP << (rand() % 256);

        start = startIP.str();
        finish = finishIP.str();
        time = rand() % 500;
    }
};