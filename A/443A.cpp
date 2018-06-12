#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    bool arr[26] ={};
    for(int i = 1; i < str.length(); i++) {
        if(!(str[i] == ' ' || str[i] == '}' || str[i] == ','))
            arr[str[i] - 97] = true;
    }
    int count = 0;
    for(int i = 0; i < 26; i++) {
        if(arr[i])
            count++;
    }
    cout<<count;
    return 0;
}
