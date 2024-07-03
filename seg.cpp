#include <bits/stdc++.h>
using namespace std;

class Segment_Tree
{
public:
    vector<int> maxi, mini, orr, andd;
    int n;

    Segment_Tree(vector<int> &arr)
    {
        n = arr.size();
        maxi.resize(4 * n);
        mini.resize(4 * n);
        orr.resize(4 * n);
        andd.resize(4 * n);
    }

    void build(int ind, int low, int high, vector<int> &arr)
    {
        if (low == high)
        {
            maxi[ind] = arr[low];
            mini[ind] = arr[low];
            orr[ind] = arr[low];
            andd[ind] = arr[low];
            return;
        }
        int mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        maxi[ind] = max(maxi[2 * ind + 1], maxi[2 * ind + 2]);
        mini[ind] = min(mini[2 * ind + 1], mini[2 * ind + 2]);
        orr[ind] = orr[2 * ind + 1] | orr[2 * ind + 2];
        andd[ind] = andd[2 * ind + 1] & andd[2 * ind + 2];
        return;
    }

    int maximum(int l, int r)
    {
        return query1(0, 0, n - 1, l, r);
    }

    int minimum(int l, int r)
    {
        return query2(0, 0, n - 1, l, r);
    }

    int orri(int l, int r)
    {
        return query4(0, 0, n - 1, l, r);
    }

    int anddi(int l, int r)
    {
        return query3(0, 0, n - 1, l, r);
    }
    void update(int idx, int val)
    {
        upd(0, 0, n - 1, idx, val);
    }

private:
    int query1(int idx, int low, int high, int l, int r)
    {
        if (high < l || r < low)
        {
            return INT_MIN;
        }
        if (l <= low && high <= r)
        {
            return maxi[idx];
        }
        int mid = (low + high) >> 1;
        int x = query1(2 * idx + 1, low, mid, l, r);
        int y = query1(2 * idx + 2, mid + 1, high, l, r);
        return max(x, y);
    }

    int query2(int idx, int low, int high, int l, int r)
    {
        if (high < l || r < low)
        {
            return INT_MAX;
        }
        if (l <= low && high <= r)
        {
            return mini[idx];
        }
        int mid = (low + high) >> 1;
        int x = query2(2 * idx + 1, low, mid, l, r);
        int y = query2(2 * idx + 2, mid + 1, high, l, r);
        return min(x, y);
    }

    int query3(int idx, int low, int high, int l, int r)
    {
        if (high < l || r < low)
        {
            return INT_MAX;
        }
        if (l <= low && high <= r)
        {
            return andd[idx];
        }
        int mid = (low + high) >> 1;
        int x = query3(2 * idx + 1, low, mid, l, r);
        int y = query3(2 * idx + 2, mid + 1, high, l, r);
        return x & y;
    }

    int query4(int idx, int low, int high, int l, int r)
    {
        if (high < l || r < low)
        {
            return 0;
        }
        if (l <= low && high <= r)
        {
            return orr[idx];
        }
        int mid = (low + high) >> 1;
        int x = query4(2 * idx + 1, low, mid, l, r);
        int y = query4(2 * idx + 2, mid + 1, high, l, r);
        return x | y;
    }
    void upd(int ind, int low, int high, int idx, int val)
    {
        if (low == high)
        {
            maxi[ind] = val;
            mini[ind] = val;
            orr[ind] = val;
            andd[ind] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (mid >= idx)
        {
            upd(ind * 2 + 1, low, mid, idx, val);
        }
        else
        {
            upd(2 * ind + 2, mid + 1, high, idx, val);
        }
        maxi[ind] = max(maxi[2 * ind + 1], maxi[2 * ind + 2]);
        mini[ind] = min(mini[2 * ind + 1], mini[2 * ind + 2]);
        orr[ind] = orr[2 * ind + 1] | orr[2 * ind + 2];
        andd[ind] = andd[2 * ind + 1] & andd[2 * ind + 2];
        return;
    }
};

int main()
{
    int n;
    cout << "Enter Array Size: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " Elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Segment_Tree st(arr);
    st.build(0, 0, n - 1, arr);
    while (true)
    {
        int l, r;
        cout << "Enter Your Range (l <= r): ";
        cin >> l >> r;
        if (l < 0 || r >= n || l > r)
        {
            cout << "Invalid range. Please try again." << endl;
            continue;
        }
        int x;
        cout << "Enter 1 for Calculating Max in Given Range" << endl;
        cout << "Enter 2 for Calculating Min in Given Range" << endl;
        cout << "Enter 3 for Calculating Bitwise Or in Given Range" << endl;
        cout << "Enter 4 for Calculating Bitwise And in Given Range" << endl;
        cout << "Enter 5 to Update Some Value in the Array" << endl;
        cout << "Enter 6 to exit" << endl;
        cin >> x;
        if (x == 1)
        {
            cout << "Max in Given Range: " << st.maximum(l, r) << endl;
        }
        else if (x == 2)
        {
            cout << "Minimum in Given Range: " << st.minimum(l, r) << endl;
        }
        else if (x == 3)
        {
            cout << "Bitwise Or of Given Range: " << st.orri(l, r) << endl;
        }
        else if (x == 4)
        {
            cout << "Bitwise And of Given Range: " << st.anddi(l, r) << endl;
        }
        else if (x == 5)
        {
            int idx;
            while (true)
            {
                cout << "Enter index at which value is to be Updated(0<=idx<n): ";
                cin >> idx;
                if (idx < 0 || idx >= n)
                {
                    cout << "Invalid Index. Please Try Again" << endl;
                }
                else
                {
                    break;
                }
            }
            int val;
            cout << "Enter New value: ";
            cin >> val;
            arr[idx] = val;
            st.update(idx, val);
            cout << "Updated!!" << endl;
        }
        else if (x == 6)
        {
            break;
        }
        else
        {
            cout << "Invalid option. Please try again." << endl;
        }
    }
    return 0;
}
