#pragma once

#include <QSortFilterProxyModel>

class SortModel :
		public QSortFilterProxyModel
{

public:
	SortModel( QObject* _parent = nullptr );

protected:
	bool lessThan( QModelIndex const& _source_left, QModelIndex const& _source_right ) const override;
};

