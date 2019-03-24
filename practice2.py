def prefix(s):
    """This function is used by the kmp algorithm to determine the prefix."""
    v = [0] * len(s)
    for i in range(1, len(s)):
        k = v[i - 1]
        while k > 0 and s[k] != s[i]:
            k = v[k - 1]
        if s[k] == s[i]:
            k = k + 1
        v[i] = k
    return v


def kmp(s, t, same_case=False, complexity=False):
    """This function is the Knuth, Morris, Pratt algorithm."""
    count = 0
    if same_case:
        t = t.lower()
        s = s.lower()

    index = None
    f = prefix(s)
    k = 0
    for i in range(len(t)):
        while k > 0 and s[k] != t[i]:
            k = f[k - 1]
            if complexity:
                count += 1

        if s[k] == t[i]:
            k = k + 1
        if k == len(s):
            index = i - len(s) + 1
            break

        if complexity:
            count += 1

    if complexity:
        print('kmp  complexity result:', count, end='\t')
    return index


def bm_pre_find(string):
    """This function is used by the bm algorithm to indexing search string."""
    d = {}

    index = 1
    for char in string[len(string) - 2::-1]:
        if char not in d:
            d[char] = index
        index += 1

    if string[len(string) - 1] not in d:
        d[string[len(string) - 1]] = len(string)
    return d


def bm(s, t, same_case=False, complexity=False):
    """This function is the Boyer Moore algorithm."""
    count = 1
    if same_case:
        s = s.lower()
        t = t.lower()
    d = bm_pre_find(s)
    len_x = i = j = k = len(s)
    while j > 0 and i <= len(t):

        if complexity:
            count += 1

        if t[k - 1] == s[j - 1]:
            k -= 1
            j -= 1
        else:
            if t[i - 1] in d:
                i += d[t[i - 1]]
            else:
                i += len(s) if len(s) + i < len(t) else len(t) - i - 1
            j = len_x
            k = i

    if complexity:
        print('bm   complexity result:', count, end='\t')

    if j <= 0:
        return k
    return None


def full_find(s, t, same_case=False, complexity=False):
    """Full find. All chars will be compare."""
    count = 0
    if same_case:
        s = s.lower()
        t = t.lower()
    for i in range(len(t)):
        j = 0
        while (j < len(s)) and (s[j] == t[i + j]):
            j += 1

            if complexity:
                count += 1

        if complexity:
            count += 1

        if j == len(s):
            if complexity:
                print('full complexity result:', count, end='\t')
            return i
    if complexity:
        print('full complexity result:', count, end='\t')
    return None


def test_with_complexity():
    """Test with complexity showing."""
    print('answer: ', bm('данные', 'пользовательские Данные', same_case=True,
                         complexity=True))
    print('answer: ', kmp('данные', 'пользовательские Данные', same_case=True,
                          complexity=True))
    print('answer: ', full_find('данные', 'пользовательские Данные',
                                same_case=True, complexity=True))


def practical_use():
    text = \
        'In literary theory, a text is any object that can be "read", whet' + \
        'her this object is a work of literature, a street sign, an arrang' + \
        'ement of buildings on a city block, or styles of clothing. It is ' + \
        'a coherent set of signs that transmits some kind of informative m' + \
        'essage.[1] This set of symbols is considered in terms of the info' + \
        'rmative' + " message's content, rather than in terms of its physi" + \
        'cal form or the medium in which it is represented. Within the fie' + \
        'ld of literary criticism, "text" also refers to the original info' + \
        'rmation content of a particular piece of writing; that is, the "t' + \
        'ext" of a work is that primal symbolic arrangement of letters as ' + \
        'originally composed, apart from later alterations, deterioration,' + \
        'commentary, translations, paratext, etc. Therefore, when literary' + \
        'criticism is concerned with the determination of a "text", it is ' + \
        'concerned with the distinguishing of the original information con' + \
        'tent from whatever has been added to or subtracted from that cont' + \
        'ent as it appears in a given textual document (that is, a physica' + \
        'l representation of text).'

    count = 0
    word = input()
    while kmp(word, text, same_case=True) is not None:
        text = text.replace(word, ' ', 1)
        count += 1

    print(count)


test_with_complexity()

practical_use()
