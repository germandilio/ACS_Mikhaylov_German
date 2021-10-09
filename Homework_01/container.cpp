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
 * container.cpp - содержит функции обработки контейнера
 */

#include "container.h"

// Инициализация контейнера
void Init(container &c) {
    c.len = 0;
}

// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c) {
    c.len = 0;
}

// Ввод содержимого контейнера из указанного потока
void In(container &c, std::ifstream &ifst) {
    while (!ifst.eof()) {
        if (In(c.container[c.len], ifst)) {
            c.len++;
        }
    }
}

// Случайный ввод содержимого контейнера
void InRandom(container &c, int size) {
    while (c.len < size) {
        if (InRandom(c.container[c.len])) {
            c.len++;
        }
    }
}

// Вывод содержимого контейнера в указанный поток
void Out(container &c, std::ofstream &ofst) {
    ofst << "Container contains " << c.len << " elements.\n" << std::endl;
    for (int i = 0; i < c.len; i++) {
        ofst << i << ": ";
        Out(c.container[i], ofst);
    }
}

// Функция удаления матриц, если ср. арифметическое элементов меньше среднего в контейнере
void RemoveByAverage(container &c) {
    double sum = 0.0;
    for (int i = 0; i < c.len; ++i) {
        sum += Average(c.container[i]);
    }
    double containerAverage = sum / c.len;

    matrix containerAfterDelete[c.len];
    int pointer = 0;
    for (int i = 0; i < c.len; ++i) {
        if (Average(c.container[i]) >= containerAverage) {
            containerAfterDelete[pointer] = c.container[i];
            ++pointer;
        }
    }
    c.len = pointer;

    for (int i = 0; i < c.len; ++i) {
        c.container[i] = containerAfterDelete[i];
    }
}
