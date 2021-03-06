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


#ifndef BIO_INITIALCONDITIONS_HPP
#define BIO_INITIALCONDITIONS_HPP


#include <cstdint>
#include <ostream>


namespace bio {


struct MutationParams;


struct InitialConditions
{
   explicit InitialConditions();
   explicit InitialConditions(
      const InitialConditions & left,
      const InitialConditions & right,
      const MutationParams & mutationParams
   );

   void applyMutations(const MutationParams & params);

   uint16_t cellLimit;
   int16_t x;
   int16_t y;
};


std::ostream & operator<<(std::ostream & os, const InitialConditions & ic);


}


#endif
