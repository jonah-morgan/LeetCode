#include "multiplyStrings.h"
#include "substrConcat.h"

int main(int argc, char** argv)
{
	vector<string> words;
	words.push_back("test");
	words.push_back("another");
	
	vector<int> nums = findSubstring("testanother", words); 

	for(int i = 0; i < nums.size(); i++)
		cout << nums[i] << endl;

	return 0;
}

