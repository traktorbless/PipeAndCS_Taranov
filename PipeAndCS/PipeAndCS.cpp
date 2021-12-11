#include "Pipe.h"
#include "CompressorStation.h"
#include "Function.h"
#include "Network.h"
#include <set>


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


enum class COMMAND {
    PIPES = 1, CS = 2, SHOW_ALL_OBJECT = 3, SAVE = 4, LOAD = 5, EXIT = 0
};

enum class PIPE_COMMAND {
    ADD_PIPE = 1, FIND_BY_FILTER = 2, PRINT_ALL_PIPES = 3 ,CANCEL = 0
};

enum class ACTION_COMMAND {
    DELETE_ALL = 1, DELETE_SELECTE = 2, CHANGE_ALL = 3,CHANGE_SELECTE = 4 , CANCEL = 0
};

enum class PIPE_FILTER {
    FIND_BY_STATUS = 1, FIND_BY_NAME = 2, CANCEL = 0
};

enum class CS_COMMAND {
    ADD_CS = 1,FIND_BY_FILTER = 2,PRINT_ALL_CS = 3, CANCEL = 0
};

enum class CS_FILTER {
    FIND_BY_PERCENT = 1, FIND_BY_NAME = 2, CANCEL = 0
};

set<int> inputNumbers(size_t size) {
    cout << "Enter numbers" << endl;
    set<int> numbers;
    int id;
    string line;
    cin.ignore(1);
    getline(cin, line);
    stringstream ss(line);
    while (ss >> id) {
        if (id <= size) {
            numbers.insert(id);
        }
    }
    return numbers;
}

void ActionWithFilter(Database& db, const vector<int>& id_list) {
    int i = 0;
    for (const auto& id : id_list) {
        cout << ++i << "." << endl;
        db.FindById(id);
    }
    ActionMenu();
    int commandNumber;
    CorrectInput(commandNumber);
    switch (commandNumber) {
        case static_cast<int>(ACTION_COMMAND::DELETE_ALL): {
            for (const auto& id : id_list) {
                db.Delete(id);
            }
            break;
        }
        case static_cast<int>(ACTION_COMMAND::CHANGE_ALL): {
            for (const auto& id : id_list) {
                db.Change(id);
            }
            break;
        }
        case static_cast<int>(ACTION_COMMAND::DELETE_SELECTE): {
            set<int> numbers = inputNumbers(id_list.size());
            for (const auto& i : numbers) {
                db.Delete(id_list[i - 1]);
            }
            break;
        }
        case static_cast<int>(ACTION_COMMAND::CHANGE_SELECTE): {
            set<int> numbers = inputNumbers(id_list.size());;
            for (const auto& i : numbers) {
                db.Change(id_list[i - 1]);
            }
            break;
        }
        case static_cast<int>(ACTION_COMMAND::CANCEL): {
            break;
        }
        default:
            cout << "Invalid command" << endl;
            break;
    }
}

int main()
{
    DataPipe dataPipe;
    DataCS dataCS;
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
                        dataPipe.Add();
                        break;
                    }
                    case static_cast<int>(PIPE_COMMAND::FIND_BY_FILTER):
                    {
                        PrintFiltersForPipe();
                        CorrectInput(commandNumber);
                        switch(commandNumber) {
                            case static_cast<int>(PIPE_FILTER::FIND_BY_STATUS): {
                                bool status;
                                cout << "Enter status" << endl;
                                CorrectInput(status);
                                vector<int> id_list = dataPipe.FindByStatusRepair(status);
                                if (!id_list.empty()){
                                ActionWithFilter(dataPipe, id_list);
                                } else {
                                    cout << "Pipes does not find" << endl;
                                }
                                break;
                            }
                            case static_cast<int>(PIPE_FILTER::FIND_BY_NAME): {
                                string name;
                                cout << "Enter name" << endl;
                                cin.ignore(1);
                                getline(cin, name);
                                vector<int> id_list = dataPipe.FindByName(name);
                                if (!id_list.empty()){
                                ActionWithFilter(dataPipe, id_list);
                                } else {
                                    cout << "Pipes does not find" << endl;
                                }
                                break;
                            }
                            case static_cast<int>(PIPE_FILTER::CANCEL): {
                                break;
                            }
                            default:
                                cout << "Invalid command" << endl;
                                break;
                        }
                        break;
                    }
                    case static_cast<int>(PIPE_COMMAND::PRINT_ALL_PIPES):
                    {
                        dataPipe.Print(cout);
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
                        dataCS.Add();
                        break;
                    }
                    case static_cast<int>(CS_COMMAND::FIND_BY_FILTER):
                    {
                        PrintFiltersForCS();
                        CorrectInput(commandNumber);
                        switch(commandNumber) {
                            case static_cast<int>(CS_FILTER::FIND_BY_PERCENT): {
                                int percent;
                                cout << "Enter percent" << endl;
                                CorrectInput(percent);
                                vector<int> id_list = dataCS.FindByPercent(percent);
                                if (!id_list.empty()){
                                ActionWithFilter(dataCS, id_list);
                                } else {
                                    cout << "CS does not find" << endl;
                                }
                                break;
                            }
                            case static_cast<int>(CS_FILTER::FIND_BY_NAME): {
                                string name;
                                cout << "Enter name" << endl;
                                cin.ignore(1);
                                getline(cin, name);
                                vector<int> id_list = dataCS.FindByName(name);
                                if (!id_list.empty()){
                                ActionWithFilter(dataCS, id_list);
                                } else {
                                    cout << "CS does not find" << endl;
                                }
                                break;
                            }
                            case static_cast<int>(CS_FILTER::CANCEL): {
                                break;
                            }
                            default:
                                cout << "Invalid command" << endl;
                                break;
                        }
                        break;
                    }
                    case static_cast<int>(CS_COMMAND::PRINT_ALL_CS):
                    {
                        dataCS.Print(cout);
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
                cout << endl;
                dataPipe.Print(cout);
                dataCS.Print(cout);
                break;
            }
            case static_cast<int>(COMMAND::SAVE):
            {
                string name;
                cout << "Enter file name" << endl;
                cin >> name;
                ofstream output(name + ".txt");
                dataPipe.Print(output);
                dataCS.Print(output);
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
                            dataPipe.Load(input);
                        } else if (line == "Compressor station") {
                            dataCS.Load(input);
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
