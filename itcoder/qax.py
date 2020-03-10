class Solution:
    def main(self):
        print("ok")


if __name__ == "__main__":
    while(1):
        m = int(input().strip())
        n = int(input().strip())
        prices = list(map(int, input().strip().split()))
        M = int(input().strip())


        print(m)
        print(n)
        print(prices)
        print(M)
        f = Solution()
        print(f.main())