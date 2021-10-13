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
 * Container.h - содержит тип данных, представляющий простейший контейнер
 */

#ifndef __container__
#define __container__
#define MAX_LENGTH 10000

#include "Matrix.h"

// Контейнер на основе одномерного массива
class Container {
 private:
    int _length;
    Matrix *_container[MAX_LENGTH];

 public:
    // Конструктор контейнера
    Container();

    // Деструктор контейнера от элементов (освобождение памяти)
    ~Container();

    // Ввод содержимого контейнера из указанного потока
    void in(std::ifstream &ifStream);

    // Случайный ввод содержимого контейнера
    void inRandom(int size);

    // Вывод содержимого контейнера в указанный поток
    void out(std::ofstream &ofStream);

    // Удаление элементов в контейнере, если ср. арифметическое < ср. ар. всего контейнера
    void removeByAverage();
};

#endif
