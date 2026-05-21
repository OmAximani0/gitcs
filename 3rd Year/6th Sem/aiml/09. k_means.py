import numpy as np

# Data points
points = {
    "A1": (2, 10),
    "A2": (2, 5),
    "A3": (8, 4),
    "B1": (5, 8),
    "B2": (7, 5),
    "B3": (6, 4),
    "C1": (1, 2),
    "C2": (4, 9),
}

labels = list(points.keys())
data = np.array(list(points.values()))

# Initial centroids: A1, B1, C1
centroids = np.array([points["A1"], points["B1"], points["C1"]], dtype=float)

k = 3
iteration = 1

while True:
    print("\nIteration", iteration)
    clusters = [[] for _ in range(k)]

    # Assign each point to nearest centroid
    for i, point in enumerate(data):
        distances = np.linalg.norm(point - centroids, axis=1)
        cluster_index = np.argmin(distances)
        clusters[cluster_index].append(i)

        print(
            labels[i],
            "->",
            np.round(distances, 2),
            "Assigned to Cluster",
            cluster_index + 1,
        )

    # Compute new centroids
    new_centroids = np.array([np.mean(data[cluster], axis=0) for cluster in clusters])

    print("\nUpdated Centroids:")
    for i in range(k):
        print("C{} = {}".format(i + 1, np.round(new_centroids[i], 2)))

    if np.allclose(centroids, new_centroids):
        break

    centroids = new_centroids
    iteration += 1

# Final clusters
print("\nFinal Clusters:")
for i in range(k):
    cluster_points = [labels[j] for j in clusters[i]]
    print("Cluster", i + 1, ":", cluster_points)
