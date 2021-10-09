// Copyright 2021, German Mikhaylov.
//
// This file is part of Homework_01.
//
//    Homework_01 is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    Homework_01 is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with Homework_01.  If not, see <https://www.gnu.org/licenses/>.
//
//-------------------------------------------------------------------------

/**
 * rnd.h - содержит генератор случайных чисел
 */

#ifndef __rnd__
#define __rnd__

#include <cstdlib>

// Рандомное double значение от -10 до 20
inline double Random() {
    double const min = -10.0;
    double const max = 20.0;

    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

// Рандомное целое значение от 1 до 20
inline int RandomDimension() {
    return rand() % 20 + 1;
}

#endif //__rnd__
