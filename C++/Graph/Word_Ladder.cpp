class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         
         unordered_map<string,int> mp;
         for( int i = 0; i < wordList.size(); i++ ){
             mp[wordList[i]]++;
         }

         queue<pair<string, int>> q;
         q.push({beginWord, 1});

         if(mp[beginWord]) mp.erase(beginWord);

         while(!q.empty()){
             string start = q.front().first;
                int value = q.front().second;
             q.pop();

             if(start==endWord) return value;
             
             
             for( int i = 0; i < start.size(); i++ ){
                 char ch1 = start[i];
                 for( char ch = 'a'; ch<='z'; ch++){
                      start[i] = ch;

                      if(mp[start]){
                          q.push({start, value+1});
                          mp.erase(start);
                      }
                 }

                 start[i] = ch1;
                 
             }
         }

         return 0;
    }
};