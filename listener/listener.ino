// listener.ino

String command;

void setup(){
    Serial.begin(115200);
}

void loop(){
    if(Serial.available()){
        char c = Serial.read();
        if( c == '\n'){
            parseCommand(command);
            command = "";
        } else {
            command += c;
        }
    }
}

void parseCommand(String com){
    if ( com == "list" ){
        // List available commands
        Serial.print("Commands available: ");
        Serial.print("send ");
        Serial.println();
    } else if ( com == "send" ){
        // Send readings 
        Serial.write("Sent");
        Serial.write("\r\n"); 
    } else {
        // Fail
        Serial.print("Command \"");
        Serial.print(com);
        Serial.print("\" not recognized, use command \"list\" for available commands");
        Serial.println();
    }
    
}
