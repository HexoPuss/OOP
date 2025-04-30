#pragma once
#include <string>

class NPC {
protected:
    std::string name;
    int x, y;

public:
    NPC(const std::string& name, int x, int y) : name(name), x(x), y(y) {}
    virtual ~NPC() = default;

    virtual std::string getType() const = 0;
    virtual bool canFight(const NPC& other) const = 0;
    virtual bool acceptFight(NPC& other) = 0;

    std::string getName() const {
        return name;
    }
    int getX() const {
        return x;
    }
    int getY() const {
        return y;
    }
};
