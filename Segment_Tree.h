#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <vector>
#include <algorithm>
#include <climits>

class Segment_Tree
{
public:
    std::vector<int> maxi, mini, orr, andd, sum, lazy;
    int n;

    Segment_Tree(std::vector<int> &arr);
    void build(int ind, int low, int high, std::vector<int> &arr);
    int maximum(int l, int r);
    int minimum(int l, int r);
    int orri(int l, int r);
    int anddi(int l, int r);
    void update(int idx, int val);
    int sumi(int l, int r);
    void rangeupdate(int l, int r, int val);

private:
    int query1(int idx, int low, int high, int l, int r);
    int query2(int idx, int low, int high, int l, int r);
    int query3(int idx, int low, int high, int l, int r);
    int query4(int idx, int low, int high, int l, int r);
    void upd(int ind, int low, int high, int idx, int val);
    void doo(int ind, int low, int high, int val);
    void poo(int ind, int low, int mid, int high);
    int query5(int idx, int low, int high, int l, int r);
    void rupd(int ind, int low, int high, int l, int r, int val);
};

#endif // SEGMENT_TREE_H
