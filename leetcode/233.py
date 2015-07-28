def countDigitOne(n):
    if n <= 0:
        return 0
    ans = 0
    a, b = 1, 0
    while n:
        print n
        if n % 10 == 0:
            ans += n / 10 * a
        elif n % 10 == 1:
            print a, b
            ans += n / 10 * a + b + 1
        else:
            ans += (n / 10 + 1) * a
        b = n % 10 * a + b
        a = a * 10
        n /= 10
        print ans
    return ans

if __name__ == '__main__':
    countDigitOne(13)
