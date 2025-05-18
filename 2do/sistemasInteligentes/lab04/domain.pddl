(define(domain minecraftCraftingTable)
    (:requirements :strips :typing :negative-preconditions)
    (:types
        slot material pickaxe craftedSlot inventory - object
        sticks cobblestone planks - material

    )

    (:predicates
        (planks-placed ?p - planks ?s - slot)
        (cobblestone-placed ?c - cobblestone ?s - slot)
        (stick-placed ?st - sticks ?s - slot)
        (material-placed ?m - material ?s - slot)
        (crafting-table ?s - slot ?sd - slot)
        (pickaxe-crafted ?pix - pickaxe ?cs - craftedSlot)
        (stick-in-inventory ?st - sticks ?in - inventory)
        (plank-in-inventory ?p - planks ?in - inventory)
        (cobblestone-in-inventory ?c - cobblestone ?in - inventory)
        (setInventory ?in - inventory ?s - slot)
        (setCraftedSlot ?cs - craftedSlot ?s - slot)
        (material-in-inventory ?m - material  ?in - inventory)

    )

    (:action place-stick
        :parameters (?s - slot ?st - sticks ?m - material  ?in - inventory )
        :precondition (and 
            (not (material-placed ?m ?s))
            (stick-in-inventory ?st ?in)
        )
        :effect (and 
            (stick-placed ?st ?s)
            (not(stick-in-inventory ?st ?in))
        )
    )
    (:action place-plank
        :parameters (?s - slot ?p - planks ?m - material  ?in - inventory )
        :precondition (and 
            (not (material-placed ?m ?s))
            (plank-in-inventory ?p ?in)
        )
        :effect (and 
            (planks-placed ?p ?s)
            (not(plank-in-inventory ?p ?in))
        )
    )

    (:action place-cobblestone
        :parameters (?s - slot ?c - cobblestone ?m - material  ?in - inventory )
        :precondition (and 
            (not (material-placed ?m ?s))
            (cobblestone-in-inventory ?c ?in)
        )
        :effect (and 
            (cobblestone-placed ?c ?s)
            (not(cobblestone-in-inventory ?c ?in))
        )
    )

)