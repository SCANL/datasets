# AbbreviationArtifact-ICSME2019
Artifact for ICSME 2019.

This artifact includes two scripts. The first script, parse_abbreviation_expansions.cpp gives an example of how to parse the identifiers, abbrevivations, and expansions out of the csv files for each project. The second, GetIdentifierFileLocations.py gives an example of how to use srcML and XPath (via python) to determine every file where each identifier in the .csv artifacts occur. This is useful if you want to know, for example, where to look for abbreviation expansions while testing your own technique.

To compile parse_abbreviation_expansions.cpp:

clang++ parse_abbreviation_expansions.cpp -std=c++1y

To run:

./a.out [name of csv file]

To run GetIdentifierFileLocations.py, you'll need the wycheproof.java.xml example project file included in the repository. Follow these instructions:

1. Make sure lxml is installed: sudo apt-get install python3-lxml
2. unzip wycheproof srcml example: gzip -d wycheproof.java.xml.gz
3. python3 GetIdentifierFileLocations.py

If you're interested in modifying the scripts for your own use, you'll need to run srcML on whatever system you're interested in. Check out the srcML webpage for information on how to download/install and run srcML: https://www.srcml.org

# Please cite the papers!

1. C. D. Newman, M. J. Decker, R. S. Alsuhaibani, A. Peruma, D. Kaushik and E. Hill, "An Empirical Study of Abbreviations and Expansions in Software Artifacts," 2019 IEEE International Conference on Software Maintenance and Evolution (ICSME), Cleveland, OH, USA, 2019, pp. 269-279, doi: 10.1109/ICSME.2019.00040.

2. C. D. Newman, M. J. Decker, R. S. AlSuhaibani, A. Peruma, D. Kaushik and E. Hill, "An Open Dataset of Abbreviations and Expansions," 2019 IEEE International Conference on Software Maintenance and Evolution (ICSME), Cleveland, OH, USA, 2019, pp. 280-280, doi: 10.1109/ICSME.2019.00041.

# Feel free to contribute!
We would love to keep this repository growing with more abbreviations and expansions and are happy to credit anyone who decides to add to our current set here in the README (we will credit your name/username/webapge or whatever you like). If you'd like to contribute more abbreviations and expansions, just make a pull request either adding your own file from a system we do not include above or modifying the .csv files already included. Just be sure to follow the format. 

You do not need to include the original identifier / split identifier (though if you can, that would be great). You may provide just the abbreviation and expansion, however-- using the format in the .csvs above: (Abbreviation:Expansion).

# Interested in our research?
**Check out https://scanl.org/**
