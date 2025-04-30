#pragma once

#include <map>
#include <vector>
#include <memory>
#include <cmath>
#include <assert.h>
#include "../npcs/NPC.h"


class BattleVisitor {
    std::map<std::string, int> killDistances = {
        {"Elf", 50},
        {"Bear", 10},
        {"Rogue", 10}
    };


public:
    explicit BattleVisitor() {}

    void engage(std::vector<std::shared_ptr<NPC>>& npcs, std::shared_ptr<NPC> npcs1, std::shared_ptr<NPC> npcs2) {
        
        if (canKillOpponent(*npcs1, *npcs2) && npcs1->isKillOpponent(*npcs2)) {
            if (canKillOpponent(*npcs2, *npcs1) &&npcs2->isKillOpponent(*npcs1)) {
                auto it = std::find_if(npcs.begin(), npcs.end(),[&](const auto& p){return p->getName()==npcs1->getName();});
                assert (it!=npcs.end()); 
                npcs.erase(it);
            }
            auto it = std::find_if(npcs.begin(), npcs.end(),[&](const auto& p){return p->getName()==npcs2->getName();});
            assert (it!=npcs.end()); 
            npcs.erase(it);
        } else if (canKillOpponent(*npcs2, *npcs1) && npcs2->isKillOpponent(*npcs1)) {
            auto it = std::find_if(npcs.begin(), npcs.end(),[&](const auto& p){return p->getName()==npcs1->getName();});
            assert (it!=npcs.end()); 
            npcs.erase(it);
            
        }
            npcs1->endFight();
            npcs2->endFight();
    }
    bool canFight(const NPC& a, const NPC& b) const {
        if (a.isFigthing() || b.isFigthing()){
            return false;
        }
        int dx = a.getX() - b.getX();
        int dy = a.getY() - b.getY();
        int distance = std::sqrt(dx * dx + dy * dy);
        int killDistance = getKillDistance(a.getType(), b.getType());
        return distance <= killDistance;
    }
    bool canKillOpponent(const NPC& a, const NPC& b) const {
        int dx = a.getX() - b.getX();
        int dy = a.getY() - b.getY();
        
        int distance = std::sqrt(dx * dx + dy * dy);

        int distanceB = killDistances.find(b.getType()) != killDistances.end() ? killDistances.at(b.getType()) : 0;

        return distance <= distanceB;
    }

private:

    int getKillDistance(const std::string& typeA, const std::string& typeB) const {
        int distanceA = killDistances.find(typeA) != killDistances.end() ? killDistances.at(typeA) : 0;
        int distanceB = killDistances.find(typeB) != killDistances.end() ? killDistances.at(typeB) : 0;
        return std::max(distanceA, distanceB);
    }
};