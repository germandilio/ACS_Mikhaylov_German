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
 * diagonalmatrix.h - содержит описание матрицы(двумерный массив)  и его интерфейса
 */

#ifndef __regularmatrix__
#define __regularmatrix__

#include <fstream>
# include "rnd.h"

struct regularmatrix {
    int dimension;
    double **matrix;
};

// Ввод параметров матрицы из файла
void In(regularmatrix &regular, std::ifstream &inputFileStream);

// Случайный ввод элементов матрицы
void InRandom(regularmatrix &regular);

// Вывод матрицы в форматируемый поток
void Out(regularmatrix &regular, std::ofstream &outputFileStream);

// Вычисление среднего арифметического элементов матрицы
double Average(regularmatrix &regular);


#endif //__regularmatrix__