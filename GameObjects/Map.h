#ifndef MAP_H
#define MAP_H

#include "Variables.h"
#include "Ground.h"
#include "Coin.h"
#include "Player.h"
#include "Spikes.h"
#include "ExitDoor.h"
#include "Door.h"
#include "Buttom.h"
#include "Stone.h"
#include "Box.h"
#include "Enemies.h"
#include "Mushroom.h"
#include "LeverTurn.h"

#include <string>
#include <vector>

class Map {
public:
    std::vector<std::vector<int>> data; // Dữ liệu map

    bool LoadFromFile(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            printf("Unable to open file %s\n", filePath.c_str());
            return false;
        }

        // Đọc dữ liệu từ file
        std::string line;
        while (std::getline(file, line)) {
            std::vector<int> row;
            std::string token;
            size_t pos = 0;

            while ((pos = line.find(',')) != std::string::npos) {
                token = line.substr(0, pos);
                row.push_back(std::stoi(token));
                line.erase(0, pos + 1);
            }

            row.push_back(std::stoi(line));
            data.push_back(row);
        }

        file.close();

        return true;
    }
};

#endif // MAP_H
