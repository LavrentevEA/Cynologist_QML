#include "dog.h"

Dog::Dog(/*QString ID, QString Name, QString Age, QString Breed, QString Owner, QObject *parent): QObject(parent*/)
{
    /*id = ID;
    name = Name;
    age = Age;
    breed = Breed;
    owner = Owner;*/
}

void Dog::setID(const QString ID)
{
    id = ID;
}
void Dog::setName(const QString Name)
{
    name = Name;
}
void Dog::setAge(const QString Age)
{
    age = Age;
}
void Dog::setBreed(const QString Breed)
{
    breed = Breed;
}
void Dog::setOwner(const QString Owner)
{
    owner = Owner;
}

QString Dog::getID() const
{
    return id;
}
QString Dog::getName() const
{
    return name;
}
QString Dog::getAge() const
{
    return age;
}
QString Dog::getBreed() const
{
    return breed;
}
QString Dog::getOwner() const
{
    return owner;
}

 Dog::~Dog()
{
}
