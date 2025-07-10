#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <unordered_map>
using namespace std;

class Solution
{
    public: int Distance(vector<int> list1, vector<int> list2){
        int diff = 0;

        sort(list1.begin(), list1.end());
        sort(list2.begin(), list2.end());

        //iterate through list1 and get distance in absolute value (to avoid negative values)
        for(int i = 0; i < list1.size(); i++){
            diff += abs(list2[i] - list1[i]);
        }
        cout << "Total difference: " << diff << endl;
        return diff;
    }

    public: int Similarity(vector<int> list1, vector<int> list2){
        //hash map is needed to record freq of each number in list 2
        unordered_map<int,int> similartyCheck;
        int similarityScore = 0;
        //push all numbers from list2 to the hash map and increase their occurrence count
        for(int j = 0; j < list2.size(); j++){
            int num = list2[j];
            similartyCheck[num]++;
        }
        //iterate through list1 and check if number is present in the hash map,
        //if present, increase similarity score by list[i] value and occurrence count of the number in the map
        for(int i = 0; i < list1.size(); i++){
            int num = list1[i];
            if(similartyCheck.count(num)){
                similarityScore += num * similartyCheck[num];
            }
        }
        cout << "Similarity score: " << similarityScore << endl;
        return similarityScore;
    }

    // public: int LevelSafetyCheck(vector<vector<int>> levelsList){
    //     return 0;
    // }
};



int main(int argc, char const *argv[])
{
    ifstream input1;
    input1.open("input.txt");
    vector<int> col1, col2;

    // ifstream input2;
    // input2.open("input2.txt");
    // vector<vector<int>> levels;
    // string line;
    istream_iterator<string> start(input1), end;    

    for (auto it = start; it != end; ++it) {
            int val1 = std::stoi(*it);
            if (++it != end) {
                int val2 = std::stoi(*it);
                col1.push_back(val1);
                col2.push_back(val2);
            }
        }

        Solution().Distance(col1, col2);
        Solution().Similarity(col1, col2);
        //Solution().LevelSafetyCheck(levels);
    return 0;
}


