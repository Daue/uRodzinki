#pragma once

#include <QAbstractListModel>
#include <QVector>
#include <QDate>

struct Person
{
	QString m_name;
	QDate m_date;
	QString m_iconName;
};

enum RoleType
{
	  Name = Qt::UserRole
	, Birthday = Qt::UserRole + 1
	, Icon = Qt::UserRole + 2
};

class PersonsModel
		: public QAbstractListModel
{
	Q_OBJECT

public:
	PersonsModel( QObject* _parent = nullptr );

	int rowCount( QModelIndex const& _parent ) const override;
	QVariant data( QModelIndex const& _index, int _role) const override;
	QHash< int, QByteArray > roleNames() const override;

private:
	QString getPersonDate( Person const& _person ) const;
	int getPersonYears( Person const& _person ) const;

private:
	QVector< Person > m_persons;
};

