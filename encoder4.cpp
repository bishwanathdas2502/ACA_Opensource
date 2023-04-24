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
vector<pair<string, string>> parallel;
vector<pair<string, string>> op;
vector<pair<string, string>> op2;
vector<pair<string, string>> cmp;
vector<pair<string, string>> boolOp;
vector<pair<string, string>> rnd;
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

string ltrim(string s)
{
  int ind = 0;
  cout<<"ifhcfhncvhnfcn"<<(int)s[0]<<endl;
  // for (int i = 0; i < s.size(); i++)
  // {
  //   if (s[i] == ' ')
  //   {
  //     ind++;
  //   }
  // }
if(s[0] == ' ')
{
s = s.substr(1);
}
  if(s[0] == '\t')
  {
    s = s.substr(1);
  }
 
  
  return s;
}

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

  s = s.substr(ind);
  return s;
}

string enocde(string s)
{
  cout<<"length of input"<<s.size()<<endl;
  string ans;
  for (auto ch : s)
  {
   
    bitset<8> bits(ch);
    string temp = bits.to_string();
    ans += temp;
  }

cout<<"length of out"<<ans.size()<<endl;
  return ans;
}

string add(string input)
{
  string mystr = input.substr(0, input.find(" ", 0));
  input = input.substr(input.find(" ", 0), input[input.length() - 1]); // ab sirf operand bache
  // cout<< " mystr space se pehel "<<mystr<<endl;
  // cout<<" input ->"<<input<<endl;

  cout << "return karna  fucntion m se pehle" << endl;
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
  cout << "return karna se pehle" << endl;
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
   cout<<"input for operand ==="<<input<<endl;
  bs += enocde(input);

  cout << " retuen karne time" << endl;
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
  cout << "bhai reutrn kar diya )))))" << endl;
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

// floationg point

string testp(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(".", 0)); // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);

  for (int i = 0; i < 6; i++)
  {
    if (mystr == op[i].first)
    {
      bs += op[i].second;
      bs += " ";
    }
  }

  mystr = input.substr(0, input.find(" ", 0));
  for (int i = 0; i < 10; i++) //
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

string fpadd(string input)
{
  cout<<"hi thete"<<endl;
  cout<<"input"<<input<<endl;
  string bs = "";
  string mystr = "";
  if (input.find(".", 0)!= string::npos)
  {
    cout<<"@@@@@@@@@@@@@@@@"<<endl;
    mystr = input.substr(0, input.find(".", 0));
    input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
    for (int i = 0; i < 4; i++) // rnd hoga to
    {
      if (mystr == rnd[i].first)
      {
        bs += rnd[i].second;
        bs += " ";

        if (input.find(".", 0))
        {
          mystr = input.substr(0, input.find(".", 0));
          input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
          // ftz -->  1
          cout<<"ftz h kya ????"<<endl;
          bs += "1";
          bs += " ";

          // type
          mystr = input.substr(0, input.find(" ", 0));
          input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
          for (int i = 0; i < 10; i++) // as add m direct type hoga
          {
            if (type[i].first == mystr)
            {
              bs += type[i].second;
              bs += " ";
            }
          }

          // operand
          bs += "11111111";
          bs += " ";
          input = ltrim(input);
          bs += enocde(input);
          return bs;
        }

        mystr = input.substr(0, input.find(" ", 0));
        input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
        for (int i = 0; i < 10; i++) // as add m direct type hoga
        {
          if (type[i].first == mystr)
          {
            bs += type[i].second;
            bs += " ";
          }
        }

        // operand
        bs += "11111111";
        bs += " ";
        input = ltrim(input);
        bs += enocde(input);
        return bs;
      }
    }

    ///
    for (int i = 0; i < 4; i++)
    {
      if (mode[i].first == mystr)
      {
        bs += mode[i].second;
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

        input = input.substr(input.find(" ", 0), input[input.length() - 1]);
        bs += "11111111";
        bs += " ";
        input = ltrim(input);
        bs += enocde(input);

        return bs;
      }
    }

    ////

    // varna sidha ftz ho sakta h
    // ftz -->  11010
    bs += "1";
    bs += " ";

    // type
    mystr = input.substr(0, input.find(" ", 0));
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
    for (int i = 0; i < 10; i++) // as add m direct type hoga
    {
      if (type[i].first == mystr)
      {
        bs += type[i].second;
        bs += " ";
      }
    }

    // operand
    bs += "11111111";
    bs += " ";
    input = ltrim(input);
    bs += enocde(input);
    return bs;
  }
  // agar rnd nhi h to and ftz bhi nhi h to sidha type

cout<<"sidha yaha par bhai ttttt"<<endl;
  mystr = input.substr(0, input.find(" ", 0)); // type
  input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);

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

string fpmul(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(".", 0));
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
  // ftz -->  11010
  bs += "11010";
  bs += " ";

  // type
  mystr = input.substr(0, input.find(" ", 0));
  input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
  for (int i = 0; i < 10; i++) // as add m direct type hoga
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }

  // operand
  bs += "11111111";
  bs += " ";
  input = ltrim(input);
  bs += enocde(input);
  return bs;
}

string fma(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(".", 0));
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
  for (int i = 0; i < 4; i++)
  {
    if (mystr == rnd[i].first)
    {
      bs += rnd[i].second;
      bs += " ";
    }
  }

  if (input.find(".", 0))
  {
    mystr = input.substr(0, input.find(".", 0));
    input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);

    if (mystr == "relu") // relu ---> 11011
    {
      bs += "11011";
      bs += " ";

      mystr = input.substr(0, input.find(" ", 0));
      input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);

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

    // varna ftz hai
    else if (mystr == "ftz")
    {
      // ftz -->  1
      bs += "1";
      bs += " ";

      // type
      mystr = input.substr(0, input.find(" ", 0));
      input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
      for (int i = 0; i < 10; i++) // as add m direct type hoga
      {
        if (type[i].first == mystr)
        {
          bs += type[i].second;
          bs += " ";
        }
      }

      // operand
      bs += "11111111";
      bs += " ";
      input = ltrim(input);
      bs += enocde(input);
      return bs;
    }
  }

  mystr = input.substr(0, input.find(" ", 0));
  input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
  for (int i = 0; i < 10; i++) // as add m direct type hoga
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }

  // operand
  bs += "11111111";
  bs += " ";
  input = ltrim(input);
  bs += enocde(input);
  return bs;
}

string Fdiv(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(".", 0));
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);

  if (mystr == "full" || mystr == "approx")
  {
    if (mystr == "full")
    {
      bs += "0";
      bs += " ";
    }
    else
    {
      bs += "1";
      bs += " ";
    }

    if (input.find(".", 0)) // ftz hoga
    {
      mystr = input.substr(0, input.find(".", 0)); // ftz ayega ya nhi
      input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
      if (mystr == "ftz")
      {
        bs += "11010";
        bs += " ";

        mystr = input.substr(0, input.find(" ", 0)); // type
        input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
        for (int i = 0; i < 10; i++) //
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
    }
    else // ftz nhi hoga
    {
      mystr = input.substr(0, input.find(" ", 0)); // type
      input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
      for (int i = 0; i < 10; i++) //
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
  }

  for (int i = 0; i < 4; i++)
  {
    if (mystr == rnd[i].first)
    {
      bs += rnd[i].second;
      bs += " ";
    }
  }

  if (input.find(".", 0)) // ftz hoga
  {
    mystr = input.substr(0, input.find(".", 0)); // ftz ayega ya nhi
    input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
    if (mystr == "ftz")
    {
      bs += "1";
      bs += " ";

      mystr = input.substr(0, input.find(" ", 0)); // type
      input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
      for (int i = 0; i < 10; i++) //
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
  }
  else // ftz nhi hoga
  {
    mystr = input.substr(0, input.find(" ", 0)); // type
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
    for (int i = 0; i < 10; i++) //
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
}

string FPMin(string input)
{
  string bs = "";
  string mystr = "";
  if (!input.find(".", 0)) // . nhi mila to sidha type h
  {
    mystr = input.substr(0, input.find(" ", 0)); // type
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
    for (int i = 0; i < 10; i++) //
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

  else
  {
    mystr = input.substr(0, input.find(".", 0)); //
    input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
    // ftz - 00    , NAN - 01    , xorsign.abs - 10
    if (mystr == "ftz")
    {
      bs += "00";
      bs += " ";
      mystr = input.substr(0, input.find(" ", 0)); // type
      input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
      for (int i = 0; i < 10; i++) //
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
    else if (mystr == "NaN")
    {
      bs += "01";
      bs += " ";
      mystr = input.substr(0, input.find(" ", 0)); // type
      input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
      for (int i = 0; i < 10; i++) //
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
    else if (mystr == "xorsign")
    {

      bs += "10";
      bs += " ";
      mystr = input.substr(0, input.find(" ", 0)); // type
      input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
      for (int i = 0; i < 10; i++) //
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
  }
}

string rcp(string input)
{
  string bs = "";
  string mystr = "";
  mystr = input.substr(0, input.find(".", 0));
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
  // approx hoga / rnd
  if (mystr == "approx") // rnd 2 bit ka hai ---> approx = 1
  {
    bs += "1";
    bs += " ";

    if (input.find(".", 0)) // ftz
    {
      mystr = input.substr(0, input.find(".", 0));
      input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
      if (mystr == "ftz")
      {
        bs += "1";
        bs += " ";

        mystr = input.substr(0, input.find(" ", 0)); // type
        input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
        for (int i = 0; i < 10; i++) //
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
    }

    else
    {
      mystr = input.substr(0, input.find(" ", 0)); // type
      input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
      for (int i = 0; i < 10; i++) //
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
  }

  // rnd m se kuch hoga

  else if (mystr == "ftz") //   sidha ftz AND type   -- 0
  {
    bs += "0";
    bs += " ";

    mystr = input.substr(0, input.find(" ", 0)); // type
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
    for (int i = 0; i < 10; i++) //
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

  for (int i = 0; i < 4; i++) // rnd ... hoga
  {
    if (mystr == rnd[i].first)
    {
      bs += rnd[i].second;
      bs += " ";

      if (input.find(".", 0)) // ftz
      {
        mystr = input.substr(0, input.find(".", 0));
        input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
        if (mystr == "ftz")
        {
          bs += "1";
          bs += " ";

          mystr = input.substr(0, input.find(" ", 0)); // type
          input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
          for (int i = 0; i < 10; i++) //
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
      }

      else // ftz nhi hia
      {
        mystr = input.substr(0, input.find(" ", 0)); // type
        input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
        for (int i = 0; i < 10; i++) //
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
    }
  }
}

string rsqrt(string input)
{
  string bs = "";
  string mystr = "";
  mystr = input.substr(0, input.find(".", 0));
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);

  // approx hi hoag ---> 1
  bs += "1";
  bs += " ";

  if (input.find(".", 0))
  {

    mystr = input.substr(0, input.find(".", 0));
    input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);

    if (mystr == "ftz") // 1
    {
      bs += "1";
      bs += " ";

      mystr = input.substr(0, input.find(" ", 0)); // type
      input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
      for (int i = 0; i < 10; i++) //
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
  }

  else
  {
    mystr = input.substr(0, input.find(" ", 0)); // type
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
    for (int i = 0; i < 10; i++) //
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
}

// half precision floating point

string hpfadd(string input)
{
  string bs = "";
  string mystr = "";

  if (input.find(".", 0)) // rnd hai
  {
    mystr = input.substr(0, input.find(".", 0));
    input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
    for (int i = 0; i < 4; i++)
    {
      if (mystr == rnd[i].first)
      {
        bs += rnd[i].second;
        bs += " ";

        mystr = input.substr(0, input.find(" ", 0)); // type
        input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);

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
    }
  }

  else
  {
    mystr = input.substr(0, input.find(" ", 0)); // type
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);

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
}

string hpffma(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(".", 0));
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
  for (int i = 0; i < 4; i++)
  {
    if (mystr == rnd[i].first)
    {
      bs += rnd[i].second;
      bs += " ";
    }
  }

  if (input.find(".", 0))
  {
    mystr = input.substr(0, input.find(".", 0));
    input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);

    if (mystr == "relu") // relu ---> 11011
    {
      bs += "11011";
      bs += " ";
    }
    mystr = input.substr(0, input.find(" ", 0));
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);

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
  else
  {
    mystr = input.substr(0, input.find(" ", 0));
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);

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
}

string hpfneg(string input)
{
  string bs = "";
  string mystr = "";
  if (input.find(".", 0)) // ftz --->> 11010

  {
    mystr = input.substr(0, input.find(".", 0));
    input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
    if (mystr == "ftz")
    {
      bs += "1";
      bs += " ";
    }
    mystr = input.substr(0, input.find(" ", 0));
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);

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

  else
  {
    mystr = input.substr(0, input.find(" ", 0));
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);

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
}

// pareallel
string bar(string input)
{

  string bs = "";
  string mystr = input.substr(0, input.find(".", 0)); // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
  if (mystr == "cta")
  {
    bs += "1";
    bs += " ";

    if (!input.find(".", 0))
    {
      mystr = input.substr(0, input.find(" ", 0));
      input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
      for (int i = 0; i < 3; i++)
      {
        if (mystr == parallel[i].first)
        {
          bs += parallel[i].second;
          bs += " ";

          bs += "11111111";
          bs += " ";
          input = ltrim(input);
          bs += enocde(input);
          cout << "yaha" << endl;
          return bs;
        }
      }
    }
  }
  else if (mystr == "wrap")
  {
    bs += "11";
    bs += " ";

    mystr = input.substr(0, input.find(" ", 0));
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
    for (int i = 0; i < 3; i++)
    {
      if (mystr == parallel[i].first)
      {
        bs += parallel[i].second;
        bs += " ";

        bs += "11111111";
        bs += " ";
        input = ltrim(input);
        bs += enocde(input);
        cout << "yaha" << endl;
        return bs;
      }
    }
  }

  cout << "I am in" << endl;

  cout << "yaha par" << endl;
  mystr = input.substr(0, input.find(" ", 0));
  input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
  for (int i = 0; i < 3; i++)
  {
    if (mystr == parallel[i].first)
    {
      bs += parallel[i].second;
      bs += " ";

      bs += "11111111";
      bs += " ";
      input = ltrim(input);
      bs += enocde(input);
      cout << "yaha" << endl;
      return bs;
    }
  }
}

string atom(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(".", 0)); // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
  if (mystr == "global") // 0
  {
    bs += "0";
    bs += " ";

    mystr = input.substr(0, input.find(".", 0)); // op2
    input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
    for (int i = 0; i < 9; i++)
    {
      if (mystr == op2[i].first)
      {
        bs += op2[i].second;
        bs += " ";
      }
    }

    mystr = input.substr(0, input.find(" ", 0)); // op2
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
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
    cout << "yahalooo" << endl;
    return bs;
  }
  else if (mystr == "shared::cta") // 1
  {
    bs += "1";
    bs += " ";

    mystr = input.substr(0, input.find(".", 0)); // op2
    input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
    for (int i = 0; i < 9; i++)
    {
      if (mystr == op2[i].first)
      {
        bs += op2[i].second;
        bs += " ";
      }
    }

    mystr = input.substr(0, input.find(" ", 0)); // op2
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
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
}

// sclaer video vale functions
string vadd(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(".", 0));                      // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
  for (int i = 0; i < 10; i++)
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }
  mystr = input.substr(0, input.find(".", 0));                             // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
  for (int i = 0; i < 10; i++)
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }
  mystr = input.substr(0, input.find(".", 0));                             // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
  for (int i = 0; i < 10; i++)
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }
  // kya op2 hai ?
  if (input.find(".", 0))
  {
    mystr = input.substr(0, input.find(".", 0));                             // sat --> 101 | 1 op2 hai
    input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
    bs += "1011";
    bs += " ";

    mystr = input.substr(0, input.find(" ", 0));                             // op2
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
    if (mystr == "add")
    {
      bs += "00";
      bs += " ";
    }
    else if (mystr == "min")
    {
      bs += "01";
      bs += " ";
    }
    else if (mystr == "max")
    {
      bs += "10";
      bs += " ";
    }

    bs += "11111111";
    bs += " ";
    input = ltrim(input);
    bs += enocde(input);
    return bs;
  }
  else // sat --> 101 | 0   op2 nhi hai
  {
    mystr = input.substr(0, input.find(" ", 0));                             // sat
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
    bs += "1010";
    bs += " ";

    bs += "11111111";
    bs += " ";
    input = ltrim(input);
    bs += enocde(input);
    return bs;
  }
}

string vshl(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(".", 0));                      // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
  for (int i = 0; i < 10; i++)
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }
  mystr = input.substr(0, input.find(".", 0));                             // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
  for (int i = 0; i < 10; i++)
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }
  mystr = input.substr(0, input.find(".", 0));                             // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
  for (int i = 0; i < 10; i++)
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }
  // mode
  mystr = input.substr(0, input.find(" ", 0));                             // sat
  input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
  for (int i = 0; i < 4; i++)
  {
    if (mode[i].first == mystr)
    {
      bs += mode[i].second;
      bs += " ";
    }
  }

  bs += "11111111";
  bs += " ";
  input = ltrim(input);
  bs += enocde(input);
  return bs;
}

string vmad(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(".", 0));                      // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
  for (int i = 0; i < 10; i++)
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }
  mystr = input.substr(0, input.find(".", 0));                             // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
  for (int i = 0; i < 10; i++)
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }
  mystr = input.substr(0, input.find(".", 0));                             // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
  for (int i = 0; i < 10; i++)
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }

  mystr = input.substr(0, input.find(" ", 0));                             //
  input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]); //
  if (mystr == "sat")
  {
    bs += "101";
    bs += " ";
  }
  else
  {
    for (int i = 0; i < 2; i++)
    {
      if (mystr == scale[i].first)
      {
        bs += scale[i].second;
        bs += " ";
      }
    }
  }

  bs += "11111111";
  bs += " ";
  input = ltrim(input);
  bs += enocde(input);
  return bs;
}

string vset(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(".", 0));                      // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
  for (int i = 0; i < 10; i++)
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }
  mystr = input.substr(0, input.find(".", 0));                             // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
  for (int i = 0; i < 10; i++)
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }

  if (input.find(".", 0))
  {
    mystr = input.substr(0, input.find(".", 0));                             // 1st . tak jo mila vo mode hoga
    input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
    for (int i = 0; i < 6; i++)
    {
      if (mystr == cmp[i].first)
      {
        bs += cmp[i].second;
        bs += " ";
      }
    }

    mystr = input.substr(0, input.find(" ", 0));                             // 1st . tak jo mila vo mode hoga
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
    for (int i = 0; i < 9; i++)
    {
      if (mystr == op2[i].first)
      {
        bs += op2[i].second;
        bs += " ";
      }
    }

    bs += "11111111";
    bs += " ";
    input = ltrim(input);
    bs += enocde(input);
    return bs;
  }
  else
  {
    mystr = input.substr(0, input.find(" ", 0));                             // 1st . tak jo mila vo mode hoga
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab

    for (int i = 0; i < 6; i++)
    {
      if (mystr == cmp[i].first)
      {
        bs += cmp[i].second;
        bs += " ";
      }
    }
    bs += "11111111";
    bs += " ";
    input = ltrim(input);
    bs += enocde(input);
    return bs;
  }
}

string Set(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(".", 0));                      // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
  for (int i = 0; i < 18; i++)
  {
    if (mystr == cmp[i].first)
    {
      bs += cmp[i].second;
      bs += " ";
    }
  }
  mystr = input.substr(0, input.find(".", 0));                             // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
  // ab ya to mystr --- boolop hoga ya to direct type
  for (int i = 0; i < 3; i++)
  {
    if (mystr == boolOp[i].first)
    {
      bs += boolOp[i].second;
      bs += " ";
      // T1
      mystr = input.substr(0, input.find(".", 0));                             // 1st . tak jo mila vo mode hoga
      input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
      for (int i = 0; i < 10; i++)
      {
        if (type[i].first == mystr)
        {
          bs += type[i].second;
          bs += " ";
        }
      }

      mystr = input.substr(0, input.find(" ", 0)); // 1st . tak jo mila vo mode hoga
      input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
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
  }

  mystr = input.substr(0, input.find(".", 0));                             // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
  for (int i = 0; i < 10; i++)
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }

  mystr = input.substr(0, input.find(" ", 0)); // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
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

string Setp(string input)
{
  cout<<"ayoayo"<<endl;
  string bs = "";
  string mystr = input.substr(0, input.find(".", 0));                      // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
  cout<<"mystr = "<<mystr<<endl;
  for (int i = 0; i < 18; i++)
  {
    if (mystr == cmp[i].first)
    {
      bs += cmp[i].second;
      bs += " ";
    }
  }

  if(input.find(".", 0) != string::npos )
  {
  mystr = input.substr(0, input.find(".", 0));                             // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
  for (int i = 0; i < 3; i++)
  {
    if (mystr == boolOp[i].first)
    {
      bs += boolOp[i].second;
      bs += " ";
      // T1

      mystr = input.substr(0, input.find(" ", 0)); // 1st . tak jo mila vo mode hoga
      input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
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
      cout<<"input ---"<<input<<endl;
      input = ltrim(input);
      cout<<"input ---"<<input<<endl;
      bs += enocde(input);
      cout << "return karne jaa rahe" << endl;
      return bs;
    }
  }

  }
  mystr = input.substr(0, input.find(" ", 0)); // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);

  cout<<"bool op nhi mila "<<endl;
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
  cout<<"input 1"<<input<<endl;
  input = ltrim(input);
  cout<<"input 2"<<input<<endl;
  bs += enocde(input);
  cout << "return karne jaa rahe" << endl;
  return bs;
}

string slct(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(".", 0));                      // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
  if (mystr == "ftz")                                                      // ftz ---> 0011
  {
    bs += "0011";
    bs += " ";

    mystr = input.substr(0, input.find(".", 0));                             // 1st . tak jo mila vo mode hoga
    input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
    for (int i = 0; i < 10; i++)
    {
      if (type[i].first == mystr)
      {
        bs += type[i].second;
        bs += " ";
      }
    }

    mystr = input.substr(0, input.find(" ", 0)); // 1st . tak jo mila vo mode hoga
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
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

  mystr = input.substr(0, input.find(".", 0));                             // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
  for (int i = 0; i < 10; i++)
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }

  mystr = input.substr(0, input.find(" ", 0)); // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
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

// half precision comp
string HPSet(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(".", 0));                      // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab

  // mystr == cmp
  for (int i = 0; i < 17; i++)
  {
    if (mystr == cmp[i].first)
    {
      bs += cmp[i].second;
      bs += " ";
    }
  }

  mystr = input.substr(0, input.find(".", 0));                             // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab

  // agar to boolOP hai
  for (int i = 0; i < 3; i++)
  {
    if (mystr == boolOp[i].first)
    {
      bs += boolOp[i].second;
      bs += " ";

      // 2 baar type
      mystr = input.substr(0, input.find(".", 0));                             // 1st . tak jo mila vo mode hoga
      input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
      for (int i = 0; i < 10; i++)
      {
        if (type[i].first == mystr)
        {
          bs += type[i].second;
          bs += " ";
        }
      }

      mystr = input.substr(0, input.find(" ", 0)); // 1st . tak jo mila vo mode hoga
      input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
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
  }

  // agar nhi hai
  for (int i = 0; i < 10; i++)
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }

  mystr = input.substr(0, input.find(" ", 0)); // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
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

string HPSetp(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(".", 0));                      // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab

  for (int i = 0; i < 17; i++)
  {
    if (mystr == cmp[i].first)
    {
      bs += cmp[i].second;
      bs += " ";
    }
  }

  if (input.find(".", 0)) // agar . mila
  {
    mystr = input.substr(0, input.find(".", 0));                             // 1st . tak jo mila vo mode hoga
    input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab

    for (int i = 0; i < 3; i++)
    {
      if (mystr == boolOp[i].first)
      {
        bs += boolOp[i].second;
        bs += " ";

        // 1 baar type

        mystr = input.substr(0, input.find(" ", 0)); // 1st . tak jo mila vo mode hoga
        input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
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
        cout<<" input 1 "<<input<<endl;
        input = ltrim(input);
        cout<<" input 2 "<<input<<endl;
        bs += enocde(input);
        return bs;
      }
    }
  }

  else
  {
    mystr = input.substr(0, input.find(" ", 0)); // 1st . tak jo mila vo mode hoga
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
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
}

// load store (sagar)

string mov(string input)
{
  string mystr = input.substr(0, input.find(" ", 0));
  input = input.substr(input.find(" ", 0), input[input.length() - 1]); // ab sirf operand bache
  
  string bs = "";
  for (int i = 0; i < 18; i++) // as add m direct type hoga
  {
    // cout<<" 123"<<endl;
    if (type[i].first == mystr)
    {
      // cout<<" hi ji"<<endl;
      bs += type[i].second;
      bs += " ";
      break;
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

string shfl(string input)
{
  // next 1st . tak mode batayega
  string bs = "";
  if (input.find("sync") != -1) 
  {
    bs=bs+"1";
    bs+=" ";
  }
  else
  {
    bs=bs+"0";
    bs+=" ";
  }

  string mystr = input.substr(0, input.find(".", 0)); 

  for (int i = 5; i < 9; i++)
  {
    if (mode[i].first == mystr)
    {
      bs += mode[i].second;
      bs += " ";
      break;
    }
  }

  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
  mystr = input.substr(0, input.find(" ", 0));

  for (int i = 0; i < 18; i++)
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
      break;
    }
  }

  input = input.substr(input.find(" ", 0), input[input.length() - 1]);
  bs += "11111111";
  bs += " ";
  input = ltrim(input);
  bs += enocde(input);

  return bs;
}

string prmt(string input)
{
  // next 1st . tak mode batayega
  string bs="";
  string mystr = input.substr(0, input.find(".", 0)); 

  for (int j = 0; j <18; j++)
  {
    if (type[j].first == mystr)
    {
      bs += type[j].second;
      bs += " ";
      break;
    }
  }

 if(input.find(".")!=-1)
 {
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
  mystr = input.substr(0, input.find(" ", 0));
  for (int i = 0; i < 15; i++)
  {
    if (mode[i].first == mystr)
    {
      bs += mode[i].second;
      bs += " ";
      break;
    }
  }
 }

  input = input.substr(input.find(" ", 0), input[input.length() - 1]);
  bs += "11111111";
  bs += " ";
  input = ltrim(input);
  bs += enocde(input);

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

string ld(string input)
{
  //separate opcode and operand first
  vector<string> spaceSepareted;
  tokenize(input," ",spaceSepareted);
  string opcode=spaceSepareted[0];
  string operand;
  for(int i=1;i<spaceSepareted.size();i++)
  {
    operand+=spaceSepareted[i];
  }
  
  string bs="";
  vector<string> inputString;
  cout<<"opcode is "<<opcode<<endl;
  tokenize(opcode,".",inputString);
  cout<<"input string after tokenization"<<endl;
  for(int i=0;i<inputString.size();i++)
  {
    cout<<inputString[i]<<" ";
  }
  cout<<endl;
  for(int i=0;i<inputString.size();i++)
  {
   //cout<<"Input string is "<<inputString[i]<<endl;
   for (int j = 0; j <4; j++)
   {
        if (qualifier[j].first == inputString[i])
        {
          bs += qualifier[j].second;
          bs += " ";
          break;
        }
   }

   if(inputString[i]=="nc")
   {
    bs+="01";
    bs += " ";
   }

   for (int j = 0; j <8; j++)
   {
        if (ss[j].first == inputString[i])
        {
          bs += ss[j].second;
          bs += " ";
          break;
        }
   }

   for (int j = 0; j <5; j++)
   {
        if (cop[j].first == inputString[i])
        {
          bs += cop[j].second;
          bs += " ";
          break;
        }
   }

   for (int j = 0; j <5; j++)
   {
        if (eviction_priority[j].first == inputString[i])
        {
          bs += eviction_priority[j].second;
          bs += " ";
          break;
        }
   }

   
  if (cache_hint[0].first == inputString[i])
    {
          bs += cache_hint[0].second;
          bs += " ";
    }

  for (int j = 0; j <3; j++)
   {
        if (prefetch_size[j].first == inputString[i])
        {
          bs += prefetch_size[j].second;
          bs += " ";
          break;
        }
   }
   for (int j = 0; j <2; j++)
   {
        if (vec[j].first == inputString[i])
        {
          bs += vec[j].second;
          bs += " ";
          break;
        }
   }

  for (int j = 0; j <18; j++)
  {
    if (type[j].first == inputString[i])
    {
      bs += type[j].second;
      bs += " ";
      break;
    }
  }

  }
  
  bs += "11111111";
  bs += " ";
  cout<<"operand-"<<operand<<endl;
  operand = ltrim2(operand);
  cout<<"operand ^^^^^^^^^^^^-"<<operand<<endl;
  bs += enocde(operand);
  return bs;
}

string ldu(string input)
{
  //separate opcode and operand first
  vector<string> spaceSepareted;
  tokenize(input," ",spaceSepareted);
  string opcode=spaceSepareted[0];
  string operand;
  for(int i=1;i<spaceSepareted.size();i++)
  {
    operand+=spaceSepareted[i];
  }
  string bs="";
  vector<string> inputString;
  tokenize(opcode,".",inputString);
  for(int i=0;i<inputString.size();i++)
  {
   for (int j = 0; j <8; j++)
   {
        if (ss[j].first == inputString[i])
        {
          bs += ss[j].second;
          bs += " ";
          break;
        }
   }

   for (int j = 0; j <2; j++)
   {
        if (vec[j].first == inputString[i])
        {
          bs += vec[j].second;
          bs += " ";
          break;
        }
   }

  for (int j = 0; j <18; j++)
  {
    if (type[j].first == inputString[i])
    {
      bs += type[j].second;
      bs += " ";
      break;
    }
  }

  }
 
  bs += "11111111";
  bs += " ";
  input = ltrim(operand);
  bs += enocde(operand);
  return bs;
}

string st(string input)
{
  //separate opcode and operand first
  vector<string> spaceSepareted;
  tokenize(input," ",spaceSepareted);
  string opcode=spaceSepareted[0];
  string operand;
  for(int i=1;i<spaceSepareted.size();i++)
  {
    operand+=spaceSepareted[i];
  }
  string bs="";
  vector<string> inputString;
  tokenize(opcode,".",inputString);
  for(int i=0;i<inputString.size();i++)
  {
   for (int j = 0; j <5; j++)
   {
        if (qualifier[j].first == inputString[i])
        {
          bs += qualifier[j].second;
          bs += " ";
          break;
        }
   }

   for (int j = 0; j <4; j++)
   {
        if (scope[j].first == inputString[i])
        {
          bs += scope[j].second;
          bs += " ";
          break;
        }
   }


   for (int j = 0; j <8; j++)
   {
        if (ss[j].first == inputString[i])
        {
          bs += ss[j].second;
          bs += " ";
          break;
        }
   }

   for (int j = 0; j <7; j++)
   {
        if (cop[j].first == inputString[i])
        {
          bs += cop[j].second;
          bs += " ";
          break;
        }
   }

  

   for (int j = 0; j <5; j++)
   {
        if (eviction_priority[j].first == inputString[i])
        {
          bs += eviction_priority[j].second;
          bs += " ";
          break;
        }
   }

   
  if (cache_hint[0].first == inputString[i])
    {
          bs += cache_hint[0].second;
          bs += " ";
    }

   for (int j = 0; j <2; j++)
   {
        if (vec[j].first == inputString[i])
        {
          bs += vec[j].second;
          bs += " ";
          break;
        }
   }

  for (int j = 0; j <18; j++)
  {
    if (type[j].first == inputString[i])
    {
      bs += type[j].second;
      bs += " ";
      break;
    }
  }

  }
 
  bs += "11111111";
  bs += " ";
  input = ltrim(operand);
  bs += enocde(operand);
  return bs;
}

string prefetch(string input)
{
  //separate opcode and operand first
  vector<string> spaceSepareted;
  tokenize(input," ",spaceSepareted);
  string opcode=spaceSepareted[0];
  string operand;
  for(int i=1;i<spaceSepareted.size();i++)
  {
    operand+=spaceSepareted[i];
  }
  string bs="";
  vector<string> inputString;
  tokenize(opcode,".",inputString);
  for(int i=0;i<inputString.size();i++)
  {
   for (int j = 0; j <2; j++)
   {
        if (space[j].first == inputString[i])
        {
          bs += space[j].second;
          bs += " ";
          break;
        }
   }

   for (int j = 0;j<2;j++)
   {
        if (level[j].first == inputString[i])
        {
          bs += level[j].second;
          bs += " ";
          break;
        }
   }

   for (int j = 0; j <5; j++)
   {
        if (eviction_priority[j].first == inputString[i])
        {
          bs += eviction_priority[j].second;
          bs += " ";
          break;
        }
   }

  if(tensor[0].first == inputString[i])
  {
    bs += tensor[0].second;
    bs += " ";
    break;
  }

  }
 
  bs += "11111111";
  bs += " ";
  input = ltrim(operand);
  bs += enocde(operand);
  return bs;
}

string prefetchu(string input)
{
  //separate opcode and operand first
  vector<string> spaceSepareted;
  tokenize(input," ",spaceSepareted);
  string opcode=spaceSepareted[0];
  string operand;
  for(int i=1;i<spaceSepareted.size();i++)
  {
    operand+=spaceSepareted[i];
  }
  string bs="";
  vector<string> inputString;
  tokenize(opcode,".",inputString);
  for(int i=0;i<inputString.size();i++)
  {
   for (int j = 0;j<2;j++)
   {
        if (level[j].first == inputString[i])
        {
          bs += level[j].second;
          bs += " ";
          break;
        }
   }
  }
 
  bs += "11111111";
  bs += " ";
  input = ltrim(operand);
  bs += enocde(operand);
  return bs;
}

string applypriority(string input)
{
  //separate opcode and operand first
  vector<string> spaceSepareted;
  tokenize(input," ",spaceSepareted);
  string opcode=spaceSepareted[0];
  string operand;
  for(int i=1;i<spaceSepareted.size();i++)
  {
    operand+=spaceSepareted[i];
  }
  string bs="";
  vector<string> inputString;
  tokenize(opcode,".",inputString);
  for(int i=0;i<inputString.size();i++)
  {
   for (int j = 0; j <2; j++)
   {
        if (space[j].first == inputString[i])
        {
          bs += space[j].second;
          bs += " ";
          break;
        }
   }
   if (eviction_priority_l2[0].first == inputString[i])
   {
          bs += eviction_priority_l2[0].second;
          bs += " ";
   }

  }
 
  bs += "11111111";
  bs += " ";
  input = ltrim(operand);
  bs += enocde(operand);
  return bs;
}

string discard(string input)
{
  //separate opcode and operand first
  vector<string> spaceSepareted;
  tokenize(input," ",spaceSepareted);
  string opcode=spaceSepareted[0];
  string operand;
  for(int i=1;i<spaceSepareted.size();i++)
  {
    operand+=spaceSepareted[i];
  }
  string bs="";
  vector<string> inputString;
  tokenize(opcode,".",inputString);
  for(int i=0;i<inputString.size();i++)
  {

   for (int j = 0; j <2; j++)
   {
        if (space[j].first == inputString[i])
        {
          bs += space[j].second;
          bs += " ";
          break;
        }
   }

   for (int j = 0;j<2;j++)
   {
        if (level[j].first == inputString[i])
        {
          bs += level[j].second;
          bs += " ";
          break;
        }
   }
  }
 
  bs += "11111111";
  bs += " ";
  input = ltrim(operand);
  bs += enocde(operand);
  return bs;
}

string isspacep(string input)  //Check this
{
  //separate opcode and operand first
  vector<string> spaceSepareted;
  tokenize(input," ",spaceSepareted);
  string opcode=spaceSepareted[0];
  string operand;
  for(int i=1;i<spaceSepareted.size();i++)
  {
    operand+=spaceSepareted[i];
  }
  string bs="";
  vector<string> inputString;
  tokenize(opcode,".",inputString);
  for(int i=0;i<inputString.size();i++)
  {
   for (int j = 0; j <8; j++)
   {
        if (ss[j].first == inputString[i])
        {
          bs += ss[j].second;
          bs += " ";
          break;
        }
   }
  }
 
  bs += "11111111";
  bs += " ";
  input = ltrim(operand);
  bs += enocde(operand);
  return bs;
}

string cvt(string input)
{
  //separate opcode and operand first
  vector<string> spaceSepareted;
  tokenize(input," ",spaceSepareted);
  string opcode=spaceSepareted[0];
  string operand;
  for(int i=1;i<spaceSepareted.size();i++)
  {
    operand+=spaceSepareted[i];
  }
  string bs="";
  vector<string> inputString;
  tokenize(opcode,".",inputString);
  for(int i=0;i<inputString.size();i++)
  {
   for (int j = 0; j <8; j++)
   {
        if (ss[j].first == inputString[i])
        {
          bs += ss[j].second;
          bs += " ";
          break;
        }
   }
  for (int j = 0; j <20; j++)
   {
    if (type[j].first == inputString[i])
    {
      bs += type[j].second;
      bs += " ";
      break;
    }
   }
  }
 
  bs += "11111111";
  bs += " ";
  input = ltrim(operand);
  bs += enocde(operand);
  return bs;
}

string cvta(string input)
{
  //separate opcode and operand first
  vector<string> spaceSepareted;
  tokenize(input," ",spaceSepareted);
  string opcode=spaceSepareted[0];
  string operand;
  for(int i=1;i<spaceSepareted.size();i++)
  {
    operand+=spaceSepareted[i];
  }
  string bs="";
  vector<string> inputString;
  tokenize(opcode,".",inputString);
  for(int i=0;i<inputString.size();i++)
  {
   for (int j = 0; j <8; j++)
   {
        if (ss[j].first == inputString[i])
        {
          bs += ss[j].second;
          bs += " ";
        }
   }
  for (int j = 0; j <18; j++)
   {
    if (type[j].first == inputString[i])
    {
      bs += type[j].second;
      bs += " ";
      break;
    }
   }
  }
 
  bs += "11111111";
  bs += " ";
  input = ltrim(operand);
  bs += enocde(operand);
  return bs;
}

string mapa(string input)
{
  //separate opcode and operand first
  vector<string> spaceSepareted;
  tokenize(input," ",spaceSepareted);
  string opcode=spaceSepareted[0];
  string operand;
  for(int i=1;i<spaceSepareted.size();i++)
  {
    operand+=spaceSepareted[i];
  }
  string bs="";
  vector<string> inputString;
  tokenize(opcode,".",inputString);
  for(int i=0;i<inputString.size();i++)
  {
   for (int j = 0; j <8; j++)
   {
        if (ss[j].first == inputString[i])
        {
          bs += ss[j].second;
          bs += " ";
          break;
        }
   }
  for (int j = 0; j <18; j++)
   {
    if (type[j].first == inputString[i])
    {
      bs += type[j].second;
      bs += " ";
    }
   }
  }
 
  bs += "11111111";
  bs += " ";
  input = ltrim(operand);
  bs += enocde(operand);
  return bs;
}

string getctarank(string input)
{
  //separate opcode and operand first
  vector<string> spaceSepareted;
  tokenize(input," ",spaceSepareted);
  string opcode=spaceSepareted[0];
  string operand;
  for(int i=1;i<spaceSepareted.size();i++)
  {
    operand+=spaceSepareted[i];
  }
  string bs="";
  vector<string> inputString;
  tokenize(opcode,".",inputString);
  for(int i=0;i<inputString.size();i++)
  {
   for (int j = 0; j <8; j++)
   {
        if (ss[j].first == inputString[i])
        {
          bs += ss[j].second;
          bs += " ";
          break;
        }
   }
  for (int j = 0; j <18; j++)
   {
    if (type[j].first == inputString[i])
    {
      bs += type[j].second;
      bs += " ";
      break;
    }
   }
  }
 
  bs += "11111111";
  bs += " ";
  input = ltrim(operand);
  bs += enocde(operand);
  return bs;
}

string cp(string input)
{
  //separate opcode and operand first
  vector<string> spaceSepareted;
  tokenize(input," ",spaceSepareted);
  string opcode=spaceSepareted[0];
  string operand;
  for(int i=1;i<spaceSepareted.size();i++)
  {
    operand+=spaceSepareted[i];
  }
  string bs="";
  vector<string> inputString;
  tokenize(opcode,".",inputString);
  for(int i=0;i<inputString.size();i++)
  {
   for (int j = 0; j <12; j++)
   {
        if (cp_ops[j].first == inputString[i])
        {
          bs += cp_ops[j].second;
          bs += " ";
          break;
        }
   }

   for (int j = 0; j <8; j++)
   {
        if (ss[j].first == inputString[i])
        {
          bs += ss[j].second;
          bs += " ";
          break;
        }
   }

   for (int j = 0; j <5; j++)
   {
        if (dim[j].first == inputString[i])
        {
          bs += dim[j].second;
          bs += " ";
          break;
        }
   }

   for (int j = 0; j <2; j++)
   {
        if (load_mode[j].first == inputString[i])
        {
          bs += load_mode[j].second;
          bs += " ";
          break;
        }
   }

   for (int j = 0; j <8; j++)
   {
        if (red_op[j].first == inputString[i])
        {
          bs += red_op[j].second;
          bs += " ";
          break;
        }
   }

   for (int j = 0; j <2; j++)
   {
        if (completion_mech[j].first == inputString[i])
        {
          bs += completion_mech[j].second;
          bs += " ";
          break;
        }
   }

   for (int j = 0; j <1; j++)
   {
        if (multicast[j].first == inputString[i])
        {
          bs += multicast[j].second;
          bs += " ";
          break;
        }
   }




   if (cache_hint[0].first == inputString[i])
    {
          bs += cache_hint[0].second;
          bs += " ";
    }

  for (int j = 0; j <3; j++)
   {
        if (prefetch_size[j].first == inputString[i])
        {
          bs += prefetch_size[j].second;
          bs += " ";
          break;
        }
   }
  for (int j = 0; j <2; j++)
   {
        if (level[j].first == inputString[i])
        {
          bs += level[j].second;
          bs += " ";
          break;
        }
   }

   for (int j = 0; j <18; j++)
   {
    if (type[j].first == inputString[i])
    {
      bs += type[j].second;
      bs += " ";
      break;
    }
   }
  }
 
  bs += "11111111";
  bs += " ";
  input = ltrim(operand);
  bs += enocde(operand);
  return bs;
}

// Logic and shift
string shf(string input) // l.mode.b32 d, a, b, c;     or b32
{
  string bs = "";
  string mystr = "";
  if (input.find(".", 0)) // l.mode.b32 d, a, b, c;
  {
    mystr = input.substr(0, input.find(".", 0)); // l/r    --> l=1   r=0
    input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
    if (mystr == "l")
    {
      bs += "1";
      bs += " ";
    }
    else
    {
      bs += "0";
      bs += " ";
    }

    mystr = input.substr(0, input.find(".", 0)); // mode
    input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
    for (int i = 0; i < 4; i++)
    {
      if (mode[i].first == mystr)
      {
        bs += mode[i].second;
        bs += " ";
      }
    }
    mystr = input.substr(0, input.find(" ", 0)); // 1st . tak jo mila vo mode hoga
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
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

  // b32 d, a, b, c;
  mystr = input.substr(0, input.find(" ", 0)); // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
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

// SIMD
string vadd2(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(".", 0));                      // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
  for (int i = 0; i < 10; i++)
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }
  mystr = input.substr(0, input.find(".", 0));                             // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
  for (int i = 0; i < 10; i++)
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }

  mystr = input.substr(0, input.find(".", 0)); // 1st . tak jo mila vo mode hoga
  for (int i = 0; i < 10; i++)
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }

  // ya to sat/add      sat ---> 101      add--->110
  if (input.find(".", 0))
  {
    input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
    mystr = input.substr(0, input.find(" ", 0));
    if (mystr == "sat")
    {
      bs += "101";
      bs += " ";
    }
    else if (mystr == "add")
    {
      bs += "110";
      bs += " ";
    }
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
    bs += "11111111";
    bs += " ";
    input = ltrim(input);
    bs += enocde(input);
    return bs;
  }
  else
  {
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
    bs += "11111111";
    bs += " ";
    input = ltrim(input);
    bs += enocde(input);
    return bs;
  }
}

string vset2(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(".", 0));                      // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
  for (int i = 0; i < 10; i++)
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }
  mystr = input.substr(0, input.find(".", 0));                             // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
  for (int i = 0; i < 10; i++)
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }

  if (input.find(".", 0)) // cmp.add hai
  {
    mystr = input.substr(0, input.find(".", 0));
    input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
    for (int i = 0; i < 6; i++)
    {
      if (mystr == cmp[i].first)
      {
        bs += cmp[i].second;
        bs += " ";
      }
    }
    mystr = input.substr(0, input.find(" ", 0));
    if (mystr == "add")
    {
      bs += "110";
      bs += " ";
    }

    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
    bs += "11111111";
    bs += " ";
    input = ltrim(input);
    bs += enocde(input);
    return bs;
  }
  else // sidha cmp hai
  {
    mystr = input.substr(0, input.find(" ", 0));
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
    for (int i = 0; i < 6; i++)
    {
      if (mystr == cmp[i].first)
      {
        bs += cmp[i].second;
        bs += " ";
      }
    }
    bs += "11111111";
    bs += " ";
    input = ltrim(input);
    bs += enocde(input);
    return bs;
  }
}

string vadd4(string input)
{
  string bs = "";
  string mystr = input.substr(0, input.find(".", 0));                      // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
  for (int i = 0; i < 10; i++)
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }
  mystr = input.substr(0, input.find(".", 0));                             // 1st . tak jo mila vo mode hoga
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]); // 1st . k baad ka sab
  for (int i = 0; i < 10; i++)
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }

  mystr = input.substr(0, input.find(".", 0)); // 1st . tak jo mila vo mode hoga
  for (int i = 0; i < 10; i++)
  {
    if (type[i].first == mystr)
    {
      bs += type[i].second;
      bs += " ";
    }
  }

  if (input.find(".", 0))
  {
    input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
    mystr = input.substr(0, input.find(" ", 0));
    if (mystr == "add")
    {
      bs += "110";
      bs += " ";
    }
    else if (mystr == "sat")
    {
      bs += "101";
      bs += " ";
    }

    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
    bs += "11111111";
    bs += " ";
    input = ltrim(input);
    bs += enocde(input);
    return bs;
  }
  else
  {
    input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
    bs += "11111111";
    bs += " ";
    input = ltrim(input);
    bs += enocde(input);
    return bs;
  }
}

// Miscellaneous
string setmaxnreg(string input)
{
  string bs = "";
  string mystr = "";
  mystr = input.substr(0, input.find(".", 0));
  input = input.substr(input.find(".", 0) + 1, input[input.length() - 1]);
  if (mystr == "dec")
  {
    bs += "0";
    bs += " ";
  }
  else // inc
  {
    bs += "1";
    bs += " ";
  }

  mystr = input.substr(0, input.find(" ", 0));

  if (mystr == "sync.aligned.u32") // 111110
  {
    bs += "111110";
    bs += " ";
  }
  input = input.substr(input.find(" ", 0) + 1, input[input.length() - 1]);
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

  parallel.push_back(make_pair("sync", "00"));
  parallel.push_back(make_pair("arrive", "01"));
  parallel.push_back(make_pair("red", "10"));

  boolOp.push_back(make_pair("and", "00"));
  boolOp.push_back(make_pair("or", "01"));
  boolOp.push_back(make_pair("xor", "10"));

  level[0] = {"L1", "01"};
  level[1] = {"L2", "10"};

  cache_hint[0] = {"L2::cache_hint", "1"};

  prefetch_size[0] = {"L2::64B", "000000"};
  prefetch_size[1] = {"L2::128B", "000001"};
  prefetch_size[2] = {"L2::256B", "000010"};

  multicast[0] = {"multicast::cluster", "00000000001"};

  completion_mech[0] = {"bulk_group", "000000000000"};
  completion_mech[1] = {"mbarrier::complete_tx::bytes", "00000000001"};

  load_mode[0] = {"tile", "00000000000000"};
  load_mode[1] = {"im2col", "00000000000001"};

  red_op[0] = {"add", "0000000000"};
  red_op[1] = {"min", "0000000001"};
  red_op[2] = {"max", "0000000010"};
  red_op[3] = {"inc", "0000000011"};
  red_op[4] = {"dec", "0000000100"};
  red_op[5] = {"and", "0000000101"};
  red_op[6] = {"or", "0000000110"};
  red_op[7] = {"xor", "0000000111"};

  dim[0] = {"1d", "000"};
  dim[1] = {"2d", "001"};
  dim[2] = {"3d", "010"};
  dim[3] = {"4d", "011"};
  dim[4] = {"5d", "100"};

  space[0] = {"global", "01"};
  space[1] = {"local", "10"};

  ss[0]={"const","0000"};
  ss[1]={"global","0001"};
  ss[2]={"local","0010"};
  ss[3]={"param","0011"};
  ss[4]={"shared::cta","0100"};
  ss[5]={"shared::cluster","0101"};
  ss[6]={"shared","0110"};
  ss[7]={"to","0111"};

  eviction_priority_l2[0] = {"L2::evict_normal", "01"};

  cp_ops[0] = {"async", "000000000"};
  cp_ops[1] = {"commit_group", "000000001"};
  cp_ops[2] = {"wait_group", "000000010"};
  cp_ops[3] = {"wait_all", "000000011"};
  cp_ops[4] = {"bulk", "000000100"};
  cp_ops[5] = {"reduce", "000000101"};
  cp_ops[6] = {"tensor", "000000110"};
  cp_ops[7] = {"prefetch", "000000111"};
  cp_ops[8] = {"ca", "000001000"};
  cp_ops[9] = {"cg", "000001001"};
  cp_ops[10] = {"read", "000001101"};

  tensor[0] = {"tensormap", "01"};

  eviction_priority[0] = {"L1::evict_normal", "00000"};
  eviction_priority[1] = {"L1::evict_unchanged", "00001"};
  eviction_priority[2] = {"L1::evict_first", "00010"};
  eviction_priority[3] = {"L1::evict_last", "00011"};
  eviction_priority[4] = {"L1::no_allocate", "00100"};

  vec[0] = {"v2", "0"};
  vec[1] = {"v4", "1"};

  scope[0] = {"cta", "00"};
  scope[1] = {"cluster", "01"};
  scope[2] = {"gpu", "10"};
  scope[3] = {"sys", "11"};

  qualifier[0] = {"weak", "000"};
  qualifier[1] = {"volatile", "001"};
  qualifier[2] = {"relaxed", "010"};
  qualifier[3] = {"acquire", "011"};
  qualifier[4] = {"release", "100"};

  // op vala hash amp
  op.push_back(make_pair("finite", "000"));
  op.push_back(make_pair("infinite", "001"));
  op.push_back(make_pair("number", "010"));
  op.push_back(make_pair("notanumber", "011"));
  op.push_back(make_pair("normal", "100"));
  op.push_back(make_pair("subnormal", "101"));

  op2.push_back(make_pair("add", "0000"));
  op2.push_back(make_pair("min", "0001"));
  op2.push_back(make_pair("max", "0010"));
  op2.push_back(make_pair("and", "0011"));
  op2.push_back(make_pair("or", "0100"));
  op2.push_back(make_pair("xor", "0101"));
  op2.push_back(make_pair("inc", "0110"));
  op2.push_back(make_pair("dec", "0111"));
  op2.push_back(make_pair("exch", "1000"));

  // rnd
  rnd.push_back(make_pair("rn", "00"));
  rnd.push_back(make_pair("rz", "01"));
  rnd.push_back(make_pair("rm", "10"));
  rnd.push_back(make_pair("rp", "11"));

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

  newfile.open("input.txt", ios::in);

  if (newfile.is_open())
  { // checking whether the file is open
    string tp1;
    while (getline(newfile, tp1))
    {
      string tp2 = tp1;
      bool curly = false;
      string bitString = "";
      string mystr = "";
      string inp = "";

      // read data from file object and put it into string.
      // cout << tp1 << "\n"; // print the data of the string

      // control flow instructions ko hum yaha par handle kar rahe hai jitne ho saje.
      // { }

     // string temp = tp1;
      
      if(tp1.find("//") !=  string::npos){
        continue;
      }
    
      
      if(tp1.size() == 0){
        continue;
      }
      
      while(tp1[0] == '\t' || tp1[0] == ' '){
        
        tp1 = tp1.substr(1);
      }
      cout<<tp1<<endl;
      string temp =tp1;
      bool isFound = false;
      if(temp[0] == '$' || temp[0] == '{' || temp[0] == '}' || temp[0] == '(' || temp[0] == ')' || temp[0] == '@'){
        isFound = true;
        bitString += "11111111 ";
        bitString += enocde(tp1);
        ofstream outfile;
        outfile.open("output.txt", ios::app);
        outfile << bitString << endl;
        bitString = "";
        
        outfile.close();
        continue;
      }


      
      
      if((temp.find(" ") != string::npos) && temp.substr(0,temp.find(" ")) == ".visible"){
        isFound = true;
        bitString += "11111111 ";
        bitString += enocde(tp1);
        ofstream outfile;
        outfile.open("output.txt", ios::app);
        outfile << bitString << endl;
        bitString = "";
        
        outfile.close();
        continue;
      }
      if((temp.find(" ") != string::npos) && temp.substr(0,temp.find(" ")) == ".shared"){
        isFound = true;
        bitString += "11111111 ";
        bitString += enocde(tp1);
        ofstream outfile;
        outfile.open("output.txt", ios::app);
        outfile << bitString << endl;
        bitString = "";
        
        outfile.close();
        continue;
      }
      if((temp.find(" ") != string::npos) && temp.substr(0,temp.find(" ")) == ".param"){
        isFound = true;
        bitString += "11111111 ";
        bitString += enocde(tp1);
        ofstream outfile;
        outfile.open("output.txt", ios::app);
        outfile << bitString << endl;
        bitString = "";
        
        outfile.close();
        continue;
      }
      
      if((temp.find(" ") != string::npos) && temp.substr(0,temp.find(" ")) == ".pragma"){
        isFound = true;
        bitString += "11111111 ";
        bitString += enocde(tp1);
        ofstream outfile;
        outfile.open("output.txt", ios::app);
        outfile << bitString << endl;
        bitString = "";
        
        outfile.close();
        continue;
      }

      if((temp.find(" ") != string::npos) && temp.substr(0,temp.find(" ")) == ".reg"){
        isFound = true;
        bitString += "11111111 ";
        bitString += enocde(tp1);
        ofstream outfile;
        outfile.open("output.txt", ios::app);
        outfile << bitString << endl;
        bitString = "";
        
        outfile.close();
        continue;
      }
      if((temp.find(";") != string::npos) && temp.substr(0,temp.find(";")) == "ret"){
        isFound = true;
        bitString += "11111111 ";
        bitString += enocde(tp1);
        ofstream outfile;
        outfile.open("output.txt", ios::app);
        outfile << bitString << endl;
        bitString = "";
        
        outfile.close();
        continue;
      }
      if((temp.find(" ") != string::npos) && temp.substr(0,temp.find(" ")) == ".version"){
        isFound = true;
        bitString += "11111111 ";
        bitString += enocde(tp1);
        ofstream outfile;
        outfile.open("output.txt", ios::app);
        outfile << bitString << endl;
        bitString = "";
        
        outfile.close();
        continue;
      }
      if((temp.find(" ") != string::npos) && temp.substr(0,temp.find(" ")) == ".target"){
        isFound = true;
        bitString += "11111111 ";
        bitString += enocde(tp1);
        ofstream outfile;
        outfile.open("output.txt", ios::app);
        outfile << bitString << endl;
        bitString = "";
        
        outfile.close();
        continue;
      }
      if((temp.find(" ") != string::npos) && temp.substr(0,temp.find(" ")) == ".address_size"){
        isFound = true;
        bitString += "11111111 ";
        bitString += enocde(tp1);
        ofstream outfile;
        outfile.open("output.txt", ios::app);
        outfile << bitString << endl;
        bitString = "";
        
        outfile.close();
        continue;
      }
      if((temp.find(".") != string::npos) && temp.substr(0,temp.find(".")) == "and"){
        isFound = true;
        bitString += "11111111 ";
        bitString += enocde(tp1);
        ofstream outfile;
        outfile.open("output.txt", ios::app);
        outfile << bitString << endl;
        bitString = "";
        
        outfile.close();
        continue;
      }
      if((temp.find(".") != string::npos) && temp.substr(0,temp.find(".")) == "not"){
        isFound = true;
        bitString += "11111111 ";
        bitString += enocde(tp1);
        ofstream outfile;
        outfile.open("output.txt", ios::app);
        outfile << bitString << endl;
        bitString = "";
        
        outfile.close();
        continue;
      }
      if((temp.find(".") != string::npos) && temp.substr(0,temp.find(".")) == "and"){
        isFound = true;
        bitString += "11111111 ";
        bitString += enocde(tp1);
        ofstream outfile;
        outfile.open("output.txt", ios::app);
        outfile << bitString << endl;
        bitString = "";
        
        outfile.close();
        continue;
      }
      if((temp.find(".") != string::npos) && temp.substr(0,temp.find(".")) == "bar"){
        isFound = true;
        bitString += "11111111 ";
        bitString += enocde(tp1);
        ofstream outfile;
        outfile.open("output.txt", ios::app);
        outfile << bitString << endl;
        bitString = "";
        
        outfile.close();
        continue;
      }
      
      


      

      // if (tp1[0] == '@') // @ = 1 0 , @! = 1 1
      // {
      //   if (tp1[1] == '!')
      //   {
      //     bitString += "1";
      //     bitString += " ";
      //     bitString += "1";
      //     bitString += " ";

      //     std::string s(1, tp1[2]);
      //     bitString += enocde(s);
      //     bitString += " ";
      //     tp1 = tp1.substr(tp1.find("!", 0) + 1, tp1[tp1.length() - 1]);
      //   }
      //   else
      //   {

      //     bitString += "1";
      //     bitString += " ";
      //     bitString += "0";
      //     bitString += " ";

      //     std::string s(1, tp1[2]);
      //     bitString += enocde(s);
      //     bitString += " ";

      //     tp1 = tp1.substr(tp1.find("@", 0) + 1, tp1[tp1.length() - 1]);
      //   }
      // }

      // // ________________________________________________________________//

      // control flow   2 bit
      // if (tp1 == "ret;") // as isme koi parameter nhi hoiga
      // {
      //   bitString += "00";
      //   bitString += " ";
      // }
      // else if (tp1 == "exit;")
      // {
      //   bitString += "01";
      //   bitString += " ";
      // }

      mystr = tp1.substr(0, tp1.find(" ", 0));
      if (mystr == "bra")
      {
        bitString += "00";
        bitString += " ";

        // tp1 = tp1.substr(tp1.find(" ", 0) + 1, tp1[tp1.length() - 1]);
        tp1 = tp1.substr(tp1.find(" ", 0) + 1);
        bitString += "11111111";
        bitString += " ";
        inp = ltrim(tp1);
        bitString += enocde(inp);
      }
      else if (mystr == "call")
      {
        bitString += "01";
        bitString += " ";

        tp1 = tp1.substr(tp1.find(" ", 0) + 1, tp1[tp1.length() - 1]);
        bitString += "11111111";
        bitString += " ";
        inp = ltrim(tp1);
        bitString += enocde(inp);
      }

      // Miscellaneous
      if (tp1 == "brkpt;")
      {

        bitString += category[18].second;
        bitString += " ";

        bitString += "000";
        bitString += " ";
      }
      else if (tp1 == "trap;")
      {

        bitString += category[18].second;
        bitString += " ";

        bitString += "011";
        bitString += " ";
      }

      mystr = tp1.substr(0, tp1.find(".", 0));                       // 1st . tak
      tp1 = tp1.substr(tp1.find(".", 0) + 1); // 1st . k baad ki string
      cout << mystr << endl;

      //  dekh ne k loye

      // arithematic instructions
      for (int i = 0; i < 24; i++)
      {

        if (instruction[0][i].first == mystr)
        {
          // cout<<"here"<<endl;
          // bitString += category[0].second;
          // bitString += " ";

          bitString += instruction[0][i].second;
          bitString += " ";

          // string mystr1;
          // mystr1=tp1.substr(0, tp1.find(" ", 0));
          // cout<<" hello bitsstring ab tak ="<<bitString<<endl;
          if (mystr == "add" || mystr == "sub")
          {
            cout<<"bitstring $$$$$$$$$$"<<bitString<<endl;
            bitString += fpadd(tp1);
            bitString += " ";
           // cout<<"bitstring $$$$$$$$$$"<<bitString<<endl;
             goto label;
          }

          else if (mystr == "mul" || mystr == "mul24" || mystr == "szext" || mystr == "szext" || mystr == "bmsk")
          {
            bitString += fpadd(tp1);
            bitString += " ";
             goto label;
          }
          else if (mystr == "mad" || mystr == "mad24") // as mad m .sat ho sakta hai
          {
          cout<<" mad here &&&&&&&&&&&"<<endl;
            bitString += mad(tp1);
            bitString += " ";
            cout<<" mbs"<<bitString<<endl;
            goto label;
          }
          else if (mystr == "sad" || mystr == "div" || mystr == "rem" || mystr == "abs" || mystr == "neg" || mystr == "popc" || mystr == "clz" || mystr == "fns" || mystr == "brev" || mystr == "bfe" || mystr == "bfi") // dont have .sat
          {
            bitString += fpadd(tp1);
            bitString += " ";
             goto label;
          }
          else if (mystr == "min" || mystr == "max")
          {
            cout << " astala vitala $$$$" << endl;
            bitString += min(tp1);
            bitString += " ";
             goto label;
          }
          else if (mystr == "bfind")
          {
            bitString += bfind(tp1);
            bitString += " ";
             goto label;
          }
          else if (mystr == "dp4a")
          {
            bitString += dp4a(tp1);
            bitString += " ";
             goto label;
          }
          else if (mystr == "dp2a")
          {
            bitString += dp2a(tp1);
            bitString += " ";
             goto label;
          }
        }
      }
cout<<" 1"<<endl;
       // // comparison and selection instuction
      for (int i = 0; i < 4; i++)
      {
        if (mystr == instruction[3][i].first)
        {
          // bitString += category[4].second;
          // bitString += " ";

          bitString += instruction[3][i].second;
          bitString += " ";
          if (mystr == "set")
          {
            bitString += Set(tp1);
            bitString += " ";
            goto label;
          }
          else if (mystr == "setp")
          {
            cout << " k andar main mugwduebhgc " << endl;
            bitString += Setp(tp1);
            bitString += " ";
            cout<<" bs ==== "<<bitString<<endl;
            goto label;
          }
          else if (mystr == "selp")
          {
            cout << "y yo yoo" << endl;
            bitString += add(tp1);
            bitString += " ";
            goto label;
          }
          else if (mystr == "slct")
          {
            bitString += slct(tp1);
            bitString += " ";
            goto label;
          }
        }
      }
cout<<" 1"<<endl;
       // Logic and Shift Instructions
      for (int i = 0; i < 9; i++)
      {
        if (mystr == instruction[5][i].first)
        {
          // bitString += category[5].second;
          // bitString += " ";
          cout<<"hello dhfcsdhchnsd"<<endl;
          bitString += instruction[5][i].second;
          bitString += " ";

          if (mystr == "and" || mystr == "or" || mystr == "xor" || mystr == "not" || mystr == "cnot" || mystr == "lop3" || mystr == "shl" || mystr == "shr")
          {
            cout << "main k andar" << endl;
            bitString += add(tp1);
            bitString += " ";

            goto label;
          }
          else if (mystr == "shf")
          {
            bitString += shf(tp1); /////   left ****************
            bitString += " ";
            goto label;
          }
        }
      }
cout<<" 1"<<endl;

      // Half Precision Comparison Instructions
      for (int i = 0; i < 2; i++)
      {
        if (mystr == instruction[5][i].first)
        {
          // bitString += category[5].second;
          // bitString += " ";

          bitString += instruction[5][i].second;
          bitString += " ";

          if (mystr == "set")
          {
            bitString += HPSet(tp1);
            bitString += " ";
             goto label;
          }
          else if (mystr == "setp")
          {
            bitString += HPSetp(tp1);
            bitString += " ";
             goto label;
          }
        }
      }
cout<<" 1"<<endl;
      // load store (sagar)

      for (int i = 0; i < 18; i++)
      {
        if (instruction[12][i].first == mystr)
        {
         bitString += category[7].second;
        bitString += " ";
          // bitString += category[7].second;
          // bitString += " ";

          bitString += instruction[12][i].second;
          bitString += " ";

          if (mystr == "mov")
          {
            bitString += mov(tp1);
            bitString += " ";
             goto label;
          }
          else if (mystr == "shfl")
          {
            bitString += shfl(tp1);
            bitString += " ";
             goto label;
          }
          else if (mystr == "prmt")
          {
            bitString += prmt(tp1);
            bitString += " ";
             goto label;
          }
          else if (mystr == "ld")
          {
             cout<<"ujsdfgbhwsihbfrusw uowehgfuwjshfcrsw ujweghfuwhf"<<endl;
            bitString += ld(tp1);
            bitString += " ";
            cout<<"********"<<bitString<<endl;
             goto label;
          }
          else if (mystr == "ldu")
          {
            bitString += ldu(tp1);
            bitString += " ";
             goto label;
          }
          else if (mystr == "st")
          {
            bitString += st(tp1);
            bitString += " ";
             goto label;
          }

          else if (mystr == "prefetch")
          {
            bitString += prefetch(tp1);
            bitString += " ";
             goto label;
          }

          else if (mystr == "prefetchu")
          {
            bitString += prefetchu(tp1);
            bitString += " ";
             goto label;
          }

          else if (mystr == "applypriority")
          {
            bitString += applypriority(tp1);
            bitString += " ";
             goto label;
          }

          else if (mystr == "discard")
          {
            bitString += discard(tp1);
            bitString += " ";
             goto label;
          }

          else if (mystr == "isspacep")
          {
            bitString += isspacep(tp1);
            bitString += " ";
             goto label;
          }

          else if (mystr == "cvt")
          {
            bitString += cvt(tp1);
            bitString += " ";
             goto label;
          }

          else if (mystr == "cvta")
          {
            bitString += cvta(tp1);
            bitString += " ";
             goto label;
          }

          else if (mystr == "mapa")
          {
            bitString += mapa(tp1);
            bitString += " ";
             goto label;
          }

          else if (mystr == "getctarank")
          {
            bitString += getctarank(tp1);
            bitString += " ";
             goto label;
          }
          else if (mystr == "cp")
          {
            bitString += cp(tp1);
            bitString += " ";
             goto label;
          }
        }
      }
cout<<" 1"<<endl;
 // parallelk
      for (int i = 0; i < 11; i++)
      {
        if (mystr == instruction[7][i].first)
        {
          // bitString += category[11].second;
          // bitString += " ";

          bitString += instruction[7][i].second;
          bitString += " ";

          if (mystr == "bar" || mystr == "barrier")
          {
            cout << "yahalooo1232" << endl;
            bitString += bar(tp1);
            bitString += " ";
             goto label;
          }
          else if (mystr == "atom")
          {
              cout<<"atom bomb ###############"<<endl;
            bitString += atom(tp1);
            bitString += " ";
             goto label;
          }
        }
      }
cout<<" 1"<<endl;
      // stack manipulation
      for (int i = 0; i < 3; i++)
      {
        if (mystr == instruction[14][i].first)
        {
          // bitString += category[14].second;
          // bitString += " ";

          bitString += instruction[14][i].second;
          bitString += " ";

          if (mystr == "stacksave" || mystr == "stackrestore")
          {
            bitString += add(tp1);
            bitString += " ";
             goto label;
          }

          // alloca remaionig
        }
      }
cout<<" 1"<<endl;
     
      // floating point
      for (int i = 0; i < 18; i++)
      {
        if (mystr == instruction[2][i].first)
        {
          // bitString += category[2].second;
          // bitString += " ";

          bitString += instruction[2][i].second;
          bitString += " ";

          if (mystr == "testp")
          {
            bitString += testp(tp1);
            bitString += " ";
             goto label;
          }
          else if (mystr == "copysign" || mystr == "mad") // sidha type hoga
          {
            bitString += add(tp1);
            bitString += " ";
            goto label;
          }
          else if (mystr == "add" || mystr == "sub" || mystr == "mul")
          {
            bitString += fpadd(tp1);
            bitString += " ";
            goto label;
          }

          else if (mystr == "fma")
          {
            bitString += fma(tp1);
            bitString += " ";
            goto label;
          }
          else if (mystr == "div")
          {
            bitString += Fdiv(tp1);
            bitString += " ";
            goto label;
          }
          else if (mystr == "abs" || mystr == "neg")
          {
            bitString += hpfneg(tp1);
            bitString += " ";
            goto label;
          }
          else if (mystr == "min" || mystr == "max")
          {
            bitString += FPMin(tp1);
            bitString += " ";
            goto label;
          }
          else if (mystr == "rcp" || mystr == "sqrt")
          {
            bitString += rcp(tp1);
            bitString += " ";
            goto label;
          }
          else if (mystr == "rsqrt" || mystr == "sin" || mystr == "cos" || mystr == "lg2" || mystr == "ex2" || mystr == "tanh")
          {
            bitString += rsqrt(tp1);
            bitString += " ";
            goto label;
          }
        }
      }
cout<<" 1"<<endl;
      // half precision floating point instruction
      for (int i = 0; i < 10; i++)
      {
        if (instruction[3][i].first == mystr)
        {
          // bitString += category[3].second;
          // bitString += " ";

          bitString += instruction[3][i].second;
          bitString += " ";

          if (mystr == "add" || mystr == "sub" || mystr == "mul")
          {
            bitString += fpadd(tp1);
            bitString += " ";
            goto label;
          }
          else if (mystr == "fma")
          {
            bitString += fma(tp1);
            bitString += " ";
            goto label;
          }
          else if (mystr == "neg" || mystr == "abs")
          {
            bitString += hpfneg(tp1);
            bitString += " ";
            goto label;
          }
          else if (mystr == "min" || mystr == "max")
          {
            bitString += FPMin(tp1);
            bitString += " ";
            goto label;
          }
          else if (mystr == "tanh" || mystr == "ex2")
          {
            bitString += rsqrt(tp1);
            bitString += " ";
            goto label;
          }
        }
        // 4 instruction s baki hai
      }
cout<<" 1"<<endl;
     
     

      // for scalar video instructions
      for (int i = 0; i < 9; i++)
      {

        if (mystr == instruction[16][i].first)
        {
          // bitString += category[16].second;
          // bitString += " ";

          bitString += instruction[16][i].second;
          bitString += " ";

          if (mystr == "vadd" || mystr == "vsub" || mystr == "vabsdiff" || mystr == "vmin" || mystr == "vmax")
          {
            bitString += vadd(tp1);
            bitString += " ";
            goto label;
          }
          else if (mystr == "vshl" || mystr == "vshr")
          {
            bitString += vshl(tp1);
            bitString += " ";
            goto label;
          }
          else if (mystr == "vmad")
          {
            bitString += vmad(tp1);
            bitString += " ";
            goto label;
          }
          else if (mystr == "vset")
          {
            bitString += vset(tp1);
            bitString += " ";
            goto label;
          }
        }
      }
cout<<" 1"<<endl;
      // SMID instruction
      for (int i = 0; i < 14; i++)
      {
        if (mystr == instruction[17][i].first)
        {
          // bitString += category[17].second;
          // bitString += " ";

          bitString += instruction[17][i].second;
          bitString += " ";

          if (mystr == "vadd2" || mystr == "vsub2" || mystr == "vavrg2" || mystr == "vabsdiff2" || mystr == "vmin2" || mystr == "vmax2")
          {
            bitString += vadd2(tp1);
            bitString += " ";
            goto label;
          }
          else if (mystr == "vset2")
          {
            bitString += vset2(tp1);
            bitString += " ";
            goto label;
          }
          else if (mystr == "vadd4" || mystr == "vsub4" || mystr == "vavrg4" || mystr == "vabsdiff4" || mystr == "vmin4" || mystr == "vmax4")
          {
            bitString += vadd4(tp1);
            bitString += " ";
            goto label;
          }
          // vset4 baki hai    ??
        }
      }
cout<<" 1"<<endl;

      cout << " bitstring  =" << bitString << endl;

      // MIscellaneous instruction
      for (int i = 0; i < 4; i++)
      {
        if (instruction[18][i].first == mystr)
        {
          // cout<<"here"<<endl;
          // bitString += category[18].second;
          // bitString += " ";

          bitString += instruction[18][i].second;
          bitString += " ";

          if (mystr == "nanosleep")
          {
            bitString += add(tp1);
            bitString += " ";
            goto label;
          }
          else if (mystr == "setmaxnreg")
          {
            // cout<<"here"<<endl;
            bitString += setmaxnreg(tp1);
            bitString += " ";
            goto label;
          }
          // pmevent baki ???
        }
      }

      // agar opening bracket hoga to usko bas encode kiya , decoding k time dekh lenge
label:      cout<<"ughdbsdndcsdnjcfnkj juioasdgbdcujasdncbsdc8988888"<<endl;
      cout <<" qus "<< tp2 << endl;
      cout <<" answer ===== "<< bitString << endl;
      // bitString += "\n";
      ofstream outfile;
      outfile.open("output.txt", ios::app);
       outfile << bitString << endl;
      // bitString = "";
      // // outfile << "hi hi" <<"\n" << endl;
      outfile.close();
    }
  }

  // map for types

  return 0;
}