# Primordial soup
hackathon submission inspired by https://xkcd.com/720/

# Pitch for old version, submitted to bon-hacketit (list of changes at the bottom, or in the commit log)

# what it was supposed to do

The original idea was to have multiple recipes offered to the user, who would then give feedback, in some manner which we didn't get around to doing yet.

This would then inform the evolutionary algorithm (or genetic one, but breeding cake and roast dinner is just going to lead to disaster) that would mutate the recipes in different ways. The recipes would be stored somewhere, so that with use the model would improve, and actually produce usable recipes.

# Problem 1

The first question to ask when using evolutionary algorithms, is what would constitute a gene, and how would it be encoded? In this case, we went with a simple characters-and-numbers approach, that depends on a few external files being around. These files would contain a list of possible ingredients, a list of possible procedures that only require a single thing (stiring, cooking, peeling, washing, etc), and a list of ways to combine two things (mixing, placing on top, sprinkling, spreading, etc.)

# problem 2

Hosting and similar issues. We ended up using heroku for the online recipe parser.

# How to:

1) Clone the repo
2) run make
3) you will now have a recipe tree stored in `recipesample.txt` (assuming I remember the name correctly.
4) There will be some recipe genomes in `recipeQ.txt`, that you can have interpreted either using parse.pl, if you have perl (this is how `recipesample.txt` is made), or using the online interpreter.

# How to use the online interpreter.

1) get a genome, either from recipeQ.txt, a friend, or by running `./gen`.
    I'm going with `./gen`
```shell
foo@bar $ ./gen
i47 m5 m8 i45 m8 m3 m5 m0 m8 m5 M4 m2 m3 m5 m8  foo@bar $ 
```
   note the lack of a newline at the end. Here our genome is `i47 m5 m8 i45 m8 m3 m5 m0 m8 m5 M4 m2 m3 m5 m8 `

2) visit `https://radiant-sierra-73200.herokuapp.com/<Whatever the genome was>`, in this case [https://radiant-sierra-73200.herokuapp.com/i47 m5 m8 i45 m8 m3 m5 m0 m8 m5 M4 m2 m3 m5 m8 ](https://radiant-sierra-73200.herokuapp.com/i47%20m5%20m8%20i45%20m8%20m3%20m5%20m0%20m8%20m5%20M4%20m2%20m3%20m5%20m8%20).
3) you will be greeted by a recipe that looks like this:
```

lettuce 
|
cracked 
|
baked 
|
|garlic 
||
|baked 
||
|stirred 
||
|cracked 
||
|cut 
||
|baked 
||
|cracked 
||
Vadd 
|
peeled 
|
stirred 
|
cracked 
|
baked 
```

No, I do not know how one stirs baked garlic.

# changes made:

 1) prevent the generator from duplicating ingredients. (adding eggs to eggs doesn't make all that much sense)
 2) stop the generator from using the same method twice in a row. (an inelegant sollution, but it works)
 3) add a bit more formatting to the output (since I wasn't the one who did the heroku, I couldn't update that version)

