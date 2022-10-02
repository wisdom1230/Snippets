#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

struct information
{
    string coutry;
    int age;
    int salay;
    string purchased;
};

int main(){
    auto fileName = "test.txt";
    fstream file_2;
    file_2.open(fileName, ios::in);
    if (!file_2.is_open())
    {
        return -1;
    }
    
    string line;
    vector<information> Information;
    getline(file_2, line);
    while (getline(file_2, line))
    {
        stringstream ss(line);
        string data;
        information info;
        
        getline(ss, data, ',');
        info.coutry = data;
        getline(ss, data, ',');
        info.age = atoi(data.c_str());
        getline(ss, data, ',');
        info.salay = atoi(data.c_str());
        getline(ss, data, ',');
        info.purchased = data;
        Information.push_back(info);
    }
    for (size_t i = 0; i < Information.size(); i++)
    {
        cout << Information[i].coutry << "\t" << Information[i].age << "\t" << Information[i].salay << "\t" << Information[i].purchased << endl;
    }
    
    return 0;
}