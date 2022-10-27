#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>

class gameSettings;

class engine : public QObject
{
    Q_OBJECT
    Q_PROPERTY(uint32_t score READ getScore WRITE setScore NOTIFY scoreChanged)
    Q_PROPERTY(uint32_t chrono READ getChrono WRITE setChrono NOTIFY chronoChanged)
    Q_PROPERTY(uint32_t timeRemaining READ getTimeRemaining WRITE setTimeRemaining NOTIFY timeRemainingChanged)
    Q_PROPERTY(uint8_t countriesFound READ getCountriesFound WRITE setCountriesFound NOTIFY countriesFoundChanged)

public:
    explicit engine(QObject *parent = nullptr);

    gameSettings* settings;

    uint32_t score;
    uint32_t chrono;
    uint32_t timeRemaining;
    uint8_t countriesFound;

    uint32_t getScore(void);
    uint32_t getChrono(void);
    uint32_t getTimeRemaining(void);
    uint8_t getCountriesFound(void);
    void setScore(uint32_t val);
    void setChrono(uint32_t val);
    void setTimeRemaining(uint32_t val);
    void setCountriesFound(uint8_t val);

signals:
    void goodAnswer(uint8_t points);
    void badAnswer(uint8_t points);
    void scoreChanged();
    void chronoChanged();
    void timeRemainingChanged();
    void countriesFoundChanged();

public slots:
    void onGoodAnswer(uint8_t points);
    void onBadAnswer(uint8_t points);
    void onJokerAsked();

private:
};

#endif // ENGINE_H
