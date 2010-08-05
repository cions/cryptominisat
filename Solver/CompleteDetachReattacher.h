/**************************************************************************
CryptoMiniSat -- Copyright (c) 2009 Mate Soos

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

#include "Solver.h"

class CompleteDetachReatacher
{
    public:
        CompleteDetachReatacher(Solver& solver);
        const bool completelyReattach();
        void completelyDetach();
        void detachPointerUsingClauses();

    private:
        void clearWatchOfPointerUsers(vec<Watched>& ws);

        void cleanAndAttachClauses(vec<Clause*>& cs, const bool lookingThroughBinary);
        void cleanAndAttachClauses(vec<XorClause*>& cs);
        const bool cleanClause(Clause*& ps);
        const bool cleanClause(XorClause& ps);
        
        Solver& solver;
};