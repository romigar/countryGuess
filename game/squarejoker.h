#ifndef SQUAREJOKER_H
#define SQUAREJOKER_H

#include <QObject>

class squareJoker : public QObject
{
    Q_OBJECT
public:
    explicit squareJoker(QObject *parent = nullptr);
    bool isActivated;
    QStringList squareList;
    QString goodAnswer;
    QString region;

signals:

public slots:
};

#endif // SQUAREJOKER_H
