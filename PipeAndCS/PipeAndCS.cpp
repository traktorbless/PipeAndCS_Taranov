// Добавить сохранение и загрузку из файла
// Сделать проверку коректности ввода


#include <iostream>
#include "Pipe.h"
#include "CompressorStation.h"
#include <fstream>
#include <vector>

using namespace std;

void ShowAllObject(const CompressionStation& station, const Pipe& pipe){
    if(station.id == -1 && pipe.id == -1){
        cout << "Object do not exist" << endl;
    } else {
        PrintPipe(pipe);
        PrintCS(station);
    }
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
    cout << "Enter command number: " << endl;
}

int main()
{
    Pipe pipe = {};
    CompressionStation station  = {};
    int commandNumber = 0;
    PrintMenu();
    bool statusProgram = true;
    for(;statusProgram;){
        cin >> commandNumber;
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
                cout << "Pipe added successfully" << endl;
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
                cout << "Program execution completed";
                statusProgram = false;
                break;
            }
            default:
                cout << "Invalid command" << endl;
                cout << "Enter command number: " << endl;
        }
    }
}


