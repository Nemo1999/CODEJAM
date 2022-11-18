# question link : https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a45ef7


from typing import Dict, Tuple, Optional , Tuple, Set
from collections import defaultdict

Module = int
CurFun = int
Initiator = Module

class Solver: 
    def __init__(self, N, Fs, Ps) -> None:
        self.N = N
        self.Fs = Fs
        self.Ps = Ps
        self.initiators = set(range(N)) - set(Ps)

        # if the module has gone to the end or abyss or blocked by another initiator, 
        # LastNode is set to None , CurFun indicate the maxFun achived by current node position.
        self.currentState: Dict[Module, Tuple[Optional[Module], CurFun]] = dict()
        for i in self.initiators:
            self.currentState[i] = (i, Fs[i])

        self.waitingStates : Dict[Module, Set[Initiator]] = defaultdict(set)
        
        
    def solve(self)-> int:
        



if __name__ == "__main__":
    T = int(input())
    for t in T:
        N = int(input()) # number of modules
        Fs = map(int, input().split(" ")) # fun factors
        Ps = map(int, input().split(" ")) # next nodes, 0 means pointing at abyss
        ans = Solver(N, Fs, Ps).solve()
        print(f"Case #{t+1}: {ans}") 
