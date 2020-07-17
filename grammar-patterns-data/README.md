# Identifier Grammar Pattern Data

This data includes six files. Five of these files contain 267 grammar patterns sampled from open source systems and the last file contains an agglomeration of data from the other five files. Each file has several columns: Identifier Type, Identifier Name, FINAL GRAMMAR PATTERN, POSSE, SWUM, STANFORD, system, language. Each of these is self-explanatory, but the function grammar patterns file contains one additional column: STANFORD_WITH_I, due to our use of the stanford+I technique for improving certain POS taggers.  

# Tagset
The tagset that we used is a subset of Penn treebank. Each of our annotations and an example can be found below. Refer to the paper for more information.

| Abbreviation | Expanded Form                           | Examples                                                        |
|--------------|-----------------------------------------|-----------------------------------------------------------------|
| N            | noun                                    | Disneyland, shoe, faucet, mother, bedroom                       |
| DT           | determiner                              | the, this, that, these, those, which                            |
| CJ           | conjunction                             | and, for, nor, but, or, yet, so                                 |
| P            | preposition                             | behind, in front of, at, under, beside, above, beneath, despite |
| NPL          | noun plural                             | Streets, cities, cars, people, lists, items, elements.          |
| NM           | noun modifier (adjective, noun-adjunct) | red, cold, hot, scary, beautiful, happy, faster, small          |
| V            | verb                                    | Run, jump, drive, spin                                          |
| VM           | verb modifier (adverb)                  | Very, loudly, seriously,impatiently, badly                      |
| PR           | pronoun                                 | she, he, her, him, it, we, us, they, them, I, me, you           |
| D            | digit                                   | 1, 2, 10, 4.12, 0xAF                                            |
| PRE          | preamble (e.g., Hungarian)              | Gimp, GLEW, GL, G, p_, m_, b_                                   |


# Please cite the paper!

1. Christian D. Newman, Reem S. AlSuhaibani, Michael J. Decker, Anthony Peruma, Dishant Kaushik, Mohamed Wiem Mkaouer, Emily Hill,
On the generation, structure, and semantics of grammar patterns in source code identifiers, Journal of Systems and Software, 2020, 110740, ISSN 0164-1212, https://doi.org/10.1016/j.jss.2020.110740. (http://www.sciencedirect.com/science/article/pii/S0164121220301680) 

Keywords: Program comprehension; Identifier naming; Software maintenance; Source code analysis; Part-of-speech tagging


# Feel free to contribute!
We would love to keep this repository growing with more grammar patterns and are happy to credit anyone who decides to add to our current set here in the README (we will credit your name/username/webapge or whatever you like). If you'd like to contribute more grammar patterns, just make a pull request either adding your own file from a system we do not include above or modifying the .csv files already included. Just be sure to follow the format. 


# Interested in our research?
**Check out https://scanl.org/**
