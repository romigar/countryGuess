#include <iostream>
#include <QRandomGenerator>
#include <QList>
#include "engine.h"
#include "gamesettings.h"
#include "continent.h"
#include "country.h"
#include "city.h"
#include "squarejoker.h"

using namespace std;


engine::engine(QObject *parent)
    : QObject(parent)
    , settings(new gameSettings(this))
    , square(new squareJoker(this))
    , m_continent(new continent())
    , m_country(new country())
{

}

/* ***************************************************************** */

void engine::setNewQuestion(void)
{
    if (m_continent->list.empty()){
        std::cout<<"Empty list"<<std::endl;
        return;
    }
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    std::random_shuffle(m_continent->list.begin(),m_continent->list.end());
    *m_country = m_continent->list.back();
    m_continent->list.pop_back();
    setQuestion(QString::fromStdString(m_country->getName()));
    setRightAnswer(QString::fromStdString(m_country->capital->getName()));
}

/* ***************************************************************** */

void engine::onButtonAnswerClicked(QString answer, uint8_t points)
{
    if (rightAnswer == answer) {
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
    // Générer une liste de 3 réponses fausses du meme continent
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
