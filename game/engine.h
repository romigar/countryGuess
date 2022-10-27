#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>

class gameSettings;
class squareJoker;
class world;
class continent;
class country;

class engine : public QObject
{
    Q_OBJECT
    Q_PROPERTY(uint32_t score READ getScore WRITE setScore NOTIFY scoreChanged)
    Q_PROPERTY(uint32_t chrono READ getChrono WRITE setChrono NOTIFY chronoChanged)
    Q_PROPERTY(uint32_t timeRemaining READ getTimeRemaining WRITE setTimeRemaining NOTIFY timeRemainingChanged)
    Q_PROPERTY(uint8_t countriesFound READ getCountriesFound WRITE setCountriesFound NOTIFY countriesFoundChanged)
    Q_PROPERTY(uint8_t rightAnswer READ getRightAnswer WRITE setRightAnswer NOTIFY rightAnswerChanged)
    Q_PROPERTY(uint8_t question READ getQuestion WRITE setQuestion NOTIFY questionChanged)

public:
    explicit engine(QObject *parent = nullptr);

    gameSettings* settings;
    squareJoker* square;
    continent* m_continent; // use take to remove a found country
    country* m_country;
    QString question;
    QString rightAnswer;

    uint32_t score;
    uint32_t chrono;
    uint32_t timeRemaining;
    uint8_t countriesFound;

    uint32_t getScore(void);
    uint32_t getChrono(void);
    uint32_t getTimeRemaining(void);
    uint8_t getCountriesFound(void);
    QString getRightAnswer(void);
    QString getQuestion(void);

    void setScore(uint32_t val);
    void setChrono(uint32_t val);
    void setTimeRemaining(uint32_t val);
    void setCountriesFound(uint8_t val);
    void setRightAnswer(QString val);
    void setQuestion(QString val);

    void setNewQuestion();

signals:
    void goodAnswer(uint8_t points);
    void badAnswer(uint8_t points);
    void scoreChanged();
    void chronoChanged();
    void timeRemainingChanged();
    void countriesFoundChanged();
    void rightAnswerChanged();
    void questionChanged();



public slots:
    void onGoodAnswer(uint8_t points);
    void onBadAnswer(uint8_t points);
    void onJokerAsked();
    void onButtonAnswerClicked(QString answer, uint8_t points);

private:
};

#endif // ENGINE_H
