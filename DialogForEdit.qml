import QtQuick 6.0
import QtQuick.Window 6.0
import QtQuick.Controls 6.0 // это версия библиотеки, содержащей Contol (аналоги виджетов) для версии Qt 5.6
import QtQuick.Layouts 6.0


Window {
    id: root
    modality: Qt.ApplicationModal  // окно объявляется модальным
    title: qsTr("Редактирование информации о собаке")
    minimumWidth: 400
    maximumWidth: 400
    minimumHeight: 200
    maximumHeight: 200

    property int currentIndex: -1

    GridLayout {
        anchors { left: parent.left; top: parent.top; right: parent.right; bottom: buttonCancel.top; margins: 10 }
        columns: 2

        Label {
            Layout.alignment: Qt.AlignRight  // выравнивание по правой стороне
            text: qsTr("Имя собаки:")
        }
        TextField {
            id: textName
            Layout.fillWidth: true
            placeholderText: qsTr("Введите имя")
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Возраст:")
        }
        TextField {
            id: textAge
            Layout.fillWidth: true
            placeholderText: qsTr("Введите возраст")
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Порода:")
        }
        TextField {
            id: textBreed
            Layout.fillWidth: true
            placeholderText: qsTr("Введите породу")
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("ФИО владельца:")
        }
        TextField {
            id: textOwner
            Layout.fillWidth: true
            placeholderText: qsTr("Введите ФИО владельца")
        }

    }
    Button {
        visible: {textName.length>0 && textAge.length>0 && root.currentIndex <0}
        anchors { right: buttonCancel.left; verticalCenter: buttonCancel.verticalCenter; rightMargin: 10 }
        text: qsTr("Добавить в список")
        width: 100
        onClicked: {
            root.hide()
            add(textName.text, textAge.text, textBreed.text, textOwner.text)
        }
    }
    Button {
        visible: {root.currentIndex>=0}
        anchors { right: buttonCancel.left; verticalCenter: buttonCancel.verticalCenter; rightMargin: 10 }
        text: qsTr("Применить")
        width: 100
        onClicked: {
            root.hide()
            edit(textName.text, textAge.text, textBreed.text, textOwner.text, root.currentIndex)
        }
    }
    Button {
        id: buttonCancel
        anchors { right: parent.right; bottom: parent.bottom; rightMargin: 10; bottomMargin: 10 }
        text: qsTr("Отменить")
        width: 100
        onClicked: {
             root.hide()
        }
    }


    function execute(name, age, breed, owner, index){
        textName.text = name
        textAge.text = age
        textBreed.text = breed
        textOwner.text = owner
        root.currentIndex = index

        root.show()
    }
 }
