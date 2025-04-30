#include <gtest/gtest.h>
#include "src/include/NPCFactory.h"
#include "src/include/BattleVisitor.h"
#include "src/include/FileManager.h"

TEST(NPCFactoryTest, CreateNPC) {
    auto orc = NPCFactory::createNPC("Elf", "TestELF", 0, 0);
    EXPECT_EQ(orc->getType(), "Elf");
    EXPECT_EQ(orc->getName(), "TestELF");
    EXPECT_EQ(orc->getX(), 0);
    EXPECT_EQ(orc->getY(), 0);
}

TEST(BattleVisitorTest, Engage) {
    std::vector<std::unique_ptr<NPC>> npcs;
    npcs.push_back(NPCFactory::createNPC("Elf", "Elf1", 0, 0));
    npcs.push_back(NPCFactory::createNPC("Bear", "Bear1", 1, 1));

    BattleVisitor battle(2);
    battle.engage(npcs);
    EXPECT_EQ(npcs.size(), 1);
}

TEST(FileManagerTest, SaveAndLoad) {
    std::vector<std::unique_ptr<NPC>> npcs;
    npcs.push_back(NPCFactory::createNPC("Rogue", "Rogue1", 5, 5));

    FileManager::saveToFile("test_npcs.txt", npcs);

    std::vector<std::unique_ptr<NPC>> loadedNpcs;
    FileManager::loadFromFile("test_npcs.txt", loadedNpcs);

    EXPECT_EQ(loadedNpcs.size(), 1);
    EXPECT_EQ(loadedNpcs[0]->getType(), "Rogue");
    EXPECT_EQ(loadedNpcs[0]->getName(), "Rogue1");
    EXPECT_EQ(loadedNpcs[0]->getX(), 5);
    EXPECT_EQ(loadedNpcs[0]->getY(), 5);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}