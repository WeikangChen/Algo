#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#pragma pack(1)

struct Date {
    unsigned short nDay      : 16;    // 0..7   (3 bits)
    unsigned short nWeek     : 16;    // 0..31  (6 bits)
    unsigned short nMonth    : 16;    // 0..12  (5 bits)
    unsigned short nYear     : 16;    // 0..100 (8 bits)
};

void print (Date &d) {
    cout << " Day = " << d.nDay
         << " Week = " << d.nWeek
         << " Month = " << d.nMonth
         << " Year = " << d.nYear
         << endl;
}

struct S {
    char flag1 : 1;
    char flag2 : 1;
    char flag3 : 1;
    char flag4 : 1;
    char flag5 : 1;
    char flag6 : 1;
    char flag7 : 1;
    char flag8 : 1;
};

int main(int argc, char** argv) {

    cout << "sizeof(S) = " << sizeof(S) << endl;
    const int n = sizeof(Date);
    cout << "sizeof(Date) = " << n << endl;
    
    Date date1 = {1, 28, 11, 16};
    Date date2 = {3, 10, 12, 120};
    print(date1);
    print(date2);
    fstream fs;

    // Set exceptions to be thrown on failure
    fs.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        fs.open("output.bin", ios::in | ios::out |  ios::binary);
    }
    catch(system_error& e) {
        cout << "Error opening file\n" ;
        cerr << "Error: " << e.what() << endl;;
        return 1 ;
    }
    fs.write((char*)&date1, n);
    fs.seekg(0, ios::beg);
    fs.read((char*)&date2, n);
    print(date2);
    fs.close();

    unsigned int i = 1;
    char *c = (char*)&i;
    if (*c)    
        printf("Little endian");
    else
        printf("Big endian");
    getchar();
    return 0;
}
