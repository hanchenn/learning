# include <iostream>
using namespace std;
class Sales_data{
    //为Sales_data的非成员函数所做的友元声明
    friend Sales_data add(const Sales_data &,const Sales_data &);
    friend Sales_data add2(const Sales_data &,const Sales_data &);
    friend istream &read(istream&,Sales_data &);
    friend ostream &print(ostream&,const Sales_data &);

public:
    //构造函数
    Sales_data() = default; // 默认构造函数 
    // 构造函数初始值列表
    Sales_data(istream &);
    Sales_data(std::string &b,const unsigned &u,const double &r):bookNo(b),units_sold(u),revenue(r*u){}
    Sales_data(std::string &b):bookNo(b){}
    std::string isbn() const {return bookNo;} //获取书籍编号
    Sales_data& combine(const Sales_data&);
    double avg_price() const;//返回售出书籍的平均价格
private:
    // 成员变量
    std::string bookNo; //书籍编号
    unsigned units_sold = 0;//售出数量
    double revenue = 0.0;//收入
    //成员函数
    
};

//在类外部定义的构造函数
Sales_data::Sales_data(std::istream& is){
    read(is,*this);
}

//方法体在类外部的成员函数
double Sales_data::avg_price() const{
    if(units_sold){
        return revenue/units_sold;
    }
    else
    {
        return 0;
    }       
}

Sales_data& Sales_data::combine(const Sales_data& one_item){

    units_sold+=one_item.units_sold;
    revenue+=one_item.revenue;

    return *this;
}

/*
定以SalesData类相关的非成员接口函数
*/ 
// read函数，把cin流中的数据写入到成员变量中
istream &read(istream& is,Sales_data &s){
    double price = 0.0;
    is>>s.bookNo>>s.units_sold>>price;
    s.revenue = price * s.units_sold;
    return is;
}
// print函数，输出成员变量的信息
ostream &print(ostream& os,const Sales_data &s){
    os << s.bookNo << "sold num: " << s.units_sold << "revenue: " << s.revenue;
    return os;
}

// add函数，把编号相同的书籍信息加起来
Sales_data add(const Sales_data &s1,const Sales_data &s2){
    Sales_data s_sum;
    if(s1.bookNo == s2.bookNo){
        s_sum.bookNo = s1.bookNo;
        s_sum.units_sold = s1.units_sold + s2.units_sold;
        s_sum.revenue = s1.revenue + s2.revenue;
    }
    else{
        cout << s1.bookNo << " and " << s2.bookNo << " is different!!!" << endl;
    }
    return s_sum;
}

Sales_data add2(const Sales_data &s1,const Sales_data &s2){
    Sales_data s_sum = s1; //s_sum是s1的副本
    s_sum.combine(s2);
    return s_sum;
}

// 调用SalesData类
int main(){
    Sales_data total;
    if(read(cin,total)){
        Sales_data trans;
        while(read(cin,trans)){
            if(total.isbn() == trans.isbn()){
                total.combine(trans);
            }
            else{
                print(cout,total) << endl;
                total = trans;
            }
        }
        print(cout,total) << endl;

    }
    else{
        cerr << "No data?!" << endl;
    }

}