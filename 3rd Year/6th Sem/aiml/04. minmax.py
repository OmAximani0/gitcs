def minimax(values, depth, index, is_max, height):

    # If we reached leaf node
    if depth == height:
        print("Leaf node reached with value:", values[index])
        return values[index]

    if is_max:
        print("\nMAX level at depth", depth)

        left = minimax(values, depth + 1, index * 2, False, height)
        right = minimax(values, depth + 1, index * 2 + 1, False, height)

        result = max(left, right)
        print("MAX chooses max(", left, ",", right, ") =", result)
        return result

    else:
        print("\nMIN level at depth", depth)

        left = minimax(values, depth + 1, index * 2, True, height)
        right = minimax(values, depth + 1, index * 2 + 1, True, height)

        result = min(left, right)
        print("MIN chooses min(", left, ",", right, ") =", result)
        return result


# Driver code
values = [10, 9, 14, 18, 5, 4, 50, 3]

import math

height = int(math.log2(len(values)))

result = minimax(values, 0, 0, True, height)

print("\nFinal Optimal Value:", result)
