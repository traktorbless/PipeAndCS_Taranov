#pragma once
#include "Pipe.h"
#include "CompressorStation.h"
#include "Function.h"
#include <vector>
#include <unordered_map>

enum class PIPE_COMMAND {
    ADD_PIPE = 1, FIND_BY_FILTER = 2, PRINT_ALL_PIPES = 3, CANCEL = 0
};

enum class FILTER_TYPE {
    FIND_PIPE_BY_STATUS, FIND_PIPE_BY_NAME, FIND_CS_BY_PERCENT, FIND_CS_BY_NAME
};

enum class CS_COMMAND {
    ADD_CS = 1, FIND_BY_FILTER = 2, PRINT_ALL_CS = 3, CANCEL = 0
};

enum class COMMAND {
    PIPES = 1, CS = 2, SHOW_ALL_OBJECT = 3, SAVE = 4, LOAD = 5, EXIT = 0
};

class Network
{
    void AddPipe();

    void DelPipe(int id);

    void ChangePipe(int id);

    void PrintPipes(std::ostream& os) const; // Сделать один метод

    void LoadPipe(std::istream& is);

    template<typename Object>
    Object FindById(int id, COMMAND command) const {
        if (command == COMMAND::PIPES) {
            return dataPipe.at(id);
        }
        if (command == COMMAND::CS) {
            return dataCS.at(id);
        }
    }

    void AddCS();

    void DelCS(int id);

    void ChangeCS(int id);

    void PrintCS(std::ostream& os) const;

    void LoadCS(std::istream& is);

    template <typename Filter>
    std::vector<int> FindByFilter(Filter filter, FILTER_TYPE command) {
        std::vector<int> result;
        if (command == FILTER_TYPE::FIND_PIPE_BY_NAME) {
            for (auto [id, object] : dataPipe) {
                Filter(result, object.GetName, filter, id);
            }
            return result;
        }

        if (command == FILTER_TYPE::FIND_PIPE_BY_STATUS) {
            for (auto [id, object] : dataPipe) {
                Filter(result, object.GetStatusRepair, filter, id);
            }
            return result;
        }

        if (command == FILTER_TYPE::FIND_CS_BY_NAME) {
            for (auto [id, object] : dataCS) {
                Filter(result, object.GetName, filter, id);
            }
            return result;
        }

        if (command == FILTER_TYPE::FIND_CS_BY_PERCENT) {
            for (auto [id, object] : dataCS) {
                Filter(result, object.GetPercentOfUnactiveWorkshop, filter, id);
            }
            return result;
        }
    }

private:
    static int max_id_pipe, max_id_cs;
    std::unordered_map<int, Pipe> dataPipe;
    std::unordered_map<int, CompressionStation> dataCS;

    template <typename T>
    void Filter(const std::vector<int>& v, T foo(), T filter, int id) {
        if (filter == foo()) {
            v.push_back(id);
        }
    }
};



