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
 * trianglematrix.cpp - содержит реализацию процедур для ввода, вывода нижнетреугольной матрицы.
 */

#include "trianglematrix.h"
#include "rnd.h"


TriangleMatrix::TriangleMatrix(int length) : Matrix(length) {
    _triangleMatrix = nullptr;
    _dim = 0;
}

void TriangleMatrix::out(std::ofstream &ofStream) {
    ofStream << "Triangle matrix with dimension = " << _length << "\n";
    for (int i = 0; i < _length; ++i) {
        for (int j = 0; j < _length; ++j) {
            if (j > i) {
                ofStream << 0 << " ";
            } else {
                int pos = (_length * i) + j - ((i * (i + 1)) / 2);
                ofStream << _triangleMatrix[pos] << " ";
            }
        }
        ofStream << "\n";
    }
    ofStream << "Average = " << this->getAverage() << std::endl;
}

void TriangleMatrix::inRandom() {
    _dim = _length * (_length + 1) / 2;
    _triangleMatrix = new double[_dim];

    Random random = Random(-10, 20);
    for (int i = 0; i < _dim; ++i) {
        _triangleMatrix[i] = random.getRandom();
    }
}

double TriangleMatrix::getAverage() {
    double sum = 0.0;

    for (int i = 0; i < _length; ++i) {
        sum += _triangleMatrix[i];
    }
    return sum / (_length * _length);
}

void TriangleMatrix::in(std::ifstream &ifStream) {
    _dim = _length * (_length + 1) / 2;
    _triangleMatrix = new double[_dim];

    for (int i = 0; i < _dim; ++i) {
        ifStream >> _triangleMatrix[i];
    }
}
