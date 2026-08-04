class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int maxarea=0;
        int right= height.size()-1;
        for(int i=0; i<height.size(); i++){
            int area= (min(height[left], height[right]) * (right-left));
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
            maxarea= max(area, maxarea);

        }
        return maxarea;
        
    }
};