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

from DiagonalMatrix import DiagonalMatrix
from RegularMatrix import RegularMatrix
from TriangleMatrix import TriangleMatrix
import random


class Container:
    def __init__(self):
        self.store = []

    def print_container(self):
        print("Container is store", len(self.store), "matrix:")
        for matrix in self.store:
            matrix.print_to_console()
        pass

    def write_container(self, output_stream):
        output_stream.write("Container is store {} matrix:\n".format(len(self.store)))
        for matrix in self.store:
            matrix.write_to_file(output_stream)
            output_stream.write("\n")
        pass

    def remove_by_average(self):
        summa = 0.0
        length = len(self.store)
        for i in range(length):
            summa += self.store[i].get_average()

        container_average = summa / length

        container_after_delete = []
        for i in range(len(self.store)):
            if self.store[i].get_average() >= container_average:
                container_after_delete.append(self.store[i])

        length = len(container_after_delete)
        self.store.clear()

        for i in range(length):
            self.store.append(container_after_delete[i])
        pass

    def read_str_array(self, str_array):
        array_len = len(str_array)
        # Индекс, задающий текущую строку в массиве
        i = 0
        fig_num = 0
        while i < array_len:
            key = int(str_array[i])
            if key == 1:
                i += 1
                matrix = RegularMatrix()
                # чтение обычной матрицы с возвратом позиции за ним
                i = matrix.read_from_file(str_array, i)
            elif key == 2:
                i += 1
                matrix = DiagonalMatrix()
                # чтение диагональной матрицы с возвратом позиции за ним
                i = matrix.read_from_file(str_array, i)
            elif key == 3:
                i += 1
                matrix = TriangleMatrix()
                # чтение треугольной матрицы с возвратом позиции за ним
                i = matrix.read_from_file(str_array, i)
            else:
                # Неверный признак
                # Возврат количества прочитанных фигур
                return fig_num

            fig_num += 1
            self.store.append(matrix)
        return fig_num

    def create_random(self, number):
        for i in range(number):
            self.store.append(random_matrix())
        pass


def random_matrix():
    identifier = random.randint(1, 3)
    matrix = None
    if identifier == 1:
        matrix = RegularMatrix()
    elif identifier == 2:
        matrix = DiagonalMatrix()
    elif identifier == 3:
        matrix = TriangleMatrix()

    matrix.random_input()
    return matrix
