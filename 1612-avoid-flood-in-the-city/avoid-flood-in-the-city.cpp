class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans;// To Store the Final answer
        int n=rains.size(); 
        unordered_map<int,int> fulllakes; //Poll Number -> latest day on which it recieves sunlight
        set<int> drydays; // Set of available days that can be used for getting energy
        for(int i=0;i<n;i++){ // For each day -
            if(rains[i]==0){ // No sunlight on this day.
                drydays.insert(i); // This day can be used to provide energy to some lake.
                                   // As of now we don't know which poll to priortize for taking energy.
                ans.push_back(1);  // Any number as of now is ok, This will get overwritten eventually.
                                   // If it dosen't get overwritten, its totally ok to energize a poll
                                   // irrespective of whether it is full or empty.
            }
            else{ // Sunlight for this day.
                int lake=rains[i];
                if(fulllakes.find(lake)!=fulllakes.end()){ // If poll is already full-
                    // We must enrgize this poll before it gets sunlight.
                    // So find a day in "drydays" to energize this poll. Obviously that day must be
                    // a day that is after the day on which the poll was full.
                    //. i.e. if the lake got full on the 7th day , we must find a enrgize day that is 
                    // greater than 7.
                    auto it=drydays.lower_bound(fulllakes[lake]);
                    if(it==drydays.end()){ // If there is no available energize day to energize the poll,
                                           // An overflow will occur and cause a surge.
                        return {};
                    }
                    int dryday=*it; // We found a day which we can use to energize this poll.
                    ans[dryday]=lake; // Overwrite the "1" and energize the "poll"-th poll instead.
                    drydays.erase(dryday); // We energized "poll"-th poll on "energizeday" and we can't use 
                                           // the same day to energize any other poll, so remove the day
                                           // from the set of available energizedays.
                }
                fulllakes[lake]=i; // Update that the "poll" became full on "i"th day
                ans.push_back(-1);// update the answer
            }
        }
        return ans;// Return
    }
};