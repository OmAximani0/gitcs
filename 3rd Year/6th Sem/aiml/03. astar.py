from queue import PriorityQueue

def a_star(graph, heuristics, start, goal):
    open_list = PriorityQueue()
    open_list.put((0, start))
    
    g_cost = {start: 0}
    parent = {start: None}

    step = 0

    while not open_list.empty():
        step += 1
        print(f"\n--- Step {step} ---")

        current_priority, current = open_list.get()
        print(f"Current node: {current} (f = {current_priority})")

        if current == goal:
            print("Goal reached!")
            break

        print("Exploring neighbors:")
        for neighbor, cost in graph[current]:
            new_cost = g_cost[current] + cost
            print(f"  Checking neighbor {neighbor}")
            print(f"    Cost from {current} to {neighbor}: {cost}")
            print(f"    New g_cost: {new_cost}")

            if neighbor not in g_cost or new_cost < g_cost[neighbor]:
                g_cost[neighbor] = new_cost
                f_cost = new_cost + heuristics[neighbor]

                open_list.put((f_cost, neighbor))
                parent[neighbor] = current

                print(f"    Updated!")
                print(f"    g_cost[{neighbor}] = {new_cost}")
                print(f"    h_cost[{neighbor}] = {heuristics[neighbor]}")
                print(f"    f_cost[{neighbor}] = {f_cost}")
            else:
                print(f"    Not updated (better path already exists)")

    # Reconstruct path
    path = []
    node = goal
    print("\nReconstructing path:")
    while node:
        print(f"  {node} <- {parent[node]}")
        path.append(node)
        node = parent[node]

    path.reverse()
    return path, g_cost[goal]


# Graph representation
graph = {
    'A': [('B', 1), ('C', 3)],
    'B': [('D', 3), ('E', 1)],
    'C': [('F', 5)],
    'D': [('G', 2)],
    'E': [('G', 4)],
    'F': [('G', 2)],
    'G': []
}

# Heuristic values
heuristics = {
    'A': 6,
    'B': 4,
    'C': 4,
    'D': 2,
    'E': 2,
    'F': 1,
    'G': 0
}

start = 'A'
goal = 'G'
path, cost = a_star(graph, heuristics, start, goal)
print("\nFinal Result:")
print("Shortest Path:", path)
print("Total Cost:", cost)