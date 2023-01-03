class Solution {
    public boolean areNumbersAscending(String s) {
        String[] s1 = s.split(" ");
        ArrayList<Integer> nums = new ArrayList<>();
        Arrays.stream(s1).forEach((s2) -> {
            if (s2.charAt(0) >= '0' && s2.charAt(0) <= '9') {
                int i = Integer.parseInt(s2);
                nums.add(i);
            }
        });
        for (int i = 1;i < nums.size();i ++) {
            if (nums.get(i) <= nums.get(i - 1)) {
                return false;
            }
        }
        return true;
    }
}