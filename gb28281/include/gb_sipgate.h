#ifndef GB_SIPGATE_H
#define GB_SIPGATE_H

#include<eXosip2/eXosip.h>
#include<thread>
using namespace std;

class gb_sipgate
{
    public:
        gb_sipgate();
        virtual ~gb_sipgate();
    public:
        int init();
        int start();
    protected:
    private:
        eXosip_t *m_pcontext = nullptr;
};

#endif // GB_SIPGATE_H
