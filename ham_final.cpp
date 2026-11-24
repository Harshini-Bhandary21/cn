#include<iostream>
using namespace std;
void encode(int h[],int d[]){
    h[3] = d[0];
    h[5] = d[1];
    h[6] = d[2];
    h[7] = d[3];

    h[1] = h[3]^h[5]^h[7];
    h[2] = h[3]^h[6]^h[7];
    h[4] = h[5]^h[6]^h[7];
}
void display(int h[]){
    for(int i=1;i<=7;i++){
        cout<<h[i]<<" ";
    }
    cout<<endl;
}
int detect(int h[]){
    int s1 =h[1]^ h[3]^h[5]^h[7];
    int s2 = h[2]^h[3]^h[6]^h[7];
    int s4 = h[4]^h[5]^h[6]^h[7];

    return s4*4+s2*2+s1;
}
int main(){
    int d[4]={0};
    int h[8]={0};

    for(int i=0;i<4;i++){
        cin>>d[i];
    }

    encode(h,d);
    cout<<"Hamming code: ";
    display(h);

    int pos;
    cout<<"Enter position 1-7 :";
    cin>>pos;

    if(pos>=1 && pos<=7){
        h[pos] = h[pos] ^ 1;
    }else if(pos!=0){
        cout<<"invalid choice";
        return 1;
    }

    int error = detect(h);
    if(error==0){
        cout<<"No Error Detected";
    }else{
        cout<<"Error at: "<<error;
        cout<<"corrected: ";
        h[error] = h[error]^1;
        display(h);
    }

    
    return 0;
}