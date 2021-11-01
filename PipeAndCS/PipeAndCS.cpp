#include "Pipe.h"
#include "CompressorStation.h"
#include "Function.h"

using namespace std;

void PrintMainMenu(){
    cout << endl;
    cout << "1.Pipes" << endl;
    cout << "2.Compressor stations" << endl;
    cout << "3.Show all object" << endl;
    cout << "4.Save" << endl;
    cout << "5.Load" << endl;
    cout << "0.Exit" << endl;
    cout << "Enter command number: " << endl;
}

void PrintPipesMenu() {
    cout << endl;
    cout << "1.Add pipe" << endl;
    cout << "2.Delete pipe" << endl;
    cout << "3.Change pipe" << endl;
    cout << "4.Find pipe by id" << endl;
    cout << "5.Find pipes by status repair" << endl;
    cout << "6.Print all pipes" << endl;
    cout << "7.Change set by id" << endl;
    cout << "8.Change set by status" << endl;
    cout << "0.Cancel" << endl;
}

void PrintCSMenu() {
    cout << endl;
    cout << "1.Add CS" << endl;
    cout << "2.Delete CS" << endl;
    cout << "3.Change CS" << endl;
    cout << "4.Find cs by id" << endl;
    cout << "5.Find cs by name" << endl;
    cout << "6.Find cs by percent" << endl;
    cout << "7.Print all compressor stations" << endl;
    cout << "8.Change set by id" << endl;
    
    cout << "0.Cancel" << endl;
}

enum class COMMAND {
    PIPES = 1, CS = 2, SHOW_ALL_OBJECT = 3, SAVE = 4, LOAD = 5, EXIT = 0
};

enum class PIPE_COMMAND {
    ADD_PIPE = 1, DEL_PIPE = 2, CHANGE_PIPE = 3, FIND_BY_ID = 4, FIND_BY_STATUS = 5, PRINT_ALL_PIPES = 6,
    CHANGE_SET_BY_ID = 7, CHANGE_SET_BY_STATUS = 8 ,CANCEL = 0
};

enum class CS_COMMAND {
    ADD_CS = 1, DEL_CS = 2, CHANGE_CS = 3, FIND_BY_ID = 4, FIND_BY_NAME = 5, FIND_BY_PERCENT = 6, PRINT_ALL_CS = 7,
    CHANGE_SET_BY_ID = 8,CANCEL = 0
};

int main()
{
    DatabasePipe dataPipe;
    DatabaseCS dataCS;
    for(;;){
        PrintMainMenu();
        int commandNumber = 0;
        CorrectInput(commandNumber);
        switch (commandNumber) {
            case static_cast<int>(COMMAND::PIPES):
            {
                PrintPipesMenu();
                CorrectInput(commandNumber);
                switch(commandNumber) {
                    case static_cast<int>(PIPE_COMMAND::ADD_PIPE):
                    {
                        dataPipe.AddPipe();
                        break;
                    }
                    case static_cast<int>(PIPE_COMMAND::DEL_PIPE):
                    {
                        cout << "Enter id" << endl;
                        int id;
                        CorrectInput(id);
                        try{
                            auto it = dataPipe.FindById(id);
                            dataPipe.DelPipe(it);
                        } catch(exception& e){
                            cout << e.what();
                        }
                        break;
                    }
                    case static_cast<int>(PIPE_COMMAND::CHANGE_PIPE):
                    {
                        cout << "Enter id" << endl;
                        int id;
                        CorrectInput(id);
                        try{
                            auto it = dataPipe.FindById(id);
                            dataPipe.ChangePipe(it);
                        }catch (exception& e) {
                            cout << e.what();
                        }
                        break;
                    }
                    case static_cast<int>(PIPE_COMMAND::FIND_BY_ID):
                    {
                        cout << "Enter id" << endl;
                        int id;
                        CorrectInput(id);
                        try{
                            auto it = dataPipe.FindById(id);
                            cout << *it;
                        } catch(exception& e) {
                            cout << e.what();
                        }
                        break;
                    }
                    case static_cast<int>(PIPE_COMMAND::FIND_BY_STATUS):
                    {
                        cout << "Enter status repair" << endl;
                        bool status;
                        CorrectInput(status);
                        vector<Pipe> result = dataPipe.FindByStatusRepair(status);
                        if (!result.empty()) {
                            for(const auto& pipe : result) {
                                cout << endl << pipe;
                            }
                        } else {
                            cout << "Pipe does not found" << endl;
                        }
                        break;
                    }
                    case static_cast<int>(PIPE_COMMAND::PRINT_ALL_PIPES):
                    {
                        dataPipe.PrintPipes(cout);
                        break;
                    }
                    case static_cast<int>(PIPE_COMMAND::CHANGE_SET_BY_ID):
                    {
                        int id1,id2;
                        cout << "Enter first and second id" << endl;
                        CorrectInput(id1);
                        CorrectInput(id2);
                        while(id2 < id1) {
                            cout << "Invalid input" << endl;
                            CorrectInput(id2);
                        }
                        try{
                        dataPipe.ChangeSetById(id1, id2);
                        } catch(exception& e) {
                            cout << e.what();
                        }
                        break;
                    }
                    case static_cast<int>(PIPE_COMMAND::CHANGE_SET_BY_STATUS):
                    {
                        bool status;
                        cout << "Enter status" << endl;
                        CorrectInput(status);
                        dataPipe.ChangeSetByStatus(status);
                        break;
                    }
                    case static_cast<int>(PIPE_COMMAND::CANCEL):
                    {
                        break;
                    }
                    default:
                    {
                        cout << "Invalid command" << endl;
                    }
                }
                break;
            }
            case static_cast<int>(COMMAND::CS):
            {
                PrintCSMenu();
                CorrectInput(commandNumber);
                switch (commandNumber) {
                    case static_cast<int>(CS_COMMAND::ADD_CS):
                    {
                        dataCS.AddCS();
                        break;
                    }
                    case static_cast<int>(CS_COMMAND::DEL_CS):
                    {
                        cout << "Enter id" << endl;
                        int id;
                        CorrectInput(id);
                        try{
                            auto it = dataCS.FindById(id);
                            dataCS.DelCS(it);
                        } catch(exception& e){
                            cout << e.what();
                        }
                        break;
                    }
                    case static_cast<int>(CS_COMMAND::CHANGE_CS):
                    {
                        cout << "Enter id" << endl;
                        int id;
                        CorrectInput(id);
                        try {
                            auto it = dataCS.FindById(id);
                            dataCS.ChangeCS(it);
                        } catch (exception& e) {
                            cout << e.what();
                        }
                        break;
                    }
                    case static_cast<int>(CS_COMMAND::FIND_BY_ID):
                    {
                        cout << "Enter id" << endl;
                        int id;
                        CorrectInput(id);
                        try{
                            auto it = dataCS.FindById(id);
                            cout << *it;
                        } catch(exception& e) {
                            cout << e.what();
                        }
                        break;
                    }
                    case static_cast<int>(CS_COMMAND::FIND_BY_NAME):
                    {
                        cout << "Enter name station" << endl;
                        string name;
                        cin.ignore(1);
                        getline(cin, name);
                        vector<CompressionStation> result = dataCS.FindByName(name);
                        if (!result.empty()) {
                            for(const auto& station : result) {
                                cout << endl <<station;
                            }
                        } else {
                            cout << "Pipe does not found" << endl;
                        }
                        break;
                    }
                    case static_cast<int>(CS_COMMAND::FIND_BY_PERCENT):
                    {
                        cout << "Enter percent" << endl;
                        int percent;
                        CorrectInput(percent);
                        vector<CompressionStation> result = dataCS.FindByPercent(percent);
                        if (!result.empty()) {
                            for(const auto& station : result) {
                                cout << endl <<station;
                            }
                        } else {
                            cout << "Pipe does not found" << endl;
                        }
                        break;
                    }
                    case static_cast<int>(CS_COMMAND::PRINT_ALL_CS):
                    {
                        dataCS.PrintCS(cout);
                        break;
                    }
                    case static_cast<int>(CS_COMMAND::CHANGE_SET_BY_ID):
                    {
                        int id1,id2;
                        cout << "Enter first and second id" << endl;
                        CorrectInput(id1);
                        CorrectInput(id2);
                        while(id2 < id1) {
                            cout << "Invalid input" << endl;
                            CorrectInput(id2);
                        }
                        try{
                        dataCS.ChangeSetById(id1, id2);
                        } catch(exception& e) {
                            cout << e.what();
                        }
                        break;
                    }
                    case static_cast<int>(CS_COMMAND::CANCEL):
                    {
                        break;
                    }
                    default:
                        cout << "Invalid command" << endl;
                }
                break;
            }
            case static_cast<int>(COMMAND::SHOW_ALL_OBJECT):
            {
                dataPipe.PrintPipes(cout);
                dataCS.PrintCS(cout);
                break;
            }
            case static_cast<int>(COMMAND::SAVE):
            {
                string name;
                cout << "Enter file name" << endl;
                cin >> name;
                ofstream output(name + ".txt");
                dataPipe.PrintPipes(output);
                dataCS.PrintCS(output);
                output.close();
                break;
            }
            case static_cast<int>(COMMAND::LOAD):
            {
                string name;
                cout << "Enter file name" << endl;
                cin >> name;
                ifstream input(name + ".txt");
                if(input) {
                    string line;
                    while(getline(input,line)) {
                        if (line == "Pipe") {
                            dataPipe.LoadPipe(input);
                        } else if (line == "Compressor station") {
                            dataCS.LoadCS(input);
                        }
                    }
                } else {
                    cout << "File doesn't exsist" << endl;
                }
                break;
            }
            case static_cast<int>(COMMAND::EXIT):
            {
                cout << "Program execution completed" << endl;
                return 0;
            }
            default:
                cout << "Invalid command" << endl;
        }
    }
}
