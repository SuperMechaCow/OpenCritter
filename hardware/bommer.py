#!/usr/bin/env python

# (c) 2015 Productize <joost@productize.be>

import sys, copy, collections, codecs
from bs4 import BeautifulSoup

soup = BeautifulSoup(open(sys.argv[1]))

date = soup.design.date.contents[0]

comp = {}
comp_nc = {}

standard_fields = ['Reference','Identifier','Package','Value','Tolerance','Voltage','Current','Power','PN']
extra_fields = []

i = 1
for c in soup.components.find_all("comp"):
  new_comp = collections.defaultdict(str)
  new_comp['Reference'] = [c['ref']]
  new_comp['Value'] = c.value.contents[0]
  new_comp['Identifier'] = ''
  new_comp['Package'] = ''
  new_comp['Tolerance'] = ''
  new_comp['Voltage'] = ''
  new_comp['Current'] = ''
  new_comp['Power'] = ''
  new_comp['PN'] = ''
  for f in c.find_all("field"):
    new_comp[f['name']] = f.contents[0]
    if f['name'] not in standard_fields:
      if f['name'] not in extra_fields:
        extra_fields.append(f['name'])
  found = None
  new_comp_no_ref = {}
  for k in new_comp.keys():
    if k != 'Reference':
      new_comp_no_ref[k] = new_comp[k]
  for c2 in comp.values():
    c2_no_ref = {}
    for k in c2.keys():
      if k != 'Reference':
        c2_no_ref[k] = c2[k]
    if str(c2_no_ref) == str(new_comp_no_ref):
      found = c2
      c2['Reference'].append(c['ref'])
      break
  if found == None:
    comp[i] = new_comp
  i+=1


with codecs.open(sys.argv[2],"w", encoding='utf-8') as f:
  f.write("Reference,Quantity,Identifier,Package,Value,Tolerance,Voltage,Current,Power,PN")
  for c in extra_fields:
    f.write(","+c)
  f.write('\r\n')
  ordered = []
  for k in comp.keys():
    c = comp[k]
    ref = ';'.join(c['Reference'])
    l = [ref, str(len(c['Reference'])), c['Identifier'], c['Package'], c['Value'], c['Tolerance'], c['Voltage'], c['Current'], c['Power'], c['PN']]
    for y in extra_fields:
      l.append(c[y])
    #for y in c.keys():
    #  if y not in standard_fields:
    #    l.append
    l = ['"'+x+'"' for x in l]
    f.write(','.join(l))
    f.write('\r\n')