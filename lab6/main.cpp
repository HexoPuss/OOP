#include "src/include/NPCFactory.h"
#include "src/include/BattleVisitor.h"
#include "src/include/FileManager.h"
#include "src/include/Logger.h"


bool isPositionOccupied(const std::vector<std::unique_ptr<NPC>>& npcs, int x, int y) {
    for (const auto& npc : npcs) {
        if (npc->getX() == x && npc->getY() == y) {
            return true;
        }
    }
    return false;
}


int main() {
    std::vector<std::unique_ptr<NPC>> npcs;
    ConsoleLogger consoleLogger;
    FileLogger fileLogger("log.txt");

    std::string type, name;
    int x, y, choice = 1;
    while (choice != 0) {
        std::cout << "Для выхода нажмите 0, для добавления NPC нажмите 1, для боя нажмите 2, для вывода всех живих NPC нажмите 3 для сохранения игры нажмите 4, для загрузки игры нажмите 5: ";
        std::cin >> choice;
        if (choice == 1) {
            int count;
            std::cout << "Введите количество NPC: ";
            if (!(std::cin >> count) || count <= 0) {
                std::cout << "Неверное количество NPC. Запустите программу еще раз." << std::endl;
                break;
            }
            for (int i = 0; i < count; i++) {
                type = "";
                while (type != "Elf" && type != "Bear" && type != "Rogue") {
                    std::cout << "Введите тип NPC (Elf, Bear, Rogue): ";
                    std::cin >> type;
                    if (type != "Elf" && type != "Bear" && type != "Rogue") {
                        std::cout << "Неверный тип NPC. Попробуйте еще раз." << std::endl;
                    }
                }
                std::cout << "Введите имя NPC: ";
                std::cin >> name;

                bool validPosition = false;
                while (!validPosition) {
                    std::cout << "Введите координату x: ";
                    if (!(std::cin >> x)) {
                        std::cout << "Неверная координата x. Запустите программу еще раз." << std::endl;
                        break;
                    }
                    std::cout << "Введите координату y: ";
                    if (!(std::cin >> y)) {
                        std::cout << "Неверная координата y. Запустите программу еще раз." << std::endl;
                        break;
                    }
                    if (isPositionOccupied(npcs, x, y)) {
                        std::cout << "Эта позиция уже занята. Пожалуйста, выберите другую." << std::endl;
                    } else {
                        validPosition = true;
                    }
                }

                if (validPosition) {
                    npcs.push_back(NPCFactory::createNPC(type, name, x, y));
                }
            }
            FileManager::saveToFile("npcs.txt", npcs);
            npcs.clear();
            FileManager::loadFromFile("npcs.txt", npcs);
        }
        else if (choice == 2) {
            long long distance;
            std::cout << "Введите расстояние для боя: ";
            if (!(std::cin >> distance) || distance <= 0) {
                std::cout << "Неверное расстояние. Запустите программу еще раз." << std::endl;
                break;
            }
            BattleVisitor battle(distance);
            battle.engage(npcs);
            consoleLogger.notify("Battle completed.");
            fileLogger.notify("Battle completed.");
        }
        else if (choice == 3) {
            for (const auto& npc : npcs) {
                std::string info = npc->getType() + " " + npc->getName() + " (" + std::to_string(npc->getX()) + ", " + std::to_string(npc->getY()) + ")";
                consoleLogger.notify(info);
            }   
        }
        else if (choice == 4) {
            FileManager::saveToFile("npcs.txt", npcs);
            consoleLogger.notify("Игра сохранена.");
            fileLogger.notify("Игра сохранена.");
        }
        else if (choice == 5) {
            npcs.clear();
            FileManager::loadFromFile("npcs.txt", npcs);
            consoleLogger.notify("Игра загружена.");
            fileLogger.notify("Игра загружена.");
        }
        else if (choice == 0) {
            break;
        }
    }
    return 0;
}