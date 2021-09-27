#include <iostream>
#include "Funtional.h"
#include "Pipe.h"
#include "CompressorStation.h"

using namespace std;

void ShowAllObject(const CompressionStation& station, const Pipe& pipe){
    if(station.id == -1 && pipe.id == -1){
        cout << "Object do not exist" << endl;
    } else {
        PrintPipe(pipe);
        PrintCS(station);
    }
}

int main()
{
    const string path = "saves.txt";
    Pipe pipe = {};
    CompressionStation station  = {};
    PrintMenu();
    bool statusProgram = true;
    for(;statusProgram;){
        int commandNumber = CorrectInputForInt();
        switch (commandNumber) {
            case 1:  
            {
                if (pipe.id == -1){
                    pipe = AddPipe();
                } else {
                    cout << "The pipe exists" << endl;
                    cout << "Enter command number: " << endl;
                    break;
                }
                cout << "Pipe added successfully" << endl;
                cout << "Enter command number: " << endl;
                break;
            }
            case 2:
            {
                if (station.id == -1){
                    station = AddCS();
                } else {
                    cout << "The compressor station exists" << endl;
                    cout << "Enter command number: " << endl;
                    break;
                }
                cout << "Compressor station added successfully" << endl;
                cout << "Enter command number: " << endl;
                break;
            }
            case 3:
            {
                ShowAllObject(station, pipe);
                cout << "Enter command number: " << endl;
                break;
            }
            case 4:
            {
                if (pipe.id != -1){
                    ChangePipe(pipe);
                } else {
                    cout << "Pipe do not exists" << endl;
                }
                cout << "Enter command number: " << endl;
                break;
            }
            case 5:
            {
                if (station.id != -1){
                ChangeCs(station);
                } else {
                    cout << "Compressor station do not exists" << endl;
                }
                cout << "Enter command number: " << endl;
                break;
            }
            case 6:
            {
                ofstream output(path, ios::app);
                ofstream clearFile(path);
                SavePipe(output, pipe);
                SaveCS(output, station);
                cout << "Saved successfully" << endl;
                break;
            }
            case 7:
            {
                ifstream input(path);
                LoadPipe(input, pipe);
                LoadCS(input, station);
                cout << "Loading completed" << endl;
                break;
            }
            case 0:
            {
                cout << "Program execution completed" << endl;
                statusProgram = false;
                break;
            }
            default:
                cout << "Invalid command" << endl;
                cout << "Enter command number: " << endl;
        }
    }
}


