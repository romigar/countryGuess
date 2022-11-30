#ifndef COUNTRY_H
#define COUNTRY_H

#include <QObject>

class city;

class country
{

public:
    country();
    country(const country&);
    country(uint8_t _id, std::string _name, uint32_t _population,
                     std::string _continent, city capital);
    ~country();

    std::string name;
    uint8_t id;
    uint32_t population;
    std::string continent;
    uint8_t continentId;
    city* capital;

    uint8_t getId(void);
    void setId(uint8_t newId);
    std::string getName(void);
    void setName(std::string newName);
    uint32_t getPopulation(void);
    void setPopulation(uint32_t newPopulation);
    std::string getContinent(void);
    void setContinent(std::string newContinent);
    uint8_t getContinentId(void);
    void setContinentId(uint8_t newContinentId);

  //  void swap(country& other);

    void display(void);
    void display_name(void);

signals:

public slots:

private:

};

//void swap(country& lhs, country& rhs){ lhs.swap(rhs); }


#endif // COUNTRY_H
