import json
import sys


with open(sys.argv[1]) as json_file:
    total = 0
    data = json.load(json_file)
    queue = data.values()
    while(queue):
        to_add = []
        for el in queue:
            if type(el) == dict:
                vals = el.values()
                if "red" in vals:
                    continue
                else:
                    for el2 in vals:
                        if type(el2) == list or type(el2) == dict:
                            to_add.append(el2)
                        else:
                            if type(el2) == int:
                                total += el2
            elif type(el) == list:
                for el2 in el:
                    if type(el2) == list or type(el2) == dict:
                        to_add.append(el2)
                    else:
                        if type(el2) == int:
                            total += el2
        queue = to_add
    print(total)
