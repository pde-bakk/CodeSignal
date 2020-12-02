//
// Created by peerdb on 01-12-20.
//


char firstNotRepeatingCharacter(string s) {
	char* hashmap = (char*)calloc(256, sizeof(int));
	for (auto it : s) {
		hashmap[it]++;
	}

	for (auto it : s) {
		if (hashmap[it] == 1)
			return it;
	}
	return '_';
}
