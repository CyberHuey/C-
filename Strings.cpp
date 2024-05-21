// C++ Program to demonstrate strings
#include <iostream>
using namespace std;
 
int main()
{
	// C Style Strings
    char g[] = "GeeksforGeeks";
    cout << s << endl;
	
	char s[] = {'g', 'f', 'g', '\0'};
	char s[4] = {'g', 'f', 'g', '\0'};
	char s[4] = "gfg";
	char s[] = "gfg";
	
	// std::string Class
	string str("GeeksforGeeks");
    cout << str;
	
	// Print repeating strings
	string str(5, 'g');
    cout << str;
	
    return 0;
}