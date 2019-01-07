 
#define C_DRUM A1
#define B_DRUM A2
#define D_DRUM A3 

void setup() {
   pinMode(C_DRUM,INPUT);
   pinMode(B_DRUM,INPUT);
   pinMode(D_DRUM,INPUT); 
 
    Serial.begin(38400);
 
}  


bool csend,bsend,dsend;

void sendTouched(int minimum,int pin,  bool * sent, String msg)
{  
    int val = analogRead(pin);
    if(val > minimum)
    {
       if(!*sent)
       {
         *sent = true;
          Serial.println(msg);
       }
    } else if(val < 5)
    {
        *sent = false;
    }
}

int i = 10;
void loop() {
  // put your main code here, to run repeatedly
   
 sendTouched(200,C_DRUM,&csend,"c");
 sendTouched(200,B_DRUM,&bsend,"b");
 sendTouched(200,D_DRUM,&dsend,"d"); 

/*
 int c = analogRead(C_DRUM);
 int b = analogRead(B_DRUM);
 int d = analogRead(D_DRUM);

 Serial.print(c);
 Serial.print("\t");
 
 Serial.print(b);
 Serial.print("\t");
 
 Serial.print(d);
 Serial.print("\t");
 */
  
 Serial.println();
 delay(5);
 
}
