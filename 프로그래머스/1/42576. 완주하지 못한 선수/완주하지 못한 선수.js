function solution(participant, completion) {
    const hash = {}
    
    for(let i = 0; i < completion.length; i++) {
        if(!hash[completion[i]]) hash[completion[i]] = 1;
        else hash[completion[i]]++;
    }
    
    for(let i = 0; i < participant.length; i++) {
        if(!hash[participant[i]]) return participant[i];
        if(hash[participant[i]]) hash[participant[i]]--;
    }
}