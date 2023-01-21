import sys
from collections import defaultdict

def findMaxFunsNoRecursion(parent, childrens, Fs, r):
    DP = dict()
    dfs_stack = [r]
    while len(dfs_stack) > 0:
        node = dfs_stack.pop()
        if len(childrens[node]) == 0:
            DP[node] = (Fs[node-1], Fs[node-1])
        elif all(c in DP for c in childrens[node]):
            maxFunChildBranches, maxFunChildTrees = zip(*(DP[c] for c in childrens[node]))
            priorityBranch = min(maxFunChildBranches)
            maxFunCurrentBranch = max(Fs[node-1], priorityBranch)
            maxFunCurrentTree = sum(maxFunChildTrees) - priorityBranch + maxFunCurrentBranch
            DP[node] = (maxFunCurrentBranch, maxFunCurrentTree)
        else:
            dfs_stack.append(node)
            dfs_stack += list(childrens[node])
    return DP[r]

def solve(N, Fs, Ps):
    childrens = defaultdict(set)
    parent = defaultdict(lambda x: 0)
    for i, p in enumerate(Ps):
        childrens[p].add(i+1)
        parent[i+1] = p
    roots = list(filter(lambda n: parent[n] == 0, range(1, N+1)))
    maxFuns = list(map(lambda r: findMaxFunsNoRecursion(parent, childrens, Fs, r), roots))
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
