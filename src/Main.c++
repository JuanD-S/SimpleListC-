#include <iostream>
#include "SimpleList.c++"

using namespace std;

int main() {    
    SimpleList<int> list;

    list.push(10);
    list.push(20);
    list.push(30);
    list.push(40);

    cout << "Lista actual:" << endl;
    list.showList();
    cout << "\n" << list.size() << endl;
    cout << "\n" << list.isEmpty() << endl;

    return 0;
}
