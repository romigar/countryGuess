#include <iostream>
#include "city.h"


city::city(uint8_t _id, std::string _name, uint32_t _population)
{
    setId(_id);
    setName(_name);
    setPopulation(_population);
}

city::city(const city& other)
{
    setName(other.name);
    setPopulation(other.population);
    setId(other.id);
}

city::city(){ }


city::~city()
{
    std::cout<<"city deleted"<<std::endl;
}


/* ***************************************************************** */

inline uint8_t city::getId(void){   return id;  }

/* ***************************************************************** */

inline std::string city::getName(void){   return name;  }

/* ***************************************************************** */

inline uint32_t city::getPopulation(void){   return population;  }

/* ***************************************************************** */

inline void city::setPopulation(uint32_t newPopulation){   population = newPopulation;  }

/* ***************************************************************** */

inline void city::setName(std::string newName){   name = newName;  }

/* ***************************************************************** */

inline void city::setId(uint8_t newId){   id = newId;  }

/* ***************************************************************** */

void city::display(void)
{
    std::cout<<"City:{ "<<std::endl;
    std::cout<<"  name : "<< this->getName() <<","<<std::endl;
    std::cout<<"  population : "<< this->getPopulation() <<","<<std::endl;
    std::cout<<"  id : "<< +this->getId() <<std::endl;
    std::cout<<"}"<<std::endl;
}
