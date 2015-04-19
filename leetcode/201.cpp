

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(n == m)
            return n;
        vector<int> vm, vn;
        while(m) {
            vm.push_back(m % 2);
            m /= 2;
        }
        while(n) {
            vn.push_back(n % 2);
            n /= 2;
        }
        while(vm.size() < vn.size())
            vm.push_back(0);
        while(vn.size() < vm.size())
            vn.push_back(0);
        vector<int> v(max(vn.size(), vm.size()), 1);
        for(int i = 0; i < v.size(); i++)
            if((vm[i] == 0 && vn[i] == 1) || (vm[i] == 1 && vn[i] == 0)) {
                for(int j = 0; j <= i; j++)
                    v[j] = 0;
			} else if (vm[i] == 0 || vn[i] == 0)
			    v[i] = 0;
        int ans = 0;
        for(int i = v.size() - 1; i >= 0; i--)
            ans = ans * 2 + v[i];
        return ans;
    }
};

