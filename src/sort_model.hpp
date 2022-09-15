#pragma once

#include <QSortFilterProxyModel>

class SortModel :
		public QSortFilterProxyModel
{
public:
	SortModel( QObject* _parent = nullptr );
};

