bool areFollowingPatterns(vector<string> strings, vector<string> patterns) {
    unordered_map<string, string>   str,
                                    patt;
    for (size_t i = 0; i < strings.size(); i++) {
        if (str.find(strings[i]) == str.end())
            str[strings[i]] = patterns[i];
        if (patt.find(patterns[i]) == patt.end())
            patt[patterns[i]] = strings[i];
        if (str[strings[i]] != patterns[i] || patt[patterns[i]] != strings[i])
            return false;
    }
    return true;
}
