#include <Servo.h> 

char dataIn='S';char determinant;char det;int vel = 0; //Bluetooth Stuff
int ohjaus = 0, pos_alusta = 0, pos_tykki = 0; 
Servo alusta, tykki, vasen, oikea, laukaus; //Servos


void setup(){
Serial.begin(9600);              
}

void loop(){  
  det = check();
  /* Moves the tank tracks until the button
     corresponding to X is pressed. After the button
     press the tank switches controls to turret*/
  if (det == 'F') // F, move forward
    { if (ohjaus == 0){
        vasen.attach(9);
        oikea.attach(10);
        vasen.write(180);
        oikea.write(0);
        det = check();}
      else {
        if (pos_tykki < 80){
        tykki.attach(5);
        pos_tykki++;
        tykki.write(pos_tykki);
        delay(20);
        det = check();
  }
        }
      }
        
   
    
  if (det == 'B') // B, move backward
    { if (ohjaus == 0){
        vasen.attach(9);
        oikea.attach(10);
        vasen.write(0);
        oikea.write(180);
        det = check();}
      else {
        if (pos_tykki > 30 ){
          tykki.attach(5);  
          pos_tykki--;
          tykki.write(pos_tykki);
          delay(20);
          det = check();
  } 
     }
    }
  
  if (det == 'L') // L, move wheels left
    { if (ohjaus == 0){
        vasen.attach(9);
        oikea.attach(10);
        vasen.write(180);
        oikea.write(180);
        det = check();}
      else  {
        if (pos_alusta < 180){
          alusta.attach(3);
          pos_alusta++;
          alusta.write(pos_alusta);
          delay(20);
          det = check();
      }
      }
    }
      
  if (det == 'R') // R, move wheels right
    { if (ohjaus == 0){
        vasen.attach(9);
        oikea.attach(10);
        oikea.write(0);
        vasen.write(0);
        det = check();}
      else {
        if (pos_alusta > 5){
          alusta.attach(3); 
          pos_alusta--;
          alusta.write(pos_alusta);
          delay(20);    
          det = check();
      }
      }
    }
  
  //Stops the movement
  if (det == 'S') // S, stop
  { vasen.detach();
    oikea.detach();
    alusta.detach();
    tykki.detach();
    laukaus.detach();
    det = check();}
  
  //Toggles the turret controls
  while (det == 'X') 
  { ohjaus = 1;
    det = check();}
  
  //Toggles the tracks
  while (det == 'x'){
    ohjaus = 0;
    det = check();
    } 
    
  //Fires the cannon
  while (det == 'W'){
    laukaus.attach(6);
    laukaus.write(90);
    delay(500);
    laukaus.write(10);
    delay(500);
    det = check();
  }
}


//Checks what button is pressed and returns it
int check()
{if (Serial.available() > 0) {dataIn = Serial.read(); 
Serial.println(dataIn);
if (dataIn == 'F'){determinant = 'F';} 
else if (dataIn == 'B'){determinant = 'B';}else if (dataIn == 'L'){determinant = 'L';}
else if (dataIn == 'R'){determinant = 'R';}else if (dataIn == 'I'){determinant = 'I';} 
else if (dataIn == 'J'){determinant = 'J';}else if (dataIn == 'G'){determinant = 'G';} 
else if (dataIn == 'H'){determinant = 'H';}else if (dataIn == 'S'){determinant = 'S';}
else if (dataIn == '0'){vel = 400;}else if (dataIn == '1'){vel = 380;}
else if (dataIn == '2'){vel = 340;}else if (dataIn == '3'){vel = 320;}
else if (dataIn == '4'){vel = 280;}else if (dataIn == '5'){vel = 240;}
else if (dataIn == '6'){vel = 200;}else if (dataIn == '7'){vel = 160;}
else if (dataIn == '8'){vel = 120;}else if (dataIn == '9'){vel = 80;}
else if (dataIn == 'q'){vel = 40;}else if (dataIn == 'U'){determinant = 'U';}
else if (dataIn == 'u'){determinant = 'u';}else if (dataIn == 'W'){determinant = 'W';}
else if (dataIn == 'w'){determinant = 'w';}else if (dataIn == 'X'){determinant = 'X';}
else if (dataIn == 'x'){determinant = 'x';}}return determinant;}
