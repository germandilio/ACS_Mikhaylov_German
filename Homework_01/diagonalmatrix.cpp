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
 * diagonalmatrix.cpp - содержит процедуру ввода, вывода параметров
 * для диагональной матрицы
 */

#include "diagonalmatrix.h"

// Ввод диагональной матрицы из файла
void In(diagonalmatrix &diagonal, std::ifstream &inputFileStream) {
    inputFileStream >> diagonal.dimension;
    diagonal.diagonal = new double[diagonal.dimension];

    for (int i = 0; i < diagonal.dimension; ++i) {
        inputFileStream >> diagonal.diagonal[i];
    }
}

// Случайный ввод диагональной матрицы
void InRandom(diagonalmatrix &diagonal) {
    diagonal.dimension = RandomDimension();
    diagonal.diagonal = new double[diagonal.dimension];

    for (int i = 0; i < diagonal.dimension; ++i) {
        diagonal.diagonal[i] = Random();
    }
}


// Вывод диагональной матрицы в форматируемый поток
void Out(diagonalmatrix &diagonal, std::ofstream &outputFileStream) {
    outputFileStream << "Diagonal matrix with dimension = " << diagonal.dimension << "\n";
    for (int i = 0; i < diagonal.dimension; ++i) {
        for (int j = 0; j < diagonal.dimension; ++j) {
            if (i == j) {
                outputFileStream << diagonal.diagonal[i] << " ";
            } else {
                outputFileStream << 0 << " ";
            }
        }
        outputFileStream << "\n";
    }
    outputFileStream << "Average = " << Average(diagonal) << "\n" << std::endl;
}


// Вычисление среднего арифметического элементов диагональной матрицы
double Average(diagonalmatrix &diagonal) {
    double sum = 0.0;

    for (int i = 0; i < diagonal.dimension; ++i) {
        sum += diagonal.diagonal[i];
    }
    return sum / (diagonal.dimension * diagonal.dimension);
}
