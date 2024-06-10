// Created by manishnangliya

#include <bits/stdc++.h>
using namespace std;

//Question: 2 type of query, 1. give the minimum in range, 2. update the value at particular index.

// segment array size should be 4*n where n is size of arr
// TC of build: no. of node visited in segment tree =near O(4n) =near O(n)
void build(int ind, int low, int high, vector<int> &seg, vector<int> &arr)
{
    if (low == high)
    {
        seg[ind] = arr[low];
        return;
    }
    int mid = low + (high - low) / 2;
    build(2 * ind + 1, low, mid, seg, arr);
    build(2 * ind + 2, mid + 1, high, seg, arr);
    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
}

// query if we are finding answer for range l,r
// case 1 partial overlap with range (low,high)  => go left , go right and calculate result
// case 2 no overlap with range (low, high) example: [low, high] [l, r] or [l,r] [low, high] =>(high<l || r<low), return INT_MAX
// case 3 complete with range (low,high) example: l <=Low<=high<=r , return seg[ind]
// TC:near O(Log n)
int query(int ind, int low, int high, int l, int r, vector<int> &seg)
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
    int left = query(2 * ind + 1, low, mid, l, r, seg);
    int right = query(2 * ind + 2, mid + 1, high, l, r, seg);
    return min(left, right);
}

void update(int ind, int low, int high, int index, int value, vector<int> &seg)
{
    if (low == high)
    {
        seg[ind] = value;
        return;
    }
    int mid = low + (high - low) / 2;
    if (index <= mid)
    {
        update(2 * ind + 1, low, mid, index, value, seg);
    }
    else
    {
        update(2 * ind + 2, mid + 1, high, index, value, seg);
    }
    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> seg(4 * n);
    build(0, 0, n - 1, seg, arr);
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << query(0, 0, n - 1, l, r, seg) << endl;
        }
        else
        {
            int index, value;
            cin >> index >> value;
            update(0, 0, n - 1, index, value, seg);
            arr[index] = value;
        }
    }
    return 0;
}