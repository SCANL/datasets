from lxml import etree
import csv

#Open artifact file as CSV
with open('ICSME_Abbreviation_Expansion_Artifact_Wycheproof.csv', newline='') as csvfile:
	csvReader = csv.DictReader(csvfile, delimiter=',', quotechar='"')
	#open srcML archive of project that artifact is from
	tree = etree.parse("wycheproof.java.xml")
	#Iterate each identifier name in the artifact csv file and check the srcML'd project file for where it appears via XPATH
	for row in csvReader:
		unit = tree.xpath('//src:unit/src:unit[descendant::src:name[text()="' + row["Original identifier"] + '"]]',
    		namespaces={
    		'src': 'http://www.srcML.org/srcML/src'
    		})
		for element in unit:
			print(row["Original identifier"] + ' ' +element.attrib['filename'])
