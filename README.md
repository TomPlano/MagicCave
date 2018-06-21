# The Cave of Shards

---

# Contents
- 1 - [Introduction](##1-introduction)
- 2 - [Lore](##2-lore)
- 3 - [Building](##3-building)

---

## 1. Introduction
This project aims to take the experience of preparing and running a tabletop
roleplaying game from an arduous task undertaken by a single individual to a
more equitable one-shot board game like experience, where no one person is wholly
responsible for all preparation. We envision the use of our tool to democratize
the playing of tabletop RPGs allowing the computer to do the uninteresting (to some)
work of creating maps, traps, loot, and enemies. In this way, the environment
itself becomes its own playable character of sorts that any one human can play
for a single session and then pass on to a different person in the play group
at the beginning of the next play experience. The potential market is any group who
want to play tabletop dungeon crawlers without having to do a lot of prep work.


## 2. Lore
Far out in the Sea of Fallen Stars, beyond the Pirate Isles, a new island has risen.
Thrust high above the waterline by a violent earthquake, it  was not long before
it was discovered by the Aglarond, venturing out onto the sea for trade and war.
Intrigued by the appearance of a new island, the high wizards of Aglarond sent
adventuring parties out to the island. Some returned, though many did not.
Those that did return told grand but conflicting tales of their time on the
island, with the only point of commonality being an unusual cave that stood
near the top of the newly formed cliffs. Each party told vastly different
accounts of the contents of the cave and each had the treasure to back up their
claims. It was finally determined that a more magical approach must be taken,
and a team of skilled wizards was dispatched, in the hopes that the secretes of
the cave would be made clear. It was to no avail however. All that was determined
was that the cave was indeed changing its contents periodically and the
mechanism was unknown. During this time treasure, monsters and even other
people were discovered within the cave, all of which had no idea of the
existence of a world outside their cave system, or of the countless other cave
systems that had been discovered in tandem to them. At the urging of the high
wizards, a commission was established on the island, both to protect the cave
and to collect a tax on those adventuring parties lucky enough to make it out
alive. It now stands open to anyone willing the take the challenge of
The Cave of Shards. Perhaps one day its secrets will be revealed.

specs:
-designed to optimism play on a 22x25 game mat or similar
-large map that is C*X by C*Y where X and Y are the edge dimensions of the play surface
as decided by players, c is some scalar (8 ish)
-large map is chopped to size and presented as different rooms.

## 3. Building

This project contains git submodules, specially jsoncpp.
To build this project after cloning
1. git submodule init   
2. git submodule update
3. if step 2 fails run "git submodule sync" then repeat step 2.
4. from the root dir, run make
