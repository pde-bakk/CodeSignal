//
// Created by peerdb on 01-12-20.
//

bool sudoku2(vector<vector<char>> grid) {
	set<char> s;
	vector<set<char>>    big;
	big.reserve(9);
	for (size_t i = 0; i < 9; i++)
		big[i].clear();

	for (auto it : grid) {
		s.clear();
		if (it.size() != 9)
			return false;
		for (size_t i = 0; i < grid.size(); i++) { // checking each row
			if (it[i] != '.') {
				cout << i;
				if (s.count(it[i]))
					return false;
				if (big[i].count(it[i])) {
					return false;
				}
				// cout << "i = " << i << "big[i].count(it[i]) = " << big[i].count(it[i]) << ", it[i] = " << it[i] << endl;
				s.insert(it[i]);
				big[i].insert(it[i]);
			}
		}
	}
	return true;
}