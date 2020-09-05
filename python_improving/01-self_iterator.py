# 定义自己的迭代器类
from collections import Iterable


# 自定义一个迭代器类，需要实现两个方法：__iter__，__next__
class my_iter(object):
    '''
    迭代器的两个作用:
    1. 记录位置；
    2. 返回当前位置的值。
    '''

    def __init__(self, data_list):
        self.current_index = 0
        self.data_list = data_list

    def __iter__(self, data_list):
        pass

    def __next__(self):
        if self.current_index >= len(self.data_list):
            # 抛出异常
            raise StopIteration
        else:
            data = self.data_list[self.current_index]
            self.current_index += 1
            return data


# 自定义一个列表
class my_list(object):
    def __init__(self):
        self.data_list = []

    def add_item(self, value):
        self.data_list.append(value)

    def __iter__(self):
        return my_iter(self.data_list)


if __name__ == "__main__":
    print(isinstance(my_iter(None), Iterable))
    print(isinstance(my_list(), Iterable))

    myls = my_list()
    myls.add_item(4)
    myls.add_item(3)
    myls.add_item(8)

    # 获取可迭代对象的迭代器
    myls_iter = iter(myls)
    # 利用迭代器的next方法获取可迭代对象的元素
    print(next(myls_iter))
    print(next(myls_iter))
    print(next(myls_iter))

    # for循环的本质就是获取了可迭代对象的迭代器
    for value in myls:
        print(value)
