// Copyright 2021, German Mikhaylov.
//
// This file is part of Homework_02.
//
//    Homework_02 is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    Homework_02 is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with Homework_02.  If not, see <https://www.gnu.org/licenses/>.
//
//-------------------------------------------------------------------------

/**
 * rnd.h - содержит описание и реализацию методов рандома.
 */

#ifndef __rnd__
#define __rnd__

#include <cstdlib>
#include <ctime>

class Random {
 public:
    Random(double first, double last) {
        if (first <= last) {
            _first = first;
            _last = last;
        } else {
            _first = last;
            _last = first;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
    }

    // Рандомное double значение от first до last
    inline double getRandom() {
        auto range = static_cast<double>(_last - _first);
        double div = RAND_MAX / range;
        return _first + (rand() / div);
    }

    // Рандомное целое значение от 1 до 20
    static inline int getRandomDimension() {
        return rand() % 20 + 1;
    }

    static inline int getRandomType() {
        return rand() % 3 + 1;
    }

 private:
    double _first;
    double _last;
};

#endif //__rnd__
