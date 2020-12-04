bool isCryptSolution(vector<string> crypt, vector<vector<char>> solution) {
    map<char, int>  m;
    for (auto it : solution)
        for (size_t i = 0; i < it.size(); i += 2)
            m[it[i]] = std::atoi(&it[i + 1]);
    size_t word[3] = {0};
    size_t digits[3];

    for (size_t w = 0; w < crypt.size(); w++) {
        if (m[crypt[w][0]] == 0 && crypt[w].length() > 1)
            return false;
        for (auto c : crypt[w]) {
            word[w] = word[w] * 10 + m[c];
        }
    }
    for (size_t i = 0; i < 3; i++) {
        digits[i] = 1;
        int tmp = word[i];
        while (tmp >= 10) {
            tmp /= 10;
            digits[i]++;
        }
    }

    return (word[0] + word[1] == word[2]);
}
