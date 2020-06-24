# Filler
_A fun project to make a player for a Filler game_  

Filler is a "go meets tetris"-like game. There are two players.  
They play on map of fixed size and each given a one cell on that map at the beginning.  
At each game step both players receive from virtual machine a random figure.  
Then they should give the virtual mashine coordinates to place that figure on map.  
That figure should intersect with one (and only one) player's cell on map. The player that placed most figures wins.  
So the goal of each player is to take as much space as possible and prevent an opponent from expanding.

Virtual machine is a ruby-script provided by school 42 as well as other players executables (can be found in resources dir).  
It opens players as subprocesses and communicates with them via stdin/stdout. 

#### Strategy
My player at the very beginning of the game makes a heat-map (array of ints) with each cell containing a distance to the nearest enemy's cell.  
At each game move my player calculates the new coordinates so that figure would be plased as close as possible to the enemy's area.  
Eventually that leads to blocking enemy's ability to place new figures.
