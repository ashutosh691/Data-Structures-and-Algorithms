class Solution {
public:
    bool isSafe(vector<vector<int>>& mat, vector<vector<bool>>& vis, int i, int j) {
        int n = mat.size(), m = mat[0].size();
        return i < n && j < m && i >= 0 && j >= 0 && !vis[i][j] && !mat[i][j];
    }

    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<int>> mat(n, vector<int>(m, 0));
        queue<tuple<int, int, int>> q;
        for(auto &i : sources) {
            mat[i[0]][i[1]] = i[2];
            q.push({i[0], i[1], i[2]});
        }
        while(!q.empty()) {
            int sz = q.size();
            vector<tuple<int, int, int>> temp;
            while(sz--) {
                temp.push_back(q.front());
                q.pop();   
            }
            sort(temp.begin(), temp.end(), [](auto& i, auto& j) {
                return get<2>(i) > get<2>(j);
            });
            vector<int> dr = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
            for(int j = 0; j < temp.size(); ++j)
                for(int i = 0; i < 4; ++i) {
                    int xr = dr[i] + get<0>(temp[j]), xy = dy[i] + get<1>(temp[j]);
                    if(isSafe(mat, vis, xr, xy)) {
                        mat[xr][xy] = get<2>(temp[j]);
                        vis[xr][xy] = true;
                        q.push({xr, xy, get<2>(temp[j])});
                    }
                }
        }
        return mat;
    }
};