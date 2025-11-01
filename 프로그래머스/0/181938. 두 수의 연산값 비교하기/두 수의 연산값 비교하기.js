function solution(a, b) {
    var answer = 0;
    if(2 * a * b > parseInt(a.toString() + b.toString()))  {
        answer = 2 * a * b;
    }
    else {
        answer = parseInt(a.toString() + b.toString());
    }
    return answer;
}