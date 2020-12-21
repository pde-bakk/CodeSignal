bool containsCloseNums(vector<int> nums, int k) {
    unordered_set<int>  S;
    unordered_map<int, vector<int>> M;
    
    for (size_t i = 0; i < nums.size(); i++) {
        M[nums[i]].push_back(i);
    }
    for (auto& it : M) {
        for (size_t i = 0; i < it.second.size() - 1; i++)
            if (it.second[i + 1] - it.second[i] <= k)
                return true;
    }
    return false;
}
