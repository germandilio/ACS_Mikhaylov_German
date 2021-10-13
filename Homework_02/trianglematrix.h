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
 * trianglematrix.h - содержит описание нижнетругольной матрицы
 */

#ifndef __triangleMatrix__
#define __triangleMatrix__

#include <fstream>
#include "Matrix.h"

// Нижняя треугольная матрица
class TriangleMatrix : public Matrix {
 private:
    int _dim;
    // указатель на инкапсулированый массив
    double *_triangleMatrix;

 public:
    explicit TriangleMatrix(int length);

    // Вывод нижнетреугольной матрицы
    void out(std::ofstream &ofStream) override;

    // Ввод рандомной нижнетреугольной матрицы
    void inRandom() override;

    // Получение среднего значения элементов матрицы
    double getAverage() override;

    // Ввод нижнетреугольной матрицы
    void in(std::ifstream &ifStream) override;
};

#endif //__triangleMatrix__
