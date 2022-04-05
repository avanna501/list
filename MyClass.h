#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QString>
#include <QList>
#include <QFile>
#include <QDebug>

class MyClass : public QObject
{
    Q_OBJECT
    //    Q_PROPERTY(type name READ name WRITE setName NOTIFY nameChanged)

public:
//    MyClass(QObject *parent = nullptr) : QObject(parent) {}
//    virtual ~MyClass() {};

    Q_INVOKABLE QList<QString> reading_()
    {
        QString line;
        QFile file(file_name);
        QList<QString> list={};

        if (!file.exists())
        {
            qDebug()<<"file not found";
            return list;

        }
        if (!file.open(QIODevice::OpenModeFlag::ReadOnly))
        {
            qDebug()<<"couldn't open the file";
            return list;
        };

        while(!file.atEnd())
        {
            line = file.readLine();
            list.append(line);


            qDebug() << "MY Class read";
            qDebug()<<line<<list.last();
        } ;

        return list;
    }
    QString  file_name;
};



#endif // MYCLASS_H
