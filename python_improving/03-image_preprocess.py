import os
import cv2


# 图片预处理类:输入一个路径，返回一个获取预处理后的图片迭代器
class image_preprocess:
    def __init__(self, images_path, process_methods):
        self.image_suffix = ['.jpg', '.png', '.bmp', '.jpeg']
        self.images_path = images_path
        self.process_methods = process_methods
        self.images_list = []
        self.image_index = 0
        self.image_name = None
        self.image = None
        self.image_processed = None
        self.get_images_list()

    # 获取图片列表
    def get_images_list(self):
        if not os.path.exists(self.images_path):
            print("{:s} don't exists!!".format(self.images_path))
            exit(1)
        for path, _, filenames in os.walk(self.images_path):
            sub_images_list = [os.path.join(path, filename) for filename in filenames if
                               os.path.splitext(filename.lower())[1] in self.image_suffix]
            self.images_list += sub_images_list

    # 读取图片
    def read_image(self):
        self.image = cv2.imread(self.image_name)
        if self.image is None:
            print("Reading {:s} is None!!".format(self.image_name))
            raise NameError

    def do_process(self):
        image_processing = self.image
        for process in self.process_methods:
            self.image_processed = process(image_processing)
            image_processing = self.image_processed
        self.image_processed = image_processing

    # 支持索引和for循环
    def __getitem__(self, index):
        self.image_index = index
        self.image_name = self.images_list[self.image_index]
        self.read_image()
        self.do_process()
        return self.image_processed


def image_resize(image, size=(128,64)):
    return cv2.resize(image, size)


def image_to_gray(image):
    return cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)


if __name__ == "__main__":
    src_path = "../images"
    img_processed = image_preprocess(src_path, [image_resize, image_to_gray])

    for img in img_processed:  # 自动调用img_processed.__getitem__方法，img就是方法的返回值
        print("{:s} has been processing".format(img_processed.image_name))
        cv2.imshow(img_processed.image_name, img)
        cv2.waitKey(0)
