#ifndef CITY_H
#define CITY_H

#include <QObject>

class city
{
public:
    city();             // public constructor
    city(const city&);  // public copy constructor
    city(uint8_t _id, std::string _name, uint32_t _population);
    ~city();

    std::string name;
    uint8_t id;
    uint32_t population;

    uint8_t getId(void);
    void setId(uint8_t newId);
    std::string getName(void);
    void setName(std::string newName);
    uint32_t getPopulation(void);
    void setPopulation(uint32_t newPopulation);
    void display();
signals:

public slots:

private:

};

#endif // CITY_H

