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
 * container.cpp - содержит функции обработки контейнера
 */

#include <iostream>
#include <fstream>
#include "Container.h"
#include "Matrix.h"

Container::Container() : _length(0) {}

Container::~Container() {
    for (int i = 0; i < _length; ++i) {
        delete _container[i];
    }
    _length = 0;
}

void Container::in(std::ifstream &ifStream) {
    while (!ifStream.eof()) {
        if ((_container[_length] = Matrix::staticIn(ifStream)) != nullptr) {
            ++_length;
        }
    }
}

void Container::inRandom(int size) {
    while (_length < size) {
        if ((_container[_length] = Matrix::staticInRandom()) != nullptr) {
            _length++;
        }
    }
}

void Container::out(std::ofstream &ofStream) {
    ofStream << "Container contains " << _length << " elements.\n" << std::endl;
    for (int i = 0; i < _length; i++) {
        ofStream << i << ": ";
        _container[i]->out(ofStream);
    }
}

void Container::removeByAverage() {
    double sum = 0.0;
    for (int i = 0; i < _length; ++i) {
        sum += _container[i]->getAverage();
    }
    double containerAverage = sum / _length;

    Matrix *containerAfterDelete[_length];
    int pointer = 0;
    for (int i = 0; i < _length; ++i) {
        if (_container[i]->getAverage() >= containerAverage) {
            containerAfterDelete[pointer] = _container[i];
            ++pointer;
        }
    }
    _length = pointer;

    for (int i = 0; i < _length; ++i) {
        _container[i] = containerAfterDelete[i];
    }
}

