#include "src/include/NPCFactory.h"
#include "src/include/BattleVisitor.h"
#include "src/include/FileManager.h"
#include "src/include/Logger.h"
#include "src/rungame/rungame.h"


int main() {
    std::vector<std::shared_ptr<NPC>> npcs;
    createNPCs(npcs);
    moveAndFightNPCs(npcs);
    return 0;
}