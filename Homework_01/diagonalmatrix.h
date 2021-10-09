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
 * diagonalmatrix.h - содержит описание диагональной матрицы и ее интерфейса
 */

#ifndef __diagonalmatrix__
#define __diagonalmatrix__

#include <fstream>
# include "rnd.h"

// диагональная матрица
struct diagonalmatrix {
    int dimension;
    double *diagonal;
};

// Ввод диагональной матрицы из файла
void In(diagonalmatrix &diagonal, std::ifstream &inputFileStream);

// Случайный ввод диагональной матрицы
void InRandom(diagonalmatrix &diagonal);

// Вывод диагональной матрицы в форматируемый поток
void Out(diagonalmatrix &diagonal, std::ofstream &outputFileStream);

// Вычисление среднего арифметического элементов диагональной матрицы
double Average(diagonalmatrix &diagonal);

#endif //__diagonalmatrix__
