#include<iostream>
#include<string>
using namespace std;

bool isBinary(string s){
    for(char c:s){
        if(c!='0' && c!='1'){
            return false;
        }
    }

    return !s.empty();
}

string performXOR(string a, string b){
    string result = "";
    for(int i = 1;i<(int)b.length();i++){
        result += (a[i]==b[i])? '0':'1';
    }
    return result;
}

string calculateCRC(string data, string key){
    int keyLen = key.length();
    string temp = data.substr(0,keyLen);
    int index = keyLen;

    while(index<data.length()){
        if(temp[0]=='1'){
            temp = performXOR(temp,key) + data[index];
        }else{
            temp = performXOR(temp,string(keyLen,'0')) + data[index];
        }

        index++;
    }

    if (temp[0] == '1') {
        temp = performXOR(temp, key);
    } else {
        temp = performXOR(temp, string(keyLen, '0'));
    }

    return temp;
}

int main(){
    string data,key;

    cout<<"Enter data: ";
    cin>>data;

    cout<<"Enter generator: ";
    cin>>key;

    if(isBinary(data) || isBinary(key) || key.length()<2 || key[0]!='1'){
        cout<<"Invalid binary data or generator!"<<endl;
        return 1;
    }

    string appended = data + string(key.length()-1,'0');
    string crc = calculateCRC(appended,key);

    

    return 0;
}