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
        bool isKillOpponent(NPC& other) {
            if (canFight(other)) {
                std::string info = "Ельф " + name + " атакует " + other.getType() + " " + other.getName() + "!\n";
                fileLogger.notify(info);
    
                if (other.getType() == "Elf") {
                    int rollElf = rollDice(*this);
                    int rollRogue = rollDice(other);
    
                    info = "Ельф " + name + " выбрасывает " + std::to_string(rollElf) + "!\n";
                    fileLogger.notify(info);
    
                    info = "Разбойник " + other.getName() + " выбрасывает " + std::to_string(rollRogue) + "!\n";
                    fileLogger.notify(info);
    
                    if (rollElf > rollRogue) {
                        std::string deathInfo = "Ельф " + name + " убивает Разбойника " + other.getName() + "!\n";
                        fileLogger.notify(deathInfo);
                        return true;
                    } else {
                        std::string info = "Разбойник " + other.getName() + " убегает от эльфа " + name + "!\n";
                        moveNPC(other);
                        fileLogger.notify(info);
                        return false;
                    }
                }
                
            }
            std::string info = "Разбойник " + name + " не может атаковать " + other.getName() + "!\n";
            fileLogger.notify(info);
            return false;
        }
    
    
    };