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
#include "Bee.h"
#include "BeeHive.h"

void Bee::work(BeeHive *beeHive) const {
    // пчела улетает за методом и возвращается
    std::this_thread::sleep_for(std::chrono::milliseconds(450));

    std::unique_lock<std::mutex> bee_lock(beeHive->bee_mutex);
    beeHive->increment_bee_counter();
    bee_lock.unlock();

    std::unique_lock<std::mutex> honey_lock(beeHive->honey_mutex);

    if (beeHive->get_honey_counter() < 30) {
        beeHive->increment_honey_counter();
        // пчела выгружает мед
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "[Пчела " + std::to_string(index) + "] выгружает мёд, всего порций в улье = " +
                     std::to_string(beeHive->get_honey_counter()) + "\n";
    } else {
        std::cout << "[Пчела " + std::to_string(index) + "] не может выгрузить мёд, т.к. макс кол-во достигнуто\n";
    }

    beeHive->decrement_bee_counter();
    bee_lock.lock();
}
