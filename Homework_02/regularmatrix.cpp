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
 * regularmatrix.cpp - declaration of in/out methods in RegularMatrix class.
 */

#include <iostream>
#include "regularmatrix.h"
#include "rnd.h"

RegularMatrix::RegularMatrix(int length) : Matrix(length) {
    matrix_ = nullptr;
}

double RegularMatrix::getAverage() {
    double sum = 0.0;

    for (int i = 0; i < length_; ++i) {
        for (int j = 0; j < length_; ++j) {
            sum += matrix_[i][j];
        }
    }
    return sum / (length_ * length_);
}


void RegularMatrix::out(std::ofstream &ofStream) {
    ofStream << "Regular matrix with dimension = " << length_ << "\n";
    for (int i = 0; i < length_; ++i) {
        for (int j = 0; j < length_; ++j) {
            ofStream << matrix_[i][j] << " ";
        }
        ofStream << "\n";
    }
    ofStream << "Average = " << this->getAverage() << "\n" << std::endl;
}

void RegularMatrix::in(std::ifstream &ifStream) {
    matrix_ = new double *[length_];

    for (int i = 0; i < length_; ++i) {
        matrix_[i] = new double[length_];
        for (int j = 0; j < length_; ++j) {
            ifStream >> matrix_[i][j];
        }
    }
}

void RegularMatrix::inRandom() {
    matrix_ = new double *[length_];

    Random random = Random(-10, 20);
    for (int i = 0; i < length_; ++i) {
        matrix_[i] = new double[length_];
        for (int j = 0; j < length_; ++j) {
            matrix_[i][j] = random.getRandom();
        }
    }
}
