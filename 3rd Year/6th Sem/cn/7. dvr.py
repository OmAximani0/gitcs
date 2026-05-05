import sys
from collections import defaultdict


class Network:
    def __init__(self, nodes):
        self.nodes = nodes
        self.graph = defaultdict(dict)
        self.dv = defaultdict(dict)

    def add_link(self, n1, n2, cost):
        self.graph[n1][n2] = cost
        self.graph[n2][n1] = cost

    def init_dv(self, node):
        self.dv[node] = {node: 0}
        for n in self.nodes:
            if n != node:
                self.dv[node][n] = sys.maxsize

    def update_dv(self, node):
        for dest in self.nodes:
            if dest != node:
                min_cost = sys.maxsize
                for nei in self.graph[node]:
                    if dest in self.dv[nei]:
                        cost = self.dv[nei][dest] + self.graph[node][nei]
                        if cost < min_cost:
                            min_cost = cost
                self.dv[node][dest] = min_cost

    def print_tables(self, node):
        print(f"Routing table for node: {node}")
        print("Destination\tCost")
        for dest, cost in self.dv[node].items():
            if dest != node:
                print(f"{dest}\t\t{cost}")
        print()


if __name__ == "__main__":
    nodes = [1, 2, 3, 4, 5]
    network = Network(nodes)
    network.add_link(1, 2, 2)
    network.add_link(1, 3, 2)
    network.add_link(1, 4, 1)
    network.add_link(2, 3, 3)
    network.add_link(2, 1, 2)
    network.add_link(2, 5, 1)
    network.add_link(3, 1, 2)
    network.add_link(3, 4, 4)
    network.add_link(3, 2, 3)
    network.add_link(3, 5, 1)
    network.add_link(4, 1, 1)
    network.add_link(4, 3, 4)
    network.add_link(5, 2, 1)
    network.add_link(5, 3, 1)
    for node in nodes:
        network.init_dv(node)
    num_iterations = 6  # Number of iterations to update the distance vectors
    for _ in range(num_iterations):
        for node in nodes:
            network.update_dv(node)
    for node in nodes:
        network.print_tables(node)
