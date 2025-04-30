#pragma once
#include <memory>
#include <iostream>
#include <string>
#include "../npcs/NPC.h"
#include "../npcs/Elf.h"
#include "../npcs/Bear.h"
#include "../npcs/Rogue.h"

class NPCFactory {
public:
     static std::unique_ptr<NPC> createNPC(const std::string& type, const std::string& name, int x, int y) {
        std::unique_ptr<NPC> npc;
        if (type == "Rogue") npc = std::make_unique<Rogue>(name, x, y);
        else if (type == "Bear") npc = std::make_unique<Bear>(name, x, y);
        else if (type == "Elf") npc = std::make_unique<Elf>(name, x, y);
        else throw std::invalid_argument("Unknown NPC type: " + type);

        return npc;
    }
};