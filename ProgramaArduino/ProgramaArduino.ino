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


#define ldr1 A0
#define ldr2 A1
#define ldr3 A2
#define ldr4 A3


#define pot A15
#define LED 31

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

boolean engarrafado1_2 = false, engarrafado3 = false, engarrafado4_5 = false, engarrafado6 = false;
boolean engarrafado7_8 = false, engarrafado9 = false, engarrafado10_11 = false;
boolean engarrafado12_13 = false, engarrafado14 = false;
boolean haCarro1 = false, haCarro4 = false, haCarro7 = false, haCarro11 = false, haCarro13 = false;
//**************************************************************************************


//Recursos
int contador1 = 0, contador2 = 0, contador3 = 0, contador4 = 0, contador5 = 0, contador6 = 0, contador7 = 0, contador8 = 0;
int contador9 = 0, contador10 = 0, contador11 = 0, contador12 = 0, contador13 = 0, contador14 = 0;

int contador3_01 = 0, contador3_02 = 0, contador6_01 = 0, contador6_02 = 0, contador9_01 = 0, contador9_02 = 0;
int contador14_01 = 0, contador14_02 = 0;

int contadorHa1 = 0, contadorHa2 = 0, contadorHa4 = 0, contadorHa5 = 0, contadorHa7 = 0, contadorHa8 = 0;
int contadorHa10 = 0, contadorHa11 = 0, contadorHa12 = 0, contadorHa13 = 0;

unsigned long tempo_ant = 0, tempo_act = 0, tempo_req = 1000;

boolean controleAlerta = false, controleVez = false;
int nSegundos = 5;
int marcoLDR = 600, maximo = 0;
byte contadorEngarrafamento = 0, contadorEngarrafamentoAuxiliar = 0;
//**********************************


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
  } else if (num == 2) {
    if (digitalRead(led_verde_2)) return 'g';
    else if (digitalRead(led_amarelo_2)) return 'y';
    else if (digitalRead(led_vermelho_2)) return 'r';
  } else if (num == 3) {
    if (digitalRead(led_verde_3)) return 'g';
    else if (digitalRead(led_amarelo_3)) return 'y';
    else if (digitalRead(led_vermelho_3)) return 'r';
  } else if (num == 4) {
    if (digitalRead(led_verde_4)) return 'g';
    else if (digitalRead(led_amarelo_4)) return 'y';
    else if (digitalRead(led_vermelho_4)) return 'r';
  }
  return ' ';
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
  Serial.println(lerEstados());
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
      // case 2:
      //   if ((estado_semaforo_1 == estado_verde) && (!engarrafado3) && (haCarro1)) {
      //     modo_verde_1();
      //   } else if ((estado_semaforo_1 == estado_verde) && (engarrafado3) && (Habilitado_TV1)) {
      //     tempo_ant = millis() - tempo_req;
      //   } else if ((estado_semaforo_1 == estado_amarelo) && (!engarrafado3) && (haCarro1)) {
      //     modo_amarelo_1();
      //   } else if ((estado_semaforo_1 == estado_amarelo) && (engarrafado3) && (Habilitado_TA1)) {
      //     tempo_ant = millis() - tempo_req;
      //   } else if (estado_semaforo_1 == estado_vermelho) {
      //     modo_vermelho_1();
      //   } else {
      //     tempo_ant = millis() - tempo_req;
      //   }

      //   if ((estado_semaforo_2 == estado_verde) && (!engarrafado6) && (haCarro4)) {
      //     modo_verde_2();
      //   } else if ((estado_semaforo_2 == estado_verde) && (engarrafado6) && (Habilitado_TV2)) {
      //     tempo_ant = millis() - tempo_req;
      //   } else if ((estado_semaforo_2 == estado_amarelo) && (!engarrafado6) && (haCarro4)) {
      //     modo_amarelo_2();
      //   } else if ((estado_semaforo_2 == estado_amarelo) && (engarrafado6) && (Habilitado_TA2)) {
      //     tempo_ant = millis() - tempo_req;
      //   } else if (estado_semaforo_2 == estado_vermelho) {
      //     modo_vermelho_2();
      //   } else {
      //     tempo_ant = millis() - tempo_req;
      //   }

      //   if ((estado_semaforo_3 == estado_verde) && (!engarrafado9) && (haCarro7)) {
      //     modo_verde_3();
      //   } else if ((estado_semaforo_3 == estado_verde) && (engarrafado9) && (Habilitado_TV3)) {
      //     tempo_ant = millis() - tempo_req;
      //   } else if ((estado_semaforo_3 == estado_amarelo) && (!engarrafado9) && (haCarro7)) {
      //     modo_amarelo_3();
      //   } else if ((estado_semaforo_3 == estado_amarelo) && (engarrafado9) && (Habilitado_TA3)) {
      //     tempo_ant = millis() - tempo_req;
      //   } else if (estado_semaforo_3 == estado_vermelho) {
      //     modo_vermelho_3();
      //   } else {
      //     tempo_ant = millis() - tempo_req;
      //   }


      //   if ((estado_semaforo_4 == estado_verde) && (!engarrafado6) && (haCarro11)) {
      //     modo_verde_4();
      //   } else if ((estado_semaforo_4 == estado_verde) && (engarrafado6) && (Habilitado_TV4)) {
      //     tempo_ant = millis() - tempo_req;
      //   } else if ((estado_semaforo_4 == estado_amarelo) && (!engarrafado6) && (haCarro11)) {
      //     modo_amarelo_4();
      //   } else if ((estado_semaforo_4 == estado_amarelo) && (engarrafado6) && (Habilitado_TA4)) {
      //     tempo_ant = millis() - tempo_req;
      //   } else if (estado_semaforo_4 == estado_vermelho) {
      //     modo_vermelho_4();
      //   } else {
      //     tempo_ant = millis() - tempo_req;
      //   }

      //   if ((estado_semaforo_5 == estado_verde) && (!engarrafado14) && (haCarro13)) {
      //     modo_verde_5();
      //   } else if ((estado_semaforo_5 == estado_verde) && (engarrafado14) && (Habilitado_TV5)) {
      //     tempo_ant = millis() - tempo_req;
      //   } else if ((estado_semaforo_5 == estado_amarelo) && !engarrafado14 && haCarro13) {
      //     modo_amarelo_5();
      //   } else if ((estado_semaforo_5 == estado_amarelo) && (engarrafado14) && (Habilitado_TA5)) {
      //     tempo_ant = millis() - tempo_req;
      //   } else if (estado_semaforo_5 == estado_vermelho) {
      //     modo_vermelho_5();
      //   } else {
      //     tempo_ant = millis() - tempo_req;
      //   }

      //   if ((estado_semaforo_6 == estado_verde) && (!engarrafado3) && (haCarro7)) {
      //     modo_verde_6();
      //   } else if ((estado_semaforo_6 == estado_verde) && (engarrafado3) && (Habilitado_TV6)) {
      //   } else if ((estado_semaforo_6 == estado_amarelo) && (!engarrafado3) && (haCarro7)) {
      //     modo_amarelo_6();
      //   } else if ((estado_semaforo_6 == estado_amarelo) && (engarrafado3) && (Habilitado_TA6)) {

      //   } else if (estado_semaforo_6 == estado_vermelho) {
      //     modo_vermelho_6();
      //   }

      //   if ((estado_semaforo_7 == estado_verde) && (!engarrafado6) && (haCarro13)) {
      //     modo_verde_7();
      //   } else if ((estado_semaforo_7 == estado_verde) && (engarrafado6) && (Habilitado_TV7)) {

      //   } else if ((estado_semaforo_7 == estado_amarelo) && (!engarrafado6) && (haCarro13)) {
      //     modo_amarelo_7();
      //   } else if ((estado_semaforo_7 == estado_amarelo) && (engarrafado6) && (Habilitado_TA7)) {

      //   } else if (estado_semaforo_7 == estado_vermelho) {
      //     modo_vermelho_7();
      //   }




      //   break;
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

  // if (LDR1 > marcoLDR) {
  //   contadorHa1++;
  //   if (contadorHa1 > nSegundos) {
  //     contadorHa2 = 0;
  //     haCarro1 = true;
  //   }
  // } else {
  //   contadorHa2++;
  //   if (contadorHa2 > nSegundos) {
  //     contadorHa1 = 0;
  //     haCarro1 = false;
  //   }
  // }


  //------------------Contando engarrafamento----------------------
  // if (engarrafado1_2) contadorEngarrafamento++;
  // if (engarrafado3) {
  //   contadorEngarrafamento++;
  //   contadorEngarrafamentoAuxiliar++;
  // }

  // if (contadorEngarrafamentoAuxiliar == 4) {
  //   tempo_act = millis();
  //   if (tempo_act - tempo_ant >= tempo_req) {
  //     controleVez = !controleVez;
  //     tempo_ant = millis();
  //     if (controleVez) {
  //       modo_alerta();
  //     } else {
  //       modo_apagados();
  //     }
  //   }
  // } else if ((!haCarro1) && (!haCarro4) && (!haCarro7) && (!haCarro11) && (!haCarro13))
  //   maquina_de_estado(1);
  // else
  //   maquina_de_estado(2);

  maquina_de_estado(1);


  // maximo = 0;
  enviarDados();
  delay(1000);
  // contadorEngarrafamento = 0;
  // contadorEngarrafamentoAuxiliar = 0;
}
