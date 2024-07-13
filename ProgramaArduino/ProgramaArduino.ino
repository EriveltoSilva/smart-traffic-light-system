//*******************************
//Variable de Estados
#define estado_verde 1
#define estado_amarelo 2
#define estado_vermelho 3

//Funciones
#define led_verde_1 2
#define led_amarelo_1 3
#define led_vermelho_1 4

#define led_verde_2 5
#define led_amarelo_2 6
#define led_vermelho_2 7

#define led_verde_3 8
#define led_amarelo_3 9
#define led_vermelho_3 10

#define led_verde_4 11
#define led_amarelo_4 12
#define led_vermelho_4 13


#define ldr1 A1
#define ldr2 A2
#define ldr3 A3
#define ldr4 A4


#define pot A5
#define LED A0

//Variable
bool Evento_TA1;
bool Evento_TR1;
bool Evento_TV1;

bool Evento_TA2;
bool Evento_TR2;
bool Evento_TV2;

bool Evento_TA3;
bool Evento_TR3;
bool Evento_TV3;

bool Evento_TA4;
bool Evento_TR4;
bool Evento_TV4;


bool Habilitado_TV1;
bool Habilitado_TA1;
bool Habilitado_TR1;

bool Habilitado_TV2;
bool Habilitado_TA2;
bool Habilitado_TR2;

bool Habilitado_TV3;
bool Habilitado_TA3;
bool Habilitado_TR3;

bool Habilitado_TV4;
bool Habilitado_TA4;
bool Habilitado_TR4;


byte estado_semaforo_1;
byte estado_semaforo_2;
byte estado_semaforo_3;
byte estado_semaforo_4;


boolean haCarro1 = false, haCarro2 = false, haCarro3 = false, haCarro4 = false;
//**************************************************************************************

//Recursos
int contadorHa1_1 = 0, contadorHa1_2 = 0, contadorHa1_3 = 0, contadorHa1_4 = 0;
int contadorHa2_1 = 0, contadorHa2_2 = 0, contadorHa2_3 = 0, contadorHa2_4 = 0;
int contadorHa3_1 = 0, contadorHa3_2 = 0, contadorHa3_3 = 0, contadorHa3_4 = 0;
int contadorHa4_1 = 0, contadorHa4_2 = 0, contadorHa4_3 = 0, contadorHa4_4 = 0;


unsigned long tempo_ant = 0, tempo_act = 0, tempo_req = 1000;
boolean controleVez = false;
int nSegundos = 5;
int marcoLDR = 600, maximo = 0;
byte contadorEngarrafamento = 0;
//**********************************

// N- Normal, E-Emergencia
char modo = 'N';

void modo_verde_1() {
  digitalWrite(led_verde_1, HIGH);
  digitalWrite(led_amarelo_1, LOW);
  digitalWrite(led_vermelho_1, LOW);
}


void modo_amarelo_1() {
  digitalWrite(led_verde_1, LOW);
  digitalWrite(led_amarelo_1, HIGH);
  digitalWrite(led_vermelho_1, LOW);
}

void modo_vermelho_1() {
  digitalWrite(led_verde_1, LOW);
  digitalWrite(led_amarelo_1, LOW);
  digitalWrite(led_vermelho_1, HIGH);
}

void modo_verde_2() {
  digitalWrite(led_verde_2, HIGH);
  digitalWrite(led_amarelo_2, LOW);
  digitalWrite(led_vermelho_2, LOW);
}

void modo_amarelo_2() {
  digitalWrite(led_verde_2, LOW);
  digitalWrite(led_amarelo_2, HIGH);
  digitalWrite(led_vermelho_2, LOW);
}

void modo_vermelho_2() {
  digitalWrite(led_verde_2, LOW);
  digitalWrite(led_amarelo_2, LOW);
  digitalWrite(led_vermelho_2, HIGH);
}


void modo_verde_3() {
  digitalWrite(led_verde_3, HIGH);
  digitalWrite(led_amarelo_3, LOW);
  digitalWrite(led_vermelho_3, LOW);
}

void modo_amarelo_3() {
  digitalWrite(led_verde_3, LOW);
  digitalWrite(led_amarelo_3, HIGH);
  digitalWrite(led_vermelho_3, LOW);
}

void modo_vermelho_3() {
  digitalWrite(led_verde_3, LOW);
  digitalWrite(led_amarelo_3, LOW);
  digitalWrite(led_vermelho_3, HIGH);
}


void modo_verde_4() {
  digitalWrite(led_verde_4, HIGH);
  digitalWrite(led_amarelo_4, LOW);
  digitalWrite(led_vermelho_4, LOW);
}

void modo_amarelo_4() {
  digitalWrite(led_verde_4, LOW);
  digitalWrite(led_amarelo_4, HIGH);
  digitalWrite(led_vermelho_4, LOW);
}

void modo_vermelho_4() {
  digitalWrite(led_verde_4, LOW);
  digitalWrite(led_amarelo_4, LOW);
  digitalWrite(led_vermelho_4, HIGH);
}

char getEstadoSemaforo(int num) {
  if (num == 1) {
    if (digitalRead(led_verde_1)) return 'g';
    else if (digitalRead(led_amarelo_1)) return 'y';
    else if (digitalRead(led_vermelho_1)) return 'r';
    else return 'd';
  } 
  else if (num == 2) {
    if (digitalRead(led_verde_2)) return 'g';
    else if (digitalRead(led_amarelo_2)) return 'y';
    else if (digitalRead(led_vermelho_2)) return 'r';
    else return 'd';
  } 
  else if (num == 3) {
    if (digitalRead(led_verde_3)) return 'g';
    else if (digitalRead(led_amarelo_3)) return 'y';
    else if (digitalRead(led_vermelho_3)) return 'r';
    else return 'd';
  } 
  else if (num == 4) {
    if (digitalRead(led_verde_4)) return 'g';
    else if (digitalRead(led_amarelo_4)) return 'y';
    else if (digitalRead(led_vermelho_4)) return 'r';
    else return 'd';
  }
  return 'd';
}

String lerEstados() {
  String estados = "";
  estados += String(getEstadoSemaforo(1)) + "*";
  estados += String(getEstadoSemaforo(2)) + "*";
  estados += String(getEstadoSemaforo(3)) + "*";
  estados += String(getEstadoSemaforo(4)) + "*";
  return estados;
}

void enviarDados() {
  Serial.println("D*" + lerEstados()+String(modo)+"*");
}



void setup() {
  //Semaforo 1
  pinMode(led_verde_1, OUTPUT);
  pinMode(led_amarelo_1, OUTPUT);
  pinMode(led_vermelho_1, OUTPUT);
  digitalWrite(led_verde_1, LOW);
  digitalWrite(led_amarelo_1, LOW);
  digitalWrite(led_vermelho_1, HIGH);

  //Semaforo 2
  pinMode(led_verde_2, OUTPUT);
  pinMode(led_amarelo_2, OUTPUT);
  pinMode(led_vermelho_2, OUTPUT);
  digitalWrite(led_verde_2, LOW);
  digitalWrite(led_amarelo_2, LOW);
  digitalWrite(led_vermelho_2, HIGH);

  //Semaforo 3
  pinMode(led_verde_3, OUTPUT);
  pinMode(led_amarelo_3, OUTPUT);
  pinMode(led_vermelho_3, OUTPUT);
  digitalWrite(led_verde_3, LOW);
  digitalWrite(led_amarelo_3, LOW);
  digitalWrite(led_vermelho_3, HIGH);

  //Semaforo 4
  pinMode(led_verde_4, OUTPUT);
  pinMode(led_amarelo_4, OUTPUT);
  pinMode(led_vermelho_4, OUTPUT);
  digitalWrite(led_verde_4, LOW);
  digitalWrite(led_amarelo_4, LOW);
  digitalWrite(led_vermelho_4, HIGH);

  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  delay(3000);

  Serial.begin(9600);
  delay(1000);

  //*****************************
  //Inicialização do semaforo 1 no Primeiro estado
  estado_semaforo_1 = estado_vermelho;
  estado_semaforo_2 = estado_verde;
  estado_semaforo_3 = estado_vermelho;
  estado_semaforo_4 = estado_verde;

  tempo_ant = millis();
  tempo_req = 1000;
  Habilitado_TR1 = true;
  Habilitado_TV2 = true;
  Habilitado_TR3 = true;
  Habilitado_TV4 = true;
}


void maquina_de_estado(byte estado_maquina) {
  //1.-*************************
  //1-Semaforo
  if (Habilitado_TV1) {
    if (millis() - tempo_ant >= tempo_req) {
      Evento_TV1 = true;
    }
  }
  if (Habilitado_TA1) {
    if (millis(); - tempo_ant >= tempo_req) {
      Evento_TA1 = true;
    }
  }
  if (Habilitado_TR1) {
    if (millis() - tempo_ant >= tempo_req) {
      Evento_TR1 = true;
    }
  }

  //semaforo 2
  if (Habilitado_TV2) {
    if (millis() - tempo_ant >= tempo_req) {
      Evento_TV2 = true;
    }
  }
  if (Habilitado_TA2) {
    if (millis() - tempo_ant >= tempo_req) {
      Evento_TA2 = true;
    }
  }
  if (Habilitado_TR2) {
    if (millis() - tempo_ant >= tempo_req) {
      Evento_TR2 = true;
    }
  }

  //Semaforo 3
  if (Habilitado_TV3) {
    if (millis() - tempo_ant >= tempo_req) {
      Evento_TV3 = true;
    }
  }
  if (Habilitado_TA3) {
    if (millis() - tempo_ant >= tempo_req) {
      Evento_TA3 = true;
    }
  }
  if (Habilitado_TR3) {
    if (millis() - tempo_ant >= tempo_req) {
      Evento_TR3 = true;
    }
  }

  //Semaforo 4
  if (Habilitado_TV4) {
    if (millis() - tempo_ant >= tempo_req) {
      Evento_TV4 = true;
    }
  }
  if (Habilitado_TA4) {
    if (millis() - tempo_ant >= tempo_req) {
      Evento_TA4 = true;
    }
  }
  if (Habilitado_TR4) {
    if (millis() - tempo_ant >= tempo_req) {
      Evento_TR4 = true;
    }
  }


  //2.-*************************

  if (Evento_TV2) {
    estado_semaforo_1 = estado_vermelho;
    estado_semaforo_3 = estado_vermelho;
    estado_semaforo_2 = estado_amarelo;
    estado_semaforo_4 = estado_amarelo;
    tempo_ant = millis();
    tempo_req = 2000;
    Habilitado_TA2 = true;
    Habilitado_TA4 = true;
    Habilitado_TR1 = true;
    Habilitado_TV3 = true;

    Habilitado_TV2 = false;
    Habilitado_TV4 = false;
  }

  if (Evento_TA2) {
    estado_semaforo_2 = estado_vermelho;
    estado_semaforo_4 = estado_vermelho;
    estado_semaforo_1 = estado_verde;
    estado_semaforo_3 = estado_verde;
    tempo_ant = millis();
    tempo_req = 2000;
    Habilitado_TR2 = true;
    Habilitado_TR4 = true;
    Habilitado_TV1 = true;
    Habilitado_TV3 = true;

    Habilitado_TA2 = false;
    Habilitado_TA4 = false;
  }




  if (Evento_TV1) {
    estado_semaforo_1 = estado_amarelo;
    estado_semaforo_3 = estado_amarelo;
    estado_semaforo_2 = estado_vermelho;
    estado_semaforo_4 = estado_vermelho;
    tempo_ant = millis();
    tempo_req = 2000;
    Habilitado_TA1 = true;
    Habilitado_TA3 = true;
    Habilitado_TR4 = true;
    Habilitado_TR2 = true;

    Habilitado_TV1 = false;
    Habilitado_TV3 = false;
  }

  if (Evento_TA1) {
    estado_semaforo_1 = estado_vermelho;
    estado_semaforo_3 = estado_vermelho;
    estado_semaforo_2 = estado_verde;
    estado_semaforo_4 = estado_verde;

    tempo_ant = millis();
    tempo_req = 2000;
    Habilitado_TA1 = false;
    Habilitado_TA3 = false;

    Habilitado_TR1 = true;
    Habilitado_TR3 = true;
    Habilitado_TV2 = true;
    Habilitado_TV4 = true;
  }




  //3.-*************************
  //Ejecions de estado
  switch (estado_maquina) {
    case 1:
      if (estado_semaforo_1 == estado_verde) {
        modo_verde_1();
      } else if (estado_semaforo_1 == estado_amarelo) {
        modo_amarelo_1();
      } else if (estado_semaforo_1 == estado_vermelho) {
        modo_vermelho_1();
      }

      if (estado_semaforo_2 == estado_verde) {
        modo_verde_2();
      } else if (estado_semaforo_2 == estado_amarelo) {
        modo_amarelo_2();
      } else if (estado_semaforo_2 == estado_vermelho) {
        modo_vermelho_2();
      }

      if (estado_semaforo_3 == estado_verde) {
        modo_verde_3();
      } else if (estado_semaforo_3 == estado_amarelo) {
        modo_amarelo_3();
      } else if (estado_semaforo_3 == estado_vermelho) {
        modo_vermelho_3();
      }

      if (estado_semaforo_4 == estado_verde) {
        modo_verde_4();
      } else if (estado_semaforo_4 == estado_amarelo) {
        modo_amarelo_4();
      } else if (estado_semaforo_4 == estado_vermelho) {
        modo_vermelho_4();
      }
      break;

    case 2:
      if ((estado_semaforo_1 == estado_verde) && (haCarro1)) {
        modo_verde_1();
      } else if ((estado_semaforo_1 == estado_verde) && (!haCarro1) && (Habilitado_TV1)) {
        tempo_ant = millis() - tempo_req;
      } else if ((estado_semaforo_1 == estado_amarelo) && (haCarro1)) {
        modo_amarelo_1();
      } else if ((estado_semaforo_1 == estado_amarelo) && (!haCarro1) && (Habilitado_TA1)) {
        tempo_ant = millis() - tempo_req;
      } else if (estado_semaforo_1 == estado_vermelho) {
        modo_vermelho_1();
      } else {
        tempo_ant = millis() - tempo_req;
      }

      if ((estado_semaforo_2 == estado_verde) && (haCarro2)) {
        modo_verde_2();
      } else if ((estado_semaforo_2 == estado_verde) && (!haCarro2) && (Habilitado_TV2)) {
        tempo_ant = millis() - tempo_req;
      } else if ((estado_semaforo_2 == estado_amarelo) && (haCarro2)) {
        modo_amarelo_2();
      } else if ((estado_semaforo_2 == estado_amarelo) && (!haCarro2) && (Habilitado_TA2)) {
        tempo_ant = millis() - tempo_req;
      } else if (estado_semaforo_2 == estado_vermelho) {
        modo_vermelho_2();
      } else {
        tempo_ant = millis() - tempo_req;
      }

      if ((estado_semaforo_3 == estado_verde) && (haCarro3)) {
        modo_verde_3();
      } else if ((estado_semaforo_3 == estado_verde) && (!haCarro3) && (Habilitado_TV3)) {
        tempo_ant = millis() - tempo_req;
      } else if ((estado_semaforo_3 == estado_amarelo) && (haCarro3)) {
        modo_amarelo_3();
      } else if ((estado_semaforo_3 == estado_amarelo) && (!haCarro3) && (Habilitado_TA3)) {
        tempo_ant = millis() - tempo_req;
      } else if (estado_semaforo_3 == estado_vermelho) {
        modo_vermelho_3();
      } else {
        tempo_ant = millis() - tempo_req;
      }


      if ((estado_semaforo_4 == estado_verde) && (haCarro4)) {
        modo_verde_4();
      } else if ((estado_semaforo_4 == estado_verde) && (!haCarro4) && (Habilitado_TV4)) {
        tempo_ant = millis() - tempo_req;
      } else if ((estado_semaforo_4 == estado_amarelo) && (haCarro4)) {
        modo_amarelo_4();
      } else if ((estado_semaforo_4 == estado_amarelo) && (!haCarro4) && (Habilitado_TA4)) {
        tempo_ant = millis() - tempo_req;
      } else if (estado_semaforo_4 == estado_vermelho) {
        modo_vermelho_4();
      } else {
        tempo_ant = millis() - tempo_req;
      }
      break;
  }


  //4.-*************************
  //Reiniciando Eventos
  Evento_TV1 = false;
  Evento_TA1 = false;
  Evento_TR1 = false;
  Evento_TV2 = false;
  Evento_TA2 = false;
  Evento_TR2 = false;
  Evento_TV3 = false;
  Evento_TA3 = false;
  Evento_TR3 = false;
  Evento_TV4 = false;
  Evento_TA4 = false;
  Evento_TR4 = false;
}

void modo_emergencia() {
  modo_vermelho_1();
  modo_vermelho_2();
  modo_vermelho_3();
  modo_vermelho_4();
}

void modo_alerta() {
  modo_amarelo_1();
  modo_amarelo_2();
  modo_amarelo_3();
  modo_amarelo_4();
}
void modo_apagados() {
  digitalWrite(led_verde_1, LOW);
  digitalWrite(led_amarelo_1, LOW);
  digitalWrite(led_vermelho_1, LOW);

  digitalWrite(led_verde_2, LOW);
  digitalWrite(led_amarelo_2, LOW);
  digitalWrite(led_vermelho_2, LOW);

  digitalWrite(led_verde_3, LOW);
  digitalWrite(led_amarelo_3, LOW);
  digitalWrite(led_vermelho_3, LOW);

  digitalWrite(led_verde_4, LOW);
  digitalWrite(led_amarelo_4, LOW);
  digitalWrite(led_vermelho_4, LOW);
}

void loop() {
  receberDados();

  if (modo == 'N') {
    int LDR1 = analogRead(ldr1);
    int LDR2 = analogRead(ldr2);
    int LDR3 = analogRead(ldr3);
    int LDR4 = analogRead(ldr4);
    int POT = analogRead(pot);

    marcoLDR = map(POT, 0, 1023, 100, 1000);
    if (LDR1 > maximo) { maximo = LDR1; }
    if (LDR2 > maximo) { maximo = LDR2; }
    if (LDR3 > maximo) { maximo = LDR3; }
    if (LDR4 > maximo) { maximo = LDR4; }
    if (marcoLDR > maximo) {
      digitalWrite(LED, HIGH);
    } else {
      digitalWrite(LED, LOW);
    }

    if (LDR1 > marcoLDR) {
      contadorHa1_1++;
      if (contadorHa1_1 > nSegundos) {
        contadorHa1_2 = 0;
        haCarro1 = true;
      }
    } else {
      contadorHa1_2++;
      if (contadorHa1_2 > nSegundos) {
        contadorHa1_1 = 0;
        haCarro1 = false;
      }
    }

    if (LDR2 > marcoLDR) {
      contadorHa2_1++;
      if (contadorHa2_1 > nSegundos) {
        contadorHa2_2 = 0;
        haCarro2 = true;
      }
    } else {
      contadorHa2_2++;
      if (contadorHa2_2 > nSegundos) {
        contadorHa2_1 = 0;
        haCarro2 = false;
      }
    }

    if (LDR3 > marcoLDR) {
      contadorHa3_1++;
      if (contadorHa3_1 > nSegundos) {
        contadorHa3_2 = 0;
        haCarro3 = true;
      }
    } else {
      contadorHa3_2++;
      if (contadorHa3_2 > nSegundos) {
        contadorHa3_1 = 0;
        haCarro3 = false;
      }
    }

    if (LDR4 > marcoLDR) {
      contadorHa4_1++;
      if (contadorHa4_1 > nSegundos) {
        contadorHa4_2 = 0;
        haCarro4 = true;
      }
    } else {
      contadorHa4_2++;
      if (contadorHa4_2 > nSegundos) {
        contadorHa4_1 = 0;
        haCarro4 = false;
      }
    }

    //------------------Contando engarrafamento----------------------
    contadorEngarrafamento=0;
    if(haCarro1)contadorEngarrafamento++;
    if(haCarro2)contadorEngarrafamento++;
    if(haCarro3)contadorEngarrafamento++;
    if(haCarro4)contadorEngarrafamento++;
    if (contadorEngarrafamento == 4) {
      tempo_act = millis();
      if (tempo_act - tempo_ant >= tempo_req) {
        controleVez = !controleVez;
        tempo_ant = millis();
        if (controleVez) {
          modo_alerta();
        } else {
          modo_apagados();
        }
      }
    } else if ((!haCarro1) && (!haCarro2) && (!haCarro3) && (!haCarro4))
      maquina_de_estado(1);
    else
      maquina_de_estado(2);

    // maquina_de_estado(1);
  } else {
    modo_emergencia();
  }

  enviarDados();
  maximo = 0;
  contadorEngarrafamento = 0;
  delay(1000);
}


void receberDados() {
  if (Serial.available()){
    while(Serial.available())
    {
      char rx =(char) Serial.read();
      if(rx=='N')
        modo = 'N';
      else if(rx=='E')
        modo = 'E';
    }
  }
}