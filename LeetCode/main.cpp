#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //set用于检查重复字符
        set<char> occ;
        int n = s.size();
        int r = -1;//右指针
        int ret = 0;

        for (int i = 0; i < n; i++)
        {
            if (i != 0)
            {   //当i不等于0时，左指针向右移动一位就从set中移除一位元素
                occ.erase(s[i-1]);
            }
           
            while ((r+1 < n) && (occ.count(s[r+1]) == 0))//右指针右移，当set中不存在右指针指向的元素时，将其放入set中
            {
                occ.insert(s[r+1]);
                r++;
            }

            ret =  max(ret, r-i+1);
        }

        return ret;
    }
};

int main()
{
    Solution s;
    string str = "bbbbbb";

    cout << s.lengthOfLongestSubstring(str) << endl;
	return 0;
}

