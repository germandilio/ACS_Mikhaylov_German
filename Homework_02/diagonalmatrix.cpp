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
 * diagonalmatrix.cpp - содержит реализацию методов класса DiagonalMatrix.
 */

#include "diagonalmatrix.h"
#include "rnd.h"
#include <iostream>
#include <fstream>

DiagonalMatrix::DiagonalMatrix(int length) : Matrix(length) {
    _diagonal = nullptr;
}

void DiagonalMatrix::out(std::ofstream &ofStream) {
    ofStream << "Diagonal matrix with dimension = " << _length << "\n";
    for (int i = 0; i < _length; ++i) {
        for (int j = 0; j < _length; ++j) {
            if (i == j) {
                ofStream << _diagonal[i] << " ";
            } else {
                ofStream << 0 << " ";
            }
        }
        ofStream << "\n";
    }
    ofStream << "Average = " << this->getAverage() << "\n" << std::endl;
}

double DiagonalMatrix::getAverage() {
    double sum = 0.0;

    for (int i = 0; i < _length; ++i) {
        sum += _diagonal[i];
    }
    return sum / (_length * _length);
}

void DiagonalMatrix::in(std::ifstream &ifStream) {
    _diagonal = new double[_length];

    for (int i = 0; i < _length; ++i) {
        ifStream >> _diagonal[i];
    }
}

void DiagonalMatrix::inRandom() {
    _diagonal = new double[_length];

    Random random = Random(-10, 20);
    for (int i = 0; i < _length; ++i) {
        _diagonal[i] = random.getRandom();
    }
}
