import json
import io
from fractions import Fraction
from pprint import pprint
try:
    to_unicode = unicode
except NameError:
    to_unicode = str

with open('original_monster_data.json') as f:
    data = json.load(f)

count = dict()
monsters = dict()

for i in data:
    challenge = str(data[i]["xp"])

    if not challenge.isdigit():
        challenge = float(sum(Fraction(s) for s in challenge.split()))

    if not challenge in count: 
        count[challenge] = 0
        monsters[challenge] = dict()

    if "environment" in data[i]:
        data[i].pop('environment')


    monsters[challenge].update({count[challenge] : data[i]})
    count[challenge] += 1

monsters["count"] = count
str_ = json.dumps(
    monsters,
    separators=(',', ': '),
    ensure_ascii=False)

with io.open("monster_data.json", 'w', encoding='utf8') as outfile:
    outfile.write(to_unicode(str_))

