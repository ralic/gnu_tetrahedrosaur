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


#ifndef CELLMODEL_HPP
#define CELLMODEL_HPP


#include <boost/optional.hpp>
#include <boost/shared_ptr.hpp>


#include "mesh/Tetrahedron.hpp"
#include "PropertyModel.hpp"


namespace bio {
class Organism;
}


/***************************************************************************
 *   CellModel class declaration                                           *
 ***************************************************************************/


class CellModel : public PropertyModel
{
   public:
      explicit CellModel(QObject * parent = 0);

      void setOrganism(boost::shared_ptr<bio::Organism> organism);

      virtual bool rootIsDecorated() const;

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

   private:
      boost::shared_ptr<bio::Organism> m_organism;
      boost::optional<mesh::Tetrahedron> m_tetrahedron;
      mutable char m_mesh;
};


#endif
