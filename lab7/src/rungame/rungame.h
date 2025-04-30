#include "../include/NPCFactory.h"
#include "../include/BattleVisitor.h"
#include "../include/FileManager.h"
#include "../include/Logger.h"
#include <random>
#include <string>
#include <thread>
#include <mutex>
#include <cstring>

#define MAX_SIZE_MAP 80
bool isPositionOccupied(const std::vector<std::shared_ptr<NPC>>& npcs, int x, int y) {
    for (const auto& npc : npcs) {
        if (npc->getX() == x && npc->getY() == y) {
            return true;
        }
    }
    return false;
}
void printMap(const std::vector<std::shared_ptr<NPC>>& npcs) {
    char map[MAX_SIZE_MAP][MAX_SIZE_MAP];
    memset(map, '.', sizeof(map)); 

    for (const auto& npc : npcs) {
        if (npc){
        map[npc->getX()][npc->getY()] = npc->getType()[0];
        }
    }

    for (int i = 0; i < MAX_SIZE_MAP; ++i) {
        for (int j = 0; j < MAX_SIZE_MAP; ++j) {
            std::cout << map[i][j];
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
     for (int i=0; i < MAX_SIZE_MAP+2; ++i) {
         std::cout << "\033[A";
     }
}

void moveNPCs(std::vector<std::shared_ptr<NPC>>& npcs) {
    std::random_device rd;
    std::mt19937 gen(rd());

    for (auto& npc : npcs) {
        if (npc->isFigthing()){
            continue;
        }

        int moveDistance = 0;
        if (npc->getType() == "Elf" || npc->getType() == "Rogue") {
            moveDistance = 10;
        } else if (npc->getType() == "Bear") {
            moveDistance = 5;
        }

        std::uniform_int_distribution<> dis(-moveDistance, moveDistance);
        int dx = dis(gen);
        int dy = dis(gen);

        int newX = std::clamp(npc->getX() + dx, 0, MAX_SIZE_MAP - 1);
        int newY = std::clamp(npc->getY() + dy, 0, MAX_SIZE_MAP - 1);

        if (!isPositionOccupied(npcs, newX, newY)) {
            npc->setX(newX);
            npc->setY(newY);
        }
    }
}







void createNPCs(std::vector<std::shared_ptr<NPC>>& npcs) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, MAX_SIZE_MAP - 1);
    

    ConsoleLogger consoleLogger;
    FileLogger fileLogger("log.txt");



    for (int i = 0; i < 50; ++i) {
        std::string type;
        std::string name;
        int x, y;

        int randomType = dis(gen);
        if (randomType%3 == 0) {
            type = "Elf";
        } else if (randomType%3 == 1) {
            type = "Bear";
        } else {
            type = "Rogue";
        }
        name = "NPC" + std::to_string(i + 1);
        x = dis(gen);
        y = dis(gen);

        while (isPositionOccupied(npcs, x, y)) {
            x = dis(gen);
            y = dis(gen);
        }
        npcs.push_back(NPCFactory::createNPC(type, name, x, y));
        std::string info = "Создан npcs: " + type + " " + name + "\n"; 
        fileLogger.notify(info);
    }
}






#include <condition_variable>
void moveAndFightNPCs(std::vector<std::shared_ptr<NPC>>& npcs) {
    std::mutex mtx;
    std::condition_variable cv;
    int count_threads = 0;
    std::mutex mtx_c_t;

    std::thread moveThread([&]() {
        auto start_time = std::chrono::system_clock::now();
        auto now = start_time;
        BattleVisitor battle;    


        while (now - start_time < std::chrono::seconds(30)){
            {
                std::lock_guard <std::mutex> lock(mtx);
                moveNPCs(npcs);

                for (size_t i = 0; i < npcs.size(); ++i) {
                    for (size_t j = i + 1; j < npcs.size(); ++j) {
                        auto npcs1 = npcs[i];
                        auto npcs2 = npcs[j];
                        
                        if (battle.canFight(*npcs1, *npcs2)) {\
                            npcs[i]->startFight();
                            npcs[j]->startFight();
                            {
                                std::lock_guard<std::mutex> lock_c_t(mtx_c_t);
                                count_threads++;
                            }
                            std::thread fightThread([&,npcs1,npcs2]() {
                                {
                                    std::lock_guard<std::mutex> lock(mtx);

                                    battle.engage(npcs, npcs1, npcs2);
                                   
                                }


                                {
                                    std::lock_guard<std::mutex> lock_c_t(mtx_c_t);
                                    count_threads--;
                                }
                                cv.notify_one();

                            });
                            fightThread.detach();

                        }
                    }
                }
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(999));
            now = std::chrono::system_clock::now();
        }

        std::unique_lock<std::mutex> lock(mtx_c_t);
        cv.wait(lock, [&] { return count_threads == 0; });
        lock.unlock();
    });
    auto start_time = std::chrono::system_clock::now();
    auto now = start_time;
    while (now - start_time < std::chrono::seconds(30)){
        {
            std::lock_guard<std::mutex> lock(mtx);
            printMap(npcs);
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
        now = std::chrono::system_clock::now();
    }
    moveThread.join();
}