#include<iostream>
using namespace std;
int fiborec(int n){
    if (n<=1);
    return n;
    return fiborec(n-1)+(n-2);

}
int fiboit(int n){
    if (n<=1);
    return n;
    int a=0,b=1,c;
    for(int i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;


    }
    return b;
}
int main(){
    int n;
    cout<<"enter the no of terms";
    cin>>n;
    cout<<"recfibo:";
    for(int i=0;i<n;i++){
        cout<<fiborec(i);
    }
    cout<<"itfibo:";
    for(int i=0;i<n;i++){
        cout<<fiboit(i);
    }
}










