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


class TriangleMatrix(Matrix):
    def __init__(self):
        self.__matrix = None
        self.__length = 0

    def read_from_file(self, str_array, i):
        self.__length = int(str_array[i])
        dim = int(int(str_array[i]) * (int(str_array[i]) + 1) // 2)

        i += 1

        self.__matrix = [0.0] * dim
        for k in range(0, dim):
            self.__matrix[k] = float(str_array[i])
            i += 1
        return i

    def random_input(self):
        self.__length = random.randint(1, 20)
        dim = int(self.__length * (self.__length + 1) // 2)

        self.__matrix = [0.0] * dim
        for k in range(0, dim):
            self.__matrix[k] = round(random.uniform(-20, 20), 5)
        pass

    def print_to_console(self):
        print("Triangle matrix with dimension = " + str(self.__length) + "\n")
        for i in range(0, self.__length):
            for j in range(0, self.__length):
                if j > i:
                    print(0, end=' ')
                else:
                    pos = int((self.__length * i) + j - ((i * (i + 1)) // 2))
                    print(str(self.__matrix[pos]) + " ")
            print("\n")
        print("Average = " + str(self.get_average()) + "\n\n")
        pass

    def write_to_file(self, output_stream):
        output_stream.write("Triangle matrix with dimension = " + str(self.__length) + "\n")
        for i in range(0, self.__length):
            for j in range(0, self.__length):
                if j > i:
                    output_stream.write("0 ")
                else:
                    pos = int((self.__length * i) + j - ((i * (i + 1)) // 2))
                    output_stream.write(str(self.__matrix[pos]) + " ")
            output_stream.write("\n")
        output_stream.write("Average = " + str(self.get_average()) + "\n\n")
        pass

    def get_average(self):
        summa = 0.0
        dim = int(self.__length * (self.__length + 1) // 2)
        for i in range(0, dim):
            summa += self.__matrix[i]
        return summa / (self.__length * self.__length)
