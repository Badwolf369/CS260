# Marble Bag

Each marble is represented by a class called 'Marble', which contains the following attributes:
 - Array of integers called 'color' containing (red, green, blue) each with values between 0 and 255
 - Boolean called 'isShooter' that detrmines if the marble is a larger marble, or shooter
 - int called 'id' that is used to identify each marble
 
Each marble also contains a function 'getInfo' which will return a string containing all info properly formatted.

The marble bag could be represented by a class or could be just main since there is only one marble bag. In any case it will contain the following functions:
 - a function called 'putMarble' which will create a random marble and place it in the bag.
 - a function called 'grabMarble' which will pull one random marble from the bag, print it out, then drop it on the table, which may as well be the void since we cant see it. Will say there are no marbles if you try to pull a marble from the empty bag.
 - a function called 'dumpMarbles' which will dump all marbles on the table, printing each one. will say there are no marbles if you try to dump an empty bag.
 
 Finally there shall be a list called 'Marbles' that is an attribute of the bag and which contains all the marbles.


When implemented it will have a message pop up asking if they want to add a marble, remove a marble, or dump all the marbles.


To test this program, a simple procedure could be done. First, ask to pull a marble, should say there are no marbles. Then ask to dump all marbles and it should say there are n marbles. Next ask to create a marble. Then ask to pull 1 marble. It should print the marble type followed #0 followed by the random color. Ask to pull a marble again, should say theres no marbles. Next ask to dump the marbles, should say there are no marbles. Ask 5 times for a marble to be added. Ask to dump the marbles, should print out 5 marble types, the numbers 1-5, and 5 random colors. Then ask it to pull a marble and dump the amrbles again, it should say there are no marbles.
