#include "doglist.h"
#include <QDebug>
#include <QMessageBox>
#include <QWidget>
#include <QApplication>
#include <QString>

DogList::DogList(QObject* parent):QAbstractListModel(parent)
{
    add("Клем", "3", "Сенбернар", "Петров И.В.");
    add("Арес", "2", "Немецкая овчарка", "Карандашова Т.В.");
    add("Кэйт", "8", "Корги", "Иванов С.С.");
}

DogList::~DogList()
{

}

int DogList::rowCount(const QModelIndex&) const
{
    return listOfDogs.size();
}


QVariant DogList::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= listOfDogs.size())
            return QVariant();
      {
        switch (role) {
                case name:
                    return QVariant(listOfDogs.at(index.row()).getName());
                case age:
                    return QVariant(listOfDogs.at(index.row()).getAge());
                case breed:
                    return QVariant(listOfDogs.at(index.row()).getBreed());
                case owner:
                    return QVariant(listOfDogs.at(index.row()).getOwner());

                default:
                    return QVariant();
            }

    }
}

QHash<int, QByteArray> DogList::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[name] = "name";
    roles[age] = "age";
    roles[breed] = "breed";
    roles[owner] = "owner";
       return roles;
}

void DogList::add(const QString& name, const QString& age, const QString& breed, const QString& owner){
     Dog dog;
     dog.setName(name);
     dog.setAge(age);
     dog.setBreed(breed);
     dog.setOwner(owner);

    beginInsertRows(QModelIndex(),listOfDogs.size(),listOfDogs.size());
    listOfDogs.append(dog);  //добавление в конец списка
    endInsertRows();

}

QAbstractListModel* DogList::getModel(){
    return this;
}

void DogList::del(const int index){

     if (index >= 0 && index < listOfDogs.size())
     {

    // сообщение модели о процессе удаления данных
         beginRemoveRows(QModelIndex(), index, index);
        listOfDogs.removeAt(index);
              endRemoveRows();
     }
     else qDebug() << "Error index";

}

QString DogList::count(const QString& textSelBreed){
    int count = 0;
    for(int i = 0; i < listOfDogs.size(); i++)
        if(listOfDogs[i].getBreed().compare(textSelBreed, Qt::CaseInsensitive)==0)
            count++;
    QString c = QString::number(count);
    return c;
}

void DogList::edit(const QString& name, const QString& age, const QString& breed, const QString& owner, const int index) {
     if(index >= 0 && index < listOfDogs.size() )
     {
        auto& currentDog = listOfDogs[index];
        if (currentDog.getName().compare(name)!=0 || currentDog.getAge() != age || currentDog.getBreed() != breed
                || currentDog.getOwner() != owner)
        {
            currentDog.setName(name);
            currentDog.setAge(age);
            currentDog.setBreed(breed);
            currentDog.setOwner(owner);

            auto modelIndex = createIndex(index, 0);
            emit dataChanged(modelIndex, modelIndex);
            qDebug() << listOfDogs[index].getOwner();
        }

     }
      else qDebug() << "Error index";
}
