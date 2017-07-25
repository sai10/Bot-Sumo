              
// 	                          			T E S T  C A S E - 2

#include <NewPing.h>

// 2 DC MOTORS

#define left_motor_f 12
#define left_motor_b 13
#define right_motor_f 10
#define right_motor_b 11

// 6 IR SENSORS

#define IR1 2
#define IR2 3
#define IR3 4
#define IR4 5
#define IR5 6
#define IR6 7

// 2 ULTRASONIC SENSORS

#define US_1_T A5
#define US_1_E A4
#define US_2_T A2
#define US_2_E A3


NewPing frontsonar(US_1_T, US_1_E, 100);
NewPing backsonar(US_2_T, US_2_E, 100);


void setup()
{

      pinMode(left_motor_f, OUTPUT);
      pinMode(left_motor_b, OUTPUT);
      pinMode(right_motor_f, OUTPUT);
      pinMode(right_motor_b, OUTPUT);
      pinMode(IR1, INPUT);
      pinMode(IR2, INPUT);
      pinMode(IR3, INPUT);
      pinMode(IR4, INPUT);
      pinMode(IR5, INPUT);
      pinMode(IR6, INPUT);
  
}

void loop()
{
      unsigned int us1 = frontsonar.ping();
      unsigned int us2 = backsonar.ping();
        
      
      if(digitalRead(IR1)==1)                                                                        //   I R -  1
      {
          if(digitalRead(IR2)==0 && digitalRead(IR3)==0 && digitalRead(IR6)==0)           // SOUTH EAST
          {
            digitalWrite(left_motor_f,LOW);
          digitalWrite(left_motor_b,LOW);
          digitalWrite(right_motor_f,LOW);
          digitalWrite(right_motor_b,HIGH);
          }
          if(digitalRead(IR2)==1)                                                         // SOUTH EAST
          {
          digitalWrite(left_motor_f,LOW);
          digitalWrite(left_motor_b,LOW);
          digitalWrite(right_motor_f,LOW);
          digitalWrite(right_motor_b,HIGH);
          }
         if(digitalRead(IR2)==1 && digitalRead(IR3)==1)                                   // SOUTH 
         {
          digitalWrite(left_motor_f,LOW);
          digitalWrite(left_motor_b,HIGH);
          digitalWrite(right_motor_f,LOW);
          digitalWrite(right_motor_b,HIGH);
         }
         if(digitalRead(IR6)==1)                                                          // SOUTH EAST
         {
          digitalWrite(left_motor_f,LOW);
          digitalWrite(left_motor_b,LOW);
          digitalWrite(right_motor_f,LOW);
          digitalWrite(right_motor_b,HIGH);
        }
      
          if(((us1/US_ROUNDTRIP_CM)!=0) )                                                 // Ultrasonic sensor 1(front)
          {
            digitalWrite(left_motor_f,LOW);
            digitalWrite(left_motor_b,LOW);
            digitalWrite(right_motor_f,LOW);
            digitalWrite(right_motor_b,HIGH);  
          }
          if( ((us2/US_ROUNDTRIP_CM)!=0))                                                 //  Ultrasonic sensor 2(back)
          {
            
            digitalWrite(left_motor_f,LOW);
            digitalWrite(left_motor_b,LOW);
            digitalWrite(right_motor_f,LOW);
            digitalWrite(right_motor_b,HIGH);
         }
      }


      if(digitalRead(IR2)==1)                                                                       //   I R  -  2
      {
           if(digitalRead(IR1)==0 && digitalRead(IR3)==0)
            {
              digitalWrite(left_motor_f,LOW);
              digitalWrite(left_motor_b,HIGH);
              digitalWrite(right_motor_f,LOW);
              digitalWrite(right_motor_b,HIGH);
            }
            if(digitalRead(IR1)==1)
            {
              digitalWrite(left_motor_f,LOW);
              digitalWrite(left_motor_b,LOW);
              digitalWrite(right_motor_f,LOW);
              digitalWrite(right_motor_b,HIGH);
            }
            if(digitalRead(IR3)==1)
            {
              digitalWrite(left_motor_f,LOW);
              digitalWrite(left_motor_b,HIGH);
              digitalWrite(right_motor_f,LOW);
              digitalWrite(right_motor_b,LOW);
            }
            if(digitalRead(IR1)==1 && digitalRead(IR3)==1)
            {
              digitalWrite(left_motor_f,LOW);
              digitalWrite(left_motor_b,HIGH);
              digitalWrite(right_motor_f,LOW);
              digitalWrite(right_motor_b,HIGH);
            }
            if(((us1/US_ROUNDTRIP_CM)!=0)||((us2/US_ROUNDTRIP_CM)!=0) )                        // Ultrasonic sensor 1(front)
            {
              digitalWrite(left_motor_f,LOW);
              digitalWrite(left_motor_b,HIGH);
              digitalWrite(right_motor_f,LOW);
              digitalWrite(right_motor_b,HIGH);  
            }
      }
      
      if(digitalRead(IR3)==1)                                                                         //   I R  -  3
      {
          if(digitalRead(IR1)==1 && digitalRead(IR2)==0)                                     // SOUTH WEST
          {
          digitalWrite(left_motor_f,LOW);
          digitalWrite(left_motor_b,HIGH);
          digitalWrite(right_motor_f,LOW);
          digitalWrite(right_motor_b,LOW);
          }

           if(digitalRead(IR2)==1)                                                           // SOUTH WEST
          {
          digitalWrite(left_motor_f,LOW);
          digitalWrite(left_motor_b,HIGH);
          digitalWrite(right_motor_f,LOW);
          digitalWrite(right_motor_b,LOW);
          }

           if(digitalRead(IR1)==1 )                                                           // SOUTH
          {
          digitalWrite(left_motor_f,LOW);
          digitalWrite(left_motor_b,HIGH);
          digitalWrite(right_motor_f,LOW);
          digitalWrite(right_motor_b,HIGH);
          }

           if(digitalRead(IR4)==1)                                                            // SOUTH WEST
          {
          digitalWrite(left_motor_f,LOW);
          digitalWrite(left_motor_b,HIGH);
          digitalWrite(right_motor_f,LOW);
          digitalWrite(right_motor_b,LOW);
          }
          if(((us1/US_ROUNDTRIP_CM)!=0)||((us2/US_ROUNDTRIP_CM)!=0) )                         // Ultrasonic sensor 1(front)
          {
            digitalWrite(left_motor_f,LOW);
            digitalWrite(left_motor_b,HIGH);
            digitalWrite(right_motor_f,LOW);
            digitalWrite(right_motor_b,LOW);  
          }
      }
      
       if(digitalRead(IR4)==1)                                                                           //  I R  -  4
       {
          if(digitalRead(IR5)==0 && digitalRead(IR6)==0)                                     //NORTH WEST
          {
          digitalWrite(left_motor_f,HIGH);
          digitalWrite(left_motor_b,LOW);
          digitalWrite(right_motor_f,LOW);
          digitalWrite(right_motor_b,LOW);
          }
          
          if(digitalRead(IR5)==1)
          {
          digitalWrite(left_motor_f,HIGH);
          digitalWrite(left_motor_b,LOW);
          digitalWrite(right_motor_f,LOW);
          digitalWrite(right_motor_b,LOW);
          }
          
          if( digitalRead(IR6)==1)
          {
          digitalWrite(left_motor_f,HIGH);
          digitalWrite(left_motor_b,LOW);
          digitalWrite(right_motor_f,HIGH);
          digitalWrite(right_motor_b,LOW);
          }
          
          if(digitalRead(IR5)==1 && digitalRead(IR6)==1)
          {
          digitalWrite(left_motor_f,HIGH);
          digitalWrite(left_motor_b,LOW);
          digitalWrite(right_motor_f,HIGH);
          digitalWrite(right_motor_b,LOW);
          }

          if(((us1/US_ROUNDTRIP_CM)!=0) )                                                 // Ultrasonic sensor 1(front)
          {
            digitalWrite(left_motor_f,HIGH);
            digitalWrite(left_motor_b,LOW);
            digitalWrite(right_motor_f,LOW);
            digitalWrite(right_motor_b,LOW);  
          }
          if((us2/US_ROUNDTRIP_CM)!=0 )                                                   // Ultrasonic sensor 2(back)
          {
            digitalWrite(left_motor_f,HIGH);
            digitalWrite(left_motor_b,LOW);
            digitalWrite(right_motor_f,LOW);
            digitalWrite(right_motor_b,LOW);  
          }
      }
      
      
      if(digitalRead(IR5)==1)                                                                             //   I  R  - 5
      {
          if(digitalRead(IR4)==0 && digitalRead(IR6)==0)
          {
          digitalWrite(left_motor_f,HIGH);
          digitalWrite(left_motor_b,LOW);
          digitalWrite(right_motor_f,HIGH);
          digitalWrite(right_motor_b,LOW);
          }

          if(digitalRead(IR4)==1)
          {
          digitalWrite(left_motor_f,HIGH);
          digitalWrite(left_motor_b,LOW);
          digitalWrite(right_motor_f,LOW);
          digitalWrite(right_motor_b,LOW);
          }

          if(digitalRead(IR6)==1)
          {
          digitalWrite(left_motor_f,LOW);
          digitalWrite(left_motor_b,LOW);
          digitalWrite(right_motor_f,HIGH);
          digitalWrite(right_motor_b,LOW);
          }

          if(digitalRead(IR4)==1 && digitalRead(IR6)==1)
          {
          digitalWrite(left_motor_f,HIGH);
          digitalWrite(left_motor_b,LOW);
          digitalWrite(right_motor_f,HIGH);
          digitalWrite(right_motor_b,LOW);
          }

          if(((us1/US_ROUNDTRIP_CM)!=0) || ((us2/US_ROUNDTRIP_CM)!=0) )                          // Ultrasonic sensor 1(front)
          {
            digitalWrite(left_motor_f,HIGH);
            digitalWrite(left_motor_b,LOW);
            digitalWrite(right_motor_f,HIGH);
            digitalWrite(right_motor_b,LOW);  
          } 
      }
      

      if(digitalRead(IR6)==1)                                                                              //  I R  - 6
      {
          if(digitalRead(IR4)==0 && digitalRead(IR5)==0)
          {
          digitalWrite(left_motor_f,LOW);
          digitalWrite(left_motor_b,LOW);
          digitalWrite(right_motor_f,HIGH);
          digitalWrite(right_motor_b,LOW);
          }

          if(digitalRead(IR1)==1 || digitalRead(IR5)==1)
          {
          digitalWrite(left_motor_f,LOW);
          digitalWrite(left_motor_b,LOW);
          digitalWrite(right_motor_f,HIGH);
          digitalWrite(right_motor_b,LOW);
          }

          if(digitalRead(IR4)==1)
          {
          digitalWrite(left_motor_f,HIGH);
          digitalWrite(left_motor_b,LOW);
          digitalWrite(right_motor_f,HIGH);
          digitalWrite(right_motor_b,LOW);
          }

          if(digitalRead(IR4)==1 && digitalRead(IR5)==1)
          {
          digitalWrite(left_motor_f,HIGH);
          digitalWrite(left_motor_b,LOW);
          digitalWrite(right_motor_f,HIGH);
          digitalWrite(right_motor_b,LOW);
          }

          if(((us1/US_ROUNDTRIP_CM)!=1) || ((us2/US_ROUNDTRIP_CM)!=1) )                        // Ultrasonic sensor 1(front)
          {
            digitalWrite(left_motor_f,HIGH);
            digitalWrite(left_motor_b,LOW);
            digitalWrite(right_motor_f,HIGH);
            digitalWrite(right_motor_b,LOW);  
          }
      }  
  }
  
