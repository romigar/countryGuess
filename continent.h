#ifndef CONTINENT_H
#define CONTINENT_H

#include <QObject>

class country;

class continent : public QObject
{
    Q_OBJECT
public:
    explicit continent(QObject *parent = nullptr);

    uint8_t getId(void);
    void setId(uint8_t newId);
    QString getName(void);
    void setName(QString newName);

signals:

public slots:

private:
    QList<country> list;
    QString name;
    uint8_t id;
};

#endif // CONTINENT_H
