#include<vector>
#include<unordered_map>
#include<set>
using namespace std;


class NumberContainers {

    // LC:2349 Design a Number Container System
    // https://leetcode.com/problems/design-a-number-container-system/description/


    /**
    - Intuition is to have a map which tracks the index and value(number) at index. (Map of indexValues)
    - And we will have another map which tracks all the possible index in a set, of that number. (Map of numbersMap)
    - For find(), we check if the number is in the numbersMap, if available we return the first index from the set of that number 
    - For change(), we check if the index already exist, if yes we take the old number on that index and look up in the numbersMap
      to eliminate the index of that number from the set. Then, replace the number at the index in indexMap, and update the numbersMap with the new number and index position
      

    **/
    
    private:
    unordered_map<int,int> indexValues ;
    unordered_map<int,set<int>> numbersMap ;

    public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        //we first need to check if the index exists in the map, if exist we will have to replace the value, but before we do that
         // we need to remove the index from the numberMap, for that number which will be replaced

         if( indexValues.find(index) != indexValues.end() ) { //if the index exist in the indexValues map
            int numberToReplace = indexValues[index]; //retrieve the old number from the old index
            set<int> &indexSet = numbersMap[numberToReplace];
            auto it = indexSet.find(index);
            if(it != indexSet.end()) {
                indexSet.erase(index);
            }
            if(indexSet.empty()) {
                numbersMap.erase(numberToReplace);
            }
         }  

            //Update the value at existing index or add the key and value to the indexValues map
            indexValues[index] = number;

            //insert the index in the numbersMap
            numbersMap[number].insert(index);
         
        
    }
    
    /**
        check if the number is present in the numbersMap , if not present return -1;
        or else if number is present and the set is not empty, return the first element of the set
    **/
    int find(int number) {
        if(numbersMap.count(number) > 0) {
            set<int> &indexSet = numbersMap[number];
            if(!indexSet.empty()) {
                return *indexSet.begin();
            } 
        } 

        return -1;
    }

    /**
        Change() -> Time Complexity: O(log n)   because of the sorted set functionality
        find()   -> Time Complexity: O(1)       because of set being sorted, we can directly return the first index in constant time
    **/
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */