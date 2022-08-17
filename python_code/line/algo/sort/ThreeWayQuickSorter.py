def sort(data):
    if data is None or len(data) <= 1:
        return
    sortR(data, 0, len(data) - 1)


def sortR(data, lo, hi):
    if lo >= hi:
        return

    pivot = data[hi]
    less, great = lo, hi

    i = lo
    while i <= great:
        if data[i] < pivot:
            data[i], data[less] = data[less], data[i]
            less, i = less + 1, i + 1
        elif data[i] > pivot:
            data[i], data[great] = data[great], data[i]
            great -= 1
        else:
            i += 1

    sortR(data, lo, less - 1)
    sortR(data, great + 1, hi)


if __name__ == '__main__':
    data = [34, 33, 12, 78, 21, 1, 98, 100]
    sort(data)
    print(data)
