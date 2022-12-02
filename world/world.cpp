#include <QObject>
#include <QFile>
#include <QDebug>
#include <iostream>
#include <vector>
#include "world.h"
#include "country.h"
#include "continent.h"


void fill_from_csv(std::vector<country> *_countryList)
{
    QFile envFile("/home/theo/workspace/countryGuess/ressources/liste.csv");
    int i = 0 ;
    if (envFile.open(QIODevice::ReadOnly)) {
        QTextStream in(&envFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList list = line.split(',');
            std::string _country = list.at(0).toStdString();
            std::string _capital = list.at(1).toStdString();
            std::string _continent = list.at(2).toStdString();
            _countryList->push_back(*new country(i,_country,_continent,_capital));
            i++;
        }
        envFile.close();
        std::cout<<  "Init list finished. Size : " << _countryList->size() <<std::endl;
    }
    else {
        std::cout<<  "can not open file"<<std::endl;
    }
}

/* ***************************************************************** */

void fillList(std::vector<country> countrylist,std::vector<continent> *_continentList)
{
    bool known_region = false;
    _continentList->clear();
    std::vector<std::vector<country>> newContList;
    std::vector<country> first;
    first.push_back(countrylist.at(0));
    newContList.push_back(first);

    for (int i = 1 ; i  < countrylist.size() ; i++) {
        known_region = false;
        for (int k = 0; k < newContList.size(); k++) {
            if (!countrylist.at(i).getContinent().compare( newContList.at(k).at(0).getContinent() ) ) {
                newContList.at(k).push_back(countrylist.at(i));
                known_region = true;
            }
        }
        if (!known_region) {
            std::vector<country> newContinent;
            newContinent.push_back(countrylist.at(i));
            newContList.push_back(newContinent);
        }
    }
    for (int k = 0; k < newContList.size(); k++) {
        _continentList->push_back(*new continent(newContList.at(k).at(0).getContinent(),k,newContList.at(k)));
    }
}

/* ***************************************************************** */

void world::fillContinentList(void)
{
    fill_from_csv(&countryList);
    fillList(countryList,&continentList);
}

/* ***************************************************************** */

world::world()
{
    fillContinentList();
}

/* ***************************************************************** */

world::world(std::vector<continent> _continentList)
{
    continentList = _continentList;
}

/* ***************************************************************** */

world::world(std::vector<country> _countryList, std::vector<continent> _continentList)
{
    continentList = _continentList;
    countryList = _countryList;
}

/* ***************************************************************** */

world::world(std::vector<country> _countryList)
{
    countryList = _countryList;
}

/* ***************************************************************** */

void world::display(void)
{
    std::cout<<"World: { ";
    std::cout<<"  Countries:"<< countryList.size() <<","<<std::endl;
    std::cout<<"  Continents :"<< continentList.size() <<","<<std::endl;
    std::cout<<"  Continents:"<< countryList.size() <<"["<<std::endl;
    for (int i = 0 ; i < continentList.size();i++) {
        continentList.at(i).display();
    }
    std::cout<<"}"<<std::endl;

}

/* ***************************************************************** */



