#pragma once

#include <QObject>

class PersonRole
		: public QObject
{

	Q_OBJECT

public:
	enum Type
	{
		  Name = Qt::UserRole
		, Birthday = Qt::UserRole + 1
		, Icon = Qt::UserRole + 2
		, YearsOld = Qt::UserRole + 3
		, Raw = Qt::UserRole + 4
		, DaysToBirthday = Qt::UserRole + 5
	};
	Q_ENUM( Type )
};


