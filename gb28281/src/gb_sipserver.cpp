#include "gb_sipserver.h"

gb_sipserver::gb_sipserver()
{
    //ctor
}

gb_sipserver::~gb_sipserver()
{
    //dtors
}
int gb_sipserver::init()
{
    if(!m_pcontext)
    {
        m_pcontext =  eXosip_malloc();
        int ret = eXosip_init(m_pcontext);
        if (ret != 0)
        {
            //cout << "\t--> Couldn't initialize eXosip! <--\n";
            return -1;
        }
        printf("sipserver inited\n");
        return 0;
    }

    return -1;
}
int gb_sipserver::start()
{
    return -1;
}
