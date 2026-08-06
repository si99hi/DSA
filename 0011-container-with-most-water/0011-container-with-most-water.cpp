class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right= height.size()-1;
        int area=0;
        while(left<=right){
            int width= right-left;
            int h= min(height[right], height[left]);
            
            area= max(area, width*h);

            if(height[left]<=height[right]){
                left++;
            }
            else{
                right--;
            }

        }
        return area;
        
    }
};