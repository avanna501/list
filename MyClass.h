#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QString>
#include <QList>
#include <QFile>
#include <QDebug>
#include <QVariantMap>
#include <QVector>

class MyClass : public QObject
{
    Q_OBJECT
    //    Q_PROPERTY(type name READ name WRITE setName NOTIFY nameChanged)

public:
//    MyClass(QObject *parent = nullptr) : QObject(parent) {}
//    virtual ~MyClass() {};

    Q_INVOKABLE QVector<QVariantMap> reading_()
    {
                int i;
        QString line;
        QFile file(file_name);
        QVector<QVariantMap> list;

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
        qDebug() << "MY Class read";

        while(!file.atEnd())
        {
            QVariantMap m;
            line = file.readLine();
            QStringList stringList=line.split(QLatin1Char(' '));

            m.insert("name", line.mid(0, line.toStdString().find(" ")));
            line=line.mid(line.toStdString().find(" ")+1);

            m.insert("id", line.mid(0, line.toStdString().find(" ")));
            line=line.mid(line.toStdString().find(" ")+1);

            m.insert("surname", line);
//            .mid(0, line.toStdString().find(" "))
//            line=line.mid(line.toStdString().find(" ")+1);

            list.push_back(m);

            qDebug()<<m;
            qDebug()<<stringList;


        } ;

        for(i=0;i<5;i++)
            qDebug()<<list[i]["name"];
        return list;
    }

    QString  file_name;
};



#endif // MYCLASS_H
