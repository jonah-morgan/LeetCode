#ifndef _SUBSTRCONCAT_H_
#define _SUBSTRCONCAT_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> findSubstring(string s, vector<string>& words)
{
	string::iterator curr = s.begin();
	string::iterator endWord;
	vector<int> nums;
	int i, j;

	j = 0;
	while(curr != s.end())
	{
		int count = 0;
		bool found = true;

		for(i = 0; i < words.size() && found; i++)
		{
			if(words[i] ==  string(curr, curr + words[i].length()))
			{
				count++;
			}
			else
				found == false;
		}

		if(count == words.size())
			nums.push_back(j);
		
		j++;		
		curr++;
	}

	return nums;
}

#endif



