#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;


class Twitter {
    struct tweet {
        int tweetId;
        int sequence;
        tweet(int id, int seq): tweetId(id), sequence(seq) {}
    };
    int m_sequence;
    unordered_map<int, vector<tweet> > m_UserTweetsMap;
    unordered_map<int, set<int>> m_UserFollowMap;
public:

    Twitter() {
        m_sequence = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        if(m_UserTweetsMap.find(userId) == m_UserTweetsMap.end())
            m_UserTweetsMap[userId] = vector<tweet>();
        m_UserTweetsMap[userId].push_back(tweet(tweetId, m_sequence++));
    }
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        m_UserFollowMap[userId].insert(userId);
        vector<int> followee(m_UserFollowMap[userId].begin(), m_UserFollowMap[userId].end());
        int usize = followee.size();
        vector<int> index(usize, 0);
        for(int uid = 0; uid < usize; ++uid) index[uid] = m_UserTweetsMap[followee[uid]].size() - 1; 
        while(res.size() < 10) {
            int maxseq = -1;
            int maxuid = -1;
            for(int uid = 0; uid < usize; ++uid) {
                if (index[uid] < 0) continue;
                tweet &one = m_UserTweetsMap[followee[uid]][index[uid]];
                if (one.sequence > maxseq) {
                    maxseq = one.sequence;
                    maxuid = uid;
                }
            }
            if (maxuid == -1) break;
            res.push_back(m_UserTweetsMap[followee[maxuid]][index[maxuid]--].tweetId);
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        m_UserFollowMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        m_UserFollowMap[followerId].erase(followeeId);
    }
};

int main(int argc, char *argv[])
{
    Twitter obj;
    int userId = 1;
    int tweetId = 5;
    int followerId = 1;
    int followeeId = 2;
    obj.postTweet(userId,tweetId);
    vector<int> param_2 = obj.getNewsFeed(userId);
    obj.follow(followerId,followeeId);
    obj.unfollow(followerId,followeeId);
    cout << "" << endl;
    return 0;
}
