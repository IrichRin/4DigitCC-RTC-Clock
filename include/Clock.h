#include <virtuabotixRTC.h>  
#include <Numbers.h>

class Clock 
{
public:
    Clock(virtuabotixRTC* rtc, int displayPin[7], int commonPin[4]);
    void initialize();
    void update();
    void render();

private:
    int* mDisplayPin;
    int* mCommonPin;
    virtuabotixRTC* mRTC;
    

    int mHours;
    int mMinutes;

    std::map<String, int> mDisplayPinNames;
    std::map<String, int> mCommonPinNames;

    void changeHour();
    void changeMinute();
    void changeNumber(int x);
    
};