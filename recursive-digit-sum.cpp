#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'superDigit' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING n
 *  2. INTEGER k
 */

int superDigit(string n, int k) {
      stringstream ss;
 if(k==1){
     int number =0;
     ss >> number;
     return number;
 }
 else {
     string s;
     long long  answer=0;
     ss << n;
     ss >>s;
     for(const auto &x:s){
         answer+= x-'0';
     }// compute the sum finish;

     answer*=k; // multiply it by k;
     ss.clear();
     ss << answer; // read the answer into a stringstream again.
     ss >> s;     // input it into the string also.

     long long sum=0;
     while(s.size()>1){
         // compute the sum of the string until the string form of the sum is of size 1.

         sum=0;
         for(const auto&x:s){
             sum+=x-'0';
         }
         ss.clear();
         ss << sum;
         ss >>s;
     }
    return sum;
 }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    string n = first_multiple_input[0];

    int k = stoi(first_multiple_input[1]);

    int result = superDigit(n, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
