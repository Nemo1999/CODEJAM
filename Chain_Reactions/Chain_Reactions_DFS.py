from collections import defaultdict

def findMaxFuns(parent, childrens, Fs, r):
    if len(childrens[r]) == 0:
        return Fs[r-1]
    subProbs = list(findMaxFuns(parent, childrens, Fs , ch) for ch in childrens[r])
    return sum(subProbs) - min(subProbs) + max(Fs[r-1], min(subProbs))

def solve(N, Fs, Ps):
    childrens = defaultdict(set)
    parent = defaultdict(lambda x: 0)
    for i, p in enumerate(Ps):
        childrens[p].add(i+1)
        parent[i+1] = p
    roots = list(filter(lambda n: parent[n] == 0, range(1, N+1)))
    maxFuns = list(map(lambda r: findMaxFuns(parent, childrens, Fs, r), roots))
    return sum(maxFuns)

if __name__ == "__main__":
    T = int(input())
    for t in range(T):
        N = int(input())
        Fs = list(map(int, input().split(" ")))
        Ps = list(map(int, input().split(" ")))
        maxFun = solve(N, Fs, Ps)
        print(f"Case #{t+1}: {maxFun}")
