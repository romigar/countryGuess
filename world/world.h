#ifndef WORLD_H
#define WORLD_H

#include <QObject>
#include <vector>

class country;
class continent;

class world
{
public:
    world();
    std::vector<country> countryList;
    std::vector<continent> continentList;

signals:

public slots:

private:

};

#endif // WORLD_H
