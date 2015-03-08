class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint64_t t1 = n, t2 = 0;
        for (int i = 0; i < 32; i++) {
            t2 = t2 * 2 + t1 % 2;
            t1 /= 2;
        }
        return (uint32_t)(t2);
    }
};
