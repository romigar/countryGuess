#include "world.h"
#include "country.h"
#include "continent.h"

world::world()
{

}

world::world(std::vector<continent> _continentList)
{
    continentList = _continentList;
}

world::world(std::vector<country> _countryList, std::vector<continent> _continentList)
{
    continentList = _continentList;
    countryList = _countryList;
}

world::world(std::vector<country> _countryList)
{
    countryList = _countryList;
}
