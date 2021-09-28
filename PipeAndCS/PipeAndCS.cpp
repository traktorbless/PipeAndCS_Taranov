#include <iostream>
#include <vector>
#include <fstream>

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
    value = temp == 0 ? false : true;
}

bool CheckCorrectInput(string& s) {
    if (s[0] == '.') {
        return false;
    }
    vector<char> correctNumbers = {'1','2','3','4','5','6','7','8','9','0','.'};
    for (auto i : s) {
        if(count(begin(correctNumbers),end(correctNumbers),i) == 1) {
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
    while(!CheckCorrectInput(value)){
        cin >> value;
    }
    return stoi(value);
}

double CorrectInputForDouble(){
    string value;
    cin >> value;
    while(!CheckCorrectInput(value)){
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
    pipe.length = CorrectInputForInt();
    return pipe;
}

void PrintPipe(const Pipe& pipe) {
    if (pipe.id != -1) {
    cout << "Pipe " << pipe.id << endl
        <<"Her character: " << endl;
    cout << "Diamter: " << pipe.diametr << endl;
    cout << "Length: " << pipe.length << endl;
    cout << "Repair satus: ";
    if (!pipe.isInRepair) {
        cout << "Station is work" << endl;
    }
    else {
        cout << "Station does not work" << endl;
    }
    }
}

void ChangePipe(Pipe& pipe){
    pipe.isInRepair = !pipe.isInRepair;
    if (pipe.isInRepair){
        cout << "Status of the pipe: under repair" << endl;
    } else {
        cout << "Status of the pipe: in progress" << endl;
    }
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
        cout << "Pipe do not saved" << endl;
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
    cin >> station.name;
    cout << "Enter number of workstaions: ";
    station.numberWorkshop = CorrectInputForInt();
    cout << "Enter number of workstation in action: ";
    int countStationAction = CorrectInputForInt();
    while(countStationAction > station.numberWorkshop){
        cout << "Invalid input" << endl;
        cin >> countStationAction;
    }
    station.numberWorkshopInAtive = countStationAction;
    cout << "Enter station effiency: ";
    station.effiency = CorrectInputForDouble();
    return station;
}

void PrintCS(const CompressionStation& station) {
    if (station.id != -1) {
    cout << "Compressor station " << station.id << endl
    << "Her character: " << endl;
    cout << "Name: " << station.name << endl;
    cout << "Number of workstations: " << station.numberWorkshop << endl;
    cout << "Number of workstations in action: " << station.numberWorkshopInAtive << endl;
    cout << "Station effiency: " << station.effiency << endl;
    }
}

void ChangeCs(CompressionStation& station) {
    cout << "Enter number workstation in active" << endl;
    int newNumberWorkstationInAction = 0;
    cin >> newNumberWorkstationInAction;
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
    << "effiency " << station.effiency;
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
