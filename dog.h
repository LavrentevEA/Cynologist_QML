#ifndef DOG_H
#define DOG_H

#include "QString"


class Dog /*public QObject*/
{
    //Q_OBJECT

public:
    Dog(/*QString ID, QString Name, QString Age, QString Breed, QString Owner QObject *parent = nullptr */);
    virtual ~Dog();
    void setID(const QString ID);
    void setName(const QString Name);
    void setAge(const QString Age);
    void setBreed(const QString Breed);
    void setOwner(const QString Owner);

    QString getID() const;
    QString getName() const;
    QString getAge() const;
    QString getBreed() const;
    QString getOwner() const;

private:
    QString id;
    QString name; //имя собаки
    QString age; //возраст
    QString breed; //порода
    QString owner; //ФИО владельца

};
#endif // DOG_H
