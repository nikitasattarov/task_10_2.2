#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <locale.h>
#include <string>

using namespace std;

int main() {
    setlocale(0, "Russian");
    map < string, pair < vector < string >, vector < int > > > d;
    vector < string > names, replicas;
    vector < int > numbers;
    int number = 1;
    string str, name, replica;
    ifstream input;
    ofstream output;
    input.open("input.txt");
    output.open("output.txt");
    getline(input, str);
    getline(input, str);
    while (str != "textLines:")
    {
        names.push_back(str);
        getline(input, str);
    }
    int i = 0;
    while (getline(input, str))
    {
        name = "";
        replica = "";
        while (str[i] != ':')
        {
            name += str[i];
            i++;
        }
        i ++;
        while (i < str.size())
        {
            replica += str[i];
            i ++;
        }
        i = 0;
        d[name].first.push_back(replica);
        d[name].second.push_back(number);
        number++;
    }
    for (vector < string > ::iterator i = names.begin(); i != names.end(); i++)
    {
        replicas = d[(*i)].first;
        numbers = d[(*i)].second;
        output << *i << endl;
        for (int j = 0; j < replicas.size(); ++j)
        {
            output << numbers[j] << ") " << replicas[j] << endl;
        }
        output << endl;
    }
    output.close();
    return 0;
}
