#ifndef COUNTRY_H
#define COUNTRY_H

#include <QObject>

class city;

class country : public QObject
{
    Q_OBJECT
public:
    explicit country(QObject *parent = nullptr);
    explicit country(uint8_t _id, QString _name, uint32_t _population,
                     QString _continent, QObject *parent = nullptr);
    explicit country(uint8_t _id, QString _name, uint32_t _population,
                     QString _continent,
                     uint8_t c_id, QString c_name, uint32_t c_pop,
                     QObject *parent = nullptr);

    uint8_t getId(void);
    void setId(uint8_t newId);
    QString getName(void);
    void setName(QString newName);
    uint32_t getPopulation(void);
    void setPopulation(uint32_t newPopulation);
    QString getContinent(void);
    void setContinent(QString newContinent);

signals:

public slots:

private:
    QString name;
    uint8_t id;
    uint32_t population;
    QString continent;
    uint8_t continentId;
    city* capital;
};

#endif // COUNTRY_H
