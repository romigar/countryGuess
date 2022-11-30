#include <iostream>
#include "country.h"
#include "city.h"

country::country()
{
}

country::country(uint8_t _id, std::string _name, uint32_t _population,
                 std::string _continent, city capital)
    : capital(new city(capital))
{
    setId(_id);
    setName(_name);
    setPopulation(_population);
    setContinent(_continent);
}

country::~country()
{
}

/* ***************************************************************** */

inline uint8_t country::getId(void){   return id;  }
inline void country::setId(uint8_t newId){    id = newId;  }
inline std::string country::getName(void){    return name; }
inline void country::setName(std::string newName){    name = newName;  }
inline uint32_t country::getPopulation(void){  return population;  }
inline void country::setPopulation(uint32_t newPopulation){    population = newPopulation; }
inline std::string country::getContinent(void){    return continent;   }
inline void country::setContinent(std::string newContinent){   continent = newContinent;   }
inline uint8_t country::getContinentId(void){    return continentId;   }
inline void country::setContinentId(uint8_t newContinentId){   continentId = newContinentId;   }


/* ***************************************************************** */
/*
void country::swap(country& other)
{
    std::string _name = other.name;
    uint8_t _id = other.getId();
    uint32_t _population = other.getPopulation();
    std::string _continent = other.getContinent();
    uint8_t _continentId = other.getContinentId();
    std::string _c_name = other.capital->name;
    uint8_t _c_id = other.capital->id;
    uint32_t _c_population = other.capital->population;

    other.setName(name);
    other.setId(id);
    other.setPopulation(getPopulation());
    other.setContinent(getContinent());
    other.setContinentId(getContinentId());
    other.capital->setName(capital->name);
    other.capital->setId(capital->id);
    other.capital->setPopulation(capital->population);

    setName(_name);
    setId(_id);
    setPopulation(_population);
    setContinent(_continent);
    setContinentId(_continentId);
    this->capital->setName(_c_name);
    this->capital->setId(_c_id);
    this->capital->setPopulation(_c_population);
}
*/
/* ***************************************************************** */


void country::display(void)
{
    std::cout<<"Country:{ ";
    std::cout<<"  name : "<< getName() <<","<<std::endl;
    std::cout<<"  population : "<< getPopulation() <<","<<std::endl;
    std::cout<<"  id : "<< +getId() <<","<<std::endl;
    std::cout<<"  continent : "<< getContinent() <<","<<std::endl;
    std::cout<<"  continentId : "<< +getContinentId() <<","<<std::endl;
    std::cout<<"  capital : ";
    this->capital->display();
    std::cout<<"}"<<std::endl;
}
