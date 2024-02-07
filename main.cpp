#include "myVector.hpp"

using namespace std;

int main(void)
{
    myVector<int> vt{11,22,33,44};
    vt.display();
    vt.push_front(10);
    vt.display();
    vt.push_back(99);
    vt.push_back(98);
    vt.push_back(97);
    vt.push_back(96);
    vt.push_back(95);
    vt.display();
    vt.erease(vt.end() - 2);
    vt.display();
    cout << vt.front() << endl;
    cout << vt.back() << endl;
    cout << *(vt.data()) << endl;
    vt.erease(vt.begin() - 1, vt.begin() + 2U);
    vt.display();
    return 0;
}