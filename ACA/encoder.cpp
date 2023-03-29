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

string ltrim(string s)
{
  int ind = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == ' ')
    {
      ind++;
    }
  }

  s = s.substr(ind);
  return s;
}

string enocde(string s)
{
  string ans;
  for (auto ch : s)
  {
    bitset<8> bits(ch);
    string temp = bits.to_string();
    ans += temp;
  }

  return ans;
}

string add(string input)
{
  string mystr = input.substr(0, input.find(" ", 0));
  input = input.substr(input.find(" ", 0), input[input.length() - 1]); // ab sirf operand bache
  // cout<< " mystr space se pehel "<<mystr<<endl;
  // cout<<" input ->"<<input<<endl;
  string bs = "";
  for (int i = 0; i < 10; i++) // as add m direct type hoga
  {
    // cout<<" 123"<<endl;
    if (type[i].first == mystr)
    {
      // cout<<" hi ji"<<endl;
      bs += type[i].second;
      bs += " ";
      // cout<<" hello ji"<<bs<<endl;
    }
  }
  // cout<<"bitstring function m ane k baad tak"<<bs<<endl;
  bs += "11111111";
  bs += " ";
  // cout<<"input pehle m--"<<input<<endl;
  input = ltrim(input);
  // cout<<"input baad m--"<<input<<endl;
  bs += enocde(input);
  // cout<<" bit string op k baad ---"<<bs<<endl;
  return bs;
}

string sub(string input)
{
  string mystr = input.substr(0, input.find(" ", 0));
  input = input.substr(input.find(" ", 0), input[input.length() - 1]); // ab sirf operand bache
  // cout<<mystr<<endl;
  string bs = "";
  for (int i = 0; i < 10; i++)
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }

  bs += "11111111";
  bs += " ";
  input = ltrim(input);
  bs += enocde(input);
  return bs;
}

string mul(string input)
{
  // next 1st . tak mode batayega
  string mystr = input.substr(0, input.find(".", 0)); // mode my str se compare karayenge
  string bs = "";                                     // return karne vali bit string

  for (int i = 0; i < 4; i++)
  {
    if (mode[i].first == mystr)
    {
      bs += mode[i].second;
      bs += " ";
    }
  }

  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
  mystr = input.substr(0, input.find(" ", 0));

  for (int i = 0; i < 10; i++)
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }

  input = input.substr(input.find(" ", 0), input[input.length() - 1]);
  bs += "11111111";
  bs += " ";
  input = ltrim(input);
  bs += enocde(input);

  return bs;
}

string mad(string input)
{
  // next 1st . tak mode batayega
  string mystr = input.substr(0, input.find(".", 0)); // mode my str se compare karayenge
  string bs = "";                                     // return karne vali bit string

  for (int i = 0; i < 4; i++)
  {
    if (mode[i].first == mystr)
    {
      bs += mode[i].second;
      bs += " ";
    }
  }

  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
  mystr = input.substr(0, input.find(" ", 0));

  for (int i = 0; i < 10; i++)
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }

  input = input.substr(input.find(" ", 0), input[input.length() - 1]);
  bs += "11111111";
  bs += " ";
  input = ltrim(input);
  bs += enocde(input);
  return bs;
}

string sad(string input) // jinme direct type hota hai
{
  string mystr = input.substr(0, input.find(" ", 0));
  input = input.substr(input.find(" ", 0), input[input.length() - 1]); // ab sirf operand bache
  string bs = "";
  for (int i = 0; i < 10; i++) // as add m direct type hoga
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }
  bs += "11111111";
  bs += " ";
  input = ltrim(input);
  bs += enocde(input);
  return bs;
}

string min(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(" ", 0));
  input = input.substr(input.find(" ", 0), input[input.length() - 1]); // ab sirf operand bache

  if (mystr[0] == 'a')
  {
    bs += "0";
    bs += " ";
  }
  else if (mystr[0] == 'b')
  {
    bs += "1";
    bs += " ";
  }

  for (int i = 0; i < 10; i++) // as add m direct type hoga
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }

  bs += "11111111";
  bs += " ";
  input = ltrim(input);
  bs += enocde(input);
  return bs;
  return bs;
}

string bfind(string input)
{
  string bs = "";
  if (input.find(".", 0)) // means shiftamt hai
  {
    string mystr = input.substr(0, input.find(".", 0));
    bs += "1011"; // for shiftamt
    bs += " ";

    input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
    mystr = input.substr(0, input.find(" ", 0));
    for (int i = 0; i < 10; i++)
    {
      if (type[i].first == mystr)
      {
        bs += type[i].second;
        bs += " ";
      }
    }
    input = input.substr(input.find(" ", 0), input[input.length() - 1]); // ab sirf operand bache

    bs += "11111111";
    bs += " ";
    input = ltrim(input);
    bs += enocde(input);
    return bs;
  }
  else
  {
    string mystr = input.substr(0, input.find(" ", 0));
    for (int i = 0; i < 10; i++)
    {
      if (type[i].first == mystr)
      {
        bs += type[i].second;
        bs += " ";
      }
    }
    input = input.substr(input.find(" ", 0), input[input.length() - 1]); // ab sirf operand bache

    bs += "11111111";
    bs += " ";
    input = ltrim(input);
    bs += enocde(input);
    return bs;
  }
}

string dp4a(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(".", 0));

  for (int i = 0; i < 10; i++) // as add m direct type hoga
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }

  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
  mystr = input.substr(0, input.find(" ", 0));
  for (int i = 0; i < 10; i++) // as add m direct type hoga
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }
  input = input.substr(input.find(" ", 0), input[input.length() - 1]); // ab sirf operand bache

  bs += "11111111";
  bs += " ";
  input = ltrim(input);
  bs += enocde(input);
  return bs;
}

string dp2a(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(".", 0)); // 1st . tak jo mila vo mode hoga
  for (int i = 0; i < 4; i++)
  {
    if (mode[i].first == mystr)
    {
      bs += mode[i].second;
      bs += " ";
    }
  }

  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
  mystr = input.substr(0, input.find(" ", 0));

  for (int i = 0; i < 10; i++) // as add m direct type hoga
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }

  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
  mystr = input.substr(0, input.find(" ", 0));
  for (int i = 0; i < 10; i++) // as add m direct type hoga
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }

  input = input.substr(input.find(" ", 0), input[input.length() - 1]); // ab sirf operand bache

  bs += "11111111";
  bs += " ";
  input = ltrim(input);
  bs += enocde(input);
  return bs;
}

// 19 categories hai --  MSB 5 bits
int main()
{

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

  mode[0] = {"hi", "000"};
  mode[1] = {"lo", "001"};
  mode[2] = {"wide", "010"};
  mode[3] = {"clamp", "011"};
  mode[4] = {"wrap", "100"};

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
  newfile.open("input.txt", ios::in);

  if (newfile.is_open())
  { // checking whether the file is open
    string tp1;
    while (getline(newfile, tp1))
    {                      // read data from file object and put it into string.
      cout << tp1 << "\n"; // print the data of the string
      string mystr;
      mystr = tp1.substr(0, tp1.find(".", 0));                       // 1st . tak
      tp1 = tp1.substr(tp1.find(".", 0) + 1, tp1[tp1.length() - 1]); // 1st . k baad ki string
      // cout<< mystr <<endl;
      for (int i = 0; i < 24; i++)
      {
        
        if (instruction[0][i].first == mystr)
        {
          // cout<<"here"<<endl;
          bitString += category[0].second;
          bitString += " ";

          bitString += instruction[0][i].second;
          bitString += " ";

          // string mystr1;
          // mystr1=tp1.substr(0, tp1.find(" ", 0));
          // cout<<" hello bitsstring ab tak ="<<bitString<<endl;
          if (mystr == "add")
          {
            bitString += add(tp1);
            bitString += " ";
          }
          else if (mystr == "sub")
          {
            bitString += sub(tp1);
            bitString += " ";
          }
          else if (mystr == "mul" || mystr == "mul24" || mystr == "szext" || mystr == "szext" || mystr == "bmsk")
          {
            bitString += mul(tp1);
            bitString += " ";
          }
          else if (mystr == "mad" || mystr == "mad24") // as mad m .sat ho sakta hai
          {
            bitString += mad(tp1);
            bitString += " ";
          }
          else if (mystr == "sad" || mystr == "div" || mystr == "rem" || mystr == "abs" || mystr == "neg" || mystr == "popc" || mystr == "clz" || mystr == "fns" || mystr == "brev" || mystr == "bfe" || mystr == "bfi") // dont have .sat
          {
            bitString += sad(tp1);
            bitString += " ";
          }
          else if (mystr == "min" || mystr == "max")
          {
            bitString += min(tp1);
            bitString += " ";
          }
          else if (mystr == "bfind")
          {
            bitString += bfind(tp1);
            bitString += " ";
          }
          else if (mystr == "dp4a")
          {
            bitString += dp4a(tp1);
            bitString += " ";
          }
          else if (mystr == "dp2a")
          {
            bitString += dp2a(tp1);
            bitString += " ";
          }
        }
      }

      // bitString += "\n";
      ofstream outfile;
      outfile.open("output.txt", ios::app);
      outfile << bitString << endl;
      bitString = "";
      // outfile << "hi hi" <<"\n" << endl;
      outfile.close();
    }

    //  cout <<" answer ===== "<< bitString << endl;
    

  }

  // map for types

  return 0;
}