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
 * regularmatrix.cpp - содержит процедуры для ввода, вывода обычной матрицы.
 */

#include "regularmatrix.h"

// Ввод параметров матрицы из файла
void In(regularmatrix &regular, std::ifstream &inputFileStream) {
    inputFileStream >> regular.dimension;
    regular.matrix = new double *[regular.dimension];

    for (int i = 0; i < regular.dimension; ++i) {
        regular.matrix[i] = new double[regular.dimension];
        for (int j = 0; j < regular.dimension; ++j) {
            inputFileStream >> regular.matrix[i][j];
        }
    }
}

// Случайный ввод элементов матрицы
void InRandom(regularmatrix &regular) {
    regular.dimension = RandomDimension();
    regular.matrix = new double *[regular.dimension];

    for (int i = 0; i < regular.dimension; ++i) {
        regular.matrix[i] = new double[regular.dimension];
        for (int j = 0; j < regular.dimension; ++j) {
            regular.matrix[i][j] = Random();
        }
    }
}

// Вывод матрицы в форматируемый поток
void Out(regularmatrix &regular, std::ofstream &outputFileStream) {
    outputFileStream << "Regular matrix with dimension = " << regular.dimension << "\n";
    for (int i = 0; i < regular.dimension; ++i) {
        for (int j = 0; j < regular.dimension; ++j) {
            outputFileStream << regular.matrix[i][j] << " ";
        }
        outputFileStream << "\n";
    }
    outputFileStream << "Average = " << Average(regular) << "\n" << std::endl;
}

// Вычисление среднего арифметического элементов матрицы
double Average(regularmatrix &regular) {
    double sum = 0.0;

    for (int i = 0; i < regular.dimension; ++i) {
        for (int j = 0; j < regular.dimension; ++j) {
            sum += regular.matrix[i][j];
        }
    }
    return sum / (regular.dimension * regular.dimension);
}
