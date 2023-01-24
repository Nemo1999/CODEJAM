class Explorer:
    def __init__(N:int, K:int):
        # N = number of rooms in the cave
        # K = number of room operations allowed
        self.N = N
        self.K = K

    def estimate():
        pass

    def observe_and_act(R: int, P: int)-> Tuple(str, int):
        # R = Number of Room that you are currently in
        # P = the passages connected to current room
        pass

if __name__ == "__main__":
    T = int(input())
    for t in range(T):
        N, K = map(int,input().split(" "))
        e = Explorer(N, K)
        for k in range(K+1):
            in_str = input()
            if in_str == "-1":
                exit(0)
            else:
                R, P = map(int, in_str.split(" "))
            action = e.observe_and_act(R, P)
            if k == K:
                print(f"E {e.estimate()}", flush=True)
            elif action[0] == "W":
                print("W", flush=True)
            elif action[0] == "T":
                print(f"T {action[1]}", flush=True)
            else:
                raise ValueError("In valid action return from Explorer")
    exit(0)
