# question link : https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a45ef7


from typing import Dict, Tuple, Optional , Tuple, Set
from collections import defaultdict

Module = int
CurFun = int
Initiator = Module

class Solver: 
    def __init__(self, N, Fs, Ps) -> None:
        self.N = N
        self.nodes: Set[Module]= set(range(1,N+1))
        
        self.fun: Dict[Module,int] = dict()
        for n in self.nodes:
            self.fun[n] = Fs[n-1]
        
        self.arrow: Dict[Module, Optional[Module]] = dict() # the value is None if key is pointing to abyss
        self.back_arrow: Dict[Module, Set[Module]] = defaultdict(set) # track the nodes that are pointing to the key
        for n in self.nodes:
            if Ps[n-1] == 0: 
                self.arrow[n] = None
            else:
                self.arrow[n] = Ps[n-1]
                self.back_arrow[Ps[n-1]].add(n)

        self.initiators = set(n for n in self.nodes if len(self.back_arrow[n]) == 0)

        # map each initiator to its last affecting node and its max fun achieved  
        # if the module has gone to the end or abyss or blocked by another initiator, 
        # LastNode is set to None , CurFun indicate the maxFun achived by current node position.
        self.state: Dict[Module, Tuple[Optional[Module], CurFun]] = dict()
        for i in self.initiators:
            self.state[i] = (i, Fs[i-1])
    
    def removeAllCycles(self):
        """no need to remove cycle because Each module may point at one other module with a lower index. """
        return 

    def pushNode(self, initiator: Module):
        """push the current node of an initiator to its limit (until blocked by crossing path)"""
        lastNodes = set(n for n, _ in self.state.values() if n != None) 

        currNode, currFun = self.state[initiator]
        if currNode == None:
            return 
        while True:
            nextNode = self.arrow[currNode]
            if nextNode == None:
                currNode = None
                break
            # check how many nodes are waiting for nextNodes
            waitingNodes = self.back_arrow[nextNode] & (lastNodes | set([currNode]))
            if len(waitingNodes) < len(self.back_arrow[nextNode]):
                break
            # all candidates for nextNodes are already waiting
            else:
                # current node is blocked by other node
                if currFun > min(f for n , f in self.state.values() if n in self.back_arrow[nextNode]):
                    break
                # current blocks all other nodes
                else:
                    # block all other waiting nodes
                    for i in self.initiators:
                        n ,f = self.state[i]
                        if n in waitingNodes and n != initiator:
                            self.state[i] = (None, f)
                    # update current node and current function
                    currNode = nextNode
                    currFun = max(currFun, self.fun[nextNode])
        self.state[initiator] = (currNode, currFun)

    def solve(self)-> int:
        activeSet = self.initiators.copy()
        while len(activeSet) > 0:
            #print(self.state)
            for a in activeSet:
                self.pushNode(a)
            activeSet = set(a for a in activeSet if self.state[a][0] != None)
        return sum(f for _, f in self.state.values())        

if __name__ == "__main__":
    T = int(input())
    for t in range(T):
        N = int(input()) # number of modules
        Fs = list(map(int, input().split(" "))) # fun factors
        Ps = list(map(int, input().split(" "))) # next nodes, 0 means pointing at abyss
        ans = Solver(N, Fs, Ps).solve()
        print(f"Case #{t+1}: {ans}") 
