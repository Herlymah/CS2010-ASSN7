#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iomanip>

using namespace std;

using WORD = std::string;
using WORD_LIST = std::set<WORD>;
using LETTER_FREQ_LIST = std::map<char,int>;  // Now includes both capital and small letters
using WORD_FREQ_LIST = std::map<WORD, int>;
using FREQ_WORD_LIST = std::multimap<int,WORD>;
using COUNTER = std::tuple<int,int,int>;

struct funcObj
{
    bool operator()(const WORD& a, const WORD& b) { 
        return a.length() < b.length(); }
};
using LONGEST = std::priority_queue<WORD,std::vector<WORD>,funcObj>;

struct DICTION {
    COUNTER stats;
    WORD_LIST words;
    LETTER_FREQ_LIST wordFreq;  // Now tracks both capital and small letters separately
    WORD_FREQ_LIST wordFreqMap;
    FREQ_WORD_LIST freqWord;
    LONGEST longWord;
};

void showStats(const DICTION& d);
void drawHistograms(const DICTION& d);
void buildDictionary(DICTION& d);