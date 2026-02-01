var answer = 0;

function dfs(numbers, target, sum, index) {
    if(index == numbers.length) {
        if(sum == target) answer++;
        return;
    }
    dfs(numbers, target, sum + numbers[index], index + 1);
    dfs(numbers, target, sum - numbers[index], index + 1);
}

function solution(numbers, target) {
    dfs(numbers, target, 0, 0);
    
    return answer;
}