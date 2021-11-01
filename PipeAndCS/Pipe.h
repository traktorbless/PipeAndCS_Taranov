#pragma once
#include <vector>

class Pipe {
public:
    
    Pipe(int new_diametr, double new_length, bool new_status, int new_id);
    
    void ChangeStatusRepair();
    
    bool GetStatusRepair() const;
    
    int GetId() const;
    
    int GetDiametr() const;
    
    double GetLength() const;
    
private:
    int id;
    static int max_id;
    int diametr;
    double length;
    bool statusRepair;
};

class DatabasePipe {
public:
    void AddPipe();
    
    void DelPipe(std::vector<Pipe>::const_iterator it);
    
    void ChangePipe(std::vector<Pipe>::const_iterator it);
    
    void PrintPipes(std::ostream& os) const;
    
    void LoadPipe(std::istream& is);
    
    void ChangeSetById(int id1,int id2);
    
    void ChangeSetByStatus(bool status);
    
    std::vector<Pipe>::const_iterator FindById(int id) const;
    
    std::vector<Pipe> FindByStatusRepair(bool status) const;
private:
    std::vector<Pipe> db;
};

std::ostream& operator<<(std::ostream& os,const Pipe& pipe);

//Pipe AddPipe() {
//    Pipe pipe = {};
//    pipe.id = 1;
//    cout << "Enter diametr: ";
//    CorrectInput(pipe.diametr);
//    cout << "Enter length: ";
//    CorrectInput(pipe.length);
//    return pipe;
//}

//void PrintPipe(const Pipe& pipe) {
//    if (pipe.id != -1) {
//    cout << "Pipe " << pipe.id << endl
//        <<"Its character: " << endl;
//    cout << "Diamter: " << pipe.diametr << endl;
//    cout << "Length: " << pipe.length << endl;
//    cout << "Repair satus: ";
//    string result = !pipe.isInRepair ? "Pipe works" : "Pipe does not work";
//    cout << result << endl;
//    } else {
//        cout << "Pipe does not exist" << endl;
//    }
//}

//void ChangePipe(Pipe& pipe){
//    pipe.isInRepair = !pipe.isInRepair;
//}

//void SavePipe(ofstream& output,const Pipe& pipe){
//    if (pipe.id != -1){
//    output << "Pipe" << endl
//    << "id " << pipe.id << endl
//    << "diametr " << pipe.diametr << endl
//    << "length " << pipe.length << endl
//    << "Status repair " << pipe.isInRepair << endl;
//    } else {
//        output << "Pipe does not exist" << endl;
//    }
//}

//void LoadPipe(ifstream& input,Pipe& pipe) {
//    string line;
//    getline(input,line);
//    if (line == "Pipe") {
//        ParseString(input, pipe.id);
//        ParseString(input, pipe.diametr);
//        ParseString(input, pipe.length);
//        ParseString(input, pipe.isInRepair);
//    } else {
//        cout << "Pipe did not save" << endl;
//    }
//}

