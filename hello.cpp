#include<iostream>
#include <vector>
#include <string>

using namespace std;
int main(){
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
    
    std::cout<<"Hello,this is a test file\n please input an number:";
    char var=0;
    std::cin>>var;
    std::cout<<var-'a'<<std::endl;
    std::cout<<"hello once again"<<std::endl;
    return 0;
}