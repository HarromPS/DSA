#include<bits/stdc++.h>

void pattern1(){
    int n;
    std::cin>>n;
    std::vector<int> arr;
    for(int i=0;i<n;i++){
        int num;
        std::cin>>num;
        arr.push_back(num);
    }

    for(auto it:arr) std::cout<<it<<" ";
    std::cout<<std::endl;
}

void pattern2(){
    std::string s;

    // get the current input stream and store into a string
    getline(std::cin, s);
    std::vector<int> arr;

    // treat strings as input and output streams
    std::stringstream ss(s);

    // read the string and extract numbers 
    std::string nums;
    while(getline(ss, nums,',')){   // get comma sperated values
        int temp = stoi(nums);  // convert string to number
        arr.push_back(temp);
    }

    for(auto it:arr) std::cout<<it<<" ";
    std::cout<<"\n";
}

void pattern3(){
    int n;
    std::cin>>n;
    std::cin.ignore();  // it is used between 2 inputs

    std::string s;
    getline(std::cin, s);

    std::cout<<n<<"\n"<<s<<"\n";
}

int main(){
    // n as arrray size and an array  
    // pattern1();

    // input as string as comma or space seperated 
    // pattern2();

    // take input as integer and string with spaces
    pattern3();
}


