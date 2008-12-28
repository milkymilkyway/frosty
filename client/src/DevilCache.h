/******************************************************************************\
*  client/src/DevilCache.h                                                     *
*  Copyright (C) 2008 John Eric Martin <john.eric.martin@gmail.com>            *
*                                                                              *
*  This program is free software; you can redistribute it and/or modify        *
*  it under the terms of the GNU General Public License version 2 as           *
*  published by the Free Software Foundation.                                  *
*                                                                              *
*  This program is distributed in the hope that it will be useful,             *
*  but WITHOUT ANY WARRANTY; without even the implied warranty of              *
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               *
*  GNU General Public License for more details.                                *
*                                                                              *
*  You should have received a copy of the GNU General Public License           *
*  along with this program; if not, write to the                               *
*  Free Software Foundation, Inc.,                                             *
*  59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.                   *
\******************************************************************************/

#ifndef __DevilCache_h__
#define __DevilCache_h__

#include <QtCore/QVariantMap>
#include <QtCore/QObject>
#include <QtCore/QHash>

class DevilCache : public QObject
{
	Q_OBJECT

public:
	static DevilCache* getSingletonPtr();

	QVariantMap devilByID(int id) const;

	QString generateToolTip(const QVariantMap& mix_data) const;

signals:
	void cacheReady();

public slots:
	void fillCache();

protected slots:
	void ajaxResponse(const QVariant& resp);

protected:
	DevilCache(QObject *parent = 0);

	bool mCacheFull;

	QHash<int, QVariantMap> mSkills;
	QHash<int, QVariantMap> mTraits;
	QHash<int, QVariantMap> mDevils;

	QHash< QString, QList<QVariantMap> > mDevilsByGenus;
};

#endif // __DevilCache_h__
