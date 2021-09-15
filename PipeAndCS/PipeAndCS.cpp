#include <iostream>
#include "Pipe.h"
#include "CompressorStation.h"

using namespace std;


void ShowAllObject(const CompressionStation& station, const Pipe& pipe){
    PrintPipe(pipe);
    PrintCS(station);
}

void PrintMenu(){
    cout << "1.Add pipe" << endl;
    cout << "2.Add compressor station" << endl;
    cout << "3.Show all object" << endl;
    cout << "4.Change pipe" << endl;
    cout << "5.Change compressor station" << endl;
    cout << "6.Save" << endl;
    cout << "7.Load" << endl;
    cout << "0.Exit" << endl;
}

int main()
{
}


