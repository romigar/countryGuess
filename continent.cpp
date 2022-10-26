#include "continent.h"
#include "country.h"

continent::continent(QObject *parent) : QObject(parent)
{

}

/* ***************************************************************** */

inline uint8_t continent::getId(void){   return id;  }

/* ***************************************************************** */

inline void continent::setId(uint8_t newId){    id = newId;  }

/* ***************************************************************** */

inline QString continent::getName(void){    return name; }

/* ***************************************************************** */

inline void continent::setName(QString newName){    name = newName;  }

/* ***************************************************************** */
