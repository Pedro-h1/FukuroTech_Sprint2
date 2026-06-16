// ==========================================================
// C++
// PROJETO: Semáforo Inteligente Inclusivo - FUKURO TECH
// Autoria: GRUPO 1
// ==========================================================

// SEMÁFORO CARROS
const int carroVerde = 2;
const int carroAmarelo = 3;
const int carroVermelho = 4;

// SEMÁFORO PEDESTRES
const int pedVermelho = 5;
const int pedVerde = 6;

// BUZZER
const int buzzer = 7;

// BOTÕES
const int btnAutista = 8;
const int btnCadeirante = 9;
const int btnVisual = 10;
const int btnIdoso = 11;

// HC-SR04
const int trigPin = 13;
const int echoPin = 12;

// FAIXA
const int faixaVermelha = A0;
const int faixaVerde = A1;

void setup()
{
  Serial.begin(9600);
  pinMode(carroVerde, OUTPUT);
  pinMode(carroAmarelo, OUTPUT);
  pinMode(carroVermelho, OUTPUT);

  pinMode(pedVerde, OUTPUT);
  pinMode(pedVermelho, OUTPUT);

  pinMode(faixaVerde, OUTPUT);
  pinMode(faixaVermelha, OUTPUT);

  pinMode(buzzer, OUTPUT);

  pinMode(btnAutista, INPUT_PULLUP);
  pinMode(btnCadeirante, INPUT_PULLUP);
  pinMode(btnVisual, INPUT_PULLUP);
  pinMode(btnIdoso, INPUT_PULLUP);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  fase1();
  fase2();
  fase3();
  fase4();
}


// FASE 1
// Carros Verde, Pedestres Vermelho
// ===============================
void fase1()
{
  digitalWrite(carroVerde, HIGH);
  digitalWrite(carroAmarelo, LOW);
  digitalWrite(carroVermelho, LOW);

  digitalWrite(pedVerde, LOW);
  digitalWrite(pedVermelho, HIGH);

  digitalWrite(faixaVerde, LOW);
  digitalWrite(faixaVermelha, HIGH);

  esperarComMonitoramento(10000);
}


// FASE 2
// Carros Amarelo
// =============
void fase2()
{
  digitalWrite(carroVerde, LOW);
  digitalWrite(carroAmarelo, HIGH);

  digitalWrite(pedVerde, LOW);
  digitalWrite(pedVermelho, HIGH);

  digitalWrite(faixaVerde, LOW);
  digitalWrite(faixaVermelha, HIGH);

  esperarComMonitoramento(2000);

  digitalWrite(carroAmarelo, LOW);
}


// FASE 3
// Carros Vermelho, Pedestres Verde
// ===============================
void fase3()
{
  digitalWrite(carroVermelho, HIGH);

  digitalWrite(pedVerde, HIGH);
  digitalWrite(pedVermelho, LOW);

  digitalWrite(faixaVerde, HIGH);
  digitalWrite(faixaVermelha, LOW);

  esperarComMonitoramento(10000);

  digitalWrite(carroVermelho, LOW);
}


// FASE 4 - Vermelho Geral (Segurança dos pedestres)
// ================================================
void fase4()
{
  digitalWrite(carroVerde, LOW);
  digitalWrite(carroAmarelo, LOW);  
  digitalWrite(carroVermelho, HIGH); // Carros continuam no vermelho

  digitalWrite(pedVerde, LOW);
  digitalWrite(pedVermelho, HIGH);   // Pedestres também no vermelho

  digitalWrite(faixaVerde, LOW);
  digitalWrite(faixaVermelha, HIGH);

  esperarComMonitoramento(2000); // 2 segundos antes de liberar os carros
}

// ===============================
// SENSOR HC-SR04
// ===============================
float medirDistancia()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duracao = pulseIn(echoPin, HIGH, 30000);

  if(duracao == 0)
  {
    return 999;
  }

  return duracao * 0.0343 / 2;
}

// ===============================
// MONITORAMENTO
// ===============================
void esperarComMonitoramento(long tempo)
{
  for(long i = 0; i < tempo / 50; i++)
  {
    verificarPerfis();
    delay(50);
  }
}

// ===============================
// VERIFICA PERFIS (Botões condicionados ao Sensor)
// ===============================
void verificarPerfis()
{
  float distancia = medirDistancia();

  // SIMULAÇÃO DA PULSEIRA:
  // Qualquer objeto a menos de 10 cm do sensor é considerado
  //uma pulseira válida
  bool pulseiraDetectada = (distancia > 0 && distancia < 10);

  if(pulseiraDetectada)
  {
    if(digitalRead(btnAutista) == LOW)
    {
      modoEspecial(15000, 0); // Autista
    }

    else if(digitalRead(btnCadeirante) == LOW)
    {
      modoEspecial(20000, 1); // Cadeirante
    }

    else if(digitalRead(btnVisual) == LOW)
    {
      modoEspecial(18000, 2); // Deficiência visual
    }

    else if(digitalRead(btnIdoso) == LOW)
    {
      modoEspecial(20000, 3); // Idoso
    }
  }
}

// ===============================
// MODO ESPECIAL 
// ===============================
void modoEspecial(long tempo, int tipoSom)
{
  // CARROS PARADOS
  digitalWrite(carroVerde, LOW);
  digitalWrite(carroAmarelo, HIGH);
  digitalWrite(carroVermelho, LOW);
  delay(2000);
    digitalWrite(carroAmarelo, LOW);
    digitalWrite(carroVermelho, HIGH);

  // PEDESTRES LIBERADOS
  digitalWrite(pedVerde, HIGH);
  digitalWrite(pedVermelho, LOW);

  // FAIXA VERDE
  digitalWrite(faixaVerde, HIGH);
  digitalWrite(faixaVermelha, LOW);

  // BIPE DE INÍCIO: dá um bipe longo avisando que abriu
  if(tipoSom == 1 || tipoSom == 3)
  {
    tone(buzzer, 1000);
    delay(500);
    noTone(buzzer);
  }

  unsigned long inicio = millis();
  int bipsFeitos = 0; // Contador para os 5 bips do idoso

  while(millis() - inicio < tempo)
  {
    unsigned long tempoDecorrido = millis() - inicio;
    unsigned long tempoRestante = tempo - tempoDecorrido;

    if(tipoSom == 2) // BIPE ACELERANDO: (Apenas Deficiente Visual)
    {
      long intervaloBipe = map(tempoRestante, 0, tempo, 100, 900);
      intervaloBipe = constrain(intervaloBipe, 100, 900); 

      tone(buzzer, 500);
      delay(intervaloBipe / 2); 
      noTone(buzzer);
      delay(intervaloBipe / 2); 
    }
    else if(tipoSom == 3) 
    {
      // Faz 5 bips nos últimos 3 segundos
      if(tempoRestante <= 3000 && bipsFeitos < 5)
      {
        tone(buzzer, 1100); 
        delay(250);         
        noTone(buzzer);
        delay(250);         
        bipsFeitos++;       
      }
      else
      {
        delay(50); 
      }
    }
    else
    {
      delay(100);
    }
  }

  // BIPE DE FIM: dá um bipe longo avisando o tempo acabou

  if(tipoSom == 1 || tipoSom == 3 || tipoSom == 2)
  {
    tone(buzzer, 1000);
    delay(500);
  }
  
  noTone(buzzer);

  // VOLTA AO NORMAL
  digitalWrite(pedVerde, LOW);
  digitalWrite(pedVermelho, HIGH);

  digitalWrite(faixaVerde, LOW);
  digitalWrite(faixaVermelha, HIGH);

  digitalWrite(carroVermelho, HIGH);
}