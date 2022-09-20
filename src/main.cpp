#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QQmlContext>

#include <src/persons_model.hpp>
#include <src/sort_model.hpp>
#include <src/person.hpp>

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	QQuickStyle::setStyle("Material");

	PersonsModel model;

	SortModel sortModel;
	sortModel.setSourceModel( &model );
	sortModel.setSortRole( PersonRole::DaysToBirthday );
	sortModel.sort( 0 );

	//qmlRegisterType< PersonsModel >( "org.dave", 1, 0, "PersonsModel" );
	qmlRegisterType< PersonRole >("person", 1,0, "PersonRole" );

	QQmlApplicationEngine engine;
	engine.rootContext()->setContextProperty( "personsModel", &sortModel );
	engine.load("qrc:/qml/main.qml");

	return app.exec();
}
