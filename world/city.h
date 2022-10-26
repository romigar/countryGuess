#ifndef CITY_H
#define CITY_H

#include <QObject>

class city : public QObject
{
    Q_OBJECT
public:
    explicit city(QObject *parent = nullptr);
    explicit city(uint8_t _id, QString _name, uint32_t _population, QObject *parent = nullptr);

    uint8_t getId(void);
    void setId(uint8_t newId);
    QString getName(void);
    void setName(QString newName);
    uint32_t getPopulation(void);
    void setPopulation(uint32_t newPopulation);

signals:

public slots:

private:
    QString name;
    uint8_t id;
    uint32_t population;
};

#endif // CITY_H

