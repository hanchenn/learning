def my_generator(data_list):
    for value in data_list:
        yield value


if __name__ == "__main__":
    # 列表推导:用于创建列表
    l = [int(c) for c in "12345567890"]
    print(l)
    iter_l = iter(l)
    print(iter_l.__next__())
    print(iter_l.__next__())
    print(iter_l.__next__())

    # 创建生成器
    # 方式一：使用列表推导的方式
    gl = (int(c) for c in "12345567890")
    print(gl)
    print(gl.__next__())
    print(gl.__next__())
    print(gl.__next__())
    # 方式二:使用yield
    my_gen = my_generator("12345567890")
    print(my_gen)
    print(my_gen.__next__())
    print(my_gen)
    print(my_gen.__next__())


