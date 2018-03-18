#include "gb_sipgate.h"

gb_sipgate::gb_sipgate()
{
    //ctor
}

gb_sipgate::~gb_sipgate()
{
    //dtor
}
int gb_sipgate::init()
{
    int ret = eXosip_init(m_pcontext);
    if(ret!=0)
    {
        return -1;
    }
    return -1;
}
