#include "string.h"


tld::string&
tld::string::operator=(tld::string that) {
    std::swap(data, that.data);
    label_name = "(" + label_name + ") = (" + that.label_name + ")";
    return *this;
}

tld::string&
tld::string::operator=(const char *str) {
    size = std::strlen(str);
    capacity = size + 1;
    data = new char[size + 1];
    memcpy(data, str, size + 1);

    label_name = "(" + label_name + ") = ''" + str + "''";
    return *this;
}

tld::string&
tld::string::operator+=(const string &that) {
    if (size + that.size > capacity) {
        char* tmp = new char[size + that.size];
        memcpy(tmp, data, size);
        delete [] data;
        data = tmp;
    }
    memcpy(data + size, that.data, that.size + 1);
    size += that.size;
    capacity = size + 1;

    label_name = "(" + label_name + ") + (" + that.label_name + ")";
    return *this;
}

tld::string tld::operator+(const tld::string& first, const tld::string& second) {
    tld::string tmp(first);
    tmp += second;

    tmp.label_name = "is_tmp_of ((" + first.label_name + ") + (" + second.label_name + "))";
    return tmp;
}

