#pragma once
#include <string>
#include <random>
#include <algorithm>
#define MAX_SIZE_MAP 80

class NPC {
protected:
    std::string name;
    int x, y;
    bool is_figthing = false;

public:
    NPC(const std::string& name, int x, int y) : name(name), x(x), y(y) {}
    virtual ~NPC() = default;

    virtual std::string getType() const = 0;
    
    virtual bool canFight(const NPC& other) const = 0;
    virtual bool isKillOpponent(NPC& other) = 0;

    std::string getName() const {
        return name;
    }
    int getX() const {
        return x;
    }
    int getY() const {
        return y;
    }

    bool isFigthing() const {
        return is_figthing;
    }
    void setX(int newX) {
        x=newX;
    }
    void setY(int newY) {
        y=newY;
    }
    void startFight() {
        is_figthing = true;
    }
    void endFight() {
        is_figthing = false;
    }
    int rollDice(NPC& npc) const {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 6);

        int diceValue = dis(gen);
        return diceValue;
    }
    void moveNPC(NPC& npc) {
    std::random_device rd;
    std::mt19937 gen(rd());

    int moveDistance = 0;
    if (npc.getType() == "Orc") {
        moveDistance = 20;
    } else if (npc.getType() == "Squirrel" || npc.getType() == "Bear") {
        moveDistance = 5;
    }

    std::uniform_int_distribution<> dis(-moveDistance, moveDistance);
    int dx = dis(gen);
    int dy = dis(gen);

    int newX = std::clamp(npc.getX() + dx, 0, MAX_SIZE_MAP - 1);
    int newY = std::clamp(npc.getY() + dy, 0, MAX_SIZE_MAP - 1);

    npc.setX(newX);
    npc.setY(newY);
}

};