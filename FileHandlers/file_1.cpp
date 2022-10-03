#include<iostream>
#include<fstream>

// 读入文件并显示内容

using namespace std;

int main(){
    auto fileName = "test.txt";
    cout << fileName << endl;
    
    fstream file_1;
    file_1.open(fileName, ios::in);
    if (!file_1.is_open())
    {
        std::cerr <<"There is an error while opening the file of " << fileName << "." << endl;
        return -1;
    }
    
    // 直接读取
    char buff_1[64] {};
    while (file_1 >> buff_1)
    {
        cout << buff_1 << endl;
    }
    
    // 按行读取
    char buff_2[64] {};
    while (file_1.getline(buff_2, sizeof(buff_2)))
    {   
        cout << buff_2 << endl;
    }
    
    // 字符读取
    char ch;
    while ((ch=file_1.get()) != EOF)
    {
        cout << ch;
    }
    
    file_1.close();
    return 0;
}