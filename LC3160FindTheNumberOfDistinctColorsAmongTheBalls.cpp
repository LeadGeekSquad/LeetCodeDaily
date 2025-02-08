#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
    public:
        vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    
            // LC:3160 Find the Number of Distinct Colors Among the Balls
            // https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/description/
    
    
            //tbh: This was a kind of a question which really made me think a lot
            // completely tricked me in the beginning

            //tip: only paint the balls you are really going to paint, 
            //no overhead needed to paint all the balls with no color in the beginning
    
    
         /**
            Intuition:
            - to track the balls painted we will have an unordered_map<int,int> which holds the index/ball as key and the color painted as value
            - to track the frequency of the colors painted we will have another unordered_map<int,int> which holds the color as key and it's frequency as it's value.
            - keep a variable distinct count to store the count of distinct colors
            - if we find a ball that is already painted, we decrement it's frequency count as it will be replaced with new color. we also need to check for distinctCount, if the frequency of that color is equal to 0 we decrement the distinctCount by 1.
            - if we find a ball that is not already painted or needs to be updated with new paint, we paint the ball and increase the color frequency, if it's a totally new color we add it to the distinctCount
            - after each query we iterate through, we push the distinctCount in the result
    
         **/   
    
            
        unordered_map<int,int> colored_balls;  // Ball labels from 0 to limit
        unordered_map<int, int> color_freq;       // Tracks frequency of each color
        int distinct_count = 0;                   // Current number of distinct colors
        vector<int> result;                       //return result, fill the result array with distinct count after every query
    
        for (const auto& query : queries) {
            // x is going to be the ball that needs to be painted. (simply x is index/ball)
            // y is going to be color that we will use to paint the ball at x. (simply y is the color we paint on x ball/index)
            int x = query[0];
            int y = query[1];
    
            //iterator return "-1" if x isn't painted previously, or else returns the color value if painted by accessing it->second
            //looking up the keys that means color index of the ball which needs to be painted
            //if it is previously painted it will have a positive value, or else if we are painting it for the first time we will put -1 in old color;
            auto it = colored_balls.find(x);
            int old_color = (it != colored_balls.end()) ? it->second : -1;
    
            // if old_color is other than -1, that means the ball was previously painted, we get the frequency of that color and decrement by 1
            // Process old color removal
            if (old_color != -1) {
                color_freq[old_color]--;
                if (color_freq[old_color] == 0) {
                    distinct_count--;
                }
            }
    
            // Update with new color if previouly painted or paints x with color y for the very first time
            colored_balls[x] = y;
            color_freq[y]++; // Increment new color frequency
            if (color_freq[y] == 1) { // If this color is newly added, we add it to the distinct count list
                distinct_count++;
            }
    
            result.push_back(distinct_count);  //after each query append the distinct count to the result
        }
    
        return result;
    
        }
    
        /**
    
        Time Complexity: O(n)  such that n is the number of queries
        Space Complexity: O(n)  our both maps atmost stores n entries and so does our result
    
        **/
    };