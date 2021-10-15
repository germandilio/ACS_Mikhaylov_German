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
 * trianglematrix.cpp - declaration of in/out methods in TriangleMatrix class.
 */

#include "trianglematrix.h"
#include "rnd.h"


TriangleMatrix::TriangleMatrix(int length) : Matrix(length) {
    triangleMatrix_ = nullptr;
    dim_ = 0;
}

void TriangleMatrix::out(std::ofstream &ofStream) {
    ofStream << "Triangle matrix with dimension = " << length_ << "\n";
    for (int i = 0; i < length_; ++i) {
        for (int j = 0; j < length_; ++j) {
            if (j > i) {
                ofStream << 0 << " ";
            } else {
                int pos = (length_ * i) + j - ((i * (i + 1)) / 2);
                ofStream << triangleMatrix_[pos] << " ";
            }
        }
        ofStream << "\n";
    }
    ofStream << "Average = " << this->getAverage() << std::endl;
}

void TriangleMatrix::inRandom() {
    dim_ = length_ * (length_ + 1) / 2;
    triangleMatrix_ = new double[dim_];

    Random random = Random(-10, 20);
    for (int i = 0; i < dim_; ++i) {
        triangleMatrix_[i] = random.getRandom();
    }
}

double TriangleMatrix::getAverage() {
    double sum = 0.0;

    for (int i = 0; i < length_; ++i) {
        sum += triangleMatrix_[i];
    }
    return sum / (length_ * length_);
}

void TriangleMatrix::in(std::ifstream &ifStream) {
    dim_ = length_ * (length_ + 1) / 2;
    triangleMatrix_ = new double[dim_];

    for (int i = 0; i < dim_; ++i) {
        ifStream >> triangleMatrix_[i];
    }
}
