# Marble Bag

Each marble is represented by a class called 'Marble', which contains the following attributes:
 - Array of integers called 'color' containing (red, green, blue) each with values between 0 and 255
 - Boolean called 'isShooter' that detrmines if the marble is a larger marble, or shooter
 - int called 'id' that is used to identify each marble
 
Each marble also contains a function 'getInfo' which will return a string containing all info properly formatted.

The marble bag could be represented by a class or could be just main since there is only one marble bag. In any case it will contain the following functions:
 - a function called 'putMarble' which will create a random marble and place it in the bag.
 - a function called 'grabMarble' which will pull one random marble from the bag, print it out, then drop it on the table, which may as well be the void since we cant see it.
 - a function called 'dumpMarbles' which will dump all marbles on the table, printing each one.
 
 Finally there shall be a list called 'Marbles' that is an attribute of the bag and which contains all the marbles.
