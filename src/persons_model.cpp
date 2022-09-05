#include "persons_model.hpp"

PersonsModel::PersonsModel( QObject* _parent )
	: QAbstractListModel( _parent )
{

	auto add
		= [ this ]( QString const& _name, QString const& _date, QString const& _iconName )
		{
			Person person;
			person.m_name = _name;
			person.m_date = QDate::fromString( _date, "yyyy-MM-dd" );
			person.m_iconName = _iconName;

			m_persons.push_back( person );
		};

	add( "Dawid Świątkowski", "1986-08-03", "Dave.jpg" );
	add( "Ania Świątkowska", "1989-05-26", "Ania.jpg" );
	add( "Jadwiga Świątkowska", "1953-12-29", "Jadzia.jpg" );
	add( "Krzysztof Świątkowski", "1987-10-22", "Kris.jpg" );
	add( "Anna Świątkowski", "1989-04-03", "Ania2.jpg" );
	add( "Ines Świątkowski", "2016-06-30", "Ines.jpg" );
	add( "Kamil Świątkowski", "1994-09-03", "Kamil.jpg" );
	add( "Mateusz Kloszczyk", "1986-10-10", "Mewa.jpg" );
	add( "Kinga Kloszczyk", "1987-07-06", "Kinga.jpg" );
	add( "Michał Kloszczyk", "2018-11-10", "Michal.jpg" );
	add( "Mikołaj Kloszczyk", "1992-11-24", "Mimi.jpg" );
	add( "Weronika Kloszczyk", "1993-07-23", "Wera.jpg" );
	add( "Dorota Kloszczyk", "1962-11-25", "Dorota.jpg" );
	add( "Antoni Kloszczyk", "1955-11-20", "Antoni.jpg" );
	add( "Julia Kowalczyk", "2005-07-01", "Julia.jpg" );
	add( "Emilia Kowalczyk", "2008-01-14", "Emi.jpg" );
	add( "Michał Cogiel", "1990-10-14", "Pablo.jpg" );
	add( "Tomasz Pytel", "1993-04-27", "Pytel.jpg" );
	add( "Agnieszka Michalczuk", "1982-02-12", "Agu.jpg" );
	add( "Kinga Włodarska", "1989-10-09", "Kinia.jpg" );
	add( "Dawid Włodarski", "1989-10-30", "Dawidek.jpg" );
	add( "Alicja Jagoda", "1989-01-19", "Bob.jpg" );
	add( "Rafał Jagoda", "1990-05-24", "Jagoda.jpg" );
	add( "Lesław Jagoda", "2019-03-20", "Lesio.jpg" );
	add( "Józef Jagoda", "2021-05-07", "Jozio.jpg" );
	add( "Marcin Gajda", "1986-03-08", "Gajda.jpg" );
	add( "Monika Gajda", "1986-11-29", "Monika.jpg" );
	add( "Ania Bloch", "1989-11-29", "Samara.jpg" );
	add( "Agnieszka Stasiak", "1989-01-03", "Krain.jpg" );
	add( "Mirek Stasiak", "1982-09-05", "Miro.jpg" );
	add( "Szymon Stasiak", "2019-04-20", "Unknown.jpg" );
	add( "Marcel Stasiak", "2021-05-25", "Unknown.jpg" );
	add( "Babcia Lucy", "1920-06-30", "Lucy.jpg" );
	add( "Emilia Klimczyk", "2020-02-13", "Unknown.jpg" );
	add( "Ester Świątkowska", "2020-07-06", "Esti.jpg" );
	add( "Nero", "2020-04-01", "Nero.jpg" );
	add( "Asia Kowalik", "1987-08-20", "Asia.jpg" );
	add( "Tadzik Kloszczyk", "2022-08-30", "Unknown.jpg" );
}

int
PersonsModel::rowCount( QModelIndex const& _parent ) const
{
	Q_UNUSED( _parent )

	return m_persons.size();
}

QVariant
PersonsModel::data( QModelIndex const& _index, int _role ) const
{
	int row = _index.row();

	if ( row < 0 || row >= m_persons.size() )
		return QVariant();

	Person const& person = m_persons.at( row );

	switch( _role )
	{
		case RoleType::Name:
			return person.m_name;
		case RoleType::Birthday:
			return getPersonDate( person );
		case RoleType::Icon:
			return person.m_iconName;
	}

	return QVariant();
}


QHash< int, QByteArray >
PersonsModel::roleNames() const
{
	static QHash< int, QByteArray > roleNames = {
			  { RoleType::Name, "name" }
			, { RoleType::Birthday, "birthday" }
			, { RoleType::Icon, "icon" }
		};

	return roleNames;
}

QString
PersonsModel::getPersonDate( Person const& _person ) const
{
	const QStringList months = {
		"Styczeń"
	  , "Luty"
	  , "Marzec"
	  , "Kwiecień"
	  , "Maj"
	  , "Czerwiec"
	  , "Lipiec"
	  , "Sierpień"
	  , "Wrzesień"
	  , "Październik"
	  , "Listopad"
	  , "Grudzień"
	};

	QString date = QString("%1 %2 %3 [%4]")
			.arg( _person.m_date.day() )
			.arg( months[ _person.m_date.month() - 1 ] )
			.arg( _person.m_date.year() )
			.arg( getPersonYears( _person) )
			;

	return date;
}

int
PersonsModel::getPersonYears(const Person &_person) const
{
	QDate currentDate = QDate::currentDate();
	QDate date = _person.m_date;

	int diffrent = currentDate.year() - date.year();

	if ( currentDate.month() < date.month() )
		diffrent -= 1;
	else if ( currentDate.month() == date.month() && currentDate.day() < date.day() )
		diffrent -= 1;

	return diffrent;
}
