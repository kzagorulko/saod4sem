def merge_sort(a, lb=0, ub=-1):
    def merge(a, lb, split, ub):
        pos1 = lb

        pos2 = split + 1

        pos3 = 0

        temp = [i for i in range(ub - lb + 1)]

        while pos1 <= split and pos2 <= ub:
            if a[pos1] < a[pos2]:
                temp[pos3] = a[pos1]
                pos1 += 1
                pos3 += 1
            else:
                temp[pos3] = a[pos2]
                pos2 += 1
                pos3 += 1

        while pos2 <= ub:
            temp[pos3] = a[pos2]
            pos3 += 1
            pos2 += 1
        while pos1 <= split:
            temp[pos3] = a[pos1]
            pos3 += 1
            pos1 += 1

        # скопировать буфер temp в a[lb]...a[ub]
        a[lb:ub + 1] = temp

        del temp

    if lb < ub:  # если есть более 1 элемента
        split_tmp = (lb + ub) / 2  # индекс, по которому делим массив
        merge_sort(a, lb, split_tmp)  # сортировать левую половину
        merge_sort(a, split_tmp + 1, ub)  ##сортировать правую половину
        merge(a, lb, split_tmp, ub)  # слить результаты в общий массив
