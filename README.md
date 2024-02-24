# Object oriented programming - project 1 - CPP
**April 2023**

### Description
This project was implemented for Object Oriented Programming course.
The aim of the project was to implement a simple world simulator as a console application. The world is represented as a two-dimensional grid of size $N \times M$ provided by the user at the beginning of the program. The simulator is to be turn-based. In each turn, all organisms existing in the world perform an action appropriate to their type.
In this world there are a lot of simple life forms with different behaviours (which will be listed below). Each organism occupies exactly one field in the table, each field can contain at most one organism (when there is a collision, one of them should be removed or moved). The order in which organisms move in a turn depends on their initiatives. The animals with the highest initiative move first. If two animals have the same initiative, the order is determined by the principle of seniority (so the older animal moves first). There is also a special type of animal - human. While all animals move in random direction, human moves in the direction determined by user with use of arrows. Human also has a special skill (Alzur's shield - description below), which can be activated with a separate button ("u"). Once deactivated, the skill cannot be used activated before 5 consecutive turns.  
This program also allows user to save and load world state from .txt file.

#### Controls
- up arrow $\uparrow$, down arrow $\downarrow$, left arrow $\gets$, right arrow $\to$ - direction in which human will move
- q - quit program
- u - activate special human skill
- z - save world state to file
- w - load world state from file

#### Types of organisms
**Plants**
| Name | Strength | Initiative | Special behaviour | Character representation
| --- | --- | --- | --- | --- |
| wolf | 9 | 5 | - | W |
| sheep | 4 | 4 | - | O |
| fox | 3 | 7 | never moves to the space occupied by organism stronger than him | L |
| turtle | 2 | 1 | 75% of time does not change its position, repels attacks of animals with strength <5, the attacker must get back on its previous field | T |
| antelope | 4 | 4 | moves 2 fields in every direction, 50% chance to escape before the fight (moves to unoccupied adjacent field) | A |

**Animals**
| Name | Strength | Initiative | Special behaviour | Character representation
| --- | --- | --- | --- | --- |
| grass | 0 | 0 | - | t |
| field milk thistle | 0 | 0 | makes three attempts to spread in one turn | m |
| guarana | 0 | 0 | increases +3 strength of animal which ate this plant | g |
| belladonna | 99 | 0 | animal that ate this plant dies | j |
| Sosnowsky's hogweed | 10 | 0 | all animals in its neoghbourhood die, animal that ate this plant dies | b |

**Human special skill**
Aluzr's shield - human scares away all animals, animal which stands on the human field is moved to random adjacent field

### Screenshots
These screenshots represent world of size $20 \times 20$.  

<img width="495" alt="image" src="https://github.com/sztvk/PG_PO_project_cpp/assets/125211734/e1fb1a1e-0b18-4292-80da-626a60ae296b">
<img width="496" alt="image" src="https://github.com/sztvk/PG_PO_project_cpp/assets/125211734/dc6bbf65-0531-44fb-8450-9ec12d70c635">
