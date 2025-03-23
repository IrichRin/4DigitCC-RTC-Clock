#include <Arduino.h>
#include <Clock.h>
                                     
Clock clock(new virtuabotixRTC(3, 4, 5), new int[7]{0, 1, 2, 6, 7, 8, 9}, new int[4]{10, 11, 12, 13});

void setup()  {      
    clock.initialize();
}

void loop()  {                                                                                                                                                                         
    clock.update();
    clock.render();
}                                                                                                        
                                                                                                        

  
