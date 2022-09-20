#include "sort_model.hpp"
#include "src/person_role_type.hpp"
#include "src/person.hpp"

SortModel::SortModel( QObject* _parent )
	: QSortFilterProxyModel( _parent )
{
}

bool SortModel::lessThan( QModelIndex const& _source_left, QModelIndex const& _source_right ) const
{
	if ( sortRole() == PersonRole::YearsOld )
	{
		auto person1 = sourceModel()->data( _source_left, PersonRole::Raw ).value< Person >();
		auto person2 = sourceModel()->data( _source_right, PersonRole::Raw ).value< Person >();

		int years1 = getPersonYears( person1 );
		int years2 = getPersonYears( person2 );

		if ( years1 == years2 )
		{
			return
					  ( person1.m_date.day() + person1.m_date.month() * 100 )
					< ( person2.m_date.day() + person2.m_date.month() * 100 )
					;
		}

		return years1 < years2;
	}

	return QSortFilterProxyModel::lessThan( _source_left, _source_right );
}
