def solve(id):
    n = int(input())
    nums = (input()).split()
    # print(nums)
    tot_append = 0

    for i in range(1,n):
        curr, prev = int(nums[i]), int(nums[i-1])
        if curr > prev:
            continue
        elif curr == prev:
            nums[i] += '0'
            tot_append += 1
        else:
            curr_ndigits, prev_ndigits = len(nums[i]), len(nums[i-1])
            diff = prev_ndigits - curr_ndigits

            for j in range(curr_ndigits):
                if nums[i][j] > nums[i-1][j]:
                    nums[i] += '0' * diff
                    tot_append += diff
                    break
                elif nums[i][j] < nums[i-1][j]:
                    nums[i] += '0' * (diff + 1)
                    tot_append += diff + 1
                    break

            curr, prev = int(nums[i]), int(nums[i-1])
            if curr > prev:
                continue

            j = prev_ndigits - 1
            while j >= curr_ndigits:
                if nums[i-1][j] < '9':
                    nums[i] += nums[i-1][curr_ndigits:j]
                    nums[i] += str(int(nums[i-1][j]) + 1)
                    nums[i] += '0' * (prev_ndigits-j-1)
                    tot_append += len(nums[i]) - curr_ndigits
                    break
                j -= 1

            curr, prev = int(nums[i]), int(nums[i-1])
            if curr > prev:
                continue

            nums[i] += '0' * (diff + 1)
            tot_append += diff + 1

    # print(nums)
    print(f"Case #{id}: {tot_append}")



if __name__ == "__main__":
    t = int(input())
    for id in range(t):
        solve(id+1)
