#ifndef STRINGV2_STRING_H
#define STRINGV2_STRING_H

#include <cstdint>
#include <algorithm>
#include <cstring>
#include <iostream>

#define CREATE_STRING(a) \
tld::string a(#a);

namespace tld {

    class string {
    public:
        string():
        size(0),
        capacity(0),
        data(nullptr) {}

        string(const char* _str)
        : size(std::strlen(_str))
        , data(nullptr)
        {
            capacity = size = 0;
            label_name += _str;

/*            capacity = size + 1;
            data = new char[size + 1]();
            memcpy(data, _str, size + 1);*/
        }

        string(const string& that):
        size(that.size),
        capacity(that.capacity),
        data(new char[that.capacity])
        {
            memcpy(data, that.data, that.size + 1);
            label_name = "is_cpy(" + that.label_name + ")";
        }

        string(string&& that) noexcept {
            size = that.size;
            capacity = that.capacity;
            data = that.data;
            that.data = nullptr;
            that.size = that.capacity = 0;

            label_name = "was_mov(" + that.label_name + ")";
        }

        ~string() {
            std::cout << "deleted: " << label_name << std::endl;
            delete[] data;
            data = nullptr;
        }

    public:
        string& operator=(string that);
        string& operator=(const char* str);
        string& operator+=(const string& that);

    private:
        uint32_t capacity;
        uint32_t size;
        char* data;

    public:
        std::string label_name;
    };

    string operator+(const string& first, const string& second);
    string operator+(string&& first, const string& second);

}

#endif //STRINGV2_STRING_H
