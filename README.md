# Data-Structures---Word-Puzzle-Patterns
https://acm.cs.nthu.edu.tw/problem/12186/
## Description
What:

The Data Structures TAs enjoy making word puzzles. Ron has challenged Eva to find all combinations of letters matching the following rule:

c(v)+(c(v)+)+c

Where c is a consonant and v is a vowel. This means: all strings of concatenations of at least two groups of one consonant followed by one or more vowels, followed by a consonant at the end (ex.: papap, paaaapaaaaap, papapap). Notice that the minimum length for this pattern is length=5.

Eva wants to check her answers. Help them build that program!

How:

You will be given 2 things: the word puzzle dimension and the word puzzle. You should traverse the matrix from left to right, from top to bottom. For each cell, output all possible paths matching the pattern in the traversal order. To change direction, use the following priorities: down, right, up, left.

You should also output the rearranged version of the word, where vowels go first and consonants after (example: apple turns into aeppl).

Example:

For example, take the word puzzle below:



Let’s take a look at some combinations:

XS is not valid, because you have 2 consonants in a row

AD is not valid, because it begins with a vowel

CAT is not valid, because there should be a vowel and a consonant to match the pattern

COZDP is not valid, because there are three consonants together

 

COZOB is valid, because it is of length>=5 and matches the pattern

XUVAIC is valid, because it is of length>=5 and matches the pattern

NIAVUX is valid, because it is of length>=5 and matches the pattern



HINT: use queue/stack to solve this problem.

## Input
1 line: What: an integer n and a new line character

           Why: matrix dimension will be (n*n)

n lines:     What: n lines of n characters followed by a new line character

                 Why: word puzzle layout

 

(n+1 lines in total)

 
## Output
You should all ‘words’ matching this pattern, followed by a space, the rearranged version of the words(vowels before consonants) and a newline character. Output should match the traversal order:

1. down
1. right
1. up
1. left

 
 
### Sample Input  

    5
    xscat
    cozdp
    okxbx
    blcpu
    lniav

### Sample Output  

    sokob ooskb
    sokoc ooskc
    socob ooscb
    socok oosck
    cokoz oockz
    cokos oocks
    cokob oockb
    zokob oozkb
    zokoc oozkc
    zocob oozcb
    zocok oozck
    kocob ookcb
    kocoz ookcz
    kocos ookcs
    xuvap uaxvp
    xuvaic uaixvc
    xuvain uaixvn
    xupav uaxpv
    xupaic uaixpc
    xupain uaixpn
    bokoz oobkz
    bokos oobks
    bokoc oobkc
    bocok oobck
    bocoz oobcz
    bocos oobcs
    ciavux iaucvx
    ciavup iaucvp
    ciapuv iaucpv
    ciapux iaucpx
    pavux aupvx
    puvaic uaipvc
    puvain uaipvn
    niavux iaunvx
    niavup iaunvp
    niapuv iaunpv
    niapux iaunpx
    vupaic uaivpc
    vupain uaivpn
    vapux auvpx
