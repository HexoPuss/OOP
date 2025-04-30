#pragma once 

#include <vector>
#include <memory>
#include <fstream>
#include "../npcs/NPC.h"
#include "NPCFactory.h"

class FileManager {
public:
    static void saveToFile(const std::string& filename, const std::vector<std::unique_ptr<NPC>>& npcs) {
        std::ofstream out;
        out.open(filename);
        if (!out) throw std::runtime_error("Failed to open file for writing.");

        for (const auto& npc : npcs) {
            out << npc->getType() << " " << npc->getName() << " "
                 << npc->getX() << " " << npc->getY() << "\n";
        }
        out.close();
    }

    static void loadFromFile(const std::string& filename, std::vector<std::unique_ptr<NPC>>& npcs) {
        std::ifstream input;
        input.open(filename);
        if (!input) throw std::runtime_error("Failed to open file for reading.");

        std::string type, name;
        int x, y;
        while (input >> type >> name >> x >> y) {
            npcs.push_back(NPCFactory::createNPC(type, name, x, y));
        }
        input.close();
    }

    
};
