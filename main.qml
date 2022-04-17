import QtQuick 6.0
import QtQuick.Window 6.0
import QtQuick.Controls 6.0// это версия библиотеки, содержащей Contol (аналоги виджетов) для версии Qt 5.6
import QtQuick.Layouts 6.0

Window {
    visible: true
    width: 800
    height: 550
    title: qsTr("Каталог кинолога")

    // объявляется системная палитра
    SystemPalette {
          id: palette;
          colorGroup: SystemPalette.Active
       }

    Rectangle{
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: butAdd.top
        anchors.bottomMargin: 8
        border.color: "SteelBlue"


    ScrollView {
        anchors.fill: parent
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 15


        ListView {
            id: dogList
            anchors.fill: parent
            model: dogModel // назначение модели, данные которой отображаются списком
            delegate: DelegateForDog{}
            clip: true //
            activeFocusOnTab: true  // реагирование на перемещение между элементами ввода с помощью Tab
            focus: true  // элемент может получить фокус
        }
    }
    }

    Button {
        id: butAdd
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.rightMargin: 8
        anchors.right:butEdit.left
        text: "Добавить"
        width: 100
        onClicked: windowAdd.show()
    }

    Button {
        id: butEdit
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.right: butDel.left
        anchors.rightMargin: 8
        text: "Редактировать"
        width: 100
        onClicked: {
            var name = dogList.currentItem.dogData.name
            var age = dogList.currentItem.dogData.age
            var breed = dogList.currentItem.dogData.breed
            var owner = dogsList.currentItem.dogData.owner


            windowEdit.execute(name, age, breed, owner, dogList.currentIndex)
        }
    }

    Button {
        id: butDel
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.right:parent.right
        anchors.rightMargin: 8
        text: "Удалить"
        width: 100
        enabled: dogList.currentIndex >= 0
        onClicked: del(dogList.currentIndex)
    }

        Label {
            id: labelBreed
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 12
            anchors.left: parent.left
            anchors.rightMargin: 8
            anchors.leftMargin: 100
            Layout.alignment: Qt.AlignRight  // выравнивание по правой стороне
            text: qsTr("Введите нужную породу:")
        }
        TextField {
            id: textSelBreed
            Layout.fillWidth: true
            placeholderText: qsTr("")
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            anchors.leftMargin: 8
            anchors.left: labelBreed.right
            anchors.rightMargin: 8
        }
        Button {
            id: butCount
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 8
            anchors.left: text.right
            anchors.leftMargin: 8
            text: "Подсчитать"
            width: 100
            enabled: textSelArea.text != ""
            onClicked: windowAnswer.countBreeds(textSelBreed.text)
        }


    DialogForAdd {
        id: windowAdd
    }
    DialogForEdit {
        id: windowEdit
    }
    DialogForAnswer {
        id: windowAnswer
    }
}

