#include <Clock.h>

Clock::Clock(virtuabotixRTC* rtc, int displayPin[7], int commonPin[4])
{
    this->mDisplayPin = displayPin;
    this->mCommonPin = commonPin;
    this->mRTC = rtc;
}

void Clock::initialize()
{
    this->mDisplayPinNames["pinA"] = mDisplayPin[0];
    this->mDisplayPinNames["pinB"] = mDisplayPin[1];
    this->mDisplayPinNames["pinC"] = mDisplayPin[2];
    this->mDisplayPinNames["pinD"] = mDisplayPin[3];
    this->mDisplayPinNames["pinE"] = mDisplayPin[4];
    this->mDisplayPinNames["pinF"] = mDisplayPin[5];
    this->mDisplayPinNames["pinG"] = mDisplayPin[6];

    this->mCommonPinNames["D1"] = mCommonPin[0];
    this->mCommonPinNames["D2"] = mCommonPin[1];
    this->mCommonPinNames["D3"] = mCommonPin[2];
    this->mCommonPinNames["D4"] = mCommonPin[3];

    for (const auto& i : mDisplayPinNames)
    {
        pinMode(i.second, OUTPUT);
    }

    for (const auto& j : mCommonPinNames)
    {
        pinMode(j.second, OUTPUT);
    }

    //open all: 
    for(const auto& x : mCommonPinNames)
    {
        digitalWrite(x.second, LOW);
    }

    this->changeNumber(1);

    delay(5000);
    for(const auto& x : mCommonPinNames)
    {
        digitalWrite(x.second, HIGH);
    }
    setToLOW(this->mDisplayPinNames);
    // this->mRTC->setDS1302Time(18, 10, 10, 7, 18, 9, 2020);
}

void Clock::update()
{
    this->mRTC->updateTime();
    this->mHours = this->mRTC->hours;
    this->mMinutes = this->mRTC->minutes;
}

void Clock::render()
{
    unsigned long startTime = millis();
    while (millis() - startTime < 2000) {
        this->changeHour();
    }

    startTime = millis();
    while (millis() - startTime < 2000) {
        this->changeMinute();
    }
}

void Clock::changeHour()
{
    //render hours
    if (this->mHours < 10)
    {
        for (const auto& i : this->mCommonPinNames)
        {
            if (i.first == "D1")
                digitalWrite(i.second, LOW);
            else
                digitalWrite(i.second, HIGH);
        }
        setToLOW(this->mDisplayPinNames);
        delay(250);

        for (const auto& j : this->mCommonPinNames)
        {
            if (j.first == "D2")
                digitalWrite(j.second, LOW);
            else
                digitalWrite(j.second, HIGH);
        }
        this->changeNumber(this->mHours);
        delay(250);
    }

    else
    {
        int first = this->mHours/10;
        int second = this->mHours%10;

        for (const auto& j : mCommonPinNames)
        {
            if (j.first != "D1")
                digitalWrite(j.second, HIGH);
            else
                digitalWrite(j.second, LOW);
        }
        this->changeNumber(first);
        delay(250);

        for (const auto& j : mCommonPinNames)
        {
            if (j.first == "D2")
                digitalWrite(j.second, LOW);
            else
                digitalWrite(j.second, HIGH);
        }
        this->changeNumber(second);
        delay(250);
    }
}

void Clock::changeMinute()
{
    //render minutes
    if (this->mMinutes < 10)
    {
        for (const auto& j : mCommonPinNames)
        {
            if (j.first == "D3")
                digitalWrite(j.second, LOW);
            else
                digitalWrite(j.second, HIGH);
        }
        this->changeNumber(0);
        delay(250);

        for (const auto& j : mCommonPinNames)
        {
            if (j.first == "D4")
                digitalWrite(j.second, LOW);
            else
                digitalWrite(j.second, HIGH);
        }
        this->changeNumber(this->mMinutes);
        delay(250);
    }
    else
    {
        int first = this->mMinutes/10;
        int second = this->mMinutes%10;

        for (const auto& j : mCommonPinNames)
        {
            if (j.first == "D3")
                digitalWrite(j.second, LOW);
            else
                digitalWrite(j.second, HIGH);
        }
        this->changeNumber(first);
        delay(250);

        for (const auto& j : mCommonPinNames)
        {
            if (j.first == "D4")
                digitalWrite(j.second, LOW);
            else
                digitalWrite(j.second, HIGH);
        }
        this->changeNumber(second);
        delay(250);
    }
}

void Clock::changeNumber(int x)
{
    switch (x)
    {
    case 1:
        setToOne(this->mDisplayPinNames);
        // Serial.print("IVE BEEN CALLED 1 ");
        break;

    case 2:
        setToTwo(this->mDisplayPinNames);
        // Serial.print("IVE BEEN CALLED 2 ");
        break;

    case 3:
        setToThree(this->mDisplayPinNames);
        // Serial.print("IVE BEEN CALLED 3 ");
        break;

    case 4:
        setToFour(this->mDisplayPinNames);
        // Serial.print("IVE BEEN CALLED 4 ");
        break;

    case 5:
        setToFive(this->mDisplayPinNames);
        // Serial.print("IVE BEEN CALLED 5 ");
        break;

    case 6:
        setToSix(this->mDisplayPinNames);
        // Serial.print("IVE BEEN CALLED 6 "); 
        break;

    case 7:
        setToSeven(this->mDisplayPinNames);
        // Serial.print("IVE BEEN CALLED 7 ");
        break;

    case 8:
        setToEight(this->mDisplayPinNames);
        // Serial.print("IVE BEEN CALLED 8 ");
        break;

    case 9:
        setToNine(this->mDisplayPinNames);
        // Serial.print("IVE BEEN CALLED 9 ");
        break;

    case 0:
        setToZero(this->mDisplayPinNames);
        // Serial.print("IVE BEEN CALLED 0 ");
        break;
    
    default:
        break;
    }
}

