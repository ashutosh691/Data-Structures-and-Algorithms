class NumArray {
public:
    vector<int> tree, arr;
    int n;

    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n, 0);
        arr = nums;
        build(0, 0, n - 1);
    }

    void build(int node, int l, int r) {
        if(l == r) {
            tree[node] = arr[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * node + 1, l, mid);
        build(2 * node + 2, mid + 1, r);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    void upd(int node, int ind, int val, int l, int r) {
        if(l == r) {
            arr[ind] = val;
            tree[node] = val;
            return; 
        }
        int mid = l + (r - l) / 2;
        if(l <= ind && ind <= mid) upd(2 * node + 1, ind, val, l, mid);
        else upd(2 * node + 2, ind, val, mid + 1, r);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int query(int node, int l, int r, int st, int end) {
        if(st > r || end < l) return 0;
        if(st >= l && end <= r) return tree[node];
        int mid = st + (end - st) / 2;
        int q1 = query(2 * node + 1, l, r, st, mid);
        int q2 = query(2 * node + 2, l, r, mid + 1, end);
        return q1 + q2;
    }

    void update(int index, int val) {
        upd(0, index, val, 0, n - 1);
    }
    
    int sumRange(int left, int right) {
        return query(0, left, right, 0, n - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */