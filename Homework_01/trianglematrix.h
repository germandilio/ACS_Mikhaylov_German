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
 * trianglematrix.h - содержит описание нижнетругольной матрицы
 */

#ifndef __trianglematrix__
#define __trianglematrix__

#include <fstream>
# include "rnd.h"

// Нижняя треугольная матрица
struct trianglematrix {
    int dimension;
    double *trianglematrix;
};

// Ввод элементов треугольной матрицы из файла
void In(trianglematrix &triangle, std::ifstream &inputFileStream);

// Случайный ввод элементов треугольной матрицы из файла
void InRandom(trianglematrix &triangle);

// Вывод элементов треугольной матрицы в файл
void Out(trianglematrix &triangle, std::ofstream &outputFileStream);

// Вычисление среднего значения
double Average(trianglematrix &triangle);

#endif //__trianglematrix__
