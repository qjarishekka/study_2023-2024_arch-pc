(define (problem minecraftCraftingTable-problem)
    (:domain minecraftCraftingTable)
    (:objects
    slot1 slot2 slot3 slot4 slot5 slot6 slot7 slot8 slot9 - slot
    inventory - inventory
    craftedSlot - craftedSlot
    plank1 plank2 plank3 - planks
    cobblestone1 cobblestone2 cobblestone3 - cobblestone
    stick1 stick2 - sticks

    )
    (:init


        (setInventory inventory slot1)
        (setCraftedSlot craftedSlot slot6)

        (crafting-table slot1 slot2)
        (crafting-table slot2 slot3)

        (crafting-table slot4 slot5)
        (crafting-table slot5 slot6)

        (crafting-table slot7 slot8)
        (crafting-table slot8 slot9)

        (crafting-table slot1 slot4)
        (crafting-table slot4 slot7)

        (crafting-table slot3 slot6)
        (crafting-table slot9 slot6)

        (crafting-table slot2 slot5)
        (crafting-table slot5 slot8)

        (material-in-inventory plank1 inventory)
        (material-in-inventory plank2 inventory)
        (material-in-inventory plank3 inventory)

        (material-in-inventory cobblestone3 inventory)

        (cobblestone-placed cobblestone1 slot1)
        (cobblestone-placed cobblestone2 slot2)
        
        (stick-placed stick1 slot5)
        (stick-placed stick2 slot8)


    )
    (:goal (and
        (cobblestone-placed cobblestone3 slot3)
    ))


)
    