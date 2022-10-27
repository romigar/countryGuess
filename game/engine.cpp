#include "engine.h"
#include "gamesettings.h"

engine::engine(QObject *parent) : QObject(parent)
{

}

/* ***************************************************************** */

void engine::onButtonAnswerClicked(QString answer, uint8_t points)
{
    if (true /*answer == goodAnswer */) {
        emit goodAnswer(points);
    }
    else {
        emit badAnswer(points);
    }
}

/* ***************************************************************** */

void engine::onBadAnswer(uint8_t points)
{
    setScore(score-points);
    //afficher bonne réponse
}

/* ***************************************************************** */

void engine::onGoodAnswer(uint8_t points)
{
    setScore(score+points);
    //afficher bonne réponse
}

/* ***************************************************************** */

void engine::onJokerAsked(void)
{
    // Générer une liste de 3 réponses fausses du mauvais continent
    // Ajouter la bonne réponse
    // Mélanger la liste
    // Mettre à jour les textes boutons
}

/* ***************************************************************** */



uint32_t engine::getScore(void){ return score; }
uint32_t engine::getChrono(void){ return chrono; }
uint32_t engine::getTimeRemaining(void){ return timeRemaining; }
uint8_t engine::getCountriesFound(void){ return countriesFound; }


/* ***************************************************************** */

void engine::setScore(uint32_t val)
{
    score = val;
    emit scoreChanged();
}

/* ***************************************************************** */

void engine::setChrono(uint32_t val)
{
    chrono = val;
    emit chronoChanged();
}

/* ***************************************************************** */

void engine::setTimeRemaining(uint32_t val)
{
    timeRemaining = val;
    emit timeRemainingChanged();
}

/* ***************************************************************** */

void engine::setCountriesFound(uint8_t val)
{
    countriesFound = val;
    emit countriesFoundChanged();
}

