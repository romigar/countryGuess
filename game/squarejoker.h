#ifndef SQUAREJOKER_H
#define SQUAREJOKER_H

#include <QObject>

class squareJoker : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isActivated READ getActivated WRITE setActivated NOTIFY activatedChanged)

public:
    explicit squareJoker(QObject *parent = nullptr);
    explicit squareJoker(bool isActivated, QObject *parent = nullptr);

    bool isActivated;
    std::vector<std::string> squareList;

    void activateSquareJoker(std::string ans1, std::string ans2, std::string ans3, std::string ans4);
    void generateList(std::string ans1, std::string ans2, std::string ans3, std::string ans4);
    void setActivated(bool active);
    bool getActivated(void);


signals:
    void activatedChanged(void);

public slots:
};

#endif // SQUAREJOKER_H
