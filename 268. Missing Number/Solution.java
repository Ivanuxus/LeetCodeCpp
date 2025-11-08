class Solution {
    public int missingNumber(int[] nums) {
        int result = 0;
        int buff = -5555;
        for (int i = 0; i <= nums.length; i++) {
            for (int j = 0; j < nums.length; j++) {
                if (i == nums[j]) {
                    break;
                }
                if (j == nums.length - 1) {
                    buff = i;
                }
            }
            if (buff != -5555) {
                return buff;
            }
        }
        return result;
    }
}

class Main {
    public static void main(String[] args) {
        Solution Instance = new Solution();
        int[] nums = {0, 1};
        int result = Instance.missingNumber(nums);
        System.out.println(result);
    }
}

