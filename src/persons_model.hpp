#pragma once

#include <QAbstractListModel>
#include <QVector>
#include <QDate>

#include "src/person_role_type.hpp"
#include "src/person.hpp"

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
	QVector< Person > m_persons;
};

