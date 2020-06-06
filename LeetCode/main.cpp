#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //set���ڼ���ظ��ַ�
        set<char> occ;
        int n = s.size();
        int r = -1;//��ָ��
        int ret = 0;

        for (int i = 0; i < n; i++)
        {
            if (i != 0)
            {   //��i������0ʱ����ָ�������ƶ�һλ�ʹ�set���Ƴ�һλԪ��
                occ.erase(s[i-1]);
            }
           
            while ((r+1 < n) && (occ.count(s[r+1]) == 0))//��ָ�����ƣ���set�в�������ָ��ָ���Ԫ��ʱ���������set��
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

