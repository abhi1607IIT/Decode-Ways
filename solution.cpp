class Solution {
public:
    int numDecodings(string s) {

    	// size of the input string
        int size = s.length();

        // initialised dynamiarray of size n+1 with 0
        int TotalDecodings[size+1] = {0};

        // Used as base for i=n-2
        TotalDecodings[size]=1;

        // iterating over the input string 
        for(int index = size-1; index >= 0; index--){

        	// if input value at current index is not 0 then calling for value at index + 1
            if(s[index]!='0' && (index+1==size || s[index+1]!='0')){
                TotalDecodings[index] += TotalDecodings[index + 1];
            }
            
            // if input value at current index is not 0 and value representing current and next index is less than 27 then call for value at index + 2
            if(s[index]!='0' && index + 1 < size && ((s[index]-'0')*10) + (s[index+1]-'0') < 27 && (index + 2 >= size || s[index+2]!='0')){
                TotalDecodings[index] += TotalDecodings[index + 2];
            }
            
        }

        // returning the total decodings
        return TotalDecodings[0];
    }
};