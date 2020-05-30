
int diod = A5;
int lightRate;
bool published = false;

void setup() {
}

void loop() {
  
  lightRate = analogRead(diod);
  String LR = String(lightRate);
  Particle.publish("lightRate", LR);
    if(lightRate >= 20 && !published){
       Particle.publish("sunlight", "There is sunlight");
        
        published = true;
    }
    
    else if(lightRate < 20 && published){
        Particle.publish("nosunlight", "Shadow");
        published = false;
    }
    
    delay(2000);
}
