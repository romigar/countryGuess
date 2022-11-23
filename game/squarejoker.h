#ifndef SQUAREJOKER_H
#define SQUAREJOKER_H

#include <QObject>

class squareJoker : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isActivated READ getActivated WRITE setActivated NOTIFY activatedChanged)

public:
    explicit squareJoker(QObject *parent = nullptr);
    explicit squareJoker(bool isActivated, QString region, QObject *parent = nullptr);
    explicit squareJoker(bool isActivated, QString region, QString goodAnswer, QObject *parent = nullptr);

    bool isActivated;
    QStringList squareList;
    QString goodAnswer;
    QString region;

    void activateSquareJoker(QString answer);
    void generateList(void);
    void setGoodAnswer(QString val);
    void setActivated(bool active);
    bool getActivated(void);


signals:
    void activatedChanged(void);

public slots:
};

#endif // SQUAREJOKER_H
