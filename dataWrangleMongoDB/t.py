import xml.etree.ElementTree as ET
import pprint

tree = ET.parse('')
root = tree.getroot()

title = root.find('./fm/bibl/title')

for a in root.findall(' '):
    email = a.find('email')
    if email is not None:
        print email.text
