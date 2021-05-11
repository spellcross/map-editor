#ifndef ENEMY_H
#define ENEMY_H

#include <stdint.h>

struct Unit
{
    uint8_t id_;
    QString name_;
    uint8_t membersCount_;

    Unit(uint8_t id, const QString& name, uint8_t membersCount)
        : id_(id)
        , name_(name)
        , membersCount_(membersCount)
    {

    }

    Unit()
        : id_(-1)
        , name_(QString())
        , membersCount_(0)
    {

    }
};



#endif // ENEMY_H




