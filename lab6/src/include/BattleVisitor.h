#pragma once

#include <vector>
#include <memory>
#include <cmath>
#include "../npcs/NPC.h"

class BattleVisitor {
    long long range;

public:
    explicit BattleVisitor(int range) : range(range) {}

    void engage(std::vector<std::unique_ptr<NPC>>& npcs) {
        for (size_t i = 0; i < npcs.size(); ++i) {
            for (size_t j = i + 1; j < npcs.size(); ++j) {
                if (npcs[i] && npcs[j] && canFight(*npcs[i], *npcs[j])) {
                    if (npcs[i]->acceptFight(*npcs[j])){
                        if (npcs[j]->acceptFight(*npcs[i])){
                            npcs[i] = nullptr;   
                        }
                        npcs[j] = nullptr;
                    }
                    else if (npcs[j]->acceptFight(*npcs[i])){
                         npcs[i] = nullptr;
                    }
                }
            }
        }

        npcs.erase(std::remove(npcs.begin(), npcs.end(), nullptr), npcs.end());
    }

private:
    bool canFight(const NPC& a, const NPC& b) const {
        int dx = a.getX() - b.getX();
        int dy = a.getY() - b.getY();
        return dx * dx + dy * dy <= range * range;
    }
};