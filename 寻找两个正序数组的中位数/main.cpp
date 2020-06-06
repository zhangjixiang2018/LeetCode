#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> tmp(nums1.size()+nums2.size(),0);//����һ������Ϊnums1���ȼ�nums2���ȵ�vector�����ڱ���������vector�е�ֵ
        
        int i = 0, j = 0;
        int k = 0;
        double ret = 0.0;
        

        //���������鰴��С˳��ϲ���һ��������
        while (i < (int)nums1.size() && j < (int)nums2.size())
        {
            if (nums1[i] < nums2[j]) tmp[k++] = nums1[i++];
            else tmp[k++] = nums2[j++];
        }

        while(i< (int)nums1.size())  tmp[k++] = nums1[i++];
        while (j < (int)nums2.size())  tmp[k++] = nums2[j++];


        if (tmp.size() % 2 == 0)//Ԫ�ظ���Ϊż�������м���������ӳ�2
        {
            ret = ((double)tmp[tmp.size() / 2] + (double)tmp[tmp.size() / 2 - 1]) / 2;
        }
        else//Ԫ�ظ���Ϊ���������ؼ�ӵ���
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