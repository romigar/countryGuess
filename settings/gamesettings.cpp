#include <QObject>
#include <QDebug>
#include "gamesettings.h"

gameSettings::gameSettings(QObject *parent) : QObject(parent)
{

}

/* ***************************************************************** */

uint32_t gameSettings::getScore(void){ return score; }
uint32_t gameSettings::getBestScore(void){ return bestScore; }
uint32_t gameSettings::getChrono(void){ return chrono; }
uint32_t gameSettings::getTimeLimit(void){ return timeLimit; }
uint32_t gameSettings::getTimeRemaining(void){ return timeRemaining; }
uint8_t gameSettings::getCountriesTotal(void){ return countriesTotal; }
uint8_t gameSettings::getCountriesFound(void){ return countriesFound; }
QString gameSettings::getPlayerName(void){ return playerName; }
QString gameSettings::getBestScoreName(void){ return bestScoreName; }

/* ***************************************************************** */

void gameSettings::onBadAnswer(uint8_t points)
{
    setScore(score-points);
    //afficher bonne réponse
}

/* ***************************************************************** */

void gameSettings::onGoodAnswer(uint8_t points)
{
    setScore(score+points);
    //afficher bonne réponse
}

/* ***************************************************************** */

void gameSettings::onJokerAsked(void)
{
    // Générer une liste de 3 réponses fausses du mauvais continent
    // Ajouter la bonne réponse
    // Mélanger la liste
    // Mettre à jour les textes boutons
}

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
