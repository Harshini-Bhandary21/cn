#include<iostream>
using namespace std;

int main(){
    string data, transmitted, received;
    int choice;

    cout<<"Enter data: ";
    cin>>data;

    cout<<"Original Data: ";
    while(true){
        cout<<"Enter choice: "<<endl;
        cout<<"1. Even Parity"<<endl;
        cout<<"2. Odd Parity"<<endl;
        cout<<"click any number to exit"<<endl;
        cin>>choice;

        transmitted=data;
        int count = 0;
        if(choice==1){
            for(int i=0;i<data.length();i++){
                if(data[i]=='1'){
                    count++;
                }
            }

            if (count%2==0)
            {
                transmitted+= to_string(0);
            }else{
                transmitted+= to_string(1);
            }

            cout<<"transmitted data : ";
            for(int i=0;i<transmitted.length();i++){
                cout<<transmitted[i];
            }

            cout<<"Enter received data: ";
            cin>>received;

            for(int i=0;i<received.length();i++){
                if(received[i]=='1'){
                    count++;
                }
            }

            if (count%2==0)
            {
                cout<<"Error not detected";
            }else{
                cout<<"Error detected";
            }

            int errorAt;
            int bit;
            for(int i=0;i<received.length();i++){
                if(received[i]!=transmitted[i]){
                    errorAt = i;
                    bit = received[i];
                }
            }
            if(bit==0){
                received[errorAt] = 1;
            }else{
                received[errorAt] = 0;
            }
            
            cout<<"corrected data : ";
            for(int i=0;i<received.length();i++){
                cout<<received[i];
            }

        }
        else if(choice==0){
            for(int i=0;i<data.length();i++){
                if(data[i]=='1'){
                    count++;
                }
            }

            if (count%2==0)
            {
                transmitted+= to_string(1);
            }else{
                transmitted+= to_string(0);
            }

            cout<<"Enter received data: ";
            cin>>received;

            for(int i=0;i<received.length();i++){
                if(received[i]=='1'){
                    count++;
                }
            }

            if (count%2==0)
            {
                cout<<"Error detected";
            }else{
                cout<<"Error not detected";
            }

            int errorAt;
            int bit;
            for(int i=0;i<received.length();i++){
                if(received[i]!=transmitted[i]){
                    errorAt = i;
                    bit = received[i];
                }
            }
            if(bit==0){
                received[errorAt] = 1;
            }else{
                received[errorAt] = 0;
            }
            
            cout<<"corrected data : ";
            for(int i=0;i<received.length();i++){
                cout<<received[i];
            }
        }else{
            break;
        }
    }
    return 0;
}