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
        bool isKillOpponent(NPC& other) {
            if (canFight(other)) {
                std::string info = "Разбойник " + name + " атакует " + other.getType() + " " + other.getName() + "!\n";
                fileLogger.notify(info);

                if (other.getType() == "Rogue") {
                    int rollRogue1 = rollDice(*this);
                    int rollRogue2 = rollDice(other);
    
                    info = "Разбойник " + name + " выбрасывает " + std::to_string(rollRogue1) + "!\n";
                    fileLogger.notify(info);
    
                    info = "Разбойник " + other.getName() + " выбрасывает " + std::to_string(rollRogue2) + "!\n";
                    fileLogger.notify(info);
    
                    if (rollRogue1 > rollRogue2) {
                        std::string deathInfo = "Разбойник " + name + " убивает Разбойника " + other.getName() + "!\n";
                        fileLogger.notify(deathInfo);
                        return true;
                    } else {
                        std::string info = "Разбойник " + other.getName() + " убегает от Разбойника " + name + "!\n";
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