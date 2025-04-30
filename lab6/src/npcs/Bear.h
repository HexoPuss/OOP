#include "NPC.h"
#include "../include/Logger.h"

class Bear : public NPC {
private:
    ConsoleLogger consoleLogger;
    FileLogger fileLogger;
public:
    Bear(const std::string& name, int x, int y) : NPC(name, x, y), fileLogger("log.txt") {}
    ~Bear() override = default;

    std::string getType() const {
        return "Bear";
    }

    bool canFight(const NPC& other) const {
        return other.getType() == "Elf";
    }
    bool acceptFight(NPC& other) {
        if (canFight(other)) {
            std::string info = "Медведь " + name + " атакует " + other.getType() + " " + other.getName() + "!\n";
            consoleLogger.notify(info);
            fileLogger.notify(info);

            if (other.getType() == "Elf") {
                std::string deathInfo = "Медведь " + name + " убивает эльфа " + other.getName() + "!\n";
                consoleLogger.notify(deathInfo);
                fileLogger.notify(deathInfo);
                return true;
            }
        }
        return false;
    }
};
