#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

bool isNice(const string &s)
{
    unordered_set<char> st(s.begin(),s.end());
    for(char ch: st)
    {
        if(isupper(ch) && !st.count(tolower(ch)))
            return false;
        if(islower(ch) && !st.count(toupper(ch)))
            return false;
    }
    return true;

}

string longestNice(string s)
{
    if(s.length()< 2)
    {
        return "";
    }
    
    if(isNice(s))   
        return s;

    for(int i=0 ; i<s.length();i++)
    {
        char ch=s[i];
        bool hasLower= (s.find(tolower(ch))<s.length());
        bool hasUpper = (s.find(toupper(ch))< s.length());
        if(!hasLower || !hasUpper)
        {
            string left= longestNice(s.substr(0,i));
            string right= longestNice(s.substr(i+1));
            return (left.length()>=right.length()) ? left:right;
        }
    }
    return "";
}

int main()
{
    string s;
    cin>>s;
    cout<<longestNice(s)<<endl;
    return 0;
}