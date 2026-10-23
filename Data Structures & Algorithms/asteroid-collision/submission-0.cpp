class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st; // Using a vector as a stack is faster and easier to return
        
        for (int x : asteroids) {
            bool destroyed = false;
            
            // Collision only happens if stack has a right-moving asteroid 
            // and the current asteroid is moving left.
            while (!st.empty() && st.back() > 0 && x < 0) {
                if (st.back() < -x) {
                    st.pop_back(); // Top asteroid explodes, keep checking the next one
                    continue;
                } else if (st.back() == -x) {
                    st.pop_back(); // Both asteroids explode
                }
                destroyed = true; // Current asteroid explodes (either equal size or larger top)
                break;
            }
            
            if (!destroyed) {
                st.push_back(x);
            }
        }
        
        return st;
    }
};