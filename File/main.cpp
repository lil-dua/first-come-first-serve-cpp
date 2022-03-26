#include <iostream>
using namespace std;
#include <fstream>
int main(){
    ifstream file;
    file.open("E:\\C C++ CodeFile\\File\\input.txt");

    int a[20];
    int n;
    file>>n;
    cout<<"Gia tri cua n: "<<n<<endl;
    for(int i = 0; i<n ; i++){
        file>>a[i];
    }
    for(int i = 0;i<n; i++){
        cout<<"Gia tri thu "<<i+1<<" : "<<a[i]<<endl;
    }

    file.close();
    return 0;
}