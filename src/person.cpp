#include "src/person.hpp"

QString
getPersonUserFriendlyDate( Person const& _person )
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

	QString date = QString("%1 %2 %3")
			.arg( _person.m_date.day() )
			.arg( months[ _person.m_date.month() - 1 ] )
			.arg( _person.m_date.year() )
			;

	return date;
}

int
getPersonYears( Person const&_person )
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

int
getPersonDaysToBirthday( Person const& _person )
{
	QDate currentDate = QDate::currentDate();
	QDate date = _person.m_date;

	date.setDate( currentDate.year(), date.month(), date.day() );

	if ( currentDate > date )
		date = date.addYears( 1 );

	return currentDate.daysTo( date );
}
