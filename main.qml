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
        id: element
        x: 579
        y: 0
        width: 61
        height: 15
        text: qsTr("Best Score")
        font.pixelSize: 12
    }

    Text {
        id: element1
        x: 308
        y: 0
        text: qsTr("Score")
        font.pixelSize: 12
    }

    Text {
        id: element2
        x: 0
        y: 0
        text: myEngine.chrono
        font.pixelSize: 12
    }

    TextInput {
        id: textInput
        x: 210
        y: 158
        width: 226
        height: 20
        text: "Capitale"
        font.pixelSize: 12
    }

    Text {
        id: element3
        x: 291
        y: 124
        text: qsTr("Pays")
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: 12
    }

    Button {
        id: button
        x: 248
        y: 252
        width: 150
        height: 32
        text: qsTr("Valider")
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Text {
        id: element4
        x: 297
        y: 358
        width: 206
        height: 77
        text: qsTr("Text")
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: 12
    }

    Button {
        id: button1
        x: 463
        y: 124
        width: 147
        height: 27
        text: qsTr("Carré")
    }

    Text {
        id: element5
        x: 463
        y: 163
        width: 147
        height: 24
        text: qsTr("Propositions carré")
        font.pixelSize: 12
    }

    Text {
        id: element6
        x: 548
        y: 15
        text: qsTr("bestscoreafficher")
        font.pixelSize: 12
    }

    Text {
        id: element7
        x: 287
        y: 15
        text: myEngine.score
        font.pixelSize: 12
    }
}
