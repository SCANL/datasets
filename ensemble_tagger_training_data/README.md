# Ensemble Tagger Training and Testing Set

This data includes two files: The training set used to create the SCANL Ensemble tagger [1] and the "unseen" testing set that includes words from systems that are not available in the training set. These are derived from a prior dataset of [Grammar Patterns](https://github.com/SCANL/datasets/tree/master/grammar_patterns_data); described in a different paper [2]. Within each of these csv files, you'll find several columns. We explain these columns below:

1. Type (only in training set) - Type (or return type) of the identifier to which current word belongs.

2. Identifier - The full identifier from which the current word was split.

3. Grammar Pattern - The sequence of part-of-speech tags generated by splitting the identifier into words and annotating with part-of-spech tags.

4. Word - The current word; derived by splitting the corresponding identifier.
    
5. SWUM annotation - The annotation that the SWUM POS tagger applied to a given word.
    
6. POSSE annotation - The annotation that the POSSE POS tagger applied to a given word.
    
7. Stanford annotation - The annotation that the Stanford POS tagger applied to a given word.

8. Flair annotation - The annotation that the FLAIR POS tagger applied to a given word.
    
9. Position - The position of a given word within its original identifier. For example, given an identifier: GetXMLReaderHandler, Get is in position 1, XML is in position 2, Reader is in position 3 and Handler is in position 4.
    
10. Identifier size (max position) - The length, in words, of the identifier of which the word was originally part. 
    
11. Normalized position - We normalized the position metric described above such that the first word in the identifier is in position 1, all middle words are in position 2, and the last word is in position 3. For example, given an identifier: GetXMLReaderHandler, Get is in position 1, XML is in position 2, Reader is in position 2 and Handler is in position 3. The reason for this feature is to mitigate the sometimes-negative effect of very long identifiers [2].
    
12. [Context](#context) - The dataset contains five categories of identifier name: function, parameter, attribute, declaration, and class. We provide the category to which the given identifier belongs as one of the features to allow the ensemble to learn patterns that are more pervasive for certain identifier types versus others. For example, function identifiers contain verbs at a higher rate than other types of identifiers [2].

13. Correct - The correct part-of-speech tag for the current word.

14. System - System in which the current word was found. 

15. Identifier Code - Each identifier has a unique number. Each word that has the same number is a part of the same identifier. For example, you can concatenate each word with a code of 0 to recreate the original identifier.

# Context
The numbers under the **context** feature represent the following categories (number -> category):
1.	attribute
2.	class
3.	declaration
4.	function
5.  parameter

# Best Features
We found [1] that the best features, of the features described above, were
1. SWUM
2. POSSE
3. Stanford
4. Normalized position
5. Context

# Tagset
The tagset that we use is a subset of Penn treebank. Each of our annotations and an example can be found below. Further examples and definitions can be found in the paper [1]

| Abbreviation | Expanded Form                           | Examples                                                        |
|--------------|-----------------------------------------|-----------------------------------------------------------------|
| N            | noun                                    | Disneyland, shoe, faucet, mother, bedroom                       |
| DT           | determiner                              | the, this, that, these, those, which                            |
| CJ           | conjunction                             | and, for, nor, but, or, yet, so                                 |
| P            | preposition                             | behind, in front of, at, under, beside, above, beneath, despite |
| NPL          | noun plural                             | streets, cities, cars, people, lists, items, elements.          |
| NM           | noun modifier (adjective)               | red, cold, hot, scary, beautiful, happy, faster, small          |
| NM           | noun modifier (noun-adjunct *italicized*) | *employee*Name, *file*Path, *font*Size, *user*Id              |
| V            | verb                                    | run, jump, drive, spin                                          |
| VM           | verb modifier (adverb)                  | very, loudly, seriously, impatiently, badly                     |
| PR           | pronoun                                 | she, he, her, him, it, we, us, they, them, I, me, you           |
| D            | digit                                   | 1, 2, 10, 4.12, 0xAF                                            |
| PRE          | preamble (e.g., Hungarian)              | Gimp, GLEW, GL, G, p_, m_, b_                                   |


# Word of Caution
Flair and Stanford recognize a larger number of verb conjugations (e.g., VBZ, VBD) than the ensemble, Posse, and SWUM. We left these conjugations in just in case someone wants to use them. If you are uninterested in using these conjugations, you should normalized them to just V-- inline with our [tagset](#tagset).

# Identifier Naming Structure Catalogue
We have put together a catalogue of [identifier naming structures](https://github.com/SCANL/identifier_name_structure_catalogue) in source code. This catalogue explains a lot more about why this work is important, how we are using the ensemble tagger and why the tagset looks the way it does.

# The actual tagger implementation
You can find the tagger that was trained using this data here: https://github.com/SCANL/ensemble_tagger

# Please cite the paper!

1. C.  D.  Newman,  M.  J.  Decker,  R.  S.  AlSuhaibani,  A.  Peruma,  S.  Mohapatra,  T.  Vishoi, M. Zampieri, M. W. Mkaouer, T. J. Sheldon, and E. Hill,  "An Ensemble Approach for Annotating Source Code Identifiers with Part-of-speech Tags," in IEEE Transactions on Software Engineering, doi: 10.1109/TSE.2021.3098242.

2. Christian D. Newman, Reem S. Alsuhaibani, Michael J. Decker, Anthony Peruma, Dishant Kaushik, Mohamed Wiem Mkaouer, Emily Hill,
On the generation, structure, and semantics of grammar patterns in source code identifiers, Journal of Systems and Software, 2020, 110740, ISSN 0164-1212, https://doi.org/10.1016/j.jss.2020.110740. (http://www.sciencedirect.com/science/article/pii/S0164121220301680) 

# Interested in our research?
**Check out https://scanl.org/**
