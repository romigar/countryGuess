#ifndef WORLD_H
#define WORLD_H

#include <QObject>

class country;
class continent;

class world : public QObject
{
    Q_OBJECT
public:
    explicit world(QObject *parent = nullptr);

signals:

public slots:

private:
    QList<country> countryList;
    QList<continent> continentList;

};

#endif // WORLD_H
