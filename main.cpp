#include "DigitalOut.h"
#include "ThisThread.h"
#include "mbed.h"

Thread thread;

DigitalOut testled(PC_7);

#include "mbed.h"
typedef struct {
float voltage; /* результат измерения напряжения */
float current; /* результат измерения тока*/
uint32_t counter;
} message_t;


/* создали вторую структуру для второго потока */
typedef struct {
int led; /* вкл или выкл */
} message_t2;



/*здесь используется объект класса MemoryPool, для определения и
управления пулом памяти фиксированного размера, информацию об этом
классе изучите в документации */
MemoryPool<message_t, 16> mpool;
Queue<message_t, 16> queue;

/* поток отправитель */
void send_thread(void)
{
  uint32_t i = 0;
  while (true) {
  testled = !testled;
    i++; /* так как настоящие данные брать неоткуда здесь они
    генерируются*/
    message_t *message = mpool.alloc();
    message->voltage = (i * 0.1) * 33;
    message->current = (i * 0.1) * 11;
    message->counter = i;
    queue.put(message);
    ThisThread::sleep_for(1000);
  }
}



/* второй поток отправитель */
void send_thread2(void)
{
  message_t2 *message = mpool.alloc();
  message->led = testled; /*значение светодиода, вкл и выкл*/
  queue.put(message);
  ThisThread::sleep_for(1000);
  }
}






int main(void)
{
  
  while (true) {
    
    thread.start(callback(send_thread));
    osEvent evt = queue.get();
    if (evt.status == osEventMessage) {
      message_t *message = (message_t *)evt.value.p;
      printf("\nVoltage: %.2f V\n\r", message->voltage);
      printf("Current: %.2f A\n\r", message->current);
      printf("Number of cycles: %u\n\r", message->counter);
      printf("led: %u\n\r", message->led);
      mpool.free(message);
    }
    
    /* создаем второй поток */
    thread.start(callback(send_thread2));
    osEvent evt = queue.get();
    if (evt.status == osEventMessage) {
      message_t2 *message = (message_t2 *)evt.value.p;
      printf("led: %u\n\r", message->led);
      mpool.free(message);
    }
   
    
  }
}
