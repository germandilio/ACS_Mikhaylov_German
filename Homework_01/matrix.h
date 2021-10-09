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
 * matrix.h - содержит описание обобщенной матрицы.
 */

#ifndef __matrix__
#define __matrix__

#include "diagonalmatrix.h"
#include "trianglematrix.h"
#include "regularmatrix.h"

// структура, обобщающая все имеющиеся матрицы
struct matrix {
    // значения ключей для каждой из матриц
    enum key {
        REGULARMATRIX, DIAGONALMATRIX, TRIANGLEMATRIX
    };
    // ключ
    key k;
    union {
        regularmatrix regular;
        diagonalmatrix diagonal;
        trianglematrix triangle;
    };
};

// Ввод обобщенной матрицы
bool In(matrix &s, std::ifstream &ifdt);

// Случайный ввод обобщенной матрицы
bool InRandom(matrix &s);

// Вывод обобщенной матрицы
void Out(matrix &s, std::ofstream &ofst);

// Вычисление среднего значения обобщенной матрицы
double Average(matrix &s);

#endif
