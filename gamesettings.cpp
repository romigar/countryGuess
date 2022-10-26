#include <QObject>
#include "gamesettings.h"

gameSettings::gameSettings(QObject *parent) : QObject(parent)
{

}

/* ***************************************************************** */

inline uint32_t gameSettings::getScore(void){ return score; }
inline uint32_t gameSettings::getBestScore(void){ return bestScore; }
inline uint32_t gameSettings::getChrono(void){ return chrono; }
inline uint32_t gameSettings::getTimeLimit(void){ return timeLimit; }
inline uint32_t gameSettings::getTimeRemaining(void){ return timeRemaining; }
inline uint8_t gameSettings::getCountriesTotal(void){ return countriesTotal; }
inline uint8_t gameSettings::getCountriesFound(void){ return countriesFound; }
inline QString gameSettings::getPlayerName(void){ return playerName; }
inline QString gameSettings::getBestScoreName(void){ return bestScoreName; }

/* ***************************************************************** */

void gameSettings::setScore(uint32_t val)
{
    score = val;
    emit scoreChanged();
}

/* ***************************************************************** */

void gameSettings::setBestScore(uint32_t val)
{
    bestScore = val;
    emit bestScoreChanged();
}

/* ***************************************************************** */

void gameSettings::setChrono(uint32_t val)
{
    chrono = val;
    emit chronoChanged();
}

/* ***************************************************************** */

void gameSettings::setTimeLimit(uint32_t val)
{
    timeLimit = val;
    emit timeLimitChanged();
}

/* ***************************************************************** */

void gameSettings::setTimeRemaining(uint32_t val)
{
    timeRemaining = val;
    emit timeRemainingChanged();
}

/* ***************************************************************** */

void gameSettings::setCountriesTotal(uint8_t val)
{
    countriesTotal = val;
    emit countriesTotalChanged();
}

/* ***************************************************************** */

void gameSettings::setCountriesFound(uint8_t val)
{
    countriesFound = val;
    emit countriesFoundChanged();
}

/* ***************************************************************** */

void gameSettings::setPlayerName(QString val)
{
    playerName = val;
    emit playerNameChanged();
}

/* ***************************************************************** */

void gameSettings::setBestScoreName(QString val)
{
    bestScoreName = val;
    emit bestScoreChanged();
}

/* ***************************************************************** */
