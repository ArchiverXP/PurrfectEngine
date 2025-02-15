
LoadBG("Hallway")
LoadTBox("textbox")
LoadSprite("O02", 0, 0)
CharSay("Olive:\n\nHi! Welcome to Purrfect Engine!", 272, 553)
PlayMus("mus/Song-Opening.ogg")
local state = 1;

function Part()
    CharSay("Olive:\n\nThis engine is still a work in progress, report any issues through\nthe github.", 272, 553)
    state = state + 1
    CheckPart(state)
    print(state)
end

function Part2()
    print("LOL, PART 2UH")
end

function CheckPart(state)
    if state == 3
        then Part2()
        elseif state == 4
            then print("FOUR")
            end
        end
