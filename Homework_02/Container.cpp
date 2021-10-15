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
 * container.cpp - functions of input, output and removing by average
 */

#include <iostream>
#include <fstream>
#include "Container.h"
#include "Matrix.h"

Container::Container() : length_(0) {}

Container::~Container() {
    for (int i = 0; i < length_; ++i) {
        delete container_[i];
    }
    length_ = 0;
}

void Container::in(std::ifstream &ifStream) {
    while (!ifStream.eof()) {
        if ((container_[length_] = Matrix::staticIn(ifStream)) != nullptr) {
            ++length_;
        }
    }
}

void Container::inRandom(int size) {
    while (length_ < size) {
        if ((container_[length_] = Matrix::staticInRandom()) != nullptr) {
            length_++;
        }
    }
}

void Container::out(std::ofstream &ofStream) {
    ofStream << "Container contains " << length_ << " elements.\n" << std::endl;
    for (int i = 0; i < length_; i++) {
        ofStream << i << ": ";
        container_[i]->out(ofStream);
    }
}

void Container::removeByAverage() {
    double sum = 0.0;
    for (int i = 0; i < length_; ++i) {
        sum += container_[i]->getAverage();
    }
    double containerAverage = sum / length_;

    Matrix *containerAfterDelete[length_];
    int pointer = 0;
    for (int i = 0; i < length_; ++i) {
        if (container_[i]->getAverage() >= containerAverage) {
            containerAfterDelete[pointer] = container_[i];
            ++pointer;
        }
    }
    length_ = pointer;

    for (int i = 0; i < length_; ++i) {
        container_[i] = containerAfterDelete[i];
    }
}

