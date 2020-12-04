//
// Created by peerdb on 01-12-20.
//

vector<vector<int>> rotateImage(vector<vector<int>> a) {
	const size_t Size = a.size() - 1;
	vector<vector<int>> out(a);

	for (size_t row = 0; row < Size + 1; ++row) {
		for (size_t i = 0; i < a[row].size(); ++i) {
			// cout << "Size: " << Size << ", row: " << row << ", i: " << i << endl;
			// cout << "Size - row: " << Size - row << endl;
			// cout << "replacing " << a[row][i] << " with " << out[i][Size - row] << endl;
			out[i][Size - row] = a[row][i];
		}
	}
	return out;
}