#include <vector>
#include <iostream>
using namespace std;



int jump(vector<int>& nums);
void jumpRecurse(vector<int>& nums, int tgt, int thisPos, int& minJump, int &jumpAmt);



int jump(vector<int>& nums) 
{
	int minJump = 27000;
	int jumps = 0;
	jumpRecurse(nums, nums.size() - 1, 0, minJump, jumps);
			        
	return minJump;
}
    


void jumpRecurse(vector<int>& nums, int tgt, int thisPos, int& minJump, int &jumpAmt)
{
	if(jumpAmt >= minJump)
		return;

	if(thisPos == tgt && jumpAmt < minJump)
	{
		minJump = jumpAmt;
	}
			            
	else if((thisPos > tgt) || (thisPos == tgt && !(jumpAmt < minJump)))
	{
		return;
	}
				            
	else
	{
		for(int i = 1; i <= nums[thisPos]; i++)
		{
			jumpAmt++;
			jumpRecurse(nums, tgt, thisPos + i, minJump, jumpAmt);
			jumpAmt--;
		}
	}
					                
}	




