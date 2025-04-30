#include "NPC.h"
#include "../include/Logger.h"

class Rogue : public NPC {
private:
    ConsoleLogger consoleLogger;
    FileLogger fileLogger;
public:
    Rogue(const std::string& name, int x, int y) : NPC(name, x, y), fileLogger("log.txt") {}
    ~Rogue() override = default;

    std::string getType() const {
        return "Rogue";
    }

    bool canFight(const NPC& other) const {
        return other.getType() == "Rogue";
    }
    bool acceptFight(NPC& other) {
        if (canFight(other)) {
            std::string info = "Разбойник " + name + " атакует " + other.getType() + " " + other.getName() + "!\n";
            consoleLogger.notify(info);
            fileLogger.notify(info);

            if (other.getType() == "Elf") {
                std::string deathInfo = "Разбойник " + name + " убивает разбойника " + other.getName() + "!\n";
                consoleLogger.notify(deathInfo);
                fileLogger.notify(deathInfo);
                return true;
            }
        }
        return false;
    }
};
