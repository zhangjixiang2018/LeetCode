#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> tmp(nums1.size()+nums2.size(),0);//创建一个长度为nums1长度加nums2长度的vector，用于保存这两个vector中的值
        
        int i = 0, j = 0;
        int k = 0;
        double ret = 0.0;
        

        //将两个数组按大小顺序合并到一个数组中
        while (i < (int)nums1.size() && j < (int)nums2.size())
        {
            if (nums1[i] < nums2[j]) tmp[k++] = nums1[i++];
            else tmp[k++] = nums2[j++];
        }

        while(i< (int)nums1.size())  tmp[k++] = nums1[i++];
        while (j < (int)nums2.size())  tmp[k++] = nums2[j++];


        if (tmp.size() % 2 == 0)//元素个数为偶数，将中间两个数相加除2
        {
            ret = ((double)tmp[tmp.size() / 2] + (double)tmp[tmp.size() / 2 - 1]) / 2;
        }
        else//元素个数为奇数，返回间接的数
        {
            ret = (double)tmp[tmp.size() / 2];
        }

        return ret;
    }
};

int main()
{
    vector<int> v1;
    vector<int> v2;

    v1.push_back(1);
    v1.push_back(3);

    v2.push_back(2);
    //v2.push_back(4);

    for (vector<int>::iterator it = v1.begin(); it < v1.end(); it++)
    {
        cout << *it << "    ";
    }
    cout << endl;

    for (vector<int>::iterator it = v2.begin(); it < v2.end(); it++)
    {
        cout << *it << "    ";
    }
    cout << endl;

    Solution s;

    cout << s.findMedianSortedArrays(v1, v2) << endl;

    

	return 0;
}