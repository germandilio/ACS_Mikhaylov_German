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
 * Matrix.h - содержит описание абстрактного класса матрицы.
 */

#ifndef __matrix__
#define __matrix__

#include <iosfwd>

// класс-абстракция, обобщающий все имеющиеся матрицы
class Matrix {
 protected:
    int _length;
 public:
    explicit Matrix(int length);

    virtual ~Matrix() = default;

    static Matrix *staticIn(std::ifstream &ifStream);

    static Matrix *staticInRandom();

    // Виртуальный метод ввода матрицы
    virtual void in(std::ifstream &ifStream) = 0;

    // Виртуальный метод задания рандомной матрицы
    virtual void inRandom() = 0;

    // Виртуальный метод вывода матрицы
    virtual void out(std::ofstream &ofStream) = 0;

    // Вычисление среднего значения матрицы
    virtual double getAverage() = 0;
};

#endif
