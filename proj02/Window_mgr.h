# include <vector>
# include <iostream>
# include "Screen.h"

class Window_mgr{
public:
    typedef std::vector<Screen>::size_type screen_index;
    void clear(const screen_index &);
private:
    std::vector<Screen> screens{Screen(48,128,'A')};
};
inline void Window_mgr::clear(const screen_index &s_index){
    // Screen &s = screens[s_index];
    Screen s = {screens[s_index]}; //使用列表直接初始化，直接初始化可以省去引用符号了吗？
    s.content = std::string(s.width*s.height,' ');
}
int main(){
    Screen my_screen(3,5,'B');
    my_screen.display(std::cout).set('#').display(std::cout);
    
    const Screen c_screen(3,5,'A');
    c_screen.display(std::cout);

    return 0;
}