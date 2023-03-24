//
// Created by lriy on 3/6/23.
//

#ifndef QTDEMO01_LIB_H
#define QTDEMO01_LIB_H
#include <string>
#include <algorithm>
#include <arpa/inet.h>
#include <vector>
using namespace std;
string reverseIP(string ip)
{
    ip += '.';
    vector<string> v;
    string temp;
    string res;
    for(int i = 0; i < ip.length(); i++)
    {
        if (ip[i] != '.')
        {
            temp += ip[i];

        }
        else {
            v.push_back(temp);
            temp = "";
        }
    }
    for(int i = v.size() - 1; i > 0 ; i--)
    {
        res += v[i];
        res += '.';
    }
    res += v[0];
    return res;
}
#endif //QTDEMO01_LIB_H
