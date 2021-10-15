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
 * Matrix.h - declaration of abstract class Matrix.
 */

#ifndef __matrix__
#define __matrix__

#include <iosfwd>

class Matrix {
 protected:
    int length_;
 public:
    explicit Matrix(int length);

    virtual ~Matrix() = default;

    static Matrix *staticIn(std::ifstream &ifStream);

    static Matrix *staticInRandom();

    virtual void in(std::ifstream &ifStream) = 0;

    virtual void inRandom() = 0;

    virtual void out(std::ofstream &ofStream) = 0;

    virtual double getAverage() = 0;
};

#endif
