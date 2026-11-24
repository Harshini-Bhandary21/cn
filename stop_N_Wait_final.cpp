#include<iostream>
using namespace std;

int main(){
    cout<<"Enter the no of frames: ";
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<"Sending frame "<<i+1<<"......"<<endl;
        
        while(true){
            int ack;
            cout<<"Did you receive acknowledgement? (1=yes) (0=no): ";
            cin>>ack;

            if(ack==1){
                cout<<"Acknowledgement Received from frame "<<i+1<<endl;
                break;
            }else{
                cout<<"retransmitting Ack for frame "<<i+1<<endl;
            }

            cout<<"Ack received successfully"<<endl;
        }

        cout<<"Ack received successfully for all frames"<<endl;
    }
    return 0;
}