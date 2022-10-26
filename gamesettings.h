#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H

#include <QObject>

class gameSettings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(uint32_t score READ getScore WRITE setScore NOTIFY scoreChanged)
    Q_PROPERTY(uint32_t bestScore READ getBestScore WRITE setBestScore NOTIFY bestScoreChanged)
    Q_PROPERTY(uint32_t chrono READ getChrono WRITE setChrono NOTIFY chronoChanged)
    Q_PROPERTY(uint32_t timeLimit READ getTimeLimit WRITE setTimeLimit NOTIFY timeLimitChanged)
    Q_PROPERTY(uint32_t timeRemaining READ getTimeRemaining WRITE setTimeRemaining NOTIFY timeRemainingChanged)
    Q_PROPERTY(uint8_t countriesTotal READ getCountriesTotal WRITE setCountriesTotal NOTIFY countriesTotalChanged)
    Q_PROPERTY(uint8_t countriesFound READ getCountriesFound WRITE setCountriesFound NOTIFY countriesFoundChanged)
    Q_PROPERTY(QString bestScoreName READ getBestScoreName WRITE setBestScoreName NOTIFY bestScoreNameChanged)
    Q_PROPERTY(QString playerName READ getPlayerName WRITE setPlayerName NOTIFY playerNameChanged)

public:
    explicit gameSettings(QObject *parent = nullptr);

    uint32_t score;
    uint32_t bestScore;
    QString bestScoreName;
    QString playerName;
    uint32_t chrono;
    uint32_t timeLimit;
    uint32_t timeRemaining;
    uint8_t countriesTotal;
    uint8_t countriesFound;

    uint32_t getScore(void);
    uint32_t getBestScore(void);
    uint32_t getChrono(void);
    uint32_t getTimeLimit(void);
    uint32_t getTimeRemaining(void);
    uint8_t getCountriesTotal(void);
    uint8_t getCountriesFound(void);
    QString getBestScoreName(void);
    QString getPlayerName(void);
    void setScore(uint32_t val);
    void setBestScore(uint32_t val);
    void setChrono(uint32_t val);
    void setTimeLimit(uint32_t val);
    void setTimeRemaining(uint32_t val);
    void setCountriesTotal(uint8_t val);
    void setCountriesFound(uint8_t val);
    void setBestScoreName(QString val);
    void setPlayerName(QString val);




signals:
    void scoreChanged();
    void bestScoreChanged();
    void bestScoreNameChanged();
    void playerNameChanged();
    void chronoChanged();
    void timeLimitChanged();
    void timeRemainingChanged();
    void countriesTotalChanged();
    void countriesFoundChanged();
    void goodAnswer(uint8_t points);
    void badAnswer(uint8_t points);

public slots:
    void onGoodAnswer(uint8_t points);
    void onBadAnswer(uint8_t points);
    void onJokerAsked();
};

#endif // GAMESETTINGS_H
