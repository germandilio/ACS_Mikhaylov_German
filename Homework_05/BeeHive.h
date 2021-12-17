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
#ifndef AVS_HW_5_BEEHIVE_H
#define AVS_HW_5_BEEHIVE_H

#include <iostream>
#include <mutex>

class BeeHive {
    int honey_counter = 0;
    int bee_counter = 0;

public:
    const double max_capacity = 30;
    std::mutex bee_mutex;
    std::mutex honey_mutex;

    int get_honey_counter() const {
        return honey_counter;
    }

    int get_bee_counter() const {
        return bee_counter;
    }

    void increment_honey_counter() {
        honey_counter++;
    }

    void increment_bee_counter() {
        bee_counter++;
    }

    void decrement_bee_counter() {
        bee_counter--;
    }

    void steelHoneyByBear() {
        honey_counter = 0;
    }

    void start(int bee_number);
};


#endif //AVS_HW_5_BEEHIVE_H
