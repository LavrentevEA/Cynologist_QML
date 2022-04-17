#ifndef DOGLIST_H
#define DOGLIST_H

#include <QAbstractListModel>
#include <QVariant>
#include <QList>
#include <QModelIndex>
#include <QItemSelectionModel>
#include "dog.h"

class DogList : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(QAbstractListModel* dogModel READ getModel CONSTANT)  /* первый параметр - тип свойства (property)
                                                                     второй параметр - имя свойства, по которому будем обращаться к реальной модели в qml-файле
                                                                     третий параметр - метод С++ для получения значения свойства (получим саму модель)
                                                                     CONSTANT - qml получит свойство однократно, и в процессе работы это свойство изменяться не будет */
private:
    QList<Dog> listOfDogs; // непосредственно данные
    QAbstractListModel *getModel();

public:
    DogList(QObject *parent = nullptr);
    ~DogList() override;

    // количество колонок
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

     // возвращение данных модели по указанному индексу и роли
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;

    enum ResentRoles {
            name = Qt::DisplayRole,
            age = Qt::DisplayRole + 1,
            breed = Qt::DisplayRole + 2,
            owner = Qt::DisplayRole + 3,
       };

    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void add(const QString& name, const QString& age, const QString& breed, const QString& owner);  // макрос указывает, что к методу можно обратиться из QML
    Q_INVOKABLE void del(const int index);
    Q_INVOKABLE QString count(const QString& textSelArea);
    Q_INVOKABLE void edit(const QString& name, const QString& age, const QString& breed, const QString& owner, const int index);
};

#endif // DOGLIST_H
