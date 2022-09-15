#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QQmlContext>

#include <src/persons_model.hpp>
#include <src/sort_model.hpp>

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	QQuickStyle::setStyle("Material");

	PersonsModel model;

	SortModel sortModel;
	//sortModel.setDynamicSortFilter( true );
	//sortModel.setFilterRole( RoleType::Name );
	//sortModel.setFilterFixedString( "Jagoda" );
	sortModel.setSourceModel( &model );

	//qmlRegisterType< PersonsModel >( "org.dave", 1, 0, "PersonsModel" );

	QQmlApplicationEngine engine;
	engine.rootContext()->setContextProperty( "personsModel", &sortModel );
	engine.load("qrc:/qml/main.qml");

	return app.exec();
}
