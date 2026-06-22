class Solution {
public:
    struct comp {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        }  
    };
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // two cars that have the same speed and diff location are different fleets

        // Sort cars based off of speed, so we start w/ the fastest cars (fleets align w/ the fastest car)

        // pairwise comps won't work (n^2 pairs)

        vector<vector<int>> cars;
        for(int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end(), comp());
        cout << cars[0][0] << endl;

        stack<vector<int>> car_stack;
        for(auto& c : cars) {
            if(car_stack.empty()) {car_stack.push(c);}
            else {
                if(isFleet(car_stack.top(), c, target)) {
                    // fleet is same speed as AHEAD car
                    // which is the car w/ the higher start pos
                    if(c[0] > car_stack.top()[0]) {
                        car_stack.top()[0] = c[0];
                        car_stack.top()[1] = c[1];
                    }
                }
                else {
                    car_stack.push(c);
                }
            }
        }
        return car_stack.size();
    }

    bool isFleet(vector<int>& a, vector<int>& b, int target) {
        int a_loc = a[0];
        int b_loc = b[0];
        int a_sd = a[1];
        int b_sd = b[1];

        int coeff_x = b_sd - a_sd;
        int cont = a_loc - b_loc;

        double time = (double)cont/(double)coeff_x;
        double dist = (double)a_sd * time + (double)a_loc;

        cout << dist << " " << a_loc << " " << b_loc << endl;
        if (dist >= 0 && dist <= (double)target) {
            if(dist < a_loc && dist < b_loc) {
                return false;
            }
            return true;
        }
        return false;
    }
};
