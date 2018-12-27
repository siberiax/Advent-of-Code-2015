import hashlib

i = 0
start = "ckczppom"
while 1:
    to_hash = start + str(i)
    check = hashlib.md5(to_hash.encode('utf-8')).hexdigest()[:6]
    if check == "000000":
        print (i)
        break
    i += 1
