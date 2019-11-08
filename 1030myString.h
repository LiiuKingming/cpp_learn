//
// Created by 28943 on 2019/10/30.
//

#ifndef CPLUSPLUS_MYSTRING1030_H
#define CPLUSPLUS_MYSTRING1030_H

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
#define DEFAULTCAPA 16
#define COUNTCAPA(size)  (((size) / DEFAULTCAPA + 1) * DEFAULTCAPA)

class String{
    char* m_data;
    size_t m_size;
    size_t m_capacity;
public:
    String(const char* str = ""):
        m_capacity(DEFAULTCAPA){
        if(nullptr == str){
            str = "";
        }
        /*    m_size = 0;
        }*/
        m_size = strlen(str);//要扩容
        m_capacity = COUNTCAPA(m_size);
        m_data = new char[m_capacity];
        strncpy(m_data, str, m_size);
    }

    //拷贝构造
    String(String &s){
        m_size = s.m_size;
        m_capacity = s.m_capacity;
        //m_data 深拷贝
        m_data = new char[m_capacity];
        strcpy(m_data, s.m_data);
    }

    String &operator=(const char* str){
        m_size = strlen(str);
        Reserve(m_size);
        strcpy(m_data, str);
        return *this;
    }

    String & operator=(String & s){
        m_size = s.m_size;
        Reserve(m_size);
        strcpy(m_data, s.m_data);
        return *this;
    }

    String(size_t n, char ch):
    m_size(n),
    m_capacity(DEFAULTCAPA){
        Reserve(m_size);

        m_data = new char[m_capacity];
        //memset初始化
        memset(m_data, ch, m_size);//也可以用循环写
    }

    ~String(){
        if(m_data){
            delete[] m_data;
            m_data = nullptr;
        }
        m_size = m_capacity = 0;
    }

    size_t Size(){
        return m_size;
    }

    size_t Length(){
        return m_size;
    }

    size_t Capacity(){
        return m_capacity - 1;
    }

    bool Empty(){
        return m_size == 0;
    }

    void Clear(){
        m_size = 0;
    }

    void Resize(size_t size, char ch = '\0'){
        Reserve(size);
        if(m_size < size){
            memset(m_data + m_size, ch, size - m_size);
        }//清除
        m_size = size;
    }

    void Reserve(size_t size){
        if(size >= m_capacity){
            m_capacity = (size / DEFAULTCAPA + 1) * DEFAULTCAPA;
            m_data = (char*)realloc(m_data, m_capacity);

        }
    }

    char &operator[](int i){
        return m_data[i];
    }

    typedef char* iterator;
    iterator begin(){
        return m_data;
    }
    iterator end(){
        return m_data + m_size;
    }

    void push_Back(char ch){
        Reserve(m_size);
        m_data[m_size] = ch;
        m_size++;
    }
    void pop_Back(){
        if(!Empty()) {
            m_size--;
        }
    }

    String &operator+=(const char * str){
//        m_data[m_size] = '\0';
        int tmp = m_size;
        m_size += strlen(str);
        Reserve(m_size);

//        strcat(m_data, str);//strcat把str接到m_data
        strcpy(m_data + tmp, str);
        return *this;
    }

    String & operator+=(String & s){
//        m_data[m_size] = '\0';
        int tmp = m_size;
        m_size += s.m_size;
        Reserve(m_size);

//        strcat(m_data + m_size, s.m_data);
        strcpy(m_data + tmp, s.m_data);
        return *this;
    }

    const char* c_str(){
        return m_data;
    }

    size_t find(char ch, int pos = 0){
        if(pos < 0 || pos >= m_size){
            return -1;
        }
        char *tmp = strchr(m_data + pos, ch);
        if(tmp){
            return tmp - m_data;//减首位置就是他的位置
        }
        return -1;
    }

    size_t find(const char* str, int pos = 0){
        if(pos < 0 || pos >= m_size){
            return -1;
        }
        char *tmp = strstr(m_data + pos, str);
        if(tmp){
            return tmp - m_data;//减首位置就是他的位置
        }
        return -1;
    }

    size_t find(const String &s, int pos = 0){
        if(pos < 0 || pos >= m_size){
            return -1;
        }
        char *tmp = strstr(m_data + pos, s.m_data);
        if(tmp){
            return tmp - m_data;//减首位置就是他的位置
        }
        return -1;
    }

    String substr(size_t start, size_t num){
        String tmp;
        tmp.Resize(num);
        strncpy(tmp.m_data, m_data + start, num);
        return tmp;
    }

    String operator+(const char* str)const;//普通
    String operator+(const String &s)const;//在左
    friend String operator+(const char* str, const String &s);//在两边

    bool operator>(const char* str)const;
    bool operator<(const char* str)const;
    bool operator>=(const char* str)const;
    bool operator<=(const char* str)const;
    bool operator==(const char* str)const;
    bool operator!=(const char* str)const;

    bool operator>(const String &s)const;
    bool operator<(const String &s)const;
    bool operator>=(const String &s)const;
    bool operator<=(const String &s)const;
    bool operator==(const String &s)const;
    bool operator!=(const String &s)const;

    friend bool operator>(const char* str, const String &s);
    friend bool operator<(const char* str, const String &s);
    friend bool operator>=(const char* str, const String &s);
    friend bool operator<=(const char* str, const String &s);
    friend bool operator==(const char* str, const String &s);
    friend bool operator!=(const char* str, const String &s);


    friend ostream & operator<<(ostream& os, const String &s);
    friend istream & operator>>(istream& is, String &s);
};

ostream& operator<<(ostream& os, const String &s){
    int i;
    for(i = 0; i < s.m_size ; i++){
        os << s.m_data[i];
    }
    return os;
}

istream& operator>>(istream& is, String &s){
//    is >> s.m_data;//const
    char* tmp = new char[1024];
    is.getline(tmp, 1024);

    s.m_size = strlen(tmp);
    s.m_capacity = COUNTCAPA(s.m_size);
    delete[]s.m_data;
    s.m_data = tmp;

    /*strcpy(s.m_data, tmp);
    delete(tmp);*/

    return is;
}

String String::operator+(const char* str)const{
    String res;
    res.m_size = m_size + strlen(str);
    res.Reserve(res.m_size);

    strncpy(res.m_data, m_data, m_size);
    strcpy(res.m_data + m_size, str);
    return res;
}
String String::operator+(const String &s)const{
    String res;
    res.m_size = m_size + s.m_size;
    res.Reserve(res.m_size);

    strncpy(res.m_data, m_data, m_size);
    strncpy(res.m_data + m_size, s.m_data, s.m_size);
    return res;
}
String operator+(const char* str, const String &s){
    String res;
    res.m_size = strlen(str) + s.m_size;
    res.Reserve(res.m_size);

    strcpy(res.m_data, str);//注意前后顺序
    strncat(res.m_data, s.m_data, s.m_size);
    return res;
}

bool String::operator>(const char* str)const{
//    int tmp = strncmp(m_data, str, m_size);
//   if(tmp = 0 && strlen(str) > m_size){
//       return false;
//    }
//    return tmp > 0;
    return strncmp(m_data, str, m_size) > 0;

}
bool String::operator<(const char* str)const{
    int tmp = strncmp(m_data, str, m_size);
    if(!tmp && strlen(str) > m_size){
        return true;
    }
    return tmp;
}
bool String::operator>=(const char* str)const{
    return !(*this < str);
}
bool String::operator<=(const char* str)const{
    return !(*this >str);
}
bool String::operator==(const char* str)const{
    int tmp = strncmp(m_data, str, m_size);
    if(tmp == 0  && strlen(str) == m_size){
        return true;
    }
    return false;
}
bool String::operator!=(const char* str)const{
    return !(*this == str);
}

bool String::operator>(const String &s)const{
    int i;
    int minSize = m_size < s.m_size ? m_size : s.m_size;
    for(i = 0; i < minSize; i++){
        if(m_data[i] > s.m_data[i]){
            return true;
        }else if(m_data[i] < s.m_data[i]){
            return false;
        }
    }
    return m_size > s.m_size;
}
bool String::operator<(const String &s)const{
    int i;
    int minSize = m_size < s.m_size ? m_size : s.m_size;
    for(i = 0; i < minSize; i++){
        if(m_data[i] < s.m_data[i]){
            return true;
        }else if(m_data[i] > s.m_data[i]){
            return false;
        }
    }
    return m_size < s.m_size;
}
bool String::operator>=(const String &s)const{
    return !(*this < s);
}
bool String::operator<=(const String &s)const{
    return !(*this > s);
}
bool String::operator==(const String &s)const{
    int i;
    int minSize = m_size < s.m_size ? m_size : s.m_size;
    for(i = 0; i < minSize; i++){
        if(m_data[i] != s.m_data[i]){
            return false;
        }
    }
    return m_size == s.m_size;
}
bool String::operator!=(const String &s)const{
    return !(*this == s);
}

bool operator>(const char* str, const String &s){
    int tmp = strncmp(str, s.m_data, s.m_size);
    if(tmp == 0 && strlen(str) > s.m_size){
        return true;
    }
    return tmp > 0;
}
bool operator<(const char* str, const String &s){
    return strncmp(str, s.m_data, s.m_size) < 0;
}
bool operator>=(const char* str, const String &s){
    return !(str < s);
}
bool operator<=(const char* str, const String &s){
    return !(str > s);
}
bool operator==(const char* str, const String &s){
    int tmp = strncmp(s.m_data, str, s.m_size);
    if(tmp == 0  && strlen(str) == s.m_size){
        return true;
    }
    return false;
}
bool operator!=(const char* str, const String &s){
    return !(str == s);
}

#endif //CPLUSPLUS_MYSTRING1030_H
