#ifndef GB_SIPSERVER_H
#define GB_SIPSERVER_H

#include<eXosip2/eXosip.h>
#include<thread>
#include<deque>
#include<mutex>
#include<condition_variable>

using namespace std;

class gb_sipserver
{
    public:
        gb_sipserver();
        virtual ~gb_sipserver();

    public:
        int init();
        int start();
        int stop();
    protected:
        void taskthread();
    private:
        bool m_brun = false;
        int m_threadpool_maxcount = 4;
        eXosip_t *m_pcontext = nullptr;
        mutex       listmutex;
        deque<eXosip_event_t *>  m_event_list;
        deque<thread *>          m_thread_pool;
        eXosip_event_t *get_event();
        void add_event(eXosip_event_t *event);

                

};

#endif // GB_SIPSERVER_H
