class Solution {
public:
    void nextStep(int &curr, vector<int> &nums) {
        curr = nums[curr];
    }
    
    void nextNextStep(int &curr, vector<int> &nums) {
        nextStep(curr, nums);
        nextStep(curr, nums);
    }
    
    int findDuplicate(vector<int>& nums) {
        int tortoise = 0, hare = 0;
        
        do {
            nextStep(tortoise, nums);
            nextNextStep(hare, nums);
        }while(tortoise != hare);
        
        hare = 0;
        while(tortoise != hare) {
            nextStep(tortoise, nums);
            nextStep(hare, nums);
        }
        
        return tortoise;
    }
};
