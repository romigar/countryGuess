#include <QObject>
#include <QDebug>
#include "gamesettings.h"

gameSettings::gameSettings(QObject *parent) : QObject(parent)
{

}

/* ***************************************************************** */

uint32_t gameSettings::getBestScore(void){ return bestScore; }
uint32_t gameSettings::getTimeLimit(void){ return timeLimit; }
uint8_t gameSettings::getCountriesTotal(void){ return countriesTotal; }
QString gameSettings::getPlayerName(void){ return playerName; }
QString gameSettings::getBestScoreName(void){ return bestScoreName; }

/* ***************************************************************** */

void gameSettings::setBestScore(uint32_t val)
{
    bestScore = val;
    emit bestScoreChanged();
}

/* ***************************************************************** */

void gameSettings::setTimeLimit(uint32_t val)
{
    timeLimit = val;
    emit timeLimitChanged();
}

/* ***************************************************************** */

void gameSettings::setCountriesTotal(uint8_t val)
{
    countriesTotal = val;
    emit countriesTotalChanged();
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
