#include <iostream>
#include <gb_sipserver.h>
#include <unistd.h>
using namespace std;

int main()
{
    gb_sipserver * pserver = new gb_sipserver();
    pserver->init();
    pserver->start();
    cout << "Hello world!" << endl;
    int i = 0;
    while(i<5)
    {
        i++;
        sleep(1);
    }
    pserver->stop();
    sleep(1);
    return 0;
}
