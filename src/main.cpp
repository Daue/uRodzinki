#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>

#include <src/persons_model.hpp>

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	QQuickStyle::setStyle("Material");

	qmlRegisterType< PersonsModel >( "org.dave", 1, 0, "PersonsModel" );

	QQmlApplicationEngine engine;
	engine.load("qrc:/qml/main.qml");

	return app.exec();
}
