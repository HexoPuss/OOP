#include "NPC.h"
#include "../include/Logger.h"

class Elf : public NPC {
private:
    ConsoleLogger consoleLogger;
    FileLogger fileLogger;
public:
    Elf(const std::string& name, int x, int y) : NPC(name, x, y), fileLogger("log.txt") {}
    ~Elf() override = default;

    std::string getType() const {
        return "Elf";
    }

    bool canFight(const NPC& other) const {
        return other.getType() == "Rogue";
    }
    bool acceptFight(NPC& other) {
        if (canFight(other)) {
            std::string info = "Ельф " + name + " атакует " + other.getType() + " " + other.getName() + "!\n";
            consoleLogger.notify(info);
            fileLogger.notify(info);

            if (other.getType() == "Elf") {
                std::string deathInfo = "Ельф " + name + " убивает разбойника " + other.getName() + "!\n";
                consoleLogger.notify(deathInfo);
                fileLogger.notify(deathInfo);
                return true;
            }
        }
        return false;
    }
};
