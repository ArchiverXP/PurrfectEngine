
LoadBG("Hallway");
LoadSprite("O02", 0, 0)
LoadTBox("textbox")
CharSay("Olive: Hi! Welcome to Purrfect Engine!", 272, 553)
PlayMus("mus/Song-Opening.ogg")
local state = 1;
function Part()
    ClearText()
    CharSay("Olive: This engine is still a work in progress, report any issues through the github.", 272, 553)
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
