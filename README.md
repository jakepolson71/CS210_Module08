# CS210_Module08
Submission of Project Three to GitHub

* Summarize the project and what problem it was solving.
  The project was an assignment to create a program that would read data from a file (that would theoretically,
I assume, be created daily by another means to record the data of what was purchased and how many times was it purchsed that day.
The program in the project would then be used to open the file, read the data, and perform certain operations on it.  These functions
included counting the number of times each item appeared in the file, how many times a single, selected item appeared, and to create
a histogram of the data in the file.

* What did you do particularly well?
  I honestly am not sure which part I did particulary well on.  I think I did well with the Python side by utilizing dictionaries to
organize the data.  However, I also think I did well in utilizing C++ as a whole.  I'm not saying that I did any of it better than anyone else
could have.  It's just for me, I did well.  I've had trouble in the past with C++, and the code used to access Python from C++ is clunky and
not something I would want to do often.  I do, however, think I did pretty well at interpreting it and using it to create a new function
based on the ones provided.  It wasn't very original, but it worked.

* Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
  One thing that I never was able to figure out was how to use a Python procedure to open the file, write a list, thenn parse the list
into a dictionary.  Python is really good with lists and I prefer its dictionary function over C++ arrays for some reason.  However, for some reason,
I wasn't able to get Python to record the dictionary into a global variable that other procedures could then use.  I have absolutley no idea why.
I attempted mutliple ways to do it and they all failed.  I ended up creating a local list and dictionary from the text file inside each procedure.
Adding that procedure in and being able to access the dictionary from every procedure thereafter would have been much more efficient.
  I'm looking back at the code right now to see where something could have been done better.  I can't remember off the top of my head how Python handles
external files, but I'm pretty sure it requires, or at least recommends closing the files - and I just saw that I completely for got to do that, so
there's something else I could have done better - or at all.

* Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
  The most challenging part for me was trying to get a grasp on what C++ was doing when it was accessing the Python file.  The syntax and methods used
could really have been designed to be more clear in what they are doing.  After some studying them though, I think I sort of have a grasp
on it.  I honestly overcame this by staring at the screen until my eyes watered.  And reading the code over and over again, breaking it down as I went.
I finally realized that it was just ordinary C++ that I wasn't used to seeing or not seeing used in that particular manner.  For instance,
"PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;" threw me for a loop for a bit until I realized that it was just
initializing Python objects  I know it says PyObjects which I got.  I just couldn't figure out what the objects were doing exactly.  I still don't
know what "pValue = Py_BuildValue("(z)", paramval);" was doing.  I think it was doing some kind of error check, but I haven't sat down and Googled it yet.
Without Google, I'd be senile.  I can't list them all, since there were so many and I can't remember which ones I used for what,
I will definitely be using Google to find Python and C++ reference and tutorial sites forever.  As long as Google exists or something better comes
along, at least.  I just hope that whatever replaces Google is as good as Google.  Otherwise I may never be able to program or cook again.

* What skills from this project will be particularly transferable to other projects or course work?
  The one skill, in both C++ and Python, that I am most likely to transfer to other projects and course work is opening external files for 
reading and writing.  Hands down.  I can't think of a single program that I own that doesn't use some sort of external file.  Modern
video games couldn't exist without them.  Heck, even recreations of old games that did use only one file now use multiple files.  Graphics files
are perhaps the most important type used in games now.  Back when Pong was invented, all of the graphics were created by programming individual pixels.
It's not that hard to imagine, since pixels back then were the size of your thumbnail.  They got a little smaller in the 8-bit days, or "the Nintendo Days",
which is what most kids know them as now.  Even then, though, graphics were programmed pixel by pixel.  They were so big that it wasn't that hard to do.
Today, that's just not feasible.  A 1920 x 1080 screen has over 2 million pixels.  It almost makes me shudder to think about having to program them one 
at a time like they did when video games were new.  I was actually a programmer back in those days.  I was an 11-year-old kid with a Tandy Color Computer 2
programming in the, unimaginable today, BASIC language.  I still feel a little nostalgic when I see "cls" still being used in C++ today.

* How did you make this program maintainable, readable, and adaptable?
  First of all, I tried to break everything down into as small of bites as I could.  (Bites, not bytes)  I probably went a little overboard on the number
of functions I used.  I'm sure a lot of the what I broke out could have been left in other functions without causing too much of a headache.  However, in
doing so, I think I left my program in a pretty readable and maintainable state.  I also used a header file to initialize functions in, which adds
just a little more organization.  Of course, I slapped in a ton of comments, probably too many, as I am known to over-comment








