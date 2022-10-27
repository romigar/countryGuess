#include <QRandomGenerator>
#include <QList>
#include "engine.h"
#include "gamesettings.h"
#include "continent.h"
#include "country.h"
#include "city.h"


engine::engine(QObject *parent) : QObject(parent)
{

}

/* ***************************************************************** */

void engine::setNewQuestion(void)
{
    uint8_t i = QRandomGenerator::global()->bounded(m_continent->list.size() + 1);
    m_country->setId(m_continent->list.at(i).id);
    m_country->setName(m_continent->list.at(i).name);
    m_country->setContinent(m_continent->list.at(i).continent);
    m_country->setPopulation(m_continent->list.at(i).population);
    m_country->capital = m_continent->list.at(i).capital;
    m_continent->list.removeAt(i);
    setQuestion(m_country->getName());
    setRightAnswer(m_country->capital->getName());
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
    setCountriesFound(getCountriesFound()+1);
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
QString engine::getRightAnswer(void){ return rightAnswer; }
QString engine::getQuestion(void){ return question; }


/* ***************************************************************** */

void engine::setRightAnswer(QString val)
{
    rightAnswer = val;
    emit rightAnswerChanged();
}

/* ***************************************************************** */

void engine::setQuestion(QString val)
{
    question = val;
    emit questionChanged();
}

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

