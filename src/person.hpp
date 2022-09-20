#pragma once

#include <QDate>
#include <QString>

struct Person
{
	QString m_name;
	QDate m_date;
	QString m_iconName;
};

Q_DECLARE_METATYPE( Person )

QString getPersonUserFriendlyDate( Person const& _person );
int getPersonYears( Person const& _person );
int getPersonDaysToBirthday( Person const& _person );


