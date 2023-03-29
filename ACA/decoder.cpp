#include <unordered_map>
#include <vector>
#include <utility>
#include <iostream>
#include <string>
#include <fstream>
#include <bitset>
using namespace std;

unordered_map<int, pair<string, string>> category;
unordered_map<int, pair<string, string>> type;
vector<vector<pair<string, string>>> instruction;
unordered_map<int, pair<string, string>> mode;

// functions

// decode
string decode(string &s){
    // cout<<s<<endl;
    long len = s.size();
    // cout<<"decode-len"<<len<<endl;
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
string add(string input)
{
    // cout<<" input f m 1 1"<<endl;
    // cout<<input<<endl;
    string bs = "";
    // type hoga next bits
    string mystr = input.substr(0, input.find(" ", 0));
    // cout<<" input f m"<<endl;
    for (int i = 0; i < 10; i++)
    {
        if (type[i].second == mystr)
        {
            
            bs += type[i].first;
            bs += " ";
            // cout<<" bs"<<bs<<endl;
            
        }
    }
    input = input.substr(input.find(" ", 0) + 1); // ab operand hoga
    input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad
    // cout<<" input f m"<<endl;
    // cout<<"inp="<<input<<endl;
    long n = input.size();
    if(input.back() == ' '){
        input.pop_back();
    }
    // cout<<" ->"<<decode(input)<<endl;
    bs += decode(input);
    return bs;
}

string mul(string input)
{
    string bs = "";
    // agla bit mod hoga
    string mystr = input.substr(0, input.find(" ", 0));

    for (int i = 0; i < 4; i++)
    {
        if (mode[i].second == mystr)
        {
            bs += mode[i].first;
            bs += " ";
        }
    }
    // iske baad type hoga
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
    mystr = input.substr(0, input.find(" ", 0)); // ye type hai
    for (int i = 0; i < 10; i++)
    {
        if (type[i].second == mystr)
        {
            bs += type[i].first;
            bs += " ";
        }
    }

    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]); // ab operand hoga
    input = input.substr(input.find("0", 0) + 1, input[input.length() - 1]); // delimeter hatane k baad
    cout<<"len of op"<<input<<endl;
    bs += decode(input);
    return bs;
}

string mad(string input)
{
    string bs = "";
    // agla bit mod hoga
    string mystr = input.substr(0, input.find(" ", 0)); // 1st space tak mod

    for (int i = 0; i < 4; i++)
    {
        if (mode[i].second == mystr)
        {
            bs += mode[i].first;
            bs += " ";
        }
    }

    // iske baad type hoga
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
    mystr = input.substr(0, input.find(" ", 0)); // ye type hai
    for (int i = 0; i < 10; i++)
    {
        if (type[i].second == mystr)
        {
            bs += type[i].first;
            bs += " ";
        }
    }

    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]); // ab operand hoga
    input = input.substr(input.find("0", 0) + 1, input[input.length() - 1]); // delimeter hatane k baad
    bs += decode(input);
    return bs;
}

string sad(string input)
{
    string bs = "";
    // type hoga next bits
    string mystr = input.substr(0, input.find(" ", 0));
    for (int i = 0; i < 10; i++)
    {
        if (type[i].second == mystr)
        {
            bs += type[i].first;
            bs += " ";
        }
    }
    // operand

    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]); // ab operand hoga
    input = input.substr(input.find("0", 0) + 1, input[input.length() - 1]); // delimeter hatane k baad
    bs += decode(input);
    return bs;
}

string min(string input)
{
    string bs = "";
    // type hoga next bits
    // string mystr = input.substr(0, input.find(" ", 0)); // ye a / b batayega

    if (input[0] == '0')
    {
        bs += "a";
        bs += " ";
    }
    else if (input[0] == '1')
    {
        bs += "b";
        bs += " ";
    }

    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]); // a b k baad vala
    string mystr = input.substr(0, input.find(" ", 0));
    for (int i = 0; i < 10; i++)
    {
        if (type[i].second == mystr)
        {
            bs += type[i].first;
            bs += " ";
        }
    }
    // operand

    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]); // ab operand hoga
    input = input.substr(input.find("0", 0) + 1, input[input.length() - 1]); // delimeter hatane k baad
    bs += decode(input);
    return bs;
}

string bfind(string input)
{
    string bs = "";
    string mystr = input.substr(0, input.find(" ", 0));
    if (mystr == "1011") // tab ye shiftamt hai
    {
        bs += "shiftamt";
        bs += " ";

        input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
        mystr = input.substr(0, input.find(" ", 0)); // ye type hoga
        for (int i = 0; i < 10; i++)
        {
            if (type[i].second == mystr)
            {
                bs += type[i].first;
                bs += " ";
            }
        }
    }
    else
    {                                                // shiftamt nhi hai to sidha type hai
        mystr = input.substr(0, input.find(" ", 0)); // ye type hoga
        for (int i = 0; i < 10; i++)
        {
            if (type[i].second == mystr)
            {
                bs += type[i].first;
                bs += " ";
            }
        }
    }
    // operand

    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]); // ab operand hoga
    input = input.substr(input.find("0", 0) + 1, input[input.length() - 1]); // delimeter hatane k baad
    bs += decode(input);
    return bs;
}

string dp4a(string input)
{
    string bs = "";
    string mystr = input.substr(0, input.find(" ", 0)); // 1st type
    for (int i = 0; i < 10; i++)
    {
        if (type[i].second == mystr)
        {
            bs += type[i].first;
            bs += " ";
        }
    }
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
    mystr = input.substr(0, input.find(" ", 0));
    for (int i = 0; i < 10; i++)
    {
        if (type[i].second == mystr)
        {
            bs += type[i].first;
            bs += " ";
        }
    }

    // operand

    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]); // ab operand hoga
    input = input.substr(input.find("0", 0) + 1, input[input.length() - 1]); // delimeter hatane k baad
    bs += decode(input);
    return bs;
}

string dp2a(string input)
{
    string bs = "";
    string mystr = input.substr(0, input.find(" ", 0)); // mod
    for (int i = 0; i < 4; i++)
    {
        if (mode[i].second == mystr)
        {
            bs += mode[i].first;
            bs += " ";
        }
    }

    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
    mystr = input.substr(0, input.find(" ", 0));
    for (int i = 0; i < 10; i++)
    {
        if (type[i].second == mystr)
        {
            bs += type[i].first;
            bs += " ";
        }
    }
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
    mystr = input.substr(0, input.find(" ", 0));
    for (int i = 0; i < 10; i++)
    {
        if (type[i].second == mystr)
        {
            bs += type[i].first;
            bs += " ";
        }
    }

    // operand

    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]); // ab operand hoga
    input = input.substr(input.find("0", 0) + 1, input[input.length() - 1]); // delimeter hatane k baad
    bs += decode(input);
    return bs;
}

int main()
{
    // category
    category[0] = {"Integer Arithmetic", "00000"};
    category[1] = {"Extended-Precision Integer Arithmetic", "00001"};
    category[2] = {"Floating Point", "00010"};
    category[3] = {"Half Precision Floating-Point", "00011"};
    category[4] = {"Comparison & Selection", "00100"};
    category[5] = {"Half Precision Comparison", "00101"};
    category[6] = {"Logic & Shift", "00110"};
    category[7] = {"Data Movement & Conversion", "00111"};
    category[8] = {"Texture", "01000"};
    category[9] = {"Surface", "01001"};
    category[10] = {"Control Flow", "01010"};
    category[11] = {"Parallel Sync & Comm", "01011"};
    category[12] = {"Wrap-level Matrix Multy-Accumulation", "01100"};
    category[13] = {"Async Wargroup level Matrix Multy-Accumulation", "01101"};
    category[14] = {"Stack Manipulation", "01110"};
    category[15] = {"Video", "01111"};
    category[16] = {"Scalar Video", "10000"};
    category[17] = {"SIMD", "10001"};
    category[18] = {"Miscellaneous", "10010"};

    // type
    type[0] = {"u16", "0000"};
    type[1] = {"u32", "0001"};
    type[2] = {"u64", "0010"};
    type[3] = {"s16", "0011"};
    type[4] = {"s32", "0100"};
    type[5] = {"s64", "0101"};
    type[6] = {"u16x2", "0110"};
    type[7] = {"s16x2", "0111"};
    type[8] = {"b32", "1000"};
    type[9] = {"b64", "1001"};

    // mod
    mode[0] = {"hi", "000"};
    mode[1] = {"lo", "001"};
    mode[2] = {"wide", "010"};
    mode[3] = {"clamp", "011"};
    mode[4] = {"wrap", "100"};

    // arithematic instructions
    vector<pair<string, string>> temp;
    temp.push_back(make_pair("add", "00000"));
    temp.push_back(make_pair("sub", "00001"));
    temp.push_back(make_pair("mul", "00010"));
    temp.push_back(make_pair("mad", "00011"));

    temp.push_back(make_pair("mul24", "00100"));
    temp.push_back(make_pair("mad24", "00101"));
    temp.push_back(make_pair("sad", "00110"));
    temp.push_back(make_pair("div", "00111"));

    temp.push_back(make_pair("rem", "01000"));
    temp.push_back(make_pair("abs", "01001"));
    temp.push_back(make_pair("neg", "01010"));
    temp.push_back(make_pair("min", "01011"));

    temp.push_back(make_pair("max", "01100"));
    temp.push_back(make_pair("popc", "01101"));
    temp.push_back(make_pair("clz", "01110"));
    temp.push_back(make_pair("bfind", "01111"));

    temp.push_back(make_pair("fns", "10000"));
    temp.push_back(make_pair("brev", "10001"));
    temp.push_back(make_pair("bfe", "10010"));
    temp.push_back(make_pair("bfi", "10011"));

    temp.push_back(make_pair("szext", "10100"));
    temp.push_back(make_pair("bmsk", "10101"));
    temp.push_back(make_pair("dp4a", "10110"));
    temp.push_back(make_pair("dp2a", "10111"));

    instruction.push_back(temp);

    fstream newfile;
    string bitString = "";
    newfile.open("output.txt", ios::in);

    if (newfile.is_open())
    { // checking whether the file is open
        string tp1;
        while (getline(newfile, tp1))
        {
            string charString;   // read data from file object and put it into string.
            // cout << tp1 << "\n"; // print the data of the string

            string mystr;
            // cout<<" strt m tp 1 hai $$$$$$$"<<tp1<<endl;
            mystr = tp1.substr(0, tp1.find(" ", 0)); // ye humko category dega
            
            tp1 = tp1.substr(tp1.find(" ", 0) + 1); // category batana k baad
            mystr = tp1.substr(0, tp1.find(" ", 0));                       // ye humko add, mul,sub batayega
            for (int i = 0; i < 24; i++)
            {
                if (instruction[0][i].second == mystr)
                {
                    // instruction[0][i] is my instruction
                    charString += instruction[0][i].first;
                    charString += " ";
                    // cout<<"char string 1="<<charString;
                    tp1 = tp1.substr(tp1.find(" ", 0) + 1); // after instruction i.e., mod,type
                    if (instruction[0][i].first == "add" || instruction[0][i].first == "sub")
                    {
                        // cout<<" f m jana"<<endl;
                        // cout<<"tp 1 hai -------"<<tp1<<endl;
                        charString += add(tp1);
                        charString += " ";
                        // cout<<" f se ana"<<endl;
                    }
                    else if (instruction[0][i].first == "mul" || instruction[0][i].first == "mul24" || instruction[0][i].first == "szext" || instruction[0][i].first == "szext" || instruction[0][i].first == "bmsk")
                    {
                        charString += add(tp1);
                        charString += " ";
                    }
                    else if (instruction[0][i].first == "mad" || instruction[0][i].first == "mad24") // as mad m .sat ho sakta hai
                    {
                        charString += mad(tp1);
                        charString += " ";
                    }
                    else if (instruction[0][i].first == "sad" || instruction[0][i].first == "div" || instruction[0][i].first == "rem" || instruction[0][i].first == "abs" || instruction[0][i].first == "neg" || instruction[0][i].first == "popc" || instruction[0][i].first == "clz" || instruction[0][i].first == "fns" || instruction[0][i].first == "brev" || instruction[0][i].first == "bfe" || instruction[0][i].first == "bfi") // dont have .sat
                    {
                        charString += sad(tp1);
                        charString += " ";
                    }
                    else if (instruction[0][i].first == "min" || instruction[0][i].first == "max")
                    {
                        charString += min(tp1);
                        charString += " ";
                    }
                    else if (instruction[0][i].first == "bfind")
                    {
                        charString += bfind(tp1);
                        charString += " ";
                    }
                    else if (instruction[0][i].first == "dp4a")
                    {
                        charString += dp4a(tp1);
                        charString += " ";
                    }
                    else if (instruction[0][i].first == "dp2a")
                    {
                        charString += dp2a(tp1);
                        charString += " ";
                    }
                }
            }
            cout << " bit string =" << charString << endl;
        }
        return 0;
    }
}