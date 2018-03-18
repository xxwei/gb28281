#include "gb_sipserver.h"
#include<sstream>
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
    m_brun = true;
    m_threadpool_maxcount = thread::hardware_concurrency();
    //printf("thread pool %d \n",m_threadpool_maxcount);
    for(int i=0;i<m_threadpool_maxcount;i++)
    {
        thread *task(new thread(std::bind(&gb_sipserver::taskthread,this)));
        task->detach();
        m_thread_pool.push_back(task);
    }
    return -1;
}
int gb_sipserver::stop()
{
    m_brun = false;
    return -1;
}
void gb_sipserver::taskthread()
{
    auto id = std::this_thread::get_id();
    stringstream ss;
    ss << id;
    string idstring = ss.str();
  
    while(m_brun)
    {
        eXosip_event_t *event = get_event();
        if(event)
        {

        }
        else
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        printf("thread is %s\n",idstring.c_str());

    }
    printf("thread exit %s\n",idstring.c_str());
}

eXosip_event_t *gb_sipserver::get_event()
{
    eXosip_event_t *event = nullptr;

    listmutex.lock();
    if(m_event_list.size())
    {
        deque<eXosip_event_t *>::iterator item = m_event_list.begin();
        event = *item;
        m_event_list.pop_front();
    }
    listmutex.unlock();
    return event;

    
}
void gb_sipserver::add_event(eXosip_event_t *event)
{
    listmutex.lock();
    m_event_list.push_back(event);
    listmutex.unlock();
}