#include <Numbers.h>

void setToOne(std::map<String, int> displayPinNames) 
{
    for (const auto& i : displayPinNames)
    {
        if(i.first == "pinB" || i.first == "pinC")
        {
            digitalWrite(i.second, HIGH);
            continue;            
        }

        digitalWrite(i.second, LOW);
    }
}

void setToTwo(std::map<String, int> displayPinNames)
{
    for (const auto& i : displayPinNames)
    {
        if(i.first == "pinC" || i.first == "pinF")
        {
            digitalWrite(i.second, LOW);
            continue;
        }
        
        digitalWrite(i.second, HIGH);
    }
}

void setToThree(std::map<String, int> displayPinNames)
{
    for (const auto& i : displayPinNames)
    {
        if(i.first == "pinE" || i.first == "pinF")
        {
            digitalWrite(i.second, LOW);
            continue;
        }
        
        digitalWrite(i.second, HIGH);
    }
}

void setToFour(std::map<String, int> displayPinNames)
{
    for (const auto& i : displayPinNames)
    {
        if(i.first == "pinA" || i.first == "pinD" || i.first == "pinE")
        {
            digitalWrite(i.second, LOW);
            continue;
        }
        
        digitalWrite(i.second, HIGH);
    }
}

void setToFive(std::map<String, int> displayPinNames)
{
    for (const auto& i : displayPinNames)
    {
        if(i.first == "pinB" || i.first == "pinE")
        {
            digitalWrite(i.second, LOW);
            continue;
        }
            
        digitalWrite(i.second, HIGH);
    }
}

void setToSix(std::map<String, int> displayPinNames)
{
    for (const auto& i : displayPinNames)
    {
        if(i.first == "pinB")
        {
            digitalWrite(i.second, LOW);
            continue;
        }

        digitalWrite(i.second, HIGH);
    }
}

void setToSeven(std::map<String, int> displayPinNames)
{
    for (const auto& i : displayPinNames)
    {
        if(i.first == "pinD" || i.first == "pinE" || i.first == "pinF" ||
            i.first == "pinG")
        {
            digitalWrite(i.second, LOW);
            continue;
        }

        digitalWrite(i.second, HIGH);
    }
}

void setToEight(std::map<String, int> displayPinNames)
{
    for (const auto& i : displayPinNames)
    {
        digitalWrite(i.second, HIGH);
    }
}

void setToNine(std::map<String, int> displayPinNames)
{
    for (const auto& i : displayPinNames)
    {
        if(i.first == "pinD" || i.first == "pinE")
        {
            digitalWrite(i.second, LOW);
            continue;
        }
        
        digitalWrite(i.second, HIGH);
    }
}

void setToZero(std::map<String, int> displayPinNames)
{
    for (const auto& i : displayPinNames)
    {
        if(i.first == "pinG")
        {
            digitalWrite(i.second, LOW);
            continue;
        }
        
        digitalWrite(i.second, HIGH);
    }
}

void setToLOW(std::map<String, int> displayPinNames)
{
    for(const auto& i : displayPinNames)
        digitalWrite(i.second, LOW);
}