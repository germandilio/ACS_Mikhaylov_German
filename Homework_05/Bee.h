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
#ifndef AVS_HW_5_BEE_H
#define AVS_HW_5_BEE_H


#include "Bear.h"

class Bee {
    int index;
public:
    void work(BeeHive *beeHive) const;

    explicit Bee(int index) {
        this->index = index;
    }
};


#endif //AVS_HW_5_BEE_H
