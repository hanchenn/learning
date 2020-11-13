# ifndef SCREEN_H
# define SCREEN_H
# include <string>
# include <iostream>

// extern Window_mgr::clear(const screen_index);
class Screen{
public:
    //定义类型成员
    typedef std::string::size_type pos;
    //定义构造函数
    Screen() = default;
    Screen(pos w,pos h,char c):width(w),height(h),content(w*h,c){}
    //定义成员函数
    char get() const {return content[cursor];} // 获取光标处的字符
    char get(pos num_r,pos num_c) const;
    Screen &move(pos num_r,pos num_c);
    Screen &set(char);
    Screen &set(pos,pos,char);
    //基于const的重载，const的Screen对象调用的是const版本的display，
    //非const的对象调用的是非const版本的display
    Screen &display(std::ostream &){do_display(std::cout);return *this;}
    const Screen &display(std::ostream &) const{do_display(std::cout);return *this;}

private:
    //定义成员变量
    pos cursor = 0; //光标位置
    pos width = 0,height = 0; //屏幕的宽高
    std::string content=nullptr;
    mutable std::string::size_type access_time = 0; //可变数据成员，即使是const成员函数也可以进行修改
    void do_display(std::ostream & os) const {os << content;}
    //定义友元
    friend class Window_mgr;//定义友元类
    // friend Window_mgr::clear(const screen_index);//定义其他类的友元成员函数
    
};

char Screen::get(pos r,pos c) const {
    return content[r*width+c];
}
inline Screen &Screen::move(pos r,pos c){ //以左值的形式返回对象
    cursor=r*width+c;
    return *this; 
}
inline Screen &Screen::set(char c){
    content[cursor] = c;
    return *this;
}
inline Screen &Screen::set(pos num_r,pos num_c,char c){
    content[num_r*width+num_c] = c;
    return *this;
}

#endif