//
// Created by peerdb on 01-12-20.
//

int firstDuplicate(vector<int> a) {
	std::set<int> s;
	for (auto it : a) {
		if (s.count(it) > 0)
			return it;
		s.insert(it);
	}
	return -1;
}
