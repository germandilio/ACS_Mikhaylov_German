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
 * Matrix.cpp - содержит реализацию статических методов абстрактного класса Matrix
 * для создания конкретных унаследованных форм матриц
 */

#include <iostream>
#include <fstream>
#include "Matrix.h"
#include "regularmatrix.h"
#include "diagonalmatrix.h"
#include "trianglematrix.h"
#include "rnd.h"

Matrix::Matrix(int length) {
    _length = length;
}

Matrix *Matrix::staticIn(std::ifstream &ifStream) {
    int type;
    ifStream >> type;
    int length;
    ifStream >> length;
    Matrix *_matrix = nullptr;
    switch (type) {
        case 1:
            _matrix = new RegularMatrix(length);
            break;
        case 2:
            _matrix = new DiagonalMatrix(length);
            break;
        case 3:
            _matrix = new TriangleMatrix(length);
            break;
    }
    _matrix->in(ifStream);
    return _matrix;
}

Matrix *Matrix::staticInRandom() {
    int type = Random::getRandomType();
    int length = Random::getRandomDimension();

    Matrix *_matrix = nullptr;
    switch (type) {
        case 1:
            _matrix = new RegularMatrix(length);
            break;
        case 2:
            _matrix = new DiagonalMatrix(length);
            break;
        case 3:
            _matrix = new TriangleMatrix(length);
            break;
    }
    _matrix->inRandom();
    return _matrix;
}
