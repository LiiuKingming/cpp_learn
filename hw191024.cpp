//
// Created by 28943 on 2019/10/27.
//
#include <iostream>
using namespace std;

class Date{
public:
    explicit Date(int year = 1900, int month = 1, int day = 1){
        //判断日期正确性
        if(year <= 0 || month <= 0 || month >12 || day <= 0 || day > getDay(year, month)) {
            this->m_year = 1;
            this->m_month = 1;
            this->m_day = 1;
            cout << "日期非法 重置为1 - 1 - 1" << endl;
        }else{
            this->m_year = year;
            this->m_month = month;
            this->m_day = day;
        }
    }

    static int getDay(int year, int month){
        static int s_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int day = s_days[month - 1];
        if(month == 2){
            if((year % 4 == 0) && (year % 100 != 0 || year % 400  == 0))
                ++day;
        }
        return day;
    }
    Date(const Date& d)
        : m_year(d.m_year)
        , m_month(d.m_month)
        , m_day(d.m_day) {
    }

    Date& operator=(const Date& d){
        if(this != &d){
            m_year = d.m_year;
            m_year = d.m_month;
            m_day = d.m_day;
        }
        return *this;
    }
    Date operator+(int days){
        Date tmp(*this);
        tmp += days;
        return tmp;
    }
    Date operator-(int days){//-天数得到日期
        Date tmp = *this;
        tmp.m_day = tmp.m_day - days;
        while (tmp.m_day <= 0){
            --tmp.m_month;
            if(tmp.m_month == 0){
              tmp.m_month = 12;
              tmp.m_year--;
            }
            tmp.m_day += getDay(tmp.m_year, tmp.m_month);
        }
        return tmp;
    }
    int operator-(const Date& d){//-日期得到天数
        Date max, min;
        int flag;
        int count = 0;
        if(*this < d){
            min = *this;
            max = d;
            flag = -1;
        }else{
            min = d;
            max = *this;
            flag = 1;
        }
        while(min < max){
            ++min;
            ++count;
        }
        return count * flag;
    }
    //i = 10  i += 2  i--->12
    Date& operator+=(int days){
        if(days < 0)
            return *this -= (-days);
        m_day += days;
        while(m_day > getDay(m_year, m_month)){
            m_day -= getDay(m_year, m_month);
            ++m_month;
            if(m_month == 13){
                m_month = 1;
                ++m_year;
            }
        }
        return *this;
    }

    Date& operator-=(int days){
        if(days < 0)
            return *this += (-days);
//        *this = *this - days;
//        return this;
        m_day -= days;
        while(m_day <= 0){
            --m_month;
            if(m_month == 0){
                m_month = 12;
                m_year--;
            }
            m_day += getDay(m_year, m_month);
        }
        return *this;
    }
    //++x
    Date& operator++(){
        return  *this += 1;
    }
    //x++
    Date operator++(int){
        Date tmp(*this);
        *this += 1;
        return tmp;
    }
    //--x
    Date& operator--(){
        return *this -= 1;
    }
    //x--
    Date operator--(int ){
        Date tmp(*this);
        *this -= 1;
        return tmp;
    }
    bool operator>(const Date& d)const{
        if(m_year > d.m_year)
            return true;
        if(m_year == d. m_year){
            if(m_month > d.m_month){
                return true;
            }else if(m_month == d.m_month) {
                if (m_day > d.m_day)
                    return true;
            }
        }
        return false;
    }

    bool operator>=(const Date& d)const{
        return *this > d || *this == d;
    }

    bool operator<(const Date& d)const{
        return !(*this >= d);
    }
    bool operator<=(const Date& d)const{
        return !(*this > d);
    }

    bool operator==(const Date& d)const{
        return this->m_year == d.m_year && this->m_month == d.m_month && this->m_day == d.m_day;
    }

    bool operator!=(const Date& d)const{
        return !(*this == d);
    }

    friend ostream& operator<<(ostream& _cout, const Date& d){
        _cout << d.m_year << "-" << d.m_month <<"-"<<d.m_day <<endl;
        return _cout;
    }
    friend istream& operator>>(istream& _cin, Date& d){
        _cin >> d.m_year >> d.m_month >> d.m_month;
        return _cin;
    }
private:
    int m_year;
    int m_month;
    int m_day;
};

void Test(){
    Date d1(2019, 11, 30);
    Date d2(2018, 11, 10);
    cout << (d1 - d2) <<endl;
}

int main(){
    Test();
    return 0;
}
