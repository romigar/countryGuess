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
    QList<country> countryList;
    QList<continent> continentList;

signals:

public slots:

private:

};

#endif // WORLD_H
