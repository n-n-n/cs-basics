#include <string>
#include <map>
#include <unordered_map>

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

template < template<class ...> class MAP > 
vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
    vector<vector<string>> ret;
    if (strs.size() == 0) return ret;
    int index = 0;

     MAP<string, int> tmp;
     //unordered_map<string, int> tmp; // better using hashmap
     //map<string, int> tmp;
     for (auto itr = strs.begin(); itr != strs.end(); ++itr) {
        string key(*itr);
        sort(key.begin(), key.end());
        if (tmp.find(key) == tmp.end()) {
            tmp[key] = index;
            ret.push_back({*itr});
            index++;
        } else {
            ret[tmp[key]].push_back(*itr);
        }
    }
    return ret; 
};

int main ()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    
    steady_clock::time_point begin, end;
    begin = steady_clock::now();
    auto ret = groupAnagrams<map>(strs);
    end = steady_clock::now();
    cout << "elapsed: " << duration_cast<microseconds>(end - begin).count() << "[msec]" << endl;
    begin = steady_clock::now();
    auto ret0 = groupAnagrams<unordered_map>(strs);
    end = steady_clock::now();
    cout << "elapsed: " << duration_cast<microseconds>(end - begin).count() << "[msec]" << endl;

    return 0;
}
