#include "country.h"
#include "city.h"

country::country(QObject *parent) : QObject(parent)
{

}

country::country(uint8_t _id, QString _name, uint32_t _population,
                 QString _continent, QObject *parent)
    : QObject(parent)
    , capital(new city(this))
{
    setId(_id);
    setName(_name);
    setPopulation(_population);
    setContinent(_continent);
}

country::country(uint8_t _id, QString _name, uint32_t _population,
                 QString _continent,
                 uint8_t c_id, QString c_name, uint32_t c_pop,
                 QObject *parent)
    : QObject(parent)
    , capital(new city(c_id,c_name,c_pop,this))
{
    setId(_id);
    setName(_name);
    setPopulation(_population);
    setContinent(_continent);
}



/* ***************************************************************** */

inline uint8_t country::getId(void){   return id;  }

/* ***************************************************************** */

inline void country::setId(uint8_t newId){    id = newId;  }

/* ***************************************************************** */

inline QString country::getName(void){    return name; }

/* ***************************************************************** */

inline void country::setName(QString newName){    name = newName;  }

/* ***************************************************************** */

inline uint32_t country::getPopulation(void){  return population;  }

/* ***************************************************************** */

inline void country::setPopulation(uint32_t newPopulation){    population = newPopulation; }

/* ***************************************************************** */

inline QString country::getContinent(void){    return continent;   }

/* ***************************************************************** */

inline void country::setContinent(QString newContinent){   continent = newContinent;   }

/* ***************************************************************** */

