import json
import io
from fractions import Fraction
from pprint import pprint

try:
    to_unicode = unicode
except NameError:
    to_unicode = str

with open('class_data.json') as f:
    data = json.load(f)


#for i in data:
#    pprint(data[i])

#monsters["count"] = count
#str_ = json.dumps(
#    monsters,
#    separators=(',', ': '),
#    ensure_ascii=False)

#with io.open("monster_data.json", 'w', encoding='utf8') as outfile:
#    outfile.write(to_unicode(str_))

