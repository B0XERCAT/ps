function solution(nums) {
    const set = new Set(nums);
    const setSize = set.size;
    return Math.min(setSize, nums.length / 2)
}