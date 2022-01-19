#include "Network.h"
#include "Console.h"

#define ACTION_FILTER(action,list) {  \
    for(const auto& id : list){       \
        action(id);                   \
    }                                 \
}

using namespace std;

enum class COMMAND {
    PIPES = 1, CS = 2, NETWORK = 3, SHOW_ALL_OBJECT = 4, SAVE = 5, LOAD = 6, EXIT = 0
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

enum class NETWORK_COMMAND {
    CONNECT = 1, DISCONNECT = 2, TOPOLOGY_SORT = 3, PRINT_ALL_CONECTIONS = 4,FIND_SHORTCUT = 5,
    FIND_MAX_STREAM = 6, CANCEL = 0
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
            ACTION_FILTER(db.Delete,id_list);
            break;
        }
        case static_cast<int>(ACTION_COMMAND::CHANGE_ALL): {
            ACTION_FILTER(db.Change, id_list);
            break;
        }
        case static_cast<int>(ACTION_COMMAND::DELETE_SELECTE): {
            set<int> numbers = inputNumbers(id_list.size());
            ACTION_FILTER(db.Delete,numbers);
            break;
        }
        case static_cast<int>(ACTION_COMMAND::CHANGE_SELECTE): {
            set<int> numbers = inputNumbers(id_list.size());;
            ACTION_FILTER(db.Change,numbers);
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
    Network network;
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
                        network.dataPipe.Add();
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
                                vector<int> id_list = network.dataPipe.FindByStatusRepair(status);
                                if (!id_list.empty()){
                                ActionWithFilter(network.dataPipe, id_list);
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
                                vector<int> id_list = network.dataPipe.FindByName(name);
                                if (!id_list.empty()){
                                ActionWithFilter(network.dataPipe, id_list);
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
                        network.dataPipe.Print(cout);
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
                        network.dataCS.Add();
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
                                vector<int> id_list = network.dataCS.FindByPercent(percent);
                                if (!id_list.empty()){
                                ActionWithFilter(network.dataCS, id_list);
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
                                vector<int> id_list = network.dataCS.FindByName(name);
                                if (!id_list.empty()){
                                ActionWithFilter(network.dataCS, id_list);
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
                        network.dataCS.Print(cout);
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
            case static_cast<int>(COMMAND::NETWORK):
            {
                NetworkMenu();
                CorrectInput(commandNumber);
                switch (commandNumber) {
                case static_cast<int>(NETWORK_COMMAND::CONNECT):
                {
                    cout << "FREE PIPES" << endl;
                    network.dataPipe.PrintFreePipe();
                    int pipe_id, inCS_id, outCS_id;
                    cout << "FREE CS" << endl;
                    network.dataCS.Print(cout);
                    cout << "Enter pipe id" << endl;
                    CorrectInput(pipe_id);
                    cout << "Enter output CS id" << endl;
                    CorrectInput(outCS_id);
                    cout << "Enter input CS id" << endl;
                    CorrectInput(inCS_id);
                    while (outCS_id == inCS_id) {
                        cout << "Invalid input" << endl;
                        CorrectInput(outCS_id);
                    }
                    network.Connect(pipe_id, outCS_id, inCS_id);
                    break;
                }
                case static_cast<int>(NETWORK_COMMAND::DISCONNECT):
                {
                    int pipe_id;
                    cout << "Enter pipe id" << endl;
                    CorrectInput(pipe_id);
                    network.Disconnect(pipe_id);
                    break;
                }
                case static_cast<int>(NETWORK_COMMAND::TOPOLOGY_SORT):
                {
                    if (!network.CheckCycleInGraph()){
                    network.topologicalSort();
                    } else {
                        cout << "Error, there is a cycle in the graph" << endl;
                    }
                    break;
                }
                case static_cast<int>(NETWORK_COMMAND::PRINT_ALL_CONECTIONS):
                {
                    network.PrintAllConnection(cout);
                    break;
                }
                case static_cast<int>(NETWORK_COMMAND::FIND_SHORTCUT):
                {
                    network.dataCS.Print(cout);
                    int firstCS,lastCS;
                    cout << "Enter start station" << endl;
                    CorrectInput(firstCS);
                    cout << "Enter last station" << endl;
                    CorrectInput(lastCS);
                    while (lastCS == firstCS) {
                        cout << "Invalid input" << endl;
                        CorrectInput(lastCS);
                    }
                    if (!network.dataCS.Contains(lastCS) || !network.dataCS.Contains(firstCS)){
                        cout << "First station or last station don't exists" << endl;
                        break;
                    }
                    network.FindShortcut(firstCS,lastCS);
                    break;
                }
                case static_cast<int>(NETWORK_COMMAND::FIND_MAX_STREAM):
                {
                    network.dataCS.Print(cout);
                    int firstCS,lastCS;
                    cout << "Enter start station" << endl;
                    CorrectInput(firstCS);
                    cout << "Enter last station" << endl;
                    CorrectInput(lastCS);
                    while (lastCS == firstCS) {
                        cout << "Invalid input" << endl;
                        CorrectInput(lastCS);
                    }
                    if (!network.dataCS.Contains(lastCS) || !network.dataCS.Contains(firstCS)){
                        cout << "First station or last station don't exists" << endl;
                        break;
                    }
                    cout << network.FindMaxStream(firstCS,lastCS);
                    break;
                }
                case static_cast<int>(NETWORK_COMMAND::CANCEL):
                {
                    break;
                }
                default:
                    cout << "Invalid input" << endl;
                }
                break;
            }
            case static_cast<int>(COMMAND::SHOW_ALL_OBJECT):
            {
                cout << endl;
                network.dataPipe.Print(cout);
                network.dataCS.Print(cout);
                break;
            }
            case static_cast<int>(COMMAND::SAVE):
            {
                string name;
                cout << "Enter file name" << endl;
                cin >> name;
                ofstream output(name + ".txt");
                network.dataPipe.Print(output);
                network.dataCS.Print(output);
                network.PrintAllConnection(output);
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
                            network.dataPipe.Load(input);
                        } else if (line == "Compressor station") {
                            network.dataCS.Load(input);
                        } else if (line == "Connection") {
                            network.LoadConnection(input);
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
