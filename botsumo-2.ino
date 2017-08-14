// 				T E S T  C A S E - 2

#include <NewPing.h>
#include <Servo.h>

//Motor Speed Control 
const int l_speed_pin = 6;
const int r_speed_pin = 11;

//Motor Direction 
const int l_dir_pin1 = 7;
const int l_dir_pin2 = 8;
const int r_dir_pin1 = 12;
const int r_dir_pin2 = 13;

//Line Sensor Inputs
const int l_line_pin = A0;
const int r_line_pin = A1;

const int line_thresh = 720;   //Input value beyond which indicates a line is detected

//Distance Sensor 
const int trig_pin = 2;
const int echo_pin = 3;

const int dist_limit = 100;   //Limit max distance reading (cm)
const int attack_dist = 75;    //Distance within which opponent will be attacked (cm)

NewPing ultra(trig_pin, echo_pin, dist_limit);

/**
Variable to keep track of and change robot states
Initially set to hunt state
0: Survive ; 1: Hunt ; 2: Attack
**/
const int Survive = 0;
const int Hunt = 1;
const int Attack = 2;
int state = Hunt;       

//Servo
const int servo_pin = 9;
Servo ramp;

void setup(){

  for(int i = 6; i <= 8; i++){
    pinMode(i, OUTPUT);
  }
  for(int i = 11; i <= 13; i++){
    pinMode(i, OUTPUT);
  } 

  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);

  ramp.attach(servo_pin);
  ramp.write(10);
}


                                        /*  Driving Functions */

void forward(){                                               //Forward function
  //Set direction
  digitalWrite(l_dir_pin1, HIGH);
  digitalWrite(r_dir_pin1, HIGH);
  digitalWrite(l_dir_pin2, LOW);
  digitalWrite(r_dir_pin2, LOW);

  //Set full speed
  analogWrite(l_speed_pin, 255);
  analogWrite(r_speed_pin, 255); 
}

void turn_left(){                                             //Left turn function
  //Set direction
  digitalWrite(l_dir_pin1, LOW);
  digitalWrite(r_dir_pin1, HIGH);
  digitalWrite(l_dir_pin2, HIGH);
  digitalWrite(r_dir_pin2, LOW);

  //Set full speed
  analogWrite(l_speed_pin, 255);
  analogWrite(r_speed_pin, 255);
}

void turn_right(){                                            //Right turn function
  //Set direction
  digitalWrite(l_dir_pin1, HIGH);
  digitalWrite(r_dir_pin1, LOW);
  digitalWrite(l_dir_pin2, LOW);
  digitalWrite(r_dir_pin2, HIGH);

  //Set full speed
  analogWrite(l_speed_pin, 255);
  analogWrite(r_speed_pin, 255);
}

void brake(){                                                 //Brake function
  //Disable direction
  digitalWrite(l_dir_pin1, LOW);
  digitalWrite(r_dir_pin1, LOW);
  digitalWrite(l_dir_pin2, LOW);
  digitalWrite(r_dir_pin2, LOW);

  //Set no speed
  analogWrite(l_speed_pin, 0);
  analogWrite(r_speed_pin, 0);
}


                                     /*Robot State Functions*/

void survive(){                                               //Survive State
  int l_line = analogRead(l_line_pin);
  int r_line = analogRead(r_line_pin);

  //If line detected on left side, turn right and drive forward a bit
  if(l_line < line_thresh){
    brake();
    turn_right();
    delay(500);
    forward();
    delay(200);
    return;
  }

  //If line detected on right side, turn left and drive forward a bit
  if(r_line < line_thresh){
    brake();
    turn_left();
    delay(500);
    forward();
    delay(200);
    return;
  }

  //If no line detected, switch to hunt state
  else
    state = Hunt;
    //{forward();
    //delay(200);}
}


void hunt(){                                                    //Hunt state
  //If a line is detected on either side, switch to survive state
  int l_line = analogRead(l_line_pin);
  int r_line = analogRead(r_line_pin);

  if(l_line < line_thresh || r_line < line_thresh){
    state = Survive;
    return;
  }

  //If opponent is detected, switch to attack state
  int dist = ultra.ping_cm();

  if(dist < attack_dist){
    state = Attack;
    return;
  }

  //Otherwise, rotate slightly and continue hunting 
  else{
    turn_right();
    delay(200);
    brake();
  }
}


void attack(){                                                   //Attack State
  //If a line is detected on either side, switch to survive state
  int l_line = analogRead(l_line_pin);
  int r_line = analogRead(r_line_pin);

  if(l_line < line_thresh || r_line < line_thresh){
    state = Survive;
    return;
  }

  int dist = ultra.ping_cm();

  //If opponent is not detected, switch to hunt state
  if(dist > attack_dist){
    state = Hunt;
    return;
  }

  //Otherwise, if opponent is detected, drive forward to attack
  else{
    forward();
    delay(500);
    brake();
  }
}


void loop(){
  //Use the switch  and "state" variable  to toggle between robot states

  switch(state){
      case Survive:
        survive();
        break;

      case Hunt:
        hunt();
        break;

      case Attack:
        attack();
        break;
  }
  //survive();
}
