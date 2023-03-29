#include <iostream>
#include<algorithm>
#include <bitset>

using namespace std;


string encode(string s){
    string ans;
    for(auto ch : s){
        bitset<8> bits(ch);
        string temp = bits.to_string();
        ans += temp;
        
    }
    
    return ans;
}


string decode(string s){
    // cout<<s<<endl;
    long len = s.size();
    // cout<<len<<endl;
    string ans = "";
    for(long i = 0;i<len;i+=8){
        string bits = "";
        for(int j = 0;j<8;j++){
            bits += s[i+j];
        }
        char ch = static_cast<char>(std::bitset<8>(bits).to_ulong());
        // cout<<ch<<endl;
        ans += ch;
    }
    return ans;
    
}


string ltrim(string s){
    int ind = 0;
    for(int i = 0;i<s.size();i++){
        if(s[i] == ' '){
            ind++;
        }
    }

    s = s.substr(ind);
    return s;
}

int main() {
    string s = "011000110010110001100001001011000110001000111011";
    string ans = decode(s);
    cout<<ans<<endl;
    return 0;
}
