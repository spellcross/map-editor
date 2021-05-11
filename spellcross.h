#ifndef SPELLCROSS_H
#define SPELLCROSS_H

#include <memory>
#include <QMap>

struct Map;
struct Unit;


class SpellCross
{
public:
    SpellCross();

    void init();

    QList<std::shared_ptr<Map>> getMapList() const;
    std::shared_ptr<Map> getMap(const QString& mapName) const;


    std::shared_ptr<Unit> getEnemy(int id) const;


private:
    QMap<QString, std::shared_ptr<Map>> maps_;
    QMap<int, std::shared_ptr<Unit>> units_;
};

#endif // SPELLCROSS_H
