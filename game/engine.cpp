#include <iostream>
#include <QRandomGenerator>
#include <QList>
#include "engine.h"
#include "gamesettings.h"
#include "world.h"
#include "continent.h"
#include "country.h"
#include "city.h"
#include "squarejoker.h"
#include "tools.h"

using namespace std;


engine::engine(QObject *parent)
    : QObject(parent)
    , settings(new gameSettings(this))
    , square(new squareJoker(this))
    , m_world(new world())
    , m_continent(new continent(m_world->continentList.at(0)))
    , m_country(new country())
{

    connect(this, SIGNAL(goodAnswer(uint8_t)), this, SLOT(onGoodAnswer(uint8_t)));
    connect(this, SIGNAL(badAnswer(uint8_t)), this, SLOT(onBadAnswer(uint8_t)));
    setChrono(0);
    setTimeRemaining(0);
    setCountriesFound(0);
    setScore(0);
    setNewQuestion();


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

void engine::onButtonAnswerClicked(QString answer, int points)
{
    std::cout<<"Answer : "<< answer.toStdString() <<std::endl;
    std::cout<<"RightAnswer : "<< rightAnswer.toStdString() <<std::endl;


    if (validDistance(rightAnswer.toLocal8Bit(),answer.toLocal8Bit(),0.3)) {
        std::cout<<"Bonne réponse"  <<std::endl;
        emit goodAnswer(points);
    }
    else {
        std::cout<<"Mauvaise réponse"  <<std::endl;

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

    std::cout<<"Score : "<< +score  <<std::endl;
    std::cout<<"Nombre de capitales trouvées : "<< +getCountriesFound()<<std::endl;

    //afficher bonne réponse
}

/* ***************************************************************** */

void engine::onJokerAsked(void)
{
    std::cout<<"Joker asked : "<< +score  <<std::endl;

    std::string ans1 = m_continent->list.at(0).getName();
    std::string ans2 = m_continent->list.at(1).getName();
    std::string ans3 = m_continent->list.at(2).getName();
    square->activateSquareJoker(ans1,ans2,ans3,rightAnswer.toStdString());

    //TODO : display list on buttons
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
