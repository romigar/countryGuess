#include "squarejoker.h"
#include <QRandomGenerator>

squareJoker::squareJoker(QObject *parent) : QObject(parent)
{

}

/* ***************************************************************** */

squareJoker::squareJoker(bool _isActivated, QString _region, QObject *parent)
    : QObject (parent)
{
    isActivated = _isActivated;
    region = _region;
}

/* ***************************************************************** */

squareJoker::squareJoker(bool _isActivated, QString _region, QString _goodAnswer, QObject *parent)
    : QObject (parent)
{
    isActivated = _isActivated;
    region = _region;
    goodAnswer = _goodAnswer;
}

/* ***************************************************************** */

void squareJoker::generateList(void)
{

    // Générer une liste de 3 réponses fausses du meme continent
    // Ajouter la bonne réponse
    // Mélanger la liste
    // Mettre à jour les textes boutons
    squareList.insert(0,goodAnswer);
    squareList.insert(1,"");
    squareList.insert(2,"");
    squareList.insert(3,"");

    // Random pick
    // countryList.at(QRandomGenerator::global()->bounded(countryList.size1 +1));

    std::srand ( unsigned ( std::time(0)));
    std::random_shuffle(squareList.begin(), squareList.end());

}

/* ***************************************************************** */

void squareJoker::setGoodAnswer(QString val)
{
    goodAnswer = val;
}

/* ***************************************************************** */

void squareJoker::setActivated(bool active)
{
    isActivated = active;
    emit activatedChanged();
}

/* ***************************************************************** */

bool squareJoker::getActivated(void)
{
    return isActivated;
}

/* ***************************************************************** */

void squareJoker::activateSquareJoker(QString answer)
{
    setGoodAnswer(answer);
    generateList();
    setActivated(true);
}

/* ***************************************************************** */

