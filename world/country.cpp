#include <iostream>
#include "country.h"
#include "city.h"

country::country()
{
}

country::country(const country& other)
    : capital(new city(*other.capital))
{
    setId(other.id);
    setName(other.name);
    setPopulation(other.population);
    setContinent(other.continent);
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

/* ***************************************************************** */

void country::display_name(void)
{
    std::cout<<getName()<<std::endl;
}
