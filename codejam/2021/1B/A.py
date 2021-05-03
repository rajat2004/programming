from itertools import permutations

TICK_TO_DEG = 1/12 * 1e-10
TOTAL_TICKS = 360 * 12 * 1e10
DEG_TO_TICK = 12 * 1e10

def check(ht, mt, st, pid):
    """
        x -> nanosecs (in ticks)
        shift -> axis in ticks

        x + shift -> hrs_ticks
        12*x + shift % M -> mins_ticks
        720*x + shift % M -> secs_ticks

        mins-hrs + y*M (y=0 to 11) => 11*x
        Get x, shift and verify secs_ticks
    """

    ns_ticks = 0
    shift = 0

    diff = (mt - ht + TOTAL_TICKS) % TOTAL_TICKS
    for rep in range(12):
        tmp = diff + rep * TOTAL_TICKS
        if tmp % 11 == 0:
            ns_ticks = tmp / 11
            shift = (ht - ns_ticks + TOTAL_TICKS) % TOTAL_TICKS

            if (ns_ticks + shift) % TOTAL_TICKS != ht:
                continue

            if (12*ns_ticks + shift) % TOTAL_TICKS != mt:
                continue

            if (720*ns_ticks + shift) % TOTAL_TICKS != st:
                continue

            # calc_st = (720*ns_ticks + shift) % TOTAL_TICKS
            # if calc_st == st:
            ns = ns_ticks % 1e9
            ns_ticks /= 1e9

            secs = ns_ticks % 60
            ns_ticks /= 60

            mins = ns_ticks % 60
            ns_ticks /= 60

            hrs = ns_ticks

            if hrs < 12:
                print(f"Case #{pid}: {int(hrs)} {int(mins)} {int(secs)} {int(ns)}")
                return True

    return False

def solve(pid):
    arr = [int(x) for x in input().split()]
    perm = permutations(arr)

    for p in perm:
        if check(p[0], p[1], p[2], pid):
            break


if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        solve(i+1)
