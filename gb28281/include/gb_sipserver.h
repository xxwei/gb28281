#ifndef GB_SIPSERVER_H
#define GB_SIPSERVER_H

#include<eXosip2/eXosip.h>
#include<thread>

using namespace std;

class gb_sipserver
{
    public:
        gb_sipserver();
        virtual ~gb_sipserver();

    public:
        int init();
        int start();
    protected:
    private:
    int threadpool_maxcount;
    eXosip_t *m_pcontext = nullptr;
};

#endif // GB_SIPSERVER_H
