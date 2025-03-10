#include <iostream>
#include "SimpleList.c++"

using namespace std;

int main() {    
    SimpleList<int> list;

    list.push(10);
    list.push(20);
    list.push(30);
    list.push(40);

    cout << "\nLista actual:" << endl;
    list.showList();
    cout << "\nsize: " << list.size() << endl;
    cout << "La lista esta vacia?: " << list.isEmpty() << endl;

    cout << "Ultimo dato eliminado: " << list.pull() << endl;
    list.showList();
    cout << "\nsize: " << list.size() << endl;

    cout << "\ndato eliminado: " << list.removeAt(1) << endl;
    list.showList();
    cout << "\nEste dato existe?: " << list.exists(30) << endl;


    return 0;
}
