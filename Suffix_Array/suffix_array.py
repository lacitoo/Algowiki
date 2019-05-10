import math


def build_suffix_array(s: str):
    n = len(s)

    # tombok feltoltese
    suffix_array = [-1] * n
    rank = [-1] * 2 * n
    new_rank = [-1] * len(rank)

    # kezdetleges ertekek adasa, amikor csak 1 hosszuakat nezunk
    for i in range(0, n):
        suffix_array[i] = i

        # karakter kodja a kezdetleges rang
        rank[i] = ord(s[i])

    for step in range(0, int(math.ceil(math.log2(n)))):
        # tomb rendezese parok szerint
        suffix_array.sort(key=lambda a: (rank[a], rank[a + 2 ** step]))

        # rangok megadasa
        rankAt = 0
        new_rank[suffix_array[0]] = 0

        # ha egy uj fajta szuffixet talalunk akkor eggyel magasabb rangot adunk neki
        for i in range(1, n):
            a = suffix_array[i - 1]
            b = suffix_array[i]

            if (rank[a], rank[a + 2 ** step]) < (rank[b], rank[b + 2 ** step]):
                rankAt += 1

            new_rank[b] = rankAt

        rank = new_rank

    return suffix_array


st = "abbacd"
sa = build_suffix_array(st)
print(sa)
print(list(map(lambda s: st[s:], sa)))
