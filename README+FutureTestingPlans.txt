Game Rules
Left Click on the Upsidedown Pyramids to drop tiles down the board. First to achieve 4 in a row wins the game.
Player must host a game before another can join.


Things I would think about for testing.

Networking:
-Testing connection to the server, test maximum possible players and try to join beyond that limit
-Get to players trying to connect to one single host.
-Seeing how the game reacts when a player suddenly disconnects, can the player still use the join to join back    into the session and continue playing
-What happens if both players host the server.

Game:
-See if I can play both server and client turns on one screen if I click the selectors fast enough
-Try potential edge cases for win detection
-What happens if the board is complete filled out, is there a tie state

UI:
-What are my options to interact with the UI/Menu
-What happens if I spam click the different buttons, does it click through.


Things to consider during the testing that are hard to account for:
-If two players are different locations far away, how does latency impact the game
-How does framerate effect the game. 