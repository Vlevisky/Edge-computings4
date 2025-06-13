# OmniStock — Controle Automático de Estoque de Medicamentos

## 🎯 Objetivo

O projeto OmniStock visa otimizar o controle de estoque hospitalar utilizando sistemas IoT e Edge Computing. Cada compartimento de medicamentos possui abertura automática mediante autenticação (simulada por botão) e registro automático de peso dos medicamentos inseridos.

## 🚀 Descrição do Funcionamento

- O operador aperta o botão simulando autenticação biométrica.
- O compartimento (gaveta) é destravado e o LED acende indicando abertura.
- O operador insere o medicamento na gaveta.
- Um sensor de peso (HX711 + célula de carga) registra a quantidade adicionada.
- Após a leitura, o compartimento é fechado automaticamente e o LED apaga.
- O valor registrado pode ser enviado via MQTT para o backend (simulado no Node-RED).

## 🔧 Arquitetura do Sistema

### Camada IoT (Edge Layer)
- **Microcontrolador:** Arduino Uno (simulado no Wokwi)
- **Sensor de Peso:** HX711 + célula de carga
- **Atuador:** Servo motor
- **Autenticação:** Botão (simulando biometria)
- **Indicador Visual:** LED

### Camada Back-End (Cloud)
- **Broker MQTT:** Simulado via Node-RED
- **Servidor / Plataforma IoT:** Explicado no diagrama para futuras integrações

### Camada Front-End (Dashboard)
- **Node-RED Dashboard:** Interface de monitoramento dos dados de peso
- **Exibição:** Histórico de registros, gauges e logs de pesagem

## 🛠 Tecnologias Utilizadas

- Arduino Uno (Wokwi)
- Sensor HX711
- Servo Motor
- Node-RED (simulação de backend)
- MQTT (simulado no Node-RED)
- Draw.io (para criação do diagrama)
- GitHub (repositório do projeto)

## 🖥 Circuito no Wokwi

O circuito foi simulado no Wokwi com as seguintes ligações:

| Componente | Pino no Arduino |
|---|---|
| Botão | 2 |
| LED | 9 |
| Servo | 5 |
| HX711 DT | 13 |
| HX711 SCK | 10 |
| HX711 VCC | 5V |
| HX711 GND | GND |

**Link para o projeto no Wokwi:**  
(https://wokwi.com/projects/433666964393885697)

## ⚙ Fluxo do Processo

1. Autenticação pelo botão.
2. Servo abre o compartimento.
3. LED acende indicando operação.
4. Operador insere os medicamentos.
5. Sensor HX711 registra o peso.
6. Servo fecha a gaveta.
7. LED apaga.
8. Valor de peso exibido no Serial e simulado no MQTT.

## 🗺 Diagrama da Arquitetura

O projeto completo com as três camadas pode ser visualizado no diagrama abaixo:

(https://github.com/user-attachments/assets/b5c6d0cb-53d3-432b-9112-c9f3fb98182c)

## 🎥 Protótipo em Funcionamento

O vídeo demonstrativo do protótipo no Wokwi pode ser visualizado no YouTube será encaminhado junto

## 📌 Observação

A comunicação MQTT está implementada no fluxo de simulação via Node-RED, mas não diretamente no microcontrolador, pois o foco deste protótipo é apresentar o conceito de Edge Computing com controle local inteligente e posterior envio de dados para o backend.
