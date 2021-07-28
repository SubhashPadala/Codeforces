p, k = map(int, input().split())
ans = list()
while(p!=0):
    ans.append((p%k+k)%k)
    p = (p-ans[-1])//(-k)
print(len(ans))
print(*ans)
