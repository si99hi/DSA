class Solution {
    public boolean validPalindrome(String s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            left++;
            right--;
        }
        return true; // Added missing return statement
    }

    public boolean isPalindrome(String s, int left, int right) {
        // Removed redeclaration of left and right
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                return false;
            }
            left++;
            right--; // Moved these inside the while loop
        }
        return true; // Added return true when loop completes
    }
}