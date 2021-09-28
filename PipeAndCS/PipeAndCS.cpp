#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

void ParseStringToInt(ifstream& input,int& value) {
    string line;
    getline(input,line);
    line.erase(remove_if(line.begin(),line.end(),::isalpha),line.end());
    value = stoi(line);
}

void ParseStringToDouble(ifstream& input,double& value) {
    string line;
    getline(input,line);
    line.erase(remove_if(line.begin(),line.end(),::isalpha),line.end());
    value = stod(line);
}

void ParseStringToBool(ifstream& input,bool& value) {
    int temp = 0;
    ParseStringToInt(input, temp);
    value = temp;
}

bool IsCorrectInput(string& s) {
    if (s[0] == '.') {
        cout << "Invalid input" << endl;
        return false;
    }
    for (auto ch : s) {
        if((ch >= '0' && ch <= '9') || ch == '.') {
            continue;
        } else {
            cout << "Invalid input" << endl;
            return false;
        }
    }
    return true;
}

int CorrectInputForInt(){
    string value;
    cin >> value;
    while(!IsCorrectInput(value)){
        cin >> value;
    }
    return stoi(value);
}

double CorrectInputForDouble(){
    string value;
    cin >> value;
    while(!IsCorrectInput(value)){
        cin >> value;
    }
    return stod(value);
}

struct Pipe {
    int id = -1;
    int diametr;
    double length;
    bool isInRepair  = false;
};


Pipe AddPipe() {
    Pipe pipe = {};
    pipe.id = 0;
    cout << "Enter diametr: ";
    pipe.diametr = CorrectInputForInt();
    cout << "Enter length: ";
    pipe.length = CorrectInputForDouble();
    return pipe;
}

void PrintPipe(const Pipe& pipe) {
    if (pipe.id != -1) {
    cout << "Pipe " << pipe.id << endl
        <<"Its character: " << endl;
    cout << "Diamter: " << pipe.diametr << endl;
    cout << "Length: " << pipe.length << endl;
    cout << "Repair satus: ";
    string result = !pipe.isInRepair ? "Pipe works" : "Pipe does not work";
    cout << result << endl;
    }
}

void ChangePipe(Pipe& pipe){
    pipe.isInRepair = !pipe.isInRepair;
}

void SavePipe(ofstream& output,const Pipe& pipe){
    if (pipe.id != -1){
    output << "Pipe" << endl
    << "id " << pipe.id << endl
    << "diametr " << pipe.diametr << endl
    << "length " << pipe.length << endl
    << "Status repair " << pipe.isInRepair << endl;
    } else {
        output << "Pipe do not exists" << endl;
    }
}

void LoadPipe(ifstream& input,Pipe& pipe) {
    string line;
    getline(input,line);
    if (line == "Pipe") {
        ParseStringToInt(input, pipe.id);
        ParseStringToInt(input, pipe.diametr);
        ParseStringToDouble(input, pipe.length);
        ParseStringToBool(input, pipe.isInRepair);
    } else {
        cout << "Pipe does not saved" << endl;
    }
}

struct CompressionStation {
    int id = -1;
    string name;
    int numberWorkshop;
    int numberWorkshopInAtive;
    double effiency;
};

CompressionStation AddCS() {
    CompressionStation station = {};
    station.id = 0;
    cout << "Enter name station: ";
    cin.ignore(1);
    getline(cin,station.name);
    cout << "Enter number of workstaions: ";
    station.numberWorkshop = CorrectInputForInt();
    cout << "Enter number of workstation in action: ";
    int countStationAction = CorrectInputForInt();
    while(countStationAction > station.numberWorkshop){
        cout << "Invalid input" << endl;
        countStationAction = CorrectInputForInt();
    }
    station.numberWorkshopInAtive = countStationAction;
    cout << "Enter station effiency: ";
    station.effiency = CorrectInputForDouble();
    return station;
}

void PrintCS(const CompressionStation& station) {
    if (station.id != -1) {
    cout << "Compressor station " << station.id << endl
    << "Its character: " << endl;
    cout << "Name: " << station.name << endl;
    cout << "Number of workstations: " << station.numberWorkshop << endl;
    cout << "Number of workstations in action: " << station.numberWorkshopInAtive << endl;
    cout << "Station effiency: " << station.effiency << endl;
    }
}

void ChangeCs(CompressionStation& station) {
    cout << "Enter number workstation in active" << endl;
    int newNumberWorkstationInAction = 0;
    newNumberWorkstationInAction = CorrectInputForInt();
    if(newNumberWorkstationInAction > station.numberWorkshop){
        cout << "Invalid input" << endl;
    } else {
        station.numberWorkshopInAtive = newNumberWorkstationInAction;
        cout << "New number of workshops: " << newNumberWorkstationInAction << endl;
    }
}

void SaveCS(ofstream& output, const CompressionStation& station){
    if (station.id != -1){
    output << "Compressor station" << endl
    << "id " << station.id << endl
    << "name " << station.name << endl
    << "number workshop " << station.numberWorkshop << endl
    << "number workshop in action " << station.numberWorkshopInAtive << endl
    << "effiency " << station.effiency;;
    } else {
        output << "Compressor station do not exists" << endl;
    }
}

void LoadCS(ifstream& input, CompressionStation& station) {
    string line;
    getline(input,line);
    if (line == "Compressor station"){
        ParseStringToInt(input, station.id);
        getline(input,station.name);
        ParseStringToInt(input, station.numberWorkshop);
        ParseStringToInt(input, station.numberWorkshopInAtive);
        ParseStringToDouble(input, station.effiency);
    } else {
        cout << "Compressor station do not saved" << endl;
    }
}

void PrintMenu(){
    cout << endl;
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
    
    for(;;){
        PrintMenu();
        int commandNumber = CorrectInputForInt();
        switch (commandNumber) {
            case 1:  
            {
                if (pipe.id == -1){
                    pipe = AddPipe();
                } else {
                    cout << "The pipe exists" << endl;
                    break;
                }
                cout << "Pipe added successfully" << endl;
                break;
            }
            case 2:
            {
                if (station.id == -1){
                    station = AddCS();
                } else {
                    cout << "The compressor station exists" << endl;
                    break;
                }
                cout << "Compressor station added successfully" << endl;
                break;
            }
            case 3:
            {
                ShowAllObject(station, pipe);
                break;
            }
            case 4:
            {
                if (pipe.id != -1){
                    ChangePipe(pipe);
                } else {
                    cout << "Pipe do not exists" << endl;
                }
                break;
            }
            case 5:
            {
                if (station.id != -1){
                ChangeCs(station);
                } else {
                    cout << "Compressor station do not exists" << endl;
                }
                break;
            }
            case 6:
            {
                ofstream output(path);
                SavePipe(output, pipe);
                SaveCS(output, station);
                output.close();
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
                return 0;
                break;
            }
            default:
                cout << "Invalid command" << endl;
        }
    }
}
