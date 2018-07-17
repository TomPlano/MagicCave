import json
import io
from pprint import pprint
try:
    to_unicode = unicode
except NameError:
    to_unicode = str

with open('original_item_data.json') as f:
    data = json.load(f)

common = dict()
uncommon = dict()
rare = dict()
vvrare = dict()
legendary = dict()

counts = {"c":0,"u":0,"r":0,"v":0,"l":0}

for i in data:
    rarity = data[i]["rarity"]
    if rarity == 'Common':
        common.update({counts['c']:data[i]})
        counts["c"]+=1
    elif rarity == 'Uncommon':
        uncommon.update({counts['u']:data[i]})
        counts["u"]+=1
    elif rarity == 'Rare':
        rare.update({counts['r']:data[i]})
        counts["r"]+=1
    elif rarity == 'Very Rare':
        vvrare.update({counts['v']:data[i]})
        counts["v"]+=1
    elif rarity == 'Legendary':
        legendary.update({counts['l']:data[i]})
        counts["l"]+=1


output = {'count':{'c':counts['c'],
                   'u':counts['u'],
                   'r':counts['r'],
                   'v':counts['v'],
                   'l':counts['l']
                  },
          '0':common,
          '1':uncommon,
          '2':rare,
          '3':vvrare,
          '4':legendary
         } 

str_ = json.dumps(
    output,
    separators=(',', ':'),
    indents=4,
    ensure_ascii=False)

with io.open("item_data.json", 'w', encoding='utf8') as outfile:
    outfile.write(to_unicode(str_))
            
        




