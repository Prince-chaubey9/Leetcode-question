typedef pair<int,int> pi;

class Twitter {
    
    unordered_map<int, unordered_set<int>> following; // contains stores which users a person follows
    unordered_map<int, vector<pi>> tweets; // user id maped with min heap , heap have timer and tweet id 
    
    int timer;
    const int k = 10; // only 10 tweets needed

public:
    
    Twitter() {
        timer = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId}); // userid m tweet k time k sath 
    }
    
    vector<int> getNewsFeed(int userId) {
        
        priority_queue<pi, vector<pi>, greater<pi>> pq; // tweet map se tweet ko map m dal taki last 10 mil sake 
        
        // User's own tweets
        int n = tweets[userId].size();
        
        for(int i = n - 1; i >= max(0, n - k); i--) {// heap m push kia 
            
            pq.push(tweets[userId][i]);
            
            if(pq.size() > k) // agr size grtr then 10 to pop kro 
                pq.pop();
        }
        
        // Followees' tweets
        for(int followee : following[userId]) { // user k follow k bhi tweets heap m push kiy 
            
            n = tweets[followee].size();
            
            for(int i = n - 1; i >= max(0, n - k); i--) {
                
                pq.push(tweets[followee][i]);
                
                if(pq.size() > k)
                    pq.pop();
            }
        }
        
        vector<int> feed; // heap se value ko feed vector m liya and return kia 
        
        while(!pq.empty()) {
            feed.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(feed.begin(), feed.end());
        
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId, tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId, followeeId);
 * obj->unfollow(followerId, followeeId);
 */

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */