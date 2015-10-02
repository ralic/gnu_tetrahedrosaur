/***************************************************************************
 *   Copyright (C) 2015 Andrey Timashov                                    *
 *                                                                         *
 *   This file is part of Tetrahedrosaur.                                  *
 *                                                                         *
 *   Tetrahedrosaur is free software: you can redistribute it and/or       *
 *   modify it under the terms of the GNU General Public License as        *
 *   published by the Free Software Foundation, either version 3 of the    *
 *   License, or (at your option) any later version.                       *
 *                                                                         *
 *   Tetrahedrosaur is distributed in the hope that it will be useful,     *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU      *
 *   General Public License for more details.                              *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with Tetrahedrosaur. If not, see <http://www.gnu.org/licenses/> *
 ***************************************************************************/


#ifndef EDGEMODEL_HPP
#define EDGEMODEL_HPP


#include <boost/optional.hpp>
#include <boost/shared_ptr.hpp>


#include "PropertyModel.hpp"


namespace bio {
class Organism;
}


/***************************************************************************
 *   EdgeModel class declaration                                           *
 ***************************************************************************/


class EdgeModel : public PropertyModel
{
   Q_OBJECT

   public:
      explicit EdgeModel(QObject * parent = 0);

      void setOrganism(boost::shared_ptr<bio::Organism> organism);

      virtual QVariant data(
         const QModelIndex & index,
         int role = Qt::DisplayRole
      ) const;
      virtual Qt::ItemFlags flags(const QModelIndex & index) const;
      virtual QModelIndex index(
         int row,
         int column,
         const QModelIndex & parent = QModelIndex()
      ) const;
      virtual QModelIndex parent(const QModelIndex & index) const;
      virtual int rowCount(const QModelIndex & parent = QModelIndex()) const;
      virtual bool setData(
         const QModelIndex & index,
         const QVariant & value,
         int role = Qt::EditRole
      );

   public slots:
      void resizeEdge(float delta);

   private:
      boost::shared_ptr<bio::Organism> m_organism;
      boost::optional<size_t> m_edge;
};


#endif
