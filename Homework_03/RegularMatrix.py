""" Copyright 2021, German Mikhaylov.

 This file is part of Homework_03.

    Homework_03 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Homework_03 is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Homework_03.  If not, see <https://www.gnu.org/licenses/>.

-------------------------------------------------------------------------"""

from Matrix import *
import random


class RegularMatrix(Matrix):
    def __init__(self):
        self.__matrix = None
        self.__length = 0

    def read_from_file(self, str_array, i):
        self.__length = int(str_array[i])
        i += 1

        self.__matrix = [[0.0] * self.__length] * self.__length
        for k in range(0, self.__length):
            for j in range(0, self.__length):
                self.__matrix[k][j] = float(str_array[i])
                i += 1
        return i

    def random_input(self):
        self.__length = random.randint(1, 20)

        self.__matrix = [[0.0] * self.__length] * self.__length
        for k in range(0, self.__length):
            for j in range(0, self.__length):
                self.__matrix[k][j] = round(random.uniform(-20, 20), 5)
        pass

    def print_to_console(self):
        print("Regular matrix with dimension = " + str(self.__length) + "\n")
        for i in range(0, self.__length):
            for j in range(0, self.__length):
                print(str(self.__matrix[i][j]) + " ")
            print("\n")
        print("Average = " + str(self.get_average()) + "\n\n")
        pass

    def write_to_file(self, output_stream):
        output_stream.write("Regular matrix with dimension = " + str(self.__length) + "\n")
        for i in range(0, self.__length):
            for j in range(0, self.__length):
                output_stream.write(str(self.__matrix[i][j]) + " ")
            output_stream.write("\n")
        output_stream.write("Average = " + str(self.get_average()) + "\n\n")
        pass

    def get_average(self):
        summa = 0.0
        for i in range(0, self.__length):
            for j in range(0, self.__length):
                summa += self.__matrix[i][j]
        return summa / (self.__length * self.__length)
