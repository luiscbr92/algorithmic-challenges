import sys

SEMICOMBOS = [['D','RD','R'],['R','D','RD'],['D','LD','L']]

cases = int(raw_input())

for c in xrange(cases):
    output_header = "Case #" + str(c+1) + ":"

    moves = raw_input().split('-')

    quasi_combos = 0

    if len(moves) > 2:
        index_of_moves = 0;
        while(index_of_moves < len(moves) - 3):
            if moves[index_of_moves:index_of_moves+3] in SEMICOMBOS:
                if SEMICOMBOS.index(moves[index_of_moves:index_of_moves+3]) == 2:
                    if moves[index_of_moves+3] <> 'K':
                        quasi_combos += 1
                else:
                    if moves[index_of_moves+3] <> 'P':
                        quasi_combos += 1

            index_of_moves += 1

        if moves[len(moves)-3:] in SEMICOMBOS:
            quasi_combos += 1

    print output_header, quasi_combos
