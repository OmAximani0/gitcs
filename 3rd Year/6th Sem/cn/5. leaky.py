import time


class LeakyBucket:
    def __init__(self, cap, rate):
        self.cap = cap
        self.rate = rate
        self.bucket = 0

    def add_packet(self, packets):
        space = self.cap - self.bucket
        if packets <= space:
            self.bucket += packets
            print(f"{packets} packet(s) added to bucket")
        else:
            self.bucket += space
            dropped = packets - space
            print(f"{space} packet(s) added, {dropped} packet(s) overflow")

    def leak(self):
        leaked = min(self.bucket, self.rate)
        self.bucket -= leaked
        print(f"{leaked} packet(s) transmitted")

    def status(self):
        print(f"Packets currently in bucket: {self.bucket}")


if __name__ == "__main__":
    cap = int(input("Enter bucket capacity: "))
    rate = int(input("Enter leak rate (packet/sec): "))
    bucket = LeakyBucket(cap, rate)

    for i in range(5):
        print(f"\nTime {i+1}")
        packets = int(input("Enter the number of incoming packets: "))
        bucket.add_packet(packets)
        bucket.leak()
        bucket.status()
        time.sleep(1)
