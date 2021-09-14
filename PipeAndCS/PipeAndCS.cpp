#include <iostream>

using namespace std;

struct Pipe {
    int id;
    int diametr;
};


void printPipe(const Pipe& p) {
    cout << "Pipe number of " << p.id << " with diametr " << p.diametr;
}

int main()
{
    Pipe p = {};
    cout << "Enter diametr: ";
    cin >> p.diametr;
    printPipe(p);
}
