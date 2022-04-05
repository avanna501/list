#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>
#include <QDateTime>
#include "MyClass.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    MyClass class1;
    class1.file_name="C:\\Users\\inter\\projects_a\\new_list\\list\\list.txt";

    class1.reading_();

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("currentDateTime", QDateTime::currentDateTime());
    engine.rootContext()->setContextProperty("A", &class1);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
