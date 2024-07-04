#include "Segment_Tree.h"
#include <climits>

Segment_Tree::Segment_Tree(std::vector<int> &arr) {
    n = arr.size();
    maxi.resize(4 * n);
    mini.resize(4 * n);
    orr.resize(4 * n);
    andd.resize(4 * n);
    sum.resize(4 * n);
    lazy.resize(4 * n, 0);
}

void Segment_Tree::build(int ind, int low, int high, std::vector<int> &arr) {
    if (low == high) {
        maxi[ind] = arr[low];
        mini[ind] = arr[low];
        orr[ind] = arr[low];
        andd[ind] = arr[low];
        sum[ind] = arr[low];
        return;
    }
    int mid = low + (high - low) / 2;
    build(2 * ind + 1, low, mid, arr);
    build(2 * ind + 2, mid + 1, high, arr);
    maxi[ind] = std::max(maxi[2 * ind + 1], maxi[2 * ind + 2]);
    mini[ind] = std::min(mini[2 * ind + 1], mini[2 * ind + 2]);
    orr[ind] = orr[2 * ind + 1] | orr[2 * ind + 2];
    andd[ind] = andd[2 * ind + 1] & andd[2 * ind + 2];
    sum[ind] = sum[2 * ind + 1] + sum[2 * ind + 2];
}

int Segment_Tree::maximum(int l, int r) {
    return query1(0, 0, n - 1, l, r);
}

int Segment_Tree::minimum(int l, int r) {
    return query2(0, 0, n - 1, l, r);
}

int Segment_Tree::orri(int l, int r) {
    return query4(0, 0, n - 1, l, r);
}

int Segment_Tree::anddi(int l, int r) {
    return query3(0, 0, n - 1, l, r);
}

void Segment_Tree::update(int idx, int val) {
    upd(0, 0, n - 1, idx, val);
}

int Segment_Tree::sumi(int l, int r) {
    return query5(0, 0, n - 1, l, r);
}

void Segment_Tree::rangeupdate(int l, int r, int val) {
    return rupd(0, 0, n - 1, l, r, val);
}

int Segment_Tree::query1(int idx, int low, int high, int l, int r) {
    if (high < l || r < low) {
        return INT_MIN;
    }
    if (l <= low && high <= r) {
        return maxi[idx];
    }
    int mid = (low + high) >> 1;
    int x = query1(2 * idx + 1, low, mid, l, r);
    int y = query1(2 * idx + 2, mid + 1, high, l, r);
    return std::max(x, y);
}

int Segment_Tree::query2(int idx, int low, int high, int l, int r) {
    if (high < l || r < low) {
        return INT_MAX;
    }
    if (l <= low && high <= r) {
        return mini[idx];
    }
    int mid = (low + high) >> 1;
    int x = query2(2 * idx + 1, low, mid, l, r);
    int y = query2(2 * idx + 2, mid + 1, high, l, r);
    return std::min(x, y);
}

int Segment_Tree::query3(int idx, int low, int high, int l, int r) {
    if (high < l || r < low) {
        return INT_MAX;
    }
    if (l <= low && high <= r) {
        return andd[idx];
    }
    int mid = (low + high) >> 1;
    int x = query3(2 * idx + 1, low, mid, l, r);
    int y = query3(2 * idx + 2, mid + 1, high, l, r);
    return x & y;
}

int Segment_Tree::query4(int idx, int low, int high, int l, int r) {
    if (high < l || r < low) {
        return 0;
    }
    if (l <= low && high <= r) {
        return orr[idx];
    }
    int mid = (low + high) >> 1;
    int x = query4(2 * idx + 1, low, mid, l, r);
    int y = query4(2 * idx + 2, mid + 1, high, l, r);
    return x | y;
}

void Segment_Tree::upd(int ind, int low, int high, int idx, int val) {
    if (low == high) {
        maxi[ind] = val;
        mini[ind] = val;
        orr[ind] = val;
        andd[ind] = val;
        sum[ind] = val;
        return;
    }
    int mid = (low + high) / 2;
    poo(ind, low, mid, high);
    if (mid >= idx) {
        upd(ind * 2 + 1, low, mid, idx, val);
    } else {
        upd(2 * ind + 2, mid + 1, high, idx, val);
    }
    maxi[ind] = std::max(maxi[2 * ind + 1], maxi[2 * ind + 2]);
    mini[ind] = std::min(mini[2 * ind + 1], mini[2 * ind + 2]);
    orr[ind] = orr[2 * ind + 1] | orr[2 * ind + 2];
    andd[ind] = andd[2 * ind + 1] & andd[2 * ind + 2];
    sum[ind] = sum[2 * ind + 1] + sum[2 * ind + 2];
}

void Segment_Tree::doo(int ind, int low, int high, int val) {
    sum[ind] += (high - low + 1) * val;
    lazy[ind] += val;
}

void Segment_Tree::poo(int ind, int low, int mid, int high) {
    if (lazy[ind] != 0) {
        doo(2 * ind + 1, low, mid, lazy[ind]);
        doo(2 * ind + 2, mid + 1, high, lazy[ind]);
        lazy[ind] = 0;
    }
}

int Segment_Tree::query5(int idx, int low, int high, int l, int r) {
    if (high < l || r < low) {
        return 0;
    }
    if (l <= low && high <= r) {
        return sum[idx];
    }
    int mid = (low + high) / 2;
    poo(idx, low, mid, high);
    int x = query5(2 * idx + 1, low, mid, l, r);
    int y = query5(2 * idx + 2, mid + 1, high, l, r);
    return x + y;
}

void Segment_Tree::rupd(int ind, int low, int high, int l, int r, int val) {
    if (high < l || r < low)
        return;
    if (l <= low && high <= r) {
        doo(ind, low, high, val);
        return;
    }
    int mid = (low + high) / 2;
    poo(ind, low, mid, high);
    rupd(2 * ind + 1, low, mid, l, r, val);
    rupd(2 * ind + 2, mid + 1, high, l, r, val);
    sum[ind] = sum[2 * ind + 1] + sum[2 * ind + 2];
}
