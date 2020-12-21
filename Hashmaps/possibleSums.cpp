int possibleSums(std::vector<int> coins, std::vector<int> quantity) {
     unordered_set<int> p;
     p.insert(0);
     
     for(int i=0; i<coins.size(); ++i) {
          auto tmp = p;
          for(int f=1; f<=quantity[i]; ++f) {
               for(int elt: tmp)
                    p.insert(elt+f*coins[i]);
          }
     }
     
     return p.size()-1;
}
