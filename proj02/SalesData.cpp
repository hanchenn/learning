# include "SalesData.h"
# include <iostream>

int main(){
    SalesData s1,s2;
    double price=0.0;
    // 读入数据
    std::cin >> s1.bookNo >> s1.units_sold >> price;
    s1.revenue = price * s1.units_sold;
    std::cin >> s2.bookNo >> s2.units_sold >> price;
    s2.revenue = price * s2.units_sold;
    
    // 比较s1和s2的编号
    if(s1.bookNo == s2.bookNo){
        //如果是同一编号，求和
        unsigned sum_units_sold = s1.units_sold + s2.units_sold;
        double sum_revenue = s1.revenue + s2.revenue;
        std::cout << s1.bookNo << "units_sold is: " << sum_units_sold 
                  << " and total reenue is: "<< sum_revenue << std::endl;
        
        return 0;
    }
    else{
        std::cout << "The two books' bookNo must be same!"<<std::endl;
        return -1; //返回负值标识失败
    }
}
