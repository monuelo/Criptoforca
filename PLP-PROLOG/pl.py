words = {}
with open("./words.csv") as f:
    for line in f:
        word, klass = line.split(",")
        klass = klass.strip().lower()
        if not klass.lower() in words:
            words[klass] = [word.lower()]
        else:
            words[klass].append(word.lower())

with open("palavras2.pl", "a") as p:
    for klass in words.keys():
        words2 = [x for x in words[klass] if " " not in x]
        count = 0
        diff = 0
        each = len(words2)/4
        for word in words2:
            if count % each == 0:
                diff += 1
            p.write("word({}, {}, {}).\n".format(word, klass, diff))
            count += 1
