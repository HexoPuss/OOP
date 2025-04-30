#include "src/rungame/rungame.h"
#include "src/include/NPCFactory.h"
#include <gtest/gtest.h>



TEST(CreateyNPCs, Create50NPCs) {
    std::vector<std::shared_ptr<NPC>> npcs;
    createNPCs(npcs);

    EXPECT_EQ(npcs.size(), 50);
}
TEST(IsPositionOccupiedTest, NoNPCsPresent) {
    std::vector<std::shared_ptr<NPC>> npcs;

    int x = 5;
    int y = 5;

    EXPECT_FALSE(isPositionOccupied(npcs, x, y));
}

TEST(MoveAndFightNPCsTest, BearSurvives) {
    std::vector<std::shared_ptr<NPC>> npcs;

    // Add one Elf
    npcs.push_back(NPCFactory::createNPC("Bear", "Bear1", 0, 0));

    // Add 12 Bears
    for (int i = 0; i < 12; ++i) {
        npcs.push_back(NPCFactory::createNPC("Elf", "Elf" + std::to_string(i + 1), i, i));
    }

    moveAndFightNPCs(npcs);
    EXPECT_NE(npcs[0]->getType(), "Bear");
}


TEST(MoveAndFightNPCsTest, MultipleNPCs) {
    std::vector<std::shared_ptr<NPC>> npcs;

    // Add two Elfs
    npcs.push_back(NPCFactory::createNPC("Elf", "Elf1", 0, 0));
    npcs.push_back(NPCFactory::createNPC("Elf", "Elf2", 5, 5));

    // Add one Elf and one Bear
    npcs.push_back(NPCFactory::createNPC("Elf", "Elf3", 20, 20));
    npcs.push_back(NPCFactory::createNPC("Bear", "Bear1", 23, 23));

    moveAndFightNPCs(npcs);
    
    EXPECT_EQ(npcs[0]->getType(), "Elf");
}






int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}