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


ccount = 0;
ucount = 0;
rcount = 0;
vcount = 0;
lcount = 0;

for i in data:
    rarity = data[i]["rarity"]
    if rarity == 'Common':
        common.update({ccount:data[i]})
        ccount+=1
    elif rarity == 'Uncommon':
        uncommon.update({ucount:data[i]})
        ucount+=1
    elif rarity == 'Rare':
        rare.update({rcount:data[i]})
        rcount+=1
    elif rarity == 'Very Rare':
        vvrare.update({vcount:data[i]})
        vcount+=1
    elif rarity == 'Legendary':
        legendary.update({lcount:data[i]})
        lcount+=1


output = {'count':{'c':ccount,'u':ucount,'r':rcount,'v':vcount,'l':lcount},'0':common,'1':uncommon,'2':rare,'3':vvrare,'4':legendary} 

str_ = json.dumps(
    output,
    separators=(',', ':'),
    ensure_ascii=False)

with io.open("item_data.json", 'w', encoding='utf8') as outfile:
    outfile.write(to_unicode(str_))
            
        




