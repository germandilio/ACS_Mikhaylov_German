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
 * shape.cpp - содержит процедуры связанные с обработкой обобщенной матрицы
 * и создания подтипа матрицы
 */

#include "matrix.h"
#include "rnd.h"

// Ввод параметров обобщенной матрицы из файла
bool In(matrix &s, std::ifstream &ifst) {
    int k;
    ifst >> k;
    switch (k) {
        case 1:
            s.k = matrix::REGULARMATRIX;
            In(s.regular, ifst);
            return true;
        case 2:
            s.k = matrix::DIAGONALMATRIX;
            In(s.diagonal, ifst);
            return true;
        case 3:
            s.k = matrix::TRIANGLEMATRIX;
            In(s.triangle, ifst);
            return true;
        default:
            return false;
    }
}

// Случайный ввод обобщенной матрицы
bool InRandom(matrix &s) {
    int k = RandomDimension() - 1;
    switch (k) {
        case 1:
            s.k = matrix::REGULARMATRIX;
            InRandom(s.regular);
            return true;
        case 2:
            s.k = matrix::DIAGONALMATRIX;
            InRandom(s.diagonal);
            return true;
        case 3:
            s.k = matrix::TRIANGLEMATRIX;
            InRandom(s.triangle);
            return true;
        default:
            return false;
    }
}

// Вывод параметров текущей фигуры в поток
void Out(matrix &s, std::ofstream &ofst) {
    switch (s.k) {
        case matrix::REGULARMATRIX:
            s.k = matrix::REGULARMATRIX;
            Out(s.regular, ofst);
            break;
        case matrix::DIAGONALMATRIX:
            s.k = matrix::DIAGONALMATRIX;
            Out(s.diagonal, ofst);
            break;
        case matrix::TRIANGLEMATRIX:
            s.k = matrix::TRIANGLEMATRIX;
            Out(s.triangle, ofst);
            break;
        default:
            ofst << "Incorrect type of matrix!" << std::endl;
    }
}

// Вычисление среднего значения элементов матрицы
double Average(matrix &s) {
    switch (s.k) {
        case matrix::REGULARMATRIX:
            return Average(s.regular);
        case matrix::DIAGONALMATRIX:
            return Average(s.diagonal);
        case matrix::TRIANGLEMATRIX:
            return Average(s.triangle);
        default:
            return 0.0;
    }
}
