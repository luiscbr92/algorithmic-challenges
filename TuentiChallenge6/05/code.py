import socket, select, string, sys, operator

dictionary = []
letters = {}
vocals = ['A','E','I','O','U']
free_letters = {}
something_correct = False

def new_level():
    free_letters['A'] = True
    free_letters['B'] = True
    free_letters['C'] = True
    free_letters['D'] = True
    free_letters['E'] = True
    free_letters['F'] = True
    free_letters['G'] = True
    free_letters['H'] = True
    free_letters['I'] = True
    free_letters['J'] = True
    free_letters['K'] = True
    free_letters['L'] = True
    free_letters['M'] = True
    free_letters['N'] = True
    free_letters['O'] = True
    free_letters['P'] = True
    free_letters['Q'] = True
    free_letters['R'] = True
    free_letters['S'] = True
    free_letters['T'] = True
    free_letters['U'] = True
    free_letters['V'] = True
    free_letters['W'] = True
    free_letters['X'] = True
    free_letters['Y'] = True
    free_letters['Z'] = True
    free_letters['-'] = True
    something_correct = False

def new_round():
    letters['A'] = 0
    letters['B'] = 0
    letters['C'] = 0
    letters['D'] = 0
    letters['E'] = 0
    letters['F'] = 0
    letters['G'] = 0
    letters['H'] = 0
    letters['I'] = 0
    letters['J'] = 0
    letters['K'] = 0
    letters['L'] = 0
    letters['M'] = 0
    letters['N'] = 0
    letters['O'] = 0
    letters['P'] = 0
    letters['Q'] = 0
    letters['R'] = 0
    letters['S'] = 0
    letters['T'] = 0
    letters['U'] = 0
    letters['V'] = 0
    letters['W'] = 0
    letters['X'] = 0
    letters['Y'] = 0
    letters['Z'] = 0
    letters['-'] = 0

def best_letter(word):
    if something_correct:
        for item in dictionary:
            if len(item) == len(word):
                good_candidate = True
                for ic in xrange(len(word)):
                    if word[ic] <> '_':
                        if word[ic] <> item[ic]:
                            good_candidate = False
                if good_candidate:
                    for c in letters.keys():
                        if free_letters[c] and c in item:
                            letters[c] += 1
    else:
        for item in dictionary:
            if len(item) == len(word):
                for vocal in vocals:
                    if free_letters[vocal]:
                        if vocal in item:
                            letters[vocal] += 1
    ch = max(letters.iteritems(), key=operator.itemgetter(1))[0]
    free_letters[ch] = False
    print ch
    return ch


if __name__ == "__main__":

    dfile = open('words.txt', 'r')
    for dline in dfile:
        dictionary.append(dline.replace('\r\n',''))
    dfile.close()

    new_level()
    print letters

    host = '52.49.91.111'
    port = 9988

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.settimeout(2)

    try :
        s.connect((host, port))
    except :
        print 'Unable to connect'
        sys.exit()

    print 'Connected to remote host'

    while True:
        socket_list = [sys.stdin, s]

        read_sockets, write_sockets, error_sockets = select.select(socket_list , [], [])

        for sock in read_sockets:
            if sock == s:
                data = sock.recv(4096)
                if not data :
                    print 'Connection closed'
                    sys.exit()
                else :
                    print data
                    lines = data.split('\n')
                    if len(lines) == 12:
                        new_round()
                        word = lines[9].replace(' ','')
                        if not something_correct:
                            for c in word:
                                if c <> '_':
                                    something_correct = True
                        s.send(best_letter(word))
                    else:
                        s.send(' ')
                        new_level()

            else :
                msg = sys.stdin.readline()
                s.send(msg)
