class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // Vector to be returned back
        std::vector<std::string> repDnaSeq;
        // Throw all the strings of length 10 into a multiSet hashTable
        if(s.length() >= 10)
        {
            populateHashSet(s);
            // Populate the vector to be returned back
            for(int sIdx=0; sIdx <= s.length()-10; ++sIdx)
            {
                const std::string sSubStr = s.substr(sIdx, 10);
                if(hashSet_.count(sSubStr) > 1)
                {
                    if (repDnaSeq.empty() || std::find(repDnaSeq.begin(), repDnaSeq.end(), sSubStr) == repDnaSeq.end())
                    {
                        repDnaSeq.emplace_back(sSubStr);  
                    }
                }
            }
        }
        return repDnaSeq;
    }
private:
    void populateHashSet(string s)
    {
        // Loop through string and cache all substrings of size 10 in the set
        for(int sIdx=0; sIdx <= s.length()-10; ++sIdx)
        {
            hashSet_.insert(s.substr(sIdx, 10));
        }
    }
    std::unordered_multiset<std::string> hashSet_;
};