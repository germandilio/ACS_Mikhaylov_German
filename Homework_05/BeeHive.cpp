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
#include <thread>
#include <vector>
#include "BeeHive.h"
#include "Bee.h"
#include "Bear.h"

void BeeHive::start(int bee_number) {
    Bear bear;
    std::vector<Bee *> bees;

    // создаем пчел
    for (int i = 0; i < bee_number; ++i) {
        Bee *bee = new Bee(i);
        bees.push_back(bee);
    }

    // 10 раундов пчел, запускаются с задержкой, чтобы пчелы не летали раундами (все вместе)
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < bee_number; ++j) {
            std::this_thread::sleep_for(std::chrono::milliseconds(73));

            Bee *bee = bees[j];
            std::thread current([bee, this](){ bee->work(this);});
            current.detach();
        }

        if (this->get_honey_counter() > this->max_capacity / 2) {
            bear.wake_up_bear(this);
        }
    }
}