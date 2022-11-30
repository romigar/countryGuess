#include <iostream>
#include "continent.h"
#include "country.h"

continent::continent(void)
{

}

continent::continent(std::string _name, uint8_t _id)
{
    setId(_id);
    setName(_name);
}


/* ***************************************************************** */

inline uint8_t continent::getId(void){   return id;  }

/* ***************************************************************** */

inline void continent::setId(uint8_t newId){    id = newId;  }

/* ***************************************************************** */

inline std::string continent::getName(void){    return name; }

/* ***************************************************************** */

inline void continent::setName(std::string newName){    name = newName;  }

/* ***************************************************************** */

void continent::display(void)
{
    std::cout<<"Country:{ ";
    std::cout<<"  name :"<< getName() <<","<<std::endl;
    std::cout<<"  id :"<< +getId() <<","<<std::endl;
    std::cout<<"  nb_countries :"<< list.size() <<","<<std::endl;
    std::cout<<"}"<<std::endl;
}
