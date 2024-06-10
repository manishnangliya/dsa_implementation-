// Created by manishnangliya
#include <bits/stdc++.h>
using namespace std;

class SGTree
{
public:
    vector<int> seg;
    SGTree(int n)
    {
        seg.resize(4 * n + 1);
    }
    // segment array size should be 4*n where n is size of arr
    // TC of build: no. of node visited in segment tree =near O(4n) =near O(n)
    void build(int ind, int low, int high, vector<int> &arr)
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }
        int mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    // query if we are finding answer for range l,r
    // case 1 partial overlap with range (low,high)  => go left , go right and calculate result
    // case 2 no overlap with range (low, high) example: [low, high] [l, r] or [l,r] [low, high] =>(high<l || r<low), return INT_MAX
    // case 3 complete with range (low,high) example: l <=Low<=high<=r , return seg[ind]
    // TC:near O(Log n)
    int query(int ind, int low, int high, int l, int r)
    {
        // no overlap
        //  l r low high or low high l r
        if (high < l || r < low)
            return INT_MAX;

        // complete overlap
        //[l low high r]
        if (low >= l && high <= r)
        {
            return seg[ind];
        }
        int mid = low + (high - low) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return min(left, right);
    }

    void update(int ind, int low, int high, int index, int value)
    {
        if (low == high)
        {
            seg[ind] = value;
            return;
        }
        int mid = low + (high - low) / 2;
        if (index <= mid)
        {
            update(2 * ind + 1, low, mid, index, value);
        }
        else
        {
            update(2 * ind + 2, mid + 1, high, index, value);
        }
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};

int main()
{
    int n1;
    cin >> n1;
    vector<int> arr1(n1);
    for (int i = 0; i < n1; i++)
        cin >> arr1[i];
    SGTree sg1(n1);
    sg1.build(0, 0, n1 - 1, arr1);

    int n2;
    cin >> n2;
    vector<int> arr2(n2);
    for (int i = 0; i < n2; i++)
        cin >> arr2[i];

    SGTree sg2(n2);
    sg2.build(0, 0, n2 - 1, arr2);

    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;
            int ans1 = sg1.query(0, 0, n1 - 1, l1, r1);
            int ans2 = sg2.query(0, 0, n2 - 1, l2, r2);
            cout << min(ans1, ans2) << endl;
        }
        else
        {
            int arrNo;
            cin >> arrNo;
            int index, value;
            cin >> index >> value;
            if (arrNo == 1)
            {
                sg1.update(0, 0, n1 - 1, index, value);
                arr1[index] = value;
            }
            else
            {
                sg2.update(0, 0, n2 - 1, index, value);
                arr2[index] = value;
            }
        }
    }
    return 0;
}