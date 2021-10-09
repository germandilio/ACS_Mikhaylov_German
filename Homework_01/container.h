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
 * container.h - содержит тип данных, представляющий простейший контейнер
 */

#ifndef __container__
#define __container__

#include "matrix.h"

// Простейший контейнер на основе одномерного массива
struct container {
    enum {
        max_len = 10000
    };
    // текущая длина
    int len;
    matrix container[max_len];
};

// Инициализация контейнера
void Init(container &c);

// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c);

// Ввод содержимого контейнера из указанного потока
void In(container &c, std::ifstream &ifst);

// Случайный ввод содержимого контейнера
void InRandom(container &c, int size);

// Вывод содержимого контейнера в указанный поток
void Out(container &c, std::ofstream &ofst);

// Вычисление суммы периметров всех фигур в контейнере
void RemoveByAverage(container &c);

#endif
