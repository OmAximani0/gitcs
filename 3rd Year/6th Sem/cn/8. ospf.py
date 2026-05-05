from tabulate import tabulate

from collections import defaultdict
from heapq import heappop, heappush


class OSPFRouter:
    def __init__(self):
        self.graph = defaultdict(list)

    def add_link(self, a, b, cost):
        self.graph[a].append((b, cost))
        self.graph[b].append((a, cost))

    def shortest_path(self, source):
        table_data = []
        queue = [(0, source, 0)]
        shortest_path = {node: (float('inf'), 0) for node in self.graph}
        shortest_path[source] = (0, 0)

        while queue:
            cost, node, hops = heappop(queue)
            for nei, neicost in self.graph[node]:
                newcost = cost + neicost
                newhops = hops + 1

                if newcost < shortest_path[nei][0]:
                    shortest_path[nei] = (newcost, newhops)
                    heappush(queue, (newcost, nei, newhops))
        for dest, (cost, hops) in shortest_path.items():
            table_data.append([source, hops, dest, cost])

        return tabulate(
            table_data,
            headers=["Source", "Hops", "Destination", "Cost"],
            tablefmt="grid"
        )


if __name__ == "__main__":
    ospf = OSPFRouter()
    ospf.add_link("A", "B", 4)
    ospf.add_link("A", "C", 5)
    ospf.add_link("B", "C", 11)
    ospf.add_link("B", "D", 9)
    ospf.add_link("B", "E", 7)
    ospf.add_link("C", "E", 3)
    ospf.add_link("D", "E", 13)
    ospf.add_link("D", "F", 2)
    ospf.add_link("E", "F", 6)

    source_router = input("Enter the Source Node : ")
    print(ospf.shortest_path(source_router.upper()))
