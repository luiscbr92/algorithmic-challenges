import yaml

stream = file('submitInput', 'r')
inpt = yaml.load(stream)
tapes = inpt['tapes']
code = inpt['code']

for i in tapes:
    output_header = "Tape #" + str(i) + ":"
    tape = list(tapes[i])
    current_state = 'start'
    index = 0

    while(current_state <> 'end'):
        if index < len(tape):
            c = tape[index]
        else:
            c = ' '
        s = current_state

        if 'write' in code[s][c].keys():
            if c <> ' ':
                tape[index] = code[s][c]['write']
            else:
                tape.append(code[s][c]['write'])
        if 'state' in code[s][c].keys():
            current_state = code[s][c]['state']

        if 'move' in code[s][c].keys():
            if 'right' == code[s][c]['move']:
                index += 1
            elif 'left' == code[s][c]['move']:
                index -= 1

    output_tape = ""
    for item in tape:
        output_tape += item

    print output_header, output_tape
