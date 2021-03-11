#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class MyString{
public:
    static size_t CCtor;

public:
    // 构造函数
    MyString(const char* cstr=0){
        if(cstr){
            m_data = new char[strlen(cstr) + 1];
            strcpy(m_data, cstr);
        }else{
            m_data = new char[1];
            *m_data = '\0';
        }
    }

    // 拷贝构造函数
    MyString(const MyString& other){
        m_data = new char[strlen(other.m_data) + 1];
        strcpy(m_data, other.m_data);
    }

    // 移动构造函数
    MyString(MyString&& str) noexcept
        :m_data(str.m_data) {
        str.m_data = nullptr;
    }

    // 拷贝赋值函数
    MyString& operator=(const MyString& other){
        if(this != &other){
            char* tmp = new char[strlen(other.m_data) + 1];
            strcpy(tmp, other.m_data);
            delete[] m_data;
            m_data = tmp;
            
            // 另一种写法
            // MyString tmp(other);
            // char* tmpPtr = tmp.m_data;
            // tmp.m_data = m_data;
            // m_data = tmpPtr;
        }
        return *this;
    }

    // 移动赋值函数
    MyString& operator=(MyString&& other) noexcept{
        if(this != &other){
            delete[] m_data;
            m_data = other.m_data;
            other.m_data = nullptr;
        }
        return *this;
    }

    ~MyString(){
        CCtor++;
        if(m_data != nullptr){
            delete[] m_data;    
            m_data = nullptr;
        }
    }

    char* c_str() const { return m_data; }

private:
    char* m_data;
};

size_t MyString::CCtor = 0;

int main(){
    MyString s1("aaa");
    MyString s2("bbbb");
    s1 = s2;
    cout << s1.c_str() << endl;
    cout << MyString::CCtor << endl;
    return 0;
}