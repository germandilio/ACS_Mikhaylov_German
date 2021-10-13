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
 * diagonalmatrix.h - содержит описание матрицы(двумерный массив)  и его интерфейса
 */

#ifndef __regularMatrix__
#define __regularMatrix__

#include <fstream>
#include "Matrix.h"

class RegularMatrix : public Matrix {
 private:
    // указатель на инкапсулированный двумерный массив
    double **_matrix;

 public:
    explicit RegularMatrix(int length);

    // Ввод двумерной матрицы
    void in(std::ifstream &ifStream) override;

    // Случайный ввод двумерной матрицы
    void inRandom() override;

    // Вывод двумерной матрицы
    void out(std::ofstream &ofStream) override;

    // Вычисление среднего значения двумерной матрицы
    double getAverage() override;
};

#endif //__regularMatrix__