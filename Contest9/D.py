import sys

def build_table(tree, node, start, end) :
    if start == end - 1 :
        tree[node] = start
        return

        mid = start + (end - start) // 2
        build_table(tree, node * 2, start, mid)
        build_table(tree, node * 2 + 1, mid, end)
        tree[node] = min(tree[node * 2], tree[node * 2 + 1])


        def find_maximum(values, indices, updates, start, end, size) :
        nodes_to_process = [(1, 1, size + 1)]
        max_index = -1
        highest_value = -1e9

        while nodes_to_process :
            current_node, node_left, node_right = nodes_to_process.pop()
            propagate(updates, values, current_node, node_left, node_right)

            if node_left >= end or node_right <= start :
                continue
                elif node_left >= start and node_right <= end :
                if values[current_node] > highest_value:
highest_value = values[current_node]
max_index = indices[current_node]
                else :
                    mid = (node_left + node_right) // 2
                    nodes_to_process.append((2 * current_node, node_left, mid))
                    nodes_to_process.append((2 * current_node + 1, mid, node_right))

                    return highest_value, max_index


                    def propagate(updates, values, idx, left, right) :
                    if updates[idx] :
                        values[idx] += updates[idx]
                        if left < right - 1 :
                            updates[2 * idx] += updates[idx]
                            updates[2 * idx + 1] += updates[idx]
                            updates[idx] = 0

                            def update(values, indices, updates, start, end, increment, lbound, ubound, node = 1) :
                            propagate(updates, values, node, lbound, ubound)

                            if lbound >= end or ubound <= start :
                                return
                                if start <= lbound < ubound <= end :
                                    updates[node] += increment
                                    propagate(updates, values, node, lbound, ubound)
                                    return

                                    mid = (lbound + ubound) // 2
                                    update(values, indices, updates, start, end, increment, lbound, mid, node * 2)
                                    update(values, indices, updates, start, end, increment, mid, ubound, node * 2 + 1)

                                    if values[node * 2] > values[node * 2 + 1]:
values[node] = values[node * 2]
indices[node] = indices[node * 2]
                                    else:
values[node] = values[node * 2 + 1]
indices[node] = indices[node * 2 + 1]


def coordinate_compress(unique_coords) :
    sorted_values = sorted(unique_coords)
    index_map = { val: idx + 1 for idx, val in enumerate(sorted_values) }
    return sorted_values, index_map, len(sorted_values)


    def process_input(num_moves) :
    moves = []
    coordinate_set = set()

    for _ in range(num_moves) :
        coords = sys.stdin.readline().rstrip()
        x1, y1, x2, y2 = map(lambda x : int(x) + 1, coords.split())
        coordinate_set.update([y1, y2])
        moves.extend([(x1, y1, y2, 1), (x2, y1, y2, -1)])

        moves.sort(key = lambda m : (m[0], -m[3]))
        return moves, * coordinate_compress(coordinate_set)

        def max_coverage(num_intervals) :
        event_list, val_mapping, rev_mapping, coord_count = process_input(num_intervals)
        lazy_updates = [0] * (4 * coord_count)
        segment_max = [0] * (4 * coord_count)
        key_indices = initialize_tree(coord_count)

        result = [0, 0, 0]
        for x, y_start, y_end, effect in event_list :
mapped_start = rev_mapping[y_start]
mapped_end = rev_mapping[y_end]
update(segment_max, key_indices, lazy_updates, mapped_start, mapped_end + 1, effect, 1, coord_count + 1)

cur_max, max_y = find_maximum(segment_max, key_indices, lazy_updates, 1, coord_count + 1, coord_count)
if cur_max > result[0]:
result = [cur_max, x - 1, val_mapping[max_y] - 1]

return result


def initialize_tree(size) :
    tracking_tree = [0] * (4 * size)
    build_table(tracking_tree, 1, 0, size)
    return tracking_tree


    number_of_intervals = int(input().strip())

    max_result = max_coverage(number_of_intervals)

    print(max_result[0])
    print(f'{max_result[1]} {max_result[2]}')