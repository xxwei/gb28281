#include <iostream>
#include <gb_sipserver.h>
using namespace std;

int main()
{
    gb_sipserver * pserver = new gb_sipserver();
    pserver->init();
    pserver->start();
    cout << "Hello world!" << endl;
    return 0;
}
