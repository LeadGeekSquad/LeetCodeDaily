#include<vector>
using namespace std;



class ProductOfNumbers {

    // LC1352 Product of the Last K Numbers
    // https://leetcode.com/problems/product-of-the-last-k-numbers/description/


    /**
        intuition:
        - for add()
        - we will need a stream which stores the elements that are being added
        - we will need a prefixProduct which stores the product of current num being added and the previous num
        - in case if the current num being added is 0, we update the lastIndexOfZero and reset the prefixProduct with 1
        - for getProduct()
        - we first need to find the begin index for the product which will be size of stream - k
        - starting that position to n-1 is the sequence we need to return the product for
        - if our lastIndexofZero is greater than or equal to the beginIndexForProduct we return 0, as the product will be 0
        - else we return from our prefixProduct, we take the last element from our prefixProduct 
            and we divide it with value at index prefixProduct[prefixProduct.size() - 1 - k]
        - we deduct that extra - 1 from the prefixProduct.size() because we have added one extra element in prefixProduct while initializing prefixProduct
    **/


private:
    vector<int> stream; //adds the element to the stream
    vector<int> prefixProduct; //keeps the precalculated prefix of the current number and the last number
    int indexOfLastZero;  //keeps the track of the latest index of zero

public:
    ProductOfNumbers() {
        indexOfLastZero = -1;
        prefixProduct = {1};
    }
    
    void add(int num) {
        stream.push_back(num);

        if(num == 0) {
            indexOfLastZero = stream.size() - 1; //note the index of zero
            prefixProduct = {1}; //reset the prefixProduct to 1
        } else {
            prefixProduct.push_back(prefixProduct.back() * num);
        }
    }
    
    int getProduct(int k) {
        int beginIndexForProduct = stream.size() - k;

        //if our index of last zero begins on or after the index of beginIndexForProduct that means the product is going to be zero 
        if(indexOfLastZero >= beginIndexForProduct) {
            return 0;
        }

        return prefixProduct.back() / prefixProduct[prefixProduct.size() - 1 - k];
    }

    /**
     * Time Complexity add(): O(1) (amortized time complexity)
     * Space Complexity add(): O(N) (stream will be of size N, where N is the number of elements added in the stream using add() ) 
     *                                  (and the elements in the prefixProduct will be N+1, so basically N)
     * 
     * 
     * Time Complexity getProduct(): O(1)  (we are using the prefixProduct to achieve constant time)
     * Space Complexity getProduct(): O(1) (no extra space utilized)
     */
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */



 /**
  * less optimal approach where our time complexity is O(k) for getProduct, where k is the last k integers.
  * the space will be O(n) where n is the size of the stream
  * 
  * 
  * class ProductOfNumbers {
private:
    vector<int> stream;
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        stream.push_back(num);
    }
    
    int getProduct(int k) {
        int temp = k;
        int product = 1;
        for(int i = stream.size()-1 ; i >= 0 ; i-- ) {
            if(temp > 0) {
                product *= stream[i];
                temp--;
            } else {
                break;
            }
        }
        return product;
    }
};
  * 
  */