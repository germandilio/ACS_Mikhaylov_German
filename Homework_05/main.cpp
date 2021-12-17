// Copyright 2021, German Mikhaylov.
//
// This file is part of Homework_05.
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
//    along with Homework_05.  If not, see <https://www.gnu.org/licenses/>.
//
//-------------------------------------------------------------------------
#include <iostream>
#include <semaphore>
#include "BeeHive.h"

int main() {
    int number_of_bees;
    std::cout << "Введите кол-во пчел > 3 и < 20: ";

    std::cin >> number_of_bees;
    if (number_of_bees > 3 && number_of_bees < 20) {

        auto *hive = new BeeHive();
        hive->start(number_of_bees);
        delete hive;
    } else {
        std::cout << "Вы ввели кол-во пчел меньше чем 3, перезапустите программу\n";
    }
    return 0;
}
