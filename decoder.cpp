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
vector<pair<string, string>> scale;
vector<pair<string, string>> op2;
vector<pair<string, string>> cmp;
vector<pair<string, string>> boolOp;
vector<pair<string, string>> rnd;
vector<pair<string, string>> op;
vector<pair<string, string>> parallel;
unordered_map<int, pair<string, string>> level;
unordered_map<int, pair<string, string>> prefetch_size;
unordered_map<int, pair<string, string>> cache_hint;
unordered_map<int, pair<string, string>> multicast;
unordered_map<int, pair<string, string>> completion_mech;
unordered_map<int, pair<string, string>> red_op;
unordered_map<int, pair<string, string>> load_mode;
unordered_map<int, pair<string, string>> dim;
unordered_map<int, pair<string, string>> space;
unordered_map<int, pair<string, string>> ss;
unordered_map<int, pair<string, string>> cp_ops;
unordered_map<int, pair<string, string>> eviction_priority_l2;
unordered_map<int, pair<string, string>> tensor;
unordered_map<int, pair<string, string>> eviction_priority;
unordered_map<int, pair<string, string>> vec;
unordered_map<int, pair<string, string>> scope;
unordered_map<int, pair<string, string>> qualifier;
unordered_map<int, pair<string, string>> cop;

// functions

// decode

// string decode_string(string s){
//     int  ix = 0;
// 	for(ix = 0;ix<s.size();ix++){
// 		if(s[ix] == ' '){
// 			ix++;
// 		}
// 		else{
// 			break;
// 		}
// 	}
// 	s = s.substr(ix);

// 	while(s.back() == ' '){
// 		s.pop_back();
// 	}

//     if(s=="")

// }

// string decode(string &s){
//     cout<<s<<endl;
//     long len = s.size();
//     // cout<<"decode-len"<<len<<endl;
//     string ans = "";
//     string temp = "";

//     for(auto ch : s){
//         if(ch == ' '){
//             ans+=decode_string(temp);
//             temp = "";
//         }
//         else if(temp == "11111111"){
//             break;
//         }
//         else{
//             temp += ch;
//         }
//     }

// }

string ltrim2(string s)
{
  int ind = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == ' ')
    {
      ind++;
    }
  }
  ind=max(0,ind-1);
  s = s.substr(ind);
  cout<<"s.size()"<<s.size()/8<<endl;
  cout<<"s is "<<s<<endl;
  return s;
}

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

string decode(string &s)
{

  while (s.back() == ' ')
  {
    s.pop_back();
  }
  // cout<<s<<endl;
  long long len = s.size();
  // cout<<"decode-len"<<len<<endl;
  string ans = ""; 
  int cnt = 0;
  long long i = 0;
  for ( i = 0; i < len; i += 8)
  {
    
    string bits = "";
    for (long long int j = 0; j < 8; j++)
    { 
      bits += s[i + j];
    }
    
    char ch = static_cast<char>(std::bitset<8>(bits).to_ulong());
    
    ans += ch;

    
    
  }
  // cout<<i<<endl;
  // cout<<cnt<<endl;
  return ans;
}

//
string add(string input)
{
  cout<<" input f m 1 1"<<endl;
  cout<<input<<endl;
  string bs = "";
  // type hoga next bits
  string mystr = input.substr(0, input.find(" ", 0));
  cout<<mystr<<endl;
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
  if (input.back() == ' ')
  {
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
  input = input.substr(input.find(" ", 0) + 1);
  mystr = input.substr(0, input.find(" ", 0)); // ye type hai
  for (int i = 0; i < 10; i++)
  {
    if (type[i].second == mystr)
    {
      bs += type[i].first;
      bs += " ";
    }
  }

  input = input.substr(input.find(" ", 0) + 1); // ab operand hoga
  input = input.substr(input.find("0", 0) + 1); // delimeter hatane k baad
  cout << "len of op" << input << endl;
  bs += decode(input);
  return bs;
}

string mad(string input)
{
  string bs = "";
  // agla bit mod hoga
 
  
  string mystr = input.substr(0, input.find(" ", 0)); // 1st space tak mod
  input = input.substr(input.find(" ", 0) + 1);
cout<<"mystr ------"<<mystr<<endl;
  for (int i = 0; i < 4; i++)
  {
    if (mode[i].second == mystr)
    {
      
      bs += mode[i].first;
      bs += " ";
    }
  }
  cout<<"bs **** "<<bs<<endl;
  cout<<"input fot type   "<<input<<endl;
  // iske baad type hoga
   mystr = input.substr(0, input.find(" ", 0)); // ye type hai
  input = input.substr(input.find(" ", 0) + 1);
 cout<<"mystr for type $$$$$$"<<mystr<<endl;
cout<<"size"<<mystr.size()<<endl;
  for (int i = 0; i < 12; i++)
  {
    cout<<" ##"<<type[i].second<<"  "<<type[i].first<<endl;
    if (mystr == type[i].second  )
    {
      cout<<"hello"<<endl;
      bs += type[i].first;
      bs += " ";
    }
  }
  cout<<"type k baad bs uip ___"<<bs<<endl;

  input = input.substr(input.find(" ", 0) + 1); // ab operand hoga
  //input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad
  cout<<"operand ----"<<input<<endl;
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

  input = input.substr(input.find(" ", 0) + 1); // ab operand hoga
  input = input.substr(input.find("0", 0) + 1); // delimeter hatane k baad
  bs += decode(input);
  return bs;
}

string min(string input)
{
  string bs = "";
  // type hoga next bits
  // string mystr = input.substr(0, input.find(" ", 0)); // ye a / b batayega
cout<<" yaha bhi ana hoga "<<endl;
  if (input.substr(0, input.find(" ", 0)) == "0")
  {
    bs += "a";
    bs += " ";
  }
  else if (input.substr(0, input.find(" ", 0)) == "1")
  {
    bs += "b";
    bs += " ";
  }

cout<<" bs ===="<<bs<<endl;
cout<<" yes ye s"<<endl;
  string mystr = input.substr(0, input.find(" ", 0));
  input = input.substr(input.find(" ", 0) + 1); // a b k baad vala
  
  for (int i = 0; i < 10; i++)
  {
    if (type[i].second == mystr)
    {
      bs += type[i].first;
      bs += " ";
    }
  }
  // operand

  input = input.substr(input.find(" ", 0) + 1); // ab operand hoga
  //input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad
  cout<<"input going ---"<<input<<endl;
  bs += decode(input);
  cout<<" answer aa gy h "<<endl;
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

    input = input.substr(input.find(" ", 0) + 1);
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
  {                                              // shiftamt nhi hai to sidha type hai
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

  input = input.substr(input.find(" ", 0) + 1); // ab operand hoga
  input = input.substr(input.find("0", 0) + 1); // delimeter hatane k baad
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
  input = input.substr(input.find(" ", 0) + 1);
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

  input = input.substr(input.find(" ", 0) + 1); // ab operand hoga
  input = input.substr(input.find("0", 0) + 1); // delimeter hatane k baad
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

  input = input.substr(input.find(" ", 0) + 1);
  mystr = input.substr(0, input.find(" ", 0));
  for (int i = 0; i < 10; i++)
  {
    if (type[i].second == mystr)
    {
      bs += type[i].first;
      bs += " ";
    }
  }
  input = input.substr(input.find(" ", 0) + 1);
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

  input = input.substr(input.find(" ", 0) + 1); // ab operand hoga
  input = input.substr(input.find("0", 0) + 1); // delimeter hatane k baad
  bs += decode(input);
  return bs;
}

// half precision comp
string HPSet(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(" ", 0)); // 1st _ cmp hoga
  input = input.substr(input.find(" ", 0) + 1);       // 1st _ k baad

  // mystr == cmp
  for (int i = 0; i < 17; i++)
  {
    if (mystr == cmp[i].second)
    {
      bs += cmp[i].first;
      bs += " ";
    }
  }

  mystr = input.substr(0, input.find(" ", 0));  // 2nd _ bool op / type hoga
  input = input.substr(input.find(" ", 0) + 1); // 2nd _ k baad

  // agar to boolOP hai
  for (int i = 0; i < 3; i++)
  {
    if (mystr == boolOp[i].second)
    {
      bs += boolOp[i].first;
      bs += " ";

      // 2 baar type
      mystr = input.substr(0, input.find(" ", 0));  // 1st type
      input = input.substr(input.find(" ", 0) + 1); // 1st type k baad
      for (int i = 0; i < 10; i++)
      {
        if (type[i].second == mystr)
        {
          bs += type[i].first;
          bs += " ";
        }
      }

      mystr = input.substr(0, input.find(" ", 0));  // 2nd type
      input = input.substr(input.find(" ", 0) + 1); // 2nd type k baad  ab delimeter aya hoga
      for (int i = 0; i < 10; i++)
      {
        if (type[i].second == mystr)
        {
          bs += type[i].first;
          bs += " ";
        }
      }

      input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad
      long n = input.size();
      if (input.back() == ' ')
      {
        input.pop_back();
      }
      // cout<<" ->"<<decode(input)<<endl;
      bs += decode(input);
      return bs;
    }
  }

  // agar nhi hai
  for (int i = 0; i < 10; i++)
  {
    if (type[i].second == mystr)
    {
      bs += type[i].first;
      bs += " ";
    }
  }

  mystr = input.substr(0, input.find(" ", 0));  // 2nd type
  input = input.substr(input.find(" ", 0) + 1); // 2nd type k baad  ab delimeter aya hoga
  for (int i = 0; i < 10; i++)
  {
    if (type[i].second == mystr)
    {
      bs += type[i].first;
      bs += " ";
    }
  }

  input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad
  long n = input.size();
  if (input.back() == ' ')
  {
    input.pop_back();
  }
  // cout<<" ->"<<decode(input)<<endl;
  bs += decode(input);
  return bs;
}

string HPSetp(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(" ", 0)); // 1st _ cmp hoga
  input = input.substr(input.find(" ", 0) + 1);       // 1st _ k baad
cout<<" halla bol;"<<endl;
cout<<"mystr h ? "<<mystr<<endl;
  // mystr == cmp
  for (int i = 0; i < 17; i++)
  {
    //cout<<"jusdbghc"<<endl;
    if (mystr == cmp[i].second)
    {
      cout<<"cmp k liye"<<endl;
      bs += cmp[i].first;
      bs += ".";
    }
  }

  mystr = input.substr(0, input.find(" ", 0));  // 2nd _ bool op / type hoga
  input = input.substr(input.find(" ", 0) + 1); // 2nd _ k baad

  // agar to boolOP hai
  for (int i = 0; i < 3; i++)
  {
    if (mystr == boolOp[i].second)
    {
      bs += boolOp[i].first;
      bs += ".";

      // 1 baar type
      mystr = input.substr(0, input.find(" ", 0));  // 1st type
      input = input.substr(input.find(" ", 0) + 1); // 1st type k baad
      for (int i = 0; i < 10; i++)
      {
        if (type[i].second == mystr)
        {
          bs += type[i].first;
          bs += " ";
        }
      }

      input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad
      long n = input.size();
      if (input.back() == ' ')
      {
        input.pop_back();
      }
      // cout<<" ->"<<decode(input)<<endl;
      bs += decode(input);
      return bs;
    }
  }

  // agar nhi hai

  // mystr type hoga
  for (int i = 0; i < 10; i++)
  {
    if (type[i].second == mystr)
    {
      bs += type[i].first;
      bs += " ";
    }
  }
  cout<<"type k baad"<<endl;
  input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad
  long n = input.size();
  if (input.back() == ' ')
  {
    input.pop_back();
  }
  // cout<<" ->"<<decode(input)<<endl;
  cout<<"input"<<input<<endl;
  bs += decode(input);
  return bs;
}


string mov(string input)
{
    // cout<<" input f m 1 1"<<endl;
    // cout<<input<<endl;
    string bs = "";
    // type hoga next bits
    string mystr = input.substr(0, input.find(" ", 0));
    // cout<<" input f m"<<endl;
    for (int i = 0; i < 20; i++)
    {
        if (type[i].second == mystr)
        {
            
            bs += type[i].first;
            bs += "   ";
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

string shfl(string input)
{
    // cout<<" input f m 1 1"<<endl;
    // cout<<input<<endl;
    string bs = "";
    // type hoga next bits
    string mystr = input.substr(0, input.find(" ", 0));
    if(mystr=="1")
    {
        bs+="sync";
        bs+=" ";
    }
     mystr = input.substr(0, input.find(" ", 0));
    // cout<<" input f m"<<endl;
    for (int i = 0; i < 20; i++)
    {
        if (type[i].second == mystr)
        {
            
            bs += type[i].first;
            bs += ".";
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

string prmt(string input)
{
    string bs = "";
    string mystr = input.substr(0, input.find(" ", 0)); // mod
     for (int i = 0; i < 20; i++)
    {
        if (type[i].second == mystr)
        {
            bs += type[i].first;
            bs += " ";
        }
    }
    
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
    mystr = input.substr(0, input.find(" ", 0));
    for (int i = 0; i < 15; i++)
    {
        if (mode[i].second == mystr)
        {
            bs += mode[i].first;
            bs += " ";
        }
    }
   
    // operand

    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]); // ab operand hoga
    input = input.substr(input.find("0", 0) + 1, input[input.length() - 1]); // delimeter hatane k baad
    bs += decode(input);
    return bs;
}

void tokenize(string s, string del,vector<string> &output)
{
    int start, end = -1*del.size();
    do {
        start = end + del.size();
        end = s.find(del, start);
        output.push_back(s.substr(start, end - start));
    } while (end != -1);
}


// string ld(string input)
// {
//     cout<<"inside load"<<endl;
//     //cout<<"input is "<<input<<endl;
//     vector<string> Separeted;
//     tokenize(input,"11111111",Separeted);
//     string opcode=Separeted[0];
//     string operand=Separeted[1];
//     cout<<"operand is "<<operand<<endl;
//     cout<<"opcpde is "<<opcode<<endl;
//     string bs="";
//     vector<string> inputString;
//     tokenize(opcode," ",inputString);
//     //cout<<"input string is "<<endl;
//     for(int i=0;i<inputString.size();i++)
//     {
//       //cout<<"lst here"<<endl;
//       for (int j = 0; j <5; j++)
//       {
//         if (qualifier[j].second == inputString[i])
//         {
//           bs += qualifier[j].first;
//           bs += ".";
//         }
//       }

//       for (int j = 0; j <8; j++)
//       {
//         if (ss[j].second == inputString[i])
//         {
//           bs += ss[j].first;
//           bs += ".";
//         }
//       }

//        for (int j = 0; j <7; j++)
//       {
//         if (cop[j].second == inputString[i])
//         {
//           bs += cop[j].first;
//           bs += " ";
//         }
//       }

//       for (int j = 0; j <5; j++)
//       {
//         if (eviction_priority[j].second == inputString[i])
//         {
//           cout<<"2345"<<endl;
//           bs += eviction_priority[j].first;
//           bs += ".";
//         }
//       }

   
//      if (cache_hint[0].second == inputString[i])
//      {
//        cout<<"2375"<<endl;
//           bs += cache_hint[0].first;
//           bs += ".";
//      }

//      for (int j = 0; j <3; j++)
//       {
         
//         if (prefetch_size[j].second == inputString[i])
//         {
//           cout<<"2845"<<endl;
//           bs += prefetch_size[j].first;
//           bs += ".";
//         }
//       }
//       for (int j = 0; j <2; j++)
//       {
//         if (vec[j].second == inputString[i])
//         {
//           bs += vec[j].first;
//           bs += ".";
//         }
//        }

//      for (int j = 0; j <20; j++)
//      {
//        if (type[j].second == inputString[i])
//         {
//          bs += type[j].first;
//          bs += " ";
//         }
//      }

//     }
//     //cout<<"here is last"<<endl;
//     cout<<"operand is "<<operand<<endl;
//     //cout<<"bs is "<<bs<<endl;
//     while(bs.back() == '.')
//     {
//       bs.pop_back();
//     }
//     cout<<"bs kya hai 00000"<<bs<<endl;
//     operand=ltrim2(operand);
//     cout<<"operand baad m is "<<operand<<endl;
//     bs += decode(operand);
//     cout<<"decode operand funct ==="<<decode(operand);
//     //cout<<"bs is "<<bs<<endl;
//     return bs;  
// }



string ld(string input)
{
    //cout<<"inside load"<<endl;
    //cout<<"input is "<<input<<endl;
    vector<string> Separeted;
    tokenize(input,"11111111",Separeted);
    string opcode=Separeted[0];
    string operand=Separeted[1];
    //cout<<"operand is "<<operand<<endl;
    //cout<<"opcpde is "<<opcode<<endl;
    string bs="";
    vector<string> inputString;
    tokenize(opcode," ",inputString);
    //cout<<"input string is "<<endl;
    for(int i=0;i<inputString.size();i++)
    {
      cout<<"input is @@@@@"<<inputString[i]<<"     "<<inputString[i].size()<<endl;
      if(inputString[i].size() == 0)
      {
        break;
      }
      for (int j = 0; j <5; j++)
      {
        if (qualifier[j].second == inputString[i])
        {
          cout<<"1"<<endl;
          bs += qualifier[j].first;
          bs += ".";
        }
      }
      cout<<"bs is 1"<<bs<<endl;

      for (int j = 0; j <8; j++)
      {
        if (ss[j].second == inputString[i])   //param
        {
          cout<<"2"<<endl;
          bs += ss[j].first;
          bs += ".";
        }
      }
      cout<<"bs is 2"<<bs<<endl;

       for (int j = 0; j <7; j++)
      {
        if (cop[j].second == inputString[i])
        {
          cout<<"3"<<endl;
          bs += cop[j].first;
          bs += ".";
        }
      }
      cout<<"bs is 3"<<bs<<endl;

      for (int j = 0; j <5; j++)
      {
        if (eviction_priority[j].second == inputString[i])
        {
          cout<<"4"<<endl;
          bs += eviction_priority[j].first;
          bs += ".";
        }
      }
      cout<<"bs is 4"<<bs<<endl;

   
     if (cache_hint[0].second == inputString[i])
     {
      cout<<"5"<<endl;
          bs += cache_hint[0].first;
          bs += ".";
     }
     cout<<"bs is 5"<<bs<<endl;

     for (int j = 0; j <3; j++)
      {
        if (prefetch_size[j].second == inputString[i])
        {
          cout<<"6"<<endl;
          bs += prefetch_size[j].first;
          bs += ".";
        }
      }
      cout<<"bs is 6"<<bs<<endl;
      for (int j = 0; j <2; j++)
      {
        if (vec[j].second == inputString[i])
        {
          cout<<"7"<<endl;
          bs += vec[j].first;
          bs += ".";
        }
       }
       cout<<"bs is 7"<<bs<<endl;

     for (int j = 0; j <20; j++)
     {
       if (type[j].second == inputString[i])
        {
          cout<<"8"<<endl;
         bs += type[j].first;
         bs += " ";
        }
     }
     cout<<"bs is 8"<<bs<<endl;
     

    }
    
    cout<<"bs is "<<bs<<endl;
    operand=ltrim2(operand);
    bs += decode(operand);
    cout<<"-------+++++++"<<bs<<endl;
    //cout<<"bs is "<<bs<<endl;
    return bs;  
}

string ldu(string input)
{
    //separate opcode and operand first
  vector<string> Separeted;
  tokenize(input,"11111111",Separeted);
  string opcode=Separeted[0];
  string operand=Separeted[1];
  vector<string> inputString;
  tokenize(opcode," ",inputString);
  string bs="";
  for(int i=0;i<inputString.size();i++)
  {
    if(inputString[i].size() == 0)
      {
        break;
      }
   for (int j = 0; j <7; j++)
   {
        if (ss[j].second == inputString[i])
        {
          bs += ss[j].first;
          bs += ".";
        }
   }

   for (int j = 0; j <2; j++)
      {
        if (vec[j].second == inputString[i])
        {
          bs += vec[j].first;
          bs += ".";
        }
       }

     for (int j = 0; j <20; j++)
     {
       if (type[j].second == inputString[i])
        {
         bs += type[j].first;
         bs += ".";
        }
     }

  }
 
  operand = ltrim2(operand);
  bs += decode(operand);
  return bs;
}

string st(string input)
{
    vector<string> Separeted;
    tokenize(input,"11111111",Separeted);
    string opcode=Separeted[0];
    string operand=Separeted[1];
    string bs="";
    vector<string> inputString;
    tokenize(opcode," ",inputString);
    for(int i=0;i<inputString.size();i++)
    {
      if(inputString[i].size() == 0)
      {
        break;
      }
      for (int j = 0; j <5; j++)
      {
        if (qualifier[j].second == inputString[i])
        {
          bs += qualifier[j].first;
          bs += ".";
        }
      }

      for (int j = 0; j <4; j++)
      {
        if (scope[j].first == inputString[i])
        {
          bs += scope[j].second;
          bs += ".";
        }
      }

      for (int j = 0; j <8; j++)
      {
        if (ss[j].second == inputString[i])
        {
          bs += ss[j].first;
          bs += ".";
        }
      }

       for (int j = 0; j <7; j++)
      {
        if (cop[j].second == inputString[i])
        {
          bs += cop[j].first;
          bs += ".";
        }
      }

      for (int j = 0; j <5; j++)
      {
        if (eviction_priority[j].second == inputString[i])
        {
          bs += eviction_priority[j].first;
          bs += ".";
        }
      }

   
     if (cache_hint[0].second == inputString[i])
     {
          bs += cache_hint[0].first;
          bs += ".";
     }

     for (int j = 0; j <2; j++)
      {
        if (vec[j].second == inputString[i])
        {
          bs += vec[j].first;
          bs += ".";
        }
       }

     for (int j = 0; j <20; j++)
     {
       if (type[j].second == inputString[i])
        {
         bs += type[j].first;
         bs += " ";
        }
     }

    }
    operand = ltrim2(operand);
    bs += decode(operand);
    return bs;  
}

string prefetch(string input)
{
   vector<string> Separeted;
    tokenize(input,"11111111",Separeted);
    string opcode=Separeted[0];
    string operand=Separeted[1];
    string bs="";
    vector<string> inputString;
    tokenize(opcode," ",inputString);
    for(int i=0;i<inputString.size();i++)
    {
      if(inputString[i].size() == 0)
      {
        break;
      }
     
     for (int j = 0; j <2; j++)
      {
        if (space[j].second == inputString[i])
        {
          bs += space[j].first;
          bs += ".";
        }
      }

   for (int j = 0;j<2;j++)
   {
        if (level[j].second == inputString[i])
        {
          bs += level[j].first;
          bs += ".";
        }
   }

      for (int j = 0; j <5; j++)
      {
        if (eviction_priority[j].second == inputString[i])
        {
          bs += eviction_priority[j].first;
          bs += ".";
        }
      }

      if(tensor[0].second == inputString[i])
      {
       bs += tensor[0].first;
       bs += ".";
      }

    }
    operand = ltrim2(operand);
    bs += decode(operand);
    return bs;  
}

string prefetchu(string input)
{
   vector<string> Separeted;
    tokenize(input,"11111111",Separeted);
    string opcode=Separeted[0];
    string operand=Separeted[1];
    string bs="";
    vector<string> inputString;
    tokenize(opcode," ",inputString);
    for(int i=0;i<inputString.size();i++)
    {
      if(inputString[i].size() == 0)
      {
        break;
      }

      for (int j = 0;j<2;j++)
      {
        if (level[j].second == inputString[i])
        {
          bs += level[j].first;
          bs += ".";
        }
      }
    }
    operand = ltrim2(operand);
    bs += decode(operand);
    return bs;  
}

string applypriority(string input)
{
   vector<string> Separeted;
    tokenize(input,"11111111",Separeted);
    string opcode=Separeted[0];
    string operand=Separeted[1];
    string bs="";
    vector<string> inputString;
    tokenize(opcode," ",inputString);
    for(int i=0;i<inputString.size();i++)
    {
      if(inputString[i].size() == 0)
      {
        break;
      }
     
     for (int j = 0; j <2; j++)
      {
        if (space[j].second == inputString[i])
        {
          bs += space[j].first;
          bs += ".";
        }
      }
     for (int j = 0; j <5; j++)
      {
        if (eviction_priority[j].second == inputString[i])
        {
          bs += eviction_priority[j].first;
          bs += ".";
        }
      }
    }
    operand = ltrim2(operand);
    bs += decode(operand);
    return bs;  
}

string discard(string input)
{
   vector<string> Separeted;
    tokenize(input,"11111111",Separeted);
    string opcode=Separeted[0];
    string operand=Separeted[1];
    string bs="";
    vector<string> inputString;
    tokenize(opcode," ",inputString);
    for(int i=0;i<inputString.size();i++)
    {
      if(inputString[i].size() == 0)
      {
        break;
      }
     
     for (int j = 0; j <2; j++)
      {
        if (space[j].second == inputString[i])
        {
          bs += space[j].first;
          bs += ".";
        }
      }
     for (int j = 0;j<2;j++)
      {
        if (level[j].second == inputString[i])
        {
          bs += level[j].first;
          bs += ".";
        }
      }
    
    }
    operand = ltrim2(operand);
    bs += decode(operand);
    return bs;  
}

string isspacep(string input)
{
   vector<string> Separeted;
    tokenize(input,"11111111",Separeted);
    string opcode=Separeted[0];
    string operand=Separeted[1];
    string bs="";
    vector<string> inputString;
    tokenize(opcode," ",inputString);
    for(int i=0;i<inputString.size();i++)
    {
      if(inputString[i].size() == 0)
      {
        break;
      }
     for (int j = 0; j <7; j++)
      {
        if (ss[j].second == inputString[i])
        {
          bs += ss[j].first;
          bs += ".";
        }
      }
    }
    operand = ltrim2(operand);
    bs += decode(operand);
    return bs;  
}

string cvt(string input)
{
   vector<string> Separeted;
    tokenize(input,"11111111",Separeted);
    string opcode=Separeted[0];
    string operand=Separeted[1];
    string bs="";
    vector<string> inputString;
    tokenize(opcode," ",inputString);
    for(int i=0;i<inputString.size();i++)
    {
      if(inputString[i].size() == 0)
      {
        break;
      }
       for (int j = 0; j <7; j++)
       {
          if (ss[j].second == inputString[i])
          {
            bs += ss[j].first;
            bs += ".";
          }
       }
       
       for (int j= 0; j<20; j++)
       {
          if (type[j].second == inputString[i])
          {
            bs += type[j].first;
            bs += ".";
          }
       }

    }
    operand = ltrim2(operand);
    bs += decode(operand);
    return bs;  
}

string cvta(string input)
{
   vector<string> Separeted;
    tokenize(input,"11111111",Separeted);
    string opcode=Separeted[0];
    string operand=Separeted[1];
    string bs="";
    vector<string> inputString;
    tokenize(opcode," ",inputString);
    for(int i=0;i<inputString.size();i++)
    {
      if(inputString[i].size() == 0)
      {
        break;
      }
       for (int j = 0; j <8; j++)
       {
          if (ss[j].second == inputString[i])
          {
            bs += ss[j].first;
            bs += ".";
          }
       }
       
       for (int j= 0; j<20; j++)
       {
          if (type[j].second == inputString[i])
          {
            bs += type[j].first;
            // bs += ".";
          }
       }

    }
    operand = ltrim2(operand);
    bs += decode(operand);
    return bs;  
}

string mapa(string input)
{
   vector<string> Separeted;
    tokenize(input,"11111111",Separeted);
    string opcode=Separeted[0];
    string operand=Separeted[1];
    string bs="";
    vector<string> inputString;
    tokenize(opcode," ",inputString);
    for(int i=0;i<inputString.size();i++)
    {
      if(inputString[i].size() == 0)
      {
        break;
      }
       for (int j = 0; j <7; j++)
       {
          if (ss[j].second == inputString[i])
          {
            bs += ss[j].first;
            bs += ".";
          }
       }
       
       for (int j= 0; j<20; j++)
       {
          if (type[j].second == inputString[i])
          {
            bs += type[j].first;
            bs += ".";
          }
       }

    }
    operand = ltrim2(operand);
    bs += decode(operand);
    return bs;  
}

string getctarank(string input)
{
   vector<string> Separeted;
    tokenize(input,"11111111",Separeted);
    string opcode=Separeted[0];
    string operand=Separeted[1];
    string bs="";
    vector<string> inputString;
    tokenize(opcode," ",inputString);
    for(int i=0;i<inputString.size();i++)
    {
      if(inputString[i].size() == 0)
      {
        break;
      }
       for (int j = 0; j <7; j++)
       {
          if (ss[j].second == inputString[i])
          {
            bs += ss[j].first;
            bs += ".";
          }
       }
       
       for (int j= 0; j<20; j++)
       {
          if (type[j].second == inputString[i])
          {
            bs += type[j].first;
            bs += ".";
          }
       }

    }
    operand = ltrim2(operand);
    bs += decode(operand);
    return bs;  
}

string cp(string input)
{
    vector<string> Separeted;
    tokenize(input,"11111111",Separeted);
    string opcode=Separeted[0];
    string operand=Separeted[1];
    string bs="";
    vector<string> inputString;
    tokenize(opcode," ",inputString);
    for(int i=0;i<inputString.size();i++)
    {
      if(inputString[i].size() == 0)
      {
        break;
      }

       for (int j = 0; j <12; j++)
       {
        if (cp_ops[j].second == inputString[i])
        {
          bs += cp_ops[j].first;
          bs += ".";
        }
       }


       for (int j = 0; j <7; j++)
       {
          if (ss[j].second == inputString[i])
          {
            bs += ss[j].first;
            bs += ".";
          }
       }

        for (int j = 0; j <5; j++)
        {
         if (dim[j].second == inputString[i])
         {
          bs += dim[j].first;
          bs += ".";
         }
        }

        for (int j = 0; j <2; j++)
        {
         if (load_mode[j].second == inputString[i])
         {
          bs += load_mode[j].first;
          bs += ".";
         }
        }

        for (int j = 0; j <8; j++)
        {
        if (red_op[j].second == inputString[i])
        {
          bs += red_op[j].first;
          bs += ".";
        }
        }
       
       for (int j = 0; j <2; j++)
   {
        if (completion_mech[j].second == inputString[i])
        {
          bs += completion_mech[j].first;
          bs += ".";
        }
   }

   for (int j = 0; j <1; j++)
   {
        if (multicast[j].second == inputString[i])
        {
          bs += multicast[j].first;
          bs += ".";
        }
   }




   if (cache_hint[0].second == inputString[i])
    {
          bs += cache_hint[0].first;
          bs += ".";
    }

  for (int j = 0; j <3; j++)
   {
        if (prefetch_size[j].second == inputString[i])
        {
          bs += prefetch_size[j].first;
          bs += ".";
        }
   }
  for (int j = 0; j <2; j++)
   {
        if (level[j].second == inputString[i])
        {
          bs += level[j].first;
          bs += ".";
        }
   }

   for (int j= 0; j<18; j++)
   {
    if (type[j].second == inputString[i])
    {
      bs += type[j].first;
      bs += ".";
    }
   }

    }
    operand = ltrim2(operand);
    bs += decode(operand);
    return bs;  
}

//parallel execution

string bar(string input)
{
  
  string bs = "";
  string mystr = input.substr(0, input.find(" ", 0)); // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(" ", 0) + 1);
  if (mystr == "1")
  {
    bs += "cta";
    bs += " ";

   
      mystr = input.substr(0, input.find(" ", 0));
      input = input.substr(input.find(" ", 0) + 1);
      for (int i = 0; i < 3; i++)
      {
        if (mystr == parallel[i].second)
        {
          bs += parallel[i].first;
          bs += " ";

                input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad
      long n = input.size();
      if (input.back() == ' ')
      {
        input.pop_back();
      }
      // cout<<" ->"<<decode(input)<<endl;
      bs += decode(input);
      return bs;
        }
      }
    
  }
  else if (mystr == "11")
  {
    bs += "wrap";
    bs += " ";

    mystr = input.substr(0, input.find(" ", 0));
    input = input.substr(input.find(" ", 0) + 1);
    for (int i = 0; i < 3; i++)
    {
      if (mystr == parallel[i].second)
      {
        bs += parallel[i].first;
        bs += " ";

                  input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad
      long n = input.size();
      if (input.back() == ' ')
      {
        input.pop_back();
      }
      // cout<<" ->"<<decode(input)<<endl;
      bs += decode(input);
      return bs;
      }
    }
  }

  cout<<"I am in"<<endl;
  
    cout<<"yaha par"<<endl;
    mystr = input.substr(0, input.find(" ", 0));
    input = input.substr(input.find(" ", 0) + 1);
    for (int i = 0; i < 3; i++)
    {
      if (mystr == parallel[i].second)
      {
        bs += parallel[i].first;
        bs += " ";

                  input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad
      long n = input.size();
      if (input.back() == ' ')
      {
        input.pop_back();
      }
      // cout<<" ->"<<decode(input)<<endl;
      bs += decode(input);
      return bs;
      }
    }
  
}

string atom(string input)
{
  string bs = "";
  cout<<"romt inp"<<input<<endl;
  string mystr = input.substr(0, input.find(" ", 0)); // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(" ", 0) + 1);
  if (mystr == "0") // 0
  {
    bs += "global";
    bs += " ";

    mystr = input.substr(0, input.find(" ", 0)); // op2
    input = input.substr(input.find(" ", 0) + 1);
    for (int i = 0; i < 9; i++)
    {
      if (mystr == op2[i].second)
      {
        bs += op2[i].first;
        bs += " ";
      }
    }

    mystr = input.substr(0, input.find(" ", 0)); // op2
    input = input.substr(input.find(" ", 0) + 1);
    for (int i = 0; i < 10; i++)
    {
      if (type[i].second == mystr)
      {
        bs += type[i].first;
        bs += " ";
      }
    }

    input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad
  long n = input.size();
  if (input.back() == ' ')
  {
    input.pop_back();
  }
  // cout<<" ->"<<decode(input)<<endl;
  bs += decode(input);
  return bs;
  }
  else if (mystr == "1") // 1
  {
    bs += "shared::cta";
    bs += " ";

    mystr = input.substr(0, input.find(" ", 0)); // op2
    input = input.substr(input.find(" ", 0) + 1);
    for (int i = 0; i < 9; i++)
    {
      if (mystr == op2[i].second)
      {
        bs += op2[i].first;
        bs += " ";
      }
    }

    mystr = input.substr(0, input.find(" ", 0)); // op2
    input = input.substr(input.find(" ", 0) + 1);
    for (int i = 0; i < 10; i++)
    {
      if (type[i].second == mystr)
      {
        bs += type[i].first;
        bs += " ";
      }
    }

    input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad
  long n = input.size();
  if (input.back() == ' ')
  {
    input.pop_back();
  }
  // cout<<" ->"<<decode(input)<<endl;
  bs += decode(input);
  return bs;
  }
}

// Logic and shift
string shf(string input) // l.mode.b32 d, a, b, c;     or b32
{
  string bs = "";
  string mystr = "";

  mystr = input.substr(0, input.find(" ", 0));  // l/r    --> l=1   r=0
  input = input.substr(input.find(" ", 0) + 1); // l/r k baad
  if (mystr == "1" || mystr == "0")             // l.mode.typr
  {
    if (mystr == "1")
    {
      bs += "l";
      bs += " ";
    }
    else
    {
      bs += "r";
      bs += " ";
    }

    mystr = input.substr(0, input.find(" ", 0)); // mode
    input = input.substr(input.find(" ", 0) + 1);
    for (int i = 0; i < 4; i++)
    {
      if (mode[i].second == mystr)
      {
        bs += mode[i].first;
        bs += " ";
      }
    }
    mystr = input.substr(0, input.find(" ", 0)); // type
    input = input.substr(input.find(" ", 0) + 1);
    for (int i = 0; i < 10; i++)
    {
      if (type[i].second == mystr)
      {
        bs += type[i].first;
        bs += " ";
      }
    }

    input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad
    long n = input.size();
    if (input.back() == ' ')
    {
      input.pop_back();
    }
    // cout<<" ->"<<decode(input)<<endl;
    bs += decode(input);
    return bs;
  }

  // type

  for (int i = 0; i < 10; i++)
  {
    if (type[i].second == mystr)
    {
      bs += type[i].first;
      bs += " ";
    }
  }

  input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad
  long n = input.size();
  if (input.back() == ' ')
  {
    input.pop_back();
  }
  // cout<<" ->"<<decode(input)<<endl;
  bs += decode(input);
  return bs;
}

// compa4rison and selection
string slct(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(" ", 0)); // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(" ", 0) + 1);       // 1st . k baad ka sab
  if (mystr == "0011")                                // ftz ---> 0011
  {
    bs += "ftz";
    bs += " ";

    mystr = input.substr(0, input.find(" ", 0));  // 1st . tak jo mila vo mode hoga
    input = input.substr(input.find(" ", 0) + 1); // 1st . k baad ka sab
    for (int i = 0; i < 10; i++)
    {
      if (type[i].second == mystr)
      {
        bs += type[i].first;
        bs += " ";
      }
    }

    mystr = input.substr(0, input.find(" ", 0)); // 1st . tak jo mila vo mode hoga
    input = input.substr(input.find(" ", 0) + 1);
    for (int i = 0; i < 10; i++)
    {
      if (type[i].second == mystr)
      {
        bs += type[i].first;
        bs += " ";
      }
    }

    input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad
    long n = input.size();
    if (input.back() == ' ')
    {
      input.pop_back();
    }
    // cout<<" ->"<<decode(input)<<endl;
    bs += decode(input);
    return bs;
  }

  for (int i = 0; i < 10; i++)
  {
    if (type[i].second == mystr)
    {
      bs += type[i].first;
      bs += " ";
    }
  }

  mystr = input.substr(0, input.find(" ", 0)); // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(" ", 0) + 1);
  for (int i = 0; i < 10; i++)
  {
    if (type[i].second == mystr)
    {
      bs += type[i].first;
      bs += " ";
    }
  }

  input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad
  long n = input.size();
  if (input.back() == ' ')
  {
    input.pop_back();
  }
  // cout<<" ->"<<decode(input)<<endl;
  bs += decode(input);
  return bs;
}

// sclaer video vale functions
string vadd(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(" ", 0)); //
  input = input.substr(input.find(" ", 0) + 1);       //
  for (int i = 0; i < 10; i++)
  {
    if (type[i].second == mystr)
    {
      bs += type[i].first;
      bs += " ";
    }
  }
  mystr = input.substr(0, input.find(" ", 0));  //
  input = input.substr(input.find(" ", 0) + 1); //
  for (int i = 0; i < 10; i++)
  {
    if (type[i].second == mystr)
    {
      bs += type[i].first;
      bs += " ";
    }
  }
  mystr = input.substr(0, input.find(" ", 0));  //
  input = input.substr(input.find(" ", 0) + 1); //
  for (int i = 0; i < 10; i++)
  {
    if (type[i].second == mystr)
    {
      bs += type[i].first;
      bs += " ";
    }
  }
  // kya op2 hai ?

  mystr = input.substr(0, input.find(" ", 0));  // sat --> 101 | 1 op2 hai
  input = input.substr(input.find(" ", 0) + 1); //
  if (mystr == "1011")
  {
    bs += "sat";
    bs += " ";

    mystr = input.substr(0, input.find(" ", 0));  // op2
    input = input.substr(input.find(" ", 0) + 1); // 1st . k baad ka sab
    if (mystr == "00")
    {
      bs += "add";
      bs += " ";
    }
    else if (mystr == "01")
    {
      bs += "min";
      bs += " ";
    }
    else if (mystr == "10")
    {
      bs += "max";
      bs += " ";
    }

    input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad
    long n = input.size();
    if (input.back() == ' ')
    {
      input.pop_back();
    }
    // cout<<" ->"<<decode(input)<<endl;
    bs += decode(input);
    return bs;
  }

  else if (mystr == "1010") // sat --> 101 | 0   op2 nhi hai
  {
    mystr = input.substr(0, input.find(" ", 0));  // sat
    input = input.substr(input.find(" ", 0) + 1); // 1st . k baad ka sab
    bs += "sat";
    bs += " ";

    input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad
    long n = input.size();
    if (input.back() == ' ')
    {
      input.pop_back();
    }
    // cout<<" ->"<<decode(input)<<endl;
    bs += decode(input);
    return bs;
  }
}

string vshl(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(" ", 0)); //
  input = input.substr(input.find(" ", 0) + 1);       //
  for (int i = 0; i < 10; i++)
  {
    if (type[i].second == mystr)
    {
      bs += type[i].first;
      bs += " ";
    }
  }
  mystr = input.substr(0, input.find(" ", 0));  //
  input = input.substr(input.find(" ", 0) + 1); //
  for (int i = 0; i < 10; i++)
  {
    if (type[i].second == mystr)
    {
      bs += type[i].first;
      bs += " ";
    }
  }
  mystr = input.substr(0, input.find(" ", 0));  //
  input = input.substr(input.find(" ", 0) + 1); //
  for (int i = 0; i < 10; i++)
  {
    if (type[i].second == mystr)
    {
      bs += type[i].first;
      bs += " ";
    }
  }
  // mode
  mystr = input.substr(0, input.find(" ", 0));                             // sat
  input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
  for (int i = 0; i < 4; i++)
  {
    if (mode[i].second == mystr)
    {
      bs += mode[i].first;
      bs += " ";
    }
  }

  input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad
  long n = input.size();
  if (input.back() == ' ')
  {
    input.pop_back();
  }
  // cout<<" ->"<<decode(input)<<endl;
  bs += decode(input);
  return bs;
}

string vmad(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(" ", 0)); //
  input = input.substr(input.find(" ", 0) + 1);       //
  for (int i = 0; i < 10; i++)
  {
    if (type[i].second == mystr)
    {
      bs += type[i].first;
      bs += " ";
    }
  }
  mystr = input.substr(0, input.find(" ", 0));  //
  input = input.substr(input.find(" ", 0) + 1); //
  for (int i = 0; i < 10; i++)
  {
    if (type[i].second == mystr)
    {
      bs += type[i].first;
      bs += " ";
    }
  }
  mystr = input.substr(0, input.find(" ", 0));  //
  input = input.substr(input.find(" ", 0) + 1); //
  for (int i = 0; i < 10; i++)
  {
    if (type[i].second == mystr)
    {
      bs += type[i].first;
      bs += " ";
    }
  }

  mystr = input.substr(0, input.find(" ", 0));                             //
  input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]); //
  if (mystr == "101")
  {
    bs += "sat";
    bs += " ";
  }
  else
  {
    for (int i = 0; i < 2; i++)
    {
      if (mystr == scale[i].second)
      {
        bs += scale[i].first;
        bs += " ";
      }
    }
  }

  input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad
  long n = input.size();
  if (input.back() == ' ')
  {
    input.pop_back();
  }
  // cout<<" ->"<<decode(input)<<endl;
  bs += decode(input);
  return bs;
}

string vset(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(" ", 0)); //
  input = input.substr(input.find(" ", 0) + 1);       //
  for (int i = 0; i < 10; i++)
  {
    if (type[i].second == mystr)
    {
      bs += type[i].first;
      bs += " ";
    }
  }
  mystr = input.substr(0, input.find(" ", 0));  //
  input = input.substr(input.find(" ", 0) + 1); //
  for (int i = 0; i < 10; i++)
  {
    if (type[i].second == mystr)
    {
      bs += type[i].first;
      bs += " ";
    }
  }

  mystr = input.substr(0, input.find(" ", 0));  //
  input = input.substr(input.find(" ", 0) + 1); //
  for (int i = 0; i < 6; i++)
  {
    if (mystr == cmp[i].second)
    {
      bs += cmp[i].first;
      bs += " ";
    }
  }

  mystr = input.substr(0, input.find(" ", 0));                             // delimeter / op
  input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
  for (int i = 0; i < 3; i++)
  {
    if (mystr == op2[i].second)
    {
      bs += op2[i].first;
      bs += " ";

      // ab delimeter aya hoga
      input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad
      long n = input.size();
      if (input.back() == ' ')
      {
        input.pop_back();
      }
      // cout<<" ->"<<decode(input)<<endl;
      bs += decode(input);
      return bs;
    }
  }

  // ab agar op nhi hai -> mystr -- delimetre
  // to input m delimeter k baad ka hai

  long n = input.size();
  if (input.back() == ' ')
  {
    input.pop_back();
  }
  // cout<<" ->"<<decode(input)<<endl;
  bs += decode(input);
  return bs;
}

// SIMD
string vadd2(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(" ", 0)); //
  input = input.substr(input.find(" ", 0) + 1);       //
  for (int i = 0; i < 10; i++)
  {
    if (type[i].second == mystr)
    {
      bs += type[i].first;
      bs += " ";
    }
  }
  mystr = input.substr(0, input.find(" ", 0));  //
  input = input.substr(input.find(" ", 0) + 1); //
  for (int i = 0; i < 10; i++)
  {
    if (type[i].second == mystr)
    {
      bs += type[i].first;
      bs += " ";
    }
  }
  mystr = input.substr(0, input.find(" ", 0));  //
  input = input.substr(input.find(" ", 0) + 1); //
  for (int i = 0; i < 10; i++)
  {
    if (type[i].second == mystr)
    {
      bs += type[i].first;
      bs += " ";
    }
  }

  mystr = input.substr(0, input.find(" ", 0));  //   sat / add
  input = input.substr(input.find(" ", 0) + 1); //
                                                // ya to sat/add      sat ---> 101      add--->110

  if (mystr == "101")
  {
    bs += "sat";
    bs += " ";
  }
  else if (mystr == "110")
  {
    bs += "add";
    bs += " ";
  }
  input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad
  long n = input.size();
  if (input.back() == ' ')
  {
    input.pop_back();
  }
  // cout<<" ->"<<decode(input)<<endl;
  bs += decode(input);
  return bs;
}

string vset2(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(" ", 0)); //
  input = input.substr(input.find(" ", 0) + 1);       //
  for (int i = 0; i < 10; i++)
  {
    if (type[i].second == mystr)
    {
      bs += type[i].first;
      bs += " ";
    }
  }
  mystr = input.substr(0, input.find(" ", 0));  //
  input = input.substr(input.find(" ", 0) + 1); //
  for (int i = 0; i < 10; i++)
  {
    if (type[i].second == mystr)
    {
      bs += type[i].first;
      bs += " ";
    }
  }

  mystr = input.substr(0, input.find(" ", 0));  // cmp hoga
  input = input.substr(input.find(" ", 0) + 1); //
  for (int i = 0; i < 6; i++)
  {
    if (mystr == cmp[i].second)
    {
      bs += cmp[i].first;
      bs += " ";
    }
  }

  mystr = input.substr(0, input.find(" ", 0));  // add / delimeter
  input = input.substr(input.find(" ", 0) + 1); //
  if (mystr == "110")                           // 110 11111111
  {
    bs += "add";
    bs += " ";
    input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad
  }
  // varna sidha delimeter hoga     11111111  to input deliemter k aage jaa chuka hoga
  long n = input.size();
  if (input.back() == ' ')
  {
    input.pop_back();
  }
  // cout<<" ->"<<decode(input)<<endl;
  bs += decode(input);
  return bs;
}

// floationg point

string testp(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(" ", 0)); // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(" ", 0) + 1);

  for (int i = 0; i < 6; i++)
  {
    if (mystr == op[i].second)
    {
      bs += op[i].first;
      bs += " ";
    }
  }

  mystr = input.substr(0, input.find(" ", 0));
  input = input.substr(input.find(" ", 0) + 1); // ab delimeter aya hoga
  for (int i = 0; i < 10; i++)                  //
  {
    if (type[i].second == mystr)
    {
      bs += type[i].first;
      bs += " ";
    }
  }

  input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad

  long n = input.size();
  if (input.back() == ' ')
  {
    input.pop_back();
  }

  bs += decode(input);
  return bs;
}

string fpadd(string input){
  string bs = "";
  string mystr = "";
  cout<<" i m nin"<<endl;

    mystr = input.substr(0, input.find(" ", 0));    // ya to type direct jhoga ya rnd vali cheeze
    input = input.substr(input.find(" ", 0) + 1);
    for (int i = 0; i < 4; i++) // rnd hoga to
    {
      if (mystr == rnd[i].second)
      {
        bs += rnd[i].first;
        bs += " ";

       
          mystr = input.substr(0, input.find(" ", 0));
          input = input.substr(input.find(" ", 0) + 1);
          if(mystr == "1")
          {
                    bs += "ftz";
                  bs += " ";

                  mystr = input.substr(0, input.find(" ", 0));
                  input = input.substr(input.find(" ", 0) + 1);
                  for (int i = 0; i < 10; i++) // as add m direct type hoga
                  {
                    if (type[i].second == mystr)
                    {
                      bs += type[i].first;
                      bs += " ";
                    }
                  }

                  input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad

                  long n = input.size();
                  if (input.back() == ' ')
                  {
                    input.pop_back();
                  }

                  bs += decode(input);
                  return bs;


          }
          
          for (int i = 0; i < 10; i++) // as add m direct type hoga
          {
            if (type[i].second == mystr)
            {
              bs += type[i].first;
              bs += " ";
            }
          }

          // operand
         input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad

          long n = input.size();
          if (input.back() == ' ')
          {
            input.pop_back();
          }

          bs += decode(input);
          return bs;
      }
    }
cout<<" abe idha r dekh le "<<endl;
     for (int i = 0; i < 4; i++)
    {
      if (mode[i].second == mystr)
      {
        cout<<"yaha par ana "<<endl;
        bs += mode[i].first;
        bs += " ";

        input = input.substr(input.find(".", 0) + 1);
        mystr = input.substr(0, input.find(" ", 0));

        for (int i = 0; i < 10; i++)
        {
          if (type[i].second == mystr)
          {
            bs += type[i].first;
            bs += " ";
          }
        }

       input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad
        input = input.substr(input.find(" ", 0) + 1);
        cout<<"input operand ----"<<input<<endl;
        long n = input.size();
        if (input.back() == ' ')
        {
          input.pop_back();
        }

        bs += decode(input);
        return bs;
      
      }
    }
cout<<" abe idha r dekh le "<<endl;
     if(mystr == "1")
     {
     bs += "ftz";
     bs += " ";

    // type
      mystr = input.substr(0, input.find(" ", 0));
      input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
      for (int i = 0; i < 10; i++) // as add m direct type hoga
      {
        if (type[i].second == mystr)
        {
          bs += type[i].first;
          bs += " ";
        }
      }

     input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad

        long n = input.size();
        if (input.back() == ' ')
        {
          input.pop_back();
        }

        bs += decode(input);
        return bs;
      

     }
     cout<<" abe idha r dekh le "<<endl;  
      
      cout<<"mystr ========"<<mystr<<endl;
        for (int i = 0; i < 10; i++) // as add m direct type hoga
        {
          if (type[i].second == mystr)
          {
            cout<<" abe idha r dekh le "<<endl;
            bs += type[i].first;
            bs += " ";
          }
        }

        // operand
       input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad

        long n = input.size();
        if (input.back() == ' ')
        {
          input.pop_back();
        }

        bs += decode(input);
        return bs;
      
    }

   

string fma(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(" ", 0));
  input = input.substr(input.find(" ", 0) + 1);
  for (int i = 0; i < 4; i++)
  {
    if (mystr == rnd[i].second)
    {
      bs += rnd[i].first;
      bs += " ";
    }
  }

  if (mystr == "1")
  {
    mystr = input.substr(0, input.find(".", 0));
    input = input.substr(input.find(".", 0) + 1);
    // ftz -->  1
    bs += "ftz";
    bs += " ";

    // type
    mystr = input.substr(0, input.find(" ", 0));
    input = input.substr(input.find(" ", 0) + 1);
    for (int i = 0; i < 10; i++) // as add m direct type hoga
    {
      if (type[i].second == mystr)
      {
        bs += type[i].first;
        bs += " ";
      }
    }

    // operand
    input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad

    long n = input.size();
    if (input.back() == ' ')
    {
      input.pop_back();
    }

    bs += decode(input);
    return bs;
  }

  else
  {
    mystr = input.substr(0, input.find(" ", 0));
    input = input.substr(input.find(" ", 0) + 1);
    for (int i = 0; i < 10; i++) // as add m direct type hoga
    {
      if (type[i].second == mystr)
      {
        bs += type[i].first;
        bs += " ";
      }
    }

    input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad

    long n = input.size();
    if (input.back() == ' ')
    {
      input.pop_back();
    }

    bs += decode(input);
    return bs;
  }
}

string Fdiv(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(" ", 0));
  input = input.substr(input.find(" ", 0) + 1);

  if (mystr == "0" || mystr == "1")
  {
    if (mystr == "full")
    {
      bs += "full";
      bs += " ";
    }
    else
    {
      bs += "approx";
      bs += " ";
    }
    mystr = input.substr(0, input.find(" ", 0)); // 1 hoag to ftz
    if (mystr == "1")                            // ftz hoga
    {
      input = input.substr(input.find(" ", 0) + 1);

      bs += "ftz";
      bs += " ";

      mystr = input.substr(0, input.find(" ", 0)); // type
      input = input.substr(input.find(" ", 0) + 1);
      for (int i = 0; i < 10; i++) //
      {
        if (type[i].second == mystr)
        {
          bs += type[i].first;
          bs += " ";
        }
      }

      input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad

      long n = input.size();
      if (input.back() == ' ')
      {
        input.pop_back();
      }

      bs += decode(input);
      return bs;
    }

    else // ftz nhi hoga
    {

      input = input.substr(input.find(" ", 0) + 1);
      for (int i = 0; i < 10; i++) //
      {
        if (type[i].second == mystr)
        {
          bs += type[i].first;
          bs += " ";
        }
      }

      input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad

      long n = input.size();
      if (input.back() == ' ')
      {
        input.pop_back();
      }

      bs += decode(input);
      return bs;
    }
  }

  for (int i = 0; i < 4; i++)
  {
    if (mystr == rnd[i].second)
    {
      bs += rnd[i].first;
      bs += " ";
    }
  }

  mystr = input.substr(0, input.find(" ", 0));
  if (mystr == "1") // ftz hoga
  {

    input = input.substr(input.find(".", 0) + 1);

    bs += "ftz";
    bs += " ";

    mystr = input.substr(0, input.find(" ", 0)); // type
    input = input.substr(input.find(" ", 0) + 1);
    for (int i = 0; i < 10; i++) //
    {
      if (type[i].second == mystr)
      {
        bs += type[i].first;
        bs += " ";
      }
    }

    input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad

    long n = input.size();
    if (input.back() == ' ')
    {
      input.pop_back();
    }

    bs += decode(input);
    return bs;
  }
  else // ftz nhi hoga
  {

    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
    for (int i = 0; i < 10; i++) //
    {
      if (type[i].second == mystr)
      {
        bs += type[i].first;
        bs += " ";
      }
    }

    input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad

    long n = input.size();
    if (input.back() == ' ')
    {
      input.pop_back();
    }

    bs += decode(input);
    return bs;
  }
}

string FPMin(string input)
{
  string bs = "";
  string mystr = "";
  mystr = input.substr(0, input.find(" ", 0)); //

  if (mystr == "00" || mystr == "01" || mystr == "10")
  {

    input = input.substr(input.find(" ", 0) + 1);
    // ftz - 00    , NAN - 01    , xorsign.abs - 10
    if (mystr == "00")
    {
      bs += "ftz";
      bs += " ";
      mystr = input.substr(0, input.find(" ", 0)); // type
      input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
      for (int i = 0; i < 10; i++) //
      {
        if (type[i].second == mystr)
        {
          bs += type[i].first;
          bs += " ";
        }
      }

      input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad

      long n = input.size();
      if (input.back() == ' ')
      {
        input.pop_back();
      }

      bs += decode(input);
      return bs;
    }
    else if (mystr == "01")
    {
      bs += "NaN";
      bs += " ";
      mystr = input.substr(0, input.find(" ", 0)); // type
      input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
      for (int i = 0; i < 10; i++) //
      {
        if (type[i].second == mystr)
        {
          bs += type[i].first;
          bs += " ";
        }
      }

      input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad

      long n = input.size();
      if (input.back() == ' ')
      {
        input.pop_back();
      }

      bs += decode(input);
      return bs;
    }
    else if (mystr == "10")
    {

      bs += "xorsign";
      bs += " ";
      mystr = input.substr(0, input.find(" ", 0)); // type
      input = input.substr(input.find(" ", 0) + 1);
      for (int i = 0; i < 10; i++) //
      {
        if (type[i].second == mystr)
        {
          bs += type[i].first;
          bs += " ";
        }
      }

      input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad

      long n = input.size();
      if (input.back() == ' ')
      {
        input.pop_back();
      }

      bs += decode(input);
      return bs;
    }
  }

  input = input.substr(input.find(" ", 0) + 1);
  for (int i = 0; i < 10; i++) //
  {
    if (type[i].second == mystr)
    {
      bs += type[i].first;
      bs += " ";
    }
  }

  input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad

  long n = input.size();
  if (input.back() == ' ')
  {
    input.pop_back();
  }

  bs += decode(input);
  return bs;
}

string rcp(string input)
{
  string bs = "";
  string mystr = "";
  mystr = input.substr(0, input.find(" ", 0));
  input = input.substr(input.find(" ", 0) + 1);
  // approx hoga / rnd
  if (mystr == "1") // rnd 2 bit ka hai ---> approx = 1
  {
    bs += "approx";
    bs += " ";

    mystr = input.substr(0, input.find(" ", 0));
    input = input.substr(input.find(" ", 0) + 1);
    if (mystr == "1")
    {
      bs += "ftz";
      bs += " ";

      mystr = input.substr(0, input.find(" ", 0)); // type
      input = input.substr(input.find(" ", 0) + 1);
      for (int i = 0; i < 10; i++) //
      {
        if (type[i].second == mystr)
        {
          bs += type[i].first;
          bs += " ";
        }
      }

      input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad

      long n = input.size();
      if (input.back() == ' ')
      {
        input.pop_back();
      }

      bs += decode(input);
      return bs;
    }

    else
    {

      for (int i = 0; i < 10; i++) //
      {
        if (type[i].second == mystr)
        {
          bs += type[i].first;
          bs += " ";
        }
      }

      input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad

      long n = input.size();
      if (input.back() == ' ')
      {
        input.pop_back();
      }

      bs += decode(input);
      return bs;
    }
  }

  // rnd m se kuch hoga

  else if (mystr == "0") //   sidha ftz AND type   -- 0
  {
    bs += "ftz";
    bs += " ";

    mystr = input.substr(0, input.find(" ", 0)); // type
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
    for (int i = 0; i < 10; i++) //
    {
      if (type[i].second == mystr)
      {
        bs += type[i].first;
        bs += " ";
      }
    }

    mystr = input.substr(0, input.find(" ", 0)); // type
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
    for (int i = 0; i < 10; i++) //
    {
      if (type[i].second == mystr)
      {
        bs += type[i].first;
        bs += " ";
      }
    }

    input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad

    long n = input.size();
    if (input.back() == ' ')
    {
      input.pop_back();
    }

    bs += decode(input);
    return bs;
  }

  for (int i = 0; i < 4; i++) // rnd ... hoga
  {
    if (mystr == rnd[i].second)
    {
      bs += rnd[i].first;
      bs += " ";

      mystr = input.substr(0, input.find(" ", 0));
      input = input.substr(input.find(" ", 0) + 1);
      if (mystr == "1")
      {
        bs += "ftz";
        bs += " ";

        mystr = input.substr(0, input.find(" ", 0)); // type
        input = input.substr(input.find(" ", 0) + 1);
        for (int i = 0; i < 10; i++) //
        {
          if (type[i].second == mystr)
          {
            bs += type[i].first;
            bs += " ";
          }
        }

        mystr = input.substr(0, input.find(" ", 0)); // type
        input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
        for (int i = 0; i < 10; i++) //
        {
          if (type[i].second == mystr)
          {
            bs += type[i].first;
            bs += " ";
          }
        }

        input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad

        long n = input.size();
        if (input.back() == ' ')
        {
          input.pop_back();
        }

        bs += decode(input);
        return bs;
      }

      else // ftz nhi hia
      {

        for (int i = 0; i < 10; i++) //
        {
          if (type[i].second == mystr)
          {
            bs += type[i].first;
            bs += " ";
          }
        }

        mystr = input.substr(0, input.find(" ", 0)); // type
        input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
        for (int i = 0; i < 10; i++) //
        {
          if (type[i].second == mystr)
          {
            bs += type[i].first;
            bs += " ";
          }
        }

        input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad

        long n = input.size();
        if (input.back() == ' ')
        {
          input.pop_back();
        }

        bs += decode(input);
        return bs;
      }
    }
  }
}

string rsqrt(string input)
{
  string bs = "";
  string mystr = "";
  mystr = input.substr(0, input.find(" ", 0));
  input = input.substr(input.find(" ", 0) + 1);

  // approx hi hoag ---> 1

  bs += "approx";
  bs += " ";

  mystr = input.substr(0, input.find(" ", 0));
  input = input.substr(input.find(" ", 0) + 1);

  if (mystr == "1") // 1
  {
    bs += "ftz";
    bs += " ";

    mystr = input.substr(0, input.find(" ", 0)); // type
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
    for (int i = 0; i < 10; i++) //
    {
      if (type[i].second == mystr)
      {
        bs += type[i].first;
        bs += " ";
      }
    }

    input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad

    long n = input.size();
    if (input.back() == ' ')
    {
      input.pop_back();
    }

    bs += decode(input);
    return bs;
  }

  else
  {

    for (int i = 0; i < 10; i++) //
    {
      if (type[i].second == mystr)
      {
        bs += type[i].first;
        bs += " ";
      }
    }

    input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad

    long n = input.size();
    if (input.back() == ' ')
    {
      input.pop_back();
    }

    bs += decode(input);
    return bs;
  }
}

// half precision floating point

string hpfadd(string input)
{
  string bs = "";
  string mystr = "";

  // rnd hai

  mystr = input.substr(0, input.find(" ", 0));
  input = input.substr(input.find(" ", 0) + 1);
  for (int i = 0; i < 4; i++)
  {
    if (mystr == rnd[i].second)
    {
      bs += rnd[i].first;
      bs += " ";

      mystr = input.substr(0, input.find(" ", 0)); // type
      input = input.substr(input.find(" ", 0) + 1);

      for (int i = 0; i < 10; i++) // as add m direct type hoga
      {
        if (type[i].second == mystr)
        {
          bs += type[i].first;
          bs += " ";
        }
      }

      input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad

      long n = input.size();
      if (input.back() == ' ')
      {
        input.pop_back();
      }

      bs += decode(input);
      return bs;
    }
  }

  for (int i = 0; i < 10; i++) // as add m direct type hoga
  {
    if (type[i].second == mystr)
    {
      bs += type[i].first;
      bs += " ";
    }
  }

  input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad

  long n = input.size();
  if (input.back() == ' ')
  {
    input.pop_back();
  }

  bs += decode(input);
  return bs;
}

string hpffma(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(" ", 0));
  input = input.substr(input.find(" ", 0) + 1);
  for (int i = 0; i < 4; i++)
  {
    if (mystr == rnd[i].second)
    {
      bs += rnd[i].first;
      bs += " ";
    }
  }

  mystr = input.substr(0, input.find(" ", 0));
  input = input.substr(input.find(" ", 0) + 1);

  if (mystr == "11011") // relu ---> 11011
  {
    bs += "relu";
    bs += " ";

    mystr = input.substr(0, input.find(" ", 0));
    input = input.substr(input.find(" ", 0) + 1);

    for (int i = 0; i < 10; i++) // as add m direct type hoga
    {
      if (type[i].second == mystr)
      {
        bs += type[i].first;
        bs += " ";
      }
    }

    input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad

    long n = input.size();
    if (input.back() == ' ')
    {
      input.pop_back();
    }

    bs += decode(input);
    return bs;
  }

  for (int i = 0; i < 10; i++) // as add m direct type hoga
  {
    if (type[i].second == mystr)
    {
      bs += type[i].first;
      bs += " ";
    }
  }

  input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad

  long n = input.size();
  if (input.back() == ' ')
  {
    input.pop_back();
  }

  bs += decode(input);
  return bs;
}

string hpfneg(string input)
{
  string bs = "";
  string mystr = "";

  mystr = input.substr(0, input.find(" ", 0));
  input = input.substr(input.find(" ", 0) + 1);
  if (mystr == "1")
  {
    bs += "ftz";
    bs += " ";

    mystr = input.substr(0, input.find(" ", 0));
    input = input.substr(input.find(" ", 0) + 1);

    for (int i = 0; i < 10; i++) // as add m direct type hoga
    {
      if (type[i].second == mystr)
      {
        bs += type[i].first;
        bs += " ";
      }
    }

    input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad

    long n = input.size();
    if (input.back() == ' ')
    {
      input.pop_back();
    }

    bs += decode(input);
    return bs;
  }

  else
  {

    for (int i = 0; i < 10; i++) // as add m direct type hoga
    {
      if (type[i].second == mystr)
      {
        bs += type[i].first;
        bs += " ";
      }
    }

    input = input.substr(input.find(" ", 0) + 1); // delimeter hatane k baad

    long n = input.size();
    if (input.back() == ' ')
    {
      input.pop_back();
    }

    bs += decode(input);
    return bs;
  }
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

  // type   - 5bits
type[0] = {"u16","0000000"};
  type[1] = {"u32", "0000001"};
  type[2] = {"u64", "0000010"};
  type[3] = {"s16", "0000011"};
  type[4] = {"s32", "0000100"};
  type[5] = {"s64", "0000101"};
  type[6] = {"u16x2", "0000110"};
  type[7] = {"s16x2", "0000111"};
  type[8] = {"b32", "0001000"};
  type[9] = {"b64", "0001001"};
  type[10]= {"b16","0001010"};
  type[11]= {"f32","0001011"};
  type[12]= {"f64","0001100"};
  type[13]= {"b8","0001101"};
  type[14]= {"u8","0001110"};
  type[15]= {"s8","0001111"};
  type[16]= {"f16","0010000"};
  type[17]= {"bf16","0010001"};
  type[18]={"e4m3x2","0010010"};
  type[19]={"e5m2x2","0010011"};
  // mode
mode[0] = {"hi", "0000"};
  mode[1] = {"lo", "0001"};
  mode[2] = {"wide", "0010"};
  mode[3] = {"clamp", "0011"};
  mode[4] = {"wrap", "0100"};
  mode[5]= {"up", "0101"};
  mode[6]= {"down", "0110"};
  mode[7]= {"bfly", "0111"};
  mode[8]= {"idx", "1000"};
  mode[9]= {"f4e","1001"};
  mode[10]= {"b4e","1010"};
  mode[11]= {"rc8","1011"};
  mode[12]= {"ec1","1100"};
  mode[13]= {"ecr","1101"};
  mode[14]= {"rc16","1110"};

  vector<pair<string, string>> temp; // 1
  temp.push_back(make_pair("add", "00000000"));
  temp.push_back(make_pair("sub", "00000001"));
  temp.push_back(make_pair("mul", "00000010"));
  temp.push_back(make_pair("mad", "00000011"));

  temp.push_back(make_pair("mul24", "00000100"));
  temp.push_back(make_pair("mad24", "00000101"));
  temp.push_back(make_pair("sad", "00000110"));
  temp.push_back(make_pair("div", "00000111"));

  temp.push_back(make_pair("rem", "00001000"));
  temp.push_back(make_pair("abs", "00001001"));
  temp.push_back(make_pair("neg", "00001010"));
  temp.push_back(make_pair("min", "00001011"));

  temp.push_back(make_pair("max", "00001100"));
  temp.push_back(make_pair("popc", "00001101"));
  temp.push_back(make_pair("clz", "00001110"));
  temp.push_back(make_pair("bfind", "00001111"));

  temp.push_back(make_pair("fns", "00010000"));
  temp.push_back(make_pair("brev", "00010001"));
  temp.push_back(make_pair("bfe", "00010010"));
  temp.push_back(make_pair("bfi", "00010011"));

  temp.push_back(make_pair("szext", "00010100"));
  temp.push_back(make_pair("bmsk", "00010101"));
  temp.push_back(make_pair("dp4a", "00010110"));
  temp.push_back(make_pair("dp2a", "00010111"));
  instruction.push_back(temp);

  vector<pair<string, string>> temp2; // 2
  temp2.push_back(make_pair("testp", "00011000"));
  temp2.push_back(make_pair("copysign", "00011001"));
  temp2.push_back(make_pair("add", "00011010"));
  temp2.push_back(make_pair("sub", "00011011"));

  temp2.push_back(make_pair("mul", "00011100"));
  temp2.push_back(make_pair("fma", "00011101"));
  temp2.push_back(make_pair("mad", "00011110"));
  temp2.push_back(make_pair("div", "00011111"));

  temp2.push_back(make_pair("abs", "00100000"));
  temp2.push_back(make_pair("neg", "00100001"));
  temp2.push_back(make_pair("min", "00100010"));
  temp2.push_back(make_pair("max", "00100011"));

  temp2.push_back(make_pair("rcp", "00100100")); /////also have to handle rcp approx
  temp2.push_back(make_pair("sqrt", "00100101"));
  temp2.push_back(make_pair("rsqrt", "00100110"));
  temp2.push_back(make_pair("sin", "00100111"));

  temp2.push_back(make_pair("cos", "00101000"));
  temp2.push_back(make_pair("lg2", "00101001"));
  temp2.push_back(make_pair("ex2", "00101010"));
  temp2.push_back(make_pair("tanh", "00101011"));
  instruction.push_back(temp2);

  vector<pair<string, string>> temp3; // 3
  temp3.push_back(make_pair("add", "00101100"));
  temp3.push_back(make_pair("sub", "00101101"));
  temp3.push_back(make_pair("mul", "00101110"));
  temp3.push_back(make_pair("fma", "00101111"));
  temp3.push_back(make_pair("neg", "00110000"));

  temp3.push_back(make_pair("abs", "00110001"));
  temp3.push_back(make_pair("min", "00110010"));
  temp3.push_back(make_pair("max", "00110011"));
  temp3.push_back(make_pair("tanh", "00110100"));
  temp3.push_back(make_pair("ex2", "00110101"));
  instruction.push_back(temp3);

  vector<pair<string, string>> temp4; // 4
  temp4.push_back(make_pair("set", "00110110"));
  temp4.push_back(make_pair("setp", "00110111"));
  temp4.push_back(make_pair("selp", "00111000"));
  temp4.push_back(make_pair("slct", "00111001"));
  instruction.push_back(temp4);

  vector<pair<string, string>> temp5; // 5
  temp5.push_back(make_pair("set", "00111010"));
  temp5.push_back(make_pair("setp", "00111011"));
  instruction.push_back(temp5);

  vector<pair<string, string>> temp6; // 6
  temp6.push_back(make_pair("and", "00111100"));
  temp6.push_back(make_pair("or", "00111101"));
  temp6.push_back(make_pair("xor", "00111110"));
  temp6.push_back(make_pair("not", "00111111"));
  temp6.push_back(make_pair("cnot", "01000000"));
  temp6.push_back(make_pair("lop3", "01000001"));
  temp6.push_back(make_pair("shf", "01000010"));
  temp6.push_back(make_pair("shl", "01000011"));
  temp6.push_back(make_pair("shr", "01000100"));
  instruction.push_back(temp6);

  vector<pair<string, string>> temp7; // 7

  temp7.push_back(make_pair("mov", "01000101"));
  temp7.push_back(make_pair("shfl", "01000110"));
  temp7.push_back(make_pair("prmt", "01000111"));
  temp7.push_back(make_pair("ld", "01001000"));

  temp7.push_back(make_pair("ldu", "01001001"));
  temp7.push_back(make_pair("st", "01001010"));
  temp7.push_back(make_pair("prefetch", "01001011"));
  temp7.push_back(make_pair("prefetchu", "01001100"));
  temp7.push_back(make_pair("applypriority", "01001101"));

  temp7.push_back(make_pair("discard", "01001110"));
  temp7.push_back(make_pair("createpolicy", "01001111"));
  temp7.push_back(make_pair("isspacep", "01010000"));
  temp7.push_back(make_pair("cvta", "01010001"));

  temp7.push_back(make_pair("cvt", "01010010"));
  temp7.push_back(make_pair("mapa", "01010011"));
  temp7.push_back(make_pair("cp", "01010100"));
  temp7.push_back(make_pair("getctarank", "01010101"));
  instruction.push_back(temp7);

  vector<pair<string, string>> temp11; // 8
  temp11.push_back(make_pair("barrier", "01010110"));
  temp11.push_back(make_pair("bar", "01010111"));
  temp11.push_back(make_pair("alloca", "01011000"));
  temp11.push_back(make_pair("atom", "01011001"));
  instruction.push_back(temp11);

  vector<pair<string, string>> temp14; // 9
  temp14.push_back(make_pair("stacksave", "01011010"));
  temp14.push_back(make_pair("stackrestore", "01011011"));
  temp14.push_back(make_pair("alloca", "01011100"));
  instruction.push_back(temp14);

  vector<pair<string, string>> temp16; // 10
  temp16.push_back(make_pair("vadd", "01011101"));
  temp16.push_back(make_pair("vsub", "01011110"));
  temp16.push_back(make_pair("vabsdiff", "01011111"));
  temp16.push_back(make_pair("vmin", "01100000"));
  temp16.push_back(make_pair("vmax", "01100001"));
  instruction.push_back(temp16);

  vector<pair<string, string>> temp17; // 11
  temp17.push_back(make_pair("vadd2", "01100010"));
  temp17.push_back(make_pair("vsub2", "01100011"));
  temp17.push_back(make_pair("vavrg2", "01100100"));
  temp17.push_back(make_pair("vabsdiff2", "01100101"));
  temp17.push_back(make_pair("vmin2", "01100110"));
  temp17.push_back(make_pair("vmax2", "01100111"));
  instruction.push_back(temp17);

  vector<pair<string, string>> temp18; // 12
  temp18.push_back(make_pair("brkpt", "01101000"));
  temp18.push_back(make_pair("nanosleep", "01101001"));
  temp18.push_back(make_pair("pmevent", "01101010"));
  temp18.push_back(make_pair("trap", "01101011"));
  temp18.push_back(make_pair("setmaxnreg", "01101100"));
  instruction.push_back(temp18);

  vector<pair<string, string>> data_movement_temp;  //13

  data_movement_temp.push_back(make_pair("mov", "00000"));
  data_movement_temp.push_back(make_pair("shfl", "00001"));
  data_movement_temp.push_back(make_pair("prmt", "00010"));
  data_movement_temp.push_back(make_pair("ld", "00011"));

  data_movement_temp.push_back(make_pair("ldu", "00100"));
  data_movement_temp.push_back(make_pair("st", "00101"));
  data_movement_temp.push_back(make_pair("prefetch", "00110"));
  data_movement_temp.push_back(make_pair("prefetchu", "00111"));
  data_movement_temp.push_back(make_pair("applypriority", "01000"));

  data_movement_temp.push_back(make_pair("discard", "01001"));
  data_movement_temp.push_back(make_pair("createpolicy", "01010"));
  data_movement_temp.push_back(make_pair("isspacep", "01011"));
  data_movement_temp.push_back(make_pair("cvta", "01100"));

  data_movement_temp.push_back(make_pair("cvt", "01101"));
  data_movement_temp.push_back(make_pair("mapa", "01110"));
  data_movement_temp.push_back(make_pair("cp", "01111"));
  data_movement_temp.push_back(make_pair("getctarank", "10000"));
instruction.push_back(data_movement_temp);

  scale.push_back(make_pair("shr7", "0"));
  scale.push_back(make_pair("shr15", "1"));

  boolOp.push_back(make_pair("and", "00"));
  boolOp.push_back(make_pair("or", "01"));
  boolOp.push_back(make_pair("xor", "10"));

  // op vala hash amp
  op.push_back(make_pair("finite", "000"));
  op.push_back(make_pair("infinite", "001"));
  op.push_back(make_pair("number", "010"));
  op.push_back(make_pair("notanumber", "011"));
  op.push_back(make_pair("normal", "100"));
  op.push_back(make_pair("subnormal", "101"));

  op2.push_back(make_pair("add", "00"));
  op2.push_back(make_pair("min", "01"));
  op2.push_back(make_pair("max", "10"));

  // rnd
  rnd.push_back(make_pair("rn", "00"));
  rnd.push_back(make_pair("rz", "01"));
  rnd.push_back(make_pair("rm", "10"));
  rnd.push_back(make_pair("rp", "11"));

  parallel.push_back(make_pair("sync", "00"));
  parallel.push_back(make_pair("arrive", "01"));
  parallel.push_back(make_pair("red", "10"));


   level[0]={"L1","01"};
  level[1]={"L2","10"};

    cache_hint[0]={"L2::cache_hint","1"};

    prefetch_size[0]={"L2::64B","000000"};
  prefetch_size[1]={"L2::128B","000001"};
  prefetch_size[2]={"L2::256B","000010"};

    multicast[0]={"multicast::cluster","00000000001"};

      completion_mech[0]={"bulk_group","000000000000"};
  completion_mech[1]={"mbarrier::complete_tx::bytes","00000000001"};

    load_mode[0]={"tile","00000000000000"};
  load_mode[1]={"im2col","00000000000001"};

    red_op[0]={"add","0000000000"};
  red_op[1]={"min","0000000001"};
  red_op[2]={"max","0000000010"};
  red_op[3]={"inc","0000000011"};
  red_op[4]={"dec","0000000100"};
  red_op[5]={"and","0000000101"};
  red_op[6]={"or","0000000110"};
  red_op[7]={"xor","0000000111"};

    dim[0]={"1d","000"};
  dim[1]={"2d","001"};
  dim[2]={"3d","010"};
  dim[3]={"4d","011"};
  dim[4]={"5d","100"};

    space[0]={"global","01"};
  space[1]={"local","10"};

    ss[0]={"const","0000"};
  ss[1]={"global","0001"};
  ss[2]={"local","0010"};
  ss[3]={"param","0011"};
  ss[4]={"shared::cta","0100"};
  ss[5]={"shared::cluster","0101"};
  ss[6]={"shared","0110"};

    eviction_priority_l2[0]={"L2::evict_normal","01"};

    cp_ops[0]={"async","000000000"};
  cp_ops[1]={"commit_group","000000001"};
  cp_ops[2]={"wait_group","000000010"};
  cp_ops[3]={"wait_all","000000011"};
  cp_ops[4]={"bulk","000000100"};
  cp_ops[5]={"reduce","000000101"};
  cp_ops[6]={"tensor","000000110"};
  cp_ops[7]={"prefetch","000000111"};
  cp_ops[8]={"ca","000001000"};
  cp_ops[9]={"cg","000001001"};
  cp_ops[10]={"read","000001101"};

    tensor[0]={"tensormap","01"};

      eviction_priority[0]={"L1::evict_normal","00000"};
  eviction_priority[1]={"L1::evict_unchanged","00001"};
  eviction_priority[2]={"L1::evict_first","00010"};
  eviction_priority[3]={"L1::evict_last","00011"};
  eviction_priority[4]={"L1::no_allocate","00100"};

  vec[0]={"v2","0"};
  vec[1]={"v4","1"};

    scope[0]={"cta","00"};
  scope[1]={"cluster","01"};
  scope[2]={"gpu","10"};
  scope[3]={"sys","11"};

    qualifier[0]={"weak","000"};
  qualifier[1]={"volatile","001"};
  qualifier[2]={"relaxed","010"};
  qualifier[3]={"acquire","011"};
  qualifier[4]={"release","100"};


  cmp.push_back(make_pair("eq", "00000"));
  cmp.push_back(make_pair("ne", "00001"));
  cmp.push_back(make_pair("lt", "00010"));
  cmp.push_back(make_pair("le", "00011"));
  cmp.push_back(make_pair("gt", "00100"));
  cmp.push_back(make_pair("ge", "00101"));
  cmp.push_back(make_pair("lo", "00110"));
  cmp.push_back(make_pair("ls", "00111"));
  cmp.push_back(make_pair("hi", "01000"));
  cmp.push_back(make_pair("hs", "01001"));
  cmp.push_back(make_pair("equ", "01010"));
  cmp.push_back(make_pair("neu", "01011"));
  cmp.push_back(make_pair("ltu", "01100"));
  cmp.push_back(make_pair("leu", "01101"));
  cmp.push_back(make_pair("gtu", "01110"));
  cmp.push_back(make_pair("geu", "01111"));
  cmp.push_back(make_pair("num", "10000"));
  cmp.push_back(make_pair("nan", "10001"));

  fstream newfile;
  
  newfile.open("output.txt", ios::in);

  if (newfile.is_open())
  { // checking whether the file is open
    string tp1;
    while (getline(newfile, tp1))
    {
      cout<<"1. uidhcsdhfcsjndfc"<<endl;
      string bitString = "";
       string mystr="";
       bool close=false;
       string tp3=tp1;

      if(tp1.size() == 0)
      {
        continue;
      }

      

      string charString; // read data from file object and put it into string.
      // cout << tp1 << "\n"; // print the data of the string

       // control flow instructions ko hum yaha par handle kar rahe hai jitne ho saje.
      //  mystr = tp1.substr(0, tp1.find(" ", 0));
      // if (tp1[0] == '0') // { - 0 , } - 1
      // {
      //   bitString += "{";
      //   bitString += " ";
      //   close = true;
      //   tp1 = tp1.substr(tp1.find("0", 0) + 1);
      //   // as } ki encoding nhi ki h to problem nhi hoga
        
      // }
      //  else if (tp1[0] == '1' && tp1[1] == '0') // @ = 1 0 , @! = 1 1
      // {
        
      //     bitString += "@";
      //     bitString += " ";


      //     std::string s(1, tp1[2]);
      //     bitString += decode(s);
      //     bitString += " ";
      //     tp1 = tp1.substr(tp1.find("10", 0) + 1, tp1[tp1.length() - 1]);
      //   }
      //   else if (tp1[0] == '1' && tp1[1] == '1')
      //   {

      //     bitString += "@!";
      //     bitString += " ";
      //     std::string s(1, tp1[2]);
      //     bitString += decode(s);
      //     bitString += " ";

      //     tp1 = tp1.substr(tp1.find("11", 0) + 1, tp1[tp1.length() - 1]);
      //   }
      
 // control flow   2 bit
      // if (tp1 == "00") // as isme koi parameter nhi hoiga
      // {
      //   bitString += "ret;";
      //   bitString += " ";
      // }
      // else if (tp1 == "01")
      // {
      //   bitString += "exit;";
      //   bitString += " ";
      // }


      mystr = tp1.substr(0, tp1.find(" ", 0));    // instruction
      if (mystr == "00")
      {
        bitString += "bra";
        bitString += " ";

        tp1 = tp1.substr(tp1.find(" ", 0) + 1);
          tp1 = tp1.substr(tp1.find(" ", 0) + 1);// delimeter hatane k liye
        bitString += decode(tp1);
      }
      else if (mystr == "01")
      {
        bitString += "call";
        bitString += " ";

        tp1 = tp1.substr(tp1.find(" ", 0) + 1);
         tp1 = tp1.substr(tp1.find(" ", 0) + 1);// delimeter hatane k liye
        bitString += decode(tp1);
      }


      // Miscellaneous
      tp1 = tp1.substr(tp1.find(" ", 0) + 1);
      if(mystr == "11111111")
      {
        bitString += decode(tp1);
        cout<<"bitstring -------"<<bitString<<endl;
        ofstream outfile;
      outfile.open("ptx.txt", ios::app);
       outfile << bitString << endl;
      // bitString = "";
      // // outfile << "hi hi" <<"\n" << endl;
      outfile.close();
        continue;
      }
      if (mystr == "000" ||mystr == "011" )
      {

      
      if(mystr == "000")
      {
        bitString += "brkpt;";
        bitString += " ";
      }
      else if (mystr == "011")
      {

        bitString += "trap;";
        bitString += " ";
      }
      }

string mystr2 = tp1.substr(0, tp1.find(" ", 0));









     
      // cout<<" strt m tp 1 hai $$$$$$$"<<tp1<<endl;
      // mystr = tp1.substr(0, tp1.find(" ", 0)); // ye humko category dega

      // tp1 = tp1.substr(tp1.find(" ", 0) + 1);  // category Hatana k baad
      //mystr = tp1.substr(0, tp1.find(" ", 0)); // ye humko add, mul,sub batayega

      // arithematic inst
      for (int i = 0; i < 24; i++)
      {
        if (instruction[0][i].second == mystr)
        {
          // instruction[0][i] is my instruction
          charString += instruction[0][i].first;
          charString += ".";
          // cout<<"char string 1="<<charString;
          cout<<"tp1 +++++++++"<<tp1<<endl;
          // tp1 = tp1.substr(tp1.find(" ", 0) + 1); // after instruction i.e., mod,type
          //  cout<<"tp1 66666"<<tp1<<endl;
          if (instruction[0][i].first == "add" || instruction[0][i].first == "sub")
          {
            cout<<"mai yaha tu kaha s"<<endl;
            cout<<"tp to shi h na bhai"<<tp1<<endl;
            charString += fpadd(tp1);
            // charString += ".";
             cout<<" f se ana"<<endl;
            goto Label;
            
          }
          else if (instruction[0][i].first == "mul" || instruction[0][i].first == "mul24" || instruction[0][i].first == "szext" || instruction[0][i].first == "szext" || instruction[0][i].first == "bmsk")
          {
            
            charString += fpadd(tp1);
            // charString += ".";
            cout<<"mai bhi yahibe"<<endl;
            goto Label;
          }
          else if (instruction[0][i].first == "mad" || instruction[0][i].first == "mad24") // as mad m .sat ho sakta hai
          {
            cout<<"uidhcsdhfcsjndfc"<<endl;
            charString += mad(tp1);
            // charString += ".";
            goto Label;
          }
          else if (instruction[0][i].first == "sad" || instruction[0][i].first == "div" || instruction[0][i].first == "rem" || instruction[0][i].first == "abs" || instruction[0][i].first == "neg" || instruction[0][i].first == "popc" || instruction[0][i].first == "clz" || instruction[0][i].first == "fns" || instruction[0][i].first == "brev" || instruction[0][i].first == "bfe" || instruction[0][i].first == "bfi") // dont have .sat
          {
            charString += sad(tp1);
            // charString += ".";
            goto Label;
          }
          else if (instruction[0][i].first == "min" || instruction[0][i].first == "max")
          {
            cout<<" yaha pat ayua hoga "<<endl;
            charString += min(tp1);
            // charString += ".";
            cout<<" yaha pat ayua hoga "<<endl;
            goto Label;
          }
          else if (instruction[0][i].first == "bfind")
          {
            charString += bfind(tp1);
            charString += ".";
            goto Label;
          }
          else if (instruction[0][i].first == "dp4a")
          {
            charString += dp4a(tp1);
            // charString += ".";
            goto Label;
          }
          else if (instruction[0][i].first == "dp2a")
          {
            charString += dp2a(tp1);
            // charString += ".";
            goto Label;
          }
        }
      }

  // floating point
      for (int i = 0; i < 18; i++)
      {
        if (mystr == instruction[1][i].first)
        {

          charString += instruction[1][i].second;
          charString += ".";
tp1 = tp1.substr(tp1.find(" ", 0) + 1); // after instruction i.e., mod,type
          if (instruction[1][i].second == "testp")
          {
            charString += testp(tp1);
            // charString += ".";
            goto Label;
          }
          else if (instruction[1][i].second == "copysign" || instruction[1][i].second == "mad") // sidha type hoga
          {
            charString += add(tp1);
            // charString += ".";
            goto Label;
          }
          else if (instruction[1][i].second == "add" || instruction[1][i].second == "sub" || instruction[1][i].second == "mul")
          {
            charString += fpadd(tp1);
            // charString += ".";
            goto Label;
          }
          else if (instruction[1][i].second == "fma")
          {
            charString += fma(tp1);
            // charString += ".";
            goto Label;
          }
          else if (instruction[1][i].second == "div")
          {
            charString += Fdiv(tp1);
            // charString += ".";
            goto Label;
          }
          else if (instruction[1][i].second == "abs" || instruction[1][i].second == "neg")
          {
            charString += hpfneg(tp1);
            // charString += ".";
            goto Label;
          }
          else if (instruction[1][i].second == "min" || instruction[1][i].second == "max")
          {
            charString += FPMin(tp1);
            // charString += ".";
            goto Label;
          }
          else if (instruction[1][i].second == "rcp" || instruction[1][i].second == "sqrt")
          {
            charString += rcp(tp1);
            // charString += ".";
            goto Label;
          }
          else if (instruction[1][i].second == "rsqrt" || instruction[1][i].second == "sin" || instruction[1][i].second == "cos" || instruction[1][i].second == "lg2" || instruction[1][i].second == "ex2" || instruction[1][i].second == "tanh")
          {
            charString += rsqrt(tp1);
            // charString += ".";
            goto Label;
          }
        }
      }

// half precision floating point instruction
      for (int i = 0; i < 10; i++)
      {
        if (instruction[2][i].first == mystr)
        {
       
          charString += instruction[2][i].second;
          charString += ".";
tp1 = tp1.substr(tp1.find(" ", 0) + 1); // after instruction i.e., mod,type
          if (instruction[2][i].second == "add" || instruction[2][i].second == "sub" || instruction[2][i].second == "mul")
          {
            charString += fpadd(tp1);
            // charString += ".";
            goto Label;
          }
          else if (instruction[2][i].second == "fma")
          {
            charString += hpffma(tp1);
            // charString += ".";
            goto Label;
          }
          else if (instruction[2][i].second == "neg" || instruction[2][i].second == "abs")
          {
            charString += hpfneg(tp1);
            // charString += ".";
            goto Label;
          }
          else if (instruction[2][i].second == "min" || instruction[2][i].second == "max")
          {
            charString += FPMin(tp1);
            // charString += ".";
            goto Label;
          }
          else if (instruction[2][i].second == "tanh" || instruction[2][i].second == "ex2")
          {
            charString += rsqrt(tp1);
            // charString += ".";
            goto Label;
          }
        }
      }

      // stack manipuylation
      for (int i = 0; i < 3; i++)
      {
        if (mystr == instruction[8][i].second)
        {


          bitString += instruction[8][i].first;
          bitString += ".";
          tp1 = tp1.substr(tp1.find(" ", 0) + 1); // after instruction i.e., mod,type
          if (instruction[8][i].first == "stacksave" || instruction[8][i].first == "stackrestore")
          {
            charString += add(tp1);
            // charString += ".";
            goto Label;
          }

          // alloca remaionig
        }

        cout << " bit string =" << charString << endl;
      }

      // load store (saagr)
      //  for (int i = 0; i < 18; i++)
      //       {
      //         string mystr2="";
      //         mystr2 = tp1.substr(tp1.find(" ", 0) + 1);
      //         string mystr3 =  tp1.substr(0, tp1.find(" ", 0));
      //           // cout<<"my str is "<<mystr<<endl;
      //           // cout<<"instruction[1][i] is "<<instruction[1][i].second<<endl;
      //           if (instruction[12][i].second == mystr3)
      //           {
      //               // instruction[0][i] is my instruction
      //               charString += instruction[12][i].second;
      //               charString += " ";
      //               // cout<<"char string 1="<<charString;
      //               tp1 = tp1.substr(tp1.find(" ", 0) + 1); // after instruction i.e., mod,type
      //               if (instruction[12][i].first == "ld")
      //               {
      //                    cout<<" f se ana"<<endl;
      //                   charString += ld(tp1);
      //                   charString += " ";
                        
      //               }
      //               else if (instruction[6][i].first == "mov")
      //               {
                        
      //                   charString += mov(tp1);
      //                   charString += " ";
      //               }
      //               else if (instruction[6][i].first == "st")
      //               {
                       
      //                   charString += st(tp1);
      //                   charString += " ";
      //               }
      //               else if (instruction[6][i].first == "shfl")
      //               {
                        
      //                   charString += shfl(tp1);
      //                   charString += " ";
      //               }
      //               else if (instruction[6][i].first == "prmt")
      //               {
                        
      //                   charString += prmt(tp1);
      //                   charString += " ";
      //               }
      //                else if (instruction[6][i].first == "ldu")
      //               {
                        
      //                   charString += ldu(tp1);
      //                   charString += " ";
      //               }
      //                else if (instruction[6][i].first == "prefetch")
      //               {
                        
      //                   charString += prefetch(tp1);
      //                   charString += " ";
      //               }
      //               else if (instruction[6][i].first == "prefetchu")
      //               {
      //                   charString += prefetchu(tp1);
      //                   charString += " ";
      //               }
      //               else if (instruction[6][i].first == "discard")
      //               {
      //                   charString += discard(tp1);
      //                   charString += " ";
      //               }
      //                else if (instruction[6][i].first == "applypriority")
      //               {
      //                   charString += applypriority(tp1);
      //                   charString += " ";
      //               }
      //                 else if (instruction[6][i].first == "cvt")
      //               {
      //                   charString += cvt(tp1);
      //                   charString += " ";
      //               }
      //                 else if (instruction[6][i].first == "cvta")
      //               {
      //                   charString += cvta(tp1);
      //                   charString += " ";
      //               }
      //                 else if (instruction[6][i].first == "cp")
      //               {
      //                   charString += cp(tp1);
      //                   charString += " ";
      //               }
      //                 else if (instruction[6][i].first == "isspacep")
      //               {
      //                   charString += isspacep(tp1);
      //                   charString += " ";
      //               }
      //                else if (instruction[6][i].first == "mapa")
      //               {
      //                   charString += mapa(tp1);
      //                   charString += " ";
      //               }
      //                else if (instruction[6][i].first == "getctarank")
      //               {
      //                   charString += getctarank(tp1);
      //                   charString += " ";
      //               }
                    
      //           }
      //       }


 // comparison and selection instuction
      for (int i = 0; i < 4; i++)
      {
        if (mystr == instruction[3][i].second)
        {


          charString += instruction[3][i].first;
          charString += ".";
          //tp1 = tp1.substr(tp1.find(" ", 0) + 1); // after instruction i.e., mod,type
          if (instruction[3][i].first == "set")
          {
            charString += HPSet(tp1);
            // charString += ".";
            goto Label;
          }
          else if (instruction[3][i].first == "setp")
          {
            cout<<" bhag ja "<<endl;
            cout<<"tp1 999999 "<<tp1<<endl;
            charString += HPSetp(tp1);
            // charString += ".";
            cout<<" bitString"<<charString<<endl;
            goto Label;
          }
          else if (instruction[3][i].first == "selp")
          {
            charString += add(tp1);
            // charString += ".";
            goto Label;
          }
          else if (instruction[3][i].first == "slct")
          {
            charString += slct(tp1);
            // charString += ".";
            goto Label;
          }
        }
      }





 // instruction for sagar
       for (int i = 0; i < 18; i++)
            {
                // cout<<"my str is "<<mystr<<endl;
                // cout<<"instruction[1][i] is "<<instruction[1][i].second<<endl;
                if (instruction[12][i].second == mystr2)
                {
                    // instruction[0][i] is my instruction
                    charString += instruction[12][i].first;
                    charString += ".";
                    // cout<<"char string 1="<<charString;
                    tp1 = tp1.substr(tp1.find(" ", 0) + 1); // after instruction i.e., mod,type
                    if (instruction[12][i].first == "ld")
                    {
         
                        charString += ld(tp1);
                        charString += "";
                       goto Label;
                        // cout<<" f se ana"<<endl;
                    }
                    else if (instruction[12][i].first == "mov")
                    {
                        cout<<" load k andadr se ana"<<endl;
                        charString += mov(tp1);
                        charString += "";
                         cout<<"loads k baad ++++++++ "<<charString<<endl;
                         goto Label;
                    }
                    else if (instruction[12][i].first == "st")
                    {
                       
                        charString += st(tp1);
                        // charString += "";
                        goto Label;
                    }
                    else if (instruction[12][i].first == "shfl")
                    {
                        
                        charString += shfl(tp1);
                        // charString += "";
                        goto Label;
                    }
                    else if (instruction[12][i].first == "prmt")
                    {
                        
                        charString += prmt(tp1);
                        // charString += "";
                        goto Label;
                    }
                     else if (instruction[12][i].first == "ldu")
                    {
                        
                        charString += ldu(tp1);
                        // charString += ".";
                        goto Label;
                    }
                     else if (instruction[12][i].first == "prefetch")
                    {
                        
                        charString += prefetch(tp1);
                        // charString += ".";
                        goto Label;
                    }
                    else if (instruction[12][i].first == "prefetchu")
                    {
                        charString += prefetchu(tp1);
                        // charString += ".";
                        goto Label;
                    }
                    else if (instruction[12][i].first == "discard")
                    {
                        charString += discard(tp1);
                        // charString += ".";
                        goto Label;
                    }
                     else if (instruction[12][i].first == "applypriority")
                    {
                        charString += applypriority(tp1);
                        // charString += ".";
                        goto Label;
                    }
                      else if (instruction[12][i].first == "cvt")
                    {
                        charString += cvt(tp1);
                        // charString += ".";
                        goto Label;
                    }
                      else if (instruction[12][i].first == "cvta")
                    {
                        charString += cvta(tp1);
                        // charString += ".";
                        goto Label;
                    }
                      else if (instruction[12][i].first == "cp")
                    {
                        charString += cp(tp1);
                      //  charString += ".";
                        goto Label;
                    }
                      else if (instruction[12][i].first == "isspacep")
                    {
                        charString += isspacep(tp1);
                        // charString += ".";
                        goto Label;
                    }
                     else if (instruction[12][i].first == "mapa")
                    {
                        charString += mapa(tp1);
                        // charString += ".";
                        goto Label;
                    }
                     else if (instruction[12][i].first == "getctarank")
                    {
                        charString += getctarank(tp1);
                        // charString += ".";
                        goto Label;
                    }
                    
                }
            }


























      //parallel execution
       for (int i = 0; i < 11; i++)
      {
        if (mystr == instruction[7][i].second)
        {


          charString += instruction[7][i].first;
          charString += " ";
          //  tp1 = tp1.substr(tp1.find(" ", 0) + 1); // after instruction i.e., mod,type

          if (instruction[7][i].first == "bar" || instruction[7][i].first == "barrier")
          {
            cout<<"yahalooo1232"<<endl;
            charString += bar(tp1);
            // charString += ".";
            goto Label;
          }
          else if (instruction[7][i].first == "atom")
          {
            cout<<"calling atom"<<endl;
            charString += atom(tp1);
            // charString += ".";
            goto Label;
          }
        }
      }

      // Half Precision Comparison Instructions
      for (int i = 0; i < 2; i++)
      {
        if (mystr == instruction[4][i].second)
        {


          charString += instruction[4][i].first;
          charString += " ";
          tp1 = tp1.substr(tp1.find(" ", 0) + 1); // after instruction i.e., mod,type
          if (instruction[4][i].first == "set")
          {
            charString += HPSet(tp1);
            // charString += ".";
          }
          else if (instruction[4][i].first == "setp")
          {
            cout<<"ab check hoga ----"<<endl;
            charString += HPSetp(tp1);
            // charString += ".";
            cout<<"ab check hogaya ----"<<endl;
            goto Label;
          }
        }
      }

      // Logic and Shift Instructions
      for (int i = 0; i < 9; i++)
      {
        if (mystr == instruction[5][i].second)
        {


          charString += instruction[5][i].first;
          charString += ".";
          // tp1 = tp1.substr(tp1.find(" ", 0) + 1); // after instruction i.e., mod,type
          if (instruction[5][i].first == "and" || instruction[5][i].first == "or" || instruction[5][i].first == "xor" || instruction[5][i].first == "not" || instruction[5][i].first == "cnot" || instruction[5][i].first == "lop3" || instruction[5][i].first == "shl" || instruction[5][i].first == "shr")
          {
            cout<<"tp1---"<<tp1<<endl;
            charString += add(tp1);
            // charString += ".";
            goto Label;
          }
          else if (instruction[5][i].first == "shf")
          {
            charString += shf(tp1); /////   left ****************
            // charString += ".";
            goto Label;
          }
        }
      }

     
      // for scalar video instructions
      for (int i = 0; i < 9; i++)
      {

        if (mystr == instruction[9][i].second)
        {
         

          charString += instruction[9][i].first;
          charString += ".";
          tp1 = tp1.substr(tp1.find(" ", 0) + 1); // after instruction i.e., mod,type

          if (instruction[9][i].first == "vadd" || instruction[9][i].first == "vsub" || instruction[9][i].first == "vabsdiff" || instruction[9][i].first == "vmin" || instruction[9][i].first == "vmax")
          {
            charString += vadd(tp1);
            // charString += ".";
            goto Label;
          }
          else if (instruction[9][i].first == "vshl" || instruction[9][i].first == "vshr")
          {
            charString += vshl(tp1);
            // charString += ".";
            goto Label;
          }
          else if (instruction[9][i].first == "vmad")
          {
            charString += vmad(tp1);
            //  charString += ".";
            goto Label;
          }
          else if (instruction[9][i].first == "vset")
          {
            charString += vset(tp1);
            //  charString += ".";
            goto Label;
          }
        }
      }

      // SMID instruction
      for (int i = 0; i < 14; i++)
      {
        if (mystr == instruction[10][i].second)
        {


          bitString += instruction[10][i].first;
          bitString += " ";
tp1 = tp1.substr(tp1.find(" ", 0) + 1); // after instruction i.e., mod,type
          if (instruction[10][i].first == "vadd2" || instruction[10][i].first == "vsub2" || instruction[10][i].first == "vavrg2" || instruction[10][i].first == "vabsdiff2" || instruction[10][i].first == "vmin2" || instruction[10][i].first == "vmax2")
          {
            charString += vadd2(tp1);
            //  charString += ".";
            goto Label;
          }
          else if (instruction[10][i].first == "vset2")
          {
            charString += vset2(tp1);
            //  charString += ".";
            goto Label;
          }
          else if (instruction[10][i].first == "vadd4" || instruction[10][i].first == "vsub4" || instruction[10][i].first == "vavrg4" || instruction[10][i].first == "vabsdiff4" || instruction[10][i].first == "vmin4" || instruction[10][i].first == "vmax4")
          {
            charString += vadd2(tp1);
            // charString += ".";
            goto Label;
          }
          // vset4 baki hai    ??
        }
      }

    
      

Label: ofstream outfile;
      outfile.open("ptx.txt", ios::app);
      cout<<"done )))))))))"<<tp3<<endl;
       outfile << charString << endl;
      // bitString = "";
      // // outfile << "hi hi" <<"\n" << endl;
      outfile.close();
      
    }
  }
  return 0;
}