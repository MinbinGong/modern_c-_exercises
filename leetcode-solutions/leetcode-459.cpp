#include <string>
using namespace std;

bool repeatedSubstringPattern(string s) { return (s + s).substr(1, 2 * s.size() - 2).find(s) != string::npos; }