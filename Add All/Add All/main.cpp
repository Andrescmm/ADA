#include <iostream>
#include <vector>
#include <set>

using namespace std;


int Add_All(multiset<int> s,int cost){
    int sum;
    cost = 0;
    multiset<int>::iterator it1 , it2;
      while(1){
        if(s.size() == 1) break;
        it1 = s.begin() ; it2 = it1++;
        sum = (*it1)+(*it2);
        s.erase(it1) ; s.erase(it2);
        s.insert(sum);
        cost += sum;
      }
    return cost;
}


int main() {
  int n,v,cost;
  multiset<int> s;
  // lee
  while(scanf("%d" , &n) && n){
    s.clear();
    for(int i = 0 ; i < n ; i++){
      scanf("%d" , &v) ; s.insert(v);
    }
    cout << Add_All(s, cost) << endl;
  }

  /*
  for (std::multiset<int>::const_iterator i(s.begin()), end(s.end());
     i != end;
     ++i)
    cout << *i << "\n";
  */
    //Add_All(array);
    
}
