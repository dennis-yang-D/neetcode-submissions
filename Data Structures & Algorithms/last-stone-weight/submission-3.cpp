class Solution {
public:
    // bucket sort solution
    vector<int> buckets;
    int lastStoneWeight(vector<int>& stones) {
        buckets.resize(101); // so we have 1 - 101 avaliable

        for(int s : stones) {
            buckets[s]++;
        }

        int i = 100;


        while(true) {
            int s1 = 0;
            int s2 = 0;
            // find s1
            while(i > -1 && buckets[i] == 0) {
                i--;
            }
            //cout << "a" << i << " ";
            if(i == -1) {break;}
            s1 = i;
            buckets[i]--;
            // find s2
            while(i > -1 && buckets[i] == 0) {
                i--;
            }
            //cout << "b" << i << " ";
            if(i == -1) {
                buckets[s1]++;
                break;
            }
            s2 = i;
            buckets[i]--;

            if(s1 == 0 && s2 == 0) {return 0;}
            buckets[abs(s1-s2)]++;
            i = max(i, abs(s1-s2));
            //cout << i << endl;
        }

        //for(int i : buckets) {
        //    cout << i << " ";
        //}


        for(int j = 100; j > -1; j--) {
            if(buckets[j] > 0) {return j;}
        }
        return 0;
    }
};
