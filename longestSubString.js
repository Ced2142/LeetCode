/**
 * @param {string} s
 * @return {number}
 */ var lengthOfLongestSubstring = function(s) {
    var map = new Map();
    var count = 0;
    var maxcount=0;
    for(i=0;i<s.length;i++){
        var past_index = map.get(s[i]);
        if(past_index==undefined){
            count++;
        } else {
            if(past_index<(i-count)){
                count++;
            } else {
                count = i - past_index;
            }
        }
        if(count>maxcount){
            maxcount = count;
        }
        
        map.set(s[i],i);
    }
    return maxcount
}
