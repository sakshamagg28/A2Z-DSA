// Method: HashMap + Linked List + Max Heap
// Time Complexity:
//   postTweet  : O(1)
//   follow     : O(1)
//   unfollow   : O(1)
//   getNewsFeed: O((F + 10) log F)
//      F = number of followed users (including self)
// Space Complexity: O(T + F)
//   T = total tweets
// Standard Interview Solution

class Twitter {
    struct Tweet {
        int id;
        int time;
        Tweet* next;

        Tweet(int tweetId, int t) {
            id = tweetId;
            time = t;
            next = nullptr;
        }
    };

    struct cmp {
        bool operator()(Tweet* a, Tweet* b) {
            return a->time < b->time;
        }
    };

    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, Tweet*> tweets;

    int timer = 0;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        Tweet* node = new Tweet(tweetId, timer++);
        node->next = tweets[userId];
        tweets[userId] = node;
    }

    vector<int> getNewsFeed(int userId) {
        following[userId].insert(userId);

        priority_queue<Tweet*, vector<Tweet*>, cmp> pq;

        for (int user : following[userId]) {
            if (tweets.count(user))
                pq.push(tweets[user]);
        }

        vector<int> ans;

        while (!pq.empty() && ans.size() < 10) {
            Tweet* cur = pq.top();
            pq.pop();

            ans.push_back(cur->id);

            if (cur->next)
                pq.push(cur->next);
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followeeId != followerId)
            following[followerId].erase(followeeId);
    }
};


