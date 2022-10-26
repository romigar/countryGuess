#include "city.h"

city::city(QObject *parent) : QObject(parent)
{

}

city::city(uint8_t _id, QString _name, uint32_t _population, QObject *parent)
    : QObject(parent)
{
    setId(_id);
    setName(_name);
    setPopulation(_population);
}


/* ***************************************************************** */

inline uint8_t city::getId(void){   return id;  }

/* ***************************************************************** */

inline QString city::getName(void){   return name;  }

/* ***************************************************************** */

inline uint32_t city::getPopulation(void){   return population;  }

/* ***************************************************************** */

inline void city::setPopulation(uint32_t newPopulation){   population = newPopulation;  }

/* ***************************************************************** */

inline void city::setName(QString newName){   name = newName;  }

/* ***************************************************************** */

inline void city::setId(uint8_t newId){   id = newId;  }

/* ***************************************************************** */
