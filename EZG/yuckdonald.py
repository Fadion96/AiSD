cost_tab = [5, 10, 5, 10, 5, 10, 1000000, 10, 5, 10]
r_tab = [-1] * len(cost_tab)


def dist(a, b, c):
    if b - a < c:
        return 0
    else:
        return 1


def get_cost(i, min_dist):
    tmp = [r_tab[x] + dist(x, i, min_dist) * cost_tab[i] for x in range(0, i)]
    tmp.append(cost_tab[i])
    r_tab[i] = max(tmp)


for r in range(len(cost_tab)):
    get_cost(r, 2)

print(r_tab)
