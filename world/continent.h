#ifndef CONTINENT_H
#define CONTINENT_H

#include <QObject>
#include <vector>
#include "country.h"

class country;

class continent
{
public:
    continent();
    continent(std::string name, uint8_t id);

    std::vector<country> list;
    std::string name;
    uint8_t id;

    uint8_t getId(void);
    void setId(uint8_t newId);
    std::string getName(void);
    void setName(std::string newName);

    void display(void);

signals:

public slots:

private:

};

#endif // CONTINENT_H
