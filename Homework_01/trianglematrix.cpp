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
 * trianglematrix.cpp - содержит функции обработки нижнетреугольной матрицы
 */

#include "trianglematrix.h"

// Ввод элементов матрицы из потока
void In(trianglematrix &triangle, std::ifstream &inputFileStream) {
    int dim;
    inputFileStream >> triangle.dimension;
    dim = triangle.dimension * (triangle.dimension + 1) / 2;
    triangle.trianglematrix = new double[dim];

    for (int i = 0; i < dim; ++i) {
        inputFileStream >> triangle.trianglematrix[i];
    }
}

// Ввод случайных значений в матрицу.
void InRandom(trianglematrix &triangle) {
    triangle.dimension = RandomDimension();
    int dim = triangle.dimension * (triangle.dimension + 1) / 2;
    triangle.trianglematrix = new double[dim];

    for (int i = 0; i < dim; ++i) {
        triangle.trianglematrix[i] = Random();
    }
}

// Вывод нижнетругольной матрицы в файловый поток.
void Out(trianglematrix &triangle, std::ofstream &outputFileStream) {
    outputFileStream << "Triangle matrix with dimension = " << triangle.dimension << "\n";
    for (int i = 0; i < triangle.dimension; ++i) {
        for (int j = 0; j < triangle.dimension; ++j) {
            if (j > i) {
                outputFileStream << 0 << " ";
            } else {
                int pos = (triangle.dimension * i) + j - ((i * (i + 1)) / 2);
                outputFileStream << triangle.trianglematrix[pos] << " ";
            }
        }
        outputFileStream << "\n";
    }
    outputFileStream << "Average = " << Average(triangle) << std::endl;
}

// Вычисление среднего значения элементов матрицы.
double Average(trianglematrix &triangle) {
    double sum = 0.0;

    for (int i = 0; i < triangle.dimension; ++i) {
        sum += triangle.trianglematrix[i];
    }
    return sum / (triangle.dimension * triangle.dimension);
}
