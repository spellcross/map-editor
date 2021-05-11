#include "spellcross.h"

#include "maps.h"
#include "unit.h"


SpellCross::SpellCross()
{

}

void SpellCross::init()
{



    QList<std::shared_ptr<Map>> list;
    list.append(std::make_shared<Map>("M01_01", 100, 84, 55, 120));
    list.append(std::make_shared<Map>("M02_01", 40, 60, 55, 120));
    list.append(std::make_shared<Map>("M02_02", 45, 65, 55, 120));
    list.append(std::make_shared<Map>("M02_03", 60, 90, 55, 120));
    list.append(std::make_shared<Map>("M02_04", 35, 85, 55, 120));
    list.append(std::make_shared<Map>("M02_05", 55, 95, 55, 120));
    list.append(std::make_shared<Map>("M02_06", 40, 60, 55, 155));
    list.append(std::make_shared<Map>("M03_01", 40, 70, 55, 120));
    list.append(std::make_shared<Map>("M03_02", 60, 80, 55, 155));
    list.append(std::make_shared<Map>("M03_03", 70, 95, 55, 85));
    list.append(std::make_shared<Map>("M03_04", 50, 70, 55, 120));
    list.append(std::make_shared<Map>("M03_05", 60, 80, 55, 120));
    list.append(std::make_shared<Map>("M03_06", 60, 70, 55, 85));
    list.append(std::make_shared<Map>("M03_07", 40, 96, 55, 120));
    list.append(std::make_shared<Map>("M03_08", 40, 86, 55, 85));
    list.append(std::make_shared<Map>("M03_09", 50, 96, 55, 155));
    list.append(std::make_shared<Map>("M03_10", 30, 130, 55, 120));
    list.append(std::make_shared<Map>("M03_11", 50, 60, 55, 120));
    list.append(std::make_shared<Map>("M03_12", 50, 96, 55, 155));
    list.append(std::make_shared<Map>("M03_13", 70, 130, 55, 140));
    list.append(std::make_shared<Map>("M04_01", 46, 60, 55, 120));
    list.append(std::make_shared<Map>("M04_02", 60, 60, 55, 120));
    list.append(std::make_shared<Map>("M04_03", 70, 70, 55, 120));
    list.append(std::make_shared<Map>("M04_04", 36, 90, 55, 120));
    list.append(std::make_shared<Map>("M04_05", 46, 100, 55, 120));
    list.append(std::make_shared<Map>("M04_06", 56, 100, 55, 120));
    list.append(std::make_shared<Map>("M04_07", 30, 68, 55, 120));
    list.append(std::make_shared<Map>("M04_08", 50, 70, 55, 155));
    list.append(std::make_shared<Map>("M04_09", 50, 90, 55, 155));
    list.append(std::make_shared<Map>("M04_10", 100, 126, 55, 120));
    list.append(std::make_shared<Map>("M04_11", 40, 60, 55, 120));
    list.append(std::make_shared<Map>("M04_12", 60, 60, 55, 85));
    list.append(std::make_shared<Map>("M04_13", 46, 70, 55, 120));
    list.append(std::make_shared<Map>("M04_14", 70, 88, 55, 120));
    list.append(std::make_shared<Map>("M04_15", 36, 70, 55, 120));
    list.append(std::make_shared<Map>("M04_16", 36, 80, 55, 155));
    list.append(std::make_shared<Map>("M05_01", 60, 70, 55, 155));
    list.append(std::make_shared<Map>("M05_02", 46, 70, 55, 120));
    list.append(std::make_shared<Map>("M05_03", 68, 70, 55, 120));
    list.append(std::make_shared<Map>("M05_04", 46, 126, 55, 120));
    list.append(std::make_shared<Map>("M05_05", 50, 66, 55, 155));
    list.append(std::make_shared<Map>("M05_06", 66, 120, 55, 120));
    list.append(std::make_shared<Map>("M05_07", 46, 100, 55, 120));
    list.append(std::make_shared<Map>("M05_08", 68, 100, 55, 120));
    list.append(std::make_shared<Map>("M05_09", 46, 126, 55, 120));
    list.append(std::make_shared<Map>("M06_01", 50, 74, 55, 120));
    list.append(std::make_shared<Map>("M06_02", 40, 94, 55, 120));
    list.append(std::make_shared<Map>("M06_03", 50, 94, 55, 120));
    list.append(std::make_shared<Map>("M06_04", 56, 104, 55, 120));
    list.append(std::make_shared<Map>("M06_05", 30, 74, 55, 120));
    list.append(std::make_shared<Map>("M06_06", 60, 90, 55, 140));
    list.append(std::make_shared<Map>("M06_07", 60, 100, 55, 120));
    list.append(std::make_shared<Map>("M06_08", 30, 100, 55, 120));
    list.append(std::make_shared<Map>("M06_09", 50, 74, 55, 140));
    list.append(std::make_shared<Map>("M06_10", 40, 80, 55, 85));
    list.append(std::make_shared<Map>("M06_11", 50, 84, 55, 120));
    list.append(std::make_shared<Map>("M06_12", 40, 126, 55, 140));
    list.append(std::make_shared<Map>("M06_13", 70, 124, 55, 140));
    list.append(std::make_shared<Map>("M06_14", 30, 64, 55, 120));
    list.append(std::make_shared<Map>("M07_01", 40, 74, 55, 120));
    list.append(std::make_shared<Map>("M07_02", 30, 84, 55, 120));
    list.append(std::make_shared<Map>("M07_03", 50, 94, 55, 120));
    list.append(std::make_shared<Map>("M07_04", 40, 104, 55, 120));
    list.append(std::make_shared<Map>("M07_05", 50, 94, 55, 120));
    list.append(std::make_shared<Map>("M07_06", 40, 80, 55, 120));
    list.append(std::make_shared<Map>("M07_07", 40, 104, 55, 120));
    list.append(std::make_shared<Map>("M07_08", 40, 114, 55, 120));
    list.append(std::make_shared<Map>("M07_09", 50, 94, 55, 120));
    list.append(std::make_shared<Map>("M07_10", 35, 70, 55, 120));
    list.append(std::make_shared<Map>("M07_11", 40, 120, 55, 120));
    list.append(std::make_shared<Map>("M07_12", 50, 84, 55, 120));
    list.append(std::make_shared<Map>("M07_13", 60, 94, 55, 120));
    list.append(std::make_shared<Map>("M07_14", 100, 60, 55, 120));
    list.append(std::make_shared<Map>("M08_01", 50, 84, 55, 120));
    list.append(std::make_shared<Map>("M08_04", 30, 74, 55, 120));
    list.append(std::make_shared<Map>("M08_05", 40, 84, 55, 120));
    list.append(std::make_shared<Map>("M08_06", 50, 94, 55, 120));
    list.append(std::make_shared<Map>("M08_07", 34, 64, 55, 120));
    list.append(std::make_shared<Map>("M08_09", 70, 114, 55, 120));
    list.append(std::make_shared<Map>("M08_12", 40, 120, 55, 120));
    list.append(std::make_shared<Map>("M08_13", 30, 74, 55, 120));
    list.append(std::make_shared<Map>("M08_14", 40, 64, 55, 120));
    list.append(std::make_shared<Map>("M08_15", 34, 84, 55, 120));
    list.append(std::make_shared<Map>("M08_16", 54, 84, 55, 120));
    list.append(std::make_shared<Map>("M08_17", 34, 94, 55, 120));
    list.append(std::make_shared<Map>("M08_18", 44, 74, 55, 120));
    list.append(std::make_shared<Map>("M08_19", 44, 74, 55, 120));
    list.append(std::make_shared<Map>("M08_20", 64, 114, 55, 120));
    list.append(std::make_shared<Map>("M09_01", 44, 84, 55, 120));
    list.append(std::make_shared<Map>("M09_02", 44, 84, 55, 120));
    list.append(std::make_shared<Map>("M09_03", 44, 84, 55, 120));
    list.append(std::make_shared<Map>("M09_04", 46, 70, 55, 120));
    list.append(std::make_shared<Map>("M09_05", 44, 84, 55, 120));
    list.append(std::make_shared<Map>("M09_06", 30, 54, 55, 120));
    list.append(std::make_shared<Map>("M09_07", 44, 84, 55, 120));
    list.append(std::make_shared<Map>("M09_08", 40, 74, 55, 120));
    list.append(std::make_shared<Map>("M09_09", 44, 84, 55, 85));
    list.append(std::make_shared<Map>("M09_10", 64, 84, 55, 120));
    list.append(std::make_shared<Map>("M09_11", 44, 74, 55, 120));
    list.append(std::make_shared<Map>("M09_12", 44, 74, 55, 120));
    list.append(std::make_shared<Map>("M09_13", 44, 120, 55, 140));
    list.append(std::make_shared<Map>("M10_01", 44, 66, 55, 120));
    list.append(std::make_shared<Map>("M10_02", 54, 116, 55, 120));
    list.append(std::make_shared<Map>("M10_03", 54, 114, 55, 120));
    list.append(std::make_shared<Map>("M10_03X", 54, 114, 55, 120));

    for (auto map : list)
    {
        maps_.insert(map->name_, map);
    }


    QList<std::shared_ptr<Unit>> enemyList;
//    enemyList.append(std::make_shared<Unit>("Orcs",            37,     100));
//    enemyList.append(std::make_shared<Unit>("Ka-Orcs",         38,     100));
//    enemyList.append(std::make_shared<Unit>("Wolves",          41,      20));
//    enemyList.append(std::make_shared<Unit>("Wolf Riders",     61,      20));
    enemyList.append(std::make_shared<Unit>(0, "Light Infantry", 100));
    enemyList.append(std::make_shared<Unit>(1, "Heavy Infantry", 100));
    enemyList.append(std::make_shared<Unit>(2, "Rangers", 20));
    enemyList.append(std::make_shared<Unit>(3, "Commandos", 20));
    enemyList.append(std::make_shared<Unit>(4, "Paranormal inf.", 20));
    enemyList.append(std::make_shared<Unit>(5, "Mine-throwers", 20));
    enemyList.append(std::make_shared<Unit>(6, "Hi-Tech Infantry", 20));
    enemyList.append(std::make_shared<Unit>(7, "Mobile Infantry", 10));
    enemyList.append(std::make_shared<Unit>(8, "Mobile Infantry", 10));
    enemyList.append(std::make_shared<Unit>(9, "Flame-throwers", 20));
    enemyList.append(std::make_shared<Unit>(10, "TAM", 10));
    enemyList.append(std::make_shared<Unit>(11, "M1 Abrams", 10));
    enemyList.append(std::make_shared<Unit>(12, "Leopard 2", 10));
    enemyList.append(std::make_shared<Unit>(13, "Leopard 2A5", 10));
    enemyList.append(std::make_shared<Unit>(14, "STRV", 10));
    enemyList.append(std::make_shared<Unit>(15, "Elmag 1",10));
    enemyList.append(std::make_shared<Unit>(16, "Elmag 2", 10));
    enemyList.append(std::make_shared<Unit>(17, "Destructor", 1));
    enemyList.append(std::make_shared<Unit>(18, "M113", 10));
    enemyList.append(std::make_shared<Unit>(19, "Marder", 10));
    enemyList.append(std::make_shared<Unit>(20, "Piranha", 10));
    enemyList.append(std::make_shared<Unit>(21, "AMX 13", 10));
    enemyList.append(std::make_shared<Unit>(22, "Gepard", 10));
    enemyList.append(std::make_shared<Unit>(23, "Roland", 10));
    enemyList.append(std::make_shared<Unit>(24, "AMX 30", 10));
    enemyList.append(std::make_shared<Unit>(25, "Light Artillery", 10));
    enemyList.append(std::make_shared<Unit>(26, "M109", 10));
    enemyList.append(std::make_shared<Unit>(27, "M106", 10));
    enemyList.append(std::make_shared<Unit>(28, "MLRS", 10));
    enemyList.append(std::make_shared<Unit>(29, "Hummer", 10));
    enemyList.append(std::make_shared<Unit>(30, "Universal 1R", 10));
    enemyList.append(std::make_shared<Unit>(31, "Universal 2R", 10));
    enemyList.append(std::make_shared<Unit>(32, "Mi-24", 10));
    enemyList.append(std::make_shared<Unit>(33, "Laser - Strahler", 10));
    enemyList.append(std::make_shared<Unit>(34, "M132", 10));
    enemyList.append(std::make_shared<Unit>(35, "UDES", 10));
    enemyList.append(std::make_shared<Unit>(36, "UDES", 10));
    enemyList.append(std::make_shared<Unit>(37, "Orcs", 100));
    enemyList.append(std::make_shared<Unit>(38, "Ka-Orcs", 100));
    enemyList.append(std::make_shared<Unit>(39, "War-Orcs", 100));
    enemyList.append(std::make_shared<Unit>(40, "Anti-tank Orcs", 100));
    enemyList.append(std::make_shared<Unit>(41, "Wolfs", 20));
    enemyList.append(std::make_shared<Unit>(42, "Undeads", 100));
    enemyList.append(std::make_shared<Unit>(43, "Arachnoids", 20));
    enemyList.append(std::make_shared<Unit>(44, "Golem", 10));
    enemyList.append(std::make_shared<Unit>(45, "Ghosts", 20));
    enemyList.append(std::make_shared<Unit>(46, "Mri", 100));
    enemyList.append(std::make_shared<Unit>(47, "Magotar", 100));
    enemyList.append(std::make_shared<Unit>(48, "Magotar", 100));
    enemyList.append(std::make_shared<Unit>(49, "Dark Angels", 10));
    enemyList.append(std::make_shared<Unit>(50, "Harpy", 1));
    enemyList.append(std::make_shared<Unit>(51, "Kamikaze Birds", 10));
    enemyList.append(std::make_shared<Unit>(52, "Baloon", 10));
    enemyList.append(std::make_shared<Unit>(53, "Mechanical Tower", 10));
    enemyList.append(std::make_shared<Unit>(54, "Mechanical Mamooth", 10));
    enemyList.append(std::make_shared<Unit>(55, "Arrow-throwers", 10));
    enemyList.append(std::make_shared<Unit>(56, "Ballist", 10));
    enemyList.append(std::make_shared<Unit>(57, "Dark Elfs", 100));
    enemyList.append(std::make_shared<Unit>(58, "Elf Masters", 10));
    enemyList.append(std::make_shared<Unit>(59, "Sonic Cannon", 10));
    enemyList.append(std::make_shared<Unit>(60, "Slizoid", 10));
    enemyList.append(std::make_shared<Unit>(61, "Wolf Riders", 20));
    enemyList.append(std::make_shared<Unit>(62, "Hell Cavalry", 20));
    enemyList.append(std::make_shared<Unit>(63, "Knights of Death", 10));
    enemyList.append(std::make_shared<Unit>(64, "Dragon", 1));
    enemyList.append(std::make_shared<Unit>(65, "Fortress of Terror", 1));
    enemyList.append(std::make_shared<Unit>(66, "Breorn", 1));
    enemyList.append(std::make_shared<Unit>(67, "Demon", 1));
    enemyList.append(std::make_shared<Unit>(68, "Wizard", 1));
    enemyList.append(std::make_shared<Unit>(69, "Nekromant", 1));
    enemyList.append(std::make_shared<Unit>(70, "Magician", 1));
    enemyList.append(std::make_shared<Unit>(71, "Conjurer", 1));
    enemyList.append(std::make_shared<Unit>(72, "Predator", 10));
    enemyList.append(std::make_shared<Unit>(73, "Destructor", 1));
    enemyList.append(std::make_shared<Unit>(74, "Daertor", 1));
    enemyList.append(std::make_shared<Unit>(75, "Renegats", 100));
    enemyList.append(std::make_shared<Unit>(76, "Renegats", 100));
    enemyList.append(std::make_shared<Unit>(77, "Renegats", 10));
    enemyList.append(std::make_shared<Unit>(78, "Renegats", 10));
    enemyList.append(std::make_shared<Unit>(79, "Commander", 1));
    enemyList.append(std::make_shared<Unit>(80, "Konvoy", 10));
    enemyList.append(std::make_shared<Unit>(81, "Tharag-Gura", 1));
    enemyList.append(std::make_shared<Unit>(82, "Queen", 1));
    enemyList.append(std::make_shared<Unit>(83, "Unit with sword", 1));
    enemyList.append(std::make_shared<Unit>(84, "Ka-Wyrdrag", 1));
    enemyList.append(std::make_shared<Unit>(85, "Ka-Tugrag", 1));
    enemyList.append(std::make_shared<Unit>(86, "Kadura", 10));



    for (auto enemy : enemyList)
    {
        units_.insert(enemy->id_, enemy);
    }
}

QList<std::shared_ptr<Map> > SpellCross::getMapList() const
{
    return maps_.values();
}

std::shared_ptr<Map> SpellCross::getMap(const QString &mapName) const
{
    return maps_.value(mapName);
}

std::shared_ptr<Unit> SpellCross::getEnemy(int id) const
{
    return units_.value(id);
}
