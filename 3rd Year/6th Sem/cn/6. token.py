import time


class TokenBucket:
    def __init__(self, cap, rate):
        self.cap = cap
        self.rate = rate
        self.tokens = 0
        self.last_time = time.time()

    def add_token(self):
        curr = time.time()
        time_elapsed = curr - self.last_time
        self.tokens = min(self.cap, self.tokens + time_elapsed * self.rate)
        self.last_time = curr

    def transmit(self, packet_size):
        if self.tokens >= packet_size:
            self.tokens -= packet_size
            print(f"Transmitted {packet_size} bytes")
            return True
        else:
            print("Dropped - insufficient tokens")
            return False


if __name__ == "__main__":
    buc = TokenBucket(50, 10)
    for i in range(1, 11):
        print(f"Time: {i} seconds")
        buc.add_token()
        packet_size = int(input("Enter the packet size: "))
        buc.transmit(packet_size)
