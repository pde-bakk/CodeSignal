bool sudoku2(vector<vector<char>> grid) {
    set<char>   s;
    set<char>   big[9];
    set<char>   subgrid[9];
    size_t  row = 0;
    for (auto it : grid) {
        s.clear();
        if (it.size() != 9)
            return false;
        for (size_t i = 0; i < grid.size(); i++) { // checking each row
            if (it[i] != '.') {
                cout << i;
                if (s.count(it[i]) || big[i].count(it[i]) || subgrid[3 * (row / 3) + (i / 3)].count(it[i]))
                    return false;
                s.insert(it[i]);
                big[i].insert(it[i]);
                subgrid[3 * (row / 3) + (i / 3)].insert(it[i]);
            }
        }
        row += 1;
    }
    return true;
}


// // Best Solution

// bool sudoku2(std::vector<std::vector<char>> grid) {
//     for (char c = '1'; c <= '9'; ++c) {
//         for (int i = 0; i < 9; ++i) {
//             int c1 = 0, c2 = 0, c3 = 0;
//             for (int j = 0; j < 9; ++j) {
//                 c1 += grid[i][j] == c;
//                 c2 += grid[j][i] == c;
//                 c3 += grid[i/3*3+j/3][i%3*3+j%3] == c;
//             }
//             if (c1 > 1 || c2 > 1 || c3 > 1)
//                 return false;
//         }
//     }
//     return true;
// }
