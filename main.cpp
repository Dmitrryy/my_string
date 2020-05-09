#include <iostream>
#include "string.h"

int main() {
    CREATE_STRING(str1);
    CREATE_STRING(str2);
    CREATE_STRING(str3);


    str1 = "Hello";
    str2 = " world";
    str3 = " and Intel!";

    //CREATE_STRING(str3);
    //tld::string str3(str1 + str2);
    //str1 = str3 + str2;
    CREATE_STRING(str4);
    str4 = str1 + str2;

    return 0;
}
