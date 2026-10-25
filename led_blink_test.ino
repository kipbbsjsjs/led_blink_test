/*
 * ESP32 外接LED闪烁实验
 * 现象：LED每3秒完整闪烁一次（亮0.5秒、灭2.5秒）
 * 采用millis()非阻塞计时，与主项目风格一致
 */

#define PIN_LED 4            // 外接LED引脚（GPIO4，丝印D4）

const unsigned long ON_TIME  = 500;   // 亮0.5秒
const unsigned long OFF_TIME = 2500;  // 灭2.5秒，合计周期3秒

unsigned long lastToggle = 0;
bool ledOn = false;

void setup() {
  Serial.begin(115200);
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);
  Serial.println("LED闪烁实验启动：每3秒闪烁一次");
}

void loop() {
  unsigned long now = millis();
  unsigned long interval = ledOn ? ON_TIME : OFF_TIME;

  if (now - lastToggle >= interval) {
    lastToggle = now;
    ledOn = !ledOn;
    digitalWrite(PIN_LED, ledOn ? HIGH : LOW);
    Serial.println(ledOn ? "LED亮" : "LED灭");
  }
}
