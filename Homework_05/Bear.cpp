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
#include "Bear.h"

void Bear::wake_up_bear(BeeHive *beeHive) const {
    std::unique_lock<std::mutex> bee_lock(beeHive->bee_mutex);
    if (beeHive->get_bee_counter() >= 3) {
        // пчелы кусают Винни-Пуха и он убегает
        std::cout << "Медведя покусали пчелы, он ушел залечивать раны\n";
        bee_lock.unlock();

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        bee_lock.lock();
    } else {
        std::unique_lock<std::mutex> honey_lock(beeHive->honey_mutex);
        std::cout << "Медведь украл " +  std::to_string(beeHive->get_honey_counter()) + " порций меда\n";

        beeHive->steelHoneyByBear();
    }
}
