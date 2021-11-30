#include "Network.h"

void Network::AddPipe()
{
    string name;
    int diametr;
    double length;
    cout << "Enter name: ";
    cin.ignore(1);
    getline(cin, name);
    cout << "Enter diametr: ";
    CorrectInput(diametr);
    cout << "Enter length: ";
    CorrectInput(length);
    Pipe p(name, diametr, length, true);
    while (dataPipe.contains(max_id_pipe)) {
        ++max_id_pipe;
    }
    dataPipe.emplace(max_id_pipe++, p);
}
