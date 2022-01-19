//
//  Console.cpp
//  PipeAndCs
//
//  Created by Антон Таранов on 14.12.2021.
//

#include "Console.h"
#include <iostream>

using namespace std;

void PrintMainMenu(){
    cout << endl;
    cout << "1.Pipes" << endl;
    cout << "2.Compressor stations" << endl;
    cout << "3.Network" << endl;
    cout << "4.Show all object" << endl;
    cout << "5.Save" << endl;
    cout << "6.Load" << endl;
    cout << "0.Exit" << endl;
    cout << "Enter command number: " << endl;
}

void PrintPipesMenu() {
    cout << endl;
    cout << "1.Add pipe" << endl;
    cout << "2.Find by filter" << endl;
    cout << "3.Print all pipes" << endl;
    cout << "0.Cancel" << endl;
}

void PrintCSMenu() {
    cout << endl;
    cout << "1.Add CS" << endl;
    cout << "2.Find by filter" << endl;
    cout << "3.Print all compressor stations" << endl;
    cout << "0.Cancel" << endl;
}

void NetworkMenu() {
    cout << endl;
    cout << "1.Connect" << endl;
    cout << "2.Disconnect" << endl;
    cout << "3.Topology Sort" << endl;
    cout << "4.Print all connections" << endl;
    cout << "5.Find shortcut" << endl;
    cout << "6.Find max stream" << endl;
    cout << "0.Cancel" << endl;
}

void ActionMenu() {
    cout << endl;
    cout << "1.Delete all" << endl;
    cout << "2.Delete selecte" << endl;
    cout << "3.Change all" << endl;
    cout << "4.Change selecte" << endl;
    cout << "0.Cancel" << endl;
}

void PrintFiltersForPipe() {
    cout << endl;
    cout << "1.Find by status repair" << endl;
    cout << "2.Find by name" << endl;
}

void PrintFiltersForCS() {
    cout << endl;
    cout << "1.Find by percent" << endl;
    cout << "2.Find by name" << endl;
}
