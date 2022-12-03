import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.6

import Engine 1.0

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Engine {
        id: myEngine
    }

    Text {
        id: textBestScore
        x: 579
        y: 0
        width: 61
        height: 15
        text: qsTr("Best Score")
        font.pixelSize: 12
    }

    Text {
        id: textScore
        x: 308
        y: 0
        text: qsTr("Score")
        font.pixelSize: 12
    }

    Text {
        id: textChrono
        x: 0
        y: 0
        text: myEngine.chrono
        font.pixelSize: 12
    }

    Text {
        id: textQuestion
        x: 291
        y: 97
        text: myEngine.question
        anchors.horizontalCenterOffset: 3
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: 20
    }

    Button {
        id: buttonValidate
        x: 248
        y: 252
        width: 150
        height: 32
        text: qsTr("Valider")
        onClicked: myEngine.onButtonAnswerClicked(textFieldAnswer.text, 1)
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Button {
        id: buttonSquare
        x: 15
        y: 322
        width: 147
        height: 27
        onClicked: myEngine.onJokerAsked()
        text: qsTr("Carré")
    }

    Text {
        id: textPropositions
        x: 15
        y: 348
        width: 113
        height: 24
        text: qsTr("Propositions carré")
        font.pixelSize: 12
        visible: myEngine.squareJokerActivated
    }

    Text {
        id: textBestScoreDisplay
        x: 548
        y: 15
        text: myEngine.bestScore
        font.pixelSize: 12
    }

    Text {
        id: textScoreDisplay
        x: 287
        y: 15
        text: myEngine.score
        font.pixelSize: 12
    }

    Text {
        id: textRightAnswer
        x: 314
        y: 132
        text: myEngine.rightAnswer
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: 20
        visible: myEngine.visibleRightAnswer
    }

    TextField {
        id: textFieldAnswer
        x: 199
        y: 176
        width: 248
        height: 25
        text: "entrer une réponse"
        placeholderText: qsTr("Text Field")
    }
}
