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


#include "Edge.hpp"


namespace mesh {


/***************************************************************************
 *   Edge structure implementation                                         *
 ***************************************************************************/


Edge::Edge()
   : equilibriumLength(0.0f)
{
}


Edge::Edge(dt::Float equilibriumLength)
   : equilibriumLength(equilibriumLength)
{
}


std::ostream & operator<<(std::ostream & os, const Edge & edge)
{
   os << "{" << edge.equilibriumLength << "}";
   return os;
}


}
