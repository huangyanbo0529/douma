

def minCost(nums, costs):
    # 三个数相等的情况
    if nums[0] == nums[1] == nums[2]:
        if nums[0] <= 2:
            return -1
        return min(costs[1] * 2 + costs[0], costs[1] * 2 + costs[1])

    # 三个数升序的情况 (即第二大的数不是 A 和 C，而是 B)
    if nums[0] < nums[1] < nums[2]:
        if nums[0] == 1 and nums[1] == 2:
            return -1
        # 比如 [2,3,4] -> [2,1,4] 或者 [2,3,1]，然后取最小值
        # 也就是要么将第 2 个数字减去 2，或者将第 3 个数字减去 3（这里不能减 2，减 2 的话，会导致和第 1 个数相同）
        gap1, gap2 = nums[1] - nums[0], nums[2] - nums[1]
        cost1 = costs[1] * (gap1 + 1)
        # 这里相等的话，需要再减掉 1
        if nums[2] - (gap2 + 1) == nums[0]:
            cost2 = costs[2] * (gap2 + 2)
        else:
            cost2 = costs[2] * (gap2 + 1)
        return min(cost1, cost2)

    # 三个数降序的情况 (即第二大的数不是 A 和 C，而是 B)
    # 和上面的升序处理逻辑刚好相反
    if nums[0] > nums[1] > nums[2]:
        if nums[2] == 1 and nums[1] == 2:
            return -1
        gap1, gap2 = nums[0] - nums[1], nums[1] - nums[2]
        cost1 = costs[1] * (gap2 + 1)
        if nums[0] - (gap1 + 1) == nums[2]:
            cost2 = costs[0] * (gap1 + 2)
        else:
            cost2 = costs[0] * (gap2 + 1)
        return min(cost1, cost2)

    def minCostSameNum(i, j):
        if nums[i] == 1:
            return -1

        nums_c = nums[:]
        nums_c[i] -= 1
        left_cost = minCost(nums_c, costs)
        if left_cost != -1:
            left_cost += costs[i]

        nums_c = nums[:]
        nums_c[j] -= 1
        right_cost = minCost(nums_c, costs)
        if right_cost != -1:
            right_cost += costs[j]

        if left_cost == right_cost == -1:
            return -1

        if left_cost == -1:
            return right_cost
        elif right_cost == -1:
            return left_cost
        else:
            return min(left_cost, right_cost)

    # 以下考虑的是两个数相等的情况
    # 这种情况可以把问题抽象成树形结构，然后使用 DFS 最最小路径即可
    # minCostSameNum 函数的逻辑，可以参考代码下面的图
    if nums[0] == nums[1]:
        return minCostSameNum(0, 1)

    if nums[0] == nums[2]:
        return minCostSameNum(0, 2)

    if nums[1] == nums[2]:
        return minCostSameNum(1, 2)

    return 0


print(minCost([1, 3, 2], [2, 6, 3]))
