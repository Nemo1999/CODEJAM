import sys
from collections import defaultdict

sys.setrecursionlimit(100000)

def findMaxFuns(parent, childrens, Fs, r):
    if len(childrens[r]) == 0:
        return Fs[r-1], Fs[r-1]
    subProbs = list(findMaxFuns(parent, childrens, Fs , ch) for ch in childrens[r])
    maxFunChildBranches, maxFunSubTrees = zip(*subProbs)
    maxFunCurrentBranch = max(min(maxFunChildBranches), Fs[r-1])
    maxFunRoot = sum(maxFunSubTrees) - min(maxFunChildBranches) + maxFunCurrentBranch
    return maxFunCurrentBranch,  maxFunRoot


def solve(N, Fs, Ps):
    childrens = defaultdict(set)
    parent = defaultdict(lambda x: 0)
    for i, p in enumerate(Ps):
        childrens[p].add(i+1)
        parent[i+1] = p
    roots = list(filter(lambda n: parent[n] == 0, range(1, N+1)))
    maxFuns = list(map(lambda r: findMaxFuns(parent, childrens, Fs, r), roots))
    _, maxFunRoots = zip(*maxFuns)
    return sum(maxFunRoots)

if __name__ == "__main__":
    T = int(input())
    for t in range(T):
        N = int(input())
        Fs = list(map(int, input().split(" ")))
        Ps = list(map(int, input().split(" ")))
        maxFun = solve(N, Fs, Ps)
        print(f"Case #{t+1}: {maxFun}")
